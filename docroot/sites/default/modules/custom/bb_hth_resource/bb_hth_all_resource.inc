<?php
// $Id$
require_once ( dirname(__FILE__) . '/bb_hth_common.inc');

function _bb_hth_all_resource_retreive ($year, $page, $ipp, $status) {
  // This is the range that we wil display
  $range_display = _get_range($page, $ipp); 
  
  $sendArray = _get_deduped_hth_week_data($year, $status);
  
  $return_data = _get_profile_data_from_nodes ($sendArray, $range_display);
  
  return($return_data);
}

