<?php

/*
 * Sony Rebuffering URL - for collecting stats
*/

chdir($_SERVER['DOCUMENT_ROOT']);
define('DRUPAL_ROOT', getcwd());
require_once $_SERVER['DOCUMENT_ROOT'] . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_DATABASE);

save_stats($_GET);

function save_stats($params) {

  if (!array_key_exists('asset_id', $params)) {
    $params['asset_id'] = '';
  }
  if (!array_key_exists('rebuffering_attempts', $params)) {
    $params['rebuffering_attempts'] = 0;
  }
  if (!array_key_exists('video_exit_timestamp', $params)) {
    $params['video_exit_timestamp'] = 0;
  }
  if (!array_key_exists('video_exit_code', $params)) {
    $params['video_exit_code'] = -1;
  }
  if (!array_key_exists('link_speed', $params)) {
    $params['link_speed'] = 0;
  }
  if (!array_key_exists('sid', $params)) {
    $params['sid'] = '';
  }
  if (!array_key_exists('suit', $params)) {
    $params['suit'] = '';
  }
  if (!array_key_exists('esn', $params)) {
    $params['esn'] = '';
  }

  $db_stats = db_insert('stats_sonytv')
    ->fields(array(
      'asset_id' => $params['asset_id'],
      'rebuffering_attempts' => $params['rebuffering_attempts'],
      'video_exit_timestamp' => $params['video_exit_timestamp'],
      'video_exit_code' => $params['video_exit_code'],
      'link_speed' => $params['link_speed'],
      'sid' => $params['sid'],
      'suit' => $params['suit'],
      'esn' => $params['esn'],
      'created' => REQUEST_TIME,
    ))
    ->execute();
}
