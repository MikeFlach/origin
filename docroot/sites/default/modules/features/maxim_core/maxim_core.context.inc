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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'channel_and_sidebar';
  $context->description = 'channel and sidebar';
  $context->tag = 'Templates';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'girls/girls-of-maxim' => 'girls/girls-of-maxim',
        'girls/girls-of-maxim/*' => 'girls/girls-of-maxim/*',
        'hot-100/2012' => 'hot-100/2012',
        'aggregator/*' => 'aggregator/*',
        'search/*' => 'search/*',
        'user/*' => 'user/*',
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
          'weight' => '-108',
        ),
        'boxes-follow_us' => array(
          'module' => 'boxes',
          'delta' => 'follow_us',
          'region' => 'sidebar_second',
          'weight' => '-106',
        ),
        'views-latest_videos-block_1' => array(
          'module' => 'views',
          'delta' => 'latest_videos-block_1',
          'region' => 'sidebar_second',
          'weight' => '-105',
        ),
        'boxes-mostrecenttweets' => array(
          'module' => 'boxes',
          'delta' => 'mostrecenttweets',
          'region' => 'sidebar_second',
          'weight' => '-103',
        ),
        'boxes-facebookrecentactivity' => array(
          'module' => 'boxes',
          'delta' => 'facebookrecentactivity',
          'region' => 'sidebar_second',
          'weight' => '-102',
        ),
        'boxes-in_this_issue' => array(
          'module' => 'boxes',
          'delta' => 'in_this_issue',
          'region' => 'sidebar_second',
          'weight' => '-101',
        ),
        'boxes-maxim_newsletter' => array(
          'module' => 'boxes',
          'delta' => 'maxim_newsletter',
          'region' => 'sidebar_second',
          'weight' => '-104',
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
  t('Templates');
  t('channel and sidebar');
  $export['channel_and_sidebar'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'channel_page';
  $context->description = 'channel page';
  $context->tag = 'Channel Pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'girls/hot100' => 'girls/hot100',
        'girls/todays-girl' => 'girls/todays-girl',
        'girls/hometown-hotties' => 'girls/hometown-hotties',
        'todays-girl/sexiest-women-tv-fall-2012' => 'todays-girl/sexiest-women-tv-fall-2012',
        'magazine' => 'magazine',
        'reviews' => 'reviews',
        'archive' => 'archive',
      ),
    ),
    'taxonomy_term' => array(
      'values' => array(
        'channels' => 'channels',
        'columns' => 'columns',
      ),
      'options' => array(
        'term_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'maxim_seo-channel_description' => array(
          'module' => 'maxim_seo',
          'delta' => 'channel_description',
          'region' => 'content',
          'weight' => '10',
        ),
        'views-maximtv_browser-maxim_tv_latest' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maxim_tv_latest',
          'region' => 'sidebar_first',
          'weight' => '-36',
        ),
        'views-home_page-promo_block_2' => array(
          'module' => 'views',
          'delta' => 'home_page-promo_block_2',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-home_page-sxsw_block' => array(
          'module' => 'views',
          'delta' => 'home_page-sxsw_block',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'dart-dart-tag-dart_big_box' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_big_box',
          'region' => 'sidebar_second',
          'weight' => '-108',
        ),
        'boxes-follow_us' => array(
          'module' => 'boxes',
          'delta' => 'follow_us',
          'region' => 'sidebar_second',
          'weight' => '-107',
        ),
        'views-latest_videos-block_1' => array(
          'module' => 'views',
          'delta' => 'latest_videos-block_1',
          'region' => 'sidebar_second',
          'weight' => '-106',
        ),
        'boxes-maxim_newsletter' => array(
          'module' => 'boxes',
          'delta' => 'maxim_newsletter',
          'region' => 'sidebar_second',
          'weight' => '-105',
        ),
        'boxes-in_this_issue' => array(
          'module' => 'boxes',
          'delta' => 'in_this_issue',
          'region' => 'sidebar_second',
          'weight' => '-104',
        ),
        'boxes-mostrecenttweets' => array(
          'module' => 'boxes',
          'delta' => 'mostrecenttweets',
          'region' => 'sidebar_second',
          'weight' => '-103',
        ),
        'boxes-facebookrecentactivity' => array(
          'module' => 'boxes',
          'delta' => 'facebookrecentactivity',
          'region' => 'sidebar_second',
          'weight' => '-102',
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
  t('Channel Pages');
  t('channel page');
  $export['channel_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'content_wide';
  $context->description = 'Wide content template';
  $context->tag = 'Templates';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'page' => 'page',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'maxim-hot-100-2012*' => 'maxim-hot-100-2012*',
        'hometown-hotties-entry-form-2013*' => 'hometown-hotties-entry-form-2013*',
        'hometown-hotties-entry-form-2014*' => 'hometown-hotties-entry-form-2014*',
        'hotties-admin*' => 'hotties-admin*',
        'cuervovegasgetaway*' => 'cuervovegasgetaway*',
        'hometown-hotties/2013*' => 'hometown-hotties/2013*',
        'careers/*' => 'careers/*',
        'hot100/2013/*' => 'hot100/2013/*',
        'devils-cut/gallery*' => 'devils-cut/gallery*',
        'webform-results/*' => 'webform-results/*',
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
  t('Templates');
  t('Wide content template');
  $export['content_wide'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'corporate_pages';
  $context->description = 'place blocks for corporate pages';
  $context->tag = 'Templates';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        14019 => 14019,
        14049 => 14049,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
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
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Templates');
  t('place blocks for corporate pages');
  $export['corporate_pages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'devils_cut_2012';
  $context->description = 'Devil\'s Cut 2012 Slideshows';
  $context->tag = 'Devil\'s Cut';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'slideshow' => 'slideshow',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'node_taxonomy' => array(
      'values' => array(
        18796 => 18796,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-devils_cut_2012_sidebar' => array(
          'module' => 'boxes',
          'delta' => 'devils_cut_2012_sidebar',
          'region' => 'sidebar_second',
          'weight' => '-114',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Devil\'s Cut');
  t('Devil\'s Cut 2012 Slideshows');
  $export['devils_cut_2012'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'entertainment_gaming_zone';
  $context->description = 'entertainment gaming channel ';
  $context->tag = 'Ad Zone';
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
        'slideshow/gaming/*' => 'slideshow/gaming/*',
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
  t('Ad Zone');
  t('entertainment gaming channel ');
  $export['entertainment_gaming_zone'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'entertainment_movies_zone';
  $context->description = 'entertainment movies channel ';
  $context->tag = 'Ad Zone';
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
        'slideshow/movies/*' => 'slideshow/movies/*',
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
  t('Ad Zone');
  t('entertainment movies channel ');
  $export['entertainment_movies_zone'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'entertainment_music_zone';
  $context->description = 'entertainment movies channel ';
  $context->tag = 'Ad Zone';
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
        'slideshow/music/*' => 'slideshow/music/*',
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
  t('Ad Zone');
  t('entertainment movies channel ');
  $export['entertainment_music_zone'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'entertainment_tv_zone';
  $context->description = 'entertainment tv channel ';
  $context->tag = 'Ad Zone';
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
        'slideshow/tv/*' => 'slideshow/tv/*',
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
  t('Ad Zone');
  t('entertainment tv channel ');
  $export['entertainment_tv_zone'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'entertainment_zone';
  $context->description = 'entertainment channel ';
  $context->tag = 'Ad Zone';
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
        'slideshow/entertainment/*' => 'slideshow/entertainment/*',
        'slideshow/comics/*' => 'slideshow/comics/*',
        'slideshow/events/*' => 'slideshow/events/*',
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
  t('Ad Zone');
  t('entertainment channel ');
  $export['entertainment_zone'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'funny_zone';
  $context->description = 'funny channel';
  $context->tag = 'Ad Zone';
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
        'funny/*' => 'funny/*',
        'jokes/*' => 'jokes/*',
        'comedians/*' => 'comedians/*',
        'found-porn/*' => 'found-porn/*',
        'beat-this-caption/*' => 'beat-this-caption/*',
        'the-dump-blog/*' => 'the-dump-blog/*',
        'stupid-clips/*' => 'stupid-clips/*',
        'slideshow/funny/*' => 'slideshow/funny/*',
        'slideshow/comedians/*' => 'slideshow/comedians/*',
        'slideshow/found-porn/*' => 'slideshow/found-porn/*',
        'slideshow/stupid-clips/*' => 'slideshow/stupid-clips/*',
        'slideshow/the-dump-blog/*' => 'slideshow/the-dump-blog/*',
        'slideshow/beat-this-caption/*' => 'slideshow/beat-this-caption/*',
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
  t('Ad Zone');
  t('funny channel');
  $export['funny_zone'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'gadgets_and_rides_zone';
  $context->description = 'gadgets and rides channel';
  $context->tag = 'Ad Zone';
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
        'gadgets-rides/*' => 'gadgets-rides/*',
        'slideshow/gadgets-rides/*' => 'slideshow/gadgets-rides/*',
        'slideshow/gadgets/*' => 'slideshow/gadgets/*',
        'slideshow/rides/*' => 'slideshow/rides/*',
        'slideshow/torture-tests/*' => 'slideshow/torture-tests/*',
        'slideshow/gift-guides/*' => 'slideshow/gift-guides/*',
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
  t('Ad Zone');
  t('gadgets and rides channel');
  $export['gadgets_and_rides_zone'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'girls_girls_of_maxim_zone';
  $context->description = 'girls of maxim channel';
  $context->tag = 'Ad Zone';
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
        'slideshow/girls-of-maxim/*' => 'slideshow/girls-of-maxim/*',
      ),
    ),
  );
  $context->reactions = array(
    'context_metadata' => array(
      'metadata_title' => 'Exclusive, Sexy Photos From the Pages of Maxim | Maxim Cover Girls',
      'metadata_description' => 'Browse galleries of sexy photos of women from the pages of Maxim Magazine, as well as exclusive online photo shoots and behind-the-scenes videos. ',
      'metadata_keywords' => 'hot girls, hot babes, sexy girls',
      'metadata_canonical' => 'http://www.maxim.com/girls/girls-of-maxim',
      'metadata_h1' => '',
    ),
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'girls__girls_of_maxim',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ad Zone');
  t('girls of maxim channel');
  $export['girls_girls_of_maxim_zone'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'girls_hometown_hotties';
  $context->description = 'hometown hotties channel';
  $context->tag = 'Channel Pages';
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
        'slideshow/hometown-hotties/*' => 'slideshow/hometown-hotties/*',
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
  t('Channel Pages');
  t('hometown hotties channel');
  $export['girls_hometown_hotties'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'girls_hot_100';
  $context->description = 'hot 100 channel';
  $context->tag = 'Channel Pages';
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
        'hot-100/2012' => 'hot-100/2012',
        'slideshow/hot100/*' => 'slideshow/hot100/*',
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
  t('Channel Pages');
  t('hot 100 channel');
  $export['girls_hot_100'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'girls_todays_girl';
  $context->description = 'today\'s girl channel';
  $context->tag = 'Channel Pages';
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
        'slideshow/todays-girl/*' => 'slideshow/todays-girl/*',
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
  t('Channel Pages');
  t('today\'s girl channel');
  $export['girls_todays_girl'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'girls_zone';
  $context->description = 'girls channel';
  $context->tag = 'Ad Zone';
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
        'girls/*' => 'girls/*',
        'slideshow/girls/*' => 'slideshow/girls/*',
        '~girls/girls-of-maxim' => '~girls/girls-of-maxim',
        '~girls/girls-of-maxim/*' => '~girls/girls-of-maxim/*',
        '~slideshow/girls-of-maxim/*' => '~slideshow/girls-of-maxim/*',
        '~girls/todays-girl' => '~girls/todays-girl',
        '~girls/todays-girl/*' => '~girls/todays-girl/*',
        '~slideshow/todays-girl/*' => '~slideshow/todays-girl/*',
        '~girls/hometown-hotties' => '~girls/hometown-hotties',
        '~girls/hometown-hotties/*' => '~girls/hometown-hotties/*',
        '~slideshow/hometown-hotties/*' => '~slideshow/hometown-hotties/*',
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
  t('Ad Zone');
  t('girls channel');
  $export['girls_zone'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = 'homepage';
  $context->tag = 'Channel Pages';
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
        'maxim_seo-channel_description' => array(
          'module' => 'maxim_seo',
          'delta' => 'channel_description',
          'region' => 'content',
          'weight' => '10',
        ),
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
        'views-home_page-buzz_of_the_day' => array(
          'module' => 'views',
          'delta' => 'home_page-buzz_of_the_day',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-home_page-promo_block_2' => array(
          'module' => 'views',
          'delta' => 'home_page-promo_block_2',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'views-home_page-sxsw_block' => array(
          'module' => 'views',
          'delta' => 'home_page-sxsw_block',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'views-home_page-in_the_magazine' => array(
          'module' => 'views',
          'delta' => 'home_page-in_the_magazine',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'views-home_page-reviews' => array(
          'module' => 'views',
          'delta' => 'home_page-reviews',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'dart-dart-tag-dart_big_box' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_big_box',
          'region' => 'sidebar_second',
          'weight' => '-107',
        ),
        'boxes-follow_us' => array(
          'module' => 'boxes',
          'delta' => 'follow_us',
          'region' => 'sidebar_second',
          'weight' => '-104',
        ),
        'views-latest_videos-block_1' => array(
          'module' => 'views',
          'delta' => 'latest_videos-block_1',
          'region' => 'sidebar_second',
          'weight' => '-103',
        ),
        'boxes-maxim_newsletter' => array(
          'module' => 'boxes',
          'delta' => 'maxim_newsletter',
          'region' => 'sidebar_second',
          'weight' => '-102',
        ),
        'boxes-in_this_issue' => array(
          'module' => 'boxes',
          'delta' => 'in_this_issue',
          'region' => 'sidebar_second',
          'weight' => '-101',
        ),
        'boxes-mostrecenttweets' => array(
          'module' => 'boxes',
          'delta' => 'mostrecenttweets',
          'region' => 'sidebar_second',
          'weight' => '-100',
        ),
        'boxes-facebookrecentactivity' => array(
          'module' => 'boxes',
          'delta' => 'facebookrecentactivity',
          'region' => 'sidebar_second',
          'weight' => '-99',
        ),
        'boxes-partner_links_side_header' => array(
          'module' => 'boxes',
          'delta' => 'partner_links_side_header',
          'region' => 'sidebar_second',
          'weight' => '-98',
        ),
        'views-partnerlinks_s-link_heavy_s' => array(
          'module' => 'views',
          'delta' => 'partnerlinks_s-link_heavy_s',
          'region' => 'sidebar_second',
          'weight' => '-96',
        ),
        'views-partnerlinks_s-links_ybarker_s' => array(
          'module' => 'views',
          'delta' => 'partnerlinks_s-links_ybarker_s',
          'region' => 'sidebar_second',
          'weight' => '-95',
        ),
        'views-partnerlinks_s-links_breport_s' => array(
          'module' => 'views',
          'delta' => 'partnerlinks_s-links_breport_s',
          'region' => 'sidebar_second',
          'weight' => '-94',
        ),
        'boxes-crowd_ignite' => array(
          'module' => 'boxes',
          'delta' => 'crowd_ignite',
          'region' => 'sidebar_second',
          'weight' => '-97',
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
  t('Channel Pages');
  t('homepage');
  $export['homepage'] = $context;

  $context = new stdClass();
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
        'maximtv/player/*' => 'maximtv/player/*',
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
          'weight' => '-44',
        ),
        'boxes-follow_us' => array(
          'module' => 'boxes',
          'delta' => 'follow_us',
          'region' => 'sidebar_second',
          'weight' => '-43',
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
          'weight' => '-47',
        ),
        'views-maximtv_browser-maximtv_sports' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maximtv_sports',
          'region' => 'wide_feature',
          'weight' => '-46',
        ),
        'views-maximtv_browser-maximtv_enter' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maximtv_enter',
          'region' => 'wide_feature',
          'weight' => '-45',
        ),
        'views-maximtv_browser-maximtv_gadgets' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maximtv_gadgets',
          'region' => 'wide_feature',
          'weight' => '-44',
        ),
        'views-maximtv_browser-maximtv_upkeep' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maximtv_upkeep',
          'region' => 'wide_feature',
          'weight' => '-43',
        ),
        'views-maximtv_browser-maximtv_vices' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maximtv_vices',
          'region' => 'wide_feature',
          'weight' => '-42',
        ),
        'views-maximtv_browser-maximtv_tough' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maximtv_tough',
          'region' => 'wide_feature',
          'weight' => '-41',
        ),
        'views-maximtv_browser-maximtv_funny' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maximtv_funny',
          'region' => 'wide_feature',
          'weight' => '-40',
        ),
        'boxes-slingshot_video' => array(
          'module' => 'boxes',
          'delta' => 'slingshot_video',
          'region' => 'wide_feature',
          'weight' => '-39',
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

  $context = new stdClass();
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
          'weight' => '-44',
        ),
        'boxes-follow_us' => array(
          'module' => 'boxes',
          'delta' => 'follow_us',
          'region' => 'sidebar_second',
          'weight' => '-43',
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
          'weight' => '-47',
        ),
        'boxes-slingshot_video' => array(
          'module' => 'boxes',
          'delta' => 'slingshot_video',
          'region' => 'wide_feature',
          'weight' => '-46',
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

  $context = new stdClass();
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

  $context = new stdClass();
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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_standard';
  $context->description = 'Sitewide for the standard template';
  $context->tag = 'Global';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~uk_content_page' => '~uk_content_page',
      ),
    ),
    'path' => array(
      'values' => array(
        '~gallery/*' => '~gallery/*',
        '~slideshow/*' => '~slideshow/*',
        '~hotties-2013-admin*' => '~hotties-2013-admin*',
        '~uk' => '~uk',
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
        'menu_block-dropdown-menu-1' => array(
          'module' => 'menu_block',
          'delta' => 'dropdown-menu-1',
          'region' => 'menu',
          'weight' => '-10',
        ),
        'menu_block-subnav-menu-1' => array(
          'module' => 'menu_block',
          'delta' => 'subnav-menu-1',
          'region' => 'submenu',
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

  $context = new stdClass();
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

  $context = new stdClass();
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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sports_zone';
  $context->description = 'sports channel';
  $context->tag = 'Ad Zone';
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
        'sports/*' => 'sports/*',
        'slideshow/sports/*' => 'slideshow/sports/*',
        'slideshow/the-big-leagues/*' => 'slideshow/the-big-leagues/*',
        'slideshow/ufc/*' => 'slideshow/ufc/*',
        'slideshow/other/*' => 'slideshow/other/*',
        'slideshow/girls-of-sports/*' => 'slideshow/girls-of-sports/*',
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
  t('Ad Zone');
  t('sports channel');
  $export['sports_zone'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'standard_content';
  $context->description = 'standard content';
  $context->tag = 'Templates';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
        'blog' => 'blog',
        'celebrity_profile' => 'celebrity_profile',
        'joke' => 'joke',
        'link_stub' => 'link_stub',
        'list' => 'list',
        'personality_test' => 'personality_test',
        'poll' => 'poll',
        'review' => 'review',
        'slideshow' => 'slideshow',
        'webform' => 'webform',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        '~maxim-hot-100-2012' => '~maxim-hot-100-2012',
        '~hometown-hotties-entry-form-2013' => '~hometown-hotties-entry-form-2013',
        '~hometown-hotties-entry-form-2014' => '~hometown-hotties-entry-form-2014',
        '~oscarsmadness' => '~oscarsmadness',
        '~hotties-admin*' => '~hotties-admin*',
        '~cuervovegasgetaway' => '~cuervovegasgetaway',
        '~hometown-hotties/2013*' => '~hometown-hotties/2013*',
        '~careers/*' => '~careers/*',
        '~devils-cut/gallery*' => '~devils-cut/gallery*',
        '~hot100/2013/*' => '~hot100/2013/*',
        '~webform-results/*' => '~webform-results/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-magazine_subscription_link' => array(
          'module' => 'boxes',
          'delta' => 'magazine_subscription_link',
          'region' => 'content',
          'weight' => '105',
        ),
        'dart-dart-tag-dart_big_box' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_big_box',
          'region' => 'sidebar_second',
          'weight' => '-108',
        ),
        'boxes-follow_us' => array(
          'module' => 'boxes',
          'delta' => 'follow_us',
          'region' => 'sidebar_second',
          'weight' => '-104',
        ),
        'views-latest_videos-block_1' => array(
          'module' => 'views',
          'delta' => 'latest_videos-block_1',
          'region' => 'sidebar_second',
          'weight' => '-103',
        ),
        'boxes-in_this_issue' => array(
          'module' => 'boxes',
          'delta' => 'in_this_issue',
          'region' => 'sidebar_second',
          'weight' => '-101',
        ),
        'boxes-facebookrecentactivity' => array(
          'module' => 'boxes',
          'delta' => 'facebookrecentactivity',
          'region' => 'sidebar_second',
          'weight' => '-100',
        ),
        'boxes-mostrecenttweets' => array(
          'module' => 'boxes',
          'delta' => 'mostrecenttweets',
          'region' => 'sidebar_second',
          'weight' => '-99',
        ),
        'boxes-maxim_newsletter' => array(
          'module' => 'boxes',
          'delta' => 'maxim_newsletter',
          'region' => 'sidebar_second',
          'weight' => '-102',
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
        'boxes-slingshot_widget' => array(
          'module' => 'boxes',
          'delta' => 'slingshot_widget',
          'region' => 'postscript_first',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'content_and_sidebar',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Templates');
  t('standard content');
  $export['standard_content'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tough_sh_zone';
  $context->description = 'tough s#&t channel';
  $context->tag = 'Ad Zone';
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
        'tough/*' => 'tough/*',
        'slideshow/tough/*' => 'slideshow/tough/*',
        'slideshow/military/*' => 'slideshow/military/*',
        'slideshow/maximum-warrior/*' => 'slideshow/maximum-warrior/*',
        'slideshow/true-crime/*' => 'slideshow/true-crime/*',
        'slideshow/scars/*' => 'slideshow/scars/*',
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
  t('Ad Zone');
  t('tough s#&t channel');
  $export['tough_sh_zone'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'uk_channel_page';
  $context->description = 'UK channel page';
  $context->tag = 'Channel Pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'uk' => 'uk',
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
        'menu_block-dropdown-menu-1' => array(
          'module' => 'menu_block',
          'delta' => 'dropdown-menu-1',
          'region' => 'menu',
          'weight' => '-10',
        ),
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'menu',
          'weight' => '-10',
        ),
        'menu_block-subnav-menu-1' => array(
          'module' => 'menu_block',
          'delta' => 'subnav-menu-1',
          'region' => 'submenu',
          'weight' => '-10',
        ),
        'views-maximtv_browser-maxim_tv_latest' => array(
          'module' => 'views',
          'delta' => 'maximtv_browser-maxim_tv_latest',
          'region' => 'sidebar_first',
          'weight' => '-36',
        ),
        'views-home_page-sxsw_block' => array(
          'module' => 'views',
          'delta' => 'home_page-sxsw_block',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-home_page-promo_block_2' => array(
          'module' => 'views',
          'delta' => 'home_page-promo_block_2',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'dart-dart-tag-dart_big_box' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_big_box',
          'region' => 'sidebar_second',
          'weight' => '-111',
        ),
        'boxes-follow_us' => array(
          'module' => 'boxes',
          'delta' => 'follow_us',
          'region' => 'sidebar_second',
          'weight' => '-110',
        ),
        'views-latest_videos-block_1' => array(
          'module' => 'views',
          'delta' => 'latest_videos-block_1',
          'region' => 'sidebar_second',
          'weight' => '-109',
        ),
        'boxes-maxim_newsletter' => array(
          'module' => 'boxes',
          'delta' => 'maxim_newsletter',
          'region' => 'sidebar_second',
          'weight' => '-108',
        ),
        'boxes-in_this_issue' => array(
          'module' => 'boxes',
          'delta' => 'in_this_issue',
          'region' => 'sidebar_second',
          'weight' => '-107',
        ),
        'boxes-mostrecenttweets' => array(
          'module' => 'boxes',
          'delta' => 'mostrecenttweets',
          'region' => 'sidebar_second',
          'weight' => '-106',
        ),
        'boxes-facebookrecentactivity' => array(
          'module' => 'boxes',
          'delta' => 'facebookrecentactivity',
          'region' => 'sidebar_second',
          'weight' => '-105',
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
        'aggregator-feed-1' => array(
          'module' => 'aggregator',
          'delta' => 'feed-1',
          'region' => 'partners_first',
          'weight' => '-10',
        ),
        'aggregator-feed-6' => array(
          'module' => 'aggregator',
          'delta' => 'feed-6',
          'region' => 'partners_second',
          'weight' => '-10',
        ),
        'aggregator-feed-16' => array(
          'module' => 'aggregator',
          'delta' => 'feed-16',
          'region' => 'partners_third',
          'weight' => '-10',
        ),
        'aggregator-feed-21' => array(
          'module' => 'aggregator',
          'delta' => 'feed-21',
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
        'views-846b1ee875dd7657be7831911a911786' => array(
          'module' => 'views',
          'delta' => '846b1ee875dd7657be7831911a911786',
          'region' => 'feature',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Channel Pages');
  t('UK channel page');
  $export['uk_channel_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'uk_content_page';
  $context->description = 'UK Content Pages';
  $context->tag = 'Templates';
  $context->conditions = array();
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-uk_channel_link' => array(
          'module' => 'boxes',
          'delta' => 'uk_channel_link',
          'region' => 'content',
          'weight' => '50',
        ),
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
        'menu_block-dropdown-menu-1' => array(
          'module' => 'menu_block',
          'delta' => 'dropdown-menu-1',
          'region' => 'menu',
          'weight' => '-10',
        ),
        'menu_block-subnav-menu-1' => array(
          'module' => 'menu_block',
          'delta' => 'subnav-menu-1',
          'region' => 'submenu',
          'weight' => '-10',
        ),
        'aggregator-feed-1' => array(
          'module' => 'aggregator',
          'delta' => 'feed-1',
          'region' => 'partners_first',
          'weight' => '-10',
        ),
        'aggregator-feed-6' => array(
          'module' => 'aggregator',
          'delta' => 'feed-6',
          'region' => 'partners_second',
          'weight' => '-10',
        ),
        'aggregator-feed-16' => array(
          'module' => 'aggregator',
          'delta' => 'feed-16',
          'region' => 'partners_third',
          'weight' => '-10',
        ),
        'aggregator-feed-21' => array(
          'module' => 'aggregator',
          'delta' => 'feed-21',
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
        'boxes-top_link_uk_channel' => array(
          'module' => 'boxes',
          'delta' => 'top_link_uk_channel',
          'region' => 'feature',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Templates');
  t('UK Content Pages');
  $export['uk_content_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'upkeep_zone';
  $context->description = 'upkeep channel';
  $context->tag = 'Ad Zone';
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
        'upkeep/*' => 'upkeep/*',
        'slideshow/upkeep/*' => 'slideshow/upkeep/*',
        'slideshow/clothes/*' => 'slideshow/clothes/*',
        'slideshow/grooming/*' => 'slideshow/grooming/*',
        'slideshow/fitness/*' => 'slideshow/fitness/*',
        'slideshow/money/*' => 'slideshow/money/*',
        'slideshow/how-to/*' => 'slideshow/how-to/*',
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
  t('Ad Zone');
  t('upkeep channel');
  $export['upkeep_zone'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vices_zone';
  $context->description = 'vices channel';
  $context->tag = 'Ad Zone';
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
        'vices/*' => 'vices/*',
        'slideshow/booze/*' => 'slideshow/booze/*',
        'slideshow/food/*' => 'slideshow/food/*',
        'slideshow/travel/*' => 'slideshow/travel/*',
        'slideshow/gambling/*' => 'slideshow/gambling/*',
        'slideshow/sex-relationships/*' => 'slideshow/sex-relationships/*',
        'slideshow/maxim-parties/*' => 'slideshow/maxim-parties/*',
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
  t('Ad Zone');
  t('vices channel');
  $export['vices_zone'] = $context;

  return $export;
}
