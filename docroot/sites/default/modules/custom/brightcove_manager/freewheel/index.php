<?php

error_reporting(E_ALL);
ini_set('display_errors', '1');

// Include Drupal bootstrap
chdir($_SERVER['DOCUMENT_ROOT']);
define('DRUPAL_ROOT', getcwd());
require_once $_SERVER['DOCUMENT_ROOT'] . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

include('freewheelapi.php');

if (isset($_GET['id']) && defined('FREEWHEEL_ID')){
  if (isset($_GET['date'])) {
    $fromdate = $_GET['date'];
  } else {
    $fromdate = 'yesterday';
  }
  $fwAPI = new FreewheelAPI();
  $fwAPI->process_bvi_xml($fromdate);
} else {
  echo 'Invalid ID';
}
