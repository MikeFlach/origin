<?php
/**
 * @file
 * maxim_generic_profile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function maxim_generic_profile_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function maxim_generic_profile_node_info() {
  $items = array(
    'generic_profile' => array(
      'name' => t('Generic Profile'),
      'base' => 'node_content',
      'description' => t('This is a gerneic profile.'),
      'has_title' => '1',
      'title_label' => t('Generic Profile Title'),
      'help' => '',
    ),
  );
  return $items;
}
