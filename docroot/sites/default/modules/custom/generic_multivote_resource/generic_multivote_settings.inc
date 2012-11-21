<?php
  // $Id$

  function _generic_mv_settings($campaign) {
    //ADD NEW CASE STATEMENT FOR EACH YEAR
    $generic_mv_settings = array();
    $today = date("Y-m-d");
    
    switch ($campaign) {
      case 'hot100-2013' :
        $begin_date = "2012-10-17";
        $end_date = "2012-12-25";

        $generic_mv_settings['active'] = _is_between_dates($begin_date, $today, $end_date);
        $generic_mv_settings['limit_type'] = 'daily';  
        $generic_mv_settings['voting_api_tag'] = 'hot100-2013';
      break;

      default :
        $generic_mv_settings['active'] = false;
        $generic_mv_settings['btn_txt'] = ''; 
        $generic_mv_settings['response_txt'] = '';
        $generic_mv_settings['btn_class'] = '';
        $generic_mv_settings['limit_type'] = '';  
        $generic_mv_settings['limit_txt'] = '';
        $generic_mv_settings['inactive_txt'] = '';
        $generic_mv_settings['voting_api_tag'] = '-2013';
      break;
    }
    
    return ($generic_mv_settings);
  }