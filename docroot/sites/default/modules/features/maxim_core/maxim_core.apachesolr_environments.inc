<?php
/**
 * @file
 * maxim_core.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function maxim_core_apachesolr_environments() {
  $export = array();

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'acquia_search_server_1';
  $environment->name = 'Acquia Search';
  $environment->url = 'http://search.acquia.com/solr/DETW-21839';
  $environment->service_class = 'AcquiaSearchService';
  $environment->conf = array();
  $environment->index_bundles = array(
    'node' => array(
      0 => 'celebrity_profile',
    ),
  );
  $export['acquia_search_server_1'] = $environment;

  return $export;
}
