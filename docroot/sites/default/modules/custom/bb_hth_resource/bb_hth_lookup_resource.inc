<?php
// $Id$
require_once ( dirname(__FILE__) . '/bb_hth_common.inc');

function _bb_hth_lookup_states_retreive () {
  $return_data = array();
  
  $return_data['states'] = _get_state_listing();
  return($return_data);
}

function _bb_hth_lookup_years_retreive () {
  $return_data = array();
  $taxonomyQuery = new EntityFieldQuery();
  
  $taxonomyTerms = $taxonomyQuery->entityCondition('entity_type', 'taxonomy_term')
    ->propertyCondition('vid', 18)
    ->execute();
  
  foreach($taxonomyTerms['taxonomy_term'] as $term) {
    $term_name = taxonomy_term_load($term->tid)->name;
    
    if (((int)$term_name < 2014) && ((int)$term_name != 2005)) {
      $terms[] = taxonomy_term_load($term->tid)->name;
    }
  }
  $return_data['years'] = array_reverse($terms);
  
  return($return_data);
}

function _bb_hth_lookup_standings_retreive () {
  $return_data = array();
  $taxonomyQuery = new EntityFieldQuery();
  
  $taxonomyTerms = $taxonomyQuery->entityCondition('entity_type', 'taxonomy_term')
    ->propertyCondition('vid', 16)
    ->execute();
  
  foreach($taxonomyTerms['taxonomy_term'] as $term) {
    $term_name = taxonomy_term_load($term->tid)->name;
    
    if (strtolower($term_name) != 'winner') {
      $terms[] = $term_name;
    }
  }
  $return_data['standings'] = $terms;
  
  return($return_data);
}