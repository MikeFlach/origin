<?php

// Report all PHP errors
error_reporting(-1);
ini_set('error_reporting', E_ALL);

if(!isset($_GET['batch'])){
  $_GET['batch'] = 1;
}

if(!isset($_GET['userid'])){
  $_GET['userid'] = 2350023;
}

if(!isset($_GET['action'])){
  die();
}

switch($_GET['action']){
  case 'getChannels':
    $data=getChannels();
    print_r($data);
  break;
  case 'downloadFiles':
    downloadFiles($_GET['batch']);
  break;
  case 'downloadThumbnailFiles':
    downloadThumbnailFiles($_GET['batch']);
  break;
  case 'getUserFileInfo':
    $fid=3978797;
    $data=getUserFileInfo($fid);
    print_r($data);
  break;
  case 'processOneUserFiles':
    processOneUserFiles($_GET['userid']);
  break;
  case 'processUserFiles':
    processUserFiles($_GET['batch']);
  break;
  case 'getMoreUserFiles':
    getMoreUserFiles($_GET['batch']);
  break;
  case 'getUserFiles':
    print_r(getUserFiles($_GET['userid']));
  break;
}

// 

//getUserFiles($_GET['userid']);

//getUserFileInfo(4135563);
// insertUsersIntoDB($_GET['batch']);
// getGroups();
// getUsersInGroup(7095);
// getUserData(2307449);

function downloadFiles($batch = 1 ){
  $maxrows = 200;
  $conversion = 1191;
  $extension = '.jpg';
  $startrow = $maxrows * ($batch-1); 

  $mysqli = new mysqli('localhost', 'maximdev', 'maxim', 'filemobile') or die('Error');

  $query = "SELECT id, uid, publicUrl, thumbUrl, conversions, contenttype, extension FROM files where extension='mov' order by id asc limit $startrow, $maxrows";
  echo $query . '<br />';
  if ($result = $mysqli->query($query)) {
    $ct=1;
    while ($row = $result->fetch_object()) {
      $fileDirectory = '/media/files/hotties/';
      //$fileDirectory = '/media/files/maxim/default/files/maxim/files/maxim2/Maxim/Hotties/2011/';
      $userDirectory = $fileDirectory . $row->uid . '/';

      switch($row->contenttype){
        case 'text/plain':
        case '':
        break;
        default:
          if(ListFind($row->conversions, $conversion)){
            // Check to see directory exists
            if(!is_dir($userDirectory)) {
              if (!mkdir($userDirectory, 0777, true)){
                die('Failed to create folder...');
              }
            }

            //$file = $userDirectory . $row->id  . '.' . $row->extension;
            $file = $userDirectory . $row->id  . $extension;
            echo $ct++ . '. ' . $row->thumbUrl . '/' . $conversion . ' -> ';
            ob_flush();
            flush();
            if(!file_exists($file)){
              echo $file . '<br />';
              file_put_contents($file, file_get_contents($row->thumbUrl . '/' . $conversion));
            } else {
              echo 'file exists<br />';
            }
          }
        break;
      }
    }
  } else {
    printf("<br />DB Error: %s\n", $mysqli->error);
  }
	mysqli_close($mysqli); 
  //return $user;

}

function downloadThumbnailFiles($batch = 1 ){
  $maxrows = 1000;
  $conversion = 1005;
  $extension = '_1005.jpg';
  $startrow = $maxrows * ($batch-1); 

  $mysqli = new mysqli('localhost', 'maximdev', 'maxim', 'filemobile') or die('Error');

  $query = "SELECT id, uid, publicUrl, thumbUrl, conversions, contenttype, extension FROM files where conversions regexp '1005' order by id asc limit $startrow, $maxrows";
  echo $query . '<br />';
  if ($result = $mysqli->query($query)) {
    $ct=1;
    while ($row = $result->fetch_object()) {
      $fileDirectory = '/media/files/hotties/';
      //$fileDirectory = '/media/files/maxim/default/files/maxim/files/maxim2/Maxim/Hotties/2011/';
      $userDirectory = $fileDirectory . $row->uid . '/';

      switch($row->contenttype){
        case 'text/plain':
        case '':
        break;
        default:
          if(ListFind($row->conversions, $conversion)){
            // Check to see directory exists
            if(!is_dir($userDirectory)) {
              if (!mkdir($userDirectory, 0777, true)){
                die('Failed to create folder...');
              }
            }

            //$file = $userDirectory . $row->id  . '.' . $row->extension;
            $file = $userDirectory . $row->id  . $extension;
            echo $ct++ . '. ' . $row->thumbUrl . '/' . $conversion . ' -> ';
            ob_flush();
            flush();
            if(!file_exists($file)){
              echo $file . '<br />';
              file_put_contents($file, file_get_contents($row->thumbUrl . '/' . $conversion));
            } else {
              echo 'file exists<br />';
            }
          }
        break;
      }
    }
  } else {
    printf("<br />DB Error: %s\n", $mysqli->error);
  }
	mysqli_close($mysqli); 
  //return $user;

}

