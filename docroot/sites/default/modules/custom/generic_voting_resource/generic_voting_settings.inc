<?php
  // $Id$

  function _profile_campaign_settings($profile_campaign_name) {
    $profile_vc_data = array();
    $today = date("Y-m-d");

    //ADD NEW CASE STATEMENT FOR EACH GENERIC PROFILE VOTING CAMPAIGN
    switch ($profile_campaign_name) {
      case 'gprofile_athlete_bodyfort' :
        $begin_date = "2012-10-17";
        $end_date = "2012-12-25";

        $profile_vc_data['voting_campaign'] = $profile_campaign_name;
        $profile_vc_data['active'] = _is_date_between($begin_date, $today, $end_date);
        $profile_vc_data['btn_txt'] = 'Vote For Me!';
        $profile_vc_data['response_txt'] = 'Thanks for voting! Remember to come back daily and vote again.';
        $profile_vc_data['btn_class'] = 'vb_athlete_bodyfort';
        $profile_vc_data['limit_type'] = 'daily';  
        $profile_vc_data['limit_txt'] = 'Thanks for voting! Remember to come back daily and vote again.';
        $profile_vc_data['inactive_txt'] = 'Voting is closed!';
        $profile_vc_data['voting_api_tag'] = 'athlete_bodyfort';
        $profile_vc_data['header_image_url'] = 'http://cdn2.maxim.com/maxim/sites/default/files/body_fortress_banner.jpg';
        //make sure to put styling of "display:block; margin-top:-1px;" if additional data is 1x1 img
        $profile_vc_data['additional_header_data'] = '';
        $profile_vc_data['prev_btn_img'] = 'http://edit.maxim.com/sites/default/files/generic_btn_prev.png';
        $profile_vc_data['next_btn_img'] = 'http://edit.maxim.com/sites/default/files/generic_btn_next.png';
        $profile_vc_data['show_slider'] = true;
      break;
    
      case 'gprofile_military_ciroc' :
        $begin_date = "2012-10-17";
        $end_date = "2012-10-26";

        $profile_vc_data['voting_campaign'] = $profile_campaign_name;
        $profile_vc_data['active'] = _is_date_between($begin_date, $today, $end_date);
        $profile_vc_data['btn_txt'] = 'Vote For Me!';
        $profile_vc_data['response_txt'] = 'Thanks for voting! Remember to come back daily and vote again.';
        $profile_vc_data['btn_class'] = 'vb_military_ciroc';
        $profile_vc_data['limit_type'] = 'daily';  
        $profile_vc_data['limit_txt'] = 'Thanks for voting! Remember to come back daily and vote again.';
        $profile_vc_data['inactive_txt'] = 'Voting is closed!';
        $profile_vc_data['voting_api_tag'] = 'military_ciroc';
        $profile_vc_data['header_image_url'] = 'http://cdn2.maxim.com/maxim/sites/default/files/Americano_980x98_V3.jpg';
        $profile_vc_data['header_image_link'] = 'http://ad.doubleclick.net/jump/N6543.3377.MAXIM.COM/B6782127.15;sz=1x1;ord=[timestamp]?';
        //make sure to put styling of "display:block; margin-top:-1px;" if additional data is 1x1 img
        $profile_vc_data['additional_header_data'] = '<img src="http://ad.doubleclick.net/ad/N6543.3377.MAXIM.COM/B6782127.15;sz=1x1;ord=[timestamp]?" border=0 width=1 height=1 alt="Advertisement" style="display:block; margin-top:-1px;">';
        $profile_vc_data['prev_btn_img'] = 'http://edit.maxim.com/sites/default/files/generic_btn_prev.png';
        $profile_vc_data['next_btn_img'] = 'http://edit.maxim.com/sites/default/files/generic_btn_next.png';
        $profile_vc_data['show_slider'] = true;
      break;

      default :
        $profile_vc_data['voting_campaign'] = '';
        $profile_vc_data['active'] = false; 
        $profile_vc_data['btn_txt'] = '';
        $profile_vc_data['response_txt'] = '';
        $profile_vc_data['btn_class'] = '';
        $profile_vc_data['limit_type'] = '';
        $profile_vc_data['limit_txt'] = '';
        $profile_vc_data['inactive_txt'] = '';
        $profile_vc_data['voting_api_tag'] = '';
        $profile_vc_data['header_image_url'] = '';
        $profile_vc_data['header_image_link'] = '';
        $profile_vc_data['additional_header_data'] = '';
        $profile_vc_data['prev_btn'] = '';
        $profile_vc_data['next_btn'] = '';
        $profile_vc_data['prev_btn_img'] = '';
        $profile_vc_data['next_btn_img'] = '';
        $profile_vc_data['show_slider'] = true;
      break;
    }

    return ($profile_vc_data);
  }
