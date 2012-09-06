<?php

// Status codes
define('SUCCESS', 0);
define('ERROR_UNKNOWN_REQUEST', -1);
define('ERROR_NO_RESULTS', -2);

/*
 * Video Feed API
 */
class VideoFeedAPI {
  private $bc_token = 'CX1YvsC6MvJ-6FddP41yjMQxH1sktJjDEH4QV0p-RQPZKyLwkfgCow..';
  private $bc_url = 'http://api.brightcove.com/services/library?';
  private $bc_output = 'json';

  public function get_all_videos(){
    $results = $this->call_brightcove('find_all_videos');
    return $results;
  }

  /*
   * Get list of videos by passing in reference ID of playlist
   */
  public function get_playlist_by_reference_id($reference_id, $params = array(), $page = 0) {
    $page_size = 10;
    $output = array('items' => array());
    $params['reference_id'] = $reference_id;
    $results = $this->call_brightcove('find_playlist_by_reference_id', $params);
    if (array_key_exists('bcdata', $results)) {
      $data = json_decode($results['bcdata']);
      //print_r($data); die();
      if (count($data)) {
        foreach ($data as $key=>$value){
          switch ($key) {
            case 'videos':
              if (count($value) > 0) {
                for($item_id=0; $item_id < count($value); $item_id++) {
                  $output['items'][] = array_merge(array('type'=>'video'), (array)$value[$item_id]);
                }
              }
            break;
          }
        }
      } else {
        $output['statusmsg'] = 'ERROR_NO_RESULTS';
      }
    }
    return $output;
  }


  public function get_playlist_overview($reference_id, $params) {
    $output = array();
    $params['reference_id'] = $reference_id;
    $results = $this->call_brightcove('find_playlist_by_reference_id', $params);
    if (array_key_exists('bcdata', $results)) {
      $data = json_decode($results['bcdata']);
      //print_r($data); die();
      if (count($data)) {
        foreach ($data as $key=>$value){
          switch ($key) {
            case 'videos':
              $output['num_videos'] = count($value);
            break;
            default:
              $output[$key] = $value;
            break;
          }

        }
      } else {
        $output['statusmsg'] = 'ERROR_NO_RESULTS';
      }
    }
    return $output;
  }

  public function get_featured_videos($player_id, $params = array()) {
    $num_featured_videos = 2;
    $output = array('items' => array());
    $params['player_id'] = $player_id;
    $params['get_item_count'] = 'true';
    $results = $this->call_brightcove('find_playlists_for_player_id', $params);
    if (array_key_exists('bcdata', $results)) {
      $data = json_decode($results['bcdata']);
      if (count($data)) {
        // print_r($data); die();
        foreach ($data as $key=>$value){
          //echo $key . "\n";
          switch ($key) {
            case 'page_number':
            case 'page_size':
            break;
            case 'items':
              for ($i=0; $i < count($value); $i++) {
                // If playlist is featured videos, get videos
                if ($value[$i]->referenceId == 'pl_featured_videos') {
                  $videoCt=0;
                  foreach ($value[$i]->videos as $video) {
                    if (++$videoCt <= $num_featured_videos) {
                      $output['items'][] = array_merge(array('type'=>'video'), (array)$video);
                    } else {
                      break;
                    }
                  }
                } else {
                  // If not featured videos, get series information
                   //print_r($value[$i]); die();
                  $output['items'][] = array_merge(array('type'=>'series'), array('name'=> $value[$i]->name, 'referenceid'=> $value[$i]->referenceId, 'shortDescription'=>$value[$i]->shortDescription, 'thumbnailURL' => $value[$i]->thumbnailURL));
                }
              }
            break;
            default:
              $output[$key] = $value;
            break;
          }
        }
      } else {
        $output['statusmsg'] = 'ERROR_NO_RESULTS';
      }
    }
    return $output;
  }

  public function get_video_by_id($videoid, $params = array()) {
    $output = array();
    $params['video_id'] = $videoid;
    $results = $this->call_brightcove('find_video_by_id', $params);
    if (array_key_exists('bcdata', $results)) {
      $data = json_decode($results['bcdata']);
      if (count($data)) {
        foreach ($data as $key=>$value){
          $output[$key] = $value;
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
      } else {
        $output['statusmsg'] = 'ERROR_NO_RESULTS';
      }
    }
    return $output;
  }

  public function search_videos($qry, $params = array()) {
    $output = array();
    $params['all'] = $qry;
    $params['get_item_count'] = 'true';
    $params['sort_by'] = 'MODIFIED_DATE:DESC';
    $results = $this->call_brightcove('search_videos', $params);

    if (array_key_exists('bcdata', $results)) {
      $data = json_decode($results['bcdata']);
      //print_r($data); die();
      if (count($data)) {
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
      } else {
        $output['statusmsg'] = 'ERROR_NO_RESULTS';
      }
    }
    return $output;
  }

  private function call_brightcove($command, $params = array()){
    $results = array();
    $str_params = '';
    $params['media_delivery'] = 'http_ios';
    if (count($params) > 0) {
      foreach($params as $key=>$value) {
        $str_params .= "&$key=$value";
      }
    }

    $results['bcdata'] = file_get_contents($this->bc_url . 'token=' . $this->bc_token . '&command=' . $command . '&output=' . $this->bc_output . $str_params);
    return $results;
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
