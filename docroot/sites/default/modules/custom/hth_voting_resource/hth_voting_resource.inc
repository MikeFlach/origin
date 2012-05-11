<?php
// $Id$

function _hth_voting_resource_create($vote_data) {
  return (1);
  $error = false;

  if (!isset($vote_data['nid'])) {
    return services_error('Missing hottie nid', 406);
  }

  if (!isset($vote_data['uid'])) {
    return services_error('Missing uid', 40);
  }

  $uuid = process_uuid($vote_data['uid']);
  if ($uuid === -1) {
    return services_error('Invalid UserID', 406);
  }
  else {
    $vote_data['uid'] = $uuid;
  }

  if (voting_limit_reached($vote_data)) {
    return services_error('Voting Limit Reached', 406);
  }

  if (voting_week_ended($vote_data)) {
    return services_error('Voting Week Finished', 406);
  }

  if (voting_year_ended($vote_data)) {
    return services_error('Voting Year Finished', 406);
  }

  hth_voting_resource_write_vote($vote_data);
}

function _hth_voting_resource_retrieve($nid) {
  return (-666);
  //return hth_voting_resource_get_vote_count($nid);
}

function voting_limit_reached($vote_data) {
  $timenow = time();
  $readytovote = 0;

  $result = db_query("SELECT timestamp FROM {votingapi_vote} WHERE uid = :curuid AND entity_id = :nid ORDER BY vote_id DESC LIMIT 1", array(':curuid' => $vote_data['uid'], ':nid' => $vote_data['nid']));

  foreach ($result as $data) {}
  if (isset($data)) {
    $timeago = $data->timestamp;
  }

  if (($timenow - $timeago) < 86400) {
    return true;
  }
  else {
    return false;
  }
}

function voting_week_ended($vote_data) {
  $result = db_query("SELECT t.name FROM taxonomy_term_data t LEFT OUTER JOIN field_data_field_hotties_contest_week w ON t.tid = w.field_hotties_contest_week_tid WHERE w.entity_id = :nid", array(':nid' => $vote_data['nid']));

  foreach ($result as $data) {}
  if (isset($data)) {
    $hottie_week = $data->name;
  }

  if ($hottie_week != variable_get('hth_contest_week', 0)) {
    return true;
  }
  else {
    return false;
  }
}

function voting_year_ended($vote_data) {
  $result = db_query("SELECT t.name FROM taxonomy_term_data t LEFT OUTER JOIN field_data_field_hotties_contest_year y ON t.tid = y.field_hotties_contest_year_tid WHERE y.entity_id = :nid", array(':nid' => $vote_data['nid']));

  foreach ($result as $data) {}
  if (isset($data)) {
    $hottie_year = $data->name;
  }

  if ($hottie_year != variable_get('hth_contest_year', 0)) {
    return true;
  }
  else {
    return false;
  }
}

function process_uuid ($data) {
  $decrypted_data = decrypt_uuid($data);
  $is_valid_uuid = is_valid_uuid ($decrypted_data);

  if ($is_valid_uuid) {
    return($decrypted_data);
  }
  else {
    return(-1);
  }
}

function is_valid_uuid ($uuid) {
  $pattern = "#^[a-f0-9]{8}-[a-f0-9]{4}-[a-f0-9]{4}-[a-f0-9]{4}-[a-f0-9]{12}$#";
  $res = preg_match($pattern, $uuid);

  return ($res);
}

function decrypt_uuid($enc_uuid) {
  $password = 'm@x1m_p@55w0rd';

  $data = base64_decode($enc_uuid);
  $salt = substr($data, 8, 8);
  $ct = substr($data, 16);

  $rounds = 3;
  $data00 = $password.$salt;
  $md5_hash = array();
  $md5_hash[0] = md5($data00, true);
  $result = $md5_hash[0];
  for ($i = 1; $i < $rounds; $i++) {
    $md5_hash[$i] = md5($md5_hash[$i - 1].$data00, true);
      $result .= $md5_hash[$i];
  }
  $key = substr($result, 0, 32);
  $iv  = substr($result, 32,16);

  return openssl_decrypt($ct, 'aes-256-cbc', $key, true, $iv);
  }
