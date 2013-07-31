<?php

/*
 * Implements hook_preprocess_block().
 */
function maxim_base_alpha_preprocess_block(&$block) {
  $function = 'maxim_base_alpha_preprocess_block__' . str_replace('-', '__', $block['block']->bid );
  if (function_exists($function)) {
   $function($block);
  }
}

function maxim_base_alpha_preprocess_block__dart__dart__tag__dart_banner(&$block) {
  $pushdown_js = 'function expand() {jQuery("#block-dart-dart-tag-dart-banner").css("height",418);};
    function contract() {jQuery("#block-dart-dart-tag-dart-banner").css("height",70);};';
  drupal_add_js($pushdown_js, 'inline');
}

function maxim_base_alpha_preprocess_block__boxes__in_this_issue(&$block) {
  drupal_add_css( drupal_get_path('theme', 'maxim_base') . '/css/block--boxes--in-this-issue.css',
    array('group' => CSS_THEME, 'every_page' => FALSE) );
}

function maxim_base_alpha_preprocess_block__delta_blocks__logo(&$block){
  //print("the logo no if");
  if ( $block['block']->context == 'slideshow_fullscreen' ) {
    $block['content'] = str_replace('logo.png','black_logo.png', $block['content']);
  } elseif ( $block['block']->context == 'uk_channel_page'  || $block['block']->context == 'uk_content_page' ) {
      $block['content'] = str_replace('logo.png','uk_logo.png', $block['content']);
  }
}


/**
 * Remove slingshot widget from sports section
 */
function maxim_base_alpha_preprocess_block__boxes__slingshot_widget(&$block){
  $exclude_sections = array('sports', 'the-big-leagues', 'mma', 'other-sports', 'ufc', 'girls-of-sports');
  $url = explode('/', url($_GET['q']));

  if (in_array($url[1], $exclude_sections)) {
    $block['content'] = '';
  }
}
