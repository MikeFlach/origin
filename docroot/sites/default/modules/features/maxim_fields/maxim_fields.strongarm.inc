<?php
/**
 * @file
 * maxim_fields.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function maxim_fields_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'brightcove_mapi_path';
  $strongarm->value = 'sites/all/libraries/brightcove';
  $export['brightcove_mapi_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'brightcove_read_api_key';
  $strongarm->value = 'CX1YvsC6MvJ-6FddP41yjMQxH1sktJjDEH4QV0p-RQPZKyLwkfgCow..';
  $export['brightcove_read_api_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'brightcove_write_api_key';
  $strongarm->value = 'CX1YvsC6MvJ-6FddP41yjMQxH1sktJjDb_COaVlPdgh9mTATqozy4Q..';
  $export['brightcove_write_api_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_fields_extra';
  $strongarm->value = 1;
  $export['ds_extras_fields_extra'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_fields_extra_list';
  $strongarm->value = 'node|article|pagination_pager
node|review|pagination_pager
node|article|pagination_showall
node|review|pagination_showall
node|article|facebook_comments
node|page|facebook_comments
node|blog|facebook_comments
node|hotties_profile|facebook_comments
node|joke|facebook_comments
node|list|facebook_comments
node|poll|facebook_comments
node|review|facebook_comments
node|slideshow|facebook_comments
node|video|facebook_comments
node|webform|facebook_comments
node|personality_test|facebook_comments
node|personality_test|personality_test
node|article|metatags
node|blog|metatags
node|page|metatags
node|generic_profile|metatags
node|hotties_profile|metatags
node|joke|metatags
node|list|metatags
node|personality_test|metatags
node|poll|metatags
node|review|metatags
node|slideshow|metatags
node|video|metatags
node|webform|metatags';
  $export['ds_extras_fields_extra_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_field_permissions';
  $strongarm->value = 0;
  $export['ds_extras_field_permissions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_field_template';
  $strongarm->value = 1;
  $export['ds_extras_field_template'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_hidden_region';
  $strongarm->value = 0;
  $export['ds_extras_hidden_region'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_hide_page_sidebars';
  $strongarm->value = 0;
  $export['ds_extras_hide_page_sidebars'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_hide_page_title';
  $strongarm->value = 0;
  $export['ds_extras_hide_page_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_region_blocks';
  $strongarm->value = array(
    'hottie_profile_information' => array(
      'title' => 'Hottie Profile Information',
      'info' => 'node_hotties_profile_full',
    ),
    'embedded_slideshow' => array(
      'title' => 'Embedded Slideshow',
      'info' => 'node_hotties_profile_full',
    ),
    'channel' => array(
      'title' => 'Channel',
      'info' => 'node_article_full',
    ),
    'review_channel' => array(
      'title' => 'Review Channel',
      'info' => 'node_review_full',
    ),
    'slideshow_channel' => array(
      'title' => 'Slideshow Channel',
      'info' => 'node_slideshow_full',
    ),
    'blog_channel' => array(
      'title' => 'Blog Channel',
      'info' => 'node_blog_full',
    ),
    'list_channel' => array(
      'title' => 'List Channel',
      'info' => 'node_list_full',
    ),
    'joke_channel' => array(
      'title' => 'Joke Channel',
      'info' => 'node_joke_full',
    ),
    'vote_button' => array(
      'title' => 'Vote Button',
      'info' => 'node_hotties_profile_full',
    ),
    'previous_next' => array(
      'title' => 'previous_next',
      'info' => 'node_hotties_profile_full',
    ),
    'generic_profile_information' => array(
      'title' => 'Generic Profile Information',
      'info' => 'node_generic_profile_full',
    ),
    'generic_profile_slideshow' => array(
      'title' => 'Generic Profile Slideshow',
      'info' => 'node_generic_profile_full',
    ),
    'generic_vote_button' => array(
      'title' => 'Generic Vote Button',
      'info' => 'node_generic_profile_full',
    ),
    'generic_prev_next' => array(
      'title' => 'Generic Prev/Next',
      'info' => 'node_generic_profile_full',
    ),
  );
  $export['ds_extras_region_blocks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_region_to_block';
  $strongarm->value = 1;
  $export['ds_extras_region_to_block'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_switch_field';
  $strongarm->value = 0;
  $export['ds_extras_switch_field'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_switch_view_mode';
  $strongarm->value = 0;
  $export['ds_extras_switch_view_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_vd';
  $strongarm->value = 0;
  $export['ds_extras_vd'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__article';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'cck_blocks' => array(
        'custom_settings' => TRUE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'xmlsitemap' => array(
          'weight' => '30',
        ),
        'metatags' => array(
          'weight' => '40',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'metatags' => array(
          'full' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'facebook_comments' => array(
          'full' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'pagination_pager' => array(
          'full' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'pagination_showall' => array(
          'full' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__blog';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'metatags' => array(
          'full' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
        ),
        'facebook_comments' => array(
          'full' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__hotties_profile';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'cck_blocks' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '18',
        ),
        'xmlsitemap' => array(
          'weight' => '19',
        ),
        'metatags' => array(
          'weight' => '1',
        ),
        'redirect' => array(
          'weight' => '20',
        ),
      ),
      'display' => array(
        'metatags' => array(
          'default' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
        'facebook_comments' => array(
          'full' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__hotties_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__joke';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'metatags' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
        'facebook_comments' => array(
          'full' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__joke'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__list';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'cck_blocks' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'metatags' => array(
          'full' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
        'facebook_comments' => array(
          'full' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__page';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'metatags' => array(
          'default' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
        'facebook_comments' => array(
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__personality_test';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '1',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '3',
        ),
        'redirect' => array(
          'weight' => '4',
        ),
        'xmlsitemap' => array(
          'weight' => '2',
        ),
      ),
      'display' => array(
        'metatags' => array(
          'teaser' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
        'facebook_comments' => array(
          'full' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
        'personality_test_question' => array(
          'full' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
        'personality_test_form' => array(
          'full' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
        'personality_test' => array(
          'full' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__personality_test'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__poll';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'poll_view_voting' => array(
          'teaser' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'poll_view_results' => array(
          'teaser' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__poll'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__review';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '10',
        ),
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
        'xmlsitemap' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'metatags' => array(
          'full' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
        'facebook_comments' => array(
          'full' => array(
            'weight' => '9',
            'visible' => TRUE,
          ),
        ),
        'pagination_pager' => array(
          'full' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
        ),
        'pagination_showall' => array(
          'full' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__slideshow';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'metatags' => array(
          'full' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
        'facebook_comments' => array(
          'full' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__video';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'metatags' => array(
          'default' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
        'facebook_comments' => array(
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__video'] = $strongarm;

  return $export;
}
