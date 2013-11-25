<?php
// $Id$

function _hth_voting_resource_retreive ($nid, $uid, $campaign) {
  // to leverage exisitng code
  $vote_data = array(
    "nid" => $nid,
    "uid" => $uid,
    "vc" => $campaign
  );
  
  $validated_data = _validate_incoming_data($vote_data, 'retreive');
  
  return($validated_data);
}

function _hth_voting_resource_create($vote_data) {
  $validated_data = _validate_incoming_data($vote_data, 'create');
  
  return($validated_data);
}


function _validate_incoming_data ($vote_data, $type) {
  $curr_hth_week = variable_get('hth_contest_week', 0);
  $curr_hth_status = variable_get('hth_contest_status', 'break');
  
  $vote_data['campaign'] = (isset($vote_data['campaign'])) ? $vote_data['campaign'] : '';
  $vote_data['uid'] = _process_uuid ($vote_data);
 
  if ($curr_hth_status == 'break') {
    return(array('statusCode' => 1, 'statusMsg' => 'Contest not active'));
  }
  if ($curr_hth_week === 'semi_finals' || $curr_hth_week === 'finals') {
    if (!_hottie_in_finals($curr_hth_week, $vote_data)) {
      return(array('statusCode' => 1, 'statusMsg' => "hth not in round:$curr_hth_week"));
    }
  }

  if ($vote_data['uid'] == -1) {
    $return = array ('statusCode' => 2, 'statusMsg' => 'missing maxim uid');
  }
  elseif ($vote_data['uid'] == -2) {
     $return = array('statusCode' => 2, 'statusMsg' => 'invalid maxim uid');
  }
  elseif (!isset($vote_data['nid'])) {
     $return = array('statusCode' => 2, 'statusMsg' => 'missing hth nid');
  }
  elseif (!is_numeric($vote_data['nid'])) {
     $return = array('statusCode' => 2, 'statusMsg' => 'non-numeric maxim nid');
  }
  elseif (_voting_year_ended($vote_data)) {
     $return = array('statusCode' => 1, 'statusMsg' => 'voting year finished');
  }
  elseif (_voting_week_ended($vote_data)) {
    $return = array('statusCode' => 1, 'statusMsg' => 'hth voting week finished');
  }
  elseif (_voting_limit_reached($vote_data)) {
     $return = array('statusCode' => 1, 'statusMsg' => 'voting limit reached');
  }
  else {
     if ($type == 'retreive') {
       $return = array('statusCode' => 0, 'statusMsg' => 'voting allowed');
     }
     elseif ($type == 'create') {
       $return = _hth_voting_resource_write_vote($vote_data);
     }
  }
  $return_val['items'] = $return;
  
  return($return_val);
}

function _voting_limit_reached($vote_data) {
  $timenow = time();
  $time_limit = 43200; // 12 hours in seconds
  
  $sql = 'SELECT timestamp FROM {votingapi_vote} WHERE uid = :curuid AND entity_id = :nid ORDER BY vote_id DESC LIMIT 1';
  $params = array(':curuid' => $vote_data['uid'], ':nid' => $vote_data['nid']);
  $result = db_query($sql,$params)->fetchObject();
  
  if ($result) {
     if (($timenow - $result->timestamp) < $time_limit) {
       return true;
     }
     else {
      return false;
     }
  }
  else {
    //no vote by that user for that nid has ever been cast
    return false;
  }
}

function _hottie_in_finals($curr_week, $vote_data) {
  $nq = ($curr_week == 'semi_finals') ? 'hth_2014_semi_finals' : 'hth_2014_finals';

  $sql = 'SELECT n.position ';
  $sql .= 'FROM {nodequeue_nodes} n, {nodequeue_queue} q, {nodequeue_subqueue} sq ';
  $sql .= 'WHERE q.qid = sq.qid AND sq.sqid = n.sqid AND n.qid = q.qid AND n.nid = :nid AND q.name = :nq';
  $params = array(':nid' =>  $vote_data['nid'], ':nq' => $nq);

  $result = db_query($sql,$params)->fetchObject();
  
  if ($result) {
    return(true);
  }
  else {
    return(false);
  }
}

