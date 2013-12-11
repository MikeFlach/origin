<?php
  // $Id$

  function _generic_mv_settings($campaign) {
    //ADD NEW CASE STATEMENT FOR EACH YEAR
    $generic_mv_settings = array();
    $today = date("Y-m-d");
    
    //More settings are in views preprocess
    switch ($campaign) {
      case 'hot100-2013' :
        $begin_date = "2012-10-17";
        $end_date = "2012-12-25";

        $generic_mv_settings['active'] = _is_between_dates($begin_date, $today, $end_date);
        $generic_mv_settings['limit_type'] = 'daily';  
        $generic_mv_settings['voting_api_tag'] = 'hot100-2013';
        $generic_mv_settings['response_txt'] = 'Thanks for voting!';
      break;
    
      case 'hot100-2014' :
        $begin_date = "2013-10-17";
        $end_date = "2015-12-25";

        $generic_mv_settings['active'] = _is_between_dates($begin_date, $today, $end_date);
        $generic_mv_settings['limit_type'] = 'daily';  
        $generic_mv_settings['voting_api_tag'] = 'hot100-2014';
        $generic_mv_settings['response_txt'] = 'Thanks for voting!';
        
        $generic_mv_settings['btn_txt'] = 'Vote For Me!';
        $generic_mv_settings['btn_class'] = 'hot100-2013';
        $generic_mv_settings['main_class'] = 'hot100vote';
        $generic_mv_settings['custom_vote_txt'] = 'Your vote has been counted!';
        $generic_mv_settings['limit_txt'] = 'Vote again tomorrow!';
        $generic_mv_settings['inactive_txt'] = 'Voting is closed!';
        $generic_mv_settings['campaign'] = $campaign;
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