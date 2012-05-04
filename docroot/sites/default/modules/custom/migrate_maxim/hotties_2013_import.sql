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

INSERT INTO migrate_hotties_2013
    SELECT `parent`.`sid` AS `sid`,
            `s`.`uid` AS `uid`,
            `s`.`is_draft` AS `is_draft`,         
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 46))) AS `photo_1`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 47))) AS `photo_2`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 52))) AS `photo_4`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 51))) AS `photo_3`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 53))) AS `photo_5`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 54))) AS `photo_6`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 55))) AS `photo_7`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 56))) AS `photo_8`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 57))) AS `photo_9`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 58))) AS `photo_10`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 75))) AS `entry_slotting`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 76))) AS `fb_referrer`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 78))) AS `contest_week`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 9))) AS `hometown`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 10))) AS `date_of_birth`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 12))) AS `phone_number`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 11))) AS `email_address`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 3))) AS `first_name`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 4))) AS `last_name`,

            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 5))) AS `address`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 6))) AS `state`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 7))) AS `city`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 8))) AS `zip_code`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 13))) AS `twitter_handle`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 14))) AS `facebook_id`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 15))) AS `resident_status`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 21))) AS `height`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 22))) AS `weight`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 23))) AS `measurements`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 25))) AS `profession`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 26))) AS `first_job`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 27))) AS `karaoke_song`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 28))) AS `favorite_sport_team`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 29))) AS `favorite_movie_actor`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 30))) AS `piercings_tattoos`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 31))) AS `mac_or_pc`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 32))) AS `gaming_prefs`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 33))) AS `talents`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 34))) AS `best_pick_up_line`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 35))) AS `craziest_thing`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 36))) AS `hookup_place`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 37))) AS `whats_in_pocket`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 38))) AS `most_comfortable_wearing`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 39))) AS `sex_pref`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 48))) AS `relationship_status`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 63))) AS `read_rules`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 64))) AS `rules_policy`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 65))) AS `photo_rights`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 66))) AS `additional_info`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 72))) AS `cuervo_shot`,
            (select group_concat(`child`.`data` separator ',') AS `GROUP_CONCAT(data)` from `webform_submitted_data` `child` where ((`child`.`sid` = `parent`.`sid`) and (`child`.`cid` = 77))) AS `referral_code`,
              from_unixtime(`s`.`submitted`) AS `submitted`,`s`.`remote_addr` AS `remote_addr` 
         FROM (`webform_submitted_data` `parent` JOIN `webform_submissions` `s` ON((`s`.`sid` = `parent`.`sid`))) 
        WHERE (`parent`.`nid` = 36876)
     GROUP BY `parent`.`sid` 
     ORDER BY `parent`.`sid` DESC;

