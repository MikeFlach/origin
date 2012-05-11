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
  $context->name = '2013_hth_profile_wk_1';
  $context->description = '2013 Hometown Hottie Profiles week 1';
  $context->tag = 'Hometown Hotties';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'hotties_profile' => 'hotties_profile',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'node_taxonomy' => array(
      'values' => array(
        14092 => 14092,
        16231 => 16231,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ca3d3d5ceaeaa060853f0a0bb4ab318a' => array(
          'module' => 'views',
          'delta' => 'ca3d3d5ceaeaa060853f0a0bb4ab318a',
          'region' => 'wide_feature',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('2013 Hometown Hottie Profiles week 1');
  t('Hometown Hotties');
  $export['2013_hth_profile_wk_1'] = $context;

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
