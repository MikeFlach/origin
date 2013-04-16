<?php
// $Id$

function _date_between($dt_start, $dt_check, $dt_end){
  if(strtotime($dt_check) >= strtotime($dt_start) && strtotime($dt_check) <= strtotime($dt_end)) {
    return true;
  }
  
  return false;
} 

function _get_file_data($fid) {
  $return_data = array();
  
  $file = file_load($fid);
  
  if ($file) {
    $return_data['uri'] = (strlen($file->uri) > 0) ? file_create_url($file->uri) : null;
    $return_data['type'] = (strlen($file->type) > 0) ? $file->type : null;
  }
  else {
    $return_data['uri'] = null;
    $return_data['type'] = 'video';
  }
  
  return($return_data);
}

function _get_profile ($node, $pn_positions) {
  $result = array();
  $node_wrapper = entity_metadata_wrapper('node', $node);
 
  // q & a
  $qa = $node_wrapper->body->value();
  $cleaned_qa = _clean_node_qa($qa['value']);

  $nid = $node_wrapper->nid->value();
  
  $city = $node_wrapper->field_profile_city->value();
  $state = taxonomy_term_load($node_wrapper->field_profile_state->value()->tid)->name;
  $hometown = $node_wrapper->field_profile_hometown->value();
  $year = taxonomy_term_load($node_wrapper->field_hotties_contest_year->value()->tid)->name;
  
  // not sure why week&main_image have to accessed this way ($node_wrapper->field_main_image->value()['fid'] is null for some reason)
  $rounds = $node_wrapper->field_hotties_contest_week->value();
  $main_image = $node_wrapper->field_main_image->value();
  $image_data = _get_file_data($main_image['fid']);
  
  //this is an array, which indicates there can be more than one slideshow. We are going to take the first slideshow(0 index). 
  $slideshow_data = $node_wrapper->field_profile_ref_slideshow->value(); 
  
  //setup array to return
  $result['nid'] = (int)$nid;
  
  $result['prevID'] = $pn_positions['prev'];
  $result['nextID'] = $pn_positions['next'];
  
  $result['name'] = $node_wrapper->field_profile_first_name->value();
  $result['maximLink'] = 'http://www.maxim.com'.url("node/$nid");
  $result['mainImage'] = _replace_empty_with_null($image_data['uri']);
 
  $result['hometown'] =  _replace_empty_with_null(_get_hometown($city, $state, $hometown, $year));
  
  $result['year'] = _replace_empty_with_null($year);
  $result['round'] = _replace_empty_with_null(_get_latest_round($rounds));
  $result['finalistPlace'] = null;
  
  $result['height'] = _replace_empty_with_null($node_wrapper->field_profile_height->value());
  $result['weight'] = _replace_empty_with_null($node_wrapper->field_profile_weight->value());
  $result['measurements'] = $node_wrapper->field_profile_measurements->value();
  $result['relationshipStatus'] = _replace_empty_with_null('');
  $result['profession'] = _replace_empty_with_null($node_wrapper->field_profile_profession_misc->value());
  
  $result['twitter'] = _replace_empty_with_null($node_wrapper->field_profile_twitter->value());
  $result['facebook'] = _replace_empty_with_null($node_wrapper->field_profile_facebook->value());
  
  $result['questionsAndAnswers'] = _replace_empty_with_null($cleaned_qa);
  
  $result['slideshow'] = _get_hottie_slideshow($slideshow_data[0]->nid);
  
  return ($result);
}

function _get_hottie_slideshow ($nid) {
  $return_data = array();
  
  $ss = node_load($nid);
  $slides_items = field_get_items('node', $ss, 'field_slides_wrapper');

  $ar_slide = array();
  $i = 0;
  foreach($slides_items as $slide_item) {
    $slide_info = field_collection_field_get_entity($slide_item);
    $slide = $slide_info->field_slides[LANGUAGE_NONE][0];
    
    $ar_slide['slide']['fid'] = (int)$slide['fid'];
    $ar_slide['slide']['type'] = $slide['type'];
    $ar_slide['slide']['uri'] = file_create_url($slide['uri']);
    $ar_slide['slide']['maximLink'] = 'http://www.maxim.com/slideshow/hometown-hotties/'.$nid.'?slide='.$i++;
    
    $return_data[] = $ar_slide;
  }
  
  return($return_data);
}

