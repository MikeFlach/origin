<?php

// Status codes
define('SUCCESS', 0);
define('ERROR_UNKNOWN_REQUEST', -1);
define('ERROR_NO_RESULTS', -2);
define('BRIGHTCOVE_ERROR', -10);
// Brightcove variables
define('BC_READ_TOKEN', 'CX1YvsC6MvJ-6FddP41yjMQxH1sktJjDEH4QV0p-RQPZKyLwkfgCow..');
define('BC_URL', 'http://api.brightcove.com/services/library?');
// Player IDs
define('PLAYER_SERIES', '1799261978001');
define('PLAYER_CHANNELS', '1798911603001');
define('PLAYER_FEATURED', '1822842484001');

if (isset($platform)) {
  define('PLATFORM', $platform);
} else {
  define('PLATFORM', NULL);
}

switch (PLATFORM) {
  default:
    // Other variables
    define('NUM_FEATURED_VIDEOS', 8); // Display number of featured videos on main pivot page
  break;
}

/**
 * Video Feed API
 */
class VideoFeedAPI {
  private $bc_output = 'json';

  // Default preroll ad URL.  vget xbox_preroll
  //private $preroll_ad_default = 'https://2f3ba.v.fwmrm.net/ad/g/1?nw=193466&prof=193466:XBOX_Live_UAC_VAST&ssnw=193466&asnw=193466&csid=AUSE1M&caid=maxim-default&vprn=[RANDOM_NUMBER]&resp=vast2ma&flag=+exvt+emcr;;ptgt=a&tpcl=PREROLL&tpos=0&maxa=1';
  private $preroll_ad_default = 'https://2f3ba.v.fwmrm.net/ad/g/1?nw=193466&prof=193466:XBOX_Live_UAC_VAST&ssnw=193466&asnw=376289&csid=AUSE1M&caid=[VideoID]&vprn=[RANDOM_NUMBER]&resp=vast2ma&flag=+exvt+emcr;;slid=pre&ptgt=a&tpos=0&maxa=1&slau=Maxim%20PreRoll';
  // Default maximum reference frame buffer length. vget xbox_max_frame_buffer
  private $max_ref_frame_buffer_length_default = 8;
  // Default ad play frequency.  vget xbox_ad_frequency
  private $ad_play_frequency_default = 0;
  // Default for ad maximum bit rate. vget xbox_ad_max_bit_rate
  private $ad_max_bit_rate_default = 0;
  private $ad_click_default = '';
  private $share_link = 'http://www.maxim.com/maximtv/player/[VideoID]';
  private $cache_interval = 20;
  private $about_text = '';
  private $interstial_ad_url = 'http://www.maxim.com/sites/default/files/ads/bb.html';
  private $interstial_ad_duration = 10;
  private $interstial_ad_frequency = 20;

