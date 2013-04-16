<?php
// $Id$
require_once ( dirname(__FILE__) . '/bb_hth_common.inc');

function _bb_hth_profile_resource_retreive ($nid, $tab) {
  if ($tab == 'state') {
    $profile = _get_profile_by_state($nid);
  }

  return($profile);
}

function _get_profile_by_state($nid) {
  $query = new EntityFieldQuery;
  
  // get node data
  $profile_data = node_load($nid);
  $profile_wrapper = entity_metadata_wrapper('node', $profile_data);
 
 //query for prev-next. get all nids that match the passed in nids state/year
  $query->entityCondition('entity_type', 'node')
        ->propertyCondition('status', 1)
        ->propertyCondition('type', 'hotties_profile')
        ->fieldCondition('field_profile_state', 'tid', $profile_wrapper->field_profile_state->value()->tid)
        ->fieldCondition('field_hotties_contest_year', 'tid', $profile_wrapper->field_hotties_contest_year->value()->tid);
  
  // get node data
  $pn_data = $query->execute();
  $allKeys = array_keys($pn_data['node']);
 
  // get prev-next nids for all nodes returned from query
  $all_pn_positions = _get_prev_next_positions($allKeys);
  
  $profile['profileItem'] = _get_profile($profile_data, $all_pn_positions[$profile_data->nid]);
  return ($profile);
}