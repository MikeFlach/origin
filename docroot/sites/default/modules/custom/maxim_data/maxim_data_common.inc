<?php
// $Id$

function _maxim_data_append_error_info (&$data_array, $e = NULL, $debug) {
  if ($debug) {
    if (!$e) {
      $err['status'] = 0; 
      $err['msg'] = '';
    }
    else {
      $err['status'] = 1; 
      $err['msg'] = $e->getMessage();
    }
    
    $data_array['error'] = $err;
  }
}

function _maxim_data_append_cache_info (&$data_array, $isCached, $fromCached, $debug) {
  if ($debug) {
    $cache_info['isCached'] = $isCached; 
    $cache_info['fromCached'] = $fromCached;
    
    $data_array['cache'] = $cache_info;
  }
}

function _maxim_data_clean_node_body ($text) {
  $remove_these = array("\r", "\n", "\t", "&nbsp;", "&nbsp");
  $brReplace = array('<br>','<br />');
  
  //needs to happen before replacement of & to &amp;
  $cleaned_text = str_replace('&#151;', '-', $text);
  
  $cleaned_text = str_replace('<h2>', '<strong>', str_replace('</h2>', '</strong>', $cleaned_text));
  $cleaned_text = preg_replace("/<img[^>]+\>/i", '', $cleaned_text); 
  $cleaned_text = preg_replace('#<a.*?>([^<]*)</a>#i', '$1', $cleaned_text);
  $cleaned_text = str_replace($remove_these, "", $cleaned_text);
  $cleaned_text = preg_replace("/&(?!amp;)/", "&amp;",  $cleaned_text);
  $cleaned_text = str_replace($brReplace, '<br/>', $cleaned_text);
  $cleaned_text = str_replace('<3', '&lt;3', $cleaned_text);
  $cleaned_text = str_replace('<-', '&lt;-', $cleaned_text);
  
  $cleaned_text = "<html>$cleaned_text</html>";
  
  return($cleaned_text);
}

function _maxim_data_close_html_tags($html) {
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

function _maxim_data_replace_empty_with_null($value) {
  if (strlen($value)) {
    return($value);
  }
  else {
    return null;
  }
}

function _maxim_data_get_file_data($fid) {
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

function _maxim_data_clean_social_handle($uname) {
  $handle = array();
  
  preg_match( '/(\w+)#?\s?$/', $uname, $handle);
  
  if (empty($handle)) {
    $return = $uname;
  } 
  elseif (count($handle) === 1) {
    $return = $handle[0];
  }
  elseif (count($handle) === 2) {
    $return = $handle[1];
  }
  
  return($return);
}

function _maxim_data_get_range ($page, $ipp) {
  $range[0] = ($page == 1) ? 0 : (($page - 1) * $ipp);
  $range[1] = $ipp;
  
  return ($range);
}

function _maxim_data_get_slideshow ($nid) {
  $return_data = array();
  
  $ss = node_load($nid);
  $ss_wrapper = entity_metadata_wrapper('node', $ss);
  $slides_items = field_get_items('node', $ss, 'field_slides_wrapper');
  
  $body = reset(field_get_items('node', $ss, 'body'));
  
  $return_data['nid'] = $ss->nid;
  $return_data['body'] = $body['safe_value'];
  $return_data['summary'] = $body['safe_summary'];
  $return_data['title'] = $ss_wrapper->title->value();
  $return_data['channel'] = $ss_wrapper->field_channel->value()->name;
  $return_data['column'] = $ss_wrapper->field_column->value()->name;
  
  $i = 0;
  foreach($slides_items as $slide_item) {
    $ar_slide = array();
    $slide = reset(reset(reset(entity_load('field_collection_item', array($slide_item['value'])))->field_slides));
    
    $ar_slide['slide']['fid'] = (int)$slide['fid'];
    $ar_slide['slide']['maximLink'] = 'http://www.maxim.com/slideshow/hometown-hotties/'.$nid.'?slide='.$i++;
    $ar_slide['slide']['title'] = _maxim_data_replace_empty($slide['field_media_title'], null);
    $ar_slide['slide']['caption'] = _maxim_data_replace_empty($slide['field_media_caption'], null);
    
    $ar_slide['slide']['description'] = _maxim_data_process_field_info ($slide['field_media_description'], 'safe_value');
    $ar_slide['slide']['copyright'] = _maxim_data_process_field_info ($slide['field_media_copyright'], 'safe_value');
    $ar_slide['slide']['creator'] = _maxim_data_process_field_info ($slide['field_image_creator'], 'tid');
    $ar_slide['slide']['clothing-credit'] = _maxim_data_process_field_info ($slide['field_image_clothing_credit'], 'safe_value');

    $ar_slide['slide']['type'] = $slide['type'];
    $ar_slide['slide']['uri'] = file_create_url($slide['uri']);
    if ((strpos($slide['uri'], 'brightcove') !== FALSE)) {
      $ar_slide['slide']['type'] = 'video';
      
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

    $return_data['slideshow'][] = $ar_slide;
  }
  
  return($return_data);
}

function _maxim_data_replace_empty($value, $replace) {
  if (!empty($value)) {
    return($value);
  }
  else {
    return ($replace);
  }
}

function _maxim_data_process_field_info ($field, $field_name) {
  if (!empty($field)) {
    if (is_array($field)) {
      while (is_array($field) && (!isset($data[$field_name]))) {
        $field = reset($field);
      }
      
      if (!isset($field[$field_name])) {
        $dp = null;
      }
      elseif ($field_name != 'tid') {
        $dp = $field[$field_name];
      }
      elseif ($field_name == 'tid') { 
        $dp = taxonomy_term_load($field[$field_name])->name;
      }
    }
    else {
      $dp = $field;
    }
  }
  else {
    $dp = null;
  }
  
  return ($dp);
}

// return highest attained status
function _maxim_data_get_latest_hth_round($rounds, $contest_status) {
  $hold_rounds = array();
  
  foreach ($rounds as $round) { 
    $hold_rounds[] = trim(strtolower($round->name));
  }
  foreach ($contest_status as $status) { 
    $hold_cs[] = trim(strtolower($status->name));
  }
  
  // we don't care about winner becuase this is used for prev/next (no nq for just winners)
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

function _maxim_data_my_array_search ($needle, $haystack) {
  foreach ($haystack as $item) {
    if (strtolower($item == $needle)) {
      return (true);
    }
  }
  return (false);
}