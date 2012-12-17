<?php
/**
 * Cache Brightcove API calls
 * @return int count
 */
function brightcove_manager_update_api_cache() {
  $data = array('num_updated' => 0, 'msg' =>'');
  $bc = brightcove_initialize();
  $bc_read_token = $bc->token_read;
  $bc_url = 'http://api.brightcove.com/services/library?';
  $cache = db_select('cache_brightcove', 'c')
    ->fields('c', array('cid', ))
    ->orderBy('cid', 'ASC')
    ->execute();
  $ct = 0;
  foreach ($cache as $record) {
    $ct++;
    $cache_id = $record->cid;
    //echo $bc_url . 'token=' . $bc_read_token . '&' . $cache_id . "\n";
    echo $ct . ': '. $bc_url . 'token=' . $bc_read_token . '&' . $cache_id . "\n\n";
    $results = file_get_contents($bc_url . 'token=' . $bc_read_token . '&' . $cache_id);
    // If no error, cache results
    if (strpos($results, '"error"') === false) {
      _brightcove_manager_cache_api_results($cache_id, $results);
    } else {
      $data['msg'] .= "\n" . 'Error with #' . $ct . ' api call' ;
    }
  }

  $data['num_updated'] = $ct;
  return $data;
}

/**
 * Brightcove update video and image assets
 * @return array number_updated
 */
function brightcove_manager_update_assets() {
  $data = array('num_updated' => 0, 'msg' =>'');
  $params = array('video_fields' => 'id,videoStillURL,thumbnailURL,FLVURL','get_item_count'=>'true');
  $videos = db_select('brightcove_manager_metadata', 'b')
    ->fields('b', array('brightcove_id'))
    ->condition('active', 1)
    ->condition('deleted', 0)
    ->execute();

  $videoIDs = array();
  $ct = 0;
  foreach ($videos as $video) {
    // Get every 50 IDs and make brightcove API call
    if ($ct++ < 50) {
      array_push($videoIDs, $video->brightcove_id);
    } else {
      $update_count = _brightcove_manager_get_assets_by_ids($videoIDs);
      $data['num_updated'] += $update_count;
      echo 'Total updated: ' . $data['num_updated'] . "\n";
      $videoIDs = array();
      $ct = 0;
    }
  }
  return $data;
}

/**
 * Update all video metadata
 * @return void
 */
function brightcove_manager_update_metadata($date, $override) {
  _brightcove_manager_update_modified_videos($date, 'INACTIVE', $override);
  _brightcove_manager_update_modified_videos($date, 'DELETED', $override);
  _brightcove_manager_update_modified_videos($date, 'PLAYABLE,UNSCHEDULED', $override);
}

/**
 * Update modified videos
 * @param  string $date='yesterday' since this date
 * @param  string $filter           video filter
 */
function _brightcove_manager_update_modified_videos($date='yesterday', $filter = '', $override = FALSE) {
  $pagesize = 25;
  $pages = 1000;
  $startpage = 0;
  $last_updated_date = _brightcove_manager_last_updated($date);
  $num_results = _brightcove_manager_get_total_count($last_updated_date, $filter);

  if ($num_results > 0) {
    $pages = $startpage + $pages;

    if (($pages * $pagesize) + $pagesize > $num_results) {
      $pages = ceil($num_results/$pagesize);
    }
    echo "\n" . $filter . ' ASSETS: '.  $num_results . "\n";
    for ($p=$startpage; $p < $pages; $p++) {
      echo 'PAGE: ' . $p;
      _brightcove_manager_get_modified_videos($p, $pagesize, $last_updated_date, $filter, $override);
      echo "\n";
    }
  }
}

/**
 * Get modified videos from brightcove
 * @param  integer $page=0           page number
 * @param  integer $pagesize=25      page size, max is 25
 * @param  string  $fromdate=NULL    modified since this date
 * @param  string  $filter=          video filter
 */
