<?php

// Include Drupal bootstrap
chdir($_SERVER['DOCUMENT_ROOT']);
define('DRUPAL_ROOT', getcwd());
require_once $_SERVER['DOCUMENT_ROOT'] . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

//add_video_to_slideshow(54636, '2551521640001');

$file = 'hotties-2014-semifinalists.csv';
if (isset($_GET['file'])) {
  $file = $_GET['file'];
}

$csv = readCSV($file);
if ($csv != FALSE) {
  parse_and_add_video($csv);
}

function parse_and_add_video($csv) {
  for ($i=1; $i < count($csv); $i++) {
    if (count($csv[$i]) == 4) {
      echo $i . '. ' .  $csv[$i][1] . ': ' . $csv[$i][2];
      if (strlen($csv[$i][2]) && strlen($csv[$i][3])) {
        add_video_to_slideshow($csv[$i][2], $csv[$i][3]);
        echo ' video: ' . $csv[$i][3];
      }
      echo '<br />';
    }
  }
}

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
    if ($entity->field_slides[LANGUAGE_NONE][0]['filename'] == $brightcove_id) {
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

function reorder_slides($nid) {
  // Reload node
  $node = node_load($nid);
  $slide_wrapper = $node->field_slides_wrapper[LANGUAGE_NONE];
  array_unshift($slide_wrapper, array_pop($slide_wrapper));

  $node->field_slides_wrapper[LANGUAGE_NONE] = $slide_wrapper;
  node_save($node);
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
