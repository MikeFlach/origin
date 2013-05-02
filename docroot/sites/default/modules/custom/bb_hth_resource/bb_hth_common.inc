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
    $return_data['drupal-path'] =  $file->uri;
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
  $cleaned_qa = _close_html_tags(_clean_node_qa($qa['value']));

  $nid = $node_wrapper->nid->value();
  
  $city = $node_wrapper->field_profile_city->value();
  $state = taxonomy_term_load($node_wrapper->field_profile_state->value()->tid)->name;
  $hometown = $node_wrapper->field_profile_hometown->value();
  $year = taxonomy_term_load($node_wrapper->field_hotties_contest_year->value()->tid)->name;
  
  // not sure why week&main_image have to accessed this way ($node_wrapper->field_main_image->value()['fid'] is null for some reason)
  $rounds = $node_wrapper->field_hotties_contest_week->value();
  $contest_status = $node_wrapper->field_hotties_contest_status->value();
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
  $result['mainImageThumbnail'] = _replace_empty_with_null(image_style_url('thumbnail_large',$image_data['drupal-path']));
 
  $result['hometown'] =  _replace_empty_with_null("$city, $state");
  $result['stateAbbr'] = _get_short_state($state);
  
  $result['year'] = _replace_empty_with_null($year);
  $result['round'] = _replace_empty_with_null(_get_latest_round($rounds,  $contest_status));
  
  $result['height'] = _replace_empty_with_null($node_wrapper->field_profile_height->value());
  $result['weight'] = _replace_empty_with_null($node_wrapper->field_profile_weight->value());
  $result['measurements'] = $node_wrapper->field_profile_measurements->value();
  $result['profession'] = _replace_empty_with_null($node_wrapper->field_profile_profession_misc->value());
  
  $result['twitter'] = _replace_empty_with_null(_clean_tewitter_handle($node_wrapper->field_profile_twitter->value()));
  $result['facebook'] = _replace_empty_with_null(_clean_tewitter_handle($node_wrapper->field_profile_facebook->value()));
  
  $result['questionsAndAnswers'] = _replace_empty_with_null($cleaned_qa);
  
  $result['slideshow'] = _get_hottie_slideshow($slideshow_data[0]->nid);
  
  $result['statuscode'] = 0;
  $result['statusmsg'] = 'SUCCESS';
  
  return ($result);
}