  /**
   * Get Ad
   * @param  array $params Brightcove parameters
   * @param  string $page  Page for ad
   * @return array         Ad metadata
   */
  public function get_ad($params, $page = 'default') {
    switch (PLATFORM) {
      case 'blackberry':
        $activityLink = 'http://www.maxim.com/feeds/blackberry/?cmd=track';
        $ad_ref_id = 'pl_xbox_ad';
        $ad_position = 3;
      break;
      case 'playstation':
        $activityLink = 'http://www.maxim.com/feeds/playstation/?cmd=track';
        $ad_ref_id = 'pl_xbox_ad';
      break;
      default:
        $activityLink = 'http://www.maxim.com/feeds/xbox/?cmd=track';
        $ad_ref_id = 'pl_xbox_ad';
      break;
    }

    $output = array('items' => array());
    $results = $this->get_playlist_by_reference_id($ad_ref_id, $params);
    foreach ($results['items'] as $item) {
      if (array_key_exists('linkURL', $item) === FALSE || $item['linkURL'] == NULL) {
        $item['activityLink'] = $activityLink . '&id=' . $item['id'] . '&page=' . $page . '&t=[timestamp]';
      } else {
        $item['activityLink'] = $item['linkURL'];
      }
      if (isset($ad_position)) {
        $item['adPosition'] = $ad_position;
      }
      if (PLATFORM != 'xbox') {
        unset($item['videoStillURL']);
      }
      unset($item['linkURL']);
      unset($item['preroll']);
      $output['items'][] = $item;
      // Return only one
      break;
    }
    return $output;
  }

/**
 * Get all videos in brightcove
 * @param  integer $page=0          Page number
 * @param  integer $pagesize=100    Page size
 * @return array of videos
 */
public function get_all_videos($page=0, $pagesize=100){
    $output = array('items' => array());
    $params = array('video_fields' => 'id,name,shortDescription,videoStillURL,length,playsTotal,startDate,FLVURL,tags','get_item_count'=>'true');
    // Get all videos
    $params['page_size'] = $pagesize;
    $params['page_number'] = $page;
    $params['sort_by'] = 'START_DATE:DESC';

    //$params['sort_order'] = 'DESC';
    $results = $this->call_brightcove('search_videos', $params);
    if (array_key_exists('bcdata', $results)) {
      $data = json_decode($results['bcdata']);
      //print_r($data); die();
      if (count($data)) {
        if (isset($data->error)) {
          $output['statusmsg'] = 'BRIGHTCOVE_ERROR';
          $output['errormsg'] = $data->error->name . ' - ' . $data->error->message;
        } else {
          foreach ($data as $key=>$value){
            switch ($key) {
              case 'page_number':
                $output['page'] = $value;
              break;
              case 'page_size':
                $output['pagesize'] = $value;
              break;
              case 'total_count':
                if ($value > 500) {
                  $total_count = 500;
                } else {
                  $total_count = $value;
                }
                $output[$key] = $total_count;
              break;
              case 'videoIds':
                $output[$key] = $value;
              break;
              case 'items':
                foreach ($value as $video) {
                  $item = (array)$video;
                  foreach ($item as $itemkey => $itemval) {
                    if ($itemkey == 'tags' && count($itemval)) {
                      $videoCat = $this->get_category_for_video($itemval);
                      if (count($videoCat) > 0) {
                        $item['categories'] = $videoCat;
                      }
                    }
                  }
                  $item['longDescription'] = $item['shortDescription'];
                  // Use videoStillURL for thumbnailURL
                  $item['thumbnailURL'] = $item['videoStillURL'];
                  $item['preroll'] = $this->get_preroll_ad($item['id']);
                  $item['shareLink'] = $this->get_share_link($item['id']);
                  $output['items'][] = array_merge(array('type'=>'video'), $item);
                }
              break;
            }
          }
        }
      }
    }
    return $output;
  }

  /**
   * Get list of videos by passing in reference ID of playlist
   * @param  string  $reference_id  Reference ID
   * @param  array   $params        Brightcove Parameters
   * @param  integer $page          Page Number
   * @param  integer $page_size     Page Size
   * @return array                  array of videos
   */
  public function get_playlist_by_reference_id($reference_id, $params = array(), $page = 0, $page_size = 100) {
    $output = array('items' => array());
    $params['reference_id'] = $reference_id;
    if (!is_numeric($page)) {
      $page = 0;
    }
    if (!is_numeric($page_size)) {
      $page_size = 100;
    }
    $results = $this->call_brightcove('find_playlist_by_reference_id', $params);
    if (array_key_exists('bcdata', $results)) {
      $data = json_decode($results['bcdata']);
      //print_r($data); die();
      if (count($data)) {
        if (isset($data->error)) {
          $output['statusmsg'] = 'BRIGHTCOVE_ERROR';
          $output['errormsg'] = $data->error->name . ' - ' . $data->error->message;
        } else {
          $output['page'] = $page;
          $output['pagesize'] = $page_size;
          //print_r($data); die();
          foreach ($data as $key=>$value){
            switch ($key) {
              case 'videoIds':
                //$output[$key] = $value;
              break;
              case 'videos':
                $output['total_count'] = count($value);
                if (count($value) > 0) {
                  $start = $page * $page_size;
                  $end = $start + $page_size;
                  if ($end > count($value)) {
                    $end = count($value);
                  }
                  for($item_id=$start; $item_id < $end; $item_id++) {
                    $video_item = array_merge(array('type'=>'video'), (array)$value[$item_id]);
                    $video_item['preroll'] = $this->get_preroll_ad($video_item['id']);
                    $video_item['shareLink'] = $this->get_share_link($video_item['id']);
                    $output['items'][] = $this->format_video_item($video_item);
                  }
                }
              break;
            }
          }
        }
      } else {
        $output['statusmsg'] = 'ERROR_NO_RESULTS';
      }
    }
    return $output;
  }

