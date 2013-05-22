<?php
// $Id$
require_once ( dirname(__FILE__) . '/bb_hth_common.inc');

function _bb_hth_profile_resource_retreive ($nid, $tab, $standing) {
  $profile_data = node_load($nid);
  if ($tab == 'state') {
    $query = _get_profile_by_state_tab($nid, $profile_data);
  }
  elseif ($tab == 'standing') {
    $query = _get_profile_by_standing_tab($nid, $profile_data, $standing);
  }
  elseif ($tab == 'all') {
    $query = _get_profile_by_all_tab($nid, $profile_data);
  }
  
  //remove invalid entries
  $query = _remove_inalvalid_entries($query);
  
  // get node data
  $pn_data = $query->execute();
  $reordered_pn_data = _reorder_node_data_by_publication_date($pn_data);
  $allKeys = array_keys($reordered_pn_data['node']);
 
  // get prev-next nids for all nodes returned from query
  $all_pn_positions = _get_prev_next_positions($allKeys);
  
  $profile['profileItem'] = _get_profile($profile_data, $all_pn_positions[$profile_data->nid]);
  return ($profile);
}

function _get_profile_by_state_tab($nid, $profile_data) {
  $query = new EntityFieldQuery;
  
  // get node data
  $profile_wrapper = entity_metadata_wrapper('node', $profile_data);
  //query for prev-next. get all nids that match the passed in nids state/year
   $query->entityCondition('entity_type', 'node')
         ->propertyCondition('status', 1)
         ->propertyCondition('type', 'hotties_profile')
         ->fieldCondition('field_profile_state', 'tid', $profile_wrapper->field_profile_state->value()->tid)
         ->fieldCondition('field_hotties_contest_year', 'tid', $profile_wrapper->field_hotties_contest_year->value()->tid);
   
   return($query);
}

function _get_profile_by_standing_tab($nid, $profile_data, $standing) {
  $query = new EntityFieldQuery;
  
  // get node data
  $profile_data = node_load($nid);
  $profile_wrapper = entity_metadata_wrapper('node', $profile_data);
  
  if (is_null($standing)) {
    $entity_status = $profile_wrapper->field_hotties_contest_status->value();
    $status =  _get_latest_status_tid($entity_status);
  }
  else  {
     $status = reset(taxonomy_get_term_by_name($standing, 'hotties_contest_status'))->tid;
  }
  
 //query for prev-next. get all nids that match the passed in nids state/year
  $query->entityCondition('entity_type', 'node')
        ->propertyCondition('status', 1)
        ->propertyCondition('type', 'hotties_profile')
        ->fieldCondition('field_hotties_contest_year', 'tid', $profile_wrapper->field_hotties_contest_year->value()->tid)
        ->fieldCondition('field_hotties_contest_status', 'tid', $status);
  
  return ($query);
}

function _get_profile_by_all_tab($nid, $profile_data) {
  $query = new EntityFieldQuery;
  
  // get node data
  $profile_wrapper = entity_metadata_wrapper('node', $profile_data);
  //query for prev-next. get all nids that match the passed in nids state/year
   $query->entityCondition('entity_type', 'node')
         ->propertyCondition('status', 1)
         ->propertyCondition('type', 'hotties_profile')
         ->fieldCondition('field_hotties_contest_year', 'tid', $profile_wrapper->field_hotties_contest_year->value()->tid);
   
   return($query);
}