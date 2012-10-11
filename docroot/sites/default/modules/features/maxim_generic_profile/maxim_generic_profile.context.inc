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
        'gmap_location-0' => array(
          'module' => 'gmap_location',
          'delta' => 0,
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'dart-dart-tag-dart_big_box' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_big_box',
          'region' => 'sidebar_second',
          'weight' => '-9',
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
