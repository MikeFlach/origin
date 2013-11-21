<?php

require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'brightcove_manager') . '/feed/videofeedapi.php');

/**
 * MSN Class
 */
class msnClass {
  private $xml;
  private $videoAPI;
  private $series=array();
  private $categories=array();
  private $filter_tags_out = array('ufc');

  function __construct() {
    $this->videoAPI = new VideoFeedAPI();
    $this->get_channels();
    $this->get_series();

    $this->xml = new XMLWriter();
    $this->xml->openMemory();
    //$this->xml->openURI('php://output');
    //$this->xml->openURI($this->xml_file);
    $this->xml->setIndent(true);
    $this->xml->setIndentString('  ');
    $this->xml->startDocument('1.0', 'UTF-8');

    // Check domain
    if ($_ENV['AH_SITE_ENVIRONMENT'] != 'prod') {
      $this->domain = 'maximstg.prod.acquia-sites.com';
    }
  }

  function build_xml() {
    $this->xml->startElement('rss');
      $this->xml->startAttribute('version');
        $this->xml->text('2');
      $this->xml->endAttribute();
      $this->xml->startAttribute('xmlns:media');
        $this->xml->text('http://search.yahoo.com/mrss');
      $this->xml->endAttribute();
      $this->build_channel();
    $this->xml->endElement(); // rss

    $this->xml->endDocument();
    $data = $this->xml->outputMemory(TRUE);
    return $data;
  }

  function build_channel() {
    $this->xml->startElement('channel');
      $this->xml->startElement('title');
        $this->xml->text('Maxim Videos');
      $this->xml->endElement(); // title
      $this->xml->startElement('link');
        $this->xml->text('http://www.maxim.com');
      $this->xml->endElement(); // link
      $this->xml->startElement('description');
        $this->xml->text('Maxim Video Feed');
      $this->xml->endElement(); // description
      $this->xml->startElement('copyright');
        $this->xml->text('Copyright ' . date('Y') . ' Alpha Media Group Inc. The material may not be reproduced, distributed, transmitted, cached or otherwise used, except with the prior written permission of Alpha Media.');
      $this->xml->endElement(); // copyright
      $this->xml->startElement('pubDate');
        $this->xml->text(date('r'));
      $this->xml->endElement(); // pubDate
      $this->build_items();
    $this->xml->endElement(); // channel
  }

  function build_items() {
    $data = array();
    // Get videos
    if (!isset($_GET['page'])) {
      $_GET['page'] = 0;
    }
    if (!isset($_GET['pagesize'])) {
      $_GET['pagesize'] = 50;
    }
    if (is_numeric($_GET['page']) && is_numeric($_GET['pagesize'])) {
      $data = $this->videoAPI->get_all_videos($_GET['page'], $_GET['pagesize'], 'http');
      //print_r($data); die();
    }
    for ($i=0; $i < count($data['items']); $i++) {
      if (!$this->is_video_allowed($data['items'][$i]['tags'])) {
        continue;
      }
      $this->xml->startElement('item');
        $this->xml->startElement('title');
          $this->xml->text($data['items'][$i]['name']);
        $this->xml->endElement(); // title
        $this->xml->startElement('description');
          $this->xml->text($data['items'][$i]['shortDescription']);
        $this->xml->endElement(); // description
        $this->xml->startElement('guid');
          $this->xml->startAttribute('isPermaLink');
            $this->xml->text('false');
          $this->xml->endAttribute();
          $this->xml->text($data['items'][$i]['id']);
        $this->xml->endElement(); // guid
        $this->xml->startElement('pubDate');
          $this->xml->text(date('r', $data['items'][$i]['startDate']/1000));
        $this->xml->endElement(); // pubDate
        // Tags and Categories
        $this->build_tags($data['items'][$i]['tags']);
        // thumbnail
        $this->xml->startElement('media:thumbnail');
          $this->xml->startAttribute('url');
            $this->xml->text($data['items'][$i]['videoStillURL']);
          $this->xml->endAttribute(); // url
        $this->xml->endElement(); // media:thumbnail
        // content
        $video_rendition = $this->get_best_rendition($data['items'][$i]['renditions']);
        $this->xml->startElement('media:content');
          $this->xml->startAttribute('url');
            $this->xml->text($video_rendition->url);
          $this->xml->endAttribute(); // url
          $this->xml->startAttribute('type');
            $this->xml->text('video/mp4');
          $this->xml->endAttribute(); // type
          $this->xml->startAttribute('medium');
            $this->xml->text('video');
          $this->xml->endAttribute(); // medium
          $this->xml->startAttribute('height');
            $this->xml->text($video_rendition->frameHeight);
          $this->xml->endAttribute(); // height
          $this->xml->startAttribute('width');
            $this->xml->text($video_rendition->frameWidth);
          $this->xml->endAttribute(); // width
          $this->xml->startAttribute('duration');
            $this->xml->text(ceil($video_rendition->videoDuration/1000));
          $this->xml->endAttribute(); // duration
          $this->xml->startAttribute('fileSize');
            $this->xml->text($video_rendition->size);
          $this->xml->endAttribute(); // fileSize
        $this->xml->endElement(); // media:content
        $this->xml->startElement('media:copyright');
          $this->xml->startAttribute('url');
            $this->xml->text('http://www.maxim.com/corporate/terms-conditions');
          $this->xml->endAttribute(); // url
          $this->xml->text(date("Y") . ' Alpha Media Group Inc.');
        $this->xml->endElement(); // item  
      $this->xml->endElement(); // item
    }
  }

