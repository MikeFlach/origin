<?php
  // $Id$

  function _maxim_data_settings($action) {
    $today = date("Y-m-d");

    define('DATA_CACHED', true);
    define('DATA_NOT_CACHED', false);
    define('DATA_FROM_CACHE', true);
    define('DATA_NOT_FROM_CACHE', false);
    
    $settings['jt-url'] = "http://" . $_SERVER['SERVER_NAME'] . '/services/data/jumbotron';
    $settings['magazine-url'] = "http://" . $_SERVER['SERVER_NAME'] . '/services/data/in-the-magazine';
    $settings['hp-url'] = "http://" . $_SERVER['SERVER_NAME'] . '/services/data/homepage';  
    $settings['profile-url'] = "http://" . $_SERVER['SERVER_NAME'] . '/services/data/profile';
    
    switch ($action) {
      case 'jumbotron' :
        $settings['jt_cache_name'] = 'maxim_data_jumbotron';
        $settings['jt_image_style'] = 'jumbotron';
        $settings['jt_thumb_style'] = 'jumbotron_carousel_icon';
        $settings['jt_cache_time_minutes'] = '1'; 
        $settings['jt_caching'] = true;
      break;
    
      case 'magazine' :
        $settings['magazine_cache_name'] = 'maxim_data_magazine';
        $settings['magazine_image_style'] = 'thumbnail_large';
        $settings['magazine_cache_time_minutes'] = '1'; 
        $settings['magazine_caching'] = true;      
      break;
    
      case 'homepage' :
        $settings['hp_cache_name'] = 'maxim_data_homepage';
        $settings['hp_image_style'] = 'thumbnail_large';
        $settings['hp_cache_time_minutes'] = '1'; 
        $settings['hp_caching'] = true;
      break;
    
      case 'profile' :
        $settings['profile_cache_name'] = 'maxim_data_profile';
        $settings['profile_cache_time_minutes'] = '1'; 
        $settings['profile_caching'] = true;
    }

    return ($settings);
  }