<?php

/*
 * Implements hook_preprocess_views_view
 */
function maxim_base_alpha_preprocess_views_view(&$view) {
  $function = 'maxim_base_alpha_preprocess_views_view__' . $view['view']->name;
  if (function_exists($function)) {
   $function($view);
  }
}

/*
 * Dispatch to individual view displays. Pass __FUNCTION__ for $calling_function. 
 */
function view_display_dispatch(&$view, $calling_function) {
  $function = $calling_function . '__' . $view['view']->current_display;
  if (function_exists($function)) {
   $function($view);
  }
}

function maxim_base_alpha_preprocess_views_view__slideshow_json(&$view) {
  view_display_dispatch($view, __FUNCTION__);
}

function maxim_base_alpha_preprocess_views_view__slideshow_json__block_1(&$view) {
}

function maxim_base_alpha_preprocess_views_view__slideshow_json__page_1(&$view) {
}

function maxim_base_alpha_preprocess_views_view__slideshow_json__page_2(&$view) {s
}

