<?php

/*
 * Implements hook_preprocess_block().
 */
function maxim_base_alpha_preprocess_block(&$block) {

  $function = 'maxim_base_alpha_preprocess_block__boxes' . str_replace('-', '__', $block['block']->bid );
  if (function_exists($function)) {
   $function($block);
  }
}

function maxim_base_alpha_preprocess_block__boxes__in_this_issue(&$block) {
  drupal_add_css( drupal_get_path('theme', 'maxim_base') . '/css/block--boxes--in-this-issue.css',
    array('group' => CSS_THEME, 'every_page' => FALSE) );
}