select * from migrate_hotties_2013 where contest_week is not null;


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
  `rank` int(11) DEFAULT '0',
  PRIMARY KEY (`fid`),
  UNIQUE KEY `fid_UNIQUE` (`fid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

INSERT IGNORE INTO migrate_hotties_files_2013
    SELECT h.sid, fm.fid, fm.filename, fm.uri, fm.filemime, fm.filesize, fm.status, fm.timestamp, fm.type, 1
    FROM migrate_hotties_2013 h
    LEFT JOIN file_managed fm on fm.fid = h.photo_1
    WHERE h.entry_slotting = 'YES'
    and h.contest_week is not null; 
INSERT IGNORE INTO migrate_hotties_files_2013
    SELECT h.sid, fm.fid, fm.filename, fm.uri, fm.filemime, fm.filesize, fm.status, fm.timestamp, fm.type, 2
    FROM migrate_hotties_2013 h
    LEFT JOIN file_managed fm on fm.fid = h.photo_2
    WHERE h.entry_slotting = 'YES'
    and h.contest_week is not null; 
INSERT IGNORE INTO migrate_hotties_files_2013
    SELECT h.sid, fm.fid, fm.filename, fm.uri, fm.filemime, fm.filesize, fm.status, fm.timestamp, fm.type, 3
    FROM migrate_hotties_2013 h
    LEFT JOIN file_managed fm on fm.fid = h.photo_3
    WHERE h.entry_slotting = 'YES'
    and h.contest_week is not null; 
INSERT IGNORE INTO migrate_hotties_files_2013
    SELECT h.sid, fm.fid, fm.filename, fm.uri, fm.filemime, fm.filesize, fm.status, fm.timestamp, fm.type, 4
    FROM migrate_hotties_2013 h
    LEFT JOIN file_managed fm on fm.fid = h.photo_4
    WHERE h.entry_slotting = 'YES'
    and h.contest_week is not null; 
INSERT IGNORE INTO migrate_hotties_files_2013
    SELECT h.sid, fm.fid, fm.filename, fm.uri, fm.filemime, fm.filesize, fm.status, fm.timestamp, fm.type, 5
    FROM migrate_hotties_2013 h
    LEFT JOIN file_managed fm on fm.fid = h.photo_5
    WHERE h.entry_slotting = 'YES'
    and h.contest_week is not null; 
INSERT IGNORE INTO migrate_hotties_files_2013
    SELECT h.sid, fm.fid, fm.filename, fm.uri, fm.filemime, fm.filesize, fm.status, fm.timestamp, fm.type, 6
    FROM migrate_hotties_2013 h
    LEFT JOIN file_managed fm on fm.fid = h.photo_6
    WHERE h.entry_slotting = 'YES'
    and h.contest_week is not null; 
INSERT IGNORE INTO migrate_hotties_files_2013
    SELECT h.sid, fm.fid, fm.filename, fm.uri, fm.filemime, fm.filesize, fm.status, fm.timestamp, fm.type, 7
    FROM migrate_hotties_2013 h
    LEFT JOIN file_managed fm on fm.fid = h.photo_7
    WHERE h.entry_slotting = 'YES'
    and h.contest_week is not null; 
INSERT IGNORE INTO migrate_hotties_files_2013
    SELECT h.sid, fm.fid, fm.filename, fm.uri, fm.filemime, fm.filesize, fm.status, fm.timestamp, fm.type, 8
    FROM migrate_hotties_2013 h
    LEFT JOIN file_managed fm on fm.fid = h.photo_8
    WHERE h.entry_slotting = 'YES'
    and h.contest_week is not null; 
INSERT IGNORE INTO migrate_hotties_files_2013
    SELECT h.sid, fm.fid, fm.filename, fm.uri, fm.filemime, fm.filesize, fm.status, fm.timestamp, fm.type, 9
    FROM migrate_hotties_2013 h
    LEFT JOIN file_managed fm on fm.fid = h.photo_9
    WHERE h.entry_slotting = 'YES'
    and h.contest_week is not null; 
INSERT IGNORE INTO migrate_hotties_files_2013
    SELECT h.sid, fm.fid, fm.filename, fm.uri, fm.filemime, fm.filesize, fm.status, fm.timestamp, fm.type, 10
    FROM migrate_hotties_2013 h
    LEFT JOIN file_managed fm on fm.fid = h.photo_10
    WHERE h.entry_slotting = 'YES'
    and h.contest_week is not null; 

# Remove text from weights
select distinct weight from migrate_hotties_2013;
update migrate_hotties_2013 set weight = replace(lower(weight), 'lbs', '');
update migrate_hotties_2013 set weight = replace(lower(weight), 'ibs', '');
update migrate_hotties_2013 set weight = replace(lower(weight), 'lb', '');
update migrate_hotties_2013 set weight = replace(lower(weight), 'pounds', '');
update migrate_hotties_2013 set weight = replace(lower(weight), '#', '');
update migrate_hotties_2013 set weight = replace(lower(weight), ' .', '');
update migrate_hotties_2013 set weight = trim(weight);


# Hotties nodequeue
SELECT @i:=0;
SELECT @wk:='hth_2013_contestants_week_1';
INSERT INTO nodequeue_nodes 
SELECT 
    (select qid from nodequeue_queue where name=@wk) as qid, 
    (select sqid from nodequeue_subqueue where title=@wk) as sqid,
    w.entity_id as nid, 
    @i:=@i+1 AS position,
    unix_timestamp(now())
FROM field_data_field_hotties_contest_week w
LEFT JOIN field_data_field_hotties_contest_year y ON y.entity_id=w.entity_id
LEFT JOIN field_data_field_profile_first_name n ON n.entity_id = w.entity_id
WHERE 
y.field_hotties_contest_year_tid = (
    select d.tid from taxonomy_term_data d 
    left join taxonomy_vocabulary v on v.vid=d.vid
    where v.machine_name='hotties_contest_year'
    and d.name='2013'
)
AND
w.field_hotties_contest_week_tid = (
    select d.tid from taxonomy_term_data d 
    left join taxonomy_vocabulary v on v.vid=d.vid
    where v.machine_name='hotties_contest_week'
    and d.name=1
)
ORDER BY n.field_profile_first_name_value ASC;