  /**
   * Get config
   * @return array config
   */
  public function get_config() {
    $config = array();
    switch(PLATFORM) {
      case 'xbox':
        $config['MaxRefFrameBufferLength'] = variable_get('xbox_max_frame_buffer', $this->max_ref_frame_buffer_length_default);
        $config['AdPlayFrequency'] = variable_get('xbox_ad_frequency', $this->ad_play_frequency_default);
        $config['AdMaximumBitRate'] = variable_get('xbox_ad_max_bit_rate', $this->ad_max_bit_rate_default);
        $config['AnalyticsURL'] = 'https://www.maxim.com/ga?site=' . PLATFORM . '&';
      break;
      case 'playstation':
        $config['AdPlayFrequency'] = variable_get('playstation_ad_frequency', $this->ad_play_frequency_default);
        $config['AnalyticsURL'] = 'http://www.maxim.com/ga?site=' . PLATFORM . '&';
      break;
      case 'blackberry':
        $config['AdPlayFrequency'] = variable_get('blackberry_ad_frequency', $this->ad_play_frequency_default);
        $config['CacheInterval'] = variable_get('blackberry_cache_interval', $this->cache_interval);
        $config['AboutText'] = variable_get('blackberry_about_text', $this->about_text);
        $config['InterstitialAdURL'] = variable_get('blackberry_interstitial_url', $this->interstial_ad_url);
        $config['InterstitialAdDuration'] = variable_get('blackberry_interstitial_duration', $this->interstial_ad_duration);
        $config['InterstitialAdFrequency'] = variable_get('blackberry_interstitial_freq', $this->interstial_ad_frequency);
        $config['AnalyticsURL'] = 'http://www.maxim.com/ga?site=' . PLATFORM . '&';
      break;
      case 'roku':
        $config['AdPlayFrequency'] = variable_get('roku_ad_frequency', $this->ad_play_frequency_default);
      break;
    }
    return $config;
  }

  /**
   * Get preroll ad.  Use drupal variable: xbox_preroll
   * @return string   Preroll URL
   */
  private function get_preroll_ad($vid = '') {
    if (isset($_GET['showpreroll']) && $_GET['showpreroll'] == 0) {
      $preroll = '';
    } else {
      switch (PLATFORM) {
        case 'playstation':
          $preroll = variable_get('playstation_preroll', $this->preroll_ad_default);
        break;
        case 'blackberry':
          $preroll = variable_get('blackberry_preroll', $this->preroll_ad_default);
        break;
        case 'roku':
          $preroll = variable_get('roku_preroll', $this->preroll_ad_default);
        break;
        default:
          // xbox
          $preroll = variable_get('xbox_preroll', $this->preroll_ad_default);
        break;
      }
    }

    // Insert video ID
    $preroll = str_replace('[VideoID]', $vid, $preroll);

    return $preroll;
  }

