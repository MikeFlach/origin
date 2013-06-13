<?php

/* Push import for Sony Feed */
date_default_timezone_set('America/Los_Angeles');

function makeRFC3339($timestamp) {
  $timestring=date("Y-m-d\TH:i:s",$timestamp);
  $offset=date("O");
  for ($i=0; $i<5; $i++) {
    $timestring.=$offset[$i];
    if ($i==2) {
      $timestring.=':';
    }
  }
  return $timestring;
}

$pushURLPath = '/trebuchet/remoteCommands/TREBpushImport/?';

$privateKey = 'maxim_dev';
$sonyDomain = 'http://b2b-dev.internet.sony.tv';
$service_name = 'US-Maxim_wt';
$feed_id = 9381;

// Production
/*
$privateKey = 'M3x1mPr0d1mP0rT';
$sonyDomain = 'http://b2b.internet.sony.tv';
$service_name = 'US-Maxim';
$feed_id = 4078;*/

$pushURL = $sonyDomain . $pushURLPath . 'service_name=' . $service_name . '&method=fromFeed&feed_id=' . $feed_id .'&timestamp=' . urlencode(makeRFC3339(time()));

$sig = md5($pushURL . $privateKey);
$pushURL .= '&sig=' . $sig;

header ("Content-Type:text/xml");
$response = file_get_contents($pushURL);
echo $response;
