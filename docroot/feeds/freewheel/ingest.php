<?php

/**
 * Ingest response
 */

$filedir = $_SERVER['DOCUMENT_ROOT'] . '/sites/default/files/ads/freewheel_ingest_' . date('YmdHis') . '_';

$str = '';
foreach($_SERVER as $key=>$val) {
  $str .= $key . ': ' . $val . "\n";
}

file_put_contents($filedir . 'servervars.txt', $str);

$str = '';
foreach($_POST as $key=>$val) {
  $str .= $key . ': ' . $val . "\n";
}

file_put_contents($filedir . 'postvars.txt', $str);

/*try{
  foreach($_FILES as $key=>$val) {
    $filename = $filedir . $_FILES[$key]['name'];
    $tmpname = $_FILES[$key]['tmp_name'];
    move_uploaded_file ($tmpname, $filename);
  }
} catch(Exception $e) {

}*/