function ListFind($list, $value, $delimiter=","){
  $arr = explode($delimiter, $list);

  for($i=0; $i<count($arr); ++$i){
    if(strcmp($arr[$i], $value) == 0) {
      return true;
    }
  }
  return false;
}

function getMoreUserFiles($userID){
  $maxrows = 50;
  $startrow = $maxrows * ($batch-1);

  $users = getUsersFromDB($startrow, $maxrows);
  $ct = 1;
  foreach ($users as $user){
    $userFiles = getUserFiles($user->id);
    print '<br /><strong>' . $ct++ . '. User: ' . $user->id . '</strong>';
    //if($userFiles['result']['totalCount'] > 25){
    print ' - Total: ' . $userFiles['result']['totalCount'];
    //}
/*    foreach($userFiles['result']['data'] as $record){
      //print_r($record);
      $fileInfo = getUserFileInfo($record['id']);
      print_r($fileInfo);
      die();
      print '<br />Insert File: ' . $record['id'];
      // print_r($fileInfo['result']);
      insertFileIntoDB($record, $fileInfo['result']);
    }*/
    ob_flush();
    flush();
  }
}

function processUserFiles($batch = 1){
  $maxrows = 50;
  $startrow = $maxrows * ($batch-1);

  $users = getUsersFromDB($startrow, $maxrows);
  $ct = 1;
  foreach ($users as $user){
    $userFiles = getUserFiles($user->id);
    print '<br /><strong>' . $ct++ . '. User: ' . $user->id . '</strong>';
    foreach($userFiles['result']['data'] as $record){
      //print_r($record);
      $fileInfo = getUserFileInfo($record['id']);
      print '<br />Insert File: ' . $record['id'];
      // print_r($fileInfo['result']);
      insertFileIntoDB($record, $fileInfo['result']);
    }
    ob_flush();
    flush();
  }
}

function processOneUserFiles($uid){
  $userFiles = getUserFiles($uid);
  print '<br /><strong>User: ' . $uid . '</strong>';
  //print_r($userFiles);
  foreach($userFiles['result']['data'] as $record){
    print_r($record);
    $fileInfo = getUserFileInfo($record['id']);
    print '<br />Insert File: ' . $record['id'];
    insertFileIntoDB($record, $fileInfo['result']);
    ob_flush();
    flush();
  }
}

function insertFileIntoDB($rec, $frec){

  $mysqli = new mysqli('localhost', 'maximdev', 'maxim', 'filemobile') or die('Error');
  // get file conversion types
  $fileConversions = array();
  foreach($frec['conversions'] as $conv){
    $fileConversions[] = $conv['type'];
  }

  $query = 'INSERT into files (id, uid, user_name, title, channel, filetype, hits, message, rating, status, tags, upload, votecount, publicUrl, thumbUrl, location, contenttype, externalid, context, filename, extension, filesize, ofilesize, parentid, privacy, moderationstatus, width, height, converttime, lastupdatetime, offensive, channel_shortname, channel_name, conversions) ';

  $query .= "VALUES ('" . 
    $rec['id'] . "', '" . 
    $rec['uid'] . "', '" . 
    $mysqli->real_escape_string($rec['user_name']) . "', '" . 
    $mysqli->real_escape_string($rec['title']) . "', '" .  
    $rec['channel'] . "', '" .  
    $rec['filetype'] . "', '" .  
    $rec['hits'] . "', '" .  
    $mysqli->real_escape_string($rec['message']) . "', '" .  
    $rec['rating'] . "', '" .  
    $rec['status'] . "', '" .  
    $rec['tags'] . "', '" .  
    $rec['upload'] . "', '" .  
    $rec['votecount'] . "', '" .  
    $rec['publicUrl'] . "', '" .  
    $rec['thumbUrl'] . "', '" .  
    $rec['location'] . "', '" .  
    $frec['contenttype'] . "', '" .  
    $frec['externalid'] . "', '" .  
    $frec['context'] . "', '" .  
    $mysqli->real_escape_string($frec['filename']) . "', '" .  
    $frec['extension'] . "', '" .  
    $frec['filesize'] . "', '" .  
    $frec['ofilesize'] . "', '" .  
    $frec['parentid'] . "', '" .  
    $frec['privacy'] . "', '" .  
    $frec['moderationstatus'] . "', '" .  
    $frec['width'] . "', '" .  
    $frec['height'] . "', '" .  
    $frec['converttime'] . "', '" .  
    $frec['lastupdatetime'] . "', '" .  
    $frec['offensive'] . "', '" .  
    $frec['channel_shortname'] . "', '" .  
    $frec['channel_name'] . "', '" .  
    implode(',', $fileConversions) . 
  "')";

  if(!$mysqli->query($query)){
    printf("<br />DB Error: %s\n", $mysqli->error);
  }
}