  /**
   * Get share link.
   * @return string   Share Link URL
   */
  private function get_share_link($vid = '') {
    // Insert video ID
    $shareLink = str_replace('[VideoID]', $vid, $this->share_link);
    switch(PLATFORM) {
      case 'blackberry':
        $shareLink .= '?src=bb';
      break;
    }

    return $shareLink;
  }


  /**
   * Format video item
   * @param  array $video_item  Video metadata
   * @return array              Formated video metadata
   */
  private function format_video_item($video_item) {
    $video_output = array();
    foreach ($video_item as $key => $value) {
      switch ($key) {
        case 'customFields':
          /*if (isset($value->rating)) {
            $video_output['rating'] = $value->rating;
          }*/
        break;
        case 'tags':
          if (count($value) > 0) {
            $video_output[$key] = $value;
            $videoCat = $this->get_category_for_video($value);
            if (count($videoCat) > 0) {
              $video_output['categories'] = $videoCat;
            }
          }
        break;
        case 'videoStillURL':
          $video_output['videoStillURL'] = $value;
          $video_output['thumbnailURL'] = $value;
        break;
        case 'thumbnailURL':
          // Use videoStillURL for thumbnailURL
        break;
        default:
          $video_output[$key] = $value;
        break;
      }
    }
    return $video_output;
  }

  /**
   * Get playlist overview
   * @param  string $reference_id  Brightcove reference ID
   * @param  array $params         Brightcove parameters
   * @return array                 Playlist metadata
   */
  public function get_playlist_overview($reference_id, $params) {
    $output = array();
    $params['reference_id'] = $reference_id;
    $results = $this->call_brightcove('find_playlist_by_reference_id', $params);
    if (array_key_exists('bcdata', $results)) {
      $data = json_decode($results['bcdata']);
      //print_r($data); die();
      if (count($data)) {
        if (isset($data->error)) {
          $output['statusmsg'] = 'BRIGHTCOVE_ERROR';
          $output['errormsg'] = $data->error->name . ' - ' . $data->error->message;
        } else {
          foreach ($data as $key=>$value){
            switch ($key) {
              case 'videos':
                $output['total_count'] = count($value);
              break;
              default:
                $output[$key] = $value;
              break;
            }
          }
        }
      } else {
        $output['statusmsg'] = 'ERROR_NO_RESULTS';
      }
    }
    return $output;
  }

  /**
   * Get featured videos
   * @param  string $player_id  Brightcove player ID
   * @param  array  $params     Brightcove parameters
   * @return array              Videos
   */
  public function get_featured_videos($player_id, $params = array()) {
    $max_items = 8;
    $num_featured_videos = NUM_FEATURED_VIDEOS;
    $output = array('items' => array());
    $params['player_id'] = $player_id;
    $params['get_item_count'] = 'true';
    // Get series playlists
    $seriesObj = $this->get_player_playlists(PLAYER_SERIES, array('video_fields' => '', 'playlist_fields' => 'referenceid'));
    //print_r($seriesObj); die();
    $series_refIDs = array();
    foreach ($seriesObj['items'] as $series) {
      $series_refIDs[] = $series->referenceId;
    }
    $results = $this->call_brightcove('find_playlists_for_player_id', $params);
    if (array_key_exists('bcdata', $results)) {
      $data = json_decode($results['bcdata']);
      if (count($data)) {
        if (isset($data->error)) {
          $output['statusmsg'] = 'BRIGHTCOVE_ERROR';
          $output['errormsg'] = $data->error->name . ' - ' . $data->error->message;
        } else {
          foreach ($data as $key=>$value){
            //echo $key . "\n";
            switch ($key) {
              case 'page_number':
              case 'page_size':
              case 'total_count':
              break;
              case 'items':
                for ($i=0; $i < count($value); $i++) {
                  // If playlist is featured videos, get videos
                  if ($value[$i]->referenceId == 'pl_featured_videos') {
                    $videoCt=0;
                    foreach ($value[$i]->videos as $video) {
                      if (++$videoCt <= $num_featured_videos && count($output['items']) < $max_items) {
                        $video_item = array_merge(array('type'=>'video'), (array)$video);
                        $video_item['preroll'] = $this->get_preroll_ad($video_item['id']);
                        $video_item['shareLink'] = $this->get_share_link($video_item['id']);
                        $output['items'][] = $this->format_video_item($video_item);
                      } else {
                        break;
                      }
                    }
                  } else {
                    // If not featured videos, see if it is a channel or series
                    if (in_array($value[$i]->referenceId, $series_refIDs)) {
                      $video_type = 'series';
                    } else {
                      $video_type = 'channel';
                    }
                    if (count($output['items']) < $max_items) {
                      $video_item = array('type'=> $video_type, 'name'=> $value[$i]->name, 'referenceId'=> $value[$i]->referenceId, 'shortDescription'=>$value[$i]->shortDescription, 'thumbnailURL' => $value[$i]->thumbnailURL);
                      $output['items'][] = $video_item;
                    }
                  }
                }
              break;
              default:
                $output[$key] = $value;
              break;
            }
          }
        }
      } else {
        $output['statusmsg'] = 'ERROR_NO_RESULTS';
      }
    }
    $output['total_count'] = count($output['items']);
    return $output;
  }

