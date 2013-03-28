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
  $environment->conf = array(
    'apachesolr_read_only' => 1,
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'article',
      1 => 'blog',
      2 => 'celebrity_profile',
      3 => 'generic_profile',
      4 => 'hotties_profile',
      5 => 'joke',
      6 => 'list',
      7 => 'page',
      8 => 'review',
      9 => 'slideshow',
      10 => 'video',
      11 => 'webform',
    ),
  );
  $export['acquia_search_server_1'] = $environment;

  return $export;
}
