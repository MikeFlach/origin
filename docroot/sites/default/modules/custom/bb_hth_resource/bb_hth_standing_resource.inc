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
  /*
  if(!isset($standing)) {
    array_unshift($standing_list, 'winner');  
  }
  */
  
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
  
  // if it is the current year, display current round else dispaly a randomized collection of profiles within year
  if ($standing == 'contestant') {
    if ($is_current_year) {
      $contest_week = variable_get('hth_contest_week');
    
      $tid_week = taxonomy_get_term_by_name($contest_week, 'hotties_contest_week');
      $query->fieldCondition('field_hotties_contest_week', 'tid', reset($tid_week)->tid);
    }
    else {
      $tid_status = taxonomy_get_term_by_name($standing, 'hotties_contest_status');
      $query->fieldCondition('field_hotties_contest_status', 'tid', reset($tid_status)->tid);
    
      //randomize for diversity
      $query->addTag("random");
    }
  }
  
  $tid_status = taxonomy_get_term_by_name($standing, 'hotties_contest_status');
  $query->fieldCondition('field_hotties_contest_status', 'tid', reset($tid_status)->tid);
  
  $tid_year = taxonomy_get_term_by_name($year, 'hotties_contest_year');
  $query->fieldCondition('field_hotties_contest_year', 'tid', reset($tid_year)->tid);
  
  //remove gamer girl profiles
  $tid_gamer_girl_week = taxonomy_get_term_by_name('Gamer Girl Finalist', 'hotties_contest_week');
  $query->fieldCondition('field_hotties_contest_week', 'tid', reset($tid_gamer_girl_week)->tid, '!=');

  // get node data
  $node_data = $query->execute();
  $return_data = _get_profile_data_from_nodes ($node_data, $range);
  
  
  return($return_data);
}

/**
 * Implementation of hook_query_TAG_alter
 */
function bb_hth_resource_query_random_alter($query) {
  $query->orderRandom();
}