  /**
   * Get categories for video
   * @param  [array] $tags  Array of tags
   * @return [array]        Array of categories
   */
  public function get_category_for_video($tags) {
    $playlists = array(PLAYER_SERIES, PLAYER_CHANNELS);
    $categories = array();
    $params = array('video_fields' => '', 'playlist_fields' => 'referenceid,name,shortDescription,thumbnailURL,filterTags');
    foreach ($playlists as $pl) {
      $data = $this->get_player_playlists($pl, $params);
      foreach ($data['items'] as $cat) {
        $test = array_intersect($cat->filterTags,$tags);
        if (count($test)) {
          $arCategories = array('name' => '', 'referenceId' => '', 'type' => '');
          $arCategories['name'] = $cat->name;
          $arCategories['referenceId'] = $cat->referenceId;
          switch ($pl) {
            case PLAYER_SERIES:
              $arCategories['type'] = 'series';
            break;
            case PLAYER_CHANNELS:
              $arCategories['type'] = 'channel';
            break;
          }
          $categories[] = $arCategories;
        }
      }
    }
    //print_r($playlist); die();
    return $categories;
  }

  /**
   * Get Video description by ID
   * @param  [string] $videoid Video ID
   * @param  [array]  $params  Brightcove Parameters
   * @return [array]           Video metadata
   */
  public function get_video_by_id($videoid, $params = array()) {
    $output = array();
    $params['video_id'] = $videoid;
    $results = $this->call_brightcove('find_video_by_id', $params, 1, 0);
    if (array_key_exists('bcdata', $results)) {
      $data = json_decode($results['bcdata']);
      if (count($data)) {
        if (isset($data->error)) {
          $output['statusmsg'] = 'BRIGHTCOVE_ERROR';
          $output['errormsg'] = $data->error->name . ' - ' . $data->error->message;
        } else {
          foreach ($data as $key=>$value){
            switch ($key) {
              case 'tags':
                $output[$key] = $value;
                $videoCat = $this->get_category_for_video($value);
                if (count($videoCat) > 0) {
                  $output['categories'] = $videoCat;
                  //$output = array_merge($output,$videoCat);
                }
              break;
              case 'thumbnailURL':
                $output['thumbnailURL'] = $data->videoStillURL;
              break;
              default:
                $output[$key] = $value;
              break;
            }
            $output['preroll'] = $this->get_preroll_ad($videoid);
            $output['shareLink'] = $this->get_share_link($videoid);
          }
        }
      } else {
        $output['statusmsg'] = 'ERROR_NO_RESULTS';
      }
    }
    return $output;
  }

