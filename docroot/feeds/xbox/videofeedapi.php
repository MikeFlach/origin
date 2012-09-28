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
// Other variables
define('NUM_FEATURED_VIDEOS', 8); // Display number of featured videos on main pivot page
define('DEFAULT_VIDEO_RATING', 'PG-13');

/**
 * Video Feed API
 */
class VideoFeedAPI {
  private $bc_output = 'json';

  public function get_ad($params, $page = 'default') {
    $activityLink = 'http://www.maxim.com/feeds/xbox/?cmd=track';
    $output = array('items' => array());
    $results = $this->get_playlist_by_reference_id('pl_xbox_ad', $params);
    foreach ($results['items'] as $item) {
      $item['activityLink'] = $activityLink . '&id=' . $item['id'] . '&page=' . $page . '&t=[timestamp]';
      $output['items'][] = $item;
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
    $params = array('video_fields' => 'id,name,shortDescription,longDescription,videoStillURL,thumbnailURL,length,playsTotal,startDate,FLVURL,tags','get_item_count'=>'true');
    // Get all videos
    $params['page_size'] = $pagesize;
    $params['page_number'] = $page;
    $params['sort_by'] = 'PUBLISH_DATE';
    $params['sort_order'] = 'DESC';
    $results = $this->call_brightcove('find_all_videos', $params);
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
              case 'videoIds':
                $output[$key] = $value;
              break;
              case 'items':
                foreach ($value as $video) {
                  $item = (array)$video;
                  foreach ($item as $itemkey => $itemval) {
                    if ($itemkey == 'tags' && count($itemval)) {
                      $videoCat = $this->get_category_for_video($itemval);
                      if (strlen($videoCat['categoryType']) > 0) {
                        $item = array_merge($item,$videoCat);
                      }
                    }
                  }
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
   */
  public function get_playlist_by_reference_id($reference_id, $params = array(), $page = 0, $page_size = 100) {
    $output = array('items' => array());
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
              case 'videoIds':
                $output[$key] = $value;
              break;
              case 'videos':
                if (count($value) > 0) {
                  for($item_id=0; $item_id < count($value); $item_id++) {
                    $video_item = array_merge(array('type'=>'video'), (array)$value[$item_id]);
                    //$video_item = array_merge(array('type'=>'video', 'rating' => DEFAULT_VIDEO_RATING), (array)$value[$item_id]);
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
            $videoCat = $this->get_category_for_video($value);
            if (strlen($videoCat['categoryType']) > 0) {
              $video_output = array_merge($video_output,$videoCat);
            }
          }
        break;
        default:
          $video_output[$key] = $value;
        break;
      }
    }
    return $video_output;
  }


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
                        //$video_item = array_merge(array('type'=>'video', 'rating' => DEFAULT_VIDEO_RATING), (array)$video);
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
                      $output['items'][] = array_merge(array('type'=>$video_type), array('name'=> $value[$i]->name, 'referenceId'=> $value[$i]->referenceId, 'shortDescription'=>$value[$i]->shortDescription, 'thumbnailURL' => $value[$i]->thumbnailURL));
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

  public function get_category_for_video($tags) {
    $playlists = array(PLAYER_SERIES, PLAYER_CHANNELS);
    $playlist = array('categoryName' => '', 'categoryReferenceId' => '', 'categoryType' => '');
    $params = array('video_fields' => '', 'playlist_fields' => 'referenceid,name,shortDescription,thumbnailURL,filterTags');
    foreach ($playlists as $pl) {
      $data = $this->get_player_playlists($pl, $params);
      foreach ($data['items'] as $cat) {
        $test = array_intersect($cat->filterTags,$tags);
        if (count($test)) {
          $playlist['categoryName'] = $cat->name;
          $playlist['categoryReferenceId'] = $cat->referenceId;
          switch ($pl) {
            case PLAYER_SERIES:
              $playlist['categoryType'] = 'series';
            break;
            case PLAYER_CHANNELS:
              $playlist['categoryType'] = 'channel';
            break;
          }
          break;
        }
      }
      if (strlen($playlist['categoryName']) > 0) {
        break;
      }
    }
    //print_r($playlist); die();
    return $playlist;
  }

  public function get_video_by_id($videoid, $params = array()) {
    $output = array();
    $params['video_id'] = $videoid;
    $results = $this->call_brightcove('find_video_by_id', $params);
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
                $videoCat = $this->get_category_for_video($value);
                if (strlen($videoCat['categoryType']) > 0) {
                  $output = array_merge($output,$videoCat);
                }
              break;
              default:
                $output[$key] = $value;
              break;
            }


          }
          //$output['rating'] = DEFAULT_VIDEO_RATING;
        }
      } else {
        $output['statusmsg'] = 'ERROR_NO_RESULTS';
      }
    }
    return $output;
  }

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

  public function search_videos($qry, $params = array()) {
    $output = array();
    $searchQry = trim(preg_replace("/[^a-zA-Z0-9\s]/", "", $qry));
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
                      if (strlen($videoCat['categoryType']) > 0) {
                        $item = array_merge($item,$videoCat);
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

  private function call_brightcove($command, $params = array(), $usecache = 1){
    $results = array();
    $str_params = '';
    $cache = '';
    if (isset($_GET['usecache'])) {
      $usecache = $_GET['usecache'];
    }
    $params['media_delivery'] = 'http_ios';
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
        $this->cache_results($cache_id, $results['bcdata']);
      }
    }

    return $results;
  }

  /**
   * Update cache
   */
  public function update_cache() {
    $qry = "select * from cache_brightcove where cid not like 'command=search_videos%' order by cid";
    $cache = db_select('cache_brightcove', 'c')
      ->fields('c', array('cid', ))
      ->condition('cid', 'command=search_videos%', 'not like')
      ->orderBy('cid', 'ASC')
      ->execute();
    foreach ($cache as $record) {
      $cache_id = $record->cid;
      echo BC_URL . 'token=' . BC_READ_TOKEN . '&' . $cache_id . "\n";
      $data = file_get_contents(BC_URL . 'token=' . BC_READ_TOKEN . '&' . $cache_id);
      // If no error, cache results
      if (strpos($data, '"error"') === false) {
        $this->cache_results($cache_id, $data);
      }
    }
  }

  private function cache_results($cache_id,$data) {
    // Save to DB
    db_merge('cache_brightcove')
      ->key(array('cid' => $cache_id))
      ->fields(array(
            'data' => $data,
            'created' => time(),
      ))
      ->execute();
  }

  private function cache_get($cache_id) {
    $data = '';
    // Save to DB
    $cache = db_select('cache_brightcove', 'c')
      ->fields('c', array('data', 'created'))
      ->condition('cid', $cache_id)
      ->execute();
    $num_of_results = $cache->rowCount();
    if($num_of_results > 0) {
      foreach ($cache as $record) {
        $data = $record->data;
      }
    }
    return $data;
  }

  public function format_output($input) {
    $output = array();
    $output = $input;
    if (array_key_exists('statusmsg', $input) && strlen($input['statusmsg'])) {
      $output = array_merge($this->parse_status_code($input['statusmsg']), $output);
    } else {
     $output = array_merge($this->parse_status_code('SUCCESS'), $output);
    }

    if (array_key_exists('bcdata', $input)) {
      $output = array_merge($output, (array)json_decode($input['bcdata']));
    }
    if ($output['statuscode'] != 0) {
        // Error, set no caching
      header("Expires: Mon, 1 Jan 1990 05:00:00 GMT");
      header("Last-Modified: " . gmdate("D, d M Y H:i:s") . " GMT");
      header("Cache-Control: no-store, no-cache, must-revalidate");
      header("Cache-Control: post-check=0, pre-check=0", false);
      header("Pragma: no-cache");
    }
    return json_encode($output);
  }

  public function parse_status_code($strCode = '') {
    $status = array('statuscode' => 0, 'statusmsg' => '');

    if (strlen($strCode) && defined($strCode)) {
      $status['statusmsg'] = $strCode;
      $status['statuscode'] = constant($strCode);
    }

    return $status;
  }
}
