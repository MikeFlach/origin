<?php
/* error_reporting(E_ALL);
ini_set('display_errors', '1'); */

require_once('videofeedapi.php');
$videoAPI = new VideoFeedAPI();
$data = array('errorcode'=>0, 'msg'=>'');

if (isset($_GET['cmd']) && strlen($_GET['cmd'])) {
  switch ($_GET['cmd']) {
    case 'getvideolist':
      if (isset($_GET['channel']) && strlen($_GET['channel'])) {
        $playlist_id='playlist:' . $_GET['channel'];
        $params = array('video_fields' => 'id,name,shortDescription,longDescription,videoStillURL,thumbnailURL,length,playsTotal,FLVURL');
        $data = $videoAPI->get_playlist_by_reference_id($playlist_id, $params);
        if ($data == 'null') {
          $data = array('errorcode'=>1, 'msg'=>'Not a valid channel');
        }
      } else {
        $data = array('errorcode'=>1, 'msg'=>'No channel defined');
      }
    break;
    case 'getallvideos':
      $data = $videoAPI->get_all_videos();
    break;
    case 'getchannels':
      $data = $videoAPI->get_player_playlists('1798911603001');
    break;
    case 'getseries':
      $data = $videoAPI->get_player_playlists('1799261978001');
    break;
    default:
    $data = array('errorcode'=>1, 'msg'=>'Not valid command');
    break;
  }
} else {
  $data = array('errorcode'=>1, 'msg'=>'No command defined');
}

header('Content-type: application/json');
echo $videoAPI->format_output($data);
