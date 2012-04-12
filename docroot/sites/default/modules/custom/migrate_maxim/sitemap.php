<?php

error_reporting(E_ALL);
ini_set('display_errors', '1');

$sitemap = 'http://localhost.maxim.com/sitemapindex-amg.xml';  
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
  $sitemapName = str_replace('http://localhost.maxim.com/sitemap-amg-','', $sitemap_URL);
  $sitemapName = str_replace('.xml.gz','', $sitemapName);
  $smContents = gzread($smFile, 10000000);
  $smXML=simplexml_load_string($smContents);
  mysql_query("CREATE TABLE IF NOT EXISTS `old_sitemap` (
   `sm_id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
   `sourceurl` VARCHAR(255) NOT NULL DEFAULT '',
   `targeturl` VARCHAR(255) NOT NULL DEFAULT '',
   `sitemap` VARCHAR(255) NOT NULL DEFAULT ''
  );");
  foreach($smXML as $sm){
    $ct++;
    //$smURL = str_replace('http://www.maxim.com/amg','', $sm->loc);
    $smURL = str_replace('http://www.maxim.com','', $sm->loc);
    echo $ct . '. ' . $smURL . '<br/>';
    
    mysql_query("INSERT IGNORE INTO old_sitemap (sourceurl, sitemap) VALUES ('$smURL', '$sitemapName')");
  }
  gzclose($smFile);
}

mysql_close($con);



?>
