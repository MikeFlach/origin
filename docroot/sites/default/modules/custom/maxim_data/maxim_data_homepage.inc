<?php
// $Id$

function _maxim_data_homepage_retreive ($page, $ipp, $cache_break) {
  try {
    $hp_settings = _maxim_data_settings('homepage');
    $range = _maxim_data_get_range($page, $ipp);
    
    if ($cache_break) {
      cache_clear_all($hp_settings['hp_cache_name'], 'cache', TRUE);
    }
    
    if (!$hp_settings['hp_caching']) {
      $hp_data['data'] = _maxim_data_get_homepage_data($hp_settings, $range); 
      _maxim_data_append_cache_info($hp_data, DATA_NOT_CACHED, DATA_NOT_FROM_CACHE);
    }
    else {
      $hp_data = &drupal_static(__FUNCTION__); 
      
      if (!isset($hp_data)) {
        if ($cache = cache_get($hp_settings['hp_cache_name'])->data[$page][$ipp]) {
          if (isset($cache)) {
            $hp_data['data'] = $cache;
           _maxim_data_append_cache_info($hp_data, DATA_CACHED, DATA_FROM_CACHE);
          }
        }
        else {
          $hp_data['data'] = _maxim_data_get_homepage_data($hp_settings, $range); 
          $paged_data_cache = cache_get($hp_settings['hp_cache_name'])->data;
          $paged_data_cache[$page][$ipp] = $hp_data['data'];
          
          cache_set($hp_settings['hp_cache_name'], $paged_data_cache, 'cache', time() + 60*($hp_settings['hp_cache_time_minutes']));
          _maxim_data_append_cache_info($hp_data, DATA_CACHED, DATA_NOT_FROM_CACHE);
        }
      }
    }
    
    _maxim_data_append_error_info($hp_data);
    return($hp_data);
  }
  
  catch (Exception $e) {
    $hp_data['data'] = array();
    
    _maxim_data_append_error_info($hp_data, $e);
    return ($hp_data);
  }
}

function _maxim_data_get_homepage_data ($hp_settings, $range) {
  $query = new EntityFieldQuery;

  $jt_nids = _maxim_data_get_jt_nids($hp_settings['jt-url']);
  
  $query->entityCondition('entity_type', 'node')
        ->propertyCondition('status', 1)
        ->propertyCondition('type', array('link-stub', 'poll', 'blog'), 'NOT IN')
        ->propertyCondition('promote', 1)
        ->propertyCondition('nid', $jt_nids, 'NOT IN')
        ->range($range[0], $range[1])
        ->propertyOrderBy('sticky', 'DESC')
        ->propertyOrderBy('created', 'DESC');
  
  $hp_data = $query->execute();
  
  $hp_return_items = array();
  if (isset($hp_data['node'])) {
    $hp_nids = array_keys($hp_data['node']);
    $hp_items = node_load_multiple($hp_nids);
    
    foreach ($hp_items as $item) {
      $main_image = reset(field_get_items('node', $item, 'field_main_image'));
      
      $item_data['nid'] = $item->nid;
      $item_data['title'] = $item->title;
      $item_data['type'] = $item->type;
      $item_data['path'] = "http://" . $_SERVER['SERVER_NAME'] . url("node/$item->nid");
      $item_data['mainImage'] = image_style_url($hp_settings['hp_image_style'], $main_image['uri']);
      //$item_data['thumnailImage'] = image_style_url($hp_settings['hp_thumbnail_style'], $main_image['uri']);
      
      $hp_return_items[] = $item_data;
    }
  }
  
  return($hp_return_items);
}

function _maxim_data_get_jt_nids($url) {
  $jt_nids = array();
  
  $jt_request = drupal_http_request($url);
  $jt_items = json_decode($jt_request->data)->data;
  
  if (count($jt_items)) {
    foreach ($jt_items as $jt_item) {
      $jt_nids[] = $jt_item->nid;
    }
  }
  
  return($jt_nids);
}
