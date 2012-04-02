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
  case '/girls/hometown-hotties':
    $ad = <<<AD
    <a href="http://ad.doubleclick.net/jump/maxim.dart/;adid=253396528;sz=145x40;ord=[timestamp]?" target="_blank"><img src="http://ad.doubleclick.net/ad/maxim.dart/;adid=253396528;sz=145x40;ord=[timestamp]?" border="0" alt="" /></a>
AD;
  break;
case '/springbreak':
    $ad = <<<AD
    <!-- begin ad tag -->
    <script type="text/javascript">
    //<![CDATA[
    ord=Math.random()*10000000000000000;
    document.write('<script type="text/javascript" src="http://ad.doubleclick.net/adj/maxim.dart/;adid=254469768;sz=145x40;ord=' + ord + '?"><\/script>');
    //]]>
    </script>
    <noscript><a href="http://ad.doubleclick.net/jump/maxim.dart/;adid=254469768;sz=145x40;ord=123456789?" target="_blank" ><img src="http://ad.doubleclick.net/ad/maxim.dart/;adid=254469768;sz=145x40;ord=123456789?" border="0" alt="" /></a></noscript>
    <!-- end ad tag -->
AD;
  break;
case '/gamergirl':
    $ad = <<<AD
    <!-- begin ad tag -->
    <script type="text/javascript">
    //<![CDATA[
    ord=Math.random()*10000000000000000;
    document.write('<script type="text/javascript" src="http://ad.doubleclick.net/adj/maxim.dart/;adid=254661241;sz=145x40;ord=' + ord + '?"><\/script>');
    //]]>
    </script>
    <noscript><a href="http://ad.doubleclick.net/jump/maxim.dart/;adid=254661241;sz=145x40;ord=123456789?" target="_blank" ><img src="http://ad.doubleclick.net/ad/maxim.dart/;adid=254661241;sz=145x40;ord=123456789?" border="0" alt="" /></a></noscript>
    <!-- end ad tag -->
AD;
  break;
}

// Write ad
echo str_replace('[timestamp]', $timestamp, $ad);
