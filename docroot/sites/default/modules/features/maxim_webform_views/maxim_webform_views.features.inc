<?php
/**
 * @file
 * maxim_webform_views.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function maxim_webform_views_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function maxim_webform_views_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