  /**
   * Get brightcove playlists in player
   * @param  string $player_id  Brightcove player ID
   * @param  array  $params     Brightcove parameters
   * @return array              playlists
   */
  public function get_player_playlists($player_id, $params = array()) {
    $output = array();
    $params['player_id'] = $player_id;
    $params['get_item_count'] = 'true';
    $results = $this->call_brightcove('find_playlists_for_player_id', $params);
    if (array_key_exists('bcdata', $results)) {
      $data = json_decode($results['bcdata']);
      if (count($data)) {
        if (isset($data->error)) {
          $output['statusmsg'] = 'BRIGHTCOVE_ERROR';
          $output['errormsg'] = $data->error->name . ' - ' . $data->error->message;
        } else {
          foreach ($data as $key=>$value){
            switch ($key) {
              case 'page_number':
              case 'page_size':
              break;
              default:
                $output[$key] = $value;
              break;
            }
          }
        }
      } else {
        $output['statusmsg'] = 'ERROR_NO_RESULTS';
      }
    }
    return $output;
  }

  /**
   * Search brightcove videos in DB
   * @param  string $qry    Query string
   * @param  array  $params Brightcove parameters
   * @return array          Search results
   */
  public function search_videos($qry, $page=0, $pagesize=100) {
    $output = array('statusmsg'=>'');
    //$searchQry = trim(preg_replace("/[^a-zA-Z0-9\s\.'\"-:,!\?]/", " ", $qry));
    if (is_numeric($page) === FALSE) {
      $page = 0;
    }
    if (is_numeric($pagesize) === FALSE) {
      $pagesize = 100;
    }
    $start = $page * $pagesize;


    $searchQry = trim($qry);
    if (strlen($searchQry) > 0) {
      $or = db_or()
        ->condition('tags', "%$searchQry%", 'LIKE')
        ->condition('name', "%$searchQry%", 'LIKE')
        ->condition('short_description', "%$searchQry%", 'LIKE');
      $endDateOr = db_or()
        ->condition('end_date', 0)
        ->condition('end_date', strtotime('now'), '>');
      $webOnlyOr = db_or()
        ->isNull('platform')
        ->condition('platform', 'web only', '<>');
      $searchQry = db_select('brightcove_manager_metadata', 'b')
        ->fields('b')
        ->condition($or)
        ->condition('active', 1)
        ->condition('start_date', strtotime('now'), '<')
        ->condition($webOnlyOr)
        ->condition($endDateOr)
        ->orderBy('start_date', 'DESC');

      $searchResults = $searchQry
        ->range($start,$pagesize)
        ->execute();
      $searchCount = $searchQry->range(0,100)->countQuery()->execute()->fetchAssoc();

      if ($searchResults->rowCount() > 0) {
        $output['statusmsg'] = 'SUCCESS';
        $output['page'] = intval($page);
        $output['pagesize'] = intval($pagesize);
        $output['total_count'] = $searchCount['expression'];
        $output['items'] = array();
        foreach ($searchResults as $record) {
          $item = array();
          $item['type'] = 'video';
          $item['id'] = $record->brightcove_id;
          $item['name'] = $record->name;
          $item['shortDescription'] = $record->short_description;
          $item['longDescription'] = $record->long_description;
          $item['startDate'] = (string)$this->convert_time_to_ms($record->start_date);
          $item['tags'] = explode(',', $record->tags);
          $item['videoStillURL'] = $record->video_still_url;
          $item['thumbnailURL'] = $record->video_still_url;
          $item['length'] = (int)$record->video_length;
          $item['playsTotal'] = $record->plays_total;
          $item['FLVURL'] = $record->flv_url;
          $item['preroll'] = $this->get_preroll_ad($item['id']);
          $item['shareLink'] = $this->get_share_link($item['id']);
          if (count($item['tags']) > 0) {
            $videoCat = $this->get_category_for_video($item['tags']);
            if (count($videoCat) > 0) {
              $item['categories'] = $videoCat;
            }
          }
          $output['items'][] = $item;
        }
      } else {
        $output['statusmsg'] = 'ERROR_NO_RESULTS';
      }

    } else {
      $output['statusmsg'] = 'ERROR_NO_RESULTS';
    }

    return $output;
  }

