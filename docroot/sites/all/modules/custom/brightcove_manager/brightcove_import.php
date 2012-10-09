<?php

//Import videos from Drupal

error_reporting(E_ALL);
ini_set('display_errors', '1');

// Include Drupal bootstrap
chdir($_SERVER['DOCUMENT_ROOT']);
define('DRUPAL_ROOT', getcwd());
define('BC_READ_TOKEN', 'CX1YvsC6MvJ-6FddP41yjMQxH1sktJjDEH4QV0p-RQPZKyLwkfgCow..');
define('BC_URL', 'http://api.brightcove.com/services/library?');

require_once $_SERVER['DOCUMENT_ROOT'] . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_DATABASE);

$pages=5;
$pagesize=100;
$pagestart=5;

if (isset($_GET['pages'])) {
  $pages = $_GET['pages'];
}
if (isset($_GET['pagesize'])) {
  $pagesize = $_GET['pagesize'];
}
if (isset($_GET['pagestart'])) {
  $pagestart = $_GET['pagestart'];
}

if (isset($_GET['cmd'])) {
  $cmd = $_GET['cmd'];
} else {
  $cmd = 'insert';
}

switch ($cmd) {
  case 'update':
    if ($pagesize > 25) {
      $pagesize = 25;
    }
    update_modified_videos($pages, $pagesize, $pagestart);
  break;
  case 'insert':
    if ($pagesize > 100) {
      $pagesize = 100;
    }
    update_brightcove_data($pages, $pagesize, $pagestart);
  break;
}

function update_brightcove_data($pages=0, $pagesize=100, $startpage = 0) {
  $num_results = get_total_count();
  $pages = $startpage + $pages;

  if (($pages * $pagesize) + $pagesize > $num_results) {
    $pages = ceil($num_results/$pagesize) + 1;
  }
  for ($p=$startpage; $p < $pages; $p++) {
    echo 'Page: ' . $p . '<br>';
    get_brightcove_data($p, $pagesize);
    flush();
  }
}

function update_modified_videos($pages=0, $pagesize=25, $startpage = 0) {
  $last_updated_date = floor(get_last_updated_date()/60);

  $num_results = get_total_count($last_updated_date);
  $pages = $startpage + $pages;

  if (($pages * $pagesize) + $pagesize > $num_results) {
    $pages = ceil($num_results/$pagesize) + 1;
  }

  for ($p=$startpage; $p < $pages; $p++) {
    echo 'Page: ' . $p . '<br>';
    get_modified_videos($p, $pagesize, $last_updated_date);
    flush();
  }
}

function get_total_count($fromdate=NULL) {
  if (strlen($fromdate) > 0) {
    $params = array('video_fields' => 'id','get_item_count'=>'true', 'from_date'=>$fromdate);
    $params['filter'] = 'PLAYABLE,UNSCHEDULED,INACTIVE,DELETED';
    $cmd = 'find_modified_videos';
  } else {
    $params = array('video_fields' => 'id','get_item_count'=>'true');
    $cmd = 'find_all_videos';
  }
  $params['page_size'] = 1;
  $params['page_number'] = 0;
  $json = call_brightcove($cmd, $params);
  $results = json_decode($json);
  return $results->total_count;
}

function get_last_updated_date() {
  $last_date = 0;
  $video_last_update = db_query('select max(rawDataDate) as last_date from brightcove_manager_metadata');
  foreach ($video_last_update as $record) {
    $last_date = $record->last_date;
  }
  return $last_date;
}

