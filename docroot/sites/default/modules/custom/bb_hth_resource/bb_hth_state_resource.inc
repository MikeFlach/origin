<?php
// $Id$
require_once ( dirname(__FILE__) . '/bb_hth_common.inc');

function _bb_hth_state_resource_retreive ($state, $year, $count) {
  $query = new EntityFieldQuery;
  
  $query->entityCondition('entity_type', 'node')
        ->propertyCondition('status', 1)
        ->propertyCondition('type', 'hotties_profile')
        ->range(0, $count);
  
  // we use reset to retreive first element because the array returned by taxonomy_get_term_by_name is indexed by the tid, which we fon't have.
  if (!is_null($state)) {
    $tid_state = taxonomy_get_term_by_name($state, 'states_provinces');
    $query->fieldCondition('field_profile_state', 'tid', reset($tid_state)->tid);
  }
  
  if (!is_null($year)) {
    $tid_year = taxonomy_get_term_by_name($year, 'hotties_contest_year');
    $query->fieldCondition('field_hotties_contest_year', 'tid', reset($tid_year)->tid);
  }
  
  // get node data
  $node_ids = array();
  $node_data = $query->execute();
 
  foreach($node_data['node'] as $node) {
    $node_ids[] = $node->nid;
  }
  
  $return_data = array();
  $nodes = node_load_multiple($node_ids);
  $i = 0;
  foreach ($nodes as $node) { 
    $node_wrapper = entity_metadata_wrapper('node', $node);
    $nid = $node_wrapper->nid->value();
    $return_data['items'][$i]['state'] = $state;
    $return_data['items'][$i++]['profileItem'] = _get_profile_html($node);
  }

  return($return_data);
}

