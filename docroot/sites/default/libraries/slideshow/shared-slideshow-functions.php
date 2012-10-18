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
    
    //from views preprocess -- obj
    if (is_object($node)) {
      if (isset($node->field_tags)) {
        $tags = $node->field_tags;
      }
      else {
        return ($t_names);
      }
    }
    //from node preprocess -- 
    elseif (is_array($node)) { 
      if (isset($node['field_tags'])) {
        $tags = $node['field_tags'];
      }
      else {
        return ($t_names);
      }
    }
    //can't find tags
    else {
      return($t_names);
    }

    $terms = $tags[LANGUAGE_NONE] ? $tags[LANGUAGE_NONE] : $tags;
    foreach ($terms as $term) {
      array_push($t_names, taxonomy_term_load($term['tid'])->name);
    }

    return($t_names);
  }

?>
