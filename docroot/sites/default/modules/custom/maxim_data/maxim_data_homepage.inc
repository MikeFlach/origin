<?php
// $Id$

function _maxim_data_homepage_retreive ($cacher_bust) {
  try {
    $hp_settings = _maxim_data_settings('homepage');
    
    $homepage_data['data'] = _maxim_data_get_homepage_data();
  }
  catch (Exception $e) {
    $homepage_data['data'] = array();
    
    _maxim_data_append_error_info($homepage_data, $e);
    
    return ($homepage_data);
  }
}

function _maxim_data_get_homepage_data () {
  $query = new EntityFieldQuery;
  
  $query->entityCondition('entity_type', 'node')
        ->propertyCondition('status', 1)
        ->propertyCondition('type', array('link-stub', 'poll', 'blog'), 'NOT IN')
        ->propertyCondition('promote', 1);
  
  $tg_channel = taxonomy_get_term_by_name('todays-girl', 'channels');
  $query->fieldCondition('field_channel', 'tid', reset($tg_channel)->tid, '!=');
}