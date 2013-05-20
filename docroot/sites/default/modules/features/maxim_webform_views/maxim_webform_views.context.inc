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
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-hth_axe_sponsor' => array(
          'module' => 'boxes',
          'delta' => 'hth_axe_sponsor',
          'region' => 'header_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Girls who are in the current HTH campaign');
  t('Hometown Hotties');
  $export['2013_hth_curr_yr'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '2013_hth_profile_finals';
  $context->description = '2013 Hometown Hottie Profiles Finals';
  $context->tag = 'Hometown Hotties';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        14117 => 14117,
      ),
      'options' => array(
        'node_form' => '1',
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
          'weight' => '-10',
        ),
        'views-f7196a9662c66fc5dc39cff0ddc514b2' => array(
          'module' => 'views',
          'delta' => 'f7196a9662c66fc5dc39cff0ddc514b2',
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
  t('2013 Hometown Hottie Profiles Finals');
  t('Hometown Hotties');
  $export['2013_hth_profile_finals'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '2013_hth_profile_semi_finals';
  $context->description = '2013 Hometown Hottie Profiles Semi Finals';
  $context->tag = 'Hometown Hotties';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~2013_hth_profile_finals' => '~2013_hth_profile_finals',
      ),
    ),
    'node_taxonomy' => array(
      'values' => array(
        14116 => 14116,
      ),
      'options' => array(
        'node_form' => '1',
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
          'weight' => '-10',
        ),
        'views-82dfb0800728b957ca38b363f4c7dfb6' => array(
          'module' => 'views',
          'delta' => '82dfb0800728b957ca38b363f4c7dfb6',
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
  t('2013 Hometown Hottie Profiles Semi Finals');
  t('Hometown Hotties');
  $export['2013_hth_profile_semi_finals'] = $context;

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
        '~2013_hth_profile_finals' => '~2013_hth_profile_finals',
        '~2013_hth_profile_semi_finals' => '~2013_hth_profile_semi_finals',
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
        'views-1b945362ac73872ea055dfb27653f800' => array(
          'module' => 'views',
          'delta' => '1b945362ac73872ea055dfb27653f800',
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
        '~2013_hth_profile_finals' => '~2013_hth_profile_finals',
        '~2013_hth_profile_semi_finals' => '~2013_hth_profile_semi_finals',
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
        'views-60b1c93cc9c15568414e706d7d71720b' => array(
          'module' => 'views',
          'delta' => '60b1c93cc9c15568414e706d7d71720b',
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
        '~2013_hth_profile_finals' => '~2013_hth_profile_finals',
        '~2013_hth_profile_semi_finals' => '~2013_hth_profile_semi_finals',
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
        'views-538846699ecdbc0969ffd1de55652517' => array(
          'module' => 'views',
          'delta' => '538846699ecdbc0969ffd1de55652517',
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
        '~2013_hth_profile_finals' => '~2013_hth_profile_finals',
        '~2013_hth_profile_semi_finals' => '~2013_hth_profile_semi_finals',
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
        'views-5f308155c90cda76675e29006c919619' => array(
          'module' => 'views',
          'delta' => '5f308155c90cda76675e29006c919619',
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
        '~2013_hth_profile_finals' => '~2013_hth_profile_finals',
        '~2013_hth_profile_semi_finals' => '~2013_hth_profile_semi_finals',
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
        'views-995785d3962506d1da2de67f65bab7b6' => array(
          'module' => 'views',
          'delta' => '995785d3962506d1da2de67f65bab7b6',
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
  $context->name = '2014_hth_curr_yr';
  $context->description = 'Girls who are in the 2014 HTH campaign';
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
        22026 => 22026,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'hth_voting_resource-hth_nav_header_2014' => array(
          'module' => 'hth_voting_resource',
          'delta' => 'hth_nav_header_2014',
          'region' => 'header_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Girls who are in the 2014 HTH campaign');
  t('Hometown Hotties');
  $export['2014_hth_curr_yr'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '2014_hth_profile_finals';
  $context->description = '2014 Hometown Hottie Profiles Finals';
  $context->tag = 'Hometown Hotties';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        14117 => 14117,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ea329c61b1cc9336652863ad60697976' => array(
          'module' => 'views',
          'delta' => 'ea329c61b1cc9336652863ad60697976',
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
  t('2014 Hometown Hottie Profiles Finals');
  t('Hometown Hotties');
  $export['2014_hth_profile_finals'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '2014_hth_profile_semi_finals';
  $context->description = '2014 Hometown Hottie Profiles Semi Finals';
  $context->tag = 'Hometown Hotties';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~2014_hth_profile_finals' => '~2014_hth_profile_finals',
      ),
    ),
    'node_taxonomy' => array(
      'values' => array(
        14116 => 14116,
        22026 => 22026,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
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
  t('2014 Hometown Hottie Profiles Semi Finals');
  t('Hometown Hotties');
  $export['2014_hth_profile_semi_finals'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '2014_hth_profile_wk_1';
  $context->description = '2014 Hometown Hottie Profiles week 1';
  $context->tag = 'Hometown Hotties';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '2014_hth_curr_yr' => '2014_hth_curr_yr',
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
        'views-1edb6a5e7874cb65fe22ef089c3f169b' => array(
          'module' => 'views',
          'delta' => '1edb6a5e7874cb65fe22ef089c3f169b',
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
  t('2014 Hometown Hottie Profiles week 1');
  t('Hometown Hotties');
  $export['2014_hth_profile_wk_1'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '2014_hth_profile_wk_2';
  $context->description = '2014 Hometown Hottie Profiles week 2';
  $context->tag = 'Hometown Hotties';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '2014_hth_curr_yr' => '2014_hth_curr_yr',
        '~2014_hth_profile_finals' => '~2014_hth_profile_finals',
        '~2014_hth_profile_semi_finals' => '~2014_hth_profile_semi_finals',
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
        'views-d5bcdb1fc61a0bac5856860bcd2b376c' => array(
          'module' => 'views',
          'delta' => 'd5bcdb1fc61a0bac5856860bcd2b376c',
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
  t('2014 Hometown Hottie Profiles week 2');
  t('Hometown Hotties');
  $export['2014_hth_profile_wk_2'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '2014_hth_profile_wk_3';
  $context->description = '2014 Hometown Hottie Profiles week 3';
  $context->tag = 'Hometown Hotties';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '2014_hth_curr_yr' => '2014_hth_curr_yr',
        '~2014_hth_profile_finals' => '~2014_hth_profile_finals',
        '~2014_hth_profile_semi_finals' => '~2014_hth_profile_semi_finals',
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
  t('2014 Hometown Hottie Profiles week 3');
  t('Hometown Hotties');
  $export['2014_hth_profile_wk_3'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '2014_hth_profile_wk_4';
  $context->description = '2014 Hometown Hottie Profiles week 4';
  $context->tag = 'Hometown Hotties';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '2014_hth_curr_yr' => '2014_hth_curr_yr',
        '~2014_hth_profile_finals' => '~2014_hth_profile_finals',
        '~2014_hth_profile_semi_finals' => '~2014_hth_profile_semi_finals',
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
        'views-91b6faa09b83095b616deb4f82c18169' => array(
          'module' => 'views',
          'delta' => '91b6faa09b83095b616deb4f82c18169',
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
  t('2014 Hometown Hottie Profiles week 4');
  t('Hometown Hotties');
  $export['2014_hth_profile_wk_4'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '2014_hth_profile_wk_5';
  $context->description = '2014 Hometown Hottie Profiles week 5';
  $context->tag = 'Hometown Hotties';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '2014_hth_curr_yr' => '2014_hth_curr_yr',
        '~2014_hth_profile_finals' => '~2014_hth_profile_finals',
        '~2014_hth_profile_semi_finals' => '~2014_hth_profile_semi_finals',
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
        'views-816321585b7e757fc44dfb6f544910d6' => array(
          'module' => 'views',
          'delta' => '816321585b7e757fc44dfb6f544910d6',
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
  t('2014 Hometown Hottie Profiles week 5');
  t('Hometown Hotties');
  $export['2014_hth_profile_wk_5'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '2014_hth_weekly_grid';
  $context->description = '2014 Weekly grid landing page';
  $context->tag = 'Hometown Hotties';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hometown_hotties_2013:hotties_2013_results' => 'hometown_hotties_2013:hotties_2013_results',
        'hometown_hotties_2013:hth_2014_finals' => 'hometown_hotties_2013:hth_2014_finals',
        'hometown_hotties_2013:hth_2014_semi' => 'hometown_hotties_2013:hth_2014_semi',
        'hometown_hotties_2013:hth_2014_w1' => 'hometown_hotties_2013:hth_2014_w1',
        'hometown_hotties_2013:hth_2014_w2' => 'hometown_hotties_2013:hth_2014_w2',
        'hometown_hotties_2013:hth_2014_w3' => 'hometown_hotties_2013:hth_2014_w3',
        'hometown_hotties_2013:hth_2014_w4' => 'hometown_hotties_2013:hth_2014_w4',
        'hometown_hotties_2013:hth_2014_w5' => 'hometown_hotties_2013:hth_2014_w5',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'hth_voting_resource-hth_nav_header_2014' => array(
          'module' => 'hth_voting_resource',
          'delta' => 'hth_nav_header_2014',
          'region' => 'header_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('2014 Weekly grid landing page');
  t('Hometown Hotties');
  $export['2014_hth_weekly_grid'] = $context;

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
        'dart-dart-tag-dart_big_box' => array(
          'module' => 'dart',
          'delta' => 'dart-tag-dart_big_box',
          'region' => 'sidebar_second',
          'weight' => '-120',
        ),
        'gmap_location-0' => array(
          'module' => 'gmap_location',
          'delta' => '0',
          'region' => 'sidebar_second',
          'weight' => '-119',
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
    'context' => array(
      'values' => array(
        '~2014_hth_curr_yr' => '~2014_hth_curr_yr',
      ),
    ),
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
          'weight' => '-122',
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
  $context->name = 'hth_map';
  $context->description = 'Display full HTH Gmap';
  $context->tag = 'Hometown Hotties';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hometown_hotties_full_gmap' => 'hometown_hotties_full_gmap',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'maxim_gmap_extensions-gmap_geolocate' => array(
          'module' => 'maxim_gmap_extensions',
          'delta' => 'gmap_geolocate',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Display full HTH Gmap');
  t('Hometown Hotties');
  $export['hth_map'] = $context;

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
          'weight' => '-120',
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
