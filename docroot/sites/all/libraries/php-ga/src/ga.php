<?php
/* Server-side Google Analytics */
require_once 'autoload.php';
use UnitedPrototype\GoogleAnalytics;

$response = array( 'errorcode'=>0, 'errormsg'=>'' );
$type = 'trackpageview';
$siteID = null;

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
  break;
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
    }
    // Assemble Session information
    // (could also get unserialized from PHP session)
    $session = new GoogleAnalytics\Session();
    if (isset($_GET['token']) && strlen($_GET['token']) > 0) {
      $strSession = preg_replace('[\D]', '', $_GET['token']); // session ID is an integer
      $strSession = intval(substr($strSession, 0, 8));
      $session->setSessionId($strSession);
      $visitor->setUniqueId($strSession);
    }
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
        $event->setLabel('page: ' . '/xbox/search/?q=' . $_GET['q']);
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
  }
}
echo json_encode($response);
