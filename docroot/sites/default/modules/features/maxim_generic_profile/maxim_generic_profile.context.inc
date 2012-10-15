<?php
/**
 * @file
 * maxim_generic_profile.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function maxim_generic_profile_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ciroc_military_slider';
  $context->description = 'Slider for Ciroc Military';
  $context->tag = 'Generic Profile';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'generic_profile' => 'generic_profile',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'node_taxonomy' => array(
      'values' => array(
        18802 => 18802,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-91a6febf55a95c690630ff315959d584' => array(
          'module' => 'views',
          'delta' => '91a6febf55a95c690630ff315959d584',
          'region' => 'wide_feature',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Generic Profile');
  t('Slider for Ciroc Military');
  $export['ciroc_military_slider'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'generic_profile';
  $context->description = 'Generic Profile';
  $context->tag = 'Node Type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'generic_profile' => 'generic_profile',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'dart-dart-tag-dart_big_box' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_big_box',
          'region' => 'sidebar_second',
          'weight' => '-115',
        ),
        'gmap_location-0' => array(
          'module' => 'gmap_location',
          'delta' => 0,
          'region' => 'sidebar_second',
          'weight' => '-114',
        ),
        'ds_extras-generic_prev_next' => array(
          'module' => 'ds_extras',
          'delta' => 'generic_prev_next',
          'region' => 'content_container',
          'weight' => '-10',
        ),
        'ds_extras-generic_profile_information' => array(
          'module' => 'ds_extras',
          'delta' => 'generic_profile_information',
          'region' => 'content_container',
          'weight' => '-9',
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
  t('Generic Profile');
  t('Node Type');
  $export['generic_profile'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'gprofile_vote_button';
  $context->description = 'generic profile voting button and header';
  $context->tag = 'Generic Profile';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        18800 => 18800,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'generic_voting_resource-generic_nav_header' => array(
          'module' => 'generic_voting_resource',
          'delta' => 'generic_nav_header',
          'region' => 'header_first',
          'weight' => '-10',
        ),
        'generic_voting_resource-generic_vote_button' => array(
          'module' => 'generic_voting_resource',
          'delta' => 'generic_vote_button',
          'region' => 'content_container',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Generic Profile');
  t('generic profile voting button and header');
  $export['gprofile_vote_button'] = $context;

  return $export;
}
