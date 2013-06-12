<?php

//$test = new SonyBIVL();
//$test->build_ingest_XML();

require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'brightcove_manager') . '/feed/videofeedapi.php');

/**
 * Sony BIVL Class
 */
class SonyBIVL {
  private $xml;
  private $videoAPI;
  private $num_categories = 0;
  private $assets = array();
  private $categories = array();
  private $destination_dir = 'feeds';
  private $destination_file = 'sony_trebuchet_feed.xml';

  function __construct() {
    $this->xml = new XMLWriter();
    $this->xml->openMemory();
    //$this->xml->openURI('php://output');
    //$this->xml->openURI($this->xml_file);
    $this->xml->setIndent(true);
    $this->xml->setIndentString('  ');
    $this->xml->startDocument('1.0', 'UTF-8');
    $this->destination_dir = file_build_uri($this->destination_dir);
    $this->videoAPI = new VideoFeedAPI();
  }

  function build_ingest_XML() {
    $this->xml->startElement('trebuchet');
      $this->xml->startAttribute('version');
        $this->xml->text('2');
      $this->xml->endAttribute();
      /*$this->xml->startElement('mehta_data_version');
        $this->xml->text(time());
      $this->xml->endElement();*/ // mehta_data_version
      $this->build_header();
      $this->build_supported_features();
      $this->build_regions();
      $this->build_root_category();

      $this->build_assets();
    $this->xml->endElement(); // trebuchet

    $this->xml->endDocument();
    $data = $this->xml->outputMemory(TRUE);
    // Save XML to file
    file_prepare_directory($this->destination_dir, FILE_CREATE_DIRECTORY);
    $filename = file_unmanaged_save_data($data, $this->destination_dir . '/' . $this->destination_file, FILE_EXISTS_REPLACE);
    if (!$filename) {
      drupal_set_message(t('Failed to save the file'), 'error');
      echo '<error>Failed to save the file</error>'; die();
    }
  }

  function build_header() {
    $this->xml->startElement('header');
      $this->xml->startElement('config');
        $this->xml->startElement('fallback_language');
          $this->xml->text('en');
        $this->xml->endElement(); // fallback_language
        $this->xml->startElement('playlist_enabled');
          $this->xml->text('true');
        $this->xml->endElement(); // playlist_enabled
        $this->xml->startElement('rebuffering_url');
          $this->xml->startAttribute('threshold');
            $this->xml->text('0');
          $this->xml->endAttribute();
          $this->xml->text('http://www.maxim.com/feeds/sony/');
        $this->xml->endElement(); // playlist_enabled
      $this->xml->endElement(); // config
    $this->xml->endElement(); // header
  }

  function build_supported_features() {
    $this->xml->startElement('supported_features');
      $this->xml->startElement('icon_formats');
        $this->xml->text('std,hd');
      $this->xml->endElement(); // icon_formats
    $this->xml->endElement(); // supported_features
  }

  function build_regions() {
    $this->xml->startElement('regions');
      $this->xml->startElement('region');
        $this->xml->startAttribute('id');
          $this->xml->text('1');
        $this->xml->endAttribute();
        $this->xml->startElement('country');
          $this->xml->text('US');
        $this->xml->endElement(); // country
      $this->xml->endElement(); // region
    $this->xml->endElement(); // regions
  }

  function build_root_category() {
    $this->xml->startElement('root_category');
      $this->xml->startAttribute('id');
        $this->xml->text('1');
      $this->xml->endAttribute();
      $this->build_icons('http://dummyimage.com/128x96.png&text=Home', 'http://dummyimage.com/256x192.png&text=Home');
      $this->xml->startElement('languages');
        $this->build_title_desc('en', 'Videos', 'Return to Videos');
      $this->xml->endElement(); // languages

      $this->build_featured_category();
      $this->build_categories('channels');
      $this->build_categories('series');
    $this->xml->endElement(); // root_category
  }

