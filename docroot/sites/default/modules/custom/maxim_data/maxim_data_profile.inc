<?php
// $Id$

function _maxim_data_profile_retreive ($nid, $cache_break, $debug) {
  try {
    $profile_settings = _maxim_data_settings('profile');
    
    if ($cache_break) {
      cache_clear_all($profile_settings['profile_cache_name'], 'cache', TRUE);
    }
    
    if (!$profile_settings['profile_caching']) {
      $profile_data = _maxim_data_get_profile ($nid);
      _maxim_data_append_cache_info($profile_data, DATA_NOT_CACHED, DATA_NOT_FROM_CACHE, $debug);
    }
    else {
      // do we have any cached data?
      $cache_data = cache_get($profile_settings['profile_cache_name']); 
      if ($cache_data) {
        $cached_full = $cache_data->data;
        //if we have cahched data, do we have cached data for this particular nid?
        if (isset($cache_data->data[$nid])) {
          // retreive cached profile data 
          $profile_data = $cache_data->data[$nid];
          _maxim_data_append_cache_info($profile_data, DATA_CACHED, DATA_FROM_CACHE, $debug); 
        }
      }
      
      // if no profile data in cache
      if (!isset($profile_data)) {
        // get profile data
        $profile_data = _maxim_data_get_profile($nid); 
        
        // place newly retrieved profile into cache
        $nid_data_cache = isset($cached_full) ? $cached_full->data : array();
        $nid_data_cache[$nid] = $profile_data;
        cache_set($profile_settings['profile_cache_name'], $nid_data_cache, 'cache', time() + 60*($profile_settings['profile_cache_time_minutes']));
      }
    }
    
    _maxim_data_append_error_info($profile_data, NULL, $debug);
    return($profile_data);
  }
  catch (Exception $e) {
    $profile_data = array();
    
    _maxim_data_append_error_info($profile_data, $e, $debug);
    return ($profile_data);
  }
}

function _maxim_data_get_profile ($nid) {
  $node = node_load($nid);
  $node_wrapper = entity_metadata_wrapper('node', $node);
  
  // body
  $body = $node_wrapper->body->value();
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
  
  $result['body'] = _maxim_data_replace_empty_with_null($body['safe_value']);
  $result['summary'] = _maxim_data_replace_empty_with_null($body['safe_summary']);
  
  if (is_numeric($slideshow_data[0]->nid)) {
    $result['slideshow'] = _maxim_data_get_slideshow($slideshow_data[0]->nid);
  }
  else {
     $result['slideshow'] = array();
  }
  
  return ($result);
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
