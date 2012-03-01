<?php
$adType;
$channel;

if (!isset($_GET['type'])) {
  die();
} else {
  $adType = $_GET['type'];
}

if (isset($_GET['ch'])) {
  $channel = $_GET['ch'];
}

if(isset($_GET['ts']) && strlen($_GET['ts'])){
  $timestamp = $_GET['ts'];
} else {
  $timestamp = strtotime(date("Y-m-d H:i:s"));
}
$ad = '';

include('../../files/ads/dynamic_ads.inc');

// Write ad
echo str_replace('[timestamp]', $timestamp, $ad);

