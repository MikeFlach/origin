<?php
// $Id$

function _maxim_data_prev_next_retrieve ($nid, $wrap, $cache_break, $debug) {
  try {
    $settings = _maxim_data_settings('prev_next');
    
    if ($cache_break) {
      cache_clear_all($settings['cache_name'], 'cache', TRUE);
    }
    
    if (!$settings['do_caching']) {
      $data = _maxim_data_get_prev_next ($nid, $wrap);
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
        $data = _maxim_data_get_prev_next($nid, $wrap); 
        
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

function _maxim_data_get_prev_next ($nid, $wrap) {
  $node = node_load($nid);
  $type = strtolower(node_type_get_name($node));
  
  //these are special slideshows with their own NQs
  $tags = isset($node->field_tags) ? $node->field_tags : array();
  $special_slideshows = _maxim_data_determine_special_slideshows($tags);
  if (count($special_slideshows)) {
    $type = 'special';
  }

  switch ($type) {
    case 'special' :
      $data = _maxim_data_pn_special ($node, $special_slideshows, $wrap);
    break;
  
    case 'hometown hotties profile' :
      $data = _maxim_data_pn_profile ($node, $wrap);
    break;
  
    case 'slideshow' :
      $data = _maxim_data_pn_slideshow ($node, $wrap);
    break;
  
  }
  
  return ($data);
}

function _maxim_data_pn_special ($node, $special_slideshows, $wrap) {
  // prev-next based on specicific NQs. Check for these first, because some of these can also be hth profiles
  if (count($special_slideshows)) {
    $nq_name = _maxim_data_get_special_nq_name($special_slideshows);
    $nq_pos = '';
    
    $pn_links['previous'] = _maxim_data_get_pn_nid_nq ('previous', $nq_name, $nq_pos, $wrap);
    $pn_links['next'] = _maxim_data_get_pn_nid_nq ('next', $nq_name, $nq_pos, $wrap);
  }
  
  return ($pn_links);
}

function _maxim_data_pn_slideshow ($node, $wrap) {
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $channel_tid = isset($node_wrapper->field_channel) ? $node_wrapper->field_channel->value()->tid : null;
  
  $pn_links['previous'] = _maxim_data_get_pn_data(_maxim_data_get_pn_nid((int)$node->nid, (int)$channel_tid, 'previous', $wrap));
  $pn_links['next'] = _maxim_data_get_pn_data(_maxim_data_get_pn_nid((int)$node->nid, (int)$channel_tid, 'next', $wrap));
  
  return($pn_links);
}

function _maxim_data_pn_profile ($node, $wrap) {
  $node_wrapper = entity_metadata_wrapper('node', $node);

  $hth_year = isset($node_wrapper->field_hotties_contest_year) ? taxonomy_term_load($node_wrapper->field_hotties_contest_year->value()->tid)->name : null;

  // only profiles > 2013 have prev-next based on NQ position
  if ($hth_year >= 2013) {
    // the prev-next links for a hth hottie will be based on her highest round
    $hth_rounds = isset($node_wrapper->field_hotties_contest_week) ? $node_wrapper->field_hotties_contest_week->value() : null;
    $hth_contest_status = isset($node_wrapper->field_hotties_contest_status) ? $node_wrapper->field_hotties_contest_status->value() : null;
    $latest_hth_round = (isset($hth_rounds) && isset($hth_contest_status)) ? _maxim_data_get_latest_hth_round($hth_rounds, $hth_contest_status) : null;
    
    $nq_name = _maxim_data_get_nq_name($hth_year, $latest_hth_round);
    $nq_pos = '';
    $pn_links['previous'] = _maxim_data_get_pn_nid ('previous', $nq_name, $nq_pos, $wrap);
    $pn_links['next'] = _maxim_data_get_pn_nid ('next', $nq_name, $nq_pos, $wrap);
  }
  else {
    $channel_tid = isset($node_wrapper->field_channel) ? $node_wrapper->field_channel->value()->tid : null;
    $pn_links['previous'] = _maxim_data_get_pn_data(_maxim_data_get_pn_nid ($node->nid, $channel_tid, 'previous', $wrap));
    $pn_links['next'] = _maxim_data_get_pn_data(_maxim_data_get_pn_nid ($node->nid, $channel_tid, 'next', $wrap));
  }

   return ($pn_links);
}

function _maxim_data_determine_special_slideshows ($tags) {
  $special_slideshows = array();
  
  if (_maxim_data_search_tags ($tags, '_covers')) { $special_slideshows['cover_gallery'] = true; }
  if (_maxim_data_search_tags ($tags, '_devils_cut_2012')) { $special_slideshows['devils_cut'] = true; }
  if (_maxim_data_search_tags ($tags, '_gamergirl_2012_contest')) { $special_slideshows['gamer_girl'] = true; }
  
  return ($special_slideshows);
}

function _maxim_data_get_special_nq_name ($special_slideshows) {
  // not sure what to do if slideshow belongs to 2 'special' groups. will probanly never happen. default to first.
  foreach ($special_slideshows as $ss_type=>$is_type) {
    if ($is_type) {
      if ($ss_type == 'covers_gallery') { return ('maxim_cover_gallery'); }
      if ($ss_type == 'gamer_girl') { return ('gamer_girl_finalists'); }
      if ($ss_type == 'devils_cut') { return ('devil_s_cut_2012'); }
    } 
  }
} 

function _maxim_data_search_tags ($tags, $target) {
  foreach ($tags as $tag) {
    if ($tag == $target) {
      return (true);
    }
  }
  
  return (false);
}

function _maxim_data_get_hth_nq_name ($hottie_year, $hottie_week) {
  $nq_name = '';
  
  if ($hottie_week == 'finals' || $hottie_week == 'semi-finals') {
     $nq_name = 'hth_' . $hottie_year . '_'  .str_replace('-', '_', $hottie_week);
   }
   else {
     $nq_name = 'hth_' . $hottie_year . '_contestants_week_' . $hottie_week;
   }
  
   return ($nq_name);
}

function _maxim_data_get_nq_position($nid, $nq_name) {
  $position = null;
  if (strlen($nq_name)) {
    $sql = 'SELECT n.position ';
    $sql .= 'FROM {nodequeue_nodes} n, {nodequeue_queue} q, {nodequeue_subqueue} sq ';
    $sql .= 'WHERE q.qid = sq.qid AND sq.sqid = n.sqid AND n.qid = q.qid AND n.nid = :nid AND q.name = :nq';
    $params = array(':nid' => $nid, ':nq' => $nq_name);

    $result = db_query($sql, $params)->fetchObject();
    if (isset($result->position)) {
      $position = $result->position;
    }
  }
  return ($position);
}

function _maxim_data_get_pn_nid ($nid, $channel_tid, $op, $wrap) {
  if ($op == 'previous') {
    $sql_ops['type'] = 'previous';
    $sql_ops['operator'] = '<';
    $sql_ops['order'] = 'DESC';
  }
  elseif ($op == 'next') {
    $sql_ops['type'] = 'next';
    $sql_ops['operator'] = '>';
    $sql_ops['order'] = 'ASC';
  }
  
  $result = _maxim_data_get_pn_nid_execute_sql($nid, $channel_tid, $sql_ops);
  // if we have reached beginning/end (no prev/next) and we want to 'wrap' around
  if($wrap && !$result) {
    $result = _maxim_data_get_pn_nid_execute_sql_rand_wrap($channel_tid, $sql_ops);
  }
  $pn_nid = (isset($result)) ? $result->nid : null; 
  
  return($pn_nid);
}
  
function _maxim_data_get_pn_nid_execute_sql ($nid, $channel_tid, $sql_ops) {
  $params = array(':nid' => $nid, ':tid' => $channel_tid);
  
  $sql_select = 'SELECT n.nid, n.title ';
  $sql_from = 'FROM {node} n, {taxonomy_index} t ';
  $sql_where = 'WHERE n.nid = t.nid AND n.created ' . $sql_ops['operator'] . ' (SELECT created FROM {node} WHERE nid = :nid) AND t.tid= :tid AND type IN (\'slideshow\') AND status = 1 ';
  $sql_order = 'ORDER BY n.created ' . $sql_ops['order'] . ' LIMIT 1';
  $sql = $sql_select . $sql_from . $sql_where . $sql_order;
  
  $result = db_query($sql, $params)->fetchObject();
  
  return ($result);
}

/* called when wrap parameter is 1 and the first/last node has been reached so no prev/next exists.
 * if this happens, we go to an arbitrary date within the past 2 years and pick that 
 * as the new nid to return. not ideal, but avoids showing the oldest slideshow as 'next' 
 * for the newest slideshow.
 */
function _maxim_data_get_pn_nid_execute_sql_rand_wrap ($channel_tid, $sql_ops) {
  $now = time();
  $ago = $now - (2 * 365 * 24 * 60 * 60); // 2 years; 365 days; 24 hours; 60 mins; 60secs
  $rand_date = mt_rand($ago, $now);

  
  $params = array(':rand_date' => $rand_date, ':tid' => $channel_tid);
  $sql_select = 'SELECT n.nid, n.title ';
  $sql_from = 'FROM {node} n, {taxonomy_index} t ';
  $sql_where = 'WHERE n.nid = t.nid AND n.created ' . $sql_ops['operator'] . ' :rand_date AND t.tid= :tid AND type IN (\'slideshow\') AND status = 1 ';
  $sql_order = 'ORDER BY n.created ' . $sql_ops['order'] . ' LIMIT 1'; 
  $sql = $sql_select . $sql_from . $sql_where . $sql_order;
  
  $result = db_query($sql, $params)->fetchObject();
  
  return ($result);
}

function _maxim_data_get_pn_data ($nid) {
  $return_value['main_image_thumb'] = null;
  $return_value['link'] = null;
  $return_value['nid'] = null;
  $return_value['title'] = null; 
  
  if (isset($nid)) {
    $node = node_load($nid);
    $node_wrapper = entity_metadata_wrapper('node', $node);

    $image_data = $node_wrapper->field_main_image->value();
    $return_value['main_image_thumb'] = isset($image_data) ? file_create_url($image_data['uri']) : null;
    
    $return_value['link'] = url("node/$nid");
    $return_value['nid'] = $nid;
    $return_value['title'] = $node->title;
  }

  return($return_value);
}