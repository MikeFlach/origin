<?php
// $Id$

function _maxim_data_magazine_retreive ($cache_break) {
  try {
    $magazine_settings = _maxim_data_settings('magazine');
    
    if ($cache_break) {
      cache_clear_all($magazine_data['magazine_cache_name'], 'cache', TRUE); 
    }
    
    if (!$magazine_settings['magazine_caching']) {
      $magazine_data['data'] = _maxim_data_get_magazine_data($magazine_settings); 
      _maxim_data_append_cache_info(&$magazine_data, DATA_NOT_CACHED, DATA_NOT_FROM_CACHE);
    }
    else {
      $magazine_data = &drupal_static(__FUNCTION__); 

      if (!isset($magazine_data)) {
        if ($cache = cache_get($magazine_settings['magazine_cache_name'])) {
          $magazine_data['data'] = $cache->data;
           _maxim_data_append_cache_info(&$magazine_data, DATA_CACHED, DATA_FROM_CACHE);
        }
        else {
          $magazine_data['data'] = _maxim_data_get_magazine_data($magazine_settings); 
          cache_set($magazine_settings['magazine_cache_name'], $magazine_data['data'], 'cache', time() + 60*($magazine_settings['magazine_cache_time_minutes']));
          _maxim_data_append_cache_info(&$magazine_data, DATA_CACHED, DATA_NOT_FROM_CACHE);
        }
      }
    }
    
    _maxim_data_append_error_info($magazine_data);
    return($magazine_data);
  }
  catch (Exception $e) {
    $magazine_data['data'] = array();
    
    _maxim_data_append_error_info($magazine_data, $e);
    return ($magazine_data);
  }
}

function _maxim_data_get_magazine_data ($magazine_settings) {
  $magazine_nodes = nodequeue_view_nodes(106, $backward = TRUE, $teaser = TRUE, $links = TRUE, $from = 0, $count = 0);

  foreach($magazine_nodes as $magazine_node) {
    $magazine_thumb = reset(field_get_items('node', $magazine_node['#node'], 'field_main_image'));
    $magazine_title = $magazine_node['#node']->title;
    $magazine_channel = taxonomy_term_load(reset(reset(field_get_items('node', $magazine_node['#node'], 'field_channel'))))->name;
    $magazine_nid = (int)$magazine_node['#node']->nid;

    $node['thumb'] =  image_style_url($magazine_settings['magazine_image_style'], $magazine_thumb['uri']);
    $node['title'] =  $magazine_title;
    $node['channel'] =  $magazine_channel;
    $node['nid'] =  $magazine_nid;
    $node['path'] = "http://" . $_SERVER['SERVER_NAME'] . url("node/$magazine_nid");
    
    $magazine_data[] = $node;
  }
  
  return ($magazine_data);
}