function _brightcove_manager_get_modified_videos($page=0, $pagesize=25, $fromdate=NULL, $filter='PLAYABLE,UNSCHEDULED,INACTIVE,DELETED', $overrideUpdate = FALSE) {
  $params = array('video_fields' => 'id,name,shortDescription,longDescription,creationDate,publishedDate,lastModifiedDate,startDate,endDate,linkURL,linkText,tags,videoStillURL,thumbnailURL,referenceId,length,economics,playsTotal,playsTrailingWeek,FLVURL,renditions,iOSRenditions,FLVFullLength,videoFullLength,customFields','get_item_count'=>'true');
  $params['page_size'] = $pagesize;
  $params['page_number'] = $page;
  $params['sort_by'] = 'MODIFIED_DATE';
  $params['sort_order'] = 'DESC';
  if (strlen($fromdate) > 0) {
    $params['from_date'] = $fromdate;
  }
  $params['filter'] = $filter;

  $results = new stdClass();
  $ct=0;
  // Make our API call
  $results = _brightcove_manager_call_mapi('modifiedvideos', $params);
  if (count($results)) {
    foreach ($results as $item) {
      $do_update_db = 0;
      echo "\n" . 'ID: ' . $item->id . ': ';
      if ($overrideUpdate == TRUE) { echo 'OVERRIDE: ';}
      // check to see if exists and last update date
      $video_last_update = db_select('brightcove_manager_metadata', 'v')
        ->fields('v', array('brightcove_id', 'raw_data_date'))
        ->condition('brightcove_id', $item->id)
        ->execute();

      $lastModifiedDate = _brightcove_manager_convert_date($item->lastModifiedDate);
      if ($video_last_update->rowCount() > 0) {
        foreach ($video_last_update as $record) {
          $diff = $record->raw_data_date - $lastModifiedDate;
          if ($diff < 0) {
            // Update DB
            $do_update_db = 1;
          }
        }
      } else {
        $do_update_db = 1;
      }

      if ($do_update_db == 1 || $overrideUpdate == TRUE) {
        echo 'dbupdate';
        _brightcove_manager_update_metadata($item, $filter, 'full');
      } else {
        echo 'No dbupdate';
      }
    }
  } else {
    // No items in results
  }
}

/**
 * Get last updated date
 * @param  string $updatedate format last update date
 * @return string             Return last updated date
 */
function _brightcove_manager_last_updated($updatedate = NULL) {
  if (strlen($updatedate) > 0) {
    $last_updated_date = floor(strtotime($updatedate)/60);
  } else {
    $last_date = 0;
    $video_last_update = db_query('select max(raw_data_date) as last_date from brightcove_manager_metadata');
    foreach ($video_last_update as $record) {
      $last_date = $record->last_date;
    }
    $last_updated_date = floor($last_date/60);
  }
  return $last_updated_date;
}

/**
 * Get assets by video ids
 * @param  array  $video_ids array of video IDs
 * @return integer  number of assets modified
 */
function _brightcove_manager_get_assets_by_ids($video_ids = array()) {
  $params = array('video_fields' => 'id,videoStillURL,thumbnailURL,FLVURL');
  $params['sort_by'] = 'MODIFIED_DATE';
  $params['sort_order'] = 'DESC';
  $params['video_ids'] = implode(',', $video_ids);

  $ct = 0;
  $results = _brightcove_manager_call_mapi('videosbyids', $params);
  if (count($results)) {
    foreach ($results as $item) {
      if (isset($item) && property_exists($item, 'id')) {
        echo ++$ct . '. ID: ' . $item->id . "\n";
        _brightcove_manager_update_metadata($item, NULL, 'assets');
      }
    }
  } else {
    // No items in results
  }
  return $ct;
}

/**
 * Get total count of videos
 * @param  string $fromdate=NULL from this date
 * @param  string $filter        video filter
 * @return int                   total number
 */
function _brightcove_manager_get_total_count($fromdate=NULL, $filter = 'PLAYABLE,UNSCHEDULED,INACTIVE,DELETED') {
  if (strlen($fromdate) > 0) {
    $params = array('video_fields' => 'id','get_item_count'=>'true', 'from_date'=>$fromdate);
    $params['filter'] = $filter;
    $cmd = 'find_modified_videos';
  } else {
    $params = array('video_fields' => 'id','get_item_count'=>'true');
    $cmd = 'find_all_videos';
  }
  $params['page_size'] = 1;
  $params['page_number'] = 0;
  $json = _brightcove_manager_call_api($cmd, $params);
  $results = json_decode($json);

  //echo 'TOTAL COUNT: ' . $results->total_count . "\n"; exit;
  return $results->total_count;
}

