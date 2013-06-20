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