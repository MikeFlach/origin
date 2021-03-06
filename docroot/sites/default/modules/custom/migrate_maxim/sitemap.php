<?php

error_reporting(E_ALL);
ini_set('display_errors', '1');

// Include Drupal bootstrap
chdir($_SERVER['DOCUMENT_ROOT']);
define('DRUPAL_ROOT', getcwd());
require_once $_SERVER['DOCUMENT_ROOT'] . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

$sitemap = 'http://localhost.maxim.com/sitemapindex-amg.xml';
$fullSitemap = file_get_contents($sitemap);
$fullSitemapXML=simplexml_load_string($fullSitemap);

// Create old sitemap table if it does not exist
$query_create = "CREATE TABLE IF NOT EXISTS old_sitemap (
 sm_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
 sourceurl VARCHAR(255) NOT NULL DEFAULT '',
 targeturl VARCHAR(255) NOT NULL DEFAULT '',
 sitemap VARCHAR(255) NOT NULL DEFAULT '')";
$result = db_query($query_create);

// Loop thru each sitemaps
$ct=0;
foreach($fullSitemapXML as $sitemap){
  $sitemap_URL = str_replace('http://www.maxim.com','http://localhost.maxim.com', $sitemap->loc);
  echo '<strong>' . $sitemap_URL . '</strong><br/>';

  $smFile = gzopen($sitemap_URL, "r");
  $sitemapName = str_replace('http://localhost.maxim.com/sitemap-amg-','', $sitemap_URL);
  $sitemapName = str_replace('.xml.gz','', $sitemapName);
  $smContents = gzread($smFile, 10000000);
  $smXML=simplexml_load_string($smContents);

  foreach($smXML as $sm){
    $ct++;
    //$smURL = str_replace('http://www.maxim.com/amg','', $sm->loc);
    $smURL = str_replace('http://www.maxim.com','', $sm->loc);
    echo $ct . '. ' . $smURL . '<br/>';

    $qry_insert = "INSERT IGNORE INTO old_sitemap (sourceurl, sitemap) VALUES ('$smURL', '$sitemapName')";
    db_query($qry_insert);
  }
  gzclose($smFile);
}

?>
