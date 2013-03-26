<?php
/**
 * @file
 * maxim_celebrity_profile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function maxim_celebrity_profile_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
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
 * Implements hook_views_api().
 */
function maxim_celebrity_profile_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function maxim_celebrity_profile_node_info() {
  $items = array(
    'celebrity_profile' => array(
      'name' => t('Celebrity Profile'),
      'base' => 'node_content',
      'description' => t('Maxim\'s Celebrity Profile'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
