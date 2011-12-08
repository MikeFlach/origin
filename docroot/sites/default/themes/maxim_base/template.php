<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 *
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

/**
 * Replace the bundled version of jQuery with jQuery 1.7.1
 * TBD - Move this code to a module.
 */
function maxim_base_js_alter(&$javascript) {
  $javascript['misc/jquery.js']['data'] = libraries_get_path('jquery')  . '/jquery-1.7.1.min.js';
}

/*
 * Implements theme_menu_tree()
 */
/*function maxim_base_menu_tree__main_menu($variables){
  return '<ul class="menu">' . $variables['tree'] . '</ul>';
}*/

/*
 * Implements theme_menu_link()
 */
function maxim_base_menu_link__main_menu($variables){
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  // add term id to top level menu
  $element['#attributes']['class'][] = 'mtid-' . str_replace('taxonomy/term/', '', $element['#href']);

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
