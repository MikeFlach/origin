<?php
/* error_reporting(E_ALL);
ini_set('display_errors', '1'); */

require_once('videofeedapi.php');
$videoAPI = new VideoFeedAPI();
$data = array('statusmsg'=>'');

if (isset($_GET['cmd']) && strlen($_GET['cmd'])) {
  switch ($_GET['cmd']) {
    case 'getfeatured':
      $params = array('video_fields' => 'id,name,shortDescription,longDescription,videoStillURL,thumbnailURL,length,FLVURL');
      $data = $videoAPI->get_featured_videos(PLAYER_FEATURED, $params);
    break;
    case 'getvideolist':
      if (isset($_GET['referenceid']) && strlen($_GET['referenceid'])) {
        $playlist_id=$_GET['referenceid'];
        $params = array('video_fields' => 'id,name,shortDescription,longDescription,videoStillURL,thumbnailURL,length,FLVURL');
        $data = $videoAPI->get_playlist_by_reference_id($playlist_id, $params);
        if ($data == 'null') {
          $data['statusmsg'] = 'ERROR_UNKNOWN_REQUEST';
        }
      } else {
        $data['statusmsg'] = 'ERROR_UNKNOWN_REQUEST';
      }
    break;
    case 'getvideo':
      if (isset($_GET['videoid']) && strlen($_GET['videoid'])) {
        $params = array('video_fields' => 'id,name,shortDescription,longDescription,videoStillURL,thumbnailURL,length,playsTotal,FLVURL');
        $data = $videoAPI->get_video_by_id($_GET['videoid'], $params);
      } else {
        $data['statusmsg'] = 'ERROR_UNKNOWN_REQUEST';
      }
    break;
    case 'getoverview':
      if (isset($_GET['referenceid']) && strlen($_GET['referenceid'])) {
        $playlist_id=$_GET['referenceid'];
        $params = array('playlist_fields' => 'referenceId,name,shortDescription,thumbnailURL,videos');
        $data = $videoAPI->get_playlist_overview($playlist_id, $params);
        if ($data == 'null') {
          $data['statusmsg'] = 'ERROR_UNKNOWN_REQUEST';
        }
      } else {
        $data['statusmsg'] = 'ERROR_UNKNOWN_REQUEST';
      }
    break;
    case 'getallvideos':
      $data = $videoAPI->get_all_videos();
    break;
    case 'getchannels':
      $params = array('video_fields' => '', 'playlist_fields' => 'referenceid,name,shortDescription,thumbnailURL');
      $data = $videoAPI->get_player_playlists(PLAYER_CHANNELS, $params);
    break;
    case 'getseries':
      $params = array('video_fields' => '', 'playlist_fields' => 'referenceid,name,shortDescription,thumbnailURL');
      $data = $videoAPI->get_player_playlists(PLAYER_SERIES, $params);
    break;
    case 'search':
      $params = array('video_fields' => 'id,name,shortDescription,longDescription,videoStillURL,thumbnailURL,length,playsTotal,FLVURL');
      if (isset($_GET['q']) && strlen($_GET['q'])) {
        $data = $videoAPI->search_videos($_GET['q'], $params);
      } else {
        $data['statusmsg'] = 'ERROR_UNKNOWN_REQUEST';
      }
    break;
    default:
    $data['statusmsg'] = 'ERROR_UNKNOWN_REQUEST';
    break;
  }
} else {
  $data['statusmsg'] = 'ERROR_UNKNOWN_REQUEST';
}

header('Content-type: application/json');
echo $videoAPI->format_output($data);