function _clean_node_qa ($text) {
  $remove_these = array("\r", "\n", "\t");
  $cleaned_text = preg_replace('#(<h2.*?>).*?(</h2>)#', '$1$2', $text);
  $cleaned_text = str_replace($remove_these, "", $cleaned_text);
  $cleaned_text = strip_tags($cleaned_text, '<strong><p><br>');
  
  return($cleaned_text);
}

function _get_long_state($abbr) {
  $states = array(
    'AL' => 'Alabama','AK' => 'Alaska','AZ' => 'Arizona','AR' => 'Arkansas',
    'CA' => 'California','CO' => 'Colorado','CT' => 'Connecticut','DE' => 'Delaware','DC' => 'District Of Columbia',
    'FL' => 'Florida','GA' => 'Georgia','HI' => 'Hawaii','ID' => 'Idaho','IL' => 'Illinois','IN' => 'Indiana','IA' => 'Iowa',
    'KS' => 'Kansas','KY' => 'Kentucky','LA' => 'Louisiana','ME' => 'Maine','MD' => 'Maryland','MA' => 'Massachusetts',
    'MI' => 'Michigan','MN' => 'Minnesota','MS' => 'Mississippi','MO' => 'Missouri','MT' => 'Montana','NE' => 'Nebraska',
    'NV' => 'Nevada','NH' => 'New Hampshire','NJ' => 'New Jersey','NM' => 'New Mexico','NY' => 'New York','NC' => 'North Carolina',
    'ND' => 'North Dakota','OH' => 'Ohio','OK' => 'Oklahoma','OR' => 'Oregon','PA' => 'Pennsylvania','RI' => 'Rhode Island',
    'SC' => 'South Carolina','SD' => 'South Dakota','TN' => 'Tennessee','TX' => 'Texas','UT' => 'Utah','VT' => 'Vermont',
    'VA' => 'Virginia','WA' => 'Washington','WV' => 'West Virginia','WI' => 'Wisconsin','WY' => 'Wyoming');
  
  return($states[strtoupper($abbr)]);
}

// for pre-2014 hotties return city, state for hometown. otherwise, return hometown.
function _get_hometown ($city, $state, $hometown, $year) {
  if ((int)$year > 2013) {
    $hometown = $hometown;
  }
  else {
    $hometown = "$city, $state";
  }
  
  return($hometown);
}

// return highest attained status
function _get_latest_round($rounds) {
  $hold_rounds = array();
  
  foreach ($rounds as $round) { 
    $hold_rounds[] = strtolower($round->name);
  }
  
  if (array_search('finalists', $hold_rounds)) {
    return ('Finalist');
  }
  elseif (array_search('semifinalist', $hold_rounds)) {
    return ('Semi-finalist');
  }
  else {
    return ($rounds[0]->name);
  }
}

function _replace_empty_with_null($value) {
  if (strlen($value)) {
    return($value);
  }
  else {
    return null;
  }
}

function _get_range ($page, $ipp) {
  if ($page == 1) {
    $range_start = 0;
    $range_end = $ipp-1;
  }
  else {
    $range_start = (($page - 1) * $ipp);
    $range_end = $range_start + ($ipp-1);
  }

  return (array($range_start, $range_end));
}

function _get_prev_next_positions ($allKeys, $tab) {
  // we need to get a handle on where each profile fits in the whole result set for prev/next links
  $positions = array();
  $node_count = count($allKeys);
  for ($i = 0; $i < $node_count; $i++) {
    // special case for no prev hth
    if ($i === 0) {
      $positions[$allKeys[$i]]['prev'] = null;
      $positions[$allKeys[$i]]['next'] = $allKeys[$i+1];
    }
    // special case for no next hth
    elseif ($i === ($node_count - 1)) {
      $positions[$allKeys[$i]]['prev'] = $allKeys[$i-1];
      $positions[$allKeys[$i]]['next'] = null;
    }
    else {
      $positions[$allKeys[$i]]['prev'] = $allKeys[$i-1];
      $positions[$allKeys[$i]]['next'] = $allKeys[$i+1];
    }
  }
  
  return ($positions);
}