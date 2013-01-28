<?php

error_reporting(E_ALL);
ini_set('display_errors', '1');

include('freewheelapi.php');

if (isset($_GET['id']) && $_GET['id'] == FREEWHEEL_ID){
  // Include Drupal bootstrap
  FreewheelAPI::include_drupal_bootstap();
  $fwAPI = new FreewheelAPI();
  $fwAPI->process_bvi_xml();
} else {
  echo 'Invalid ID';
}
