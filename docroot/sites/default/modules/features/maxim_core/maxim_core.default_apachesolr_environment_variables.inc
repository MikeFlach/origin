<?php
/**
 * @file
 * maxim_core.default_apachesolr_environment_variables.inc
 */

/**
 * Implements hook_default_apachesolr_environment_variable().
 */
function maxim_core_default_apachesolr_environment_variable() {
  $export = array();

  $name = new stdClass;
  $name->disabled = FALSE; /* Edit this to true to make a default name disabled initially */
  $name->api_version = 1;
  $name->env_id = 'acquia_search_server_1';
  $name->name = 'apachesolr_read_only';
  $name->value = 's:1:"1";';
  $export['apachesolr_read_only'] = $name;

  return $export;
}
