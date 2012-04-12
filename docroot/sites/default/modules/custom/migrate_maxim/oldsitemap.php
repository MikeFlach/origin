<?php

error_reporting(E_ALL);
ini_set('display_errors', '1');

$arFiles = array();
$maxLinks = 100;

// Database connection
$con = mysql_connect("localhost","maximdev","maxim");
if (!$con) { die('Could not connect: ' . mysql_error()); }
mysql_select_db("maximdev", $con);

// Get distinct sitemaps
$sitemaps = mysql_query("select distinct sitemap from old_sitemap");


$strSitemap = '';
// Loop thru sitemaps, create sitemap file
while ($row = mysql_fetch_assoc($sitemaps)) {
   $strSitemap .= '<a href="/sites/default/files/xmlsitemap/old/' . $row['sitemap'] . '-1.html">' . $row['sitemap'] . '</a><br>';
  // Create sitemap file
  $sitemap_file = '/var/sites/dev-maxim/docroot/sites/default/files/xmlsitemap/old/' . $row['sitemap'] .'-1.html';
  array_push($arFiles, $sitemap_file);
  file_put_contents($sitemap_file, '<html><head><title></title><body>');
}

// Create main html file
$strHTML = '<html><head><title>Maxim site links</title></head><body>';
$strHTML .= $strSitemap;
$strHTML .= '</body></html>';
file_put_contents('/var/sites/dev-maxim/docroot/sites/default/files/xmlsitemap/old/main.html', $strHTML);

// Get all old URLs from DB
$oldURLs = mysql_query("select * from old_sitemap order by sitemap, sourceurl");

$ct = 0;
$prev_filect = 1;
$prev_sitemap = '';
while ($row = mysql_fetch_assoc($oldURLs)) {
  $current_sitemap = $row['sitemap'];
  if ($prev_sitemap == $current_sitemap) {
    $ct++;
  } else {
    $ct = 1;
    $prev_filect = 1;
  }
  $filect = floor($ct/$maxLinks) + 1;

  $sitemap_file = '/var/sites/dev-maxim/docroot/sites/default/files/xmlsitemap/old/' . $current_sitemap .'-'. $filect . '.html';

  if (!file_exists($sitemap_file)) {
    array_push($arFiles, $sitemap_file);
    file_put_contents($sitemap_file, '<html><head><title></title><body>');
  }
  if ($prev_filect != $filect) {
    file_put_contents('/var/sites/dev-maxim/docroot/sites/default/files/xmlsitemap/old/' . $current_sitemap .'-'. $prev_filect . '.html', '<a href="/sites/default/files/xmlsitemap/old/' . $current_sitemap .'-'. $filect . '.html">More links</a>', FILE_APPEND);
  }

  file_put_contents($sitemap_file, '<a href="http://www.maxim.com' . $row['sourceurl'] . '">http://www.maxim.com' . $row['sourceurl'] . '</a><br />' . "\n", FILE_APPEND); 

  $prev_sitemap = $current_sitemap;
  $prev_filect = $filect;
}

// Close html in files
print_r($arFiles);
foreach ($arFiles as $sitemap_filename){
  echo $sitemap_filename;
  file_put_contents($sitemap_filename, '</body></html>', FILE_APPEND);
}

mysql_close($con);

?>
