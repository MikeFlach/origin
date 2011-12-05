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
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
    ),
    'columns' => array(
      'name' => 'Columns',
      'machine_name' => 'columns',
      'description' => 'Defines repeating series of content',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
    ),
    'content_authors' => array(
      'name' => 'Authors',
      'machine_name' => 'content_authors',
      'description' => 'Override author field',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
    ),
    'freeform_tags' => array(
      'name' => 'Vignette Tags',
      'machine_name' => 'freeform_tags',
      'description' => 'Tags used in the Vignette system',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
    ),
    'joke_categories' => array(
      'name' => 'Joke Categories',
      'machine_name' => 'joke_categories',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
    ),
    'partner' => array(
      'name' => 'Partners',
      'machine_name' => 'partner',
      'description' => 'External Partners',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
    ),
    'people_places_things' => array(
      'name' => 'People Places Things',
      'machine_name' => 'people_places_things',
      'description' => 'Proper nouns taxonomy to group events, twitter feeds, people',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
    ),
    'review_types' => array(
      'name' => 'Review Types',
      'machine_name' => 'review_types',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
    ),
    'reviews_game_platforms' => array(
      'name' => 'Reviews: Game Platforms',
      'machine_name' => 'reviews_game_platforms',
      'description' => 'Game System Platforms',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
    ),
    'reviews_mpaa_ratings' => array(
      'name' => 'Reviews: MPAA Ratings',
      'machine_name' => 'reviews_mpaa_ratings',
      'description' => 'Movie Ratings',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
    ),
    'reviews_sources' => array(
      'name' => 'Reviews: Sources',
      'machine_name' => 'reviews_sources',
      'description' => 'Review Source',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
    ),
    'reviews_star_rating' => array(
      'name' => 'Reviews: Star Rating',
      'machine_name' => 'reviews_star_rating',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
    ),
    'reviews_tv_networks' => array(
      'name' => 'Reviews: TV Networks',
      'machine_name' => 'reviews_tv_networks',
      'description' => 'TV Networks',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => 'Use tags to group articles on similar topics into categories.',
      'hierarchy' => '1',
      'module' => 'taxonomy',
      'weight' => '-8',
      'metatags' => array(),
    ),
  );
}
