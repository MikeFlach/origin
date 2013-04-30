<?php
// $Id$
require_once ( dirname(__FILE__) . '/bb_hth_common.inc');

function _bb_hth_all_resource_retreive ($year, $page, $ipp, $status) {
  $return_data = array();
  $range = _get_range($page, $ipp);
  
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'node')
        ->propertyCondition('status', 1)
        ->propertyCondition('type', 'hotties_profile')
        ->range($range[0], $ipp)
        ->propertyOrderBy('changed', 'DESC');
        
  $tid_year = taxonomy_get_term_by_name($year, 'hotties_contest_year');
  $query->fieldCondition('field_hotties_contest_year', 'tid', reset($tid_year)->tid);
  
  if (!is_null($status)) {
    $tid_status = taxonomy_get_term_by_name($status, 'hotties_contest_status');
    $query->fieldCondition('field_hotties_contest_status', 'tid', reset($tid_status)->tid);
  }
  // get node data
  $node_data = $query->execute();
  $return_data = _get_profile_data_from_nodes ($node_data, $range, 'already_paged');
  
  return($return_data);
}
