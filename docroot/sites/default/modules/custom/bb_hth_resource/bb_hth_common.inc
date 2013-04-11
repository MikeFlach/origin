<?php
// $Id$

function _date_between($dt_start, $dt_check, $dt_end){
  if(strtotime($dt_check) >= strtotime($dt_start) && strtotime($dt_check) <= strtotime($dt_end)) {
    return true;
  }
  
  return false;
} 

function _get_image_uri($fid) {
  $file = file_load($fid);
  if (strlen($file->uri) > 0) {
    return(file_create_url($file->uri));
  }
  else {
    return ('');
  }
}

function _get_profile_html ($node) {
  $result = array();
  
  $node_wrapper = entity_metadata_wrapper('node', $node);
  
  $qa = $node_wrapper->body->value();
  $cleaned_qa = _clean_node_qa($qa['value']);
  
  $result['questionsAndAnswers'] = $cleaned_qa;
  return ($result);
}

function _clean_node_qa ($text) {
 $remove_these = array("\r", "\n", "\t");
 $cleaned_text = preg_replace('#(<h2.*?>).*?(</h2>)#', '$1$2', $text);
 $cleaned_text = str_replace($remove_these, "", $cleaned_text);
 $cleaned_text = strip_tags($cleaned_text, '<strong><p><br>');
  
  return($cleaned_text);
}

function get_long_state($abbr) {
  $us_state_abbrevs_names = array(
    'AL'=>'ALABAMA','AK'=>'ALASKA','AS'=>'AMERICAN SAMOA','AZ'=>'ARIZONA','AR'=>'ARKANSAS',
    'CA'=>'CALIFORNIA','CO'=>'COLORADO','CT'=>'CONNECTICUT','DE'=>'DELAWARE','DC'=>'DISTRICT OF COLUMBIA',
    'FM'=>'FEDERATED STATES OF MICRONESIA','FL'=>'FLORIDA','GA'=>'GEORGIA','GU'=>'GUAM GU','HI'=>'HAWAII',
    'ID'=>'IDAHO','IL'=>'ILLINOIS','IN'=>'INDIANA','IA'=>'IOWA','KS'=>'KANSAS','KY'=>'KENTUCKY',
    'LA'=>'LOUISIANA','ME'=>'MAINE','MH'=>'MARSHALL ISLANDS','MD'=>'MARYLAND','MA'=>'MASSACHUSETTS','MI'=>'MICHIGAN',
    'MN'=>'MINNESOTA','MS'=>'MISSISSIPPI','MO'=>'MISSOURI','MT'=>'MONTANA','NE'=>'NEBRASKA','NV'=>'NEVADA',
    'NH'=>'NEW HAMPSHIRE','NJ'=>'NEW JERSEY','NM'=>'NEW MEXICO','NY'=>'NEW YORK','NC'=>'NORTH CAROLINA',
    'ND'=>'NORTH DAKOTA','MP'=>'NORTHERN MARIANA ISLANDS','OH'=>'OHIO','OK'=>'OKLAHOMA','OR'=>'OREGON','PW'=>'PALAU',
    'PA'=>'PENNSYLVANIA','PR'=>'PUERTO RICO','RI'=>'RHODE ISLAND','SC'=>'SOUTH CAROLINA','SD'=>'SOUTH DAKOTA',
    'TN'=>'TENNESSEE','TX'=>'TEXAS','UT'=>'UTAH','VT'=>'VERMONT','VI'=>'VIRGIN ISLANDS','VA'=>'VIRGINIA',
    'WA'=>'WASHINGTON','WV'=>'WEST VIRGINIA','WI'=>'WISCONSIN','WY'=>'WYOMING'
  );
  
  return($us_state_abbrevs_names[$abbr]);
}