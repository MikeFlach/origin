<?php

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

  public function get_playlist_by_reference_id($reference_id, $params = array(), $page = 0) {
    $page_size = 10;
    $output = array('errorcode' => 0, 'items' => array());
    $params['reference_id'] = $reference_id;
    $results = $this->call_brightcove('find_playlist_by_reference_id', $params);
    if (array_key_exists('bcdata', $results)) {
      $data = json_decode($results['bcdata']);
      //print_r($data); die();
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
    }
    return $output;
  }

  public function get_player_playlists($player_id) {
    $results = $this->call_brightcove('find_playlists_for_player_id', array('player_id' => $player_id, 'get_item_count'=>'true'));
    return $results;
  }

  private function call_brightcove($command, $params = array()){
    $results = array('errorcode' => 0, 'msg' => '');
    $str_params = '';
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
    /*if (array_key_exists('errorcode', $input)) {
      $output['errorcode'] = $input['errorcode'];
    }
    if (array_key_exists('msg', $input)) {
      $output['msg'] = $input['msg'];
    }*/
    if (array_key_exists('bcdata', $input)) {
      $output = array_merge($output, (array)json_decode($input['bcdata']));
    }
    return json_encode($output);
  }
}
