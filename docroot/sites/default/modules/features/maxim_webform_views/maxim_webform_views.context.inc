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
  $context->name = '2013_hth_curr_yr';
  $context->description = 'Girls who are in the current HTH campaign';
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
        16231 => 16231,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'hometown-hotties/*' => 'hometown-hotties/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-hth_axe_sponsor' => array(
          'module' => 'boxes',
          'delta' => 'hth_axe_sponsor',
          'region' => 'header_second',
          'weight' => NULL,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Girls who are in the current HTH campaign');
  t('Hometown Hotties');
  $export['2013_hth_curr_yr'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '2013_hth_profile_wk_1';
  $context->description = '2013 Hometown Hottie Profiles week 1';
  $context->tag = 'Hometown Hotties';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '2013_hth_curr_yr' => '2013_hth_curr_yr',
      ),
    ),
    'node_taxonomy' => array(
      'values' => array(
        14092 => 14092,
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
        'ds_extras-vote_button' => array(
          'module' => 'ds_extras',
          'delta' => 'vote_button',
          'region' => 'content_container',
          'weight' => '-30',
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
  $context->name = '2013_hth_profile_wk_2';
  $context->description = '2013 Hometown Hottie Profiles week 2';
  $context->tag = 'Hometown Hotties';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '2013_hth_curr_yr' => '2013_hth_curr_yr',
      ),
    ),
    'node_taxonomy' => array(
      'values' => array(
        14107 => 14107,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-4494f857b8b9a3d13c54fddfe1400d95' => array(
          'module' => 'views',
          'delta' => '4494f857b8b9a3d13c54fddfe1400d95',
          'region' => 'wide_feature',
          'weight' => '-10',
        ),
        'ds_extras-vote_button' => array(
          'module' => 'ds_extras',
          'delta' => 'vote_button',
          'region' => 'content_container',
          'weight' => '-30',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('2013 Hometown Hottie Profiles week 2');
  t('Hometown Hotties');
  $export['2013_hth_profile_wk_2'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '2013_hth_profile_wk_3';
  $context->description = '2013 Hometown Hottie Profiles week 3';
  $context->tag = 'Hometown Hotties';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '2013_hth_curr_yr' => '2013_hth_curr_yr',
      ),
    ),
    'node_taxonomy' => array(
      'values' => array(
        14108 => 14108,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-7931077e04c6390b8c35fdbca7435469' => array(
          'module' => 'views',
          'delta' => '7931077e04c6390b8c35fdbca7435469',
          'region' => 'wide_feature',
          'weight' => '-10',
        ),
        'ds_extras-vote_button' => array(
          'module' => 'ds_extras',
          'delta' => 'vote_button',
          'region' => 'content_container',
          'weight' => '-30',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('2013 Hometown Hottie Profiles week 3');
  t('Hometown Hotties');
  $export['2013_hth_profile_wk_3'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '2013_hth_profile_wk_4';
  $context->description = '2013 Hometown Hottie Profiles week 4';
  $context->tag = 'Hometown Hotties';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '2013_hth_curr_yr' => '2013_hth_curr_yr',
      ),
    ),
    'node_taxonomy' => array(
      'values' => array(
        14109 => 14109,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ed179f28bc0d4e146352c67e32138235' => array(
          'module' => 'views',
          'delta' => 'ed179f28bc0d4e146352c67e32138235',
          'region' => 'wide_feature',
          'weight' => '-10',
        ),
        'ds_extras-vote_button' => array(
          'module' => 'ds_extras',
          'delta' => 'vote_button',
          'region' => 'content_container',
          'weight' => '-30',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('2013 Hometown Hottie Profiles week 4');
  t('Hometown Hotties');
  $export['2013_hth_profile_wk_4'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '2013_hth_profile_wk_5';
  $context->description = '2013 Hometown Hottie Profiles week 5';
  $context->tag = 'Hometown Hotties';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '2013_hth_curr_yr' => '2013_hth_curr_yr',
      ),
    ),
    'node_taxonomy' => array(
      'values' => array(
        14110 => 14110,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-dc4a2b0450a1e957ada40a29ca368883' => array(
          'module' => 'views',
          'delta' => 'dc4a2b0450a1e957ada40a29ca368883',
          'region' => 'wide_feature',
          'weight' => '-10',
        ),
        'ds_extras-vote_button' => array(
          'module' => 'ds_extras',
          'delta' => 'vote_button',
          'region' => 'content_container',
          'weight' => '-30',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('2013 Hometown Hottie Profiles week 5');
  t('Hometown Hotties');
  $export['2013_hth_profile_wk_5'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'gamer_girl_contest';
  $context->description = 'Gamer Girl Contest 2012';
  $context->tag = 'Gamer Girl';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        17801 => 17801,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'gamer_girl_voting_resource-gamer_girl_nav_header' => array(
          'module' => 'gamer_girl_voting_resource',
          'delta' => 'gamer_girl_nav_header',
          'region' => 'header_first',
          'weight' => '-101',
        ),
        'gamer_girl_voting_resource-gamer_girl_vote_button' => array(
          'module' => 'gamer_girl_voting_resource',
          'delta' => 'gamer_girl_vote_button',
          'region' => 'content_container',
          'weight' => '-30',
        ),
      ),
    ),
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'gamergirl_content',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Gamer Girl');
  t('Gamer Girl Contest 2012');
  $export['gamer_girl_contest'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'gamer_girl_finalist_grid';
  $context->description = 'Ganer girl fianlist grid header placement';
  $context->tag = 'Gamer Girl';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hometown_hotties_2013:gamer_girl_finalists' => 'hometown_hotties_2013:gamer_girl_finalists',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'gamer_girl_voting_resource-gamer_girl_nav_header' => array(
          'module' => 'gamer_girl_voting_resource',
          'delta' => 'gamer_girl_nav_header',
          'region' => 'header_first',
          'weight' => NULL,
        ),
        'dart-dart-tag-wallpaper' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-wallpaper',
          'region' => 'copyright',
          'weight' => '-10',
        ),
      ),
    ),
    'dart_settings' => array(
      'dart_site' => '',
      'dart_zone' => 'gamergirl_content',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Gamer Girl');
  t('Ganer girl fianlist grid header placement');
  $export['gamer_girl_finalist_grid'] = $context;

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
        'boxes-hth_axe_profilelink' => array(
          'module' => 'boxes',
          'delta' => 'hth_axe_profilelink',
          'region' => 'content',
          'weight' => NULL,
        ),
        'dart-dart-tag-dart_big_box' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_big_box',
          'region' => 'sidebar_second',
          'weight' => NULL,
        ),
        'gmap_location-0' => array(
          'module' => 'gmap_location',
          'delta' => 0,
          'region' => 'sidebar_second',
          'weight' => NULL,
        ),
        'ds_extras-previous_next' => array(
          'module' => 'ds_extras',
          'delta' => 'previous_next',
          'region' => 'content_container',
          'weight' => '-60',
        ),
        'ds_extras-hottie_profile_information' => array(
          'module' => 'ds_extras',
          'delta' => 'hottie_profile_information',
          'region' => 'content_container',
          'weight' => '-20',
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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hometown_hotties_profile_header';
  $context->description = 'Header for Hometown Hotties program';
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
    'path' => array(
      'values' => array(
        'hometown-hotties/*' => 'hometown-hotties/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'hth_voting_resource-hth_nav_header' => array(
          'module' => 'hth_voting_resource',
          'delta' => 'hth_nav_header',
          'region' => 'header_first',
          'weight' => NULL,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Header for Hometown Hotties program');
  t('Hometown Hotties');
  $export['hometown_hotties_profile_header'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hth_weekly_grid';
  $context->description = 'Weekly grid landing page';
  $context->tag = 'Hometown Hotties';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hometown_hotties_2013:hotties_2013_results' => 'hometown_hotties_2013:hotties_2013_results',
        'hometown_hotties_2013:hth_2013_finals' => 'hometown_hotties_2013:hth_2013_finals',
        'hometown_hotties_2013:hth_2013_semi' => 'hometown_hotties_2013:hth_2013_semi',
        'hometown_hotties_2013:hth_2013_w1' => 'hometown_hotties_2013:hth_2013_w1',
        'hometown_hotties_2013:hth_2013_w2' => 'hometown_hotties_2013:hth_2013_w2',
        'hometown_hotties_2013:hth_2013_w3' => 'hometown_hotties_2013:hth_2013_w3',
        'hometown_hotties_2013:hth_2013_w4' => 'hometown_hotties_2013:hth_2013_w4',
        'hometown_hotties_2013:hth_2013_w5' => 'hometown_hotties_2013:hth_2013_w5',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'hth_voting_resource-hth_nav_header' => array(
          'module' => 'hth_voting_resource',
          'delta' => 'hth_nav_header',
          'region' => 'header_first',
          'weight' => NULL,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Hometown Hotties');
  t('Weekly grid landing page');
  $export['hth_weekly_grid'] = $context;

  return $export;
}
