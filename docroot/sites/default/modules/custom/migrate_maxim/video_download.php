<?php

//Import videos from Drupal
set_time_limit(0);

error_reporting(E_ALL);
ini_set('display_errors', '1');

// Include Drupal bootstrap
chdir($_SERVER['DOCUMENT_ROOT']);
define('DRUPAL_ROOT', getcwd());
define('VIDEO_ROOT', '/home/henry/Videos');
require_once $_SERVER['DOCUMENT_ROOT'] . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_DATABASE);

// Include the BCMAPI Wrapper
require(DRUPAL_ROOT . '/feeds/bc-mapi.php');
// Instantiate the class, passing it our Brightcove API tokens (read, then write)
$bc = new BCMAPI(
  'CX1YvsC6MvJ-6FddP41yjMQxH1sktJjDEH4QV0p-RQPZKyLwkfgCow..',
  'CX1YvsC6MvJ-6FddP41yjMQxH1sktJjDb_COaVlPdgh9mTATqozy4Q..'
);

//download_video_files();
import_hotties_to_brightcove();

function download_hotties_2011_videos() {
  $query = db_select('field_data_field_slides_wrapper', 'w');
  $query->leftJoin('node', 'n', 'n.nid = w.entity_id');
  $query->leftJoin('field_data_field_slides', 's', 'w.field_slides_wrapper_value = s.entity_id');
  $query->leftJoin('file_managed', 'f', 'f.fid = s.field_slides_fid');
  $query->fields('n', array('title', 'nid'))
        ->fields('f', array('fid', 'uri'))
        ->condition('f.type', 'video')
        ->condition('f.filename', '2011 Hometown', 'regexp');

  $qryResults = $query->execute();

  $file_path=VIDEO_ROOT . '/cdn/';
  $ct=0;
  foreach ($qryResults as $record) {
    echo ++$ct . '. ' . $record->nid . ' - ' . $record->title . ' - ' . $record->uri . '<br />';
    $file = str_replace('public://', 'http://cdn2.maxim.com/maxim/sites/default/files/', $record->uri);
    save_file($file, $record->fid . '.mp4' , $file_path);
    flush();
  }
}

function import_hotties_to_brightcove() {
  GLOBAL $bc;
  $file_path = VIDEO_ROOT . '/cdn/';
  $query = db_select('field_data_field_slides_wrapper', 'w');
  $query->leftJoin('node', 'n', 'n.nid = w.entity_id');
  $query->leftJoin('field_data_field_slides', 's', 'w.field_slides_wrapper_value = s.entity_id');
  $query->leftJoin('file_managed', 'f', 'f.fid = s.field_slides_fid');
  $query->fields('n', array('title', 'nid'))
        ->fields('f', array('fid', 'uri'))
        ->condition('f.type', 'video')
        ->condition('f.filemime', 'video/brightcove', '<>')
        ->condition('f.filename', '2011 Hometown', 'regexp')
        ->condition('f.fid', array(82178, 82179,82197, 82196, 82195, 82202, 82201, 82200, 82216, 82215, 82214, 82220, 82219, 82218, 82227, 82226, 82225, 82234, 82233, 82232, 82237, 82236, 82235,82240, 82238, 82239, 82244, 82243, 82242, 82268, 82277, 82276, 82275), 'not in');

  $result = $query->execute();

  $ct=0;

  $mediaOptions = array (
      'create_multiple_renditions' => TRUE,
      'preserve_source_rendition' => TRUE,
    );

  foreach($result as $row){
//var_dump($row);
    if($ct++ < 10) {
      //var_dump($row); die();
      // Create an array of meta data from our form fields
      $metaData = array(
        'name' => strip_tags($row->title) . ' - Semifinalist - 2011 Hometown Hotties',
        'startDate' => 1309641195*1000,
        'tags'=> array('2011 Hometown Hotties', 'hometown hotties'),
      );

      $description = '2011 Hometown Hotties Semifinalist: ' . $row->title;
      $metaData['shortDescription'] = str_limit(strip_tags($description),148);

      //print_r($metaData); die();

      $filename = $row->fid . '.mp4';

      $video_file_location = $file_path . $filename;

      try {
        // Upload the video and save the video ID
        $bcid = $bc->createMedia('video', $video_file_location, $metaData, $mediaOptions);
        //echo 'New video id: ' . $bcid  . '; title: ' . $row->title  . ' - Semifinalist - 2011 Hometown Hotties' . "<br/>";
        $str = "update file_managed set uri='brightcove://$bcid', filemime='video/brightcove', filesize=0, filename='$bcid'
where fid=$row->fid;";
        echo $str . "<br/>";
        db_query($str);

      } catch(Exception $error) {
        // Handle our error
        echo $error;
        die();
      }
    } else {
      // Stop at 1 for testing
      die();
    }
  }
}

function get_video_files() {
  $qry = <<<QRY
    SELECT * FROM maxim.video_5min where id is null order by video_id desc
QRY;
  $results = db_query($qry);
  $ct=0;
  foreach ($results as $record) {
    if(strpos($record->drupal_file_uri, ' ') > 0) {
      get_video_file(str_replace(' ', '%20', $record->drupal_file_uri), $record->drupal_nid . '_' . str_replace(' ', '_', $record->original_filename));
    }
  }
}

