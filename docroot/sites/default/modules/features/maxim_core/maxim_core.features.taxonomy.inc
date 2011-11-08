<?php
/**
 * @file
 * maxim_core.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function maxim_core_taxonomy_default_vocabularies() {
  return array(
    'channels' => array(
      'name' => 'Channels',
      'machine_name' => 'channels',
      'description' => 'maxim channels ',
      'hierarchy' => '1',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'columns' => array(
      'name' => 'Columns',
      'machine_name' => 'columns',
      'description' => 'Defines repeating series of content',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'content_authors' => array(
      'name' => 'Authors',
      'machine_name' => 'content_authors',
      'description' => 'Override author field',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'freeform_tags' => array(
      'name' => 'Vignette Tags',
      'machine_name' => 'freeform_tags',
      'description' => 'Tags used in the Vignette system',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'joke_categories' => array(
      'name' => 'Joke Categories',
      'machine_name' => 'joke_categories',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'partner' => array(
      'name' => 'Partners',
      'machine_name' => 'partner',
      'description' => 'External Partners',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => 'Use tags to group articles on similar topics into categories.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-8',
    ),
  );
}