  function get_series() {
    $seriesObj = $this->videoAPI->get_player_playlists(PLAYER_SERIES, array('video_fields' => '', 'playlist_fields' => 'name,referenceid'));
    foreach ($seriesObj['items'] as $series) {
      $this->series[] = array(
        'id' => $series->referenceId,
        'name' => $series->name
      );
    }
  }

  function get_channels() {
    $channelObj = $this->videoAPI->get_player_playlists(PLAYER_CHANNELS, array('video_fields' => '', 'playlist_fields' => 'name,referenceid'));
    foreach ($channelObj['items'] as $channel) {
      $this->channels[] = array(
        'id' => $channel->referenceId,
        'name' => $channel->name
      );
    }
  }

  function build_tags($videoTags=array()) {
    $tags = array();
    for ($t=0; $t < count($videoTags); $t++) {
      $type = $this->get_category_type($videoTags[$t]);
      switch ($type) {
        case 'tag':
          $tags[] = strtolower($videoTags[$t]);
        break;
        case 'channel':
        case 'series':
          $this->xml->startElement('media:category');
            $this->xml->text(ucwords($videoTags[$t]));
          $this->xml->endElement(); // media:category
        break;
      }
    }

    if (count($tags)) {
      $this->xml->startElement('media:keywords');
        $this->xml->text(implode(',', $tags));
      $this->xml->endElement(); // media:keywords 
    }
  }

  function is_video_allowed($tags) {
    for ($t=0; $t < count($tags); $t++) {
      if (in_array($tags[$t], $this->filter_tags_out)) {
        return false;
      }
    }
    return true;
  }

  function get_category_type($name) {
    $type = '';
    // check if channel
    for($c=0; $c<count($this->channels); $c++) {
      if (strtolower($name) == strtolower($this->channels[$c]['name'])) {
        $type = 'channel';
        break;
      }
    }
    if (strlen($type) == 0) {
      // Check if series
      for($s=0; $s<count($this->series); $s++) {
        if (strtolower($name) == strtolower($this->series[$s]['name'])) {
          $type = 'series';
          break;
        }
      }
    }

    if (strlen($type) == 0) {
      $type='tag';
    }

    return $type;
  }

  function get_best_rendition($renditions) {
    $max_width = 0;
    $best_rendition = array();
    for ($r = 0; $r < count($renditions); $r++) {
      if ($renditions[$r]->frameWidth > $max_width) {
        $max_width = $renditions[$r]->frameWidth;
        $best_rendition = $renditions[$r];
      }
    }
    return $best_rendition;
  }
}