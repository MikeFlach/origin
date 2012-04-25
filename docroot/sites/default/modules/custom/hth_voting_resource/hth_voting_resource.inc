<?php
// $Id$

function _hth_voting_resource_create($vote_data) {
  if (!isset($vote_data['nid'])) {
    return services_error('Missing hottie nid', 406);
  }

  if (!isset($vote_data['uid'])) {
    return services_error('Missing uid', 406);
  }

  if (voting_limit_reached($vote_data)) {
    return services_error('Voting Limit Reached', 406);
  }
  else {
    hth_voting_resource_write_vote($vote_data);

  }
}

function _hth_voting_resource_retrieve($nid) {
  return hth_voting_resource_get_vote_count($nid);
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
    return (true);
  }
  else {
    return (false);
  }
}

