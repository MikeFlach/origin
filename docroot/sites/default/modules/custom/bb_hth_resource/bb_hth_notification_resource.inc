<?php
// $Id$
require_once ( dirname(__FILE__) . '/bb_hth_common.inc');

function _bb_hth_notification_retreive () {
  $return_data = array();
  $current_round = variable_get('hth_contest_week', 0);
  //$current_status = variable_get('hth_contest_status', 'break');
  $current_status = 'break';
  
  switch ($current_round) {
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
      $msg = "WEEK $current_round VOTING HAS BEGUN!";
      break;
    case 'semi-finals':
      $msg = "SEMIFINALS VOTING HAS BEGUN!";
      break;
     case 'finals':
      $msg = "FINALS VOTING HAS BEGUN!";
      break;
  }
  
  // $return_data['items']['currentRound'] = $current_round;
  // $return_data['items']['notificationMsg'] = $msg;
  // $return_data['items']['contestStatus'] = $current_status;
  
  $return_data['items']['currentRound'] = "semi-finals";
  $return_data['items']['notificationMsg'] = "SEMIFINALS VOTING HAS BEGUN!";
  $return_data['items']['contestStatus'] = "break";
 
  return($return_data);
}
