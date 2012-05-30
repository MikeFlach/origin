<?php

error_reporting(E_ALL);
ini_set('display_errors', '1');

$arFiles = array();
$maxLinks = 100;

// Database connection
$con = mysql_connect("localhost","maximdev","maxim");
if (!$con) { die('Could not connect: ' . mysql_error()); }
mysql_select_db("maxim", $con);

$datetime = date(DATE_ATOM);

// Get distinct sitemaps
$sitemaps = mysql_query("select distinct sitemap from old_sitemap");

$strSitemap = '';
// Loop thru sitemaps, create sitemap file
while ($row = mysql_fetch_assoc($sitemaps)) {
   $strSitemap .= '<sitemap><loc>http://www.maxim.com/sites/default/files/xmlsitemap/old/' . $row['sitemap'] . '.xml</loc><lastmod>' . $datetime . '</lastmod></sitemap>' . "\n";
  // Create sitemap file
  $sitemap_file = '/var/sites/dev-maxim/docroot/sites/default/files/xmlsitemap/old/' . $row['sitemap'] .'.xml';
  array_push($arFiles, $sitemap_file);
}

// Create main xml file
$strHTML = '<?xml version="1.0" encoding="UTF-8"?>' . "\n" . '<sitemapindex xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">'. "\n";
$strHTML .= $strSitemap;
$strHTML .= '</sitemapindex>' . "\n";
file_put_contents('/var/sites/dev-maxim/docroot/sites/default/files/xmlsitemap/old/main.xml', $strHTML);

// Get all old URLs from DB
$oldURLs = mysql_query("select * from old_sitemap order by sitemap, sourceurl");

$ct = 0;
$prev_filect = 1;
$prev_sitemap = '';
while ($row = mysql_fetch_assoc($oldURLs)) {
  $current_sitemap = $row['sitemap'];
  $sitemap_file = '/var/sites/dev-maxim/docroot/sites/default/files/xmlsitemap/old/' . $current_sitemap .'.xml';

  if (!file_exists($sitemap_file)) {
    file_put_contents($sitemap_file, '<?xml version="1.0" encoding="UTF-8"?>' . "\n" . '<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">' . "\n");
  }

  file_put_contents($sitemap_file, '<url><loc>http://www.maxim.com' . $row['sourceurl'] . '</loc><lastmod>' . $datetime . '</lastmod><priority>0.7</priority></url>' . "\n", FILE_APPEND); 

  $prev_sitemap = $current_sitemap;
}

// Close html in files
foreach ($arFiles as $sitemap_filename){
  echo $sitemap_filename . '<br />';
  file_put_contents($sitemap_filename, '</urlset>', FILE_APPEND);
}

mysql_close($con);

?>
