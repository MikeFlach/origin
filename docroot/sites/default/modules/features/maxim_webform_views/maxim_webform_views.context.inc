<?php
/**
 * @file
 * maxim_webform_views.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function maxim_webform_views_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hometown_hottie_profile';
  $context->description = 'Hometown Hottie Profile';
  $context->tag = 'Node Type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'hotties_profile' => 'hotties_profile',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'gmap_location-0' => array(
          'module' => 'gmap_location',
          'delta' => 0,
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'jtweetsanywhere-jtweetsanywhere' => array(
          'module' => 'jtweetsanywhere',
          'delta' => 'jtweetsanywhere',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'ds_extras-hotties_twitter_feed' => array(
          'module' => 'ds_extras',
          'delta' => 'hotties_twitter_feed',
          'region' => 'wide_feature',
          'weight' => '-10',
        ),
        'ds_extras-hometown_hotties_slider' => array(
          'module' => 'ds_extras',
          'delta' => 'hometown_hotties_slider',
          'region' => 'wide_feature',
          'weight' => '-10',
        ),
        'ds_extras-hottie_profile_information' => array(
          'module' => 'ds_extras',
          'delta' => 'hottie_profile_information',
          'region' => 'content_container',
          'weight' => '-10',
        ),
        'ds_extras-embedded_slideshow' => array(
          'module' => 'ds_extras',
          'delta' => 'embedded_slideshow',
          'region' => 'feature',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'hth_profile',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Hometown Hottie Profile');
  t('Node Type');
  $export['hometown_hottie_profile'] = $context;

  return $export;
}