function get_video_nodes_not_in_5min() {
  $qry = <<<QRY
  select n.nid, n.vid, n.created, FROM_UNIXTIME(n.created) as create_date_time, n.title, b.body_value, td.name as channel,
   fm.uri as file_uri, fm.filemime, fm.filename, five.field_media_5min_id_value as 5min_id, t.field_media_thumbnail_path_value
  from node n
  left join field_data_field_media_file f on n.nid = f.entity_id
  left join field_data_body b on n.nid = b.entity_id
  left join file_managed fm on f.field_media_file_fid = fm.fid
  left join field_data_field_channel c on n.nid = c.entity_id
  left join taxonomy_term_data td on td.tid = c.field_channel_tid
  left join field_data_field_media_5min_id five on fm.fid = five.entity_id and five.entity_type='file' and five.bundle='video'
  left join field_data_field_media_thumbnail_path t on t.entity_id = n.nid and t.entity_type='node' and t.bundle='video'
  where n.type='video'
  and five.field_media_5min_id_value is null
  order by created desc
  limit 0, 10000;
QRY;

  $results = db_query($qry);
  $ct=0;
  foreach ($results as $record) {
    //print_r($record);
    $video_update = db_insert('video_5min')
      ->fields(array(
        'title' => $record->title,
        'description' => $record->body_value,
        'link' => 'node/' . $record->nid,
        'original_url' => $record->file_uri,
        'original_filename' => $record->filename,
        'original_type' => $record->filemime,
        'video_file' => $record->file_uri,
        'video_type' => $record->filemime,
        'image_thumbnail_url' => $record->field_media_thumbnail_path_value,
        'category' => $record->channel,
        'pubDate' => $record->created,
        'pubDateTime' =>$record->create_date_time,
        'drupal_nid' => $record->nid,
        'drupal_file_uri' => $record->file_uri,
        'drupal_file_entity_id' => $record->fid,
      ))
      ->execute();
    echo ++$ct . '. id: ' . $record->nid . '; title: ' . $record->title . '<br>';
  }
}

function get_video_nodes_with_5min_ids() {
  $qry = <<<QRY
  select n.nid, n.vid, n.created, FROM_UNIXTIME(n.created) as create_date_time, n.title, td.name as channel,
     fm.uri as file_uri, fm.fid, fm.filemime, five.field_media_5min_id_value as fivemin_id
  from node n
  left join field_data_field_media_file f on n.nid = f.entity_id
  left join file_managed fm on f.field_media_file_fid = fm.fid
  left join field_data_field_channel c on n.nid = c.entity_id
  left join taxonomy_term_data td on td.tid = c.field_channel_tid
  left join field_data_field_media_5min_id five on fm.fid = five.entity_id and five.entity_type='file' and five.bundle='video'
  where n.type='video'
  and five.field_media_5min_id_value is not null
  order by created desc
QRY;

  $results = db_query($qry);
  $ct=0;
  $file_path = DRUPAL_ROOT . '/sites/default/files/';
  foreach ($results as $record) {
    //print_r($record);

    $video_update = db_update('video_5min')
      ->fields(array(
        'drupal_nid' => $record->nid,
        'drupal_file_uri' => $record->file_uri,
        'drupal_file_entity_id' => $record->fid,
      ))
      ->condition('id', $record->fivemin_id)
      ->execute();
    echo ++$ct . '. id: ' . $record->fivemin_id . '; file: ' . $record->file_uri . '<br>';
  }
}

function download_video_files() {
  $file_path = VIDEO_ROOT . '/cdn/';
  $qry = "SELECT w.entity_id as nid, s.*, f.* FROM maxim.field_data_field_slides s
    left join field_data_field_slides_wrapper w on w.field_slides_wrapper_value=s.entity_ID
    left join file_managed f on f.fid=s.field_slides_fid
    where f.type = 'video'
    and w.entity_id is not null";
  $results = db_query($qry);

  $ct = 0;
  foreach ($results as $row) {
    echo ++$ct . '. ' . $row->fid . ' - ' . $row->uri . '<br />';
    flush();
    save_file($row->uri, $row->fid . '-' . $row->filename , $file_path);
    /*if ($ct < 50) {
      echo ++$ct . '. ' . $row->id . ' - ' . $row->original_url . '<br />';
      flush();
      save_file($row->original_url, $row->id . '.' . $row->original_type , $file_path);
    }*/
  }

}

function update_brightcove_video($bID) {
  $file_path = VIDEO_ROOT . '/5min_orig/';
  $qry = "select * from video_5min where original_type='mov' or original_type='mp4'";
  $results = db_query($qry);

  $mediaOptions = array (
      'create_multiple_renditions' => TRUE,
      'preserve_source_rendition' => TRUE,
    );
  $ct = 0;

  foreach ($results as $row) {
    if ($ct < 50) {
      echo ++$ct . '. ' . $row->id . ' - ' . $row->original_url . '<br />';
      flush();
      save_file($row->original_url, $row->id . '.' . $row->original_type , $file_path);
    }
  }

}

