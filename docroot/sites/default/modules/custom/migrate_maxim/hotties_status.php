<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');
set_time_limit(500);

// Include Drupal bootstrap
chdir($_SERVER['DOCUMENT_ROOT']);
define('DRUPAL_ROOT', getcwd());
require_once $_SERVER['DOCUMENT_ROOT'] . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

$status_contestant = array_keys(taxonomy_get_term_by_name('Contestant', 'hotties_contest_status'));
$status_semifinalist = array_keys(taxonomy_get_term_by_name('Semifinalist', 'hotties_contest_status'));
$status_finalist = array_keys(taxonomy_get_term_by_name('Finalist', 'hotties_contest_status'));

$week_semifinalist = array_keys(taxonomy_get_term_by_name('Semifinalist', 'hotties_contest_week'));
$week_finalist = array_keys(taxonomy_get_term_by_name('Finalists', 'hotties_contest_week'));

DEFINE ('STATUS_CONTESTANT_TID', strval($status_contestant[0]));
DEFINE ('STATUS_SEMIFINALIST_TID', strval($status_semifinalist[0]));
DEFINE ('STATUS_FINALIST_TID', strval($status_finalist[0]));
DEFINE ('WEEK_SEMIFINALIST_TID', strval($week_semifinalist[0]));
DEFINE ('WEEK_FINALIST_TID', strval($week_finalist[0]));

$block = 0;
$start = 0;
$blocksize = 500;
$type='all';

if (isset($_GET['type'])) {
  $type = $_GET['type'];
}

if (isset($_GET['block']) && is_numeric($_GET['block'])) {
  $block = $_GET['block'];
}
if (isset($_GET['blocksize']) && is_numeric($_GET['blocksize'])) {
  $blocksize = $_GET['blocksize'];
}

switch($type) {
  case 'semis': {
    update_all_semifinalists($start, $blocksize);
    break;
  }
  case 'finals': {
    update_all_finalists($start, $blocksize);
    break;
  }
  case 'all': {
    update_all_hotties($start, $blocksize);
    break;
  }
}

if ($block > 0) {
  $start = $block * $blocksize;
}

function update_all_hotties($start = 0, $blocksize = 100) {
  // Get the numeric id of your field by passing field name
  $contest_status_info = field_info_field('field_hotties_contest_status');
  $contest_status_fields = array($contest_status_info['id']);

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'hotties_profile')
  ->range($start, $blocksize);

  $result = $query->execute();
  $nids = array_keys($result['node']);

  echo '<strong>Number returned: ' . count($nids) . '</strong><br>';
  foreach ($nids as $nid) {
    insert_contest_status($nid, STATUS_CONTESTANT_TID, $contest_status_fields);
  }
}

function update_all_semifinalists($start = 0, $blocksize = 100) {
  // Get the numeric id of your field by passing field name
  $contest_week_info = field_info_field('field_hotties_contest_week');
  $contest_week_fields = array($contest_week_info['id']);

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'hotties_profile')
  ->fieldCondition('field_hotties_contest_status', 'tid', STATUS_SEMIFINALIST_TID)
  ->range($start, $blocksize);

  $result = $query->execute();
  $nids = array_keys($result['node']);

  echo '<strong>Number returned: ' . count($nids) . '</strong><br>';
  foreach ($nids as $nid) {
    insert_contest_week($nid, WEEK_SEMIFINALIST_TID, $contest_week_fields);
  }
}

function update_all_finalists($start = 0, $blocksize = 100) {
  // Get the numeric id of your field by passing field name
  $contest_status_info = field_info_field('field_hotties_contest_status');
  $contest_status_fields = array($contest_status_info['id']);
  $contest_week_info = field_info_field('field_hotties_contest_week');
  $contest_week_fields = array($contest_week_info['id']);

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'hotties_profile')
  ->fieldCondition('field_hotties_contest_status', 'tid', STATUS_FINALIST_TID)
  ->range($start, $blocksize);

  $result = $query->execute();
  $nids = array_keys($result['node']);
  echo '<strong>Number returned: ' . count($nids) . '</strong><br>';

  foreach ($nids as $nid) {
    insert_contest_week($nid, WEEK_SEMIFINALIST_TID, $contest_week_fields);
    insert_contest_week($nid, WEEK_FINALIST_TID, $contest_week_fields);
    insert_contest_status($nid, STATUS_SEMIFINALIST_TID, $contest_status_fields);
  }
}

//insert_contest_week(33251, WEEK_FINALIST_TID);

function insert_contest_status($nid, $status, $contest_status_fields) {
  $node = node_load($nid);
  $term_exists = 0;
  echo '<br>Contest Status: ' .$nid;

  foreach($node->field_hotties_contest_status[$node->language] as $term) {
    if ($term['tid'] == $status) {
      $term_exists = 1;
      echo ': term exists';
      break;
    }
  }

  if ($term_exists == 0) {
    $node->field_hotties_contest_status[$node->language][] = array('tid' => $status);
    // Execute the storage function
    field_sql_storage_field_storage_write('node', $node, 'update', $contest_status_fields);
  }
}

function insert_contest_week($nid, $week, $contest_week_fields) {
  $node = node_load($nid);
  $term_exists = 0;
  echo '<br>Contest Week: ' .$nid;

  foreach($node->field_hotties_contest_week[$node->language] as $term) {
    if ($term['tid'] == $week) {
      $term_exists = 1;
      echo ': term exists';
      break;
    }
  }

  if ($term_exists == 0) {
    $node->field_hotties_contest_week[$node->language][] = array('tid' => $week);

    // Execute the storage function
    field_sql_storage_field_storage_write('node', $node, 'update', $contest_week_fields);
  }
}

// Clear field cache
//drupal_flush_all_caches();
