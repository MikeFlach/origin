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
  $view->name = 'channel';
  $view->description = 'A view to emulate Drupal core\'s handling of taxonomy/term.';
  $view->tag = 'default';
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
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['set_breadcrumb'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['use_taxonomy_term_path'] = 1;
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
  $view->name = 'home_page';
  $view->description = 'Emulates the default Drupal front page; you may set the default home page path to this view to make it your front page.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Latest content';
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
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 1;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
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
    'poll' => 'poll',
  );
  /* Filter criterion: Nodequeue: In queue */
  $handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['filters']['in_queue']['value'] = '0';
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
    'image_style' => 'thumbnail',
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
  $view->description = 'Display a list of all nodes in queue \'Jumbotron Items\'';
  $view->tag = 'Jumbotron';
  $view->base_table = 'node';
  $view->human_name = 'Jumbotron Block';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Queue \'Jumbotron Items\'';
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stub_image']['id'] = 'field_stub_image';
  $handler->display->display_options['fields']['field_stub_image']['table'] = 'field_data_field_stub_image';
  $handler->display->display_options['fields']['field_stub_image']['field'] = 'field_stub_image';
  /* Field: Content: Jumbotron Image */
  $handler->display->display_options['fields']['field_jumbo_image']['id'] = 'field_jumbo_image';
  $handler->display->display_options['fields']['field_jumbo_image']['table'] = 'field_data_field_jumbo_image';
  $handler->display->display_options['fields']['field_jumbo_image']['field'] = 'field_jumbo_image';
  /* Field: Content: Jumbotron Subtitle */
  $handler->display->display_options['fields']['field_feature_subtitle']['id'] = 'field_feature_subtitle';
  $handler->display->display_options['fields']['field_feature_subtitle']['table'] = 'field_data_field_feature_subtitle';
  $handler->display->display_options['fields']['field_feature_subtitle']['field'] = 'field_feature_subtitle';
  /* Field: Content: Jumbotron Title */
  $handler->display->display_options['fields']['field_feature_title']['id'] = 'field_feature_title';
  $handler->display->display_options['fields']['field_feature_title']['table'] = 'field_data_field_feature_title';
  $handler->display->display_options['fields']['field_feature_title']['field'] = 'field_feature_title';
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_stub_link']['id'] = 'field_stub_link';
  $handler->display->display_options['fields']['field_stub_link']['table'] = 'field_data_field_stub_link';
  $handler->display->display_options['fields']['field_stub_link']['field'] = 'field_stub_link';
  /* Field: Content: Vignette Vanity URL */
  $handler->display->display_options['fields']['field_vgn_vanity_url']['id'] = 'field_vgn_vanity_url';
  $handler->display->display_options['fields']['field_vgn_vanity_url']['table'] = 'field_data_field_vgn_vanity_url';
  $handler->display->display_options['fields']['field_vgn_vanity_url']['field'] = 'field_vgn_vanity_url';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
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
  $handler->display->display_options['style_options']['root_object'] = 'jumbotron';
  $handler->display->display_options['style_options']['top_child_object'] = 'item';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_stub_image']['id'] = 'field_stub_image';
  $handler->display->display_options['fields']['field_stub_image']['table'] = 'field_data_field_stub_image';
  $handler->display->display_options['fields']['field_stub_image']['field'] = 'field_stub_image';
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
  $handler->display->display_options['fields']['field_stub_image']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_stub_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stub_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stub_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stub_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stub_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_stub_image']['field_api_classes'] = 0;
  /* Field: Content: Jumbotron Image */
  $handler->display->display_options['fields']['field_jumbo_image']['id'] = 'field_jumbo_image';
  $handler->display->display_options['fields']['field_jumbo_image']['table'] = 'field_data_field_jumbo_image';
  $handler->display->display_options['fields']['field_jumbo_image']['field'] = 'field_jumbo_image';
  /* Field: Content: Jumbotron Subtitle */
  $handler->display->display_options['fields']['field_feature_subtitle']['id'] = 'field_feature_subtitle';
  $handler->display->display_options['fields']['field_feature_subtitle']['table'] = 'field_data_field_feature_subtitle';
  $handler->display->display_options['fields']['field_feature_subtitle']['field'] = 'field_feature_subtitle';
  /* Field: Content: Jumbotron Title */
  $handler->display->display_options['fields']['field_feature_title']['id'] = 'field_feature_title';
  $handler->display->display_options['fields']['field_feature_title']['table'] = 'field_data_field_feature_title';
  $handler->display->display_options['fields']['field_feature_title']['field'] = 'field_feature_title';
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_stub_link']['id'] = 'field_stub_link';
  $handler->display->display_options['fields']['field_stub_link']['table'] = 'field_data_field_stub_link';
  $handler->display->display_options['fields']['field_stub_link']['field'] = 'field_stub_link';
  $handler->display->display_options['fields']['field_stub_link']['label'] = '';
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
  $handler->display->display_options['fields']['field_stub_link']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_stub_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stub_link']['empty'] = 'NONE';
  $handler->display->display_options['fields']['field_stub_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stub_link']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stub_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_stub_link']['field_api_classes'] = 0;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
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
  $handler->display->display_options['path'] = 'jumbotron.json';

  /* Display: Jumbtron Block */
  $handler = $view->new_display('block', 'Jumbtron Block', 'block_1');
  $handler->display->display_options['display_description'] = 'Jimbotron Block';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'jumbotron';
  $handler->display->display_options['style_options']['top_child_object'] = 'item';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['jumbotron'] = $view;

  $view = new view;
  $view->name = 'partner_links';
  $view->description = '';
  $view->tag = 'default';
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
    'image_style' => 'square_thumbnail',
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
  $view->tag = 'default';
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

  return $export;
}
