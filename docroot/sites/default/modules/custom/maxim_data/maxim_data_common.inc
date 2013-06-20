<?php
// $Id$

function _append_error_info (&$data_array, $e = NULL) {
  if (!$e) {
    $data_array['error']['status'] = 0; 
    $data_array['error']['msg'] = '';
  }
  else {
    $data_array['error']['status'] = 1; 
    $data_array['error']['msg'] = $e->getMessage();
  }
}

function _append_cache_info (&$data_array, $isCached, $fromCached) {
  $data_array['cache']['isCached'] = $isCached; 
  $data_array['cache']['fromCached'] = $fromCached;
}