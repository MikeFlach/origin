<?php
/* error_reporting(E_ALL);
ini_set('display_errors', '1'); */
set_time_limit(60);
header ("Content-Type:text/xml");

// Create a hash for simple security
// token = dde66dd3a24038987c29f6f38c9e596c
if (isset($_GET['token']) && $_GET['token'] == md5('maxim/msn_feed')) {

  // Include Drupal bootstrap
  chdir($_SERVER['DOCUMENT_ROOT']);
  define('DRUPAL_ROOT', getcwd());
  require_once $_SERVER['DOCUMENT_ROOT'] . '/includes/bootstrap.inc';
  drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

  $platform = 'msn';
  require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'brightcove_manager') . '/feed/msn.class.php');
  $msn = new msnClass();
  $xml = $msn->build_xml();
} else {
  $xml = '<error>Not authorized</error>';
}

echo $xml;