  private function convert_time_to_ms($time) {
    if (is_numeric($time)) {
      if ($time < 2147483647) {
        $time = $time * 1000;
      }
    } else {
      $time = 0;
    }
    return $time;
  }

  /**
   * NO LONGER USED BECAUSE IT WAS TOO SLOW.  KEPT AS BACKUP.
   * Search brightcove videos using brightcove API
   * @param  string $qry    Query string
   * @param  array  $params Brightcove parameters
   * @return array          Search results
   */
  public function search_videos_in_brightcove($qry, $params = array()) {
    $output = array();
    $searchQry = trim(preg_replace("/[^a-zA-Z0-9\s]/", " ", $qry));
    $searchQry = str_replace(' ', '%20', $searchQry);
    if (strlen($searchQry) > 0) {
      $params['all'] = $searchQry;
      $params['get_item_count'] = 'true';
      $params['sort_by'] = 'MODIFIED_DATE:DESC';

      $results = $this->call_brightcove('search_videos', $params);

      if (array_key_exists('bcdata', $results)) {
        $data = json_decode($results['bcdata']);
        //print_r($data); die();
        if (count($data)) {
          if (isset($data->error)) {
            $output['statusmsg'] = 'BRIGHTCOVE_ERROR';
            $output['errormsg'] = $data->error->name . ' - ' . $data->error->message;
          } else {
            foreach ($data as $key=>$value){
              switch ($key) {
                case 'page_number':
                case 'page_size':
                break;
                case 'items':
                  $items = array();
                  foreach ($value as $itemkey => $itemval) {
                    $item = (array)$itemval;
                    if (isset($itemval->tags) && count($itemval->tags) > 0) {
                      $videoCat = $this->get_category_for_video($itemval->tags);
                      if (count($videoCat) > 0) {
                        $item['categories'] = $videoCat;
                      }
                    }
                    unset($item['customFields']);
                    $items[] = $item;
                  }
                  $output['items'] = $items;
                break;
                default:
                  $output[$key] = $value;
                break;
              }
            }
          }
        } else {
          $output['statusmsg'] = 'ERROR_NO_RESULTS';
        }
      }
    } else {
      $output['statusmsg'] = 'ERROR_NO_RESULTS';
    }

    return $output;
  }

  /**
   * Call brightcove API
   * @param  string  $command  Brightcove command
   * @param  array   $params   Brightcove parameters
   * @param  integer $usecache Use caceh (0/1)
   * @return array             Results from brightcove
   */
  private function call_brightcove($command, $params = array(), $usecache = 1, $savecache = 1){
    $results = array();
    $str_params = '';
    $cache = '';
    if (isset($_GET['usecache'])) {
      $usecache = $_GET['usecache'];
    }
    $params['media_delivery'] = 'http_ios';
    switch (PLATFORM) {
      case 'blackberry':
        $params['none'] = 'platform:web+only&none=tag:ad';
      break;
      case 'playstation':
        $$params['none'] = 'platform:web+only&none=tag:ad';
      break;
      default:
        $params['none'] = 'platform:web+only&none=tag:ad';
      break;
    }
    if (count($params) > 0) {
      foreach($params as $key=>$value) {
        $str_params .= "&$key=$value";
      }
    }
    $cache_id = 'command=' . $command . $str_params;

    if ($usecache == 1) {
      $cache = $this->cache_get($cache_id);
      if (strlen($cache) > 0) {
        $results['bcdata'] = $cache;
      } else {
        $usecache = 0;
      }
    }

    if ($usecache == 0) {
      //echo BC_URL . 'token=' . BC_READ_TOKEN . '&command=' . $command . '&output=' . $this->bc_output . $str_params; die();
      $results['bcdata'] = file_get_contents(BC_URL . 'token=' . BC_READ_TOKEN . '&command=' . $command . '&output=' . $this->bc_output . $str_params);
      // If no error, cache results
      if (strpos($results['bcdata'], '"error"') === false) {
        if ($savecache == 1) {
          $this->cache_results($cache_id, $results['bcdata']);
        }
      }
    }

    return $results;
  }

