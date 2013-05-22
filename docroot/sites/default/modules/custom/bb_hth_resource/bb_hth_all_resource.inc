<?php
// $Id$
require_once ( dirname(__FILE__) . '/bb_hth_common.inc');

function _bb_hth_all_resource_retreive ($year, $page, $ipp, $status) {
  // This is the range that we wil display
  $range_display = _get_range($page, $ipp); 
  
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node')
        ->propertyCondition('status', 1)
        ->propertyCondition('type', 'hotties_profile');
        
  $tid_year = taxonomy_get_term_by_name($year, 'hotties_contest_year');
  $query->fieldCondition('field_hotties_contest_year', 'tid', reset($tid_year)->tid);
  
  //remove invalid entries
  $query = _remove_inalvalid_entries($query);
  
  if (!is_null($status)) {
    $tid_status = taxonomy_get_term_by_name($status, 'hotties_contest_status');
    $query->fieldCondition('field_hotties_contest_status', 'tid', reset($tid_status)->tid);
  }
  // get node data
  $node_data = $query->execute();
  $reordered_nodes = _reorder_node_data_by_publication_date($node_data);
  
  $return_data = _get_profile_data_from_nodes ($reordered_nodes, $range_display);
  return($return_data);
}
