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
 * Implements hook_flag_default_flags().
 */
function maxim_celebrity_profile_flag_default_flags() {
  $flags = array();
  // Exported flag: "Reveal Celebrity Profile".
  $flags['hot100_reveal'] = array(
    'content_type' => 'node',
    'title' => 'Reveal Celebrity Profile',
    'global' => '1',
    'types' => array(
      0 => 'celebrity_profile',
    ),
    'flag_short' => 'Hidden (Click To Show)',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Visible (Click To Hide)',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '3',
      ),
      'unflag' => array(
        0 => '3',
      ),
    ),
    'weight' => 0,
    'show_on_form' => 1,
    'access_author' => '',
    'show_on_page' => 0,
    'show_on_teaser' => 0,
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'maxim_celebrity_profile',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;

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