function getUsersFromDB($start, $maxrows){
  $user = array();
	$mysqli = new mysqli('localhost', 'maximdev', 'maxim', 'filemobile') or die('Error');
  $query = "SELECT id, firstname, lastname FROM users order by id asc limit $start, $maxrows";
  echo $query;
  if ($result = $mysqli->query($query)) {
    $ct=-1;
    while ($row = $result->fetch_object()) {
      $user[] = $row;
   }
  }
	mysqli_close($mysqli); 
  return $user;
}

function getUserFiles($id){
  $params = array(
    'method' => 'media.getFiles',
    'filters' => array(
        'uid' => $id,
      ),
    'limit' => 100,
  );
  $data = getData($params);
  return $data;
}

function getUserFileInfo($fid){
  $params = array(
    'method' => 'media.getFileInfo',
    'id' => $fid,
  );
  $data = getData($params);
  //print_r($data);
  return $data;
}

function getChannels(){
  $params = array(
    'method' => 'channels.getChannels',
  );
  $data = getData($params);
  return $data;
}

function insertUsersIntoDB($batch){
  $data = getGroups();
  
	$link = new mysqli('localhost', 'maximdev', 'maxim', 'filemobile') or die('Error');
  $ct=0;
  foreach($data['result'] as $gp){
    $ct++;
    if($batch == $ct){
      // Get users in Group
      $userData = getUsersInGroup($gp['id'])  ;
     
      foreach($userData['result']['data'] as $u){
        echo '<br />insertUser ' . $u['id'];
        // insert user
	      $query = 'INSERT IGNORE into users (id, firstname, lastname, avatar, email, user) ';
        $query .= "VALUES (" . $u['id'] . ", '" . $link->real_escape_string($u['firstname']) . "', '" . $link->real_escape_string($u['lastname']) . "', '" . $u['avatar'] . "', '" . $u['email'] . "', '" . $link->real_escape_string($u['user']) . "')";

        $result=$link->query($query) or die("DB Error: " . mysqli_error());
        
        // insert join user-group 
        $query = 'INSERT into jn_group_user (groupID, userID, offset) ';
        $query .= "VALUES (" . $gp['id'] . ", " . $u['id'] . ", " . $u['offset'] . ")";
        $result=$link->query($query) or die("DB Error: " . mysqli_error());

        // insert additional details
        insertUserDetails($link, $u['id']);
      }
    }
  }

	mysqli_close($link);
}

