<?php

error_reporting(E_ALL);
ini_set('display_errors', '1');

// Include Drupal bootstrap
chdir($_SERVER['DOCUMENT_ROOT']);
define('DRUPAL_ROOT', getcwd());
require_once $_SERVER['DOCUMENT_ROOT'] . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

getImageCrops();

function getImageCrops(){
  $docroot = $_SERVER['DOCUMENT_ROOT'];

  $query = 'SELECT i.fid, style_name, xoffset, yoffset, width, height, scale, uri FROM image_crop_settings i left join file_managed f on i.fid=f.fid';

  $result = db_query($query);

  foreach ($result as $row) {
    $fileLocation = str_replace('public://', $docroot . '/sites/default/files/', $row->uri);
    
    if (file_exists($fileLocation)) {
      list($origwidth, $origheight) = getimagesize($fileLocation);
      echo '<br />fid: ' . $row->fid . ', loc: ' . $fileLocation;
      if ($row->scale == 'original') {
        $ratio = 1;
      } else {
        $ratio = $row->scale/$origwidth;
      }
      echo ' ratio is ' . $ratio;
      if ($ratio > 0) {
        $newWidth = round($row->width/$ratio);
        $newHeight = round($row->height/$ratio);
        $newXoffset = round($row->xoffset/$ratio);
        $newYoffset = round($row->yoffset/$ratio);
        echo $row->width . 'x' .  $row->height . ':' .  $row->xoffset . ',' . $row->yoffset . ' => ' .
          $newWidth . 'x' .  $newHeight . ':' .  $newXoffset . ',' . $newYoffset;
        $repQuer = "REPLACE manualcrop(fid, style_name, x, y, width, height) VALUES (" . $row->fid . ", '" . $row->style_name . "', '" . $newXoffset . "', '" . $newYoffset . "', '" . $newWidth . "', '" . $newHeight . "')";
        $rep_result = db_query($repQuery);
      }
    }
  }
}
