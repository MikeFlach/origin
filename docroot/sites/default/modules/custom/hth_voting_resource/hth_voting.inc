<?php
// $Id$

/**
 * Callback for creating hth_voting resources.
 *
 * @param object $data
 * @return object
 */
function _hth_voting_resource_create($data) {
  unset($data->id);
  $data->created = time();

  if (!isset($data->nid)) {
    return services_error('Missing hottie nid', 406);
  }

  hth_voting_resource_write_note($data);
  return (object)array(
    'id' => $data->id,
    'uri' => services_resource_uri(array('note', $data->nid)),
  );
}

/**
 * Callback for retrieving hth_voting resources.
 *
 * @param int $id
 * @return object
 */
function _hth_voting_resource_retrieve($nid) {
  return hth_voting_resource_get_vote_count($nid);
}
