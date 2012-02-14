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
switch($murl){
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
}

// Write ad
echo str_replace('[timestamp]', $timestamp, $ad);

function parseIniFile($iIniFile){
  $aResult  =
  $aMatches = array();
  $a = &$aResult;
  $s = '\s*([[:alnum:]_\- \*]+?)\s*';
  preg_match_all('#^\s*((\['.$s.'\])|(("?)'.$s.'\\5\s*=\s*("?)(.*?)\\7))\s*(;[^\n]*?)?$#ms', @file_get_contents($iIniFile), $aMatches, PREG_SET_ORDER);

  foreach ($aMatches as $aMatch){
    if (empty($aMatch[2]))
      $a [$aMatch[6]] = $aMatch[8];
    else
      $a = &$aResult [$aMatch[3]];
    }
  return $aResult;
}