function insertUserDetails($link, $id){
  $userDetails = getUserData($id);
  $u = $userDetails['result'];

    echo '<br />insertDetails for ' . $u['id'];
	  $query = 'INSERT IGNORE into user_details (userID, gender, birthdate, cellphone, phone, website, occupation, address1, address2, city, state, country, language, description, created, lastlogin, random1, random2, geo_latitude, geo_longitude, active)';
    $query .= " VALUES (" . $u['id'] . ", 
      'F' , '" .
      $link->real_escape_string($u['birthdate']) . "', '" . 
      $link->real_escape_string($u['cellphone']) . "', '" . 
      $link->real_escape_string($u['phone']) . "', '" . 
      $link->real_escape_string($u['website']) . "', '" . 
      $link->real_escape_string($u['occupation']) . "', '" . 
      $link->real_escape_string($u['address1'])  . "', '" . 
      $link->real_escape_string($u['address2'])  . "', '" . 
      $link->real_escape_string($u['city'])  . "', '" . 
      $link->real_escape_string($u['state'])  . "', '" . 
      $link->real_escape_string($u['country'])  . "', '" . 
      $link->real_escape_string($u['language'])  . "', '" . 
      $link->real_escape_string($u['description'])  . "', '" . 
      $link->real_escape_string($u['created'])  . "', '" . 
      $link->real_escape_string($u['lastlogin'])  . "', '" . 
      $link->real_escape_string($u['random1'])  . "', '" . 
      $link->real_escape_string($u['random2']) . "', '" . 
      $link->real_escape_string($u['geo_latitude'])  . "', '" . 
      $link->real_escape_string($u['geo_longitude']) . "', '" . 
      $link->real_escape_string($u['active']) . 
    "')";

   $result=$link->query($query) or die("DB Error: " . mysqli_error());
    echo '<br />insertMetadata for ' . $u['id'];
    $query = 'INSERT IGNORE into user_metadata (userID, twitter, height, measurement, weight, eyeColor, hairColor, profession, relationshipStatus, favSportsTeam, favActor, karaokeSong, firstJob, piercingTattoos, superPower, pickupLine, craziestThing, unusualHookup, somethingFree, comfortableOutfit, amazingRomp, rules, lang, fbconnect)';
    $query .= " VALUES (" . $u['id'] . ", '" . 
      $link->real_escape_string($u['meta']['twitter']) . "', '" . 
      $link->real_escape_string($u['meta']['height']) . "', '" . 
      $link->real_escape_string($u['meta']['measurement']) . "', '" . 
      $link->real_escape_string($u['meta']['weight']) . "', '" . 
      $link->real_escape_string($u['meta']['eyeColor']) . "', '" . 
      $link->real_escape_string($u['meta']['hairColor'])  . "', '" . 
      $link->real_escape_string($u['meta']['profession'])  . "', '" . 
      $link->real_escape_string($u['meta']['relationshipStatus'])  . "', '" . 
      $link->real_escape_string($u['meta']['favSportsTeam'])  . "', '" . 
      $link->real_escape_string($u['meta']['favActor'])  . "', '" . 
      $link->real_escape_string($u['meta']['karaokeSong'])  . "', '" . 
      $link->real_escape_string($u['meta']['firstJob'])  . "', '" . 
      $link->real_escape_string($u['meta']['piercingTattoos'])  . "', '" . 
      $link->real_escape_string($u['meta']['superPower'])  . "', '" . 
      $link->real_escape_string($u['meta']['pickupLine'])  . "', '" . 
      $link->real_escape_string($u['meta']['craziestThing']) . "', '" . 
      $link->real_escape_string($u['meta']['unusualHookup'])  . "', '" . 
      $link->real_escape_string($u['meta']['somethingFree']) . "', '" . 
      $link->real_escape_string($u['meta']['comfortableOutfit']) . "', '" . 
      $link->real_escape_string($u['meta']['amazingRomp']) . "', '" . 
      $link->real_escape_string($u['meta']['rules']) . "', '" . 
      $link->real_escape_string($u['meta']['lang']) . "', '" . 
      $link->real_escape_string($u['meta']['fbconnect']) . 
    "')";

    $result=$link->query($query) or die("DB Error: " . mysqli_error());

}


function getGroups(){
  $params = array(
    'method' => 'groups.getGroups',
    'sort' => 'treeleft ASC',
  );
  $data = getData($params);
  return $data;
}
 
function getGroupData($groupID){
  $params = array(
    'method' => 'groups.getGroup',
    'groupId' => $groupID,
  );
  $data = getData($params);

  print_r($data);
}

function getUsersInGroup($groupID){
  $params = array(
    'method' => 'users.getUsers',
    'limit' => 1000,
    'filters' => array(
      'groupid' => $groupID,
    )
  );
  $data = getData($params);
  //print_r($data);
  return $data;
}

function getUserData($id){
  $params = array(
    'method' => 'users.getUserInfo',
    'id' => $id,
  );
  $data = getData($params);
  //print_r($data);
  return $data;
}

function insertGroupsIntoDB(){
  $data = getGroups();
  
	$link = new mysqli('localhost', 'maximdev', 'maxim', 'filemobile') or die('Error');

  foreach($data['result'] as $gp){
    print_r($gp);
	  $query = 'insert into groups (groupID, name, description, created, createdBy)';
    $query .= " VALUES (" . $gp['id'] . ", '" . $gp['name'] . "', '" . $gp['description'] . "', '" . $gp['created'] . "', '" . $gp['createdBy'] . "')";

	  $result=$link->query($query) or die("DB Error");
  }

	mysqli_close($link);
}


function getData($params){
  $api_key = '44df868f35142e2ceab80b039e263256';
  $api_url = 'http://www.filemobile.com/services/php?';

  $params['phpVersion'] = 5;
  $params['vhost'] = 509;
  $params['APIKEY'] = $api_key;

  $url = $api_url . http_build_query($params,null,'&');

  //echo 'url: ' . $url . '<br />';
  // Get data
  $data = file_get_contents($url);

  // Change the structure back to a PHP structure
  $data = unserialize($data);
  return $data;
}

