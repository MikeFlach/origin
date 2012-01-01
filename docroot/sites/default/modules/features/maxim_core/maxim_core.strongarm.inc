<?php
/**
 * @file
 * maxim_core.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function maxim_core_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'acquia_identifier';
  $strongarm->value = 'DETW-21839';
  $export['acquia_identifier'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'acquia_key';
  $strongarm->value = '77bbdff917d146fa8181b1309eeb5b64';
  $export['acquia_key'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'acquia_search_version';
  $strongarm->value = '7.x-2.1';
  $export['acquia_search_version'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_theme';
  $strongarm->value = 'seven';
  $export['admin_theme'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_default_environment';
  $strongarm->value = 'acquia_search_server_1';
  $export['apachesolr_default_environment'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_mlt_blocks';
  $strongarm->value = array(
    'mlt-001' => array(
      'name' => 'More like this',
      'num_results' => '5',
      'mlt_fl' => array(
        'label' => 'label',
        'taxonomy_names' => 'taxonomy_names',
      ),
      'mlt_mintf' => '1',
      'mlt_mindf' => '1',
      'mlt_minwl' => '3',
      'mlt_maxwl' => '15',
      'mlt_maxqt' => '20',
      'mlt_type_filters' => array(),
      'mlt_custom_filters' => '',
    ),
  );
  $export['apachesolr_mlt_blocks'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_site_hash';
  $strongarm->value = 'g5bewz';
  $export['apachesolr_site_hash'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'block_cache';
  $strongarm->value = 1;
  $export['block_cache'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache';
  $strongarm->value = 1;
  $export['cache'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache';
  $strongarm->value = 0;
  $export['cache_flush_cache'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_apachesolr';
  $strongarm->value = 0;
  $export['cache_flush_cache_apachesolr'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_block';
  $strongarm->value = 0;
  $export['cache_flush_cache_block'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_field';
  $strongarm->value = 0;
  $export['cache_flush_cache_field'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_filter';
  $strongarm->value = 0;
  $export['cache_flush_cache_filter'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_form';
  $strongarm->value = 0;
  $export['cache_flush_cache_form'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_image';
  $strongarm->value = 0;
  $export['cache_flush_cache_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_menu';
  $strongarm->value = 0;
  $export['cache_flush_cache_menu'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_page';
  $strongarm->value = 0;
  $export['cache_flush_cache_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_path';
  $strongarm->value = 0;
  $export['cache_flush_cache_path'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_token';
  $strongarm->value = 0;
  $export['cache_flush_cache_token'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_views';
  $strongarm->value = 0;
  $export['cache_flush_cache_views'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_views_data';
  $strongarm->value = 0;
  $export['cache_flush_cache_views_data'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_lifetime';
  $strongarm->value = '600';
  $export['cache_lifetime'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_article';
  $strongarm->value = 0;
  $export['comment_anonymous_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_blog';
  $strongarm->value = 0;
  $export['comment_anonymous_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_hotties_profile';
  $strongarm->value = 0;
  $export['comment_anonymous_hotties_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_joke';
  $strongarm->value = 0;
  $export['comment_anonymous_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_link_stub';
  $strongarm->value = 0;
  $export['comment_anonymous_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_list';
  $strongarm->value = 0;
  $export['comment_anonymous_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_page';
  $strongarm->value = 0;
  $export['comment_anonymous_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_poll';
  $strongarm->value = 0;
  $export['comment_anonymous_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_review';
  $strongarm->value = 0;
  $export['comment_anonymous_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_slideshow';
  $strongarm->value = 0;
  $export['comment_anonymous_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_video';
  $strongarm->value = 0;
  $export['comment_anonymous_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_webform';
  $strongarm->value = 0;
  $export['comment_anonymous_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_article';
  $strongarm->value = '2';
  $export['comment_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_blog';
  $strongarm->value = '2';
  $export['comment_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_article';
  $strongarm->value = 1;
  $export['comment_default_mode_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_blog';
  $strongarm->value = 1;
  $export['comment_default_mode_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_hotties_profile';
  $strongarm->value = 1;
  $export['comment_default_mode_hotties_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_joke';
  $strongarm->value = 1;
  $export['comment_default_mode_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_link_stub';
  $strongarm->value = 1;
  $export['comment_default_mode_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_list';
  $strongarm->value = 1;
  $export['comment_default_mode_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_page';
  $strongarm->value = 1;
  $export['comment_default_mode_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_poll';
  $strongarm->value = 1;
  $export['comment_default_mode_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_review';
  $strongarm->value = 1;
  $export['comment_default_mode_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_slideshow';
  $strongarm->value = 1;
  $export['comment_default_mode_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_video';
  $strongarm->value = 1;
  $export['comment_default_mode_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_webform';
  $strongarm->value = 1;
  $export['comment_default_mode_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_article';
  $strongarm->value = '10';
  $export['comment_default_per_page_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_blog';
  $strongarm->value = '10';
  $export['comment_default_per_page_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_hotties_profile';
  $strongarm->value = '50';
  $export['comment_default_per_page_hotties_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_joke';
  $strongarm->value = '10';
  $export['comment_default_per_page_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_link_stub';
  $strongarm->value = '50';
  $export['comment_default_per_page_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_list';
  $strongarm->value = '10';
  $export['comment_default_per_page_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_page';
  $strongarm->value = '50';
  $export['comment_default_per_page_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_poll';
  $strongarm->value = '30';
  $export['comment_default_per_page_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_review';
  $strongarm->value = '10';
  $export['comment_default_per_page_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_slideshow';
  $strongarm->value = '10';
  $export['comment_default_per_page_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_video';
  $strongarm->value = '10';
  $export['comment_default_per_page_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_webform';
  $strongarm->value = '10';
  $export['comment_default_per_page_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_article';
  $strongarm->value = 1;
  $export['comment_form_location_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_blog';
  $strongarm->value = 1;
  $export['comment_form_location_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_hotties_profile';
  $strongarm->value = 1;
  $export['comment_form_location_hotties_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_joke';
  $strongarm->value = 1;
  $export['comment_form_location_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_link_stub';
  $strongarm->value = 1;
  $export['comment_form_location_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_list';
  $strongarm->value = 1;
  $export['comment_form_location_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_page';
  $strongarm->value = 1;
  $export['comment_form_location_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_poll';
  $strongarm->value = 1;
  $export['comment_form_location_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_review';
  $strongarm->value = 1;
  $export['comment_form_location_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_slideshow';
  $strongarm->value = 1;
  $export['comment_form_location_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_video';
  $strongarm->value = 1;
  $export['comment_form_location_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_webform';
  $strongarm->value = 1;
  $export['comment_form_location_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_hotties_profile';
  $strongarm->value = '0';
  $export['comment_hotties_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_joke';
  $strongarm->value = '0';
  $export['comment_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_link_stub';
  $strongarm->value = '0';
  $export['comment_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_list';
  $strongarm->value = '2';
  $export['comment_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_page';
  $strongarm->value = '1';
  $export['comment_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_poll';
  $strongarm->value = '2';
  $export['comment_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_article';
  $strongarm->value = '1';
  $export['comment_preview_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_blog';
  $strongarm->value = '1';
  $export['comment_preview_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_hotties_profile';
  $strongarm->value = '1';
  $export['comment_preview_hotties_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_joke';
  $strongarm->value = '1';
  $export['comment_preview_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_link_stub';
  $strongarm->value = '1';
  $export['comment_preview_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_list';
  $strongarm->value = '1';
  $export['comment_preview_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_page';
  $strongarm->value = '1';
  $export['comment_preview_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_poll';
  $strongarm->value = '1';
  $export['comment_preview_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_review';
  $strongarm->value = '1';
  $export['comment_preview_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_slideshow';
  $strongarm->value = '1';
  $export['comment_preview_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_video';
  $strongarm->value = '1';
  $export['comment_preview_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_webform';
  $strongarm->value = '1';
  $export['comment_preview_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_review';
  $strongarm->value = '2';
  $export['comment_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_slideshow';
  $strongarm->value = '0';
  $export['comment_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_article';
  $strongarm->value = 1;
  $export['comment_subject_field_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_blog';
  $strongarm->value = 1;
  $export['comment_subject_field_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_hotties_profile';
  $strongarm->value = 1;
  $export['comment_subject_field_hotties_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_joke';
  $strongarm->value = 1;
  $export['comment_subject_field_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_link_stub';
  $strongarm->value = 1;
  $export['comment_subject_field_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_list';
  $strongarm->value = 1;
  $export['comment_subject_field_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_page';
  $strongarm->value = 1;
  $export['comment_subject_field_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_poll';
  $strongarm->value = 1;
  $export['comment_subject_field_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_review';
  $strongarm->value = 1;
  $export['comment_subject_field_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_slideshow';
  $strongarm->value = 1;
  $export['comment_subject_field_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_video';
  $strongarm->value = 1;
  $export['comment_subject_field_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_webform';
  $strongarm->value = 1;
  $export['comment_subject_field_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_video';
  $strongarm->value = '1';
  $export['comment_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_webform';
  $strongarm->value = '1';
  $export['comment_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cron_key';
  $strongarm->value = '9H8h8r_VbrpMnq9hGRVvfwnlO-TmjAIs9VemPAVSODg';
  $export['cron_key'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cron_safe_threshold';
  $strongarm->value = '3600';
  $export['cron_safe_threshold'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'css_js_query_string';
  $strongarm->value = 'lx33t1';
  $export['css_js_query_string'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dart_global_network_id';
  $strongarm->value = '';
  $export['dart_global_network_id'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dart_global_prefix';
  $strongarm->value = 'maxim';
  $export['dart_global_prefix'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dart_global_site';
  $strongarm->value = 'dart';
  $export['dart_global_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dart_global_slug';
  $strongarm->value = '<none>';
  $export['dart_global_slug'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dart_global_zone';
  $strongarm->value = 'newsitetest';
  $export['dart_global_zone'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dart_js';
  $strongarm->value = '';
  $export['dart_js'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dart_key_vals';
  $strongarm->value = array();
  $export['dart_key_vals'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dart_noscript';
  $strongarm->value = 1;
  $export['dart_noscript'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dart_special_key_vals';
  $strongarm->value = array(
    'ord' => 'ord',
    'tile' => 0,
  );
  $export['dart_special_key_vals'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dart_special_tile_init';
  $strongarm->value = '0';
  $export['dart_special_tile_init'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dart_taxonomy_default_callback';
  $strongarm->value = '_dart_taxonomy_callback_tid';
  $export['dart_taxonomy_default_callback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dart_taxonomy_default_key';
  $strongarm->value = 'term';
  $export['dart_taxonomy_default_key'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dart_test_prefix';
  $strongarm->value = '';
  $export['dart_test_prefix'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dart_test_site';
  $strongarm->value = '';
  $export['dart_test_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dart_test_zone';
  $strongarm->value = '';
  $export['dart_test_zone'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_api_use_iso8601';
  $strongarm->value = 0;
  $export['date_api_use_iso8601'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_api_version';
  $strongarm->value = '7.2';
  $export['date_api_version'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_default_timezone';
  $strongarm->value = 'America/New_York';
  $export['date_default_timezone'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_first_day';
  $strongarm->value = '1';
  $export['date_first_day'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_long';
  $strongarm->value = 'l, F j, Y - g:ia';
  $export['date_format_long'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_medium';
  $strongarm->value = 'F j, Y - g:ia';
  $export['date_format_medium'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_short';
  $strongarm->value = 'd/m/Y - g:ia';
  $export['date_format_short'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_popup_timepicker';
  $strongarm->value = 'wvega';
  $export['date_popup_timepicker'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'drupal_css_cache_files';
  $strongarm->value = array(
    '6beb0fcb1b76d9b4adba17cd59bbf4fc53b03471ff3b24b5429c984a453128e6' => 'public://css/css_CKoWqiBj9gVXhPuDSnNphuEB0b0J2To76x0pX0EGqn4.css',
    '581803d40730db18e5c6ab6250c236809c59763d7adc4044152962ed25cf313f' => 'public://css/css_1FuaQyNpeoGilFLg6GsDTprte9QHfko-0ntzSWCraiQ.css',
    '3b0407267c5be92150882508807ceb245279dc227e721724553ccf385ce069df' => 'public://css/css_AmMyjju2AJyqusAZjGLpYIR3Ra6i0gCU91XFHlj089Y.css',
    'f18a8839aa6e541411e6a0d610b089ec4cac263eddd6e49d4c4c3ee94030e3a5' => 'public://css/css_awfzfhsvx3JNH5ze4Tj-xwAt6Noetnx6X-egOLL35Ho.css',
    'bfa3a43832e9e7d3168bb89ee039d4a025bf1f7ccd280fb5164be1fe92d0563d' => 'public://css/css_dzxv0AN_X_rzFX2k-19LSQrTwFN9yhxwNWSl5rFbJGs.css',
    '375252a39d7a655c929223e7fb7856eb33d025daa25f17b5eb40a79ebd5b4743' => 'public://css/css_kinPAvI8coKe0oFSa1a1ENduKbcfWNXxPXYCIokW4X8.css',
    'd28273bcbaf3662cdcb5ec9c5272b0b0ff9127d5219db7ecd0ddc954629ab76a' => 'public://css/css_2EGGyKgumZfk71Pm_7dBT3H-xZteTllJUKFrl5AAd_o.css',
    'b92bcafde8b3e7aba2abfddcbbd6ce050870ecd3b55c968dc572c13dad0c072e' => 'public://css/css_6O37bEB29TGnRJU1tAoasi9KqHKM_CG9lQHbAQRwuAA.css',
    '0c7dd1b153520cf4049c6cbd163709bd165d2d7e35c52435ebef62d61dc21eab' => 'public://css/css_XscWcDilpwmM0U8Yu5oFKEJV7xHVRB5nL51O5iYMm3k.css',
    '096ce2055a27940ac6d3fcaaa0697ffd10e732c75ffb1cf6be38fa57a1dae473' => 'public://css/css_DtQfn6gi5iVYorQlp-sbtPIKT-B-ZFuzOB2OL5h52R4.css',
    '5c3831aa986098d0c77212d48e680a96b622f6e3e423814d8fc3df4aeeaa9d65' => 'public://css/css_NnTbynq6T3EXdfKtC8a5xFN5UUAc_81Fb9iBvY_KTgg.css',
    '1a82d984b23e362a26eb9c33d6df1ad24c4ac6f034f9310baac42d95f7162d2b' => 'public://css/css_CKoWqiBj9gVXhPuDSnNphuEB0b0J2To76x0pX0EGqn4.css',
    '1a376b37fcaf73c12fb7ce3e5284c29e9f2b3ffef9bc7e9dc1dc2b0f18de2c47' => 'public://css/css_v90grOqRqhsHS7uBuZCvJuBc0ux8Dyqk6XNK-TmrzCo.css',
    '7d1952e3a14b2262278c9bf8aaac7e345db57ed4051963c2e576757e8d36c2e4' => 'public://css/css_AmMyjju2AJyqusAZjGLpYIR3Ra6i0gCU91XFHlj089Y.css',
    '24016f7a1ef8184ff3b02de0dbf51d0ea6679aa6403e44bac7e3d414da66e9ec' => 'public://css/css_POtUsfvAAshyABE9BqlhyPE0gah7ebW3jy1l-FxtHx4.css',
    'f778745bfb3b0194d389e6f514c5b7757f8b93ed3a5bca3635934e4471f3fc18' => 'public://css/css_kinPAvI8coKe0oFSa1a1ENduKbcfWNXxPXYCIokW4X8.css',
    'd6db2a71fb7e8c3cc87f8ccb77876e05ceb035ebf16e26be62fd0fdcee57ace5' => 'public://css/css_2EGGyKgumZfk71Pm_7dBT3H-xZteTllJUKFrl5AAd_o.css',
    'cc53f87e774b70c1fadd50f192e37a2bdd11d954b7abcc61fff8d0e428a5c8a1' => 'public://css/css_6O37bEB29TGnRJU1tAoasi9KqHKM_CG9lQHbAQRwuAA.css',
    'c93ad58998d32e364d55fecfeca50d6c90f9e7bcf7b79093f1a7a48be9b1ba84' => 'public://css/css_XscWcDilpwmM0U8Yu5oFKEJV7xHVRB5nL51O5iYMm3k.css',
    '80d79e8b016d2b0e342ea8816ef523b7ac605836343b167224894ac735481a25' => 'public://css/css_DtQfn6gi5iVYorQlp-sbtPIKT-B-ZFuzOB2OL5h52R4.css',
    '0015bc4ba7b5c6695592fbec5446baa351dbb20c6fdab3a98442fd0e206bf295' => 'public://css/css_dCLDCc4rplWgbF_F-wH-UH7MWTOnU1mlsBFMMve6XLQ.css',
    '4cb447fcd2e27c36140e734c1a3672a68289e2814ec6cbe99d9b00f583c8ad27' => 'public://css/css_oJfzx9zEyYT8t8DAAMlGseXREvdGzMAKMRz-3ilFjmg.css',
    '577e55fda1774cf5eee91355b5ce599fb73c3df92017318fbdba193d707cdefc' => 'public://css/css_YgnpqV6re0pxZ2ZfJ9erO4TjLvIoiOZFw32kL3ot4Vg.css',
    '006d0706cd962b385a929c4b691530b8c182e804beb99c59256f6de96be5d042' => 'public://css/css_tEDNb_aeRQRitgZgrkzMtelmZnsz2jU5ZLHHM4EBXVs.css',
    '619efc39de6d6c09f02d5851f17b4ffbc1843404301253511f59ef99d8dcd084' => 'public://css/css_4_3bVyEqyzqub93pAja4KmFiV68QDJeBpEu1T-B_Lz0.css',
    'fa1246f958a966e849a86d475b7805e8ca364f7adb9a6b618d69c4ff87662e0b' => 'public://css/css_5HmfCdpHW4i24AolcogMnSSbP0QYgMui8EB1Iqr99bk.css',
    '52c670c24cc81bcfa290900dc900a51486706e78acc5a24d0b1b2ba58f5cb26f' => 'public://css/css_uq1diRDf-G36ZpTf2O0t1PJNolwpHnq4T2eNK4yXKC4.css',
    '8b611cf528578f4be1ca3817457ebc48a498002838d07052984c7761cc08aaa6' => 'public://css/css_hjAmwRVJJ377gcQ8LCUWVIl2OKeS3xVbr5PXUxg-2D8.css',
    '8953107cf79ea47eb776523a928f321ba004b6723af7de324ec4104bd11bc731' => 'public://css/css_kinPAvI8coKe0oFSa1a1ENduKbcfWNXxPXYCIokW4X8.css',
    '7d27e65d421c421fd13c4e9e1aef7828af96c37a98a9282a8c9d2325f8205211' => 'public://css/css_2EGGyKgumZfk71Pm_7dBT3H-xZteTllJUKFrl5AAd_o.css',
    'fb724c3d2c709a3d95cd8312f9fac1239789cdaea0e6ef3c91c9872b0551be49' => 'public://css/css_6O37bEB29TGnRJU1tAoasi9KqHKM_CG9lQHbAQRwuAA.css',
    '777ccad7d71298ddb768b94ab7a9374eb4cfab569619d38d7a671a65c3dc45f6' => 'public://css/css_XscWcDilpwmM0U8Yu5oFKEJV7xHVRB5nL51O5iYMm3k.css',
    '1a2ba5357d52b71980d69be737da29b75dbfb9ee3326ba0c6fd167c1893e7d8d' => 'public://css/css_DtQfn6gi5iVYorQlp-sbtPIKT-B-ZFuzOB2OL5h52R4.css',
    'de2e2eeeebbe5284cb47465344cc2f848993444241caaf88427054c44bcad041' => 'public://css/css_dCLDCc4rplWgbF_F-wH-UH7MWTOnU1mlsBFMMve6XLQ.css',
    '7107f851183992e78a3b9c2e9504b02766cacd7a392ae8ea3fe1bde918f755aa' => 'public://css/css_oJfzx9zEyYT8t8DAAMlGseXREvdGzMAKMRz-3ilFjmg.css',
    'a885034d37eff1653dfb68dfe4f95a01731d40439dc4be827ca94b02266cc726' => 'public://css/css_YgnpqV6re0pxZ2ZfJ9erO4TjLvIoiOZFw32kL3ot4Vg.css',
    '0c10347d1c94d6edc62bd617719dba9bfb4b4acc2bd2c811119fdc3d9675f4a4' => 'public://css/css_YeQ3VZO2N_L-jjgR2Xd_Ive7KeOQbYjwvd-NrjVVHLQ.css',
    '5178df964480f4a98406a5a63281f0231946e2c90f68c0ca9887c8d87e053a08' => 'public://css/css_4_3bVyEqyzqub93pAja4KmFiV68QDJeBpEu1T-B_Lz0.css',
    '622794c3ded471336a3736dc92e32511e6689e59efb5945dd1a544a0fec70546' => 'public://css/css_5HmfCdpHW4i24AolcogMnSSbP0QYgMui8EB1Iqr99bk.css',
    '8cc168558dab3201ba6b4fd2c6bd01f1cb5eb3293d1ea18652ed85161cc13050' => 'public://css/css_uq1diRDf-G36ZpTf2O0t1PJNolwpHnq4T2eNK4yXKC4.css',
    'f0426d5e2e51711a4396bc6dc3b428ae8707c86c25ab4d659dc8393f364706cc' => 'public://css/css_CKoWqiBj9gVXhPuDSnNphuEB0b0J2To76x0pX0EGqn4.css',
    '4ca4ce5ad99eea6251e867edd6c06773d51e1d93a46855f584cb1d3417264fd1' => 'public://css/css_AmMyjju2AJyqusAZjGLpYIR3Ra6i0gCU91XFHlj089Y.css',
    '36d9f6662499366704a6fb55f1495397dc613fc8c0837d14aabd4ac45d6ab377' => 'public://css/css_g1nt5ATPqYv5-1cvejSoHXr5-zJiW5xYxMks0Z1DR88.css',
    '230b74ae068ff2c062cfb04436a46da050df1e277ad93a1b40e1e4b73194482b' => 'public://css/css_kinPAvI8coKe0oFSa1a1ENduKbcfWNXxPXYCIokW4X8.css',
    'bab51ff20becb763dbf103b3004a060e945b0a563aa2d44e50c262447c9df2fc' => 'public://css/css_2EGGyKgumZfk71Pm_7dBT3H-xZteTllJUKFrl5AAd_o.css',
    '535d5291bb87fb90859ffa17b6aacc3e7a84325bad5b5742bdeef7382f5e736d' => 'public://css/css_6O37bEB29TGnRJU1tAoasi9KqHKM_CG9lQHbAQRwuAA.css',
    '4f342f87a486f8e56a4fe85a4eb3630424d44893d0d1b982dfc2f818cb120ce2' => 'public://css/css_XscWcDilpwmM0U8Yu5oFKEJV7xHVRB5nL51O5iYMm3k.css',
    '1ebbf552bf7a03045db20372c25a8508583769e24c8a04070708753b9a6d1b5e' => 'public://css/css_DtQfn6gi5iVYorQlp-sbtPIKT-B-ZFuzOB2OL5h52R4.css',
    'a34614ceb75ba2c9299b41c68e82ddef3b127cfe8abc8c58d751d1eaa5bdf0c4' => 'public://css/css_4_3bVyEqyzqub93pAja4KmFiV68QDJeBpEu1T-B_Lz0.css',
    'be3db923f93ce33bac2248b2d90a724ccd70bd283928d644c18738ee9b3e3b8d' => 'public://css/css_96-HSXf3DPLFCFysWHcW6GIbz6h-p7qF_cNeikMoUAA.css',
    '963dcbaa3d96938302603efa810da0b7d4882ed340f9dfb00a490a936dae5e83' => 'public://css/css_7l5PSZ9z67aGLdY975oraPTcoYtZkfAYS7Rz0oS2O6s.css',
    '200bc7bf8242989c77db646d1ab853da060278000c050979c12a919be1025cd6' => 'public://css/css_4d_VPpKnoUEsGhBBX--JdBr8Qfi9RjeNxmyP65nYN6c.css',
  );
  $export['drupal_css_cache_files'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'drupal_js_cache_files';
  $strongarm->value = array(
    '7329bfa92917b84e7b945471998b4c97c1be31b4299ece1035f1968eacd0d0b6' => 'public://js/js_dgV9INs_QUwDV0DUTHFCxVm0mhsvovK-wDFE34cp_KA.js',
    'c2fb37e79f7bb9e611f65f0c96ea9410096390020c73f4473848b9a4a47368ee' => 'public://js/js_B7eQjnOdURrVWJT4wPfB88WarwhD70wgNygU3dfJ7MI.js',
    'd5f400421e3f6c7e9d018d0bd4d89936c8aa1485cd2a5249ae931922d8b743a7' => 'public://js/js_fnSkdnAvPXbnL-NJ5lEYJdQz4iEU9mFqOnI__vKd8KM.js',
    'f172946978f9f0416182b496815e4b8d7e77889b839138f089b0dd590953ff6e' => 'public://js/js_0N6_-Pa9NtbR1NBSHsbo-Se_h4dWS-aO4Mbbxs0gqLo.js',
    '2e13e9f40ea669e63836f9ea74bbe9fccec39ff6bfa09194c62b48de96c4f821' => 'public://js/js_MWR9njZUqvzTGadPEZTiKmDIqxTQf_MZuJB7YC5TNzA.js',
    'c7e819dc4246c10819116479fc25d0bfaf9166617ea1a73947c6307cc863f90e' => 'public://js/js_dgV9INs_QUwDV0DUTHFCxVm0mhsvovK-wDFE34cp_KA.js',
    '30cac28ef663fdfdb7359ca59a9964081f3820d9dea61024606b4bccbf22cead' => 'public://js/js_B7eQjnOdURrVWJT4wPfB88WarwhD70wgNygU3dfJ7MI.js',
    '6f342f05393f121c5d9d296724885ffc2a88320bf59ecfb6ed73a112d2e52c77' => 'public://js/js_kygF0_9m6Y7XA2V2nMOK7Rg-pNwN9V5131X7e9kZBcA.js',
    '11ad973aaae2327dc0a3293b3caecee989a0dedfbe806d557047f1713b330a96' => 'public://js/js_MWR9njZUqvzTGadPEZTiKmDIqxTQf_MZuJB7YC5TNzA.js',
    '25c60562f483400b111d243c3057762c44e435b85e61328bbff7f45ad7682f14' => 'public://js/js_G2SkAnLWPq4-pSR2_VGORVaVyzBi-aNHY3hgsl1Wr8g.js',
    'ddaee7e4b42f7998b1031eb089e8d7b269fc9c1293cdcfc98d7dedbf838e0dc5' => 'public://js/js_n6OyxrH6ns44vQtmYiQpr6DQwzzeBO0Tu1K2SnJa2OE.js',
    'b252b0c4439fdc7653dff4a4411d0cf5833698aceed6d282e179d05a189b53a9' => 'public://js/js_7LQQobnZuEpZHudMXeEfiq7trwmogh3xY3-aCY-ZzP0.js',
    '60272fd6a10f8938f3a07d85a8ea648a224cceb79144e173bf86c917d35b77eb' => 'public://js/js_QR5VRVd9rvKUeKMGxO7YMmITaIpMe9pwWwQV3t_XSlg.js',
    '19d64a3932ba3cea42d5b61d0589b6c94d91373c60cd97fdfd867aad6d4db99f' => 'public://js/js_uDMa2-Ir52ThLnczukf2UQtpY95PpKiZakCGzBG1oWI.js',
    '0162b0718c1bd92ca64c305314e25da67c8b6a466a181b5025b865fa317077bf' => 'public://js/js_N-9YVKhZPem9wao8dXnOG5x4dVGTgTvDUiR7HUioNqg.js',
    'eaec75211f3ce8811faf72edf459b60e8ff6ada3bcf0fe1c3dc6cad3332d0fcd' => 'public://js/js_LH7uVLF7UrizLS-3SvEBwrh3G3iZGTjg36BFeEKCH6g.js',
    '73ad695a22bae5e8f7f542d77af42614a306db0f35b64ac074ef3150a4357eb5' => 'public://js/js_43n5FBy8pZxQHxPXkf-sQF7ZiacVZke14b0VlvSA554.js',
    '4b1a7589286bde8f6d74d57708a95bb1fc469371801eaabe46b417cecd3f0b22' => 'public://js/js_ylpEZ9W68qKbsMbAsAttaLA9e3eYkYn6G5b-VXmeIk0.js',
    'af77b6c1b2a4ef342bde4efe442ff767c71aa3f77469057e64f2d5802385eeb1' => 'public://js/js_CC-zfeuQHcDhFtVRuKW53h30TL7j_105J32Nz8b8R38.js',
    'd644156dcf808a785aeb29aa08976153f65aa2d62a03608162fb7712eadb1529' => 'public://js/js_7zP6PCK-g6veukBjSd8bPysjUnzS3yYms6USHV7S4cw.js',
    'f269aca661ae71c633b5a97560a6bf854f1aa06ce82c23acc31861121bfbe644' => 'public://js/js_QR5VRVd9rvKUeKMGxO7YMmITaIpMe9pwWwQV3t_XSlg.js',
    '809bdfbc11466ee6bfb2f5847d71e357bad9e4f7622c24d86f9ab1c82cb82ddf' => 'public://js/js_BS4uUH6TrTTSc2nu0oxtd02tCQzPHOQ3hSVvNyre9A4.js',
    '71cfa1a31788577a01a40c9bee161d8c0fdd5e8a81fb4d6c6fe11b360fd0a75a' => 'public://js/js_43n5FBy8pZxQHxPXkf-sQF7ZiacVZke14b0VlvSA554.js',
    'e0cef96fb617425e94624198c34ac5e89bb6f50c35c7db1b84f310c535437c71' => 'public://js/js_CC-zfeuQHcDhFtVRuKW53h30TL7j_105J32Nz8b8R38.js',
    '683e6cba714d16b6eaf32670d2a884f08af648c139ae829e6f7720c0ccf47220' => 'public://js/js_BJvh6tc0yTQdpzYenoY-Uuur0ZrHaWKTiHDS-gIqJV8.js',
    'a6f1dfd24cf9f629b97144e9275002cf41b0289a922277f264c7c48c742fead6' => 'public://js/js_QR5VRVd9rvKUeKMGxO7YMmITaIpMe9pwWwQV3t_XSlg.js',
    '82d31b23d7c99ec2d8c596785ef341d999ade27cb06a00816320b42bcd1dde2e' => 'public://js/js_3yVJbPQVXAyxLoSGxq_YRpBzN7zcFaQHzRnA1nmcsUk.js',
    'ad7d167050202a73b3f3ae1bcbcf17740613ce7aba8ae3c9c3a247e01a693607' => 'public://js/js_43n5FBy8pZxQHxPXkf-sQF7ZiacVZke14b0VlvSA554.js',
    '7fafcb0172ea9c528f7bbc679088c064fa351a7d294b59c9347f5ed868d40631' => 'public://js/js_dgV9INs_QUwDV0DUTHFCxVm0mhsvovK-wDFE34cp_KA.js',
    'bf9548b2fdaf1856659d1d69f21d14344fbfcc411b7c7088c3bdea016eae15a8' => 'public://js/js_JUDp_MmPKJxATqdGBBg0_Mao_-UG6QMMx0e95Xz_qlA.js',
    'aae3b7a1ae974c2bf9bc502033d992c4fd82182e170bd84590605585ec642df0' => 'public://js/js_fbzvrmXF-eCviZztyXeTtxwv9PXtpaQhQfTs9wcwATc.js',
    '2279948aba79e9d39989bf3482b62a84c1b9bd89a404513d8a9a176598825b36' => 'public://js/js_DgpakMbnb8cCSYM3pCKc4-ifOPf768fqx5E6Im3PQTs.js',
    '4dd33f968dabaecc85cdc48c3b9024269550e6241e0b4a8fd4d96999f4823656' => 'public://js/js_RONoqNyVVzE88D8jxxayKB72mmOLzYt280pIzLZT6Bw.js',
    'e9758630d741158d639cea9a99726d2cb0ef673bda919de89f664d7fd237606f' => 'public://js/js_wwg3AtVGdUvmCsqDwMgbfdkV4NRQN_W4uyKjAQT75P4.js',
    '8d77c38f3b4d196eecf89dffe1bd78c44f7b73faf372989abe0326416dec7e4d' => 'public://js/js_9yXOQr2tijaUCvvaWUHp_C-NWy0h9QF0YaGR4SUywgg.js',
    '7fc54f3b839962b0ff99b08ccdacecf17728b1f1f72b0f435c92caeffa4b3ab4' => 'public://js/js_Wnj0duC6g3B6dpdOslG701djKw2ioJVd-sGQsuvFMcg.js',
    'd67ab0f70bef70e6bdc8be97ed0904f2dd6007577af9f6841e60c37a9561231a' => 'public://js/js_OYGZhUdsrQmH4TxK3zxVCGINWLN81k2pBI0M8ev9gOQ.js',
    '9d238ad262eac705fcd52fde69707b2ff50ebf24b5480dcd5bf2005dbb67df21' => 'public://js/js_vmRm0rODRtm4CL6wjPmES-GlbyNdCX8WLViPCCx0vcs.js',
    'a030938486316ea60fe8f9ec95e40aee58a0d89b12f457c88e1f493818358074' => 'public://js/js_82VLBvyAB6o2gbqGADcIXtRIICFKUA-ilNehR2uKkSQ.js',
    'f286bbb129f99c18e4b620f4912ad7f09ddc1ff9e92229a107e505f8a92b1693' => 'public://js/js_RONoqNyVVzE88D8jxxayKB72mmOLzYt280pIzLZT6Bw.js',
    'b4f7ab8a862afabc719d1657eaadc6fa89092a7595779c633b608c9a0ca172c8' => 'public://js/js_dSmEQH-qmD8Q460KHwDlJO-wvlYGr0QBqLFcRrvVlU4.js',
    '1869e849f729283ace5b610e5ef17aca2dc00d98e19d0ba57837866bcf429674' => 'public://js/js_l2d87eQR3mDezDu6c6tlmfqhdPDsS_MTSc97fpQgI1w.js',
    '4d30e2d03e2eaeee08c54070d116e83d23e502f80c9a2faa3d7a21a3e45c4cbc' => 'public://js/js_1tT2ji_UvJnSLbaO3S48XqUiOfd4GDSdxwh01OO3St8.js',
    'a5a8b96e41f4e1307f7b5d904b9ba5df3869888783457f32c6a6cde1a0755a1c' => 'public://js/js_7KAgR6X5q4vxQZ-x1ZEZLcFdkzWFDvGLjPjY3zfIVOM.js',
    'c936b50dab20d818f0ed1a56a8ea6bca4813272153ad5a398821ee5f8f4ac691' => 'public://js/js_J2SXnVXv8q5OarvAXp8ZFeLsc-6aiOlJFpC2rt8XDM0.js',
    '163177a718278ca738beac917a05aa59a9e2e1f1a105bd99510128beb86ca25d' => 'public://js/js_t5EWXXjCZpXt2n0BHaJiOivSS7JIYhSeDVYKzRtrniU.js',
  );
  $export['drupal_js_cache_files'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'features_codecache';
  $strongarm->value = array(
    'maxim_core' => array(
      'dependencies' => '7f109a912ddf0790d131525de83cdc2e',
      'field' => 'a9ddda2406bda9c8685f69c460546d44',
      'taxonomy' => '8dae41d1cf32dc0129727ac0020b353e',
      'user_role' => '0d0a001c1884bedd043a8eb141ae4985',
      'node' => 'b642c7a8e74a0882bcdc0b7c4421985b',
      'variable' => '4ff16b43b6ae75f0f90deabc96cc91fb',
      'field_group' => 'ef0a8d90552c290a17b6417daa3e61cf',
      'views_view' => '1c268d345a27b9d7bdd871a276bf5a19',
      'page_manager_handlers' => '10bfdc417c3c76b02c458d75894aa8e3',
      'filter' => 'd121ccbcd112f9f679b777d4aa42431c',
      'page_manager_pages' => 'b1bf49ca7db19c8415ba1b38ec9f14f2',
      'context' => 'a746f63bc0d15e45ce7684127cb8529f',
      'dart_tags' => '3550e409c42412cd16c9e9eaef186967',
      'wysiwyg' => 'da3d9003f8ae8b6e62c6f5691b463831',
      'user_permission' => '6d5d7e80c83975eff7cd825b7eb2d5bb',
      'box' => '3383f1f603db7b7326791f93da58fe7e',
      'apachesolr_environment' => '025e98b1afaacea1a473331e2c39a34b',
      'apachesolr_search_page' => FALSE,
      'delta' => '3598971239c97378b332f0fee50cdc98',
      'apachesolr_environment_variable' => '00119faab8a545369bd8716ab5c4dd92',
      'image' => '51890cda05bf1a5de295e9214e2401aa',
      'file_display' => '6cf2a0ded84c3c483c6f62ec6d9e80b6',
      'fe_nodequeue' => '7f8f22631fccf99e6e5d7c90ebc164e9',
      'metatag_config' => FALSE,
      'fontyourface' => '10dbb80e52754ba4392d44d652da9827',
    ),
  );
  $export['features_codecache'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_account';
  $strongarm->value = 'UA-4245914-60';
  $export['googleanalytics_account'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_cache';
  $strongarm->value = 0;
  $export['googleanalytics_cache'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_codesnippet_after';
  $strongarm->value = '';
  $export['googleanalytics_codesnippet_after'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_codesnippet_before';
  $strongarm->value = '';
  $export['googleanalytics_codesnippet_before'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_cross_domains';
  $strongarm->value = '';
  $export['googleanalytics_cross_domains'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_custom';
  $strongarm->value = '0';
  $export['googleanalytics_custom'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_custom_var';
  $strongarm->value = array(
    'slots' => array(
      1 => array(
        'slot' => 1,
        'name' => '',
        'value' => '',
        'scope' => '3',
      ),
      2 => array(
        'slot' => 2,
        'name' => '',
        'value' => '',
        'scope' => '3',
      ),
      3 => array(
        'slot' => 3,
        'name' => '',
        'value' => '',
        'scope' => '3',
      ),
      4 => array(
        'slot' => 4,
        'name' => '',
        'value' => '',
        'scope' => '3',
      ),
      5 => array(
        'slot' => 5,
        'name' => '',
        'value' => '',
        'scope' => '3',
      ),
    ),
  );
  $export['googleanalytics_custom_var'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_domain_mode';
  $strongarm->value = '0';
  $export['googleanalytics_domain_mode'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_js_scope';
  $strongarm->value = 'header';
  $export['googleanalytics_js_scope'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_pages';
  $strongarm->value = 'admin

admin/*

batch

node/add*

node/*/*

