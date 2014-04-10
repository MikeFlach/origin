<?php
// $Id$

function _maxim_data_slideshow_retreive ($nid, $cache_break, $debug, $renderable) {
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
    
    $slideshow_return_data = $renderable ? _maxim_data_renderable_slideshow($slideshow_data) : $slideshow_data;
    
    _maxim_data_append_error_info($slideshow_return_data, NULL, $debug);
    return($slideshow_return_data);
  }
  catch (Exception $e) {
    $slideshow_data = array();
    
    _maxim_data_append_error_info($slideshow_data, $e, $debug);
    return ($slideshow_data);
  }
}

function _maxim_data_renderable_slideshow($slideshow_data) {
  $type = 'ul';
  $attributes = array('class' => 'slideshow-items');
  $items = _maxim_data_renderable_slide_data($slideshow_data['slideshow']);
    
  $output[] = array(
    '#theme' => 'item_list',
    '#items' => $items,
    '#type' => 'ul',
    '#attributes' => $attributes,
  );
  
  return($output);
}

function _maxim_data_renderable_slide_data ($slideshow) {
  foreach ($slideshow as $slide) {
    $image = theme_image(array('path' => $slide['slide']['uri']));
    
    $output = array (
      'image' => array(
        '#type' => 'markup',
        '#prefix' => '<div class="slideshow_item">',
        '#markup' => $image,
        '#suffix' => '</div>',
      )
    );
      
     $formatted_data[] = array(
       'data' => drupal_render($output),
       'class' => array ('slideshow-item-row')
     );
  }
  
  return($formatted_data);
}
