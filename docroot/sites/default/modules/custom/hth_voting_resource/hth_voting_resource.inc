<?php
// $Id$

function _hth_voting_resource_retreive($composit_data) {
  $data = explode("~", $composit_data);
  $vote_data = array(
    "nid" => $data[0],
    "uid" => $data[1],
  );

  $vote_data['uid'] = process_uuid ($vote_data);
  if ($vote_data['uid'] != 0) {
    return(check_voting_data($vote_data));
  }
  else {
    return ('missing_uuid');
  }
}

function _hth_voting_resource_create($vote_data) {
  $vote_data['uid'] = process_uuid ($vote_data);
  if ($vote_data['uid'] != 0) {
    return(check_voting_data($vote_data));
  }
  else {
    return ('missing_uuid');
  }
  $chk_res = check_voting_data($vote_data);

  if ($chk_res == 'no_vote_entered') {
    $vote_res = hth_voting_resource_write_vote($vote_data);
    return($vote_res);
  }
  else {
    return ($chk_res);
  }
}

function check_voting_data (array $vote_data) {
  if ($vote_data['uid'] == -1) {
    return ('invalid_uuid');
  }

  if (!isset($vote_data['nid'])) {
    return ('missing_hottie_nid');
  }

  if (voting_year_ended($vote_data)) {
    return ('voting_year_finished');
  }

  if (voting_week_ended($vote_data)) {
    return ('voting_week_finished');
  }

  if (voting_limit_reached($vote_data)) {
    return('limit_reached');
  }
  else {
    return('no_vote_entered');
  }
}

function voting_limit_reached($vote_data) {
  $timenow = time();
  $readytovote = 0;

  $result = db_query("SELECT timestamp FROM {votingapi_vote} WHERE uid = :curuid AND entity_id = :nid ORDER BY vote_id DESC LIMIT 1", array(':curuid' => $vote_data['uid'], ':nid' => $vote_data['nid']));

  $timeago = $timenow - 500000;
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

function get_uuid ($data) {
  $str_data = hexToStr($data);
  $decrypted_data = decrypt_uuid($str_data);
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

function decrypt_uuid($str) {
  $ky = 'm@x1m_p@55w0rd';
  if($ky=='')return $str;
  $ky=str_replace(chr(32),'',$ky);
  if(strlen($ky)<8)exit('key error');
  $kl=strlen($ky)<32?strlen($ky):32;
  $k=array();for($i=0;$i<$kl;$i++){
  $k[$i]=ord($ky{$i})&0x1F;}
  $j=0;for($i=0;$i<strlen($str);$i++){
  $e=ord($str{$i});
  $str{$i}=$e&0xE0?chr($e^$k[$j]):chr($e);
  $j++;$j=$j==$kl?0:$j;}
  return $str;
}

function hexToStr($hex) {
  $string='';

  for ($i=0; $i < strlen($hex)-1; $i+=2) {
    $string .= chr(hexdec($hex[$i].$hex[$i+1]));
  }

  return $string;
}

function process_uuid($vote_data) {
  if (!isset($vote_data['uid'])) {
    return (0);
  }
  $uuid = get_uuid($vote_data['uid']);
  if ($uuid === -1) {
    return (0);
  }
  else {
    return ($uuid);
  }
}

function hth_voting_resource_write_vote($vote_data) {
  $vote = array();
  $criteria = array();

  $vote['entity_type'] = 'node';
  $vote['value_type'] = 'points';
  $vote['entity_id'] = $vote_data['nid'];
  $vote['value'] = 1;
  $vote['uid'] = $vote_data['uid'];
  $vote['tag'] = 'vote';

  $votingapi_set_votes = votingapi_set_votes($vote, $criteria);

  if (is_array($votingapi_set_votes)) {
    return ('vote_entered');
  }
  else {
    return ('error_adding_vote');
  }
}
