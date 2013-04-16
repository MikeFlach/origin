<?php
// $Id$
require_once ( dirname(__FILE__) . '/bb_hth_common.inc');

function _bb_hth_state_resource_retreive ($year, $state_abbr, $page, $ipp, $status = NULL) {
  $return_data = array();
  $query = new EntityFieldQuery;
  $state = _get_long_state ($state_abbr);
  $range = _get_range($page, $ipp);
  
  $query->entityCondition('entity_type', 'node')
        ->propertyCondition('status', 1)
        ->propertyCondition('type', 'hotties_profile');
  
  // we use reset to retreive first element because the array returned by taxonomy_get_term_by_name is indexed by the tid, which we fon't have.
  if (!is_null($state)) {
    $tid_state = taxonomy_get_term_by_name($state, 'states_provinces');
    $query->fieldCondition('field_profile_state', 'tid', reset($tid_state)->tid);
  }
  
  if (!is_null($year)) {
    $tid_year = taxonomy_get_term_by_name($year, 'hotties_contest_year');
    $query->fieldCondition('field_hotties_contest_year', 'tid', reset($tid_year)->tid);
  }
  
  if (!is_null($status)) {
    $tid_status = taxonomy_get_term_by_name($status, 'hotties_contest_status');
    $query->fieldCondition('field_hotties_contest_status', 'tid', reset($tid_status)->tid);
  }
  
  // get node data
  $node_data = $query->execute();
  $allKeys = array_keys($node_data['node']);
 
  // get prev-next nids for all nodes returned from query
  $all_pn_positions = _get_prev_next_positions($allKeys);
  
  // get list of node_ids to load based on range
  $node_ids = array();
  for ($j = $range[0], $i = 0; $j <= $range[1]; $j++, $i++) {
    $node_ids[$i] = $allKeys[$j];
  }
  
  $nodes = node_load_multiple($node_ids);
  foreach ($nodes as $node) {
    $new_item = array();
    
    $new_item['state'] = $state;
    $new_item['profileItem'] =  _get_profile($node, $all_pn_positions[$node->nid]);
    
    $return_data['items'][] = $new_item;
  }

  return($return_data);
}

