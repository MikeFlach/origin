<?php
/**
 * @file
 * maxim_core.default_apachesolr_environments.inc
 */

/**
 * Implements hook_default_apachesolr_environment().
 */
function maxim_core_default_apachesolr_environment() {
  $export = array();

  $name = new stdClass;
  $name->disabled = FALSE; /* Edit this to true to make a default name disabled initially */
  $name->api_version = 1;
  $name->env_id = 'acquia_search_server_1';
  $name->name = 'Acquia Search';
  $name->url = 'http://search.acquia.com/solr/DETW-21839';
  $name->service_class = 'AcquiaSearchService';
  $export['acquia_search_server_1'] = $name;

  $name = new stdClass;
  $name->disabled = FALSE; /* Edit this to true to make a default name disabled initially */
  $name->api_version = 1;
  $name->env_id = 'solr';
  $name->name = 'localhost server';
  $name->url = 'http://localhost:8983/solr';
  $name->service_class = '';
  $export['solr'] = $name;

  return $export;
}
