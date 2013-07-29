<?php

// Include Drupal bootstrap
chdir($_SERVER['DOCUMENT_ROOT']);
define('DRUPAL_ROOT', getcwd());
require_once $_SERVER['DOCUMENT_ROOT'] . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

//add_video_to_slideshow(54636, '2551521640001');

// file name
$file = 'hotties-2014-semifinalists.csv';
if (isset($_GET['file'])) {
  $file = $_GET['file'];
}

$start = 1;
if (isset($_GET['start'])) {
  $start = $_GET['start'];
}

$num = 5;
if (isset($_GET['num'])) {
  $num = $_GET['num'];
}

$type = 'video';
if (isset($_GET['type'])) {
  $type = $_GET['type'];
}

$csv = readCSV($file);
if ($csv != FALSE) {
  switch ($type) {
    case 'video':
      parse_and_add_video($csv, $start, $num);
    break;
    case 'status':
      add_semifinal_status($csv, $start, $num);
      echo '<br />Done';
    break;
  }
}

function parse_and_add_video($csv, $start, $num) {
  $end = $start + $num;
  for ($i=$start; $i < $end; $i++) {
    if (count($csv[$i]) == 4) {
      echo $i . '. ' .  $csv[$i][1] . ': ' . $csv[$i][2] . ':' . $csv[$i][3];
      if (strlen($csv[$i][2]) && strlen($csv[$i][3])) {
        add_video_to_slideshow($csv[$i][2], $csv[$i][3]);
        echo ' video: ' . $csv[$i][3];
      }
      echo '<br />';
      flush();
    }
  }
}

/**
 * CSV file format: nid, title, slideshow_nid, brightcove_id
 * @param  string $csvFile CSV file location
 * @return [type]          [description]
 */
function readCSV($csvFile){
  $fileLocation = $_SERVER['DOCUMENT_ROOT'] . '/sites/default/files/private-files/';
  if (file_exists($fileLocation . $csvFile)) {
    $file_handle = fopen($fileLocation . $csvFile, 'r');
    while (!feof($file_handle) ) {
      $line_of_text[] = fgetcsv($file_handle, 1024);
    }
    fclose($file_handle);
    return $line_of_text;
  } else {
    echo 'File does not exist';
    return FALSE;
  }
}

function add_video_to_slideshow($nid, $brightcove_id, $position = 'first') {
  // Load the node by nid
  $node = node_load($nid);
  // get fid for brightcove
  $brightcove_fid = get_fid($brightcove_id);

  // Check to see if the video exists in slideshow already
  $node_wrapper = entity_metadata_wrapper('node', $nid);
  foreach ($node_wrapper->field_slides_wrapper->value() as $entity) {
    if ($entity->field_slides[LANGUAGE_NONE][0]['fid'] == $brightcove_fid) {
      echo ' already exists';
      return;
    }
  }

  // Add field collection
  add_field_collection($node, 'node', 'field_slides_wrapper', array(
    'field_slide_title' => '',
    'field_slides' => array(
        'fid' => $brightcove_fid,
        'display' => '1',
      ),
  ));

  if ($position == 'first') {
    reorder_slides($nid);
  }
}

function add_semifinal_status($csv, $start, $num) {
  $week_semi = taxonomy_get_term_by_name('Semifinalist', 'hotties_contest_week');
  $status_semi = taxonomy_get_term_by_name('Semifinalist', 'hotties_contest_status');
  $week_tid = key($week_semi);
  $status_tid = key($status_semi);
  echo 'Add Semifinalist status' . '<br />';
  $end = $start + $num;
  for ($a=$start; $a < $end; $a++) {
    $nid = $csv[$a][0];
    echo $a . ': ' . $nid . '<br>';
    $node = node_load($nid);
    $week_exists = 0;
    $status_exists = 0;

    if ($node !== FALSE) {
      for ($i = 0; $i < count($node->field_hotties_contest_week[LANGUAGE_NONE]); $i++) {
        if ($node->field_hotties_contest_week[LANGUAGE_NONE][$i]['tid'] == strval($week_tid)) {
          $week_exists = 1;
          echo 'week exists ';
          break;
        }
      }
      for ($i = 0; $i < count($node->field_hotties_contest_status[LANGUAGE_NONE]); $i++) {
        if ($node->field_hotties_contest_status[LANGUAGE_NONE][$i]['tid'] == strval($status_tid)) {
          $status_exists = 1;
          echo 'status exists ';
          break;
        }
      }
      if ($week_exists == 0) {
        array_push($node->field_hotties_contest_week[LANGUAGE_NONE], array("tid" => strval($week_tid)));
      }
      if ($status_exists == 0) {
        array_push($node->field_hotties_contest_status[LANGUAGE_NONE],  array("tid" => strval($status_tid)));
      }

      if ($week_exists == 0 || $status_exists == 0) {
        $node->revision = 1;
        $node->log = t('Set hottie to Semifinalist');
        echo 'save';
        node_save($node);
      } else {
        echo 'no save';
      }
      echo '<br>';
    }
  }
}

function reorder_slides($nid) {
  // Reload node
  $node = node_load($nid);
  if ($node !== FALSE) {
    $slide_wrapper = $node->field_slides_wrapper[LANGUAGE_NONE];
    array_unshift($slide_wrapper, array_pop($slide_wrapper));
    $node->field_slides_wrapper[LANGUAGE_NONE] = $slide_wrapper;
    node_save($node);
  }
}

function add_field_collection($parent, $type, $collection_name, $values) {
  // Create entity using the entity name and set the parent.
  $field_collection_item = entity_create('field_collection_item', array('field_name' => $collection_name));
  $field_collection_item->setHostEntity($type, $parent);

  // EMW makes it easier for us to work with the field_collection
  $field_collection_item_w = entity_metadata_wrapper('field_collection_item', $field_collection_item);

  // Add the fields to the entity.
  foreach($values as $key => $value) {
    $field_collection_item_w->{$key}->set($value);
  }

  // Save the entity.
  try{
    $field_collection_item_w->save();
  } catch (Exception $e) {
    print_r($e);
  }

  return $field_collection_item;
}

function get_fid($brightcove_id) {
  $video_url = 'brightcove://' . $brightcove_id;

  // Check to see if brightcove video exists in CMS
  $files = entity_load('file', FALSE, array('uri' => $video_url));

  if (empty($files)) {
    // Get file object
    $bc_file_obj = brightcove_media_file_uri_to_object($video_url);
    // Save file to drupal
    $files = file_save($bc_file_obj);
    // Get new fid
    $fid = $files->fid;
  } else {
    // Get existing fid
    $fid = reset($files)->fid;
  }

  return $fid;
}