function _voting_week_ended($vote_data) {
  $hth_contest_week = variable_get('hth_contest_week', 0);
  
  if (variable_get('hth_contest_status', 0) == 'break') {
    return true;
  }
  
  $sql = 'SELECT t.name FROM {taxonomy_term_data} t LEFT OUTER JOIN {field_data_field_hotties_contest_week} w ON t.tid = w.field_hotties_contest_week_tid WHERE w.entity_id = :nid';
  $params = array(':nid' => $vote_data['nid']);
  $dbresult = db_query($sql,$params);
  
  foreach($dbresult as $row) {
    if (($hth_contest_week == 'semi-finals') && ($row->name == 'Semifinalist')) {
      return (false);
    }
    elseif (($hth_contest_week == 'finals') && ($row->name == 'Finalists')) {
      return (false);
    }
    elseif ($row->name == variable_get('hth_contest_week', 0)) {
      return (false);
    }
  }
  
  return (true);
}

function _voting_year_ended($vote_data) {
  // we use db_query() for speed.
  $sql = 'SELECT t.name FROM {taxonomy_term_data} t LEFT OUTER JOIN {field_data_field_hotties_contest_year} y ON t.tid = y.field_hotties_contest_year_tid WHERE y.entity_id = :nid';
  $params = array(':nid' => $vote_data['nid']);
  $result = db_query($sql,$params)->fetchObject();

  $hottie_year = ($result) ? $result->name : '';
  
  if ($hottie_year != variable_get('hth_contest_year', 0)) {
    return true;
  }
  else {
    return false;
  }
}

function _get_uuid ($data) {
  $str_data = _hexToStr($data);
  $decrypted_data = _decrypt_uid($str_data);
  $_is_valid_uuid = _is_valid_uuid ($decrypted_data);

  if ($_is_valid_uuid) {
    return($decrypted_data);
  }
  else {
    return(-1);
  }
}

function _is_valid_uuid ($uuid) {
  $pattern = "#^[a-f0-9]{8}-[a-f0-9]{4}-[a-f0-9]{4}-[a-f0-9]{4}-[a-f0-9]{12}$#";
  $res = preg_match($pattern, $uuid);

  return ($res);
}

function _decrypt_uid($str) {
  $ky = 'm@x1m_p@55w0rd';
  if($ky == '') {
    return $str;
  }
  $ky = str_replace(chr(32),'',$ky);
  if(strlen($ky) < 8) {
    exit('key error');
  }
  $kl = strlen($ky) < 32 ? strlen($ky) : 32;
  $k=array();
  for($i = 0;$i < $kl;$i++) {
    $k[$i] = ord($ky{$i})&0x1F;
  }
  $j=0;
  for($i = 0;$i < strlen($str);$i++) {
    $e=ord($str{$i});
    $str{$i}=$e&0xE0?chr($e^$k[$j]):chr($e);
    $j++;
    $j=$j==$kl?0:$j;
  }
  return $str;
}

function _hexToStr($hex) {
  $string='';

  for ($i=0; $i < strlen($hex)-1; $i+=2) {
    $string .= chr(hexdec($hex[$i].$hex[$i+1]));
  }

  return $string;
}

function _process_uuid($vote_data) {
  if (!isset($vote_data['uid'])) {
    return (-1);
  }
  $uuid = _get_uuid($vote_data['uid']);
  if ($uuid === -1) {
    return (-2);
  }
  else {
    //return ($uuid);
    $u = explode('-', $uuid);
    return substr(hexdec($u[0]),0,9);
  }
}

function _hth_voting_resource_write_vote($vote_data) {
  $vote = array();
  $criteria = array();
  $curr_hth_week = variable_get('hth_contest_week', 0);
  $curr_hth_year = variable_get('hth_contest_year', 0);

  if ($curr_hth_week === 'semi-finals' || $curr_hth_week === 'finals') {
    $tag = 'hth-vote-'.$curr_hth_week.'-'.$curr_hth_year;
  }
  else {
    $tag = 'hth_vote_'.$curr_hth_year;
  }

  $vote['entity_type'] = 'node';
  $vote['value_type'] = 'points';
  $vote['entity_id'] = $vote_data['nid'];
  $vote['value'] = 1;
  $vote['uid'] = $vote_data['uid'];
  $vote['tag'] = $tag;

  $votingapi_set_votes = votingapi_set_votes($vote, $criteria);

  if (is_array($votingapi_set_votes)) {
    if ($vote_data['campaign'] == 'bb') {
      $field_name = "hth_count_$curr_hth_year";
   
      db_update('blackberry_data')->expression("$field_name", "$field_name + :inc", array(':inc' => 1))->execute();
      
      return (array ('statusCode' => 0, 'statusMsg' => 'vote recorded', 'voteMsg' => 'Thanks! Come back and vote for me again tomorrow!'));
    }
    
    return (array ('statusCode' => 0, 'statusMsg' => 'vote recorded'));
  }
  else {
    return (array ('statusCode' => 1, 'statusMsg' => 'error: could not record vote'));
  }
}

