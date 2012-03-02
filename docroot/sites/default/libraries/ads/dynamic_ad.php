<?php
/* Currently not used.  Saved for possible future use */

$adType;
$channel;
$mainChannel;
$subChannel;
$ad = '';

if (!isset($_GET['type'])) {
  die();
} else {
  $adType = $_GET['type'];
}

if (isset($_GET['ch'])) {
  $channel = explode('|', $_GET['ch']);
  if (count($channel) > 0) {
    $mainChannel = $channel[0];
  }
  if (count($channel) > 1) {
    $subChannel = $channel[1];
  }
}

if(isset($_GET['ts']) && strlen($_GET['ts'])){
  $timestamp = $_GET['ts'];
} else {
  $timestamp = strtotime(date("Y-m-d H:i:s"));
}

if ($adType == 'fullslideshow'){
  switch($mainChannel){

  default:
    $ad = <<<AD
    <a href=""><img src="/sites/default/files/ads/android_app_slideshow.png" width="155" height="32" /></a>
AD;
  break;
  }
}

// Write ad
echo str_replace('[timestamp]', $timestamp, $ad);
