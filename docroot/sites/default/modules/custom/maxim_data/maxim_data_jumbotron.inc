<?php
// $Id$
require_once ( dirname(__FILE__) . '/maxim_data_common.inc');

function _maxim_data_jumbotron_retreive ($cache_break) {
  try {
    $jt_settings = _maxim_data_settings('jumbotron');
    
    if ((!$jt_settings['jt_caching']) || ($cache_break)) {
      $jumbotron_data['data'] = _get_jumbotron_data(); 

      $jumbotron_data['cacheInfo']['isCached'] = false;
      $jumbotron_data['cacheInfo']['fromCache'] = false;
    }
    else {
      $jumbotron_data = &drupal_static(__FUNCTION__); 

      if (!isset($jumbotron_data)) {
        if ($cache = cache_get('maxim_data_jumbotron')) {
          $jumbotron_data['data'] = $cache->data;

          $jumbotron_data['cacheInfo']['fromCache'] = true;
          $jumbotron_data['cacheInfo']['isCached'] = true;
        }
        else {
          $jumbotron_data['data'] = _get_jumbotron_data(); 
          cache_set('maxim_data_jumbotron', $jumbotron_data, 'cache', time() + 60*($jt_settings['jt_cache_time_minutes']));

          $jumbotron_data['cacheInfo']['isCached'] = true;
          $jumbotron_data['cacheInfo']['fromCache'] = false;
        }
      }
    }
    
    _append_error_info($jumbotron_data);
    return($jumbotron_data);
  }
  catch (Exception $e) {
    $jumbotron_data['data'] = array();
    
    _append_error_info($jumbotron_data, $e);
    return ($jumbotron_data);
  }
}

function _get_jumbotron_data () {
  $jt_nodes = nodequeue_view_nodes(1, $backward = TRUE, $teaser = TRUE, $links = TRUE, $from = 0, $count = 0);

  foreach($jt_nodes as $jt_node) {
    $jt_image = reset(field_get_items('node', $jt_node['#node'], 'field_jumbo_image'));
    $jt_thumb = reset(field_get_items('node', $jt_node['#node'], 'field_main_image'));
    $jt_title = reset(field_get_items('node', $jt_node['#node'], 'field_feature_title'));
    $jt_subtitle = reset(field_get_items('node', $jt_node['#node'], 'field_feature_subtitle'));
    $jt_nid = (int)$jt_node['#node']->nid;

    $node['src'] =  image_style_url($jt_settings['jt_image_style'], $jt_image['uri']);
    $node['thumb'] =  image_style_url($jt_settings['jt_thumb_style'], $jt_thumb['uri']);
    $node['title'] =  $jt_title['safe_value'];
    $node['subtitle'] =  $jt_subtitle['safe_value'];
    $node['panelType'] =  'image';
    $node['nid'] =  $jt_nid;
    
    $jumbotron_data[] = $node;
  }
  
  return ($jumbotron_data);
}