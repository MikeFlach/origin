<?php

set_time_limit(600);
header ("Content-Type:text/xml");

// Create a hash for simple security
// token = ac5ab03e18d5e56eaed4c31803cbc63b
if (isset($_GET['token']) && $_GET['token'] == md5('maxim/sony_bivl_feed')) {

  // Include Drupal bootstrap
  chdir($_SERVER['DOCUMENT_ROOT']);
  define('DRUPAL_ROOT', getcwd());
  require_once $_SERVER['DOCUMENT_ROOT'] . '/includes/bootstrap.inc';
  drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

  $platform = 'sony_bivl';
  require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'brightcove_manager') . '/sony/sonybivl.class.php');

  if(isset($_GET['newData']) && $_GET['newData'] == 1){
    $sony = new SonyBIVL();
    $sony->build_ingest_XML();
    $xml = '<status>success</status>';
  } else {
    $feedFile = file_build_uri('feeds/sony_trebuchet_feed.xml');
    if (!file_exists($feedFile)){
      $sony = new SonyBIVL();
      $sony->build_ingest_XML();
    }
    $xml = file_get_contents($feedFile);
  }
} else {
  $xml = '<error>Not authorized</error>';
}
echo $xml;
