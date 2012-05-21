<?php


error_reporting(E_ALL);
ini_set('display_errors', '1');

getHottieProfiles();

function getHottieProfiles(){
    $con = mysql_connect("ded-1108.prod.acquia-sites.com","maxim","Svb6pHHm8VJZ8S2");
  if (!$con) { die('Could not connect: ' . mysql_error()); }

  mysql_select_db("maxim", $con);

  $result = mysql_query("select * from field_data_field_profile_ref_slideshow where bundle='hotties_profile' order by entity_id asc");

  $ct=0;
  while($row = mysql_fetch_array($result)){
    $ct++;
    $source_URL = 'node/'.$row['field_profile_ref_slideshow_nid'];
    $target_URL = 'node/'.$row['entity_id'];
    echo $ct . ': ' . $source_URL . ' -> ' . $target_URL . ':' . redirect_hash($source_URL) .'<br>';
    mysql_query("REPLACE redirect(hash, type, uid, source, source_options, redirect, redirect_options, status_code)
      VALUES ('" . redirect_hash($source_URL) . "', 'redirect', 4, '" . $source_URL . "', 'a:0:{}', '" . $target_URL . "', 'a:0:{}', 0 )");
  }

  mysql_close($con);
}

function redirect_hash($source){
  $hash = array(
    'source' => $source,
    'language' =>'und'
  );
  redirect_sort_recursive($hash, 'ksort');
  return drupal_hash_base64(serialize($hash));
}

function redirect_sort_recursive(&$array, $callback = 'sort'){
  $result = $callback($array);
  foreach ($array as $key => $value){
    if (is_array($value)){
      $result &= redirect_sort_recursive($array[$key], $callback);
    }
  }
  return $result;
}

function drupal_hash_base64($data){
  $hash = base64_encode(hash('sha256', $data, TRUE));
  return strtr($hash, array('+' => '-', '/' => '_', '=' => ''));
}

/*
 * Clean Strings (remove special characters)
 */
function cleanString($str){
  return preg_replace('/[^a-zA-Z0-9_ -]/s', '', $str);
}