function _get_hottie_slideshow ($nid) {
  $return_data = array();
  
  $ss = node_load($nid);
  $slides_items = field_get_items('node', $ss, 'field_slides_wrapper');

  $i = 0;
  foreach($slides_items as $slide_item) {
    $ar_slide = array();
    
    $slide_info = field_collection_field_get_entity($slide_item);
    $slide = $slide_info->field_slides[LANGUAGE_NONE][0];
    
    $ar_slide['slide']['fid'] = (int)$slide['fid'];
    
    $ar_slide['slide']['uri'] = file_create_url($slide['uri']);
    $ar_slide['slide']['maximLink'] = 'http://www.maxim.com/slideshow/hometown-hotties/'.$nid.'?slide='.$i++;
    
    $ar_slide['slide']['type'] = $slide['type'];
    if (($slide['type'] == 'video') && (strpos($slide['uri'], 'brightcove') !== FALSE)) {
      $brightcove_info = array();
      $brightcove_id = str_replace('brightcove://', '', $slide['uri']);
      
      $bc = brightcove_initialize();
      $video_details = $bc->find('find_video_by_id', array('video_id' => $brightcove_id, 'media_delivery' => 'http_ios'));  
      
      $brightcove_info['id'] = $brightcove_id;
      $brightcove_info['name'] = $video_details->name;
      $brightcove_info['shortDescription'] = $video_details->shortDescription;
      $brightcove_info['videoStillURL'] = $video_details->videoStillURL;
      $brightcove_info['thumbnailURL'] = $video_details->thumbnailURL;
      $brightcove_info['length'] = $video_details->length;
      $brightcove_info['FLVURL'] = $video_details->FLVURL;
      $brightcove_info['preroll'] =  variable_get('blackberry_preroll');
      $brightcove_info['sharelink'] = "http://www.maxim.com/maximtv/player/$brightcove_id?src=bb";
      
      $ar_slide['slide']['brightcoveInfo'] =  $brightcove_info;
    }

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

function _get_state_array() {
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
    
    return ($states);
}

function _get_long_state($abbr) {
  $states = _get_state_array();
  
  return ($states[strtoupper($abbr)]);

}

function _get_short_state($state) {
  $states = _get_state_array();
  
  $abbr = '';
  foreach($states as $key => $long_state) {
    if (strtolower($state) == strtolower($long_state)) {
      return($key);
    }
  }
  return ($abbr);
}

function _get_state_listing () {
  $states = _get_state_array();
  
  foreach($states as $short_state => $long_state) {
    $state['state']['abbr'] = $short_state;
    $state['state']['name'] = $long_state;
    
    $state_list[] = $state;
  }
  
  return($state_list);
}

function _get_paged_state_list ($range) {
  $return_data = array();
  $states = _get_state_array();
  
  $subArray = array_slice($states, $range[0], (($range[1] - $range[0])+1));
  foreach ($subArray as $state) {
    $return_data[] = $state;
  }
  
  return($return_data);
}

// return highest attained status
function _get_latest_round($rounds, $contest_status) {
  $hold_rounds = array();
  
  foreach ($rounds as $round) { 
    $hold_rounds[] = trim(strtolower($round->name));
  }
  foreach ($contest_status as $status) { 
    $hold_cs[] = trim(strtolower($status->name));
  }
  
  if (my_array_search('winner', $hold_cs)) {
    return ('Winner');
  }
  if (my_array_search('finalists', $hold_rounds)) {
    return ('Finalist');
  }
  if (my_array_search('semifinalist', $hold_rounds)) {
    return ('Semi-finalist');
  }
  else {
    return ('Round '.$rounds[0]->name);
  }
}

// return highest attained status
function _get_latest_status_tid($contest_status) {
  foreach ($contest_status as $status) { 
    $hold_cs[] = strtolower($status->name);
  }
  
  if (array_search('winner', $hold_cs)) {
    $tid = taxonomy_get_term_by_name('Winner', 'hotties_contest_status');
  }
  if (array_search('finalist', $hold_cs)) {
    $tid = taxonomy_get_term_by_name('Finalist', 'hotties_contest_status');
  }
  elseif (array_search('semifinalist', $hold_cs)) {
    $tid = taxonomy_get_term_by_name('Semifinalist', 'hotties_contest_status');
  }
  else {
    $tid = taxonomy_get_term_by_name('Contestant', 'hotties_contest_status');
  }
  
  return (reset($tid)->tid);
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
  if ($page == 0) {
    $range_start = 0;
    $range_end = $ipp-1;
  }
  else {
    $range_start = (($page) * $ipp);
    $range_end = $range_start + ($ipp-1);
  }

  return (array($range_start, $range_end));
}

function _get_prev_next_positions ($allKeys) {
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
  
function _get_profile_data_from_nodes($node_data, $range, $already_paged = NULL)  {
  $return_data = array();
  $allKeys = array_keys($node_data['node']);
 
  // get prev-next nids for all nodes returned from query
  $all_pn_positions = _get_prev_next_positions($allKeys);
  
  // get list of node_ids to load based on range
  $node_ids = array();
  for ($j = $range[0], $i = 0; $j <= $range[1]; $j++, $i++) {
    // the all tab query was already proceed with a range.
    $node_ids[$i] = (!isset($already_paged)) ? $allKeys[$j] : $allKeys[$i];
  }
  
  $nodes = node_load_multiple($node_ids);
  try {
    $return_data['statuscode'] = 0;
    $return_data['statusmsg'] ='SUCCESS';
    foreach ($nodes as $node) {
      $new_item = array();
      $new_item['profileItem'] =  _get_profile($node, $all_pn_positions[$node->nid]);

      $return_data['items'][] = $new_item;
    }
  }
  catch (Exception $e) {
    $return_data['statuscode'] = 1;
    $return_data['statusmsg'] ='FAILURE';
    $return_data['items'] = array();
  }
  
  return($return_data);
}

function _close_html_tags($html) {
  preg_match_all('#<(?!meta|img|br|hr|input\b)\b([a-z]+)(?: .*)?(?<![/|/ ])>#iU', $html, $result);
  $openedtags = $result[1];
  
  preg_match_all('#</([a-z]+)>#iU', $html, $result);
  $closedtags = $result[1];
  
  $len_opened = count($openedtags);
  if (count($closedtags) == $len_opened) {
    return $html;
  }
  
  $openedtags = array_reverse($openedtags);
  for ($i=0; $i < $len_opened; $i++) {
    if (!in_array($openedtags[$i], $closedtags)) {
      $html .= '</'.$openedtags[$i].'>';
    } 
    else {
      unset($closedtags[array_search($openedtags[$i], $closedtags)]);
    }
  }
    
  return $html;
} 

function _clean_tewitter_handle($twitter) {
  preg_match( '/(\w+)#?\s?$/', $twitter, $handle);
  
  if (empty($handle)) {
    $return = $twitter;
  } 
  elseif (count($handle) === 1) {
    $return = $handles[0];
  }
  elseif (count($handle) === 2) {
    $return = $handle[1];
  }
  
  return($return);
}

function my_array_search ($needle, $haystack) {
  foreach ($haystack as $item) {
    if (strtolower($item == $needle)) {
      return (true);
    }
  }
  return (false);
}