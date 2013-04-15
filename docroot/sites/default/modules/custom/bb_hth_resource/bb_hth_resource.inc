<?php
// $Id$
require_once ( dirname(__FILE__) . '/bb_hth_common.inc');

function _bb_hth_resource_retreive_hth($year, $week, $state, $status, $page, $ipp) {
  $query = new EntityFieldQuery;
  
  if ($page == 1) {
    $range_start = 0;
    $range_end = $ipp-1;
  }
  else {
    $range_start = (($page - 1) * $ipp);
    $range_end = $range_start + ($ipp-1);
  }

  $query->entityCondition('entity_type', 'node')
        ->propertyCondition('status', 1)
        ->propertyCondition('type', 'hotties_profile')
        ->range($range_start, $ipp);

  // we use reset to retreive first element because the array returned by taxonomy_get_term_by_name is indexed by the tid, which we fon't have.
  if (!is_null($year)) {
    $tid_year = taxonomy_get_term_by_name($year, 'hotties_contest_year');
    $query->fieldCondition('field_hotties_contest_year', 'tid', reset($tid_year)->tid);
  }
  if (!is_null($week)) {
    $tid_week = taxonomy_get_term_by_name($week, 'hotties_contest_week');
    $query->fieldCondition('field_hotties_contest_week', 'tid', reset($tid_week)->tid);
  }
  if (!is_null($state)) {
    $tid_state = taxonomy_get_term_by_name($state, 'states_provinces');
    $query->fieldCondition('field_profile_state', 'tid', reset($tid_state)->tid);
  }
  if (!is_null($status)) {
    $tid_status = taxonomy_get_term_by_name($status, 'hotties_contest_status');
    $query->fieldCondition('field_hotties_contest_status', 'tid', reset($tid_status)->tid);
  }
  
  // get node data
  $node_ids = array();
  $node_data = $query->execute();
 
  foreach($node_data['node'] as $node) {
    $node_ids[] = $node->nid;
  }
  
  $data =  _get_node_data($node_ids);
 // $data[] = "RS:$range_start"; $data[] = "RE:$range_end";
  
  return($data);
}

function _get_node_data($node_ids) {
  $nodes = node_load_multiple($node_ids);
  
  // we need to replace the tids returned in node_load_multiple with the actual term 
  $return_data = array();
  $i = 0;
  foreach ($nodes as $node) { 
    $node_wrapper = entity_metadata_wrapper('node', $node);
    
    // for pre-2014 hotties return city, state for hometown. otherwise, return hometown.
    $year = taxonomy_term_load($node_wrapper->field_hotties_contest_year->value()->tid)->name;
    $city = $node_wrapper->field_profile_city->value();
    $state = taxonomy_term_load($node_wrapper->field_profile_state->value()->tid)->name;
    if ((int)$year > 2013) {
      $hometown = $node_wrapper->field_profile_hometown->value();
    }
    else {
       $hometown = "$city, $state";
    }
    
    // get terms from tid
    $nid = $node_wrapper->nid->value();
   // $return_data[$i]['record'] = $i;
    $return_data[$i]['nid'] = $nid;
    $return_data[$i]['name'] = $node_wrapper->field_profile_first_name->value();
    $return_data[$i]['hometown'] = $hometown;
    $return_data[$i]['profileLink'] = 'http://www.maxim.com'.url("node/$nid");
    
    $image = $node_wrapper->field_main_image->value(); 
    $return_data[$i++]['mainImage'] = _get_image_uri($image['fid']);
  }
  
  return ($return_data);
}

function _get_image_uri($fid) {
  $file = file_load($fid);
  if (strlen($file->uri) > 0) {
    return(file_create_url($file->uri));
  }
  else {
    return('');
  }
}

function _get_profile_html ($nid) {
  return ("PROFILE DATA");
}