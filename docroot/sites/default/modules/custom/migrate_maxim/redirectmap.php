<?php


error_reporting(E_ALL);
ini_set('display_errors', '1');

// Include Drupal bootstrap
chdir($_SERVER['DOCUMENT_ROOT']);
define('DRUPAL_ROOT', getcwd());
require_once $_SERVER['DOCUMENT_ROOT'] . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

//convertTitlesToURLs();

insertRedirect3();

function insertRedirect(){

  //db_query("DELETE FROM redirect");
  //
  $qry = "select * from old_sitemap s left join vgn_redirect r on s.sourceurl = concat('/amg', r.source_url) where entity_id is not null order by r.drupal_url asc";
  $result = db_query($qry);

  $ct =0;
  foreach($result as $row){
    $sURL = substr($row->sourceurl, 1);
    //$sURL = str_replace('+', ' ', $sURL);
    $sURL = urldecode($sURL);
    echo ++$ct . '. ' . redirect2_hash($sURL) . ':' . $sURL;
    $rid = db_merge('redirect2')
      ->key(array('source'=>$sURL))
      ->fields(array(
        'hash' => redirect2_hash($sURL),
        'type' => 'redirect',
        'source' => $sURL,
        'source_options' => 'a:0:{}',
        'redirect' => $row->drupal_url,
        'redirect_options' => 'a:0:{}',
        'status_code' => 0,
      ))
      ->execute()
    ;
    echo ': ' .$rid . '<br>';
  }
}

/*
 * Insert the rest into redirect3 table with no target URL
 *
 */

function insertRedirect2(){
  $qry = "select * from old_sitemap s where matched = 0";
  $result = db_query($qry);

  $ct =0;
  foreach($result as $row){
    $sURL = substr($row->sourceurl, 1);
    $sURL = urldecode($sURL);
    echo ++$ct . '. ' . redirect2_hash($sURL) . ':' . $sURL;
    $rid = db_merge('redirect3')
      ->key(array('source'=>$sURL))
      ->fields(array(
        'hash' => redirect2_hash($sURL),
        'type' => 'redirect',
        'source' => $sURL,
        'source_options' => 'a:0:{}',
        'redirect' => '',
        'redirect_options' => 'a:0:{}',
        'status_code' => 0,
      ))
      ->execute()
    ;
    echo ': ' .$rid . '<br>';
  }
}

/*
 * Do search on possible urls in redirect3 table
 *
 */

function insertRedirect3(){

  $qry = "select * from redirect3 where redirect = ''";
  $result = db_query($qry);

  $ct =0;
  foreach($result as $row){
    $sURL = $row->source;
    $sURL = str_replace('amg/', '', $sURL);
    $sURL = str_replace('+', '-', $sURL);
    $sURL = str_replace(' ', '-', $sURL);
    $sURL = str_replace("'", '', $sURL);
    $sURL = urldecode($sURL);
    echo $sURL; die();
    echo ++$ct . '. ' . redirect2_hash($sURL) . ':' . $sURL;
    $rid = db_merge('redirect3')
      ->key(array('source'=>$sURL))
      ->fields(array(
        'hash' => redirect2_hash($sURL),
        'type' => 'redirect',
        'source' => $sURL,
        'source_options' => 'a:0:{}',
        'redirect' => '',
        'redirect_options' => 'a:0:{}',
        'status_code' => 0,
      ))
      ->execute()
    ;
    echo ': ' .$rid . '<br>';
  }
}


function redirect2_hash($source){
  $hash = array(
    'source' => $source,
    'language' =>'und'
  );
  redirect_sort_recursive($hash, 'ksort');
  return drupal_hash_base64(serialize($hash));
}
/*
function redirect_sort_recursive(&$array, $callback = 'sort'){
  $result = $callback($array);
  foreach ($array as $key => $value){
    if (is_array($value)){
      $result &= redirect_sort_recursive($array[$key], $callback);
    }
  }
  return $result;
}

function drupal_hash_base64($data){
  $hash = base64_encode(hash('sha256', $data, TRUE));
  return strtr($hash, array('+' => '-', '/' => '_', '=' => ''));
}*/


