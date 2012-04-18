<?php
/**
 * @file
 * maxim_display.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function maxim_display_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "delta" && $api == "delta") {
    return array("version" => "3");
  }
}

