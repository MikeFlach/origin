<?php

/*
 * Implements hook_preprocess_block().
 */
function maxim_base_alpha_preprocess_block(&$block) {
  if ($block['attributes_array']['id'] == 'block-boxes-in-this-issue') {
    drupal_add_css( drupal_get_path('theme', 'maxim_base') . '/css/block--boxes--in-this-issue.css',
      array('group' => CSS_THEME, 'every_page' => FALSE) );
  }
}