<?php
 error_reporting(E_ALL);
ini_set('display_errors', '1'); 
set_time_limit(600);
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



// Include Drupal bootstrap
/*chdir($_SERVER['DOCUMENT_ROOT']);
define('DRUPAL_ROOT', getcwd());
require_once $_SERVER['DOCUMENT_ROOT'] . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

$platform = 'msn';
require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'brightcove_manager') . '/feed/videofeedapi.php');
$videoAPI = new VideoFeedAPI();
$data = array('statusmsg'=>'');

if (isset($_GET['cmd']) && strlen($_GET['cmd'])) {
  switch ($_GET['cmd']) {
  	case 'getvideos':
    	if (!isset($_GET['page'])) {
        $_GET['page'] = 0;
    	}
    	if (!isset($_GET['pagesize'])) {
        $_GET['pagesize'] = 50;
    	}
    	if (is_numeric($_GET['page']) && is_numeric($_GET['pagesize'])) {
        $data = $videoAPI->get_all_videos($_GET['page'], $_GET['pagesize'], 'http');
    	} else {
        $data['statusmsg'] = 'ERROR_UNKNOWN_REQUEST';
    	}
  	break;
	}
}*/

//header('Content-type: application/xml');
//print_r($data);

//echo $videoAPI->format_output($data, $show_status);
