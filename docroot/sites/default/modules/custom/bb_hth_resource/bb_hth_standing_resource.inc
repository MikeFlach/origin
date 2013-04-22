<?php
// $Id$
require_once ( dirname(__FILE__) . '/bb_hth_common.inc');

/* gets profile information for one or more states */
function _bb_hth_standing_resource_retreive ($year, $standing, $page, $ipp) {
  $current_year = 2013; // this will eventually be a drupal variable.
  $range = _get_range($page, $ipp);
  
  // different results for current/previous year landing pages
  $standing_list = isset($standing) ? array($standing) : array('finalist', 'semifinalist', 'contestant');
  if ($year == 'current') {
    $use_year = $current_year;
  }
  else {
    $use_year = $year;
    if(!isset($standing)) {
      array_unshift($standing_list, 'winner');  
    }
  }
  
  foreach ($standing_list as $standing) {
    $return_data["$year"]['items']["$standing"]['statuscode'] = 0;
    $return_data["$year"]['items']["$standing"]['statusmsg'] ='SUCCESS';
    $return_data["$year"]['items']["$standing"]['items']  = _get_profiles_for_standing ($use_year, $standing, $range);
  }    

  return($return_data);
}

function _get_profiles_for_standing ($year, $standing, $range) {
  $query = new EntityFieldQuery;
  
  $query->entityCondition('entity_type', 'node')
        ->propertyCondition('status', 1)
        ->propertyCondition('type', 'hotties_profile');

  $tid_year = taxonomy_get_term_by_name($year, 'hotties_contest_year');
  $query->fieldCondition('field_hotties_contest_year', 'tid', reset($tid_year)->tid);

  $tid_status = taxonomy_get_term_by_name($standing, 'hotties_contest_status');
  $query->fieldCondition('field_hotties_contest_status', 'tid', reset($tid_status)->tid);

  // get node data
  $node_data = $query->execute();
  $return_data = _get_profile_data_from_nodes ($node_data, $range);
  
  
  return($return_data);
}
