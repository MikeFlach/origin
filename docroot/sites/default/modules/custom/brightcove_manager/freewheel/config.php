<?php

/**
 * Config file
 */
date_default_timezone_set('UTC');

// If from command line, determine environment
// Otherwise make sure the ID matches
if (PHP_SAPI === 'cli') {
  if ($_ENV['AH_SITE_ENVIRONMENT'] == 'prod') {
    $freewheel_id = 376289;
  } else {
    $freewheel_id = 376288;
  }
} else {
  if (isset($_GET['id'])) {
    $freewheel_id = $_GET['id'];
  } else {
    $freewheel_id = 0;
  }
}

define('FREEWHEEL_EMAIL', 'hwan@maxim.com');

switch ($freewheel_id) {
  case '376288':
    // Development
    define('FREEWHEEL_ENV', 'dev');
    define('FREEWHEEL_ID', 376288);
    define('FREEWHEEL_USER', 'BVI@Maxim_376288');
    define('FREEWHEEL_TOKEN', 'c4dfd44acf03');
    define('MAXIM_SERVER_CALLBACK', 'http://maximstg.prod.acquia-sites.com');
  break;
  case '376289':
    // Production
    define('FREEWHEEL_ENV', 'prod');
    define('FREEWHEEL_ID', 376289);
    define('FREEWHEEL_USER', 'BVI@Maxim_376289');
    define('FREEWHEEL_TOKEN', 'add6bbddc116');
    define('MAXIM_SERVER_CALLBACK', 'http://www.maxim.com');
  break;
}

