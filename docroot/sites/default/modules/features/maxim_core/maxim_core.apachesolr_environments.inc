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
    'apachesolr_index_last' => array(
      'field_collection_item' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'node' => array(
        'last_changed' => '1369855753',
        'last_entity_id' => '84356',
      ),
      'redirect' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'file' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'taxonomy_term' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'taxonomy_vocabulary' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'user' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'wysiwyg_profile' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'rules_config' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
    ),
    'apachesolr_index_updated' => 1371069340,
    'apachesolr_last_optimize' => 1369993501,
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
      6 => 'link_stub',
      7 => 'list',
      8 => 'page',
      9 => 'review',
      10 => 'slideshow',
      11 => 'video',
      12 => 'webform',
    ),
  );
  $export['acquia_search_server_1'] = $environment;

  return $export;
}
