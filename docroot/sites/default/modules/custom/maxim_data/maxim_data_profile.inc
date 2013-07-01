<?php
// $Id$

function _maxim_data_profile_retreive ($nid) {
  try {
    $profile_data['data'] = _maxim_data_get_profile ($nid);
    
    _maxim_data_append_error_info($profile_data, $e);
    
    return($profile_data);
  }
  catch (Exception $e) {
    $profile_data['data'] = array();
    
    _maxim_data_append_error_info($profile_data, $e);
    return ($profile_data);
  }
}

function _maxim_data_get_profile ($nid) {
  $node = node_load($nid);
  $node_wrapper = entity_metadata_wrapper('node', $node);
  
  // body
  $body = $node_wrapper->body->value();
  $cleaned_body = _maxim_data_close_html_tags(_maxim_data_clean_node_body($body['value']));
  
  $city = $node_wrapper->field_profile_city->value();
  $state = taxonomy_term_load($node_wrapper->field_profile_state->value()->tid)->name;
  $hometown = $node_wrapper->field_profile_hometown->value();
  $year = taxonomy_term_load($node_wrapper->field_hotties_contest_year->value()->tid)->name;
  
  // not sure why week&main_image have to accessed this way ($node_wrapper->field_main_image->value()['fid'] is null for some reason)
  $rounds = $node_wrapper->field_hotties_contest_week->value();
  $contest_status = $node_wrapper->field_hotties_contest_status->value();
  $main_image = $node_wrapper->field_main_image->value();
  $image_data = _get_file_data($main_image['fid']);
  
  //this is an array, which indicates there can be more than one slideshow. We are going to take the first slideshow (0 index). 
  $slideshow_data = $node_wrapper->field_profile_ref_slideshow->value(); 
  
  //setup array to return
  $result['nid'] = $nid;
  $result['name'] = $node_wrapper->field_profile_first_name->value();
  $result['maximLink'] = 'http://www.maxim.com'.url("node/$nid");
  $result['mainImage'] = _maxim_data_replace_empty_with_null($image_data['uri']);
  $result['mainImageThumbnail'] = _maxim_data_replace_empty_with_null(image_style_url('thumbnail_large',$image_data['drupal-path']));
  $result['hometown'] =  _maxim_data_replace_empty_with_null("$city, $state");
  $result['stateAbbr'] = _get_short_state($state);
  
  $result['year'] = _maxim_data_replace_empty_with_null($year);
  $result['round'] = _maxim_data_replace_empty_with_null(_get_latest_round($rounds,  $contest_status));
  $result['votingYearActive'] = ($result['year'] == variable_get('hth_contest_year', 0)) ? TRUE : FALSE;
  
  $result['height'] = _maxim_data_replace_empty_with_null($node_wrapper->field_profile_height->value());
  $result['weight'] = _maxim_data_replace_empty_with_null($node_wrapper->field_profile_weight->value());
  $result['measurements'] = $node_wrapper->field_profile_measurements->value();
  $result['profession'] = _maxim_data_replace_empty_with_null($node_wrapper->field_profile_profession_misc->value());
  
  $result['twitter'] = _maxim_data_replace_empty_with_null(_maxim_data_clean_social_handle($node_wrapper->field_profile_twitter->value()));
  $result['facebook'] = _maxim_data_replace_empty_with_null(_maxim_data_clean_social_handle($node_wrapper->field_profile_facebook->value()));
  
  $result['questionsAndAnswers'] = _maxim_data_replace_empty_with_null($cleaned_body);
  
  if (is_numeric($slideshow_data[0]->nid)) {
    $result['slideshow'] = _maxim_data_get_hottie_slideshow($slideshow_data[0]->nid);
  }
  else {
     $result['slideshow'] = array();
  }
  
  $result['statuscode'] = 0;
  $result['statusmsg'] = 'SUCCESS';
  
  return ($result);
}

function _maxim_data_get_hottie_slideshow ($nid) {
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


function _maxim_data_get_state_array() {
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

function _maxim_data_get_long_state($abbr) {
  $states = _maxim_data_get_state_array();
  
  return ($states[strtoupper($abbr)]);

}

function _maxim_data_get_short_state($state) {
  $states = _maxim_data_get_state_array();
  
  $abbr = '';
  foreach($states as $key => $long_state) {
    if (strtolower($state) == strtolower($long_state)) {
      return($key);
    }
  }
  return ($abbr);
}