  function build_featured_category() {
    array_push($this->categories, 'pl_featured');
    $this->xml->startElement('category');
      $this->xml->startAttribute('id');
        $this->xml->text('pl_featured');
      $this->xml->endAttribute();
      $this->xml->startAttribute('style');
        $this->xml->text('row');
      $this->xml->endAttribute();
      $this->xml->startAttribute('order');
        $this->xml->text(array_search("pl_featured",$this->categories));
      $this->xml->endAttribute();
      $this->build_icons('http://dummyimage.com/128x96.png&text=Featured+Videos', 'http://dummyimage.com/256x192.png&text=Featured+Videos');
      $this->xml->startElement('languages');
        $this->build_title_desc('en', 'Featured Videos', 'Maxim Featured Videos');
      $this->xml->endElement(); // languages
    $this->xml->endElement(); // category
  }

  function build_categories($type) {
    $data = $this->get_categories($type);
    for($i=0; $i < count($data['items']); $i++) {
      $cat = $data['items'][$i];
      array_push($this->categories, $cat->referenceId);
      $this->xml->startElement('category');
        $this->xml->startAttribute('id');
          $this->xml->text($cat->referenceId);
        $this->xml->endAttribute();
        $this->xml->startAttribute('style');
          $this->xml->text('row');
        $this->xml->endAttribute();
        $this->xml->startAttribute('order');
          $this->xml->text(array_search($cat->referenceId, $this->categories));
        $this->xml->endAttribute();
        $this->build_icons('http://dummyimage.com/128x96.png&text=' . $cat->name, 'http://dummyimage.com/256x192.png&text=' . $cat->name);
        //$this->build_icons($cat->thumbnailURL, $cat->thumbnailURL);
        $this->xml->startElement('languages');
          $this->build_title_desc('en', $cat->name, $cat->shortDescription);
        $this->xml->endElement(); // languages
      $this->xml->endElement(); // category
    }
  }

  function get_categories($type) {
    $categories = '';
    $params = array('video_fields' => '', 'playlist_fields' => 'referenceid,name,shortDescription,thumbnailURL,filterTags');
    $player = '';
    switch ($type) {
      case 'series':
        $player = PLAYER_SERIES;
      break;
      case 'channels':
        $player = PLAYER_CHANNELS;
      break;
    }
    if (strlen($player)) {
      $categories = $this->videoAPI->get_player_playlists($player, $params);
    }

    return $categories;
  }

  function build_assets() {
    //$this->assets;
    for ($cat=0; $cat < count($this->categories); $cat++) {
      $this->get_assets($this->categories[$cat]);
    }
    //print_r($this->assets);
    $this->xml->startElement('assets');
      foreach($this->assets as $key=>$value){
        $this->xml->startElement('asset');
          $this->xml->startAttribute('id');
            $this->xml->text($key);
          $this->xml->endAttribute();
          $this->xml->startAttribute('pay_content');
            $this->xml->text('false');
          $this->xml->endAttribute();
          // Loop thru categories
          foreach ($value['categories'] as $cat=>$order) {
            $this->xml->startElement('in_category');
              $this->xml->startAttribute('id');
                $this->xml->text($cat);
              $this->xml->endAttribute();
              $this->xml->startAttribute('order');
                $this->xml->text($order);
              $this->xml->endAttribute();
            $this->xml->endElement(); // in_category
          }
          $this->xml->startElement('type');
            $this->xml->text('video');
          $this->xml->endElement(); // type
          $this->build_icons($this->get_image_url($value['icon_std'], 'sony_sd'), $this->get_image_url($value['icon_hd'], 'sony_hd'));
          $this->xml->startElement('languages');
            $this->build_title_desc('en', $value['title'], $value['description']);
          $this->xml->endElement(); // languages
          $this->xml->startElement('start_date');
            $this->xml->text($value['start_date']);
          $this->xml->endElement(); // start_date
          $this->xml->startElement('duration');
            $this->xml->text($value['duration']);
          $this->xml->endElement(); // duration
          $this->xml->startElement('metafile_type');
            $this->xml->text('m3u8');
          $this->xml->endElement(); // metafile_type
          $this->xml->startElement('stream_type');
            $this->xml->text('HTTPLS');
          $this->xml->endElement(); // stream_type
          $this->xml->startElement('container_type');
            $this->xml->text('MPEG2TS');
          $this->xml->endElement(); // container_type
          $this->xml->startElement('video_type');
            $this->xml->text('AVC');
          $this->xml->endElement(); // video_type
          $this->xml->startElement('audio_type');
            $this->xml->text('AAC');
          $this->xml->endElement(); // audio_type
          $this->xml->startElement('rating');
            $this->xml->startAttribute('scheme');
              $this->xml->text('urn:v-chip');
            $this->xml->endAttribute();
            $this->xml->text('14');
          $this->xml->endElement(); // rating

          $this->xml->startElement('asset_url');
            $this->xml->text($value['asset_url']);
          $this->xml->endElement(); // asset_url
        $this->xml->endElement(); // asset
       //echo 'test'; print_r($key); die();
      }
    $this->xml->endElement(); // assets

  }

