<?php
// $Id$

function _bb_voting_resource_retreive_hth($year, $week, $state, $status, $page, $ipp) {
  $query = new EntityFieldQuery;
  
  if ($page == 1) {
    $range_start = 0;
    $range_end = $ipp-1;
  }
  else {
    $range_start = (($page - 1) * $ipp);
    $range_end = $range_start + ($ipp-1);
  }

  $query->entityCondition('entity_type', 'node')
        ->propertyCondition('status', 1)
        ->propertyCondition('type', 'hotties_profile')
        ->range($range_start, $ipp);

  // we use reset to retreive first element because the array returned by taxonomy_get_term_by_name is indexed by the tid, which we fon't have.
  if (!is_null($year)) {
    $tid_year = taxonomy_get_term_by_name($year, 'hotties_contest_year');
    $query->fieldCondition('field_hotties_contest_year', 'tid', reset($tid_year)->tid);
  }
  if (!is_null($week)) {
    $tid_week = taxonomy_get_term_by_name($week, 'hotties_contest_week');
    $query->fieldCondition('field_hotties_contest_week', 'tid', reset($tid_week)->tid);
  }
  if (!is_null($state)) {
    $tid_state = taxonomy_get_term_by_name($state, 'states_provinces');
    $query->fieldCondition('field_profile_state', 'tid', reset($tid_state)->tid);
  }
  if (!is_null($status)) {
    $tid_status = taxonomy_get_term_by_name($status, 'hotties_contest_status');
    $query->fieldCondition('field_hotties_contest_status', 'tid', reset($tid_status)->tid);
  }
  
  // get node data
  $node_ids = array();
  $node_data = $query->execute();
 
  foreach($node_data['node'] as $node) {
    $node_ids[] = $node->nid;
  }
  
  $data =  _get_node_data($node_ids);
 // $data[] = "RS:$range_start"; $data[] = "RE:$range_end";
  
  return($data);
}

function _get_node_data($node_ids) {
  $nodes = node_load_multiple($node_ids);
  
  // we need to replace the tids returned in node_load_multiple with the actual term 
  $return_data = array();
  $i = 0;
  foreach ($nodes as $node) { 
    $node_wrapper = entity_metadata_wrapper('node', $node);
    
    // for pre-2014 hotties return city, state for hometown. otherwise, return hometown.
    $year = taxonomy_term_load($node_wrapper->field_hotties_contest_year->value()->tid)->name;
    $city = $node_wrapper->field_profile_city->value();
    $state = taxonomy_term_load($node_wrapper->field_profile_state->value()->tid)->name;
    if ((int)$year > 2013) {
      $hometown = $node_wrapper->field_profile_hometown->value();
    }
    else {
       $hometown = "$city, $state";
    }
    
    // get terms from tid
    $nid = $node_wrapper->nid->value();
   // $return_data[$i]['record'] = $i;
    $return_data[$i]['nid'] = $nid;
    $return_data[$i]['name'] = $node_wrapper->field_profile_first_name->value();
    $return_data[$i]['hometown'] = $hometown;
    $return_data[$i]['profile-link'] = 'http://www.maxim.com'.url("node/$nid");
    
    $image = $node_wrapper->field_main_image->value(); 
    $return_data[$i++]['main-image'] = _get_image_uri($image['fid']);
  }
  
  return ($return_data);
}

function _bb_voting_resource_retreive($nid, $uid) {
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

    $vote_data['vote-campaign-data'] = _bb_campaign_settings($vote_data['vc']);
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

function _bb_voting_resource_create($vote_data) {
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
    
    $vote_data['vote-campaign-data'] = _bb_campaign_settings ($vote_data['vc']);
    if (_voting_limit_reached($vote_data)) {
      return('limit-reached');
    }
  }
  else {
    return ('missing-uuid');
  }

  return(_bb_voting_resource_write_vote($vote_data));
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

function _bb_voting_resource_write_vote($vote_data) {
  $vote = array();
  $criteria = array();

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

function _get_image_uri($fid) {
  $file = file_load($fid);
  if (strlen($file->uri) > 0) {
    return(file_create_url($file->uri));
  }
  else {
    return('');
  }
}

