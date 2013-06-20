<?php
// $Id$
require_once ( dirname(__FILE__) . '/bb_hth_common.inc');

/* gets profile information for one or more states */
function _bb_hth_standing_resource_retreive ($year, $standing, $page, $ipp) {
  $current_year = variable_get('hth_contest_year');
  $range = _get_range($page, $ipp);
  
  // different results for current/previous year landing pages
  $standing_list = isset($standing) ? array($standing) : array('winner', 'finalist', 'semifinalist', 'contestant');
  if ($year == 'current') {
    $use_year = $current_year;
    $is_current_year = TRUE;
  }
  else {
    $use_year = $year;
    $is_current_year = ($year == $current_year) ? TRUE : FALSE;
  }  
  
  foreach ($standing_list as $standing) {
    $return_data["$year"]['items']["$standing"]['statuscode'] = 0;
    $return_data["$year"]['items']["$standing"]['statusmsg'] ='SUCCESS';
    $return_data["$year"]['items']["$standing"] = _get_profiles_for_standing ($use_year, $standing, $range, $is_current_year);
  }    

  return($return_data);
}

function _get_profiles_for_standing ($year, $standing, $range, $is_current_year) {
  $query = new EntityFieldQuery;
  
  $query->entityCondition('entity_type', 'node')
        ->propertyCondition('status', 1)
        ->propertyCondition('type', 'hotties_profile');
  

  $tid_status = taxonomy_get_term_by_name($standing, 'hotties_contest_status');
  $query->fieldCondition('field_hotties_contest_status', 'tid', reset($tid_status)->tid);
  
  $tid_year = taxonomy_get_term_by_name($year, 'hotties_contest_year');
  $query->fieldCondition('field_hotties_contest_year', 'tid', reset($tid_year)->tid);
  
  //remove invalid entries
  $query = _remove_inalvalid_entries($query);
  
  // get node data
  $node_data = $query->execute();
  $reordered_nodes = _reorder_node_data_by_publication_date($node_data);
  $return_data = _get_profile_data_from_nodes ($reordered_nodes, $range);
  
  
  return($return_data);
}

/**
 * Implementation of hook_query_TAG_alter
 */
function bb_hth_resource_query_random_alter($query) {
  $query->orderRandom();
}
