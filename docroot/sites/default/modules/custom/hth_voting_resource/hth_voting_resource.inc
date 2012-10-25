<?php
// $Id$

function _hth_voting_resource_retreive($composit_data) {
  $curr_hth_week = variable_get('hth_contest_week', 0);

  $data = explode("~", $composit_data);
  $vote_data = array(
    "nid" => $data[0],
    "uid" => $data[1],
  );

  $vote_data['uid'] = process_uuid ($vote_data);
  if ($vote_data['uid'] != '0') {
    if ($vote_data['uid'] == -1) {
      return ('invalid_uuid');
    }

    if (!isset($vote_data['nid'])) {
      return ('missing_hottie_nid');
    }

    if (!is_numeric($vote_data['nid'])) {
      return ('non-numeric_hottie_nid');
    }

    if (voting_year_ended($vote_data)) {
      return ('voting_year_finished');
    }

    //if semis/finals check to make sure hth is in the proper queue, else make sure it's the proper hth week
    if ($curr_hth_week === 'semi_finals' || $curr_hth_week === 'finals') {
      if (!hottie_in_finals($curr_hth_week, $vote_data)) {
        return ('hottie_not_in_'.$curr_hth_week);
      }
    }
    else {
      if (voting_week_ended($vote_data)) {
        return ('voting_week_finished');
      }
    }

    if (voting_limit_reached($vote_data)) {
      return('limit_reached');
    }
    else {
      return('no_vote_entered');
    }
  }
  else {
    return ('missing_uuid');
  }
}

function _hth_voting_resource_create($vote_data) {
  $curr_hth_week = variable_get('hth_contest_week', 0);

  $vote_data['uid'] = process_uuid ($vote_data);
  if ($vote_data['uid'] != '0') {
    if ($vote_data['uid'] == -1) {
      return ('invalid_uuid');
    }

    if (!isset($vote_data['nid'])) {
      return ('missing_hottie_nid');
    }

     if (!is_numeric($vote_data['nid'])) {
      return ('non-numeric_hottie_nid');
    }

    if (voting_year_ended($vote_data)) {
      return ('voting_year_finished');
    }

    //if semis or finals check to make sure hth is in the proper queue, else make sure it's the proper hth week
    if ($curr_hth_week === 'semi_finals' || $curr_hth_week === 'finals') {
      if (!hottie_in_finals($curr_hth_week, $vote_data)) {
        return ('hottie_not_in_'.$curr_hth_week);
      }
    }
    else {
      if (voting_week_ended($vote_data)) {
        return ('voting_week_finished');
      }
    }

    if (voting_limit_reached($vote_data)) {
      return('limit_reached');
    }
  }
  else {
    return ('missing_uuid');
  }

  return(hth_voting_resource_write_vote($vote_data));
}

function voting_limit_reached($vote_data) {
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

function hottie_in_finals($curr_week, $vote_data) {
  $nq = ($curr_week == 'semi_finals') ? 'hth_2013_semi_finals' : 'hth_2013_finals';

  $sql = 'SELECT n.position ';
  $sql .= 'FROM nodequeue_nodes n, nodequeue_queue q, nodequeue_subqueue sq ';
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

function voting_week_ended($vote_data) {
  $sql = 'SELECT t.name FROM taxonomy_term_data t LEFT OUTER JOIN field_data_field_hotties_contest_week w ON t.tid = w.field_hotties_contest_week_tid WHERE w.entity_id = :nid';
  $params = array(':nid' => $vote_data['nid']);
  $result = db_query($sql,$params)->fetchObject();
  
  $hottie_week = ($result) ? $result->name : '';

  if ($hottie_week != variable_get('hth_contest_week', 0)) {
    return true;
  }
  else {
    return false;
  }
}

function voting_year_ended($vote_data) {
  $sql = 'SELECT t.name FROM taxonomy_term_data t LEFT OUTER JOIN field_data_field_hotties_contest_year y ON t.tid = y.field_hotties_contest_year_tid WHERE y.entity_id = :nid';
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

//this function encrypts & decrypts!
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
    //return ($uuid);
    $u = explode('-', $uuid);
    return substr(hexdec($u[0]),0,9);
  }
}

function hth_voting_resource_write_vote($vote_data) {
  $vote = array();
  $criteria = array();
  $curr_hth_week = variable_get('hth_contest_week', 0);

  if ($curr_hth_week === 'semi_finals' || $curr_hth_week === 'finals') {
    $tag = 'vote_'.$curr_hth_week;
  }
  else {
    $tag = 'vote';
  }

  $vote['entity_type'] = 'node';
  $vote['value_type'] = 'points';
  $vote['entity_id'] = $vote_data['nid'];
  $vote['value'] = 1;
  $vote['uid'] = $vote_data['uid'];
  $vote['tag'] = $tag;

  $votingapi_set_votes = votingapi_set_votes($vote, $criteria);

  if (is_array($votingapi_set_votes)) {
    return ('vote_entered');
  }
  else {
    return ('error_adding_vote');
  }
}
