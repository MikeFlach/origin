<?php
/**
 * @file
 * maxim_core.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function maxim_core_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'about_maxim_links';
  $view->description = '';
  $view->tag = 'footer';
  $view->base_table = 'node';
  $view->human_name = 'About Maxim Links';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'footer-list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 0;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'jumbotron_items' => 0,
    'newsreel' => 0,
    'partner_links' => 0,
    'maxim_magazine_links' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Nodequeue: Queue title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'nodequeue_queue';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['filters']['title_1']['value'] = 'About Maxim Links';

  /* Display: About Maxim Links */
  $handler = $view->new_display('block', 'About Maxim Links', 'block');
  $handler->display->display_options['block_description'] = 'About Maxim Links';
  $export['about_maxim_links'] = $view;

  $view = new view;
  $view->name = 'channel';
  $view->description = 'A view to emulate Drupal core\'s handling of taxonomy/term.';
  $view->tag = 'channel';
  $view->base_table = 'node';
  $view->human_name = 'Channel';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title_enable'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'channels' => 'channels',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['transform'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['set_breadcrumb'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['use_taxonomy_term_path'] = 0;
  /* Contextual filter: Content: Has taxonomy term ID depth modifier */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['exception']['title_enable'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['specify_validation'] = 1;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest Stories';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Channel */
  $handler->display->display_options['fields']['field_channel']['id'] = 'field_channel';
  $handler->display->display_options['fields']['field_channel']['table'] = 'field_data_field_channel';
  $handler->display->display_options['fields']['field_channel']['field'] = 'field_channel';
  $handler->display->display_options['fields']['field_channel']['label'] = '';
  $handler->display->display_options['fields']['field_channel']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_channel']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_channel']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_channel']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_channel']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_channel']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_channel']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_channel']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_channel']['field_api_classes'] = 0;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_main_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_main_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_main_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_main_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_main_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_large',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_main_image']['field_api_classes'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<a><i><b><strong><em><p>';
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '2500',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'taxonomy/term/%';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 15;
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'taxonomy/term/%/%/feed';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['channel'] = $view;

  $view = new view;
  $view->name = 'featured_links';
  $view->description = '';
  $view->tag = 'footer';
  $view->base_table = 'node';
  $view->human_name = 'Featured Links';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'footer-list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 0;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'jumbotron_items' => 0,
    'newsreel' => 0,
    'partner_links' => 0,
    'maxim_magazine_links' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Nodequeue: Queue title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'nodequeue_queue';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['filters']['title_1']['value'] = 'Featured Links';

  /* Display: Featured Links */
  $handler = $view->new_display('block', 'Featured Links', 'block');
  $handler->display->display_options['block_description'] = 'Featured Links';
  $export['featured_links'] = $view;

  $view = new view;
  $view->name = 'home_page';
  $view->description = 'Emulates the default Drupal front page; you may set the default home page path to this view to make it your front page.';
  $view->tag = 'frontpage';
  $view->base_table = 'node';
  $view->human_name = 'Front Page';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['title']['alter']['preserve_tags'] = '<p><b><i><strong><em>';
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Channel */
  $handler->display->display_options['fields']['field_channel']['id'] = 'field_channel';
  $handler->display->display_options['fields']['field_channel']['table'] = 'field_data_field_channel';
  $handler->display->display_options['fields']['field_channel']['field'] = 'field_channel';
  $handler->display->display_options['fields']['field_channel']['label'] = '';
  $handler->display->display_options['fields']['field_channel']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_channel']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_channel']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_channel']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_channel']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_channel']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_channel']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_channel']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_channel']['field_api_classes'] = 0;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_main_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_main_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_main_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_main_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_main_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_large',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_main_image']['field_api_classes'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<p><b><i><strong><em>';
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '2500',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 0;
  $handler->display->display_options['filters']['promote']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'link_stub' => 'link_stub',
    'poll' => 'poll',
  );
  /* Filter criterion: Nodequeue: In queue */
  $handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel';

  /* Display: Home Page */
  $handler = $view->new_display('page', 'Home Page', 'page');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 0;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'jumbotron_items' => 'jumbotron_items',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 0;
  $handler->display->display_options['filters']['promote']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'link_stub' => 'link_stub',
    'poll' => 'poll',
  );
  /* Filter criterion: Nodequeue: In queue */
  $handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['filters']['in_queue']['value'] = '0';
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['operator'] = 'not';
  $handler->display->display_options['filters']['tid']['value'] = array(
    0 => '14020',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'channels';
  $handler->display->display_options['path'] = 'frontpage';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Front page feed';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'rss.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $handler->display->display_options['sitename_title'] = '1';

  /* Display: Latest blog posts */
  $handler = $view->new_display('block', 'Latest blog posts', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest blog posts';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 0;
  $handler->display->display_options['filters']['promote']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
  );
  /* Filter criterion: Nodequeue: In queue */
  $handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel';

  /* Display: Latest MaximTV */
  $handler = $view->new_display('block', 'Latest MaximTV', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest from MaximTV';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stub_image']['id'] = 'field_stub_image';
  $handler->display->display_options['fields']['field_stub_image']['table'] = 'field_data_field_stub_image';
  $handler->display->display_options['fields']['field_stub_image']['field'] = 'field_stub_image';
  $handler->display->display_options['fields']['field_stub_image']['label'] = '';
  $handler->display->display_options['fields']['field_stub_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stub_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stub_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stub_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stub_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stub_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stub_image']['settings'] = array(
    'image_style' => 'thumbnail_small',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_stub_image']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 0;
  $handler->display->display_options['filters']['promote']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  /* Filter criterion: Nodequeue: In queue */
  $handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel';
  $export['home_page'] = $view;

  $view = new view;
  $view->name = 'jumbotron';
  $view->description = 'Display Jumbotron Items';
  $view->tag = 'jumbotron';
  $view->base_table = 'node';
  $view->human_name = 'Jumbotron';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_json';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'jumbotron_items' => 'jumbotron_items',
  );
  /* Field: Content: Jumbotron Image */
  $handler->display->display_options['fields']['field_jumbo_image']['id'] = 'field_jumbo_image';
  $handler->display->display_options['fields']['field_jumbo_image']['table'] = 'field_data_field_jumbo_image';
  $handler->display->display_options['fields']['field_jumbo_image']['field'] = 'field_jumbo_image';
  $handler->display->display_options['fields']['field_jumbo_image']['label'] = 'src';
  $handler->display->display_options['fields']['field_jumbo_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_jumbo_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_jumbo_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_jumbo_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_jumbo_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_jumbo_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_jumbo_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_jumbo_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_jumbo_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_jumbo_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_jumbo_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_jumbo_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_jumbo_image']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_jumbo_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_jumbo_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_jumbo_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_jumbo_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_jumbo_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_jumbo_image']['settings'] = array(
    'image_style' => 'jumbotron',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_jumbo_image']['field_api_classes'] = 0;
  /* Field: Content: Jumbotron Subtitle */
  $handler->display->display_options['fields']['field_feature_subtitle']['id'] = 'field_feature_subtitle';
  $handler->display->display_options['fields']['field_feature_subtitle']['table'] = 'field_data_field_feature_subtitle';
  $handler->display->display_options['fields']['field_feature_subtitle']['field'] = 'field_feature_subtitle';
  $handler->display->display_options['fields']['field_feature_subtitle']['label'] = 'subtitle';
  $handler->display->display_options['fields']['field_feature_subtitle']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_feature_subtitle']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_feature_subtitle']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_feature_subtitle']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_feature_subtitle']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_feature_subtitle']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_feature_subtitle']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_feature_subtitle']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_feature_subtitle']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_feature_subtitle']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_feature_subtitle']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_feature_subtitle']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_feature_subtitle']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_feature_subtitle']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_feature_subtitle']['empty'] = ' ';
  $handler->display->display_options['fields']['field_feature_subtitle']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_feature_subtitle']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_feature_subtitle']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_feature_subtitle']['field_api_classes'] = 0;
  /* Field: Content: Jumbotron Title */
  $handler->display->display_options['fields']['field_feature_title']['id'] = 'field_feature_title';
  $handler->display->display_options['fields']['field_feature_title']['table'] = 'field_data_field_feature_title';
  $handler->display->display_options['fields']['field_feature_title']['field'] = 'field_feature_title';
  $handler->display->display_options['fields']['field_feature_title']['label'] = 'title';
  $handler->display->display_options['fields']['field_feature_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_feature_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_feature_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_feature_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_feature_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_feature_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_feature_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_feature_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_feature_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_feature_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_feature_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_feature_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_feature_title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_feature_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_feature_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_feature_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_feature_title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_feature_title']['field_api_classes'] = 0;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = 'thumb';
  $handler->display->display_options['fields']['field_main_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_main_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_main_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_main_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_main_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_main_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_main_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'jumbotron_carousel_icon',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_main_image']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'panelType';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'image';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 1;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Jumbotron */
  $handler = $view->new_display('page', 'Jumbotron', 'page');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = '';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'jumbotron.json';

  /* Display: Jumbtron Block */
  $handler = $view->new_display('block', 'Jumbtron Block', 'block_1');
  $handler->display->display_options['display_description'] = 'Jimbotron Block';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = '';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['jumbotron'] = $view;

  $view = new view;
  $view->name = 'magazine_links';
  $view->description = '';
  $view->tag = 'circulation';
  $view->base_table = 'node';
  $view->human_name = 'Magazine Links';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'footer-list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 0;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'jumbotron_items' => 0,
    'newsreel' => 0,
    'partner_links' => 0,
    'maxim_magazine_links' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Nodequeue: Queue title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'nodequeue_queue';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['filters']['title_1']['value'] = 'Magazine Links';

  /* Display: Magazine Links */
  $handler = $view->new_display('block', 'Magazine Links', 'block');
  $handler->display->display_options['block_description'] = 'Magazine Links';
  $export['magazine_links'] = $view;

  $view = new view;
  $view->name = 'maximtv_browser';
  $view->description = 'Groups of MaximTV content grouped by channel';
  $view->tag = 'maximtv';
  $view->base_table = 'node';
  $view->human_name = 'MaximTV Browser';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'more Gadgets & Rides';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '[field_channel]';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 1;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = 1;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'channels' => 'channels',
    'tags' => 0,
    'content_authors' => 0,
    'columns' => 0,
    'joke_categories' => 0,
    'partner' => 0,
    'people_places_things' => 0,
    'review_types' => 0,
    'reviews_game_platforms' => 0,
    'reviews_mpaa_ratings' => 0,
    'reviews_sources' => 0,
    'reviews_star_rating' => 0,
    'reviews_tv_networks' => 0,
    'freeform_tags' => 0,
  );
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['relationship'] = 'term_node_tid';
  $handler->display->display_options['relationships']['parent']['required'] = 0;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['path']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['path']['alter']['external'] = 0;
  $handler->display->display_options['fields']['path']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['path']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['path']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['path']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['path']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['path']['alter']['html'] = 0;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['path']['hide_empty'] = 0;
  $handler->display->display_options['fields']['path']['empty_zero'] = 0;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['path']['absolute'] = 0;
  /* Field: Field: Thumbnail Path */
  $handler->display->display_options['fields']['field_media_thumbnail_path']['id'] = 'field_media_thumbnail_path';
  $handler->display->display_options['fields']['field_media_thumbnail_path']['table'] = 'field_data_field_media_thumbnail_path';
  $handler->display->display_options['fields']['field_media_thumbnail_path']['field'] = 'field_media_thumbnail_path';
  $handler->display->display_options['fields']['field_media_thumbnail_path']['label'] = '';
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['text'] = '<img src="[field_media_thumbnail_path]" width="220" height="157" />';
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['absolute'] = 1;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Channel */
  $handler->display->display_options['fields']['field_channel']['id'] = 'field_channel';
  $handler->display->display_options['fields']['field_channel']['table'] = 'field_data_field_channel';
  $handler->display->display_options['fields']['field_channel']['field'] = 'field_channel';
  $handler->display->display_options['fields']['field_channel']['label'] = '';
  $handler->display->display_options['fields']['field_channel']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_channel']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_channel']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_channel']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_channel']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_channel']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_channel']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_channel']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_channel']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_channel']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Has taxonomy terms (with depth)';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'channels';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['error_message'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '1';

  /* Display: MaximTV Entertainment */
  $handler = $view->new_display('block', 'MaximTV Entertainment', 'block');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['block_description'] = 'MaximTV Entertainment';

  /* Display: MaximTV Girls */
  $handler = $view->new_display('block', 'MaximTV Girls', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Has taxonomy terms (with depth)';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'channels';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['error_message'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '1';
  $handler->display->display_options['block_description'] = 'MaximTV Girls';

  /* Display: MaximTV Sports */
  $handler = $view->new_display('block', 'MaximTV Sports', 'block_2');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Has taxonomy terms (with depth)';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'channels';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['error_message'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '1';
  $handler->display->display_options['block_description'] = 'MaximTV Sports';

  /* Display: MaximTV Gadgets & Rides */
  $handler = $view->new_display('block', 'MaximTV Gadgets & Rides', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    5 => '5',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Has taxonomy terms (with depth)';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'channels';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['error_message'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '1';
  $handler->display->display_options['block_description'] = 'MaximTV Gadgets';

  /* Display: MaximTV Upkeep */
  $handler = $view->new_display('block', 'MaximTV Upkeep', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    6 => '6',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Has taxonomy terms (with depth)';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'channels';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['error_message'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '1';
  $handler->display->display_options['block_description'] = 'MaximTV Upkeep';

  /* Display: MaximTV Vices */
  $handler = $view->new_display('block', 'MaximTV Vices', 'block_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    7 => '7',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Has taxonomy terms (with depth)';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'channels';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['error_message'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '1';
  $handler->display->display_options['block_description'] = 'MaximTV Vices';

  /* Display: MaximTV Tough */
  $handler = $view->new_display('block', 'MaximTV Tough', 'block_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    322 => '322',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Has taxonomy terms (with depth)';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'channels';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['error_message'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '1';
  $handler->display->display_options['block_description'] = 'MaximTV Tough';

  /* Display: MaximTV Funny */
  $handler = $view->new_display('block', 'MaximTV Funny', 'block_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    8 => '8',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Has taxonomy terms (with depth)';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'channels';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['error_message'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '1';
  $handler->display->display_options['block_description'] = 'MaximTV Funny';

  /* Display: MaximTV */
  $handler = $view->new_display('page', 'MaximTV', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'MaximTV';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['path']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['path']['alter']['external'] = 0;
  $handler->display->display_options['fields']['path']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['path']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['path']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['path']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['path']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['path']['alter']['html'] = 0;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['path']['hide_empty'] = 0;
  $handler->display->display_options['fields']['path']['empty_zero'] = 0;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['path']['absolute'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[path] ';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Field: Thumbnail Path */
  $handler->display->display_options['fields']['field_media_thumbnail_path']['id'] = 'field_media_thumbnail_path';
  $handler->display->display_options['fields']['field_media_thumbnail_path']['table'] = 'field_data_field_media_thumbnail_path';
  $handler->display->display_options['fields']['field_media_thumbnail_path']['field'] = 'field_media_thumbnail_path';
  $handler->display->display_options['fields']['field_media_thumbnail_path']['label'] = '';
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['text'] = '<img src="[field_media_thumbnail_path]" width="220" height="157" />';
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['absolute'] = 1;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_media_thumbnail_path']['field_api_classes'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Channel */
  $handler->display->display_options['fields']['field_channel']['id'] = 'field_channel';
  $handler->display->display_options['fields']['field_channel']['table'] = 'field_data_field_channel';
  $handler->display->display_options['fields']['field_channel']['field'] = 'field_channel';
  $handler->display->display_options['fields']['field_channel']['label'] = '';
  $handler->display->display_options['fields']['field_channel']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_channel']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_channel']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_channel']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_channel']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_channel']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_channel']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_channel']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_channel']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_channel']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  $handler->display->display_options['path'] = 'maximtv';
  $export['maximtv_browser'] = $view;

  $view = new view;
  $view->name = 'menu_content_items';
  $view->description = 'json pages to propagate menu items';
  $view->tag = 'menu';
  $view->base_table = 'node';
  $view->human_name = 'Menu Content Items';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '1800';
  $handler->display->display_options['cache']['output_lifespan'] = '1800';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'featured';
  $handler->display->display_options['style_options']['top_child_object'] = 'item';
  $handler->display->display_options['style_options']['plaintext_output'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['path']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['path']['alter']['external'] = 0;
  $handler->display->display_options['fields']['path']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['path']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['path']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['path']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['path']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['path']['alter']['html'] = 0;
  $handler->display->display_options['fields']['path']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['path']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['path']['hide_empty'] = 0;
  $handler->display->display_options['fields']['path']['empty_zero'] = 0;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['path']['absolute'] = 0;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = 'thumb';
  $handler->display->display_options['fields']['field_main_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_main_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_main_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_main_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_main_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_main_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_main_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_main_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_large',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_main_image']['field_api_classes'] = 0;
  /* Field: Content: Rendered Content */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = 'summary';
  $handler->display->display_options['fields']['rendered_entity']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['external'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['html'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['hide_empty'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['empty_zero'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'full';
  /* Field: Content: Channel */
  $handler->display->display_options['fields']['field_channel']['id'] = 'field_channel';
  $handler->display->display_options['fields']['field_channel']['table'] = 'field_data_field_channel';
  $handler->display->display_options['fields']['field_channel']['field'] = 'field_channel';
  $handler->display->display_options['fields']['field_channel']['label'] = 'channel_id';
  $handler->display->display_options['fields']['field_channel']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_channel']['alter']['text'] = '!1';
  $handler->display->display_options['fields']['field_channel']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_channel']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_channel']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_channel']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_channel']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_channel']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_channel']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_channel']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_channel']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_channel']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'channels' => 'channels',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = 0;
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['tid']['add_table'] = 0;
  $handler->display->display_options['arguments']['tid']['require_value'] = 0;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments']['tid']['set_breadcrumb'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'article' => 'article',
    'slideshow' => 'slideshow',
  );

  /* Display: subchannel feature */
  $handler = $view->new_display('page', 'subchannel feature', 'subchannel_feature');
  $handler->display->display_options['path'] = 'menu-subchannel/%';

  /* Display: channel features */
  $handler = $view->new_display('page', 'channel features', 'channel_features');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['path'] = 'menu-channel/%';

  /* Display: video features */
  $handler = $view->new_display('page', 'video features', 'video_features');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  $handler->display->display_options['path'] = 'menu-video/%';
  $export['menu_content_items'] = $view;

  $view = new view;
  $view->name = 'newsreel';
  $view->description = '';
  $view->tag = 'newsreel';
  $view->base_table = 'node';
  $view->human_name = 'Newsreel';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 0;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'jumbotron_items' => 0,
    'newsreel' => 0,
    'partner_links' => 0,
    'maxim_magazine_links' => 0,
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<link>[view_node] </link>';
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['alt'] = '[title]';
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_type'] = '0';
  $handler->display->display_options['fields']['view_node']['element_label_type'] = '0';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 0;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['text'] = '<p>[field_main_image-title]</p>';
  $handler->display->display_options['fields']['field_main_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_main_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_main_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_main_image']['alter']['preserve_tags'] = '<p>';
  $handler->display->display_options['fields']['field_main_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_main_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_main_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_main_image']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_main_image']['empty'] = '<img src="" width="70" height="50" />';
  $handler->display->display_options['fields']['field_main_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_main_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_main_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'feature_icon',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_main_image']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<p>[title]</p>';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '21';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Nodequeue: Queue title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'nodequeue_queue';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['filters']['title_1']['value'] = 'Newsreel';

  /* Display: Newsreel Small */
  $handler = $view->new_display('block', 'Newsreel Small', 'block');
  $handler->display->display_options['block_description'] = 'Newsreel Small';

  /* Display: Newsreel Large */
  $handler = $view->new_display('block', 'Newsreel Large', 'block_1');
  $handler->display->display_options['block_description'] = 'Newsreel Large';
  $export['newsreel'] = $view;

  $view = new view;
  $view->name = 'nodequeue_11';
  $view->description = 'Display a list of all nodes in queue \'Partner Links\'';
  $view->tag = 'nodequeue, partner';
  $view->base_table = 'node';
  $view->human_name = 'Partner Links Nodequeue View';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 1;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '[field_partner_image] ';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 1;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'partner_links' => 'partner_links',
  );
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  /* Field: Taxonomy term: Partner Link */
  $handler->display->display_options['fields']['field_partner_link']['id'] = 'field_partner_link';
  $handler->display->display_options['fields']['field_partner_link']['table'] = 'field_data_field_partner_link';
  $handler->display->display_options['fields']['field_partner_link']['field'] = 'field_partner_link';
  $handler->display->display_options['fields']['field_partner_link']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_partner_link']['label'] = '';
  $handler->display->display_options['fields']['field_partner_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_partner_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_partner_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_partner_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_partner_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_partner_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_partner_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_partner_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_partner_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_partner_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_partner_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_partner_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_partner_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_partner_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_partner_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_partner_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_partner_link']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_partner_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_partner_link']['field_api_classes'] = 0;
  /* Field: Taxonomy term: Partner Logo */
  $handler->display->display_options['fields']['field_partner_image']['id'] = 'field_partner_image';
  $handler->display->display_options['fields']['field_partner_image']['table'] = 'field_data_field_partner_image';
  $handler->display->display_options['fields']['field_partner_image']['field'] = 'field_partner_image';
  $handler->display->display_options['fields']['field_partner_image']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_partner_image']['label'] = '';
  $handler->display->display_options['fields']['field_partner_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_partner_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_partner_image']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_partner_image']['alter']['path'] = '[field_partner_link]';
  $handler->display->display_options['fields']['field_partner_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_partner_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_partner_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_partner_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_partner_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_partner_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_partner_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_partner_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_partner_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_partner_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_partner_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_partner_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_partner_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_partner_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_partner_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_partner_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_partner_image']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_stub_link']['id'] = 'field_stub_link';
  $handler->display->display_options['fields']['field_stub_link']['table'] = 'field_data_field_stub_link';
  $handler->display->display_options['fields']['field_stub_link']['field'] = 'field_stub_link';
  $handler->display->display_options['fields']['field_stub_link']['label'] = '';
  $handler->display->display_options['fields']['field_stub_link']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_stub_link']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['field_stub_link']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_stub_link']['alter']['path'] = '[field_stub_link]';
  $handler->display->display_options['fields']['field_stub_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['external'] = 1;
  $handler->display->display_options['fields']['field_stub_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stub_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stub_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stub_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stub_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stub_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_stub_link']['field_api_classes'] = 0;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;
  /* Filter criterion: Taxonomy term: Term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'partner';

  /* Display: Partner Links - Second */
  $handler = $view->new_display('block', 'Partner Links - Second', 'block_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'partner_links' => 'partner_links',
  );
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = 0;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'partner' => 'partner',
    'tags' => 0,
    'content_authors' => 0,
    'channels' => 0,
    'columns' => 0,
    'joke_categories' => 0,
    'people_places_things' => 0,
    'review_types' => 0,
    'reviews_game_platforms' => 0,
    'reviews_mpaa_ratings' => 0,
    'reviews_sources' => 0,
    'reviews_star_rating' => 0,
    'reviews_tv_networks' => 0,
    'freeform_tags' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;
  /* Filter criterion: Taxonomy term: Term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    13442 => '13442',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'partner';
  $handler->display->display_options['block_description'] = 'Partner Links - Second';

  /* Display: Partner Links - Third */
  $handler = $view->new_display('block', 'Partner Links - Third', 'block_2');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'partner_links' => 'partner_links',
  );
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = 0;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'partner' => 'partner',
    'tags' => 0,
    'content_authors' => 0,
    'channels' => 0,
    'columns' => 0,
    'joke_categories' => 0,
    'people_places_things' => 0,
    'review_types' => 0,
    'reviews_game_platforms' => 0,
    'reviews_mpaa_ratings' => 0,
    'reviews_sources' => 0,
    'reviews_star_rating' => 0,
    'reviews_tv_networks' => 0,
    'freeform_tags' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;
  /* Filter criterion: Taxonomy term: Term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    13441 => '13441',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'partner';
  $handler->display->display_options['block_description'] = 'Partner Links - Third';

  /* Display: Partner Links - Fourth */
  $handler = $view->new_display('block', 'Partner Links - Fourth', 'block_3');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'partner_links' => 'partner_links',
  );
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = 0;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'partner' => 'partner',
    'tags' => 0,
    'content_authors' => 0,
    'channels' => 0,
    'columns' => 0,
    'joke_categories' => 0,
    'people_places_things' => 0,
    'review_types' => 0,
    'reviews_game_platforms' => 0,
    'reviews_mpaa_ratings' => 0,
    'reviews_sources' => 0,
    'reviews_star_rating' => 0,
    'reviews_tv_networks' => 0,
    'freeform_tags' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;
  /* Filter criterion: Taxonomy term: Term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    13443 => '13443',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'partner';
  $handler->display->display_options['block_description'] = 'Partner Links - Fourth';

  /* Display: Partner Links - First */
  $handler = $view->new_display('block', 'Partner Links - First', 'block_4');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'partner_links' => 'partner_links',
  );
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = 0;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'partner' => 'partner',
    'tags' => 0,
    'content_authors' => 0,
    'channels' => 0,
    'columns' => 0,
    'joke_categories' => 0,
    'people_places_things' => 0,
    'review_types' => 0,
    'reviews_game_platforms' => 0,
    'reviews_mpaa_ratings' => 0,
    'reviews_sources' => 0,
    'reviews_star_rating' => 0,
    'reviews_tv_networks' => 0,
    'freeform_tags' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;
  /* Filter criterion: Taxonomy term: Term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    67 => '67',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'partner';
  $handler->display->display_options['block_description'] = 'Partner Links - First';
  $export['nodequeue_11'] = $view;

  $view = new view;
  $view->name = 'partner_feed';
  $view->description = 'Feeds to syndicate content to partners';
  $view->tag = 'partner';
  $view->base_table = 'node';
  $view->human_name = 'Partner feed';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Partner Feed';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'slideshow' => 'slideshow',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'partner-feed';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'partner-feed.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );

  /* Display: Fox News Feed */
  $handler = $view->new_display('feed', 'Fox News Feed', 'foxnews');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['path'] = 'foxnews-feed.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $export['partner_feed'] = $view;

  $view = new view;
  $view->name = 'partner_links';
  $view->description = '';
  $view->tag = 'partner';
  $view->base_table = 'node';
  $view->human_name = 'Partner Links';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_stub_link']['id'] = 'field_stub_link';
  $handler->display->display_options['fields']['field_stub_link']['table'] = 'field_data_field_stub_link';
  $handler->display->display_options['fields']['field_stub_link']['field'] = 'field_stub_link';
  $handler->display->display_options['fields']['field_stub_link']['label'] = '';
  $handler->display->display_options['fields']['field_stub_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stub_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stub_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stub_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stub_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stub_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_stub_link']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_stub_link']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_stub_link]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 1;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Partner (field_partner_source) */
  $handler->display->display_options['arguments']['field_partner_source_tid']['id'] = 'field_partner_source_tid';
  $handler->display->display_options['arguments']['field_partner_source_tid']['table'] = 'field_data_field_partner_source';
  $handler->display->display_options['arguments']['field_partner_source_tid']['field'] = 'field_partner_source_tid';
  $handler->display->display_options['arguments']['field_partner_source_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_partner_source_tid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['field_partner_source_tid']['title'] = '%1';
  $handler->display->display_options['arguments']['field_partner_source_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_partner_source_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_partner_source_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_partner_source_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_partner_source_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_partner_source_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_partner_source_tid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'link_stub' => 'link_stub',
  );

  /* Display: Partner Links - List View */
  $handler = $view->new_display('block', 'Partner Links - List View', 'partner_links_list');

  /* Display: Partner Links - Thumbnail View */
  $handler = $view->new_display('block', 'Partner Links - Thumbnail View', 'partner_links_thumbnail');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_stub_link']['id'] = 'field_stub_link';
  $handler->display->display_options['fields']['field_stub_link']['table'] = 'field_data_field_stub_link';
  $handler->display->display_options['fields']['field_stub_link']['field'] = 'field_stub_link';
  $handler->display->display_options['fields']['field_stub_link']['label'] = '';
  $handler->display->display_options['fields']['field_stub_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stub_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stub_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stub_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stub_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stub_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_stub_link']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_stub_link']['field_api_classes'] = 0;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stub_image']['id'] = 'field_stub_image';
  $handler->display->display_options['fields']['field_stub_image']['table'] = 'field_data_field_stub_image';
  $handler->display->display_options['fields']['field_stub_image']['field'] = 'field_stub_image';
  $handler->display->display_options['fields']['field_stub_image']['label'] = '';
  $handler->display->display_options['fields']['field_stub_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_stub_image']['alter']['path'] = '[field_stub_link]';
  $handler->display->display_options['fields']['field_stub_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['alter']['external'] = 1;
  $handler->display->display_options['fields']['field_stub_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_stub_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stub_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stub_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stub_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stub_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stub_image']['settings'] = array(
    'image_style' => 'thumbnail_medium',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_stub_image']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_stub_link]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 1;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  $export['partner_links'] = $view;

  $view = new view;
  $view->name = 'polls';
  $view->description = '';
  $view->tag = 'polls';
  $view->base_table = 'node';
  $view->human_name = 'Polls';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Today\'s Poll';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'see more polls';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'poll' => 'poll',
  );

  /* Display: Polls Listing */
  $handler = $view->new_display('page', 'Polls Listing', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Polls Archive';
  $handler->display->display_options['path'] = 'polls';

  /* Display: Most Recent Poll */
  $handler = $view->new_display('block', 'Most Recent Poll', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $export['polls'] = $view;

  $view = new view;
  $view->name = 'slideshow_json';
  $view->description = '';
  $view->tag = 'slideshow';
  $view->base_table = 'node';
  $view->human_name = 'Slideshow json';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'slideshow';
  $handler->display->display_options['style_options']['top_child_object'] = 'slide';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['content_type'] = 'text/json';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 1;
  /* Relationship: Content: Slides (field_slides_wrapper) */
  $handler->display->display_options['relationships']['field_slides_wrapper_value']['id'] = 'field_slides_wrapper_value';
  $handler->display->display_options['relationships']['field_slides_wrapper_value']['table'] = 'field_data_field_slides_wrapper';
  $handler->display->display_options['relationships']['field_slides_wrapper_value']['field'] = 'field_slides_wrapper_value';
  $handler->display->display_options['relationships']['field_slides_wrapper_value']['required'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Field-collection item: Slides */
  $handler->display->display_options['fields']['field_slides']['id'] = 'field_slides';
  $handler->display->display_options['fields']['field_slides']['table'] = 'field_data_field_slides';
  $handler->display->display_options['fields']['field_slides']['field'] = 'field_slides';
  $handler->display->display_options['fields']['field_slides']['relationship'] = 'field_slides_wrapper_value';
  $handler->display->display_options['fields']['field_slides']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slides']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slides']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slides']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slides']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slides']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slides']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slides']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slides']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slides']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slides']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slides']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slides']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_slides']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slides']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slides']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slides']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_slides']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_slides']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_slides']['settings'] = array(
    'file_view_mode' => 'default',
  );
  $handler->display->display_options['fields']['field_slides']['field_api_classes'] = 0;
  /* Field: Field-collection item: Caption */
  $handler->display->display_options['fields']['field_slide_caption']['id'] = 'field_slide_caption';
  $handler->display->display_options['fields']['field_slide_caption']['table'] = 'field_data_field_slide_caption';
  $handler->display->display_options['fields']['field_slide_caption']['field'] = 'field_slide_caption';
  $handler->display->display_options['fields']['field_slide_caption']['relationship'] = 'field_slides_wrapper_value';
  $handler->display->display_options['fields']['field_slide_caption']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slide_caption']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slide_caption']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slide_caption']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slide_caption']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slide_caption']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slide_caption']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slide_caption']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slide_caption']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slide_caption']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slide_caption']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slide_caption']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slide_caption']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_slide_caption']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slide_caption']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slide_caption']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slide_caption']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_slide_caption']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'slideshow' => 'slideshow',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;

  /* Display: Slideshow json */
  $handler = $view->new_display('block', 'Slideshow json', 'block_1');
  $export['slideshow_json'] = $view;

  return $export;
}
