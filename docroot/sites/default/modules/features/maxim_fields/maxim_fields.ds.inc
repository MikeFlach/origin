<?php
/**
 * @file
 * maxim_fields.ds.inc
 */

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
        0 => 'field_column',
        1 => 'field_content_author',
        2 => 'field_main_image',
        3 => 'body',
      ),
      'channel' => array(
        4 => 'field_channel',
      ),
    ),
    'fields' => array(
      'field_column' => 'ds_content',
      'field_content_author' => 'ds_content',
      'field_main_image' => 'ds_content',
      'body' => 'ds_content',
      'field_channel' => 'channel',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
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
        2 => 'field_content_author',
        3 => 'field_main_image',
        4 => 'body',
      ),
      'blog_channel' => array(
        1 => 'field_channel',
      ),
    ),
    'fields' => array(
      'field_column' => 'ds_content',
      'field_channel' => 'blog_channel',
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
        0 => 'body',
      ),
      'hottie_profile_information' => array(
        1 => 'vote_button',
        2 => 'group_hottie_profile_info',
        3 => 'latest_tweet',
        5 => 'field_profile_first_name',
        6 => 'city_state_comma_separated',
        7 => 'year_week_competed',
        8 => 'social_links',
        9 => 'field_profile_height',
        10 => 'field_profile_weight',
        11 => 'field_profile_measurements',
        12 => 'field_profile_profession_misc',
      ),
      'embedded_slideshow' => array(
        4 => 'field_profile_ref_slideshow',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'vote_button' => 'hottie_profile_information',
      'group_hottie_profile_info' => 'hottie_profile_information',
      'latest_tweet' => 'hottie_profile_information',
      'field_profile_ref_slideshow' => 'embedded_slideshow',
      'field_profile_first_name' => 'hottie_profile_information',
      'city_state_comma_separated' => 'hottie_profile_information',
      'year_week_competed' => 'hottie_profile_information',
      'social_links' => 'hottie_profile_information',
      'field_profile_height' => 'hottie_profile_information',
      'field_profile_weight' => 'hottie_profile_information',
      'field_profile_measurements' => 'hottie_profile_information',
      'field_profile_profession_misc' => 'hottie_profile_information',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
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
      ),
    ),
    'fields' => array(
      'field_joke_category' => 'ds_content',
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
      ),
      'joke_channel' => array(
        3 => 'field_channel',
      ),
    ),
    'fields' => array(
      'field_joke_category' => 'ds_content',
      'field_main_image' => 'ds_content',
      'body' => 'ds_content',
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
      'list_channel' => array(
        0 => 'field_channel',
      ),
      'ds_content' => array(
        1 => 'field_main_image',
        2 => 'body',
        3 => 'field_content_author',
      ),
    ),
    'fields' => array(
      'field_channel' => 'list_channel',
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
  $export['node|list|full'] = $ds_layout;

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
        2 => 'group_reviews_data',
        3 => 'field_reviews_air_date',
        4 => 'field_reviews_mpaa_rating',
        5 => 'field_main_image',
        6 => 'body',
        7 => 'field_reviews_tv_network',
        8 => 'field_reviews_source',
        9 => 'field_reviews_game_platform',
        10 => 'field_affiliate_link',
        11 => 'field_reviews_artist',
        12 => 'field_reviews_website',
        13 => 'field_reviews_star_rating',
      ),
      'review_channel' => array(
        14 => 'field_channel',
      ),
    ),
    'fields' => array(
      'field_reviews_release_date' => 'ds_content',
      'field_content_author' => 'ds_content',
      'group_reviews_data' => 'ds_content',
      'field_reviews_air_date' => 'ds_content',
      'field_reviews_mpaa_rating' => 'ds_content',
      'field_main_image' => 'ds_content',
      'body' => 'ds_content',
      'field_reviews_tv_network' => 'ds_content',
      'field_reviews_source' => 'ds_content',
      'field_reviews_game_platform' => 'ds_content',
      'field_affiliate_link' => 'ds_content',
      'field_reviews_artist' => 'ds_content',
      'field_reviews_website' => 'ds_content',
      'field_reviews_star_rating' => 'ds_content',
      'field_channel' => 'review_channel',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
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
        0 => 'body',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
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
      'slideshow_channel' => array(
        0 => 'field_channel',
      ),
      'ds_content' => array(
        1 => 'body',
      ),
    ),
    'fields' => array(
      'field_channel' => 'slideshow_channel',
      'body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
  );
  $export['node|slideshow|full'] = $ds_layout;

  return $export;
}
