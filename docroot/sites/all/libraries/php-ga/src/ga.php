<?php
/* Server-side Google Analytics */
require_once 'autoload.php';
use UnitedPrototype\GoogleAnalytics;

$response = array( 'errorcode'=>0, 'errormsg'=>'' );
$type = 'trackpageview';
$siteID = null;
$call_comscore = 0;

if (!isset($_GET['site'])){
  $response['errorcode'] = 1;
  $response['errormsg'] = 'No site defined.';
}

if (isset($_GET['type'])) {
  $type = $_GET['type'];
}

if ($response['errorcode'] != 0){
  echo json_encode($response);
  die();
}

switch ($_GET['site']){
  case 'xbox':
    $siteID = 'UA-4245914-1';
    $siteDomain = 'xbox.maxim.com';
    $call_comscore = 1;
  break;
  case 'playstation':
    $siteID = 'UA-4245914-1';
    $siteDomain = 'playstation.maxim.com';
  break;
  case 'blackberry':
    $siteID = 'UA-4245914-1';
    $siteDomain = 'blackberry.maxim.com';
  break;
}

if (isset($_GET['uid']) && is_numeric($_GET['uid'])) {
  if ($_GET['uid'] < 0x7fffffff) {
    $uid = $_GET['uid'];
  } else {
    $uid = substr($_GET['uid'], -8);
  }
} else {
  $uid = rand(100000, 200000000);
}

if (strlen($siteID) > 0) {
  try {
    // Initilize GA Tracker
    $tracker = new GoogleAnalytics\Tracker($siteID, $siteDomain);
    // Assemble Visitor information
    // (could also get unserialized from database)
    $visitor = new GoogleAnalytics\Visitor();
    if (isset($_GET['device']) && strlen($_GET['device']) > 0) {
      $visitor->setUserAgent($_GET['device']);
    } else {
      $visitor->setUserAgent($uid);
    }
    // Assemble Session information
    // (could also get unserialized from PHP session)
    $session = new GoogleAnalytics\Session();
    $strSession = $uid;
    $session->setSessionId($strSession);
    $visitor->setUniqueId($strSession);
  } catch (Exception $e) {
    $response['errorcode'] = 10;
    $response['errormsg'] = $e->getMessage();
    echo json_encode($response);
    die();
  }

  switch ($type) {
    case 'trackpageview':
      if (!isset($_GET['page'])) {
        $response['errorcode'] = 2;
        $response['errormsg'] = 'No page defined.';
        echo json_encode($response);
        die();
      }
      // Assemble Page information
      $page = new GoogleAnalytics\Page($_GET['page']);

      // Track page view
      $tracker->trackPageview($page,$session,$visitor);
      $response['errormsg'] = 'Success.';

      if ($call_comscore == 1) {
        include('comscore.php');
        comscore_beacon($siteDomain, $_GET['page'], $_GET['page']);
      }
    break;
    case 'tracksearch':
      if (!isset($_GET['q'])) {
        $response['errorcode'] = 3;
        $response['errormsg'] = 'No term defined.';
        echo json_encode($response);
        die();
      }
      // Assemble Page information
      $page = new GoogleAnalytics\Page('/xbox/search/?q=' . $_GET['q']);
      // Track User events
      if (isset($_GET['email']) && strlen($_GET['email']) > 0) {
        $event = new GoogleAnalytics\Event();
        $event->setCategory('userEvents');
        $event->setAction('user: ' . $_GET['email']);
        $event->setLabel('page: ' . '/' . $_GET['site'] . '/search/?q=' . $_GET['q']);
        $tracker->trackEvent($event, $session, $visitor);
      }

      // Track page view
      $tracker->trackPageview($page,$session,$visitor);
      $response['errormsg'] = 'Success.';
    break;
    case 'trackevent':
      $event = new GoogleAnalytics\Event();
      $arEvent = array();
      if (isset($_GET['category']) && strlen($_GET['category']) > 0){
        $event->setCategory($_GET['category']);
        array_push($arEvent, $_GET['category']);
      } else {
        $response['errorcode'] = 4;
        $response['errormsg'] = 'No category defined.';
        echo json_encode($response);
        die();
      }
      if (isset($_GET['action']) && strlen($_GET['action']) > 0){
        $event->setAction($_GET['action']);
        array_push($arEvent, $_GET['action']);
      }
      if (isset($_GET['label']) && strlen($_GET['label']) > 0){
        $event->setLabel($_GET['label']);
        array_push($arEvent, $_GET['label']);
      }
      if (isset($_GET['value']) && strlen($_GET['value']) > 0){
        $event->setValue($_GET['value']);
        array_push($arEvent, $_GET['value']);
      }
      $tracker->trackEvent($event, $session, $visitor);
      $response['errormsg'] = 'Success.';
    break;
    case 'tracksocial':
      $social = new GoogleAnalytics\SocialInteraction();
      if (isset($_GET['network']) && strlen($_GET['network']) > 0){
        $social->setNetwork($_GET['network']);
      } else {
        $response['errorcode'] = 5;
        $response['errormsg'] = 'No network defined.';
        echo json_encode($response);
        die();
      }
      if (isset($_GET['action']) && strlen($_GET['action']) > 0){
        $social->setAction($_GET['action']);
      } else {
        $response['errorcode'] = 6;
        $response['errormsg'] = 'No action defined.';
        echo json_encode($response);
        die();
      }
      if (isset($_GET['target']) && strlen($_GET['target']) > 0){
        $social->setTarget($_GET['target']);
      } else {
        $response['errorcode'] = 7;
        $response['errormsg'] = 'No page defined.';
        echo json_encode($response);
        die();
      }
      if (isset($_GET['page']) && strlen($_GET['page']) > 0){
        $page = $_GET['page'];
        if ($_GET['site'] == 'xbox' && strpos($page, '/xbox/') === FALSE) {
          $page = '/xbox/' . $page;
        }
      } else {
        $page = '';
      }
      $pageTracker = new GoogleAnalytics\Page($page);
      $tracker->trackSocial($social, $pageTracker, $session, $visitor);
      $response['errormsg'] = 'Success.';
    break;
  }
}
echo json_encode($response);
