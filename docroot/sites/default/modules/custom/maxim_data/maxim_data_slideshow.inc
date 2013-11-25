<?php
// $Id$

function _maxim_data_slideshow_retreive ($nid, $cache_break, $debug) {
  try {
    $settings = _maxim_data_settings('slideshow');
    
    if ($cache_break) {
      cache_clear_all($settings['slideshow_cache_name'], 'cache', TRUE);
    }
    
    if (!$settings['slideshow_caching']) {
      $slideshow_data = _maxim_data_get_slideshow($nid); 
      _maxim_data_append_cache_info($slideshow_data, DATA_NOT_CACHED, DATA_NOT_FROM_CACHE, $debug);
    }
    else {
      $slideshow_data = &drupal_static(__FUNCTION__); 
      
      // do we have any cached data?
      $cache_data = cache_get($profile_settings['slideshow_cache_name']); 
     
      if ($cache_data) {
        $cached_full = $cache_data->data;
        //if we have cahched data, do we have cached data for this particular nid?
        if (isset($cache_data->data[$nid])) {
          // retreive cached profile data 
          $slideshow_data = $cache_data->data[$nid];
          _maxim_data_append_cache_info($slideshow_data, DATA_CACHED, DATA_FROM_CACHE, $debug); 
        }
      }
      

      if (!isset($slideshow_data)) {
        if ($cache = cache_get($settings['$slideshow_cache_name'])) {
          $slideshow_data = $cache->data;
           _maxim_data_append_cache_info($slideshow_data, DATA_CACHED, DATA_FROM_CACHE, $debug);
        }
        else {
          $slideshow_data = _maxim_data_get_slideshow($nid); 
          
          $nid_data_cache = isset($cached_full) ? $cached_full->data : array();
          $nid_data_cache[$nid] = $slideshow_data;
          cache_set($settings['$slideshow_cache_name'], $nid_data_cache, 'cache', time() + 60*($settings['$slideshow_cache_time_minutes']));
          _maxim_data_append_cache_info($slideshow_data, DATA_CACHED, DATA_NOT_FROM_CACHE, $debug); 
        }
      }
    }
    
    _maxim_data_append_error_info($slideshow_data, NULL, $debug);
    return($slideshow_data);
  }
  catch (Exception $e) {
    $slideshow_data = array();
    
    _maxim_data_append_error_info($slideshow_data, $e, $debug);
    return ($slideshow_data);
  }
}