function convertTitlesToURLs(){
  $con = mysql_connect("localhost","maximdev","maxim");
  if (!$con) { die('Could not connect: ' . mysql_error()); }

  mysql_select_db("maximdev", $con);
  $result = mysql_query("SELECT * FROM vgn_redirect where target_url is null and title_from_url is not null order by source_url asc");

  // Loop thru each redirect and search by title
  $ct1=0;
  while($row = mysql_fetch_array($result)){
    $ct1++;
    echo $ct1 . '. ' . cleanString($row['title_from_url']) . '<br>';
    $titleResults = mysql_query("select n.type, n.nid, n.title, u.alias, u.source from node n
      left join url_alias u on u.source = concat('node/', n.nid)
      where n.title='" . mysql_real_escape_string($row['title_from_url']) . "' order by n.nid asc");
      //  n.nid not in (select entity_id from vgn_redirect where entity_id is not null) and

    $numResults = mysql_num_rows($titleResults);
    $ct=0;
    if($numResults > 0){
      while($trow = mysql_fetch_array($titleResults)){
        $ct++;
        if($ct == 1){
          echo $row['id'] . ': ' . $row['source_url']  . ' : ' .  $trow['alias'] . '<br />';
          mysql_query("UPDATE vgn_redirect set
            entity_type='node',
            bundle='" . $trow['type'] .  "',
            entity_id='" . $trow['nid'] .  "',
            drupal_url='" . mysql_real_escape_string($trow['source']) . "',
            target_url='" . mysql_real_escape_string($trow['alias']) . "'
            where id = '" . $row['id'] . "'"
          );
        }
      }
    }
  }

  mysql_close($con);
}

/*
 * Clean Strings (remove special characters)
 */
function cleanString($str){
  return preg_replace('/[^a-zA-Z0-9_ -]/s', '', $str);
}


/*
 * Write redirect map to file
 */
function writeMapToFile(){
  $file = '/var/sites/dev-maxim/rewritemap_maxim.txt';
  $fp = fopen($file, 'w');

  $con = mysql_connect("localhost","maximdev","maxim");
  if (!$con) { die('Could not connect: ' . mysql_error()); }

  mysql_select_db("maximdev", $con);

  $result = mysql_query("SELECT * FROM vgn_redirect order by source_url asc");

  // Loop thru each redirect and write to file
  while($row = mysql_fetch_array($result)){
    if(strlen($row['target_url'])){
      echo substr($row['source_url'], 1 ) . ' ' . $row['target_url'] . "<br>";
      fwrite($fp, substr($row['source_url'], 1 ) . ' ' . $row['target_url'] . "\n");
    }
  }

  fclose($fp);
  mysql_close($con);
}

function getTitleFromUrl(){
  $con = mysql_connect("localhost","maximdev","maxim");
  if (!$con) { die('Could not connect: ' . mysql_error()); }

  mysql_select_db("maximdev", $con);

  $result = mysql_query("SELECT * FROM vgn_redirect where target_url is null and title_from_url is null order by source_url asc");

  // Loop thru each redirect and write to file
  while($row = mysql_fetch_array($result)){
    $title = getTitle($row['source_url']);
    if(strlen($title)){
      echo $row['id'] . ': ' . $row['source_url']  . ' : ' .  mysql_real_escape_string($title) . '<br />';
      mysql_query("UPDATE vgn_redirect set title_from_url='" . mysql_real_escape_string($title) . "' WHERE id=" . $row['id']);
    }
  }

  mysql_close($con);
}


function getTitle($url){
  $str='';
  $aURL = explode('/',$url);
  if(count($aURL) >= 3){
    $title = array_pop($aURL);
    $str=urldecode($title);
  }

  return $str;
}

function parseSitemap(){
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
    mysql_query("CREATE TABLE IF NOT EXISTS `vgn_sitemap` (
     `sm_id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
     `sourceurl` VARCHAR(255) NOT NULL DEFAULT '',
     `targeturl` VARCHAR(255) NOT NULL DEFAULT ''
    );");
    foreach($smXML as $sm){
      $ct++;
      $smURL = str_replace('http://www.maxim.com/amg','', $sm->loc);
      echo $ct . '. ' . $smURL . '<br/>';

      mysql_query("INSERT IGNORE INTO vgn_sitemap (sourceurl) VALUES ('$smURL')");
    }
    gzclose($smFile);
  }

  mysql_close($con);
}
