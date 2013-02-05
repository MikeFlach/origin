<?php

/**
 * Config file
 */
if (isset($_GET['env'])) {
  $env = $_GET['env'];
} else {
  $env = 'dev';
}

date_default_timezone_set('UTC');

define('FREEWHEEL_EMAIL', 'hwan@maxim.com');

switch ($env) {
  case 'dev':
    // Development
    define('FREEWHEEL_ID', 376288);
    define('FREEWHEEL_USER', 'BVI@Maxim_376288');
    define('FREEWHEEL_TOKEN', 'c4dfd44acf03');
    define('MAXIM_SERVER_CALLBACK', 'http://maximstg.prod.acquia-sites.com');
  break;
  case 'prod':
    // Production
    define('FREEWHEEL_ID', 376289);
    define('FREEWHEEL_USER', 'BVI@Maxim_376289');
    define('FREEWHEEL_TOKEN', 'add6bbddc116');
    define('MAXIM_SERVER_CALLBACK', 'http://www.maxim.com');
  break;
}
