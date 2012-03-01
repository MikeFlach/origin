<?php
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
  
  if(isset($_GET['ts']) && strlen($_GET['ts'])){
    $timestamp = $_GET['ts'];
  } else {
    $timestamp = strtotime(date("Y-m-d H:i:s"));
  }
  $ad = '';

// include ads
include('../../files/ads/menu_sponsor_ads.inc');

// Write ad
echo str_replace('[timestamp]', $timestamp, $ad);
