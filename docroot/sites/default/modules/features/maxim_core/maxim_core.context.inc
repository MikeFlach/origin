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
  $context->name = 'channel_and_sidebar';
  $context->description = 'channel and sidebar';
  $context->tag = 'Node Type';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'girls/girls-of-maxim' => 'girls/girls-of-maxim',
        'girls/girls-of-maxim/*' => 'girls/girls-of-maxim/*',
        'girls/hot100*' => 'girls/hot100*',
        'girls/todays-girl*' => 'girls/todays-girl*',
        'girls/hometown-hotties*' => 'girls/hometown-hotties*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-facebookrecentactivity' => array(
          'module' => 'boxes',
          'delta' => 'facebookrecentactivity',
          'region' => 'sidebar_second',
          'weight' => '-35',
        ),
        'boxes-mostrecenttweets' => array(
          'module' => 'boxes',
          'delta' => 'mostrecenttweets',
          'region' => 'sidebar_second',
          'weight' => '-35',
        ),
        'dart-dart-tag-dart_big_box' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_big_box',
          'region' => 'sidebar_second',
          'weight' => '-35',
        ),
        'boxes-in_this_issue' => array(
          'module' => 'boxes',
          'delta' => 'in_this_issue',
          'region' => 'sidebar_second',
          'weight' => '-34',
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
        'delta_blocks-page-title' => array(
          'module' => 'delta_blocks',
          'delta' => 'page-title',
          'region' => 'wide_feature',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'channel_and_sidebar',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Node Type');
  t('channel and sidebar');
  $export['channel_and_sidebar'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'channel_page';
  $context->description = 'channel page';
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
        'poll-recent' => array(
          'module' => 'poll',
          'delta' => 'recent',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-maximtv_browser-maxim_tv_latest' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maxim_tv_latest',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'dart-dart-tag-dart_big_box' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_big_box',
          'region' => 'sidebar_second',
          'weight' => '-37',
        ),
        'boxes-facebookrecentactivity' => array(
          'module' => 'boxes',
          'delta' => 'facebookrecentactivity',
          'region' => 'sidebar_second',
          'weight' => '-36',
        ),
        'boxes-mostrecenttweets' => array(
          'module' => 'boxes',
          'delta' => 'mostrecenttweets',
          'region' => 'sidebar_second',
          'weight' => '-35',
        ),
        'boxes-in_this_issue' => array(
          'module' => 'boxes',
          'delta' => 'in_this_issue',
          'region' => 'sidebar_second',
          'weight' => '-34',
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
        'delta_blocks-page-title' => array(
          'module' => 'delta_blocks',
          'delta' => 'page-title',
          'region' => 'wide_feature',
          'weight' => '-10',
        ),
        'views-channel_feature-block' => array(
          'module' => 'views',
          'delta' => 'channel_feature-block',
          'region' => 'feature',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('channel page');
  $export['channel_page'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'content_wide';
  $context->description = 'Wide content template';
  $context->tag = 'Node Type';
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
  t('Node Type');
  t('Wide content template');
  $export['content_wide'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'entertainment_gaming_zone';
  $context->description = 'entertainment gaming channel ';
  $context->tag = 'Channels';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        22 => 22,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'entertainment/gaming' => 'entertainment/gaming',
      ),
    ),
  );
  $context->reactions = array(
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'entertainment__gaming',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('entertainment gaming channel ');
  $export['entertainment_gaming_zone'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'entertainment_movies_zone';
  $context->description = 'entertainment movies channel ';
  $context->tag = 'Channels';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        23 => 23,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'entertainment/movies' => 'entertainment/movies',
      ),
    ),
  );
  $context->reactions = array(
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'entertainment__movies',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('entertainment movies channel ');
  $export['entertainment_movies_zone'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'entertainment_music_zone';
  $context->description = 'entertainment movies channel ';
  $context->tag = 'Channels';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        27 => 27,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'entertainment/music' => 'entertainment/music',
      ),
    ),
  );
  $context->reactions = array(
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'entertainment__music',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('entertainment movies channel ');
  $export['entertainment_music_zone'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'entertainment_tv_zone';
  $context->description = 'entertainment tv channel ';
  $context->tag = 'Channels';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        29 => 29,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'entertainment/tv' => 'entertainment/tv',
      ),
    ),
  );
  $context->reactions = array(
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'entertainment__tv',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('entertainment tv channel ');
  $export['entertainment_tv_zone'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'entertainment_zone';
  $context->description = 'entertainment channel ';
  $context->tag = 'Channels';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        3 => 3,
        24 => 24,
        25 => 25,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'entertainment' => 'entertainment',
        'entertainment/comics' => 'entertainment/comics',
        'entertainment/events' => 'entertainment/events',
      ),
    ),
  );
  $context->reactions = array(
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'entertainment',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('entertainment channel ');
  $export['entertainment_zone'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'funny_zone';
  $context->description = 'funny channel';
  $context->tag = 'Channels';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        8 => 8,
        47 => 47,
        48 => 48,
        49 => 49,
        50 => 50,
        52 => 52,
        53 => 53,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'funny' => 'funny',
      ),
    ),
  );
  $context->reactions = array(
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'funny',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('funny channel');
  $export['funny_zone'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'gadgets_and_rides_zone';
  $context->description = 'gadgets and rides channel';
  $context->tag = 'Channels';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        5 => 5,
        33 => 33,
        34 => 34,
        35 => 35,
        314 => 314,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'gadgets-rides' => 'gadgets-rides',
      ),
    ),
  );
  $context->reactions = array(
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'gadgets_n_rides',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('gadgets and rides channel');
  $export['gadgets_and_rides_zone'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'girls_girls_of_maxim_zone';
  $context->description = 'girls of maxim channel';
  $context->tag = 'Channels';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        12 => 12,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'girls/girls-of-maxim' => 'girls/girls-of-maxim',
      ),
    ),
  );
  $context->reactions = array(
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'girls__girls_of_maxim',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('girls of maxim channel');
  $export['girls_girls_of_maxim_zone'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'girls_hometown_hotties';
  $context->description = 'hometown hotties channel';
  $context->tag = 'Channels';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        9 => 9,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'girls/hometown-hotties' => 'girls/hometown-hotties',
      ),
    ),
  );
  $context->reactions = array(
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'girls__hometown_hotties',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('hometown hotties channel');
  $export['girls_hometown_hotties'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'girls_hot_100';
  $context->description = 'hot 100 channel';
  $context->tag = 'Channels';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        10 => 10,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'girls/hot100' => 'girls/hot100',
      ),
    ),
  );
  $context->reactions = array(
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'girls__hot_100',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('hot 100 channel');
  $export['girls_hot_100'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'girls_todays_girl';
  $context->description = 'today\'s girl channel';
  $context->tag = 'Channels';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        11 => 11,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'girls/todays-girl' => 'girls/todays-girl',
      ),
    ),
  );
  $context->reactions = array(
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'girls__todays_girl',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('today\'s girl channel');
  $export['girls_todays_girl'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'girls_zone';
  $context->description = 'girls channel';
  $context->tag = 'Channels';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        1 => 1,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'girls' => 'girls',
        'girls/girls-of-maxim*' => 'girls/girls-of-maxim*',
      ),
    ),
  );
  $context->reactions = array(
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'girls',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('girls channel');
  $export['girls_zone'] = $context;

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
        'views-home_page-todays_girl' => array(
          'module' => 'views',
          'delta' => 'home_page-todays_girl',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-maximtv_browser-maxim_tv_latest' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maxim_tv_latest',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-home_page-block_1' => array(
          'module' => 'views',
          'delta' => 'home_page-block_1',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'views-polls-block' => array(
          'module' => 'views',
          'delta' => 'polls-block',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'dart-dart-tag-dart_big_box' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_big_box',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'boxes-follow_us' => array(
          'module' => 'boxes',
          'delta' => 'follow_us',
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
        'boxes-in_this_issue' => array(
          'module' => 'boxes',
          'delta' => 'in_this_issue',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'views-jumbotron-block_1' => array(
          'module' => 'views',
          'delta' => 'jumbotron-block_1',
          'region' => 'wide_feature',
          'weight' => '-10',
        ),
      ),
    ),
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'homepage',
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
    'path' => array(
      'values' => array(
        'maximtv' => 'maximtv',
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
        'views-maximtv_browser-maximtv_girls' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maximtv_girls',
          'region' => 'wide_feature',
          'weight' => '-10',
        ),
        'views-maximtv_browser-maximtv_sports' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maximtv_sports',
          'region' => 'wide_feature',
          'weight' => '-9',
        ),
        'views-maximtv_browser-maximtv_enter' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maximtv_enter',
          'region' => 'wide_feature',
          'weight' => '-8',
        ),
        'views-maximtv_browser-maximtv_gadgets' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maximtv_gadgets',
          'region' => 'wide_feature',
          'weight' => '-7',
        ),
        'views-maximtv_browser-maximtv_upkeep' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maximtv_upkeep',
          'region' => 'wide_feature',
          'weight' => '-6',
        ),
        'views-maximtv_browser-maximtv_vices' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maximtv_vices',
          'region' => 'wide_feature',
          'weight' => '-5',
        ),
        'views-maximtv_browser-maximtv_tough' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maximtv_tough',
          'region' => 'wide_feature',
          'weight' => '-4',
        ),
        'views-maximtv_browser-maximtv_funny' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maximtv_funny',
          'region' => 'wide_feature',
          'weight' => '-3',
        ),
        'delta_blocks-page-title' => array(
          'module' => 'delta_blocks',
          'delta' => 'page-title',
          'region' => 'feature',
          'weight' => '-10',
        ),
      ),
    ),
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'maxim_tv',
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
  $context->name = 'maximtv_channel';
  $context->description = 'maximtv channel page';
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
    'path' => array(
      'values' => array(
        'maximtv/*' => 'maximtv/*',
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
          'weight' => '-36',
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
        'views-5b5f24e7b0bbeaecfde7efe6263a1eb6' => array(
          'module' => 'views',
          'delta' => '5b5f24e7b0bbeaecfde7efe6263a1eb6',
          'region' => 'wide_feature',
          'weight' => '-10',
        ),
        'delta_blocks-page-title' => array(
          'module' => 'delta_blocks',
          'delta' => 'page-title',
          'region' => 'feature',
          'weight' => '-10',
        ),
      ),
    ),
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'maxim_tv',
    ),
    'delta' => array(
      'delta_template' => 'maxim_tv',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Node Type');
  t('maximtv channel page');
  $export['maximtv_channel'] = $context;

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
        'boxes-footer_copyright' => array(
          'module' => 'boxes',
          'delta' => 'footer_copyright',
          'region' => 'copyright',
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
        '~gallery/*' => '~gallery/*',
        '~slideshow/*' => '~slideshow/*',
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
          'weight' => '-11',
        ),
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'menu',
          'weight' => '-10',
        ),
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => 1,
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
        'boxes-footer_max' => array(
          'module' => 'boxes',
          'delta' => 'footer_max',
          'region' => 'footer_first',
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
    'path' => array(
      'values' => array(
        '~node/add/slideshow*' => '~node/add/slideshow*',
        '~/slideshow/*' => '~/slideshow/*',
        '~/admin*' => '~/admin*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-7b047b398fde88abd06e8a48923ad260' => array(
          'module' => 'views',
          'delta' => '7b047b398fde88abd06e8a48923ad260',
          'region' => 'feature',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Node Type');
  $export['slideshow'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'slideshow_fullscreen';
  $context->description = 'Fullscreen Slideshow';
  $context->tag = 'Node Type';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'slideshow/*' => 'slideshow/*',
        'gallery/*' => 'gallery/*',
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
      ),
    ),
    'delta' => array(
      'delta_template' => 'blackout',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Fullscreen Slideshow');
  t('Node Type');
  $export['slideshow_fullscreen'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sports_zone';
  $context->description = 'sports channel';
  $context->tag = 'Channels';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        2 => 2,
        16 => 16,
        17 => 17,
        18 => 18,
        19 => 19,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'sports' => 'sports',
      ),
    ),
  );
  $context->reactions = array(
    'dart_settings' => array(
      'dart_site' => 'dart',
      'dart_zone' => 'sports',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('sports channel');
  $export['sports_zone'] = $context;

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
        'hotties_profile' => 'hotties_profile',
        'joke' => 'joke',
        'link_stub' => 'link_stub',
        'list' => 'list',
        'poll' => 'poll',
        'review' => 'review',
        'slideshow' => 'slideshow',
        'webform' => 'webform',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'search*' => 'search*',
        'user/*' => 'user/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-facebookrecentactivity' => array(
          'module' => 'boxes',
          'delta' => 'facebookrecentactivity',
          'region' => 'sidebar_second',
          'weight' => '-35',
        ),
        'boxes-mostrecenttweets' => array(
          'module' => 'boxes',
          'delta' => 'mostrecenttweets',
          'region' => 'sidebar_second',
          'weight' => '-35',
        ),
        'dart-dart-tag-dart_big_box' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_big_box',
          'region' => 'sidebar_second',
          'weight' => '-35',
        ),
        'boxes-in_this_issue' => array(
          'module' => 'boxes',
          'delta' => 'in_this_issue',
          'region' => 'sidebar_second',
          'weight' => '-34',
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

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tough_sh_zone';
  $context->description = 'tough s#&t channel';
  $context->tag = 'Channels';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        44 => 44,
        322 => 322,
        323 => 323,
        324 => 324,
        325 => 325,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'tough' => 'tough',
      ),
    ),
  );
  $context->reactions = array(
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'tough',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('tough s#&t channel');
  $export['tough_sh_zone'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'upkeep_zone';
  $context->description = 'upkeep channel';
  $context->tag = 'Channels';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        6 => 6,
        37 => 37,
        43 => 43,
        317 => 317,
        318 => 318,
        319 => 319,
        320 => 320,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'upkeep' => 'upkeep',
      ),
    ),
  );
  $context->reactions = array(
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'upkeep',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('upkeep channel');
  $export['upkeep_zone'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vices_zone';
  $context->description = 'vices channel';
  $context->tag = 'Channels';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        7 => 7,
        38 => 38,
        39 => 39,
        41 => 41,
        42 => 42,
        45 => 45,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'vices' => 'vices',
      ),
    ),
  );
  $context->reactions = array(
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'vices',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');
  t('vices channel');
  $export['vices_zone'] = $context;

  return $export;
}