/**
 * Update metadata in database
 * @param  object $item        video
 * @param  string $filter=NULL filter type
 * @param  string $type='full' type of update
 * @return void
 */
function _brightcove_manager_update_metadata($item, $filter=NULL, $type='full') {
  if(isset($item->customFields->{'5min_id'})) {
    $fiveminID = $item->customFields->{'5min_id'};
  } else {
    $fiveminID = NULL;
  }
  if(isset($item->customFields->platform)) {
    $platform = $item->customFields->platform;
  } else {
    $platform = NULL;
  }
  if ($filter === 'DELETED') {
    $deleted = 1;
    echo ', deleted';
  } else {
    $deleted = 0;
  }
  if ($filter === 'DELETED' || $filter === 'INACTIVE' || $item->FLVURL == null) {
  //if (strpos($filter, 'INACTIVE') !== false || $item->FLVURL == null) {
    $active = 0;
     echo ', made inactive';
  } else {
    $active = 1;
  }
  switch ($type) {
    case 'assets':
      $video_update = db_merge('brightcove_manager_metadata')
        ->key(array('brightcove_id' => $item->id))
        ->fields(array(
          'video_still_url' => $item->videoStillURL,
          'thumbnail_url' => $item->thumbnailURL,
          'flv_url' => $item->FLVURL,
        ))
        ->execute();
    break;
    case 'full':
      $video_update = db_merge('brightcove_manager_metadata')
        ->key(array('brightcove_id' => $item->id))
        ->fields(array(
          'name' => $item->name,
          'short_description' => $item->shortDescription,
          'long_description' => $item->longDescription,
          'creation_date' =>  _brightcove_manager_convert_date($item->creationDate),
          'published_date' => _brightcove_manager_convert_date($item->publishedDate),
          'last_modified_date' => _brightcove_manager_convert_date($item->lastModifiedDate),
          'start_date' => _brightcove_manager_convert_date($item->startDate),
          'end_date' => _brightcove_manager_convert_date($item->endDate),
          'related_link_url' => $item->linkURL,
          'related_link_text' => $item->linkText,
          'tags' =>implode(",", $item->tags),
          'video_still_url' => $item->videoStillURL,
          'thumbnail_url' => $item->thumbnailURL,
          'reference_id' => $item->referenceId,
          'video_length' => _brightcove_manager_convert_int($item->length),
          'plays_total' => _brightcove_manager_convert_int($item->playsTotal),
          'plays_trailing_week' => _brightcove_manager_convert_int($item->playsTrailingWeek),
          'fivemin_id' => $fiveminID,
          'platform' => $platform,
          'active' => $active,
          'deleted' => $deleted,
          'flv_url' => $item->FLVURL,
          'renditions' => json_encode($item->renditions),
          'ios_renditions' => json_encode($item->IOSRenditions),
          'flv_full_length' => json_encode($item->FLVFullLength),
          'video_full_length' => json_encode($item->videoFullLength),
          'raw_data' => json_encode($item),
          'raw_data_date' => strtotime('now'),
        ))
        ->execute();
    break;
  }
}

/**
 * Cache Brightcove results
 * @param  string $cache_id  Cache ID
 * @param  string $data      $data
 * @return void
 */
function _brightcove_manager_cache_api_results($cache_id,$data) {
  // Save to DB
  db_merge('cache_brightcove')
    ->key(array('cid' => $cache_id))
    ->fields(array(
          'data' => $data,
          'created' => time(),
    ))
    ->execute();
}

function _brightcove_manager_convert_date($unixtime) {
  if (is_numeric($unixtime)) {
    if ($unixtime > 2147483647) {
      $unixtime = $unixtime/1000;
    }
  } else {
    $unixtime = 0;
  }
  return $unixtime;
}

function _brightcove_manager_convert_int($int) {
  if (!is_numeric($int)) {
    $int = 0;
  }
  return $int;
}
