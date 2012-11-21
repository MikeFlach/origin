<?php
// $Id$

function _generic_multivote_resource_retreive($composit_data) {
  $data = explode("~", $composit_data);
  $vote_data = array(
    "campaign" => $data[0],
    "uid" => $data[1],
  );

  $vote_data['uid'] = _process_uuid($vote_data);
  if ($vote_data['uid'] != '0') {
    if ($vote_data['uid'] == -1) {
      return ('invalid-uuid');
    }
    
    $vote_data['settings_data'] = _generic_mv_settings($vote_data['campaign']);
    return(_get_current_votes($vote_data));
  }
  else {
    return ('missing-uuid');
  }
}

function _generic_multivote_resource_create($vote_data) {
  $vote_data['uid'] = _process_uuid ($vote_data);
  if ($vote_data['uid'] != '0') {
    if ($vote_data['uid'] == -1) {
      return ('invalid-uuid');
    }

    if (!isset($vote_data['nid'])) {
      return ('missing-nid');
    }

     if (!is_numeric($vote_data['nid'])) {
      return ('non-numeric-nid');
    }
    
    $vote_data['settings_data'] = _generic_mv_settings($vote_data['campaign']);
    if (_voting_limit_reached($vote_data)) {
      return('limit-reached');
    }
  }
  else {
    return ('missing-uuid');
  }

  return(generic_multivote_resource_write_vote($vote_data));
}

function _voting_limit_reached($vote_data) {  
  if ($vote_data['settings_data']['limit_type'] != 'none') {
    $timenow = time();
    $time_limit = _get_time_limit($vote_data['settings_data']['limit_type']);
    
    $sql = 'SELECT timestamp FROM {votingapi_vote} WHERE tag = :campaign AND uid = :curuid AND entity_id = :nid ORDER BY vote_id DESC LIMIT 1';
    $params = array(':curuid' => $vote_data['uid'], ':nid' => $vote_data['nid'], ':campaign' => $vote_data['settings_data']['voting_api_tag']);
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
}

function _get_current_votes($vote_data) {  
  if ($vote_data['settings_data']['limit_type'] != 'none') {
    $time_limit = _get_time_limit($vote_data['settings_data']['limit_type']);
    $end_time = time();
    $begin_time = $end_time - $time_limit;

    $sql = 'SELECT entity_id FROM {votingapi_vote} WHERE tag = :campaigntag AND uid = :curuid and timestamp > :begintime and timestamp < :endtime';
    $params = array(':curuid' => $vote_data['uid'], ':campaigntag' => $vote_data['settings_data']['voting_api_tag'], ':begintime' => $begin_time, ':endtime' => $end_time);
    $result = db_query($sql,$params);
    
    $votes = array();
    foreach ($result as $record) {
      array_push($votes,  intval($record->entity_id));
    }
    
    return ($votes);
  }
}

 function _get_time_limit ($limit_type) {
   if ($limit_type === 'daily') {
     //return 12 hours in seconds.
     return (43200);
   }
   else {
     return (0);
   }
 }

function _get_uuid ($data) {
  $str_data = _hexToStr($data);
  $decrypted_data = _decrypt_uuid($str_data);
  $is_valid_uuid = _is_valid_uuid ($decrypted_data);

  if ($is_valid_uuid) {
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

function _decrypt_uuid($str) {
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

function _hexToStr($hex) {
  $string='';

  for ($i=0; $i < strlen($hex)-1; $i+=2) {
    $string .= chr(hexdec($hex[$i].$hex[$i+1]));
  }

  return $string;
}

function _process_uuid($vote_data) {
  if (!isset($vote_data['uid'])) {
    return (0);
  }
  $uuid = _get_uuid($vote_data['uid']);
  if ($uuid === -1) {
    return (0);
  }
  else {
    //return ($uuid);
    $u = explode('-', $uuid);
    return substr(hexdec($u[0]),0,9);
  }
}

function generic_multivote_resource_write_vote($vote_data) {
  $vote = array();
  $criteria = array();

  $vote['entity_type'] = 'node';
  $vote['value_type'] = 'points';
  $vote['entity_id'] = $vote_data['nid'];
  $vote['value'] = 1;
  $vote['uid'] = $vote_data['uid'];
  $vote['tag'] = $vote_data['settings_data']['voting_api_tag'];

  $votingapi_set_votes = votingapi_set_votes($vote, $criteria);

  if (is_array($votingapi_set_votes)) {
    return ('vote_entered::nid='.$vote_data['nid']);
  }
  else {
    return ('error_adding_vote');
  }
}
