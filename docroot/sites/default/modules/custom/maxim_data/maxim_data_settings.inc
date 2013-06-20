<?php
  // $Id$
  
  function _maxim_data_settings($action) {
    $today = date("Y-m-d");

    switch ($action) {
      case 'jumbotron' :  
        $settings['jt_image_style'] = 'jumbotron';
        $settings['jt_thumb_style'] = 'jumbotron_carousel_icon';
        $settings['jt_cache_time_minutes'] = '5'; 
        $settings['jt_caching'] = true;
      break;
    }

    return ($settings);
  }
