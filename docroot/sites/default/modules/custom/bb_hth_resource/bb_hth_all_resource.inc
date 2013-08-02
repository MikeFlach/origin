<?php
// $Id$
require_once ( dirname(__FILE__) . '/bb_hth_common.inc');

function _bb_hth_all_resource_retreive ($year, $page, $ipp, $status) {
  // This is the range that we wil display
  $range_display = _get_range($page, $ipp); 
  
  if ($cache = cache_get('bb_hth_resource_all_tab')) {
    $sendArray['node'] = $cache->data;
  }
  else {
    $week_list = array('Finalists','Semifinalist','5','4','3','2','1');
    $query_array = array();

    foreach ($week_list as $week) {
      $hth_array = _get_week_nodes($week, $year, $status);

      foreach ($hth_array['node'] as $hth) {
        $hth_nids[] = $hth->nid;
      }

      $hth_nids_no_dupes = _remove_hth_dupes($query_array, $hth_nids, $week);

      if (count($hth_nids_no_dupes)) {
        // clone array
        $query_array = array_merge(array(), $hth_nids_no_dupes);
      }

      unset($hth_nids_no_dupes);
    }

    //$reordered_nodes = _reorder_node_data_by_publication_date($node_data);

    for ($i=0; $i<count($query_array); $i++) {
      $nid_indexed_array[$query_array[$i]] = $query_array[$i];
    } 
    
    $sendArray['node'] = $nid_indexed_array;
    cache_set('bb_hth_resource_all_tab', $nid_indexed_array, 'cache', time() + 60*2); //2 min cache
  }
  
  $return_data = _get_profile_data_from_nodes ($sendArray, $range_display);
  
  return($return_data);
}

function _get_week_nodes ($week, $year, $status) {
  $query = new EntityFieldQuery;
  
  $query->entityCondition('entity_type', 'node')
        ->propertyCondition('status', 1)
        ->propertyCondition('type', 'hotties_profile');
        
  $tid_year = taxonomy_get_term_by_name($year, 'hotties_contest_year');
  $query->fieldCondition('field_hotties_contest_year', 'tid', reset($tid_year)->tid);
  
  $tid_week = taxonomy_get_term_by_name($week, 'hotties_contest_week');
  $query->fieldCondition('field_hotties_contest_week', 'tid', reset($tid_week)->tid);
  
  //remove invalid entries
  $query = _remove_inalvalid_entries($query);

  if ($status) {
    $tid_status = taxonomy_get_term_by_name($status, 'hotties_contest_status');
    $query->fieldCondition('field_hotties_contest_status', 'tid', reset($tid_status)->tid);  
  }

  $node_data = $query->execute();
  
  return($node_data);
}

function _remove_hth_dupes ($hth_data, $new_nids, $week) {
  if ($week == 'Finalists') {
    $return_array = $new_nids;
  }
  else {
    // clone hth array
    $return_array = array_merge(array(), $hth_data); 

    for ($i=0; $i<count($new_nids); $i++) {
      $remove_nid = false;
      for ($j=0; $j<count($hth_data); $j++) {
        if ($new_nids[$i] == $hth_data[$j]) {
          $remove_nid = true;
        }
      }
      if (!$remove_nid) {
        $return_array[] = $new_nids[$i];
      }
    }
  }
  
  return ($return_array);
}