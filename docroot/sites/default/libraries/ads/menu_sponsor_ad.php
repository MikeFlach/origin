<?php
/*
 * Menu Sponsor Ad
 * 6/21/2012 [HW] Change to using XML file for menu ads (/sites/default/files/private-files/ads/menu_ads.xml)
 */

// if no referer then don't serve
/*if(!isset($_SERVER['HTTP_REFERER'])){
  die();
} else {
  //$url = parse_url($_SERVER['HTTP_REFERER']);
  //$path = $url['path'];
}*/
if(!isset($_GET['murl']) && !isset($_GET['surl'])){
  die();
}

// main channel url
$murl = '';
if(isset($_GET['murl'])){
  $murl = $_GET['murl'];
}

// subchannel url
$surl = '';
if(isset($_GET['surl'])){
  $surl = $_GET['surl'];
}

$ad = '';
$xmlfile = $_SERVER['DOCUMENT_ROOT'] . '/sites/default/files/private-files/ads/menu_ads.xml';

if (file_exists($xmlfile) || die()) {
  try {
    $xml = simplexml_load_file($xmlfile);
    // Check to see if main channel URL exists - For sponsoring the whole menu section
    foreach ($xml->children() as $child) {
      if (isset($child->attributes()->dir) && $child->attributes()->dir == $murl) {
        if ( isDateBetween($child->attributes()->startdate, $child->attributes()->enddate) ) {
          $ad=$child;
          break;
        }
      }
    }
    // Check to see if subchannel URL exists - Overrides main menu ad
    foreach ($xml->children() as $child) {
      if (isset($child->attributes()->dir) && $child->attributes()->dir == $surl) {
        if ( isDateBetween($child->attributes()->startdate, $child->attributes()->enddate) ) {
          $ad=$child;
        }
        break;
      }
    }
  } catch (Exception $e) { /* Do nothing */ }
}

if (strlen($ad) > 0) {
  if(isset($_GET['ts']) && strlen($_GET['ts'])){
    $timestamp = $_GET['ts'];
  } else {
    $timestamp = strtotime(date("Y-m-d H:i:s"));
  }

  // Write ad
  echo str_replace('[timestamp]', $timestamp, $ad);
}

function isValidDate ($dateString) {
  $x = strtotime ($dateString);
  if ($x === false || $x == -1) {
    return false;
  } else {
    return true;
  }
}

function isDateBetween($dt_start = 'yesterday', $dt_end = 'tomorrow', $dt_check='now'){
  if (!isValidDate($dt_start)) {
    $dt_start = 'yesterday';
  }
  if (!isValidDate($dt_end)) {
    $dt_end = 'tomorrow';
  }
  if (!isValidDate($dt_check)) {
    $dt_check = 'now';
  }
  if(strtotime($dt_check) > strtotime($dt_start) && strtotime($dt_check) < strtotime($dt_end)) {
    return true;
  }
  return false;
}
