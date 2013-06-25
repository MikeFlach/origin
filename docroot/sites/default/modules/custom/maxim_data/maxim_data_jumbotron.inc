<?php
// $Id$

function _maxim_data_jumbotron_retreive ($cache_break) {
  try {
    $jt_settings = _maxim_data_settings('jumbotron');
    
    if ($cache_break) {
      cache_clear_all($jumbotron_data['jt_cache_name'], 'cache', TRUE); 
    }
    
    if (!$jt_settings['jt_caching']) {
      $jumbotron_data['data'] = _maxim_data_get_jumbotron_data($jt_settings); 
      _maxim_data_append_cache_info(&$jumbotron_data, MAXIM_DATA_JUMBOTRON_NOT_CACHED, MAXIM_DATA_JUMBOTRON_NOT_FROM_CACHE);
    }
    else {
      $jumbotron_data = &drupal_static(__FUNCTION__); 

      if (!isset($jumbotron_data)) {
        if ($cache = cache_get($jt_settings['jt_cache_name'])) {
          $jumbotron_data['data'] = $cache->data;
           _maxim_data_append_cache_info(&$jumbotron_data, MAXIM_DATA_JUMBOTRON_CACHED, MAXIM_DATA_JUMBOTRON_FROM_CACHE);
        }
        else {
          $jumbotron_data['data'] = _maxim_data_get_jumbotron_data($jt_settings); 
          cache_set($jt_settings['jt_cache_name'], $jumbotron_data['data'], 'cache', time() + 60*($jt_settings['jt_cache_time_minutes']));
          _maxim_data_append_cache_info(&$jumbotron_data, MAXIM_DATA_JUMBOTRON_CACHED, MAXIM_DATA_JUMBOTRON_NOT_FROM_CACHE);
        }
      }
    }
    
    _maxim_data_append_error_info($jumbotron_data);
    return($jumbotron_data);
  }
  catch (Exception $e) {
    $jumbotron_data['data'] = array();
    
    _maxim_data_append_error_info($jumbotron_data, $e);
    return ($jumbotron_data);
  }
}

function _maxim_data_get_jumbotron_data ($jt_settings) {
  $jt_nodes = nodequeue_view_nodes(1, $backward = TRUE, $teaser = TRUE, $links = TRUE, $from = 0, $count = 0);

  foreach($jt_nodes as $jt_node) {
    $jt_image = reset(field_get_items('node', $jt_node['#node'], 'field_jumbo_image'));
    $jt_thumb = reset(field_get_items('node', $jt_node['#node'], 'field_main_image'));
    $jt_title = $jt_node['#node']->title;
    $jt_subtitle = reset(field_get_items('node', $jt_node['#node'], 'field_feature_subtitle'));
    $jt_nid = (int)$jt_node['#node']->nid;

    $node['src'] =  image_style_url($jt_settings['jt_image_style'], $jt_image['uri']);
    $node['thumb'] =  image_style_url($jt_settings['jt_thumb_style'], $jt_thumb['uri']);
    $node['title'] =  $jt_title;
    $node['subtitle'] =  $jt_subtitle['safe_value'];
    $node['panelType'] =  'image';
    $node['nid'] =  $jt_nid;
    $node['path'] = "http://" . $_SERVER['SERVER_NAME'] . url("node/$jt_nid");
    
    $jumbotron_data[] = $node;
  }
  
  return ($jumbotron_data);
}