function import_to_brightcove() {
  $file_path = VIDEO_ROOT . '/videos/';

  $qry = "select * from video_5min v where uploaded = 0 and tags <> '' and tags <> 'ad' and brightcoveID is null order by id ASC";
  $result = db_query($qry);

  $ct=0;

  $mediaOptions = array (
      'create_multiple_renditions' => TRUE,
      'preserve_source_rendition' => TRUE,
    );

  foreach($result as $row){
    if($ct++ < 50) {
      //var_dump($row); die();
      // Create an array of meta data from our form fields
      $metaData = array(
        'name' => strip_tags($row->title),
        'referenceId' => 'nid_' . $row->drupal_nid,
        'startDate' => strtotime($row->pubDateTime)*1000,
        'tags'=> explode(',', $row->tags),
      );

      if (strlen($row->description) > 0) {
        $metaData['shortDescription'] = str_limit(strip_tags($row->description),148);
        $metaData['longDescription'] = strip_tags($row->description);
      } else {
        $metaData['shortDescription'] = str_limit(strip_tags($row->title),148);
        $metaData['longDescription'] = '';
      }

      //print_r($metaData); die();

      $extVideo = $row->video_file;
      $filename = $row->drupal_nid . '_' . $row->original_filename;
      if (strpos($filename, '.flv')) {
        $filename = str_replace('.flv', '.mpg', $filename);
      }

      if(strpos($filename, ' ') > 0) {
        $filename = str_replace(' ', '_', $filename);
      }

      $video_file_location = $file_path . $filename;

      try {
        // Upload the video and save the video ID
        $bcid = $bc->createMedia('video', $video_file_location, $metaData, $mediaOptions);
        echo 'New video id: ' . $bcid  . '; title: ' . $row->title . "<br/>";
        // Update database
        $updateQry = db_query("update video_5min set brightcoveID = '$bcid', uploaded = 1 where video_id='$row->video_id'");

        // Upload image
        $imagefile = $row->image_thumbnail_url;
        if (strlen($imagefile)) {
          $imagefilename = basename($row->image_thumbnail_url);
          $imageMetadata = array(
            'type' => 'VIDEO_STILL',
            'displayName' => $imagefilename,
          );
          // Save external image to file
          if(strpos($imagefilename, ' ') > 0) {
            $imagefilename = str_replace(' ', '_', $imagefilename);
          }
          save_file($imagefile, $imagefilename);
          $image_file_location = $file_path . $imagefilename;

          $bcImageID = $bc->createImage('video', $image_file_location, $imageMetadata, $bcid);
          $bcThumbnailID = $bc->createImage('video', $image_file_location, array('type'=>'THUMBNAIL', 'displayName'=>$imagefilename . ' Thumbnail'), $bcid);
        }
      } catch(Exception $error) {
        // Handle our error
        echo $error;
        die();
      }
    } else {
      // Stop at 1 for testing
      die();
    }
  }
}

function get_video_file($file_uri, $filename) {
  $file_path = DRUPAL_ROOT . '/sites/default/files/';
  $file_location = '';
  if (strpos($file_uri, 'public://maxim/files/maxim2') !== false) {
    $file_location = str_replace('public://', 'http://cdn2.maxim.com/maxim/sites/default/files/', $file_uri);
  } else if (strpos($file_uri, 'public://') !== false) {
    $file_location = $file_path . str_replace('public://', '', $file_uri);
  } else if (strpos($file_uri, 'http://cdn2.maxim.com') !== false) {
    $file_location = $file_path . str_replace('http://cdn2.maxim.com/', '', $file_uri);
  }
   echo $file_location , '<br>';
  if (strlen($file_location) > 0 && file_exists($file_location)) {
    echo ' exists';
  } else {
    if (strpos($filename, '.flv')) {
      $filename = str_replace('.flv', '.mpg', $filename);
    }
    if (strpos($file_uri, 'public://') !== false) {
      $fileURL = str_replace('public://', 'http://cdn2.maxim.com/maxim/sites/default/files/', $file_uri);
    } else {
      $fileURL = $file_uri;
    }
    save_file($fileURL,$filename);
  }
}

function save_file($url, $newfilename, $local_path = '/tmp/videos/'){
  if (!file_exists($local_path . $newfilename)) {
    set_time_limit(0);
    $fp = fopen($local_path . $newfilename, 'w+');
    if (strpos($url, 'public://') !== FALSE) {
      $cdn_url = str_replace('public://', 'http://cdn2.maxim.com/maxim/sites/default/files/', $url);
    } else {
      $cdn_url = $url;
    }

    $ch = curl_init($cdn_url);//Here is the file we are downloading
    curl_setopt($ch, CURLOPT_FILE, $fp); // here it sais to curl to just save it
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
    curl_exec($ch);
    curl_close($ch);
    fclose($fp);
  } else {
    echo 'file exists<br />';
  }
}

function str_limit($str,$len) {
  if (strlen($str) > $len) {
    $str = substr($str,0,$len-3) . '...';
  }
  return $str;
}
