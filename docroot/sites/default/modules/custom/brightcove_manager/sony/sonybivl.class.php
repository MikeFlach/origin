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
  private $channels = array();
  private $series = array();
  private $featured_videos = array();
  private $featured_main = array();
  private $featured_girls = array();
  private $featured_funny = array();
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
      $this->build_category_menu();
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
        $this->xml->startElement('web');
          $this->xml->startElement('theme');
            $this->xml->text('gray');
          $this->xml->endElement(); // theme
          $this->xml->startElement('icon_web');
            $this->xml->startElement('background_image');
              $this->xml->text('http://cdn2.maxim.com/maxim/sites/default/libraries/video/1280x720_sony_bg.png');
            $this->xml->endElement(); // background_image
            $this->xml->startElement('logo');
              $this->xml->text('http://cdn2.maxim.com/maxim/sites/default/libraries/video/200x50_maxim_logo.png');
            $this->xml->endElement(); // logo
          $this->xml->endElement(); // icon_web
        $this->xml->endElement(); // web

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
        $this->xml->text('std,hd,web');
      $this->xml->endElement(); // icon_formats
      $this->xml->startElement('platforms');
        $this->xml->text('legacy,webtreb');
      $this->xml->endElement(); // platforms
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
      $this->xml->startElement('web');
        $this->xml->startElement('theme');
           $this->xml->text('gray');
        $this->xml->endElement(); // theme
      $this->xml->endElement(); // web
      $this->build_icons( array(
        'sd' => 'http://dummyimage.com/128x96.png&text=Browse+Videos',
        'hd' => 'http://dummyimage.com/256x192.png&text=Browse+Videos',
        'menu' => 'http://dummyimage.com/256x192.png&text=Browse+Videos',
        'grid' => array(
          'aspect' => 'landscape',
          'url' => 'http://dummyimage.com/256x192.png&text=Browse+Videos',
        )
      ));
      $this->xml->startElement('languages');
        $this->build_title_desc('en', 'Maxim Videos', 'Browse Maxim Videos');
      $this->xml->endElement(); // languages

      $this->build_featured_category('pl_featured');
      $this->build_featured_category('pl_girls');
      /*$this->build_featured_category('pl_girls_landing');
      $this->build_featured_category('pl_funny_landing'); */
      $this->build_categories('channels', 5);
      $this->build_featured_category('pl_funny');
      $this->build_featured_category('pl_entertainment');
      $this->build_categories('series', 8);
      $this->build_featured_category('pl_2013_hometown_hotties');
      $this->build_featured_category('pl_hot_yoga');
    $this->xml->endElement(); // root_category
  }

  function build_category_menu() {
    $this->xml->startElement('category_menu');
      $this->xml->startElement('category_ref');
        $this->xml->startAttribute('id');
          $this->xml->text('pl_featured');
        $this->xml->endAttribute();
      $this->xml->endElement(); // category_ref
      for ($i=0; $i < count($this->channels); $i++) {
        $this->xml->startElement('category_ref');
          $this->xml->startAttribute('id');
            $this->xml->text($this->channels[$i]);
          $this->xml->endAttribute();
        $this->xml->endElement(); // category_ref
      }
      for ($i=0; $i < count($this->series); $i++) {
        $this->xml->startElement('category_ref');
          $this->xml->startAttribute('id');
            $this->xml->text($this->series[$i]);
          $this->xml->endAttribute();
        $this->xml->endElement(); // category_ref
      }
    $this->xml->endElement(); // category_menu
  }

  function build_featured_category($type) {
    switch ($type) {
      case 'pl_featured':
        $type_name = "Featured";
        $type_style = 'row';
      break;
      case 'pl_girls_landing':
        $type_name = "Featured Girls";
        $type_style = 'row';
      break;
      case 'pl_girls':
        $type_name = "Girls";
        $type_style = 'row';
      break;
      case 'pl_funny':
        $type_name = "Funny";
        $type_style = 'tile';
      break;
      case 'pl_entertainment':
        $type_name = "Entertainment";
        $type_style = 'tile';
      break;
      case 'pl_funny_landing':
        $type_name = "Featured Funny";
        $type_style = 'row';
      break;
      case 'pl_2013_hometown_hotties':
        $type_name = "2013 Hometown Hotties";
        $type_style = 'tile';
      break;
      case 'pl_2013_hot_yoga':
        $type_name = "Hot Yoga";
        $type_style = 'tile';
      break;
    }

    array_push($this->categories, $type);
    $this->xml->startElement('category');
      $this->xml->startAttribute('id');
        $this->xml->text($type);
      $this->xml->endAttribute();
      $this->xml->startAttribute('style');
        $this->xml->text($type_style);
      $this->xml->endAttribute();
      $this->xml->startAttribute('order');
        $this->xml->text(array_search($type, $this->categories)+1);
      $this->xml->endAttribute();
      $this->build_icons( array(
        'sd' => 'http://dummyimage.com/128x96.png&text=' . urlencode($type_name),
        'hd' => 'http://dummyimage.com/256x192.png&text=' . urlencode($type_name),
        'menu' => 'http://dummyimage.com/256x192.png&text=' . urlencode($type_name),
        'grid' => array(
          'aspect' => 'landscape',
          'url' => 'http://dummyimage.com/256x192.png&text=' . urlencode($type_name),
        )
      ));
      $this->xml->startElement('languages');
        $this->build_title_desc('en', $type_name, 'Maxim ' . $type_name . ' Videos');
      $this->xml->endElement(); // languages
      if ($type == 'pl_featured') {
        $this->build_featured_category('pl_girls_landing');
        $this->build_featured_category('pl_funny_landing');
      }
    $this->xml->endElement(); // category
  }

  function build_categories($type, $type_order) {
    $data = $this->get_categories($type);
    switch ($type) {
      case 'channels':
        $type_name = 'Channels';
        $type_style = 'tile';
      break;
      case 'series':
        $type_name = 'Series';
        $type_style = 'tile';
      break;
    }
    $this->xml->startElement('category');
      $this->xml->startAttribute('id');
        $this->xml->text('pl_' . $type);
      $this->xml->endAttribute();
      $this->xml->startAttribute('style');
        $this->xml->text('tile');
      $this->xml->endAttribute();
      $this->xml->startAttribute('order');
        $this->xml->text($type_order);
      $this->xml->endAttribute();
      $this->build_icons( array(
        'sd' => 'http://dummyimage.com/128x96.png&text=' . urlencode($type_name),
        'hd' => 'http://dummyimage.com/256x192.png&text=' . urlencode($type_name),
        'menu' => 'http://dummyimage.com/256x192.png&text=' . urlencode($type_name),
        'grid' => array(
          'aspect' => 'landscape',
          'url' => 'http://dummyimage.com/256x192.png&text=' . urlencode($type_name),
        )
      ));
      $this->xml->startElement('languages');
        $this->build_title_desc('en', $type_name, 'Maxim ' . $type_name);
      $this->xml->endElement(); // languages

      for($i=0; $i < count($data['items']); $i++) {
        $cat = $data['items'][$i];
        array_push($this->categories, $cat->referenceId);
        switch ($type) {
          case 'channels':
            array_push($this->channels, $cat->referenceId);
            $type_order = array_search($cat->referenceId, $this->channels) + 1;
          break;
          case 'series':
            array_push($this->series, $cat->referenceId);
            $type_order = array_search($cat->referenceId, $this->series) + 1;
          break;
        }
        $this->xml->startElement('category');
          $this->xml->startAttribute('id');
            $this->xml->text($cat->referenceId);
          $this->xml->endAttribute();
          $this->xml->startAttribute('style');
            $this->xml->text($type_style);
          $this->xml->endAttribute();
          $this->xml->startAttribute('order');
            $this->xml->text($type_order);
          $this->xml->endAttribute();
          /*if ($type == 'series') {
            $this->xml->startAttribute('collection_type');
              $this->xml->text('generic');
            $this->xml->endAttribute();
          }*/
          $this->build_icons( array(
            'sd' => 'http://dummyimage.com/128x96.png&text=' . urlencode($cat->name),
            'hd' => 'http://dummyimage.com/256x192.png&text=' . urlencode($cat->name),
            'menu' => 'http://dummyimage.com/256x192.png&text=' . urlencode($cat->name),
            'grid' => array(
              'aspect' => 'landscape',
              'url' => 'http://dummyimage.com/256x192.png&text=' . urlencode($cat->name),
            )
          ));
          //$this->build_icons($cat->thumbnailURL, $cat->thumbnailURL);
          $this->xml->startElement('languages');
            $this->build_title_desc('en', $cat->name, $cat->shortDescription);
          $this->xml->endElement(); // languages
        $this->xml->endElement(); // category
      }
    $this->xml->endElement(); // category
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
    $feature_index = 0;
    for ($cat=0; $cat < count($this->categories); $cat++) {
      $this->get_assets($this->categories[$cat]);
    }
//print_r($this->featured_videos); die();
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
                $this->xml->text($order + 1);
              $this->xml->endAttribute();
              /*if (in_array($cat, $this->series)) {
                $this->xml->startAttribute('collection_number');
                  $this->xml->text(1);
                $this->xml->endAttribute();
              }*/
            $this->xml->endElement(); // in_category
          }
          // Check to see if video is featured
          if (array_key_exists($key, $this->featured_videos)) {
            $this->xml->startElement('featured');
              $this->xml->startElement('feature');
                $this->xml->startAttribute('type');
                  $this->xml->text('detail');
                $this->xml->endAttribute();
                $this->xml->startAttribute('id');
                  $this->xml->text(++$feature_index);
                $this->xml->endAttribute();
                $this->xml->startElement('show_in');
                foreach ($this->featured_videos[$key] as $cat) {
                  $this->xml->startElement('target');
                  $this->xml->startAttribute('category');
                    switch ($cat) {
                      case 'pl_girls_landing':
                        $featured_cat = 'pl_girls';
                        $featured_order = array_search($key, $this->featured_girls) + 1;
                      break;
                      case 'pl_funny_landing':
                        $featured_cat = 'pl_funny';
                        $featured_order = array_search($key, $this->featured_funny) + 1;
                      break;
                      default:
                        $featured_cat = $cat;
                        $featured_order = array_search($key, $this->featured_main) + 1;
                      break;
                    }
                    $this->xml->text($featured_cat);
                  $this->xml->endAttribute();
                  $this->xml->startAttribute('order');
                    $this->xml->text($featured_order);
                  $this->xml->endAttribute();
                  $this->xml->endElement(); //target
                }
                $this->xml->endElement(); //show_in
              $this->xml->endElement(); //feature
            $this->xml->endElement(); //featured
          }

          $this->xml->startElement('type');
            $this->xml->text('video');
          $this->xml->endElement(); // type
          $this->xml->startElement('content_type');
            $this->xml->text('broadcast');
          $this->xml->endElement(); // broadcast
          $this->build_icons(array(
            'sd' => $this->get_image_url($value['icon_std'], 'sony_sd'),
            'hd' => $this->get_image_url($value['icon_hd'], 'sony_hd'),
            'grid' => array(
              'aspect' => 'landscape',
              'url' => $this->get_image_url($value['icon_hd'], 'sony_hd'),
            ),
            'poster' => $this->get_image_url($value['icon_hd'], 'sony_poster'),
          ));
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
      }
    $this->xml->endElement(); // assets

  }

  function get_image_url($url, $style) {
    $image_url = '';
    if ($style == 'original') {
      $image_url = $url;
    } else {
      $drupal_url = brightcove_remote_image($url);
      $image_url = image_style_url($style, $drupal_url);
      $image_url = str_replace('/feeds/sony/trebuchet', '', $image_url);
    }
    return $image_url;
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
        $asset_id = 'asset_' . $items[$i]['id'];
        if (!array_key_exists($asset_id, $this->assets)) {
          $this->array_push_assoc($this->assets, 'asset_' . $items[$i]['id'], array('categories'));
        }
        $this->assets['asset_' . $items[$i]['id']]['categories'][$type] = $i;
        // If featured category, add to respective array
        switch ($type) {
          case 'pl_featured':
            $this->array_push_assoc($this->featured_videos, $asset_id);
            $this->featured_videos[$asset_id][] = $type;
            array_push($this->featured_main, $asset_id);
          break;
          case 'pl_girls_landing':
            $this->array_push_assoc($this->featured_videos, $asset_id);
            $this->featured_videos[$asset_id][] = $type;
            array_push($this->featured_girls, $asset_id);
          break;
          case 'pl_funny_landing':
            $this->array_push_assoc($this->featured_videos, $asset_id);
            $this->featured_videos[$asset_id][] = $type;
            array_push($this->featured_funny, $asset_id);
          break;
        }

        $this->assets[$asset_id]['title'] = $items[$i]['name'];
        $this->assets[$asset_id]['description'] = $items[$i]['shortDescription'];
        if (strlen($items[$i]['videoStillURL'])) {
          $icon = $items[$i]['videoStillURL'];
        } else if (strlen($items[$i]['thumbnailURL'])){
          $icon = $items[$i]['thumbnailURL'];
        } else {
          $icon = '';
        }
        $this->assets[$asset_id]['icon_std'] = $icon;
        $this->assets[$asset_id]['icon_hd'] = $icon;
        $this->assets[$asset_id]['asset_url'] = $items[$i]['FLVURL'];
        $this->assets[$asset_id]['duration'] = round($items[$i]['length']/1000);
        $this->assets[$asset_id]['start_date'] = $this->convert_start_date($items[$i]['startDate']);
        if ($type == 'pl_featured') {
          $this->assets[$asset_id]['featured'] = 1;
        }
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
          if ($title != $desc) {
            $this->xml->text($desc);
          } else {
            $this->xml->text($desc . ' video');
          }
        } else {
          $this->xml->text($title . ' video');
        }
      $this->xml->endElement(); // title
    $this->xml->endElement(); // language
  }

  function build_icons($icons) {
    $this->xml->startElement('default_icons');
      if (array_key_exists('sd', $icons)) {
        $this->xml->startElement('icon_std');
          $this->xml->text($icons['sd']);
        $this->xml->endElement(); // icon_std
      }
      if (array_key_exists('hd', $icons)) {
        $this->xml->startElement('icon_hd');
          $this->xml->text($icons['hd']);
        $this->xml->endElement(); // icon_hd
      }
      if (array_key_exists('menu', $icons) || array_key_exists('grid', $icons) || array_key_exists('poster', $icons)) {
        $this->xml->startElement('icon_web');
          if (array_key_exists('menu', $icons)) {
            $this->xml->startElement('menu_icon');
              $this->xml->text($icons['menu']);
            $this->xml->endElement(); // menu_icon
          }
          if (array_key_exists('poster', $icons)) {
            $this->xml->startElement('poster');
              $this->xml->text($icons['poster']);
            $this->xml->endElement(); // poster
          }
          if (array_key_exists('grid', $icons)) {
            $this->xml->startElement('grid_icon');
              if (array_key_exists('aspect', $icons['grid'])) {
                $this->xml->startAttribute('aspect');
                  $this->xml->text($icons['grid']['aspect']);
                $this->xml->endAttribute();
              }
              $this->xml->text($icons['grid']['url']);
            $this->xml->endElement(); // grid_icon
          }
        $this->xml->endElement(); // icon_web
      }
    $this->xml->endElement(); // default_icons
  }

  function array_push_assoc($array, $key, $value){
   $array[$key] = $value;
   return $array;
  }

}
