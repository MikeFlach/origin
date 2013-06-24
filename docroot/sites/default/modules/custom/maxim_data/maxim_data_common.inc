<?php
// $Id$

function _maxim_data_append_error_info (&$data_array, $e = NULL) {
  if (!$e) {
    $data_array['error']['status'] = 0; 
    $data_array['error']['msg'] = '';
  }
  else {
    $data_array['error']['status'] = 1; 
    $data_array['error']['msg'] = $e->getMessage();
  }
}

function _maxim_data_append_cache_info (&$data_array, $isCached, $fromCached) {
  $data_array['cache']['isCached'] = $isCached; 
  $data_array['cache']['fromCached'] = $fromCached;
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
  preg_match( '/(\w+)#?\s?$/', $uname, $handle);
  
  if (empty($handle)) {
    $return = $uname;
  } 
  elseif (count($handle) === 1) {
    $return = $handles[0];
  }
  elseif (count($handle) === 2) {
    $return = $handle[1];
  }
  
  return($return);
}