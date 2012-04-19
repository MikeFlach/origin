<?php

if (!isset($_GET['action'])) {
  die('No action defined.');
}

switch($_GET['action']){
  case 'initTables':
    createHottiesTables();
  break;
  case 'hottiesImages':
    hottiesImages();
  break;
}

function createHottiesTables(){
  
  echo 'create tables';
  $mysqli = new mysqli('localhost', 'maximdev', 'maxim', 'maximdev') or die('Error');

  $query=<<<QUERY
  CREATE TABLE `migrate_hotties_2013` (
    `sid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'The unique identifier for this submission.',
    `uid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'The id of the user that completed this submission.',
    `is_draft` tinyint(4) NOT NULL DEFAULT '0' COMMENT 'Is this a draft of the submission?',
    `photo_1` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `photo_2` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `photo_4` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `photo_3` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `photo_5` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `photo_6` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `photo_7` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `photo_8` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `photo_9` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `photo_10` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `entry_slotting` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `fb_referrer` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `contest_week` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `hometown` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `date_of_birth` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `phone_number` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `email_address` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `first_name` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `last_name` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `address` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `state` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `city` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `zip_code` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `twitter_handle` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `facebook_id` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `resident_status` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `height` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `weight` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `measurements` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `profession` text CHARACTER SET utf8 DEFAULT NULL,
    `first_job` text CHARACTER SET utf8 DEFAULT NULL,
    `karaoke_song` text CHARACTER SET utf8 DEFAULT NULL,
    `favorite_sport_team` text CHARACTER SET utf8 DEFAULT NULL,
    `favorite_movie_actor` text CHARACTER SET utf8 DEFAULT NULL,
    `piercings_tattoos` text CHARACTER SET utf8 DEFAULT NULL,
    `mac_or_pc` text CHARACTER SET utf8 DEFAULT NULL,
    `gaming_prefs` text CHARACTER SET utf8 DEFAULT NULL,
    `talents` text CHARACTER SET utf8 DEFAULT NULL,
    `best_pick_up_line` text CHARACTER SET utf8 DEFAULT NULL,
    `craziest_thing` text CHARACTER SET utf8 DEFAULT NULL,
    `hookup_place` text CHARACTER SET utf8 DEFAULT NULL,
    `whats_in_pocket` text CHARACTER SET utf8 DEFAULT NULL,
    `most_comfortable_wearing` text CHARACTER SET utf8 DEFAULT NULL,
    `sex_pref` text CHARACTER SET utf8 DEFAULT NULL,
    `relationship_status` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `read_rules` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `rules_policy` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `photo_rights` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `additional_info` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `cuervo_shot` text CHARACTER SET utf8 DEFAULT NULL,
    `referral_code` varchar(342) CHARACTER SET utf8 DEFAULT NULL,
    `submitted` datetime DEFAULT NULL,
    `remote_addr` varchar(128) CHARACTER SET utf8 DEFAULT NULL COMMENT 'The IP address of the user that submitted the form.',
    PRIMARY KEY (`sid`)
  ) ENGINE=MyISAM DEFAULT CHARSET=latin1;
QUERY;
  echo $query;
  $result = $mysqli->query($query);

$query = <<<QUERY
CREATE TABLE `migrate_hotties_files_2013` (
  `sid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'The unique identifier for this submission.',
  `fid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'File ID.',
  `filename` varchar(255) CHARACTER SET utf8 DEFAULT '' COMMENT 'Name of the file with no path components. This may differ from the basename of the URI if the file is renamed to avoid overwriting an existing file.',
  `uri` varchar(255) CHARACTER SET utf8 DEFAULT '' COMMENT 'The URI to access the file (either local or remote).',
  `filemime` varchar(255) CHARACTER SET utf8 DEFAULT '' COMMENT 'The file’s MIME type.',
  `filesize` int(10) unsigned DEFAULT '0' COMMENT 'The size of the file in bytes.',
  `status` tinyint(4) DEFAULT '0' COMMENT 'A field indicating the status of the file. Two status are defined in core: temporary (0) and permanent (1). Temporary files older than DRUPAL_MAXIMUM_TEMP_FILE_AGE will be removed during a cron run.',
  `timestamp` int(10) unsigned DEFAULT '0' COMMENT 'UNIX timestamp for when the file was added.',
  `type` varchar(50) CHARACTER SET utf8 DEFAULT 'undefined' COMMENT 'The type of this file.',
  `order` int(11) DEFAULT '0',
  PRIMARY KEY (`fid`),
  UNIQUE KEY `fid_UNIQUE` (`fid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
QUERY;

  $result = $mysqli->query($query);

  mysqli_close($mysqli); 
  print_r($result);
}

// Insert file metadata into table
function hottiesImages(){
  $query = '';

  $mysqli = new mysqli('localhost', 'maximdev', 'maxim', 'maximdev') or die('Error');
  if (mysqli_connect_errno()) {
     printf("Connect failed: %s\n", mysqli_connect_error());
     exit();
  }

  for($i=1; $i<=10; $i++) {
    $query = "INSERT IGNORE INTO migrate_hotties_files_2013
    SELECT h.sid, fm.fid, fm.filename, fm.uri, fm.filemime, fm.filesize, fm.status, fm.timestamp, fm.type, $i
    FROM maximdev.migrate_hotties_2013 h
    LEFT JOIN file_managed fm on fm.fid = h.photo_$i
    WHERE h.entry_slotting = 'YES'; ";
    //    AND  h.contest_week is not null;
    echo $query . "\n";
    $result = $mysqli->query($query);
    if (!$result) {
       printf("%s\n", $mysqli->error);
       exit();
    }
  }

  mysqli_close($mysqli); 
}



// Extract Hometown Hotties from webform and insert into table
function hottiesFromWebform(){




}
