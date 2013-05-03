<?php
// $Id$
require_once ( dirname(__FILE__) . '/bb_hth_common.inc');

function _bb_hth_all_resource_retreive ($year, $page, $ipp, $status) {
  $return_data = array();
  
  // we have to adjust the range that we request in order to get proper prev/next nids for the first and last profiles on paged output.
  $get_one_previous = ($page > 0) ? TRUE : FALSE;
  $range_retrieve = _get_range($page, $ipp, $get_one_previous); 

  // This is the range that we wil display
  $range_display = _get_range($page, $ipp); 
  
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node')
        ->propertyCondition('status', 1)
        ->propertyCondition('type', 'hotties_profile')
        ->range($range_retrieve[0], $ipp+2) // we need to retreive an extra node to detertine next nid for last profile on page 
        ->propertyOrderBy('changed', 'DESC');
        
  $tid_year = taxonomy_get_term_by_name($year, 'hotties_contest_year');
  $query->fieldCondition('field_hotties_contest_year', 'tid', reset($tid_year)->tid);
  
  //remove gamer girl profiles
  $tid_gamer_girl_week = taxonomy_get_term_by_name('Gamer Girl Finalist', 'hotties_contest_week');
  $query->fieldCondition('field_hotties_contest_week', 'tid', reset($tid_gamer_girl_week)->tid, '!=');
  
  if (!is_null($status)) {
    $tid_status = taxonomy_get_term_by_name($status, 'hotties_contest_status');
    $query->fieldCondition('field_hotties_contest_status', 'tid', reset($tid_status)->tid);
  }
  // get node data
  $node_data = $query->execute();
  
// get nid of first element on page to use as previous nid to the first element on the page and then discard
  if ($get_one_previous) {
    $prev_id = reset($node_data['node'])->nid;
    unset($node_data['node'][$prev_id]);
  }
  
  $return_data = _get_profile_data_from_nodes ($node_data, $range_display, 'already_paged', $prev_id);
  
  return($return_data);
}
