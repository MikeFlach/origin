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
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-maximtv_browser-block_4' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-block_4',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'dart-dart-tag-dart_big_box' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_big_box',
          'region' => 'sidebar_second',
          'weight' => '0',
        ),
        'boxes-mostrecenttweets' => array(
          'module' => 'boxes',
          'delta' => 'mostrecenttweets',
          'region' => 'sidebar_second',
          'weight' => '3',
        ),
        'boxes-facebookrecentactivity' => array(
          'module' => 'boxes',
          'delta' => 'facebookrecentactivity',
          'region' => 'sidebar_second',
          'weight' => '5',
        ),
        'views-newsreel-block' => array(
          'module' => 'views',
          'delta' => 'newsreel-block',
          'region' => 'header_first',
          'weight' => '-10',
        ),
        'dart-dart-tag-dart_leaderboard' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_leaderboard',
          'region' => 'header_second',
          'weight' => '-10',
        ),
        'views-channel_feature-block' => array(
          'module' => 'views',
          'delta' => 'channel_feature-block',
          'region' => 'feature',
          'weight' => '-10',
        ),
      ),
    ),
  );
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
        'system-user-menu' => array(
          'module' => 'system',
          'delta' => 'user-menu',
          'region' => 'utility_menu',
          'weight' => '-10',
        ),
        'views-home_page-block_1' => array(
          'module' => 'views',
          'delta' => 'home_page-block_1',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'views-polls-block' => array(
          'module' => 'views',
          'delta' => 'polls-block',
          'region' => 'sidebar_first',
          'weight' => '5',
        ),
        'views-maximtv_browser-block_4' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-block_4',
          'region' => 'sidebar_first',
          'weight' => '3',
        ),
        'dart-dart-tag-dart_big_box' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_big_box',
          'region' => 'sidebar_second',
          'weight' => '0',
        ),
        'boxes-mostrecenttweets' => array(
          'module' => 'boxes',
          'delta' => 'mostrecenttweets',
          'region' => 'sidebar_second',
          'weight' => '3',
        ),
        'boxes-facebookrecentactivity' => array(
          'module' => 'boxes',
          'delta' => 'facebookrecentactivity',
          'region' => 'sidebar_second',
          'weight' => '5',
        ),
        'views-jumbotron-block_1' => array(
          'module' => 'views',
          'delta' => 'jumbotron-block_1',
          'region' => 'wide_feature',
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
  $context->name = 'maximtv';
  $context->description = '';
  $context->tag = 'Node Type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'video' => 'video',
      ),
      'options' => array(
        'node_form' => '1',
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
        'dart-dart-tag-dart_big_box' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_big_box',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-newsreel-block' => array(
          'module' => 'views',
          'delta' => 'newsreel-block',
          'region' => 'header_first',
          'weight' => '-10',
        ),
        'dart-dart-tag-dart_leaderboard' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_leaderboard',
          'region' => 'header_second',
          'weight' => '-10',
        ),
        'views-maximtv_browser-block_1' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-block_1',
          'region' => 'wide_feature',
          'weight' => '-10',
        ),
        'views-maximtv_browser-block_2' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-block_2',
          'region' => 'wide_feature',
          'weight' => '-9',
        ),
        'views-maximtv_browser-block' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-block',
          'region' => 'wide_feature',
          'weight' => '-8',
        ),
        'views-maximtv_browser-block_3' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-block_3',
          'region' => 'wide_feature',
          'weight' => '-7',
        ),
        'views-maximtv_browser-block_8' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-block_8',
          'region' => 'wide_feature',
          'weight' => '-6',
        ),
        'views-maximtv_browser-block_5' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-block_5',
          'region' => 'wide_feature',
          'weight' => '-5',
        ),
        'views-maximtv_browser-block_6' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-block_6',
          'region' => 'wide_feature',
          'weight' => '-4',
        ),
        'views-maximtv_browser-block_7' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-block_7',
          'region' => 'wide_feature',
          'weight' => '-3',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'maxim_tv',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Node Type');
  $export['maximtv'] = $context;

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
        'system-user-menu' => array(
          'module' => 'system',
          'delta' => 'user-menu',
          'region' => 'utility_menu',
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
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'menu',
          'weight' => '-10',
        ),
        'menu_block-maxim_core-1' => array(
          'module' => 'menu_block',
          'delta' => 'maxim_core-1',
          'region' => 'submenu',
          'weight' => '-10',
        ),
        'views-nodequeue_11-block_4' => array(
          'module' => 'views',
          'delta' => 'nodequeue_11-block_4',
          'region' => 'partners_first',
          'weight' => '-10',
        ),
        'views-nodequeue_11-block_1' => array(
          'module' => 'views',
          'delta' => 'nodequeue_11-block_1',
          'region' => 'partners_second',
          'weight' => '-10',
        ),
        'views-nodequeue_11-block_2' => array(
          'module' => 'views',
          'delta' => 'nodequeue_11-block_2',
          'region' => 'partners_third',
          'weight' => '-10',
        ),
        'views-nodequeue_11-block_3' => array(
          'module' => 'views',
          'delta' => 'nodequeue_11-block_3',
          'region' => 'partners_fourth',
          'weight' => '-10',
        ),
        'menu_block-footer_menu-1' => array(
          'module' => 'menu_block',
          'delta' => 'footer_menu-1',
          'region' => 'footer_second',
          'weight' => '-10',
        ),
        'views-magazine_links-block' => array(
          'module' => 'views',
          'delta' => 'magazine_links-block',
          'region' => 'footer_third',
          'weight' => '-10',
        ),
        'views-featured_links-block' => array(
          'module' => 'views',
          'delta' => 'featured_links-block',
          'region' => 'footer_fourth',
          'weight' => '-10',
        ),
        'views-about_maxim_links-block' => array(
          'module' => 'views',
          'delta' => 'about_maxim_links-block',
          'region' => 'footer_fifth',
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

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'slideshow';
  $context->description = '';
  $context->tag = 'Node Type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'slideshow' => 'slideshow',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-slideshow_json-block_2' => array(
          'module' => 'views',
          'delta' => 'slideshow_json-block_2',
          'region' => 'wide_feature',
          'weight' => '-10',
        ),
        'views-slideshow_json-block_1' => array(
          'module' => 'views',
          'delta' => 'slideshow_json-block_1',
          'region' => 'feature',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Node Type');
  $export['slideshow'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'standard_content';
  $context->description = 'standard content';
  $context->tag = 'Node Type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
        'blog' => 'blog',
        'joke' => 'joke',
        'link_stub' => 'link_stub',
        'list' => 'list',
        'page' => 'page',
        'poll' => 'poll',
        'review' => 'review',
        'slideshow' => 'slideshow',
        'webform' => 'webform',
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
          'weight' => '-9',
        ),
        'boxes-mostrecenttweets' => array(
          'module' => 'boxes',
          'delta' => 'mostrecenttweets',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'boxes-facebookrecentactivity' => array(
          'module' => 'boxes',
          'delta' => 'facebookrecentactivity',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-newsreel-block' => array(
          'module' => 'views',
          'delta' => 'newsreel-block',
          'region' => 'header_first',
          'weight' => '-10',
        ),
        'dart-dart-tag-dart_leaderboard' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_leaderboard',
          'region' => 'header_second',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'content_and_sidebar',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Node Type');
  t('standard content');
  $export['standard_content'] = $context;

  return $export;
}
