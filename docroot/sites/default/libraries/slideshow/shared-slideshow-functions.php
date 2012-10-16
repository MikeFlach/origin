<?php

function process_slideshow_ads($default_frequency) {
  $ad_refresh_rate = variable_get('slideshow_ad_frequency', $default_frequency);
  drupal_add_js(array('Maxim' => array('slideshow' => array('ad_frequency' => $ad_refresh_rate))), 'setting');
} 

function is_gamer_girl($node) {
  $tags = get_all_taxonomomy_tags($node);

  foreach ($tags as $tag) {
    if ($tag == '_gamergirl_2012_contest') {
      return (true);
    }
  }

  return(false);
}

function get_all_taxonomomy_tags($node) {
  $t_names = array();
  $terms = isset($node['field_tags'][LANGUAGE_NONE]) ? $node['field_tags'][LANGUAGE_NONE] : $node['field_tags'];
  
  foreach ($terms as $term) {
    array_push($t_names, taxonomy_term_load($term['tid'])->name);
  }
            
  return($t_names);
}

?>