user/*/*';
  $export['googleanalytics_pages'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_privacy_donottrack';
  $strongarm->value = 1;
  $export['googleanalytics_privacy_donottrack'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_roles';
  $strongarm->value = array(
    1 => 0,
    2 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $export['googleanalytics_roles'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_site_search';
  $strongarm->value = FALSE;
  $export['googleanalytics_site_search'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_trackadsense';
  $strongarm->value = 0;
  $export['googleanalytics_trackadsense'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_tracker_anonymizeip';
  $strongarm->value = 0;
  $export['googleanalytics_tracker_anonymizeip'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_trackfiles';
  $strongarm->value = 1;
  $export['googleanalytics_trackfiles'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_trackfiles_extensions';
  $strongarm->value = '7z|aac|arc|arj|asf|asx|avi|bin|csv|doc|exe|flv|gif|gz|gzip|hqx|jar|jpe?g|js|mp(2|3|4|e?g)|mov(ie)?|msi|msp|pdf|phps|png|ppt|qtm?|ra(m|r)?|sea|sit|tar|tgz|torrent|txt|wav|wma|wmv|wpd|xls|xml|z|zip';
  $export['googleanalytics_trackfiles_extensions'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_trackmailto';
  $strongarm->value = 1;
  $export['googleanalytics_trackmailto'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_trackoutbound';
  $strongarm->value = 1;
  $export['googleanalytics_trackoutbound'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_trackoutboundaspageview';
  $strongarm->value = 0;
  $export['googleanalytics_trackoutboundaspageview'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_visibility_pages';
  $strongarm->value = '0';
  $export['googleanalytics_visibility_pages'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_visibility_roles';
  $strongarm->value = '0';
  $export['googleanalytics_visibility_roles'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_toolkit';
  $strongarm->value = 'gd';
  $export['image_toolkit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_article';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_blog';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_hotties_profile';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_hotties_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_joke';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_link_stub';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_list';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_page';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_poll';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_review';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_slideshow';
  $strongarm->value = array();
  $export['menu_options_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_video';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_webform';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_article';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_blog';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_hotties_profile';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_hotties_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_joke';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_link_stub';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_list';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_page';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_poll';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_review';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_slideshow';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_video';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_webform';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodequeue_autocomplete_limit';
  $strongarm->value = '10';
  $export['nodequeue_autocomplete_limit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodequeue_links';
  $strongarm->value = FALSE;
  $export['nodequeue_links'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodequeue_tab_name';
  $strongarm->value = 'Add To Content Lists';
  $export['nodequeue_tab_name'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodequeue_use_tab';
  $strongarm->value = 1;
  $export['nodequeue_use_tab'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodequeue_view_per_queue';
  $strongarm->value = 1;
  $export['nodequeue_view_per_queue'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_admin_theme';
  $strongarm->value = '1';
  $export['node_admin_theme'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_article';
  $strongarm->value = array(
    0 => 'promote',
    1 => 'revision',
  );
  $export['node_options_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_blog';
  $strongarm->value = array(
    0 => 'promote',
    1 => 'revision',
  );
  $export['node_options_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_hotties_profile';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_hotties_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_joke';
  $strongarm->value = array();
  $export['node_options_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_link_stub';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_list';
  $strongarm->value = array();
  $export['node_options_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_page';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_poll';
  $strongarm->value = array(
    0 => 'promote',
  );
  $export['node_options_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_review';
  $strongarm->value = array();
  $export['node_options_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_slideshow';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_video';
  $strongarm->value = array();
  $export['node_options_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_webform';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_article';
  $strongarm->value = '1';
  $export['node_preview_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_blog';
  $strongarm->value = '1';
  $export['node_preview_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_hotties_profile';
  $strongarm->value = '1';
  $export['node_preview_hotties_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_joke';
  $strongarm->value = '1';
  $export['node_preview_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_link_stub';
  $strongarm->value = '1';
  $export['node_preview_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_list';
  $strongarm->value = '1';
  $export['node_preview_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_page';
  $strongarm->value = '1';
  $export['node_preview_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_poll';
  $strongarm->value = '1';
  $export['node_preview_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_review';
  $strongarm->value = '1';
  $export['node_preview_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_slideshow';
  $strongarm->value = '1';
  $export['node_preview_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_video';
  $strongarm->value = '1';
  $export['node_preview_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_webform';
  $strongarm->value = '1';
  $export['node_preview_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_article';
  $strongarm->value = 0;
  $export['node_submitted_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_blog';
  $strongarm->value = 0;
  $export['node_submitted_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_hotties_profile';
  $strongarm->value = 0;
  $export['node_submitted_hotties_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_joke';
  $strongarm->value = 0;
  $export['node_submitted_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_link_stub';
  $strongarm->value = 0;
  $export['node_submitted_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_list';
  $strongarm->value = 0;
  $export['node_submitted_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_page';
  $strongarm->value = 0;
  $export['node_submitted_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_poll';
  $strongarm->value = 0;
  $export['node_submitted_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_review';
  $strongarm->value = 0;
  $export['node_submitted_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_slideshow';
  $strongarm->value = 0;
  $export['node_submitted_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_video';
  $strongarm->value = 0;
  $export['node_submitted_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_webform';
  $strongarm->value = 0;
  $export['node_submitted_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_cache_maximum_age';
  $strongarm->value = '1800';
  $export['page_cache_maximum_age'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_compression';
  $strongarm->value = 1;
  $export['page_compression'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_blog_pattern';
  $strongarm->value = 'blogs/[user:name]';
  $export['pathauto_blog_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_case';
  $strongarm->value = '1';
  $export['pathauto_case'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_forum_pattern';
  $strongarm->value = '[term:vocabulary]/[term:name]';
  $export['pathauto_forum_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_ignore_words';
  $strongarm->value = 'a, an, as, at, before, but, by, for, from, is, in, into, like, off, on, onto, per, since, than, that, to, up, via';
  $export['pathauto_ignore_words'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_max_component_length';
  $strongarm->value = '100';
  $export['pathauto_max_component_length'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_max_length';
  $strongarm->value = '100';
  $export['pathauto_max_length'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_article_pattern';
  $strongarm->value = '';
  $export['pathauto_node_article_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_blog_pattern';
  $strongarm->value = '';
  $export['pathauto_node_blog_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_joke_pattern';
  $strongarm->value = '';
  $export['pathauto_node_joke_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_link_stub_pattern';
  $strongarm->value = '';
  $export['pathauto_node_link_stub_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_list_pattern';
  $strongarm->value = '';
  $export['pathauto_node_list_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_page_pattern';
  $strongarm->value = '';
  $export['pathauto_node_page_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_pattern';
  $strongarm->value = '[node:field_channel]/[node:title]';
  $export['pathauto_node_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_poll_pattern';
  $strongarm->value = 'poll/[node:title]';
  $export['pathauto_node_poll_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_review_pattern';
  $strongarm->value = '';
  $export['pathauto_node_review_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_slideshow_pattern';
  $strongarm->value = '';
  $export['pathauto_node_slideshow_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_video_pattern';
  $strongarm->value = 'maximtv/[node:title]';
  $export['pathauto_node_video_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_webform_pattern';
  $strongarm->value = '';
  $export['pathauto_node_webform_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_ampersand';
  $strongarm->value = '0';
  $export['pathauto_punctuation_ampersand'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_asterisk';
  $strongarm->value = '0';
  $export['pathauto_punctuation_asterisk'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_at';
  $strongarm->value = '0';
  $export['pathauto_punctuation_at'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_backtick';
  $strongarm->value = '0';
  $export['pathauto_punctuation_backtick'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_back_slash';
  $strongarm->value = '0';
  $export['pathauto_punctuation_back_slash'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_caret';
  $strongarm->value = '0';
  $export['pathauto_punctuation_caret'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_colon';
  $strongarm->value = '0';
  $export['pathauto_punctuation_colon'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_comma';
  $strongarm->value = '0';
  $export['pathauto_punctuation_comma'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_dollar';
  $strongarm->value = '0';
  $export['pathauto_punctuation_dollar'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_double_quotes';
  $strongarm->value = '0';
  $export['pathauto_punctuation_double_quotes'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_equal';
  $strongarm->value = '0';
  $export['pathauto_punctuation_equal'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_exclamation';
  $strongarm->value = '0';
  $export['pathauto_punctuation_exclamation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_greater_than';
  $strongarm->value = '0';
  $export['pathauto_punctuation_greater_than'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_hash';
  $strongarm->value = '0';
  $export['pathauto_punctuation_hash'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_hyphen';
  $strongarm->value = '1';
  $export['pathauto_punctuation_hyphen'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_left_curly';
  $strongarm->value = '0';
  $export['pathauto_punctuation_left_curly'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_left_parenthesis';
  $strongarm->value = '0';
  $export['pathauto_punctuation_left_parenthesis'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_left_square';
  $strongarm->value = '0';
  $export['pathauto_punctuation_left_square'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_less_than';
  $strongarm->value = '0';
  $export['pathauto_punctuation_less_than'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_percent';
  $strongarm->value = '0';
  $export['pathauto_punctuation_percent'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_period';
  $strongarm->value = '0';
  $export['pathauto_punctuation_period'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_pipe';
  $strongarm->value = '0';
  $export['pathauto_punctuation_pipe'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_plus';
  $strongarm->value = '0';
  $export['pathauto_punctuation_plus'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_question_mark';
  $strongarm->value = '0';
  $export['pathauto_punctuation_question_mark'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_quotes';
  $strongarm->value = '0';
  $export['pathauto_punctuation_quotes'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_right_curly';
  $strongarm->value = '0';
  $export['pathauto_punctuation_right_curly'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_right_parenthesis';
  $strongarm->value = '0';
  $export['pathauto_punctuation_right_parenthesis'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_right_square';
  $strongarm->value = '0';
  $export['pathauto_punctuation_right_square'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_semicolon';
  $strongarm->value = '0';
  $export['pathauto_punctuation_semicolon'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_slash';
  $strongarm->value = '0';
  $export['pathauto_punctuation_slash'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_tilde';
  $strongarm->value = '0';
  $export['pathauto_punctuation_tilde'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_underscore';
  $strongarm->value = '0';
  $export['pathauto_punctuation_underscore'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_reduce_ascii';
  $strongarm->value = 1;
  $export['pathauto_reduce_ascii'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_separator';
  $strongarm->value = '-';
  $export['pathauto_separator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_channels_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_channels_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_columns_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_columns_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_content_authors_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_content_authors_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_freeform_tags_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_freeform_tags_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_joke_categories_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_joke_categories_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_partner_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_partner_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_pattern';
  $strongarm->value = '[term:vocabulary]/[term:name]';
  $export['pathauto_taxonomy_term_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_people_places_things_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_people_places_things_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_reviews_game_platforms_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_reviews_game_platforms_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_reviews_mpaa_ratings_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_reviews_mpaa_ratings_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_reviews_sources_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_reviews_sources_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_reviews_star_rating_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_reviews_star_rating_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_reviews_tv_networks_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_reviews_tv_networks_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_review_types_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_review_types_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_tags_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_tags_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_transliterate';
  $strongarm->value = FALSE;
  $export['pathauto_transliterate'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_update_action';
  $strongarm->value = '2';
  $export['pathauto_update_action'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_user_pattern';
  $strongarm->value = 'users/[user:name]';
  $export['pathauto_user_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_verbose';
  $strongarm->value = 0;
  $export['pathauto_verbose'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'preprocess_css';
  $strongarm->value = 1;
  $export['preprocess_css'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'preprocess_js';
  $strongarm->value = 1;
  $export['preprocess_js'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_article';
  $strongarm->value = 1;
  $export['scheduler_publish_enable_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_blog';
  $strongarm->value = 1;
  $export['scheduler_publish_enable_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_joke';
  $strongarm->value = 1;
  $export['scheduler_publish_enable_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_link_stub';
  $strongarm->value = 1;
  $export['scheduler_publish_enable_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_list';
  $strongarm->value = 1;
  $export['scheduler_publish_enable_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_page';
  $strongarm->value = 1;
  $export['scheduler_publish_enable_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_poll';
  $strongarm->value = 1;
  $export['scheduler_publish_enable_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_review';
  $strongarm->value = 1;
  $export['scheduler_publish_enable_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_slideshow';
  $strongarm->value = 1;
  $export['scheduler_publish_enable_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_video';
  $strongarm->value = 1;
  $export['scheduler_publish_enable_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_webform';
  $strongarm->value = 1;
  $export['scheduler_publish_enable_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_article';
  $strongarm->value = 0;
  $export['scheduler_publish_required_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_blog';
  $strongarm->value = 0;
  $export['scheduler_publish_required_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_joke';
  $strongarm->value = 0;
  $export['scheduler_publish_required_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_link_stub';
  $strongarm->value = 0;
  $export['scheduler_publish_required_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_list';
  $strongarm->value = 0;
  $export['scheduler_publish_required_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_page';
  $strongarm->value = 0;
  $export['scheduler_publish_required_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_poll';
  $strongarm->value = 0;
  $export['scheduler_publish_required_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_review';
  $strongarm->value = 0;
  $export['scheduler_publish_required_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_slideshow';
  $strongarm->value = 0;
  $export['scheduler_publish_required_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_video';
  $strongarm->value = 0;
  $export['scheduler_publish_required_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_webform';
  $strongarm->value = 0;
  $export['scheduler_publish_required_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_article';
  $strongarm->value = 1;
  $export['scheduler_publish_revision_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_blog';
  $strongarm->value = 1;
  $export['scheduler_publish_revision_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_joke';
  $strongarm->value = 1;
  $export['scheduler_publish_revision_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_link_stub';
  $strongarm->value = 1;
  $export['scheduler_publish_revision_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_list';
  $strongarm->value = 1;
  $export['scheduler_publish_revision_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_page';
  $strongarm->value = 1;
  $export['scheduler_publish_revision_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_poll';
  $strongarm->value = 1;
  $export['scheduler_publish_revision_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_review';
  $strongarm->value = 1;
  $export['scheduler_publish_revision_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_slideshow';
  $strongarm->value = 1;
  $export['scheduler_publish_revision_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_video';
  $strongarm->value = 1;
  $export['scheduler_publish_revision_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_webform';
  $strongarm->value = 1;
  $export['scheduler_publish_revision_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_article';
  $strongarm->value = 1;
  $export['scheduler_publish_touch_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_blog';
  $strongarm->value = 1;
  $export['scheduler_publish_touch_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_joke';
  $strongarm->value = 1;
  $export['scheduler_publish_touch_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_link_stub';
  $strongarm->value = 1;
  $export['scheduler_publish_touch_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_list';
  $strongarm->value = 1;
  $export['scheduler_publish_touch_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_page';
  $strongarm->value = 1;
  $export['scheduler_publish_touch_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_poll';
  $strongarm->value = 1;
  $export['scheduler_publish_touch_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_review';
  $strongarm->value = 1;
  $export['scheduler_publish_touch_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_slideshow';
  $strongarm->value = 1;
  $export['scheduler_publish_touch_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_video';
  $strongarm->value = 1;
  $export['scheduler_publish_touch_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_webform';
  $strongarm->value = 1;
  $export['scheduler_publish_touch_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_article';
  $strongarm->value = 1;
  $export['scheduler_unpublish_enable_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_blog';
  $strongarm->value = 1;
  $export['scheduler_unpublish_enable_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_joke';
  $strongarm->value = 1;
  $export['scheduler_unpublish_enable_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_link_stub';
  $strongarm->value = 1;
  $export['scheduler_unpublish_enable_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_list';
  $strongarm->value = 1;
  $export['scheduler_unpublish_enable_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_page';
  $strongarm->value = 1;
  $export['scheduler_unpublish_enable_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_poll';
  $strongarm->value = 1;
  $export['scheduler_unpublish_enable_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_review';
  $strongarm->value = 1;
  $export['scheduler_unpublish_enable_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_slideshow';
  $strongarm->value = 1;
  $export['scheduler_unpublish_enable_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_video';
  $strongarm->value = 1;
  $export['scheduler_unpublish_enable_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_webform';
  $strongarm->value = 1;
  $export['scheduler_unpublish_enable_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_article';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_blog';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_joke';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_link_stub';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_list';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_page';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_poll';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_review';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_slideshow';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_video';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_webform';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_article';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_blog';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_joke';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_link_stub';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_link_stub'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_list';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_page';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_poll';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_review';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_slideshow';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_video';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_webform';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_webform'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_active_modules';
  $strongarm->value = array(
    'apachesolr_search' => 'apachesolr_search',
    'advanced_help' => 0,
    'node' => 0,
    'user' => 0,
  );
  $export['search_active_modules'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_default_module';
  $strongarm->value = 'apachesolr_search';
  $export['search_default_module'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'frontpage';
  $export['site_frontpage'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_default';
  $strongarm->value = 'maxim_base';
  $export['theme_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_admin_role';
  $strongarm->value = '3';
  $export['user_admin_role'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_csv_delimiter';
  $strongarm->value = '\\t';
  $export['webform_csv_delimiter'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_default_format';
  $strongarm->value = 0;
  $export['webform_default_format'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_default_from_address';
  $strongarm->value = 'contests@maxim.com';
  $export['webform_default_from_address'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_default_from_name';
  $strongarm->value = 'Maxim';
  $export['webform_default_from_name'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_default_subject';
  $strongarm->value = 'Form submission from: %title';
  $export['webform_default_subject'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_disabled_components';
  $strongarm->value = array();
  $export['webform_disabled_components'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_email_address_format';
  $strongarm->value = 'long';
  $export['webform_email_address_format'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_export_format';
  $strongarm->value = 'delimited';
  $export['webform_export_format'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_format_override';
  $strongarm->value = 0;
  $export['webform_format_override'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_node_types';
  $strongarm->value = array(
    0 => 'webform',
  );
  $export['webform_node_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_search_index';
  $strongarm->value = 0;
  $export['webform_search_index'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_submission_access_control';
  $strongarm->value = '1';
  $export['webform_submission_access_control'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_use_cookies';
  $strongarm->value = 1;
  $export['webform_use_cookies'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_base_url';
  $strongarm->value = 'http://www.maxim.com';
  $export['xmlsitemap_base_url'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_batch_limit';
  $strongarm->value = '100';
  $export['xmlsitemap_batch_limit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_chunk_size';
  $strongarm->value = 'auto';
  $export['xmlsitemap_chunk_size'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_developer_mode';
  $strongarm->value = 0;
  $export['xmlsitemap_developer_mode'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_frontpage_changefreq';
  $strongarm->value = '86400';
  $export['xmlsitemap_frontpage_changefreq'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_frontpage_priority';
  $strongarm->value = '1.0';
  $export['xmlsitemap_frontpage_priority'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_lastmod_format';
  $strongarm->value = 'Y-m-d\\TH:i\\Z';
  $export['xmlsitemap_lastmod_format'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_minimum_lifetime';
  $strongarm->value = '86400';
  $export['xmlsitemap_minimum_lifetime'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_path';
  $strongarm->value = 'xmlsitemap';
  $export['xmlsitemap_path'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_prefetch_aliases';
  $strongarm->value = 0;
  $export['xmlsitemap_prefetch_aliases'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_article';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.7',
  );
  $export['xmlsitemap_settings_node_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_blog';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.7',
  );
  $export['xmlsitemap_settings_node_blog'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_joke';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_joke'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_list';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_page';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_poll';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.3',
  );
  $export['xmlsitemap_settings_node_poll'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_review';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_slideshow';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_slideshow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_video';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_taxonomy_term_channels';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.9',
  );
  $export['xmlsitemap_settings_taxonomy_term_channels'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_taxonomy_term_columns';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_taxonomy_term_columns'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings__active_tab';
  $strongarm->value = 'edit-frontpage';
  $export['xmlsitemap_settings__active_tab'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_xsl';
  $strongarm->value = 1;
  $export['xmlsitemap_xsl'] = $strongarm;

  return $export;
}