function get_modified_videos($page=0, $pagesize=25, $fromdate=NULL) {
  $params = array('video_fields' => 'id,name,shortDescription,longDescription,creationDate,publishedDate,lastModifiedDate,startDate,endDate,linkURL,linkText,tags,videoStillURL,thumbnailURL,referenceId,length,economics,playsTotal,playsTrailingWeek,FLVURL,renditions,iOSRenditions,FLVFullLength,videoFullLength,customFields','get_item_count'=>'true');
  $params['page_size'] = $pagesize;
  $params['page_number'] = $page;
  $params['sort_by'] = 'MODIFIED_DATE';
  $params['sort_order'] = 'DESC';
  if (strlen($fromdate) > 0) {
    $params['from_date'] = $fromdate;
  }
  $params['filter'] = 'PLAYABLE,UNSCHEDULED,INACTIVE,DELETED';

  $results = new stdClass();
  $ct=0;
  // Make our API call
  do {
    if ($ct != 0) {
      sleep(10);
    }
    if ($ct < 10) {
      echo 'try ' . ++$ct . '<br>';
      $json = call_brightcove('find_modified_videos', $params);
      $results = json_decode($json);
    } else {
      echo 'Error with brightcove service';
      break;
    }
  } while (!isset($results->items));

  //print_r($results); die();
  if (isset($results->items) && count($results->items)) {
    foreach ($results->items as $item) {
      $do_update_db = 0;
      echo 'ID: ' . $item->id . ': ';

      // check to see if exists and last update date
      $video_last_update = db_select('brightcove_manager_metadata', 'v')
        ->fields('v', array('brightcoveID', 'rawDataDate'))
        ->condition('brightcoveID', $item->id)
        ->execute();

      $lastModifiedDate = convert_date($item->lastModifiedDate);

      if ($video_last_update->rowCount() > 0) {
        foreach ($video_last_update as $record) {
          $diff = $record->rawDataDate - $lastModifiedDate;
          if ($diff < 0) {
            // Update DB
            $do_update_db = 1;
          }
        }
      } else {
        $do_update_db = 1;
      }

      if ($do_update_db == 1) {
        echo 'dbupdate' . '<br>';
        if(isset($item->customFields->{'5min_id'})) {
          $fiveminID = $item->customFields->{'5min_id'};
        } else {
          $fiveminID = NULL;
        }
        $video_update = db_merge('brightcove_manager_metadata')
          ->key(array('brightcoveID' => $item->id))
          ->fields(array(
            'name' => $item->name,
            'shortDescription' => $item->shortDescription,
            'longDescription' => $item->longDescription,
            'creationDate' =>  convert_date($item->creationDate),
            'publishedDate' => convert_date($item->publishedDate),
            'lastModifiedDate' => convert_date($item->lastModifiedDate),
            'startDate' => convert_date($item->startDate),
            'endDate' => convert_date($item->endDate),
            'relatedLinkURL' => $item->linkURL,
            'relatedLinkText' => $item->linkText,
            'tags' =>implode(",", $item->tags),
            'videoStillURL' => $item->videoStillURL,
            'thumbnailURL' => $item->thumbnailURL,
            'referenceID' => $item->referenceId,
            'videoLength' => convert_int($item->length),
            'playsTotal' => convert_int($item->playsTotal),
            'playsTrailingWeek' => convert_int($item->playsTrailingWeek),
            'fiveminID' => $fiveminID,
            'referenceID' => $item->referenceId,
            'FLVURL' => $item->FLVURL,
            'renditions' => json_encode($item->renditions),
            'iosRenditions' => json_encode($item->IOSRenditions),
            'FLVFullLength' => json_encode($item->FLVFullLength),
            'videoFullLength' => json_encode($item->videoFullLength),
            'rawData' => json_encode($item),
            'rawDataDate' => strtotime('now'),
          ))
          ->execute();
      } else {
        echo 'No dbupdate' . '<br>';
      }
    }
  } else {
    // No items in results
  }
}

