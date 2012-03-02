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

/* top level sponsor ads */
switch ($murl){
case '/girls':
break;
case '/sports':
break;
case '/entertainment':
break;
case '/gadgets-rides':
break;
case '/upkeep':
break;
case '/vices':
break;
case '/tough':
break;
case '/funny':
break;
}

/* if $surl is defined, then override top level ad */
switch ($surl){
  case '/entertainment/oscars':
    $ad = <<<AD
    <!-- begin ad tag -->
    <script type="text/javascript" src="http://ad.doubleclick.net/adj/maxim.dart/;advertiser=ford;sz=145x40;ord=[timestamp]?"></script>
    <noscript><a href="http://ad.doubleclick.net/jump/maxim.dart/;advertiser=ford;sz=145x40;ord=[timestamp]?"><img src="http://ad.doubleclick.net/ad/maxim.dart/;advertiser=ford;sz=145x40;ord=[timestamp]?" border="0" alt="" /></a></noscript>
    <!-- end ad tag -->
AD;
  break;
  case '/girls/hometown-hotties':
    $ad = <<<AD
    <a href="http://ad.doubleclick.net/jump/maxim.dart/;adid=253396528;sz=145x40;ord=[timestamp]?" target="_blank"><img src="http://ad.doubleclick.net/ad/maxim.dart/;adid=253396528;sz=145x40;ord=[timestamp]?" border="0" alt="" /></a>
AD;
  break;
  case '/vices/booze':
    $ad = <<<AD
    <!-- begin ad tag -->
    <script type="text/javascript" src="http://ad.doubleclick.net/adj/maxim.dart/;adid=stoli_logo;sz=145x40;ord=[timestamp]?" target="_blank"></script>
    <noscript><a href="http://ad.doubleclick.net/jump/maxim.dart/;adid=stoli_logo;sz=145x40;ord=[timestamp]?"><img src="http://ad.doubleclick.net/ad/maxim.dart/;adid=stoli_logo;sz=145x40;ord=[timestamp]?" border="0" alt="" /></a></noscript>
    <!-- end ad tag -->
AD;
  break;
}

// Write ad
echo str_replace('[timestamp]', $timestamp, $ad);
