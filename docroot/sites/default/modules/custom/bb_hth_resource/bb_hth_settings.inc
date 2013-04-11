<?php
  // $Id$
  require_once ( dirname(__FILE__) . '/bb_hth_common.inc');
  
  function _bb_campaign_settings($profile_campaign_name) {
    $profile_vc_data = array();
    $today = date("Y-m-d");

    switch ($profile_campaign_name) {
      case 'hth' :  
        $begin_date = "";
        $end_date = "";

        $profile_vc_data['voting_campaign'] = $profile_campaign_name;
        $profile_vc_data['active'] = _date_between($begin_date, $today, $end_date);
        $profile_vc_data['btn_txt'] = 'Vote For Me!'; 
        $profile_vc_data['response_txt'] = 'Thanks for voting!';
        $profile_vc_data['limit_type'] = 'daily';  
        $profile_vc_data['limit_txt'] = 'Thanks for voting! Remember to come back daily and vote again.';
        $profile_vc_data['inactive_txt'] = 'Voting is closed!';
        $profile_vc_data['voting_api_tag'] = 'hth-2014-initial-round';
      break;
    }

    return ($profile_vc_data);
  }