function get_brightcove_data($page=0, $pagesize=100) {
  $params = array('video_fields' => 'id,name,shortDescription,longDescription,creationDate,publishedDate,lastModifiedDate,startDate,endDate,linkURL,linkText,tags,videoStillURL,thumbnailURL,referenceId,length,economics,playsTotal,playsTrailingWeek,FLVURL,renditions,iOSRenditions,FLVFullLength,videoFullLength,customFields','get_item_count'=>'true');
  $params['page_size'] = $pagesize;
  $params['page_number'] = $page;
  $params['sort_by'] = 'MODIFIED_DATE';
  $params['sort_order'] = 'DESC';

  $results = new stdClass();
  $ct=0;
  // Make our API call
  do {
    if ($ct != 0) {
      sleep(10);
    }
    if ($ct < 10) {
      echo 'try ' . ++$ct . '<br>';
      $json = call_brightcove('find_all_videos', $params);
      $results = json_decode($json);
    } else {
      echo 'Error with brightcove service';
      break;
    }
  } while (!isset($results->items));

  //print_r($results); die();
  if (isset($results->items) && count($results->items)) {
    foreach ($results->items as $item) {
      $do_update_db = 0;
      echo 'ID: ' . $item->id . ': ';

      // check to see if exists and last update date
      $video_last_update = db_select('brightcove_manager_metadata', 'v')
        ->fields('v', array('brightcoveID', 'rawDataDate'))
        ->condition('brightcoveID', $item->id)
        ->execute();

      $lastModifiedDate = convert_date($item->lastModifiedDate);

      if ($video_last_update->rowCount() > 0) {
        foreach ($video_last_update as $record) {
          $diff = $record->rawDataDate - $lastModifiedDate;
          if ($diff < 0) {
            // Update DB
            $do_update_db = 1;
          }
        }
      } else {
        $do_update_db = 1;
      }

      if ($do_update_db == 1) {
        echo 'dbupdate' . '<br>';
        if(isset($item->customFields->{'5min_id'})) {
          $fiveminID = $item->customFields->{'5min_id'};
        } else {
          $fiveminID = NULL;
        }
        $video_update = db_merge('brightcove_manager_metadata')
          ->key(array('brightcoveID' => $item->id))
          ->fields(array(
            'name' => $item->name,
            'shortDescription' => $item->shortDescription,
            'longDescription' => $item->longDescription,
            'creationDate' =>  convert_date($item->creationDate),
            'publishedDate' => convert_date($item->publishedDate),
            'lastModifiedDate' => convert_date($item->lastModifiedDate),
            'startDate' => convert_date($item->startDate),
            'endDate' => convert_date($item->endDate),
            'relatedLinkURL' => $item->linkURL,
            'relatedLinkText' => $item->linkText,
            'tags' =>implode(",", $item->tags),
            'videoStillURL' => $item->videoStillURL,
            'thumbnailURL' => $item->thumbnailURL,
            'referenceID' => $item->referenceId,
            'videoLength' => convert_int($item->length),
            'playsTotal' => convert_int($item->playsTotal),
            'playsTrailingWeek' => convert_int($item->playsTrailingWeek),
            'fiveminID' => $fiveminID,
            'referenceID' => $item->referenceId,
            'FLVURL' => $item->FLVURL,
            'renditions' => json_encode($item->renditions),
            'iosRenditions' => json_encode($item->IOSRenditions),
            'FLVFullLength' => json_encode($item->FLVFullLength),
            'videoFullLength' => json_encode($item->videoFullLength),
            'rawData' => json_encode($item),
            'rawDataDate' => strtotime('now'),
          ))
          ->execute();
      } else {
        echo 'No dbupdate' . '<br>';
      }
    }
  } else {
    // No items in results
  }
}

function convert_date($unixtime) {
  if (is_numeric($unixtime)) {
    if ($unixtime > 2147483647) {
      $unixtime = $unixtime/1000;
    }
  } else {
    $unixtime = 0;
  }
  return $unixtime;
}

function convert_int($int) {
  if (!is_numeric($int)) {
    $int = 0;
  }
  return $int;
}

/**
 * Call brightcove API
 * @param  string  $command  Brightcove command
 * @param  array   $params   Brightcove parameters
 * @param  integer $usecache Use caceh (0/1)
 * @return array             Results from brightcove
 */
function call_brightcove($command, $params = array()){
  $bc_output = 'json';
  $results = array();
  $str_params = '';

  $params['media_delivery'] = 'http_ios';
  if (count($params) > 0) {
    foreach($params as $key=>$value) {
      $str_params .= "&$key=$value";
    }
  }

  //echo BC_URL . 'token=' . BC_READ_TOKEN . '&command=' . $command . '&output=' . $bc_output . $str_params; die();
  $results = file_get_contents(BC_URL . 'token=' . BC_READ_TOKEN . '&command=' . $command . '&output=' . $bc_output . $str_params);

  return $results;
}

