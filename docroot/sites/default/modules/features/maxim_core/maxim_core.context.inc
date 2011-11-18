<?php
/**
 * @file
 * maxim_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function maxim_core_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'channel_page';
  $context->description = 'channel';
  $context->tag = 'Channels';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'channels' => 'channels',
      ),
      'options' => array(
        'term_form' => '1',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('channel');
  $export['channel_page'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = 'homepage';
  $context->tag = 'Channels';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'poll-recent' => array(
          'module' => 'poll',
          'delta' => 'recent',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'homepage',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('homepage');
  $export['homepage'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'informational_page';
  $context->description = 'basic content pages';
  $context->tag = 'Informational';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'page' => 'page',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'delta' => array(
      'delta_template' => 'basic_page',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Informational');
  t('basic content pages');
  $export['informational_page'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = 'global';
  $context->tag = 'Global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global');
  t('global');
  $export['sitewide'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_blackout';
  $context->description = 'Sitewide for the blackout template';
  $context->tag = 'Global';
  $context->conditions = array();
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global');
  t('Sitewide for the blackout template');
  $export['sitewide_blackout'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_debug';
  $context->description = 'Sitewide global debug';
  $context->tag = 'Global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'context_ui-editor' => array(
          'module' => 'context_ui',
          'delta' => 'editor',
          'region' => 'partners_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global');
  t('Sitewide global debug');
  $export['sitewide_debug'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_standard';
  $context->description = 'Sitewide for the standard template';
  $context->tag = 'Global';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~blackout' => '~blackout',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'delta_blocks-logo' => array(
          'module' => 'delta_blocks',
          'delta' => 'logo',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'utility_menu',
          'weight' => '-10',
        ),
        'dart-dart-tag-dart_big_box' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_big_box',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'boxes-mostrecenttweets' => array(
          'module' => 'boxes',
          'delta' => 'mostrecenttweets',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'boxes-facebookrecentactivity' => array(
          'module' => 'boxes',
          'delta' => 'facebookrecentactivity',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'dart-dart-tag-dart_leaderboard' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_leaderboard',
          'region' => 'header_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global');
  t('Sitewide for the standard template');
  $export['sitewide_standard'] = $context;

  return $export;
}
