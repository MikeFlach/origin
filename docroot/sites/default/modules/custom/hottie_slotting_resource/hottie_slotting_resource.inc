<?php
// $Id$

function _hottie_slotting_resource_create($slot_data) {
  //if yes/no/maybeslotting
  if (array_key_exists('slot', $slot_data)) {
   _slot_hottie($slot_data);
  }
  //if week slotting
  else {
    _slot_hottie_week($slot_data);
  }
  
}

function _slot_hottie($slot_data) {  
  if (_previously_slotted($slot_data)) {
    if ($slot_data['slot'] == 'unslotted') {
      $sql = 'DELETE FROM {webform_submitted_data} WHERE nid = :nid AND sid = :sid AND cid = :cid AND no = :no';
      $vars_data = array(':nid' => $slot_data['nid'], ':sid' => $slot_data['sid'], ':cid' => $slot_data['cid'], ':no' => $slot_data['no']);
    }
    else {
      $sql = 'UPDATE {webform_submitted_data} SET data = :slot WHERE nid = :nid AND sid = :sid AND cid = :cid AND no = :no';
      $vars_data = array(':nid' => $slot_data['nid'], ':sid' => $slot_data['sid'], ':cid' => $slot_data['cid'], ':no' => $slot_data['no'], ':slot' => $slot_data['slot']);
    }
    
    $result = 'Updated webform_submitted_data';
  }
  else {
    $sql = 'INSERT {webform_submitted_data} (nid,sid,cid,no,data) VALUES (:nid,:sid,:cid,:no,:slot)';
    $result = 'Inserted webform_submitted_data';
    $vars_data = array(':nid' => $slot_data['nid'], ':sid' => $slot_data['sid'], ':cid' => $slot_data['cid'], ':no' => $slot_data['no'], ':slot' => $slot_data['slot']);
  }

  db_query($sql, $vars_data);
  return($result);
}

function _slot_hottie_week($slot_data) {  
  if (_previously_slotted($slot_data)) {
    if ($slot_data['week'] == 'none') {
      $sql = 'DELETE FROM {webform_submitted_data} WHERE nid = :nid AND sid = :sid AND cid = :cid AND no = :no';
      $vars_data = array(':nid' => $slot_data['nid'], ':sid' => $slot_data['sid'], ':cid' => $slot_data['cid'], ':no' => $slot_data['no']);
    }
    else {
      $sql = 'UPDATE {webform_submitted_data} SET data = :week WHERE nid = :nid AND sid = :sid AND cid = :cid AND no = :no';
      $vars_data = array(':nid' => $slot_data['nid'], ':sid' => $slot_data['sid'], ':cid' => $slot_data['cid'], ':no' => $slot_data['no'], ':week' => $slot_data['week']);
    }
    
    $result = 'Updated webform_submitted_data';
  }
  else {
    $sql = 'INSERT {webform_submitted_data} (nid,sid,cid,no,data) VALUES (:nid,:sid,:cid,:no,:week)';
    $vars_data = array(':nid' => $slot_data['nid'], ':sid' => $slot_data['sid'], ':cid' => $slot_data['cid'], ':no' => $slot_data['no'], ':week' => $slot_data['week']);
    $result = 'Inserted webform_submitted_data';
  }

  db_query($sql, $vars_data);
  return($result);
}

function _previously_slotted ($slot_data) {
  $sql_query_check_value_exists = 'SELECT data FROM {webform_submitted_data} WHERE nid = :nid AND sid = :sid AND cid = :cid AND no = :no';
  $vars_query_check_value_exists = array(':nid' => $slot_data['nid'], ':sid' => $slot_data['sid'], ':cid' => $slot_data['cid'], ':no' => $slot_data['no']);
  
  $result = db_query($sql_query_check_value_exists, $vars_query_check_value_exists)->fetchObject();
  if (isset($result->data)) {
    return true;
  }
  else {
    return false;
  }
}