<?php

/*
 * Implements hook_preprocess_views_view().
 */
function maxim_base_alpha_preprocess_views_view(&$view) {
  // Dispatch function based on node type
  $function = 'maxim_base_alpha_preprocess_views_view__' . $view['view']->name;
  if (function_exists($function)) {
    $function($view);
  }
}

function maxim_base_alpha_preprocess_views_view__channel_feature(&$view) {
  if ( strpos($_SERVER['REQUEST_URI'], 'page=') !== false ) {
    $view['rows'] = ' ';
  }
}