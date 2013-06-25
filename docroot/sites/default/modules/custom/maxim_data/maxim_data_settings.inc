<?php
  // $Id$

  function _maxim_data_settings($action) {
    $today = date("Y-m-d");

    switch ($action) {
      case 'jumbotron' :
        define('MAXIM_DATA_JUMBOTRON_CACHED', true);
        define('MAXIM_DATA_JUMBOTRON_NOT_CACHED', false);
        define('MAXIM_DATA_JUMBOTRON_FROM_CACHE', true);
        define('MAXIM_DATA_JUMBOTRON_NOT_FROM_CACHE', false);
        
        $settings['jt_cache_name'] = 'maxim_data_jumbotron';
        $settings['jt_image_style'] = 'jumbotron';
        $settings['jt_thumb_style'] = 'jumbotron_carousel_icon';
        $settings['jt_cache_time_minutes'] = '5'; 
        $settings['jt_caching'] = true;
      break;
    
      case 'magazine' :
        define('MAXIM_DATA_MAGAZINE_CACHED', true);
        define('MAXIM_DATA_MAGAZINE_NOT_CACHED', false);
        define('MAXIM_DATA_MAGAZINE_FROM_CACHE', true);
        define('MAXIM_DATA_MAGAZINE_NOT_FROM_CACHE', false);
        
        $settings['magazine_cache_name'] = 'maxim_data_magazine';
        $settings['magazine_image_style'] = 'thumbnail_large';
        $settings['magazine_cache_time_minutes'] = '5'; 
        $settings['magazine_caching'] = true;
      break;
    
      case 'homepage' :
        define('MAXIM_DATA_HOMEPAGE_CACHED', true);
        define('MAXIM_DATA_HOMEPAGE_NOT_CACHED', false);
        define('MAXIM_DATA_HOMEPAGE_FROM_CACHE', true);
        define('MAXIM_DATA_HOMEPAGE_NOT_FROM_CACHE', false);
        
        $settings['hp_cache_name'] = 'maxim_data_homepage';
        $settings['hp_cache_time_minutes'] = '5'; 
        $settings['hp_caching'] = true;
      break;
    }

    return ($settings);
  }