  function get_image_url($url, $style) {
    $drupal_url = brightcove_remote_image($url);
    return image_style_url($style, $drupal_url);
  }

  function get_assets($type) {
    $params = array('video_fields' => 'id,name,shortDescription,longDescription,videoStillURL,thumbnailURL,length,startDate,FLVURL,tags,customFields');
    switch($type) {
      case 'pl_featured':
        $data = $this->videoAPI->get_featured_videos(PLAYER_FEATURED, $params);
      break;
      default:
        $data = $this->videoAPI->get_playlist_by_reference_id($type, $params, 0, 100);
      break;
    }

    $items = $data['items'];
    for ($i=0; $i<count($items); $i++) {
      if(strlen($items[$i]['id'])) {
        if (!array_key_exists('asset_' . $items[$i]['id'], $this->assets)) {
          $this->array_push_assoc($this->assets, 'asset_' . $items[$i]['id'], array('categories'));
        }
        $this->assets['asset_' . $items[$i]['id']]['categories'][$type] = $i;
        $this->assets['asset_' . $items[$i]['id']]['title'] = $items[$i]['name'];
        $this->assets['asset_' . $items[$i]['id']]['description'] = $items[$i]['shortDescription'];
        $this->assets['asset_' . $items[$i]['id']]['icon_std'] = $items[$i]['videoStillURL'];
        $this->assets['asset_' . $items[$i]['id']]['icon_hd'] = $items[$i]['videoStillURL'];
        $this->assets['asset_' . $items[$i]['id']]['asset_url'] = $items[$i]['FLVURL'];
        $this->assets['asset_' . $items[$i]['id']]['duration'] = round($items[$i]['length']/1000);
        $this->assets['asset_' . $items[$i]['id']]['start_date'] = $this->convert_start_date($items[$i]['startDate']);
      }
    }
  }

  function convert_start_date($time) {
    return str_replace('+00:00', 'Z', gmdate('c', $time/1000));
  }

  function build_title_desc($language, $title, $desc) {
    $this->xml->startElement('language');
      $this->xml->startAttribute('id');
        $this->xml->text($language);
      $this->xml->endAttribute();
      $this->xml->startElement('title');
        if (strlen($title) > 128) {
          $title = substr($title, 0, 125) . '...';
        }
        $this->xml->text($title);
      $this->xml->endElement(); // title
      $this->xml->startElement('description');
        if (strlen($desc) > 0) {
          $this->xml->text($desc);
        } else {
          $this->xml->text($title . ' video');
        }
      $this->xml->endElement(); // title
    $this->xml->endElement(); // language
  }

  function build_icons($sd, $hd) {
    $this->xml->startElement('default_icons');
      $this->xml->startElement('icon_std');
        $this->xml->text($sd);
      $this->xml->endElement(); // icon_std
      $this->xml->startElement('icon_hd');
        $this->xml->text($hd);
      $this->xml->endElement(); // icon_hd
    $this->xml->endElement(); // default_icons
  }

  function array_push_assoc($array, $key, $value){
   $array[$key] = $value;
   return $array;
  }

}
