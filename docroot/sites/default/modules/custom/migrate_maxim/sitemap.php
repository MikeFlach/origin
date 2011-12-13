<?php

error_reporting(E_ALL);
ini_set('display_errors', '1');

$sitemap = 'http://www.maxim.com/sitemapindex-amg.xml';  
$fullSitemap = file_get_contents($sitemap);
$fullSitemapXML=simplexml_load_string($fullSitemap);

$con = mysql_connect("localhost","maximdev","maxim");
if (!$con) { die('Could not connect: ' . mysql_error()); }

mysql_select_db("maximdev", $con);

// Loop thru each sitemaps
$ct=0;
foreach($fullSitemapXML as $sitemap){
  
  $sitemap_URL = $sitemap->loc;

  echo '<strong>' . $sitemap_URL . '</strong><br/>';

  $smFile = gzopen($sitemap_URL, "r");
  $smContents = gzread($smFile, 10000000);
  $smXML=simplexml_load_string($smContents);
  foreach($smXML as $sm){
    $ct++;
    $smURL = str_replace('http://www.maxim.com/amg','', $sm->loc);
    echo $ct . '. ' . $smURL . '<br/>';

    mysql_query("INSERT IGNORE INTO vgn_sitemap (sourceurl) VALUES ('$smURL')");
  }
  gzclose($smFile);
}

mysql_close($con);



?>
