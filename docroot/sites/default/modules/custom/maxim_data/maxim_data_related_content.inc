<?php
// $Id$

function _maxim_data_related_content_retrieve ($nid, $count, $cache_break, $debug) {
  try {
    $settings = _maxim_data_settings('related_content');
    
    if ($cache_break) {
      cache_clear_all($settings['cache_name'], 'cache', TRUE);
    }
    
    if (!$settings['do_caching']) {
      $data = _maxim_data_get_related_content ($nid, $count);
      _maxim_data_append_cache_info($data, DATA_NOT_CACHED, DATA_NOT_FROM_CACHE, $debug);
    }
    else {
      // do we have any cached data?
      $cache_data = cache_get($settings['cache_name']); 
      if ($cache_data) {
        $cached_full = $cache_data->data;
        //if we have cahched data, do we have cached data for this particular nid?
        if (isset($cache_data->data[$nid])) {
          // retreive cached prev_next data 
          $data = $cache_data->data[$nid];
          _maxim_data_append_cache_info($data, DATA_CACHED, DATA_FROM_CACHE, $debug); 
        }
      }
      
      // if no profile data in cache
      if (!isset($data)) {
        // get prev_next data
         $data = _maxim_data_get_related_content ($nid, $count);
        
        // place newly retrieved prev_next into cache
        $nid_data_cache = isset($cached_full) ? $cached_full->data : array();
        $nid_data_cache[$nid] = $data;
        cache_set($settings['cache_name'], $nid_data_cache, 'cache', time() + 60*($settings['cache_time_minutes']));
      }
    }
    
    _maxim_data_append_error_info($data, NULL, $debug);
    return($data);
  }
  catch (Exception $e) {
    $data = array();
    
    _maxim_data_append_error_info($data, $e, $debug);
    return ($data);
  }
}

function _maxim_data_get_related_content ($nid, $count) {
  $settings = _maxim_data_settings('related_content');
  $node = node_load($nid);
  $type = strtolower(node_type_get_name($node));
  
  switch ($type) {
    case 'article' || 'review' || 'blog' || 'slideshow':
      $channel_tid = _maxim_data_get_parent_tid(_maxim_data_get_channel_tid($node));
      
      //pain in the ass. depth parameter was removed. we have to loop through all child tids to build list
      $child_tids = taxonomy_get_children($channel_tid);
        
      $latest_articles = array();
      foreach($child_tids as $child) {
        $child_articles = taxonomy_select_nodes($child->tid, FALSE, $settings['article_pool_count'], array('t.created' => 'DESC'));
        $latest_articles = array_merge($latest_articles, $child_articles);
      }
      
      $nid_array = _maxim_data_get_related_nids($latest_articles, $count, $nid);
      $related_data =  _maxim_data_get_related_data_from_nids($nid_array);
    break;
  
  }
  
  return ($related_data);
}

function _maxim_data_get_related_nids($articles, $count, $nid) {
  for($i=0; $i < count($articles); $i++) {
    if ($articles[$i] != $nid) {
      $article_nids[$articles[$i]] = $articles[$i];
    }
  }
  
  $related_nids = array_rand($article_nids, $count);
  for($i=0; $i < count($related_nids); $i++) {
    $return_data[$related_nids[$i]] = $related_nids[$i];
  }
  
  return($return_data);
}

function _maxim_data_get_related_data_from_nids ($nids) {
  $settings = _maxim_data_settings('related_content');
  $articles = node_load_multiple($nids);
  
  foreach ($articles as $article) {
    $main_image = reset(field_get_items('node', $article, 'field_main_image'));    
    $item_data['main_image'] = image_style_url($settings['image_style'], $main_image['uri']);
    $item_data['main_image_uri'] =  $main_image['uri'];
    $item_data['nid'] = $article->nid;
    $item_data['title'] = $article->title;
    $item_data['link'] = url("node/$article->nid");

    $return_data[] = $item_data;
  }
  
  return ($return_data);
}