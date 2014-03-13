<?php
/* error_reporting(E_ALL);
ini_set('display_errors', '1'); */
set_time_limit(60);
header ("Content-Type:text/xml");

// Create a hash for simple security
// token = e3de9f77ee9e8b72a0928bbcb3777952
if (isset($_GET['token']) && $_GET['token'] == md5('maxim/ndn_feed')) {

  // Include Drupal bootstrap
  chdir($_SERVER['DOCUMENT_ROOT']);
  define('DRUPAL_ROOT', getcwd());
  require_once $_SERVER['DOCUMENT_ROOT'] . '/includes/bootstrap.inc';
  drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

  $platform = 'ndn';
  require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'brightcove_manager') . '/feed/mrss.class.php');
  $mrss = new mrssClass();
  $xml = $mrss->build_xml();
} else {
  $xml = '<error>Not authorized</error>';
}

echo $xml;
