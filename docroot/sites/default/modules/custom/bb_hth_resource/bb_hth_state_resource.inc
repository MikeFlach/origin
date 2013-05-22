<?php
// $Id$
require_once ( dirname(__FILE__) . '/bb_hth_common.inc');

/* gets profile information for one or more states */
function _bb_hth_state_resource_retreive ($year, $state_abbr, $statePage, $stateIpp, $page, $ipp, $status) {
  $return_data = array();
  
  // override default values for state ranges if we are looking at 1 state
  if (isset($state_abbr)) {
    $statePage = 1; $stateIpp = 1;
  }
  
  //profile & state ranges
  $range = _get_range($page, $ipp);
  $state_range = _get_range($statePage, $stateIpp);
  
  $state_list = (!isset($state_abbr)) ? _get_paged_state_list($state_range) : (array)_get_long_state ($state_abbr);
  foreach ($state_list as $state) {
    $return_data["$year"]['items']['statuscode'] = 0;
    $return_data["$year"]['items']['statusmsg'] = 'SUCCESS';
    $return_data["$year"]['items']["$state"] = _get_profiles_for_state ($range, $state, $year, $status);
  }
  
  return($return_data);
}

function _get_profiles_for_state ($range, $state, $year, $status) {
  $return_data = array();
  
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node')
        ->propertyCondition('status', 1)
        ->propertyCondition('type', 'hotties_profile');
  
  // we use reset to retreive first element because the array returned by taxonomy_get_term_by_name is indexed by the tid, which we fon't have.
  $tid_state = taxonomy_get_term_by_name($state, 'states_provinces');
  $query->fieldCondition('field_profile_state', 'tid', reset($tid_state)->tid);

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
  $return_data = _get_profile_data_from_nodes ($reordered_nodes, $range);
  
  return($return_data);
}
