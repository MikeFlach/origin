<?php
/**
 * @file
 * maxim_fields.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function maxim_fields_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_post_date_medium_no_time',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_channel' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h3',
          'ow-cl' => 'article-channel',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|article|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|slideshow|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'slideshow';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_post_date_medium_no_time',
    ),
  );
  $export['node|slideshow|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function maxim_fields_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'hotties_previous_next';
  $ds_field->label = 'Hotties - Previous/Next';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<div class="clearfix">
  <div class="hottie-prev-btn"></div>
  <div class="hottie-next-btn"></div>
</div>',
      'format' => 'full_html',
    ),
    'use_token' => 0,
  );
  $export['hotties_previous_next'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function maxim_fields_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_column',
        1 => 'field_content_author',
        2 => 'field_main_image',
        3 => 'body',
      ),
    ),
    'fields' => array(
      'field_column' => 'ds_content',
      'field_content_author' => 'ds_content',
      'field_main_image' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|article|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'post_date',
        1 => 'field_column',
        2 => 'field_content_author',
        3 => 'field_main_image',
        4 => 'body',
        5 => 'pagination_pager',
        7 => 'pagination_showall',
        8 => 'facebook_comments',
        9 => 'metatags',
      ),
      'channel' => array(
        6 => 'field_channel',
      ),
    ),
    'fields' => array(
      'post_date' => 'ds_content',
      'field_column' => 'ds_content',
      'field_content_author' => 'ds_content',
      'field_main_image' => 'ds_content',
      'body' => 'ds_content',
      'pagination_pager' => 'ds_content',
      'field_channel' => 'channel',
      'pagination_showall' => 'ds_content',
      'facebook_comments' => 'ds_content',
      'metatags' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|article|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_column',
        1 => 'field_content_author',
        2 => 'field_main_image',
        3 => 'body',
      ),
    ),
    'fields' => array(
      'field_column' => 'ds_content',
      'field_content_author' => 'ds_content',
      'field_main_image' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
  );
  $export['node|blog|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_column',
        1 => 'field_content_author',
        2 => 'field_main_image',
        3 => 'body',
        4 => 'facebook_comments',
        5 => 'metatags',
      ),
      'blog_channel' => array(
        6 => 'field_channel',
      ),
    ),
    'fields' => array(
      'field_column' => 'ds_content',
      'field_content_author' => 'ds_content',
      'field_main_image' => 'ds_content',
      'body' => 'ds_content',
      'facebook_comments' => 'ds_content',
      'metatags' => 'ds_content',
      'field_channel' => 'blog_channel',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
  );
  $export['node|blog|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|hotties_profile|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'hotties_profile';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_profile_ref_video',
        1 => 'body',
        2 => 'field_profile_zipcode',
      ),
    ),
    'fields' => array(
      'field_profile_ref_video' => 'ds_content',
      'body' => 'ds_content',
      'field_profile_zipcode' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
  );
  $export['node|hotties_profile|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|hotties_profile|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'hotties_profile';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'read_my_full_profile_anchor',
        1 => 'body',
        2 => 'facebook_comments',
        3 => 'metatags',
      ),
      'hottie_profile_information' => array(
        4 => 'group_hottie_profile_info',
        5 => 'latest_tweet',
        7 => 'field_profile_first_name',
        9 => 'field_profile_hometown',
        11 => 'year_week_competed',
        12 => 'social_links',
        13 => 'field_profile_height',
        14 => 'field_profile_weight',
        15 => 'field_profile_measurements',
        16 => 'field_profile_profession_misc',
        17 => 'field_profile_gamer_handle',
        18 => 'read_my_full_profile_link',
      ),
      'embedded_slideshow' => array(
        6 => 'field_profile_ref_slideshow',
      ),
      'vote_button' => array(
        8 => 'vote_button',
      ),
      'previous_next' => array(
        10 => 'hotties_previous_next',
      ),
    ),
    'fields' => array(
      'read_my_full_profile_anchor' => 'ds_content',
      'body' => 'ds_content',
      'facebook_comments' => 'ds_content',
      'metatags' => 'ds_content',
      'group_hottie_profile_info' => 'hottie_profile_information',
      'latest_tweet' => 'hottie_profile_information',
      'field_profile_ref_slideshow' => 'embedded_slideshow',
      'field_profile_first_name' => 'hottie_profile_information',
      'vote_button' => 'vote_button',
      'field_profile_hometown' => 'hottie_profile_information',
      'hotties_previous_next' => 'previous_next',
      'year_week_competed' => 'hottie_profile_information',
      'social_links' => 'hottie_profile_information',
      'field_profile_height' => 'hottie_profile_information',
      'field_profile_weight' => 'hottie_profile_information',
      'field_profile_measurements' => 'hottie_profile_information',
      'field_profile_profession_misc' => 'hottie_profile_information',
      'field_profile_gamer_handle' => 'hottie_profile_information',
      'read_my_full_profile_link' => 'hottie_profile_information',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|hotties_profile|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|joke|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'joke';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_joke_category',
        1 => 'field_main_image',
        2 => 'body',
        3 => 'metatags',
      ),
    ),
    'fields' => array(
      'field_joke_category' => 'ds_content',
      'field_main_image' => 'ds_content',
      'body' => 'ds_content',
      'metatags' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
  );
  $export['node|joke|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|joke|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'joke';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_joke_category',
        1 => 'field_main_image',
        2 => 'body',
        3 => 'facebook_comments',
        4 => 'metatags',
      ),
      'joke_channel' => array(
        5 => 'field_channel',
      ),
    ),
    'fields' => array(
      'field_joke_category' => 'ds_content',
      'field_main_image' => 'ds_content',
      'body' => 'ds_content',
      'facebook_comments' => 'ds_content',
      'metatags' => 'ds_content',
      'field_channel' => 'joke_channel',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
  );
  $export['node|joke|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|list|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'list';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_main_image',
        1 => 'body',
        2 => 'field_content_author',
      ),
    ),
    'fields' => array(
      'field_main_image' => 'ds_content',
      'body' => 'ds_content',
      'field_content_author' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
  );
  $export['node|list|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|list|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'list';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_content_author',
        1 => 'field_main_image',
        2 => 'body',
        3 => 'facebook_comments',
        4 => 'metatags',
      ),
      'list_channel' => array(
        5 => 'field_channel',
      ),
    ),
    'fields' => array(
      'field_content_author' => 'ds_content',
      'field_main_image' => 'ds_content',
      'body' => 'ds_content',
      'facebook_comments' => 'ds_content',
      'metatags' => 'ds_content',
      'field_channel' => 'list_channel',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
  );
  $export['node|list|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|personality_test|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'personality_test';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_main_image',
        1 => 'body',
        2 => 'metatags',
        3 => 'facebook_comments',
        4 => 'personality_test',
      ),
    ),
    'fields' => array(
      'field_main_image' => 'ds_content',
      'body' => 'ds_content',
      'metatags' => 'ds_content',
      'facebook_comments' => 'ds_content',
      'personality_test' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
  );
  $export['node|personality_test|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|review|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'review';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_content_author',
        1 => 'field_main_image',
        2 => 'body',
        3 => 'field_reviews_release_date',
        4 => 'field_reviews_source',
        5 => 'field_reviews_air_date',
        6 => 'field_affiliate_link',
        7 => 'field_reviews_mpaa_rating',
        8 => 'field_reviews_tv_network',
        9 => 'field_reviews_website',
        10 => 'field_reviews_game_platform',
        11 => 'field_reviews_artist',
        12 => 'field_reviews_star_rating',
      ),
    ),
    'fields' => array(
      'field_content_author' => 'ds_content',
      'field_main_image' => 'ds_content',
      'body' => 'ds_content',
      'field_reviews_release_date' => 'ds_content',
      'field_reviews_source' => 'ds_content',
      'field_reviews_air_date' => 'ds_content',
      'field_affiliate_link' => 'ds_content',
      'field_reviews_mpaa_rating' => 'ds_content',
      'field_reviews_tv_network' => 'ds_content',
      'field_reviews_website' => 'ds_content',
      'field_reviews_game_platform' => 'ds_content',
      'field_reviews_artist' => 'ds_content',
      'field_reviews_star_rating' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
  );
  $export['node|review|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|review|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'review';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_reviews_release_date',
        1 => 'field_content_author',
        2 => 'field_reviews_air_date',
        3 => 'group_reviews_data',
        4 => 'field_main_image',
        5 => 'field_reviews_mpaa_rating',
        6 => 'field_reviews_tv_network',
        7 => 'body',
        8 => 'field_reviews_game_platform',
        9 => 'field_reviews_source',
        10 => 'field_reviews_artist',
        11 => 'field_affiliate_link',
        12 => 'field_reviews_star_rating',
        13 => 'field_reviews_website',
        14 => 'pagination_pager',
        15 => 'pagination_showall',
        16 => 'facebook_comments',
        18 => 'metatags',
      ),
      'review_channel' => array(
        17 => 'field_channel',
      ),
    ),
    'fields' => array(
      'field_reviews_release_date' => 'ds_content',
      'field_content_author' => 'ds_content',
      'field_reviews_air_date' => 'ds_content',
      'group_reviews_data' => 'ds_content',
      'field_main_image' => 'ds_content',
      'field_reviews_mpaa_rating' => 'ds_content',
      'field_reviews_tv_network' => 'ds_content',
      'body' => 'ds_content',
      'field_reviews_game_platform' => 'ds_content',
      'field_reviews_source' => 'ds_content',
      'field_reviews_artist' => 'ds_content',
      'field_affiliate_link' => 'ds_content',
      'field_reviews_star_rating' => 'ds_content',
      'field_reviews_website' => 'ds_content',
      'pagination_pager' => 'ds_content',
      'pagination_showall' => 'ds_content',
      'facebook_comments' => 'ds_content',
      'field_channel' => 'review_channel',
      'metatags' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|review|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|slideshow|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'slideshow';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'post_date',
        1 => 'body',
        2 => 'metatags',
      ),
    ),
    'fields' => array(
      'post_date' => 'ds_content',
      'body' => 'ds_content',
      'metatags' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|slideshow|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|slideshow|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'slideshow';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'post_date',
        1 => 'body',
        2 => 'facebook_comments',
        3 => 'metatags',
      ),
      'slideshow_channel' => array(
        4 => 'field_channel',
      ),
    ),
    'fields' => array(
      'post_date' => 'ds_content',
      'body' => 'ds_content',
      'facebook_comments' => 'ds_content',
      'metatags' => 'ds_content',
      'field_channel' => 'slideshow_channel',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|slideshow|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_column',
        1 => 'field_media_file',
        2 => 'body',
        3 => 'facebook_comments',
        4 => 'metatags',
      ),
    ),
    'fields' => array(
      'field_column' => 'ds_content',
      'field_media_file' => 'ds_content',
      'body' => 'ds_content',
      'facebook_comments' => 'ds_content',
      'metatags' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|video|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_column',
        1 => 'field_brightcove_video',
        2 => 'body',
        3 => 'facebook_comments',
        4 => 'metatags',
      ),
    ),
    'fields' => array(
      'field_column' => 'ds_content',
      'field_brightcove_video' => 'ds_content',
      'body' => 'ds_content',
      'facebook_comments' => 'ds_content',
      'metatags' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|video|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|webform|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'webform';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_main_image',
        1 => 'body',
        2 => 'webform',
        3 => 'facebook_comments',
        4 => 'metatags',
      ),
    ),
    'fields' => array(
      'field_main_image' => 'ds_content',
      'body' => 'ds_content',
      'webform' => 'ds_content',
      'facebook_comments' => 'ds_content',
      'metatags' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|webform|full'] = $ds_layout;

  return $export;
}
