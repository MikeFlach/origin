<?php
/**
 * @file
 * maxim_generic_profile.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function maxim_generic_profile_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'general_profile_nq_slider';
  $view->description = '2013 Hotties Slider';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'General Profile NQ Slider';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '-1';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'gprofile-list clearfix';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Title';
  $handler->display->display_options['header']['area']['content'] = 'Week 1 Hottie Contestants';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['label'] = '2013 Hotties Nodequeue';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'hth_2013_contestants_week_1' => 'hth_2013_contestants_week_1',
    'jumbotron_items' => 0,
    'newsreel' => 0,
    'top_menu_items' => 0,
    'featured_links' => 0,
    'about_maxim_links' => 0,
    'magazine_links' => 0,
    'channel_features' => 0,
    'girls_all_top_100s' => 0,
    'halloween' => 0,
    'baseball' => 0,
    'football' => 0,
    'military' => 0,
    'partner_links_bottom' => 0,
    'partner_links_side' => 0,
    'in_the_magazine' => 0,
    'hth_2013_contestants_week_2' => 0,
    'hth_2013_contestants_week_3' => 0,
    'hth_2013_contestants_week_4' => 0,
    'hth_2013_contestants_week_5' => 0,
    'hot100_2012' => 0,
  );
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_main_image']['element_class'] = 'gprofile-image';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'feature_icon',
    'image_link' => 'content',
  );
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_profile_first_name']['id'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['table'] = 'field_data_field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['field'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_first_name']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_profile_first_name']['element_class'] = 'gprofile-name';
  $handler->display->display_options['fields']['field_profile_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_first_name']['element_default_classes'] = FALSE;
  /* Field: Nodequeue: Position */
  $handler->display->display_options['fields']['position']['id'] = 'position';
  $handler->display->display_options['fields']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['fields']['position']['field'] = 'position';
  $handler->display->display_options['fields']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['fields']['position']['label'] = '';
  $handler->display->display_options['fields']['position']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['position']['element_type'] = '0';
  $handler->display->display_options['fields']['position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['position']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['position']['element_wrapper_class'] = 'position';
  $handler->display->display_options['fields']['position']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['position']['separator'] = '';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';

  /* Display: Ciroc Military */
  $handler = $view->new_display('block', 'Ciroc Military', 'ciroc_military_slider');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Title';
  $handler->display->display_options['header']['area']['content'] = 'All Contestants';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['label'] = '2013 Hotties Nodequeue';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'military_ciroc_nq' => 'military_ciroc_nq',
    'jumbotron_items' => 0,
    'newsreel' => 0,
    'top_menu_items' => 0,
    'featured_links' => 0,
    'about_maxim_links' => 0,
    'magazine_links' => 0,
    'channel_features' => 0,
    'girls_all_top_100s' => 0,
    'halloween' => 0,
    'baseball' => 0,
    'football' => 0,
    'military' => 0,
    'partner_links_bottom' => 0,
    'partner_links_side' => 0,
    'in_the_magazine' => 0,
    'hth_2013_contestants_week_1' => 0,
    'hth_2013_contestants_week_2' => 0,
    'hth_2013_contestants_week_3' => 0,
    'hth_2013_contestants_week_4' => 0,
    'hth_2013_contestants_week_5' => 0,
    'hot100_2012' => 0,
    'hth_2013_semi_finals' => 0,
    'hth_2013_finals' => 0,
    'gamer_girl_finalists' => 0,
    'uk_feature_story' => 0,
    'devil_s_cut_2012' => 0,
  );
  $handler->display->display_options['block_description'] = 'Ciroc Military Slider';

  /* Display: Body Fortress */
  $handler = $view->new_display('block', 'Body Fortress', 'body_fortress_slider');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Title';
  $handler->display->display_options['header']['area']['content'] = 'All Contestants';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['label'] = '2013 Hotties Nodequeue';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'athlete_bodyfort_nq' => 'athlete_bodyfort_nq',
    'jumbotron_items' => 0,
    'newsreel' => 0,
    'top_menu_items' => 0,
    'featured_links' => 0,
    'about_maxim_links' => 0,
    'magazine_links' => 0,
    'channel_features' => 0,
    'girls_all_top_100s' => 0,
    'halloween' => 0,
    'baseball' => 0,
    'football' => 0,
    'military' => 0,
    'partner_links_bottom' => 0,
    'partner_links_side' => 0,
    'in_the_magazine' => 0,
    'hth_2013_contestants_week_1' => 0,
    'hth_2013_contestants_week_2' => 0,
    'hth_2013_contestants_week_3' => 0,
    'hth_2013_contestants_week_4' => 0,
    'hth_2013_contestants_week_5' => 0,
    'hot100_2012' => 0,
    'hth_2013_semi_finals' => 0,
    'hth_2013_finals' => 0,
    'gamer_girl_finalists' => 0,
    'uk_feature_story' => 0,
    'devil_s_cut_2012' => 0,
    'military_ciroc_nq' => 0,
  );
  $handler->display->display_options['block_description'] = 'Body Fortress Slider';
  $export['general_profile_nq_slider'] = $view;

  return $export;
}
