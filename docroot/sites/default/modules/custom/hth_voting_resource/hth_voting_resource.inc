<?php
// $Id$

function _hth_voting_resource_create($vote_data) {
  if (!isset($vote_data['nid'])) {
    return services_error('Missing hottie nid', 406);
  }

  if (!isset($vote_data['uid'])) {
    return services_error('Missing uid', 406);
  }

  hth_voting_resource_write_vote($vote_data);
}

function _hth_voting_resource_retrieve($nid) {
  return hth_voting_resource_get_vote_count($nid);
}