  /**
   * Update cache
   * @return void
   */
  public function update_cache() {
    $qry = "select * from cache_brightcove where cid not like 'command=search_videos%' order by cid";
    $cache = db_select('cache_brightcove', 'c')
      ->fields('c', array('parameters', ))
      ->condition('parameters', 'command=search_videos%', 'not like')
      ->orderBy('parameters', 'ASC')
      ->execute();
    foreach ($cache as $record) {
      $cache_id = $record->parameters;
      echo BC_URL . 'token=' . BC_READ_TOKEN . '&' . $cache_id . "\n";
      $data = file_get_contents(BC_URL . 'token=' . BC_READ_TOKEN . '&' . $cache_id);
      // If no error, cache results
      if (strpos($data, '"error"') === false) {
        $this->cache_results($cache_id, $data);
      }
    }
  }

  /**
   * Cache Brightcove results
   * @param  string $cache_id  Cache ID
   * @param  string $data      $data
   * @return void
   */
  private function cache_results($cache_id,$data) {
    // Save to DB
    if ($data != 'null') {
      db_merge('cache_brightcove')
        ->key(array('cid' => md5($cache_id)))
        ->fields(array(
              'data' => $data,
              'parameters' => $cache_id,
              'created' => time(),
        ))
        ->execute();
    }
  }

  /**
   * Get Cache from DB
   * @param  string $cache_id Cache ID
   * @return string           Cache Value
   */
  private function cache_get($cache_id) {
    $data = '';
    // Save to DB
    $cache = db_select('cache_brightcove', 'c')
      ->fields('c', array('data', 'parameters', 'created'))
      ->condition('cid', md5($cache_id))
      ->execute();
    $num_of_results = $cache->rowCount();
    if($num_of_results > 0) {
      foreach ($cache as $record) {
        $data = $record->data;
      }
    }
    return $data;
  }

  /**
   * Format output for JSON
   * @param  array $input  array input
   * @return string        JSON output
   */
  public function format_output($input, $show_status) {
    $output = array();
    $output = $input;
    if (array_key_exists('statusmsg', $input) && strlen($input['statusmsg'])) {
      $output = array_merge($this->parse_status_code($input['statusmsg']), $output);
    } else {
      if ($show_status) {
        $output = array_merge($this->parse_status_code('SUCCESS'), $output);
      }
    }

    if (array_key_exists('bcdata', $input)) {
      $output = array_merge($output, (array)json_decode($input['bcdata']));
    }
    if (array_key_exists('statuscode', $output) && $output['statuscode'] != 0) {
        // Error, set no caching
      header("Expires: Mon, 1 Jan 1990 05:00:00 GMT");
      header("Last-Modified: " . gmdate("D, d M Y H:i:s") . " GMT");
      header("Cache-Control: no-store, no-cache, must-revalidate");
      header("Cache-Control: post-check=0, pre-check=0", false);
      header("Pragma: no-cache");
    }
    return json_encode($output);
  }

  /**
   * Parse Status Code
   * @param  string $strCode  Status Code
   * @return array            Status array
   */
  public function parse_status_code($strCode = '') {
    $status = array('statuscode' => 0, 'statusmsg' => '');

    if (strlen($strCode) && defined($strCode)) {
      $status['statusmsg'] = $strCode;
      $status['statuscode'] = constant($strCode);
    }

    return $status;
  }
}
