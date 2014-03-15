<?php
// $Id$

function _generic_voting_resource_retreive($composit_data) {
  $data = explode("~", $composit_data);
  $vote_data = array(
    "nid" => $data[0],
    "uid" => $data[1],
    "vc" => $data[2]
  );

  $vote_data['uid'] = _process_uuid($vote_data);
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

    $vote_data['vote-campaign-data'] = _profile_campaign_settings($vote_data['vc']);
    if (_voting_limit_reached($vote_data)) {
      return('limit-reached');
    }
    else {
      return('no-vote-entered');
    }
  }
  else {
    return ('missing-uuid');
  }
}

function _generic_voting_resource_create($vote_data) {
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
    
    $vote_data['vote-campaign-data'] = _profile_campaign_settings ($vote_data['vc']);
    if (_voting_limit_reached($vote_data)) {
      return('limit-reached');
    }
  }
  else {
    return ('missing-uuid');
  }

  return(_generic_voting_resource_write_vote($vote_data));
}

function _voting_limit_reached($vote_data) {  
  if ($vote_data['vote-campaign-data']['limit_type'] != 'none') {
    $timenow = time();
    $time_limit = _get_time_limit($vote_data['vote-campaign-data']['limit_type']);
    
    $sql = 'SELECT timestamp FROM {votingapi_vote} WHERE tag = :campaign AND uid = :curuid AND entity_id = :nid ORDER BY vote_id DESC LIMIT 1';
    $params = array(':curuid' => $vote_data['uid'], ':nid' => $vote_data['nid'], ':campaign' => $vote_data['vote-campaign-data']['voting_api_tag']);
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

function _generic_voting_resource_write_vote($vote_data) {
  $vote = array();
  $criteria = array();
  $contest_status = variable_get('hth_contest_status', 'break');

  if ($contest_status != 'break') {
    $vote['entity_type'] = 'node';
    $vote['value_type'] = 'points';
    $vote['entity_id'] = $vote_data['nid'];
    $vote['value'] = 1;
    $vote['uid'] = $vote_data['uid'];
    $vote['tag'] = $vote_data['vote-campaign-data']['voting_api_tag'];

    $votingapi_set_votes = votingapi_set_votes($vote, $criteria);

    if (is_array($votingapi_set_votes)) {
      return ('vote_entered');
    }
    else {
      return ('error_adding_vote');
    }
  }
  else {
    return ('error_adding_vote');
  }
}
