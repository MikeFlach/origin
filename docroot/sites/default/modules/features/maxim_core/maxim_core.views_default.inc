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
  $view->name = 'channel_content';
  $view->description = 'Content to propagate channel pages';
  $view->tag = 'Maxim';
  $view->base_table = 'node';
  $view->human_name = 'Channel content';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
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
  /* Contextual filter: Content: Channel (field_channel) */
  $handler->display->display_options['arguments']['field_channel_tid']['id'] = 'field_channel_tid';
  $handler->display->display_options['arguments']['field_channel_tid']['table'] = 'field_data_field_channel';
  $handler->display->display_options['arguments']['field_channel_tid']['field'] = 'field_channel_tid';
  $handler->display->display_options['arguments']['field_channel_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_channel_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_channel_tid']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['field_channel_tid']['default_argument_options']['node'] = 0;
  $handler->display->display_options['arguments']['field_channel_tid']['default_argument_options']['limit'] = 0;
  $handler->display->display_options['arguments']['field_channel_tid']['default_argument_options']['vocabularies'] = array(
    'tags' => 0,
    'channels' => 0,
    'columns' => 0,
  );
  $handler->display->display_options['arguments']['field_channel_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_channel_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_channel_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_channel_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_channel_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_channel_tid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Channel content block */
  $handler = $view->new_display('block', 'Channel content block', 'block');
  $handler->display->display_options['display_description'] = 'The block that propagates the channel view into the panel';

  /* Display: Sub-channel content block */
  $handler = $view->new_display('block', 'Sub-channel content block', 'block_1');
  $handler->display->display_options['display_description'] = 'Content block for sub channel content';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $export['channel_content'] = $view;

  $view = new view;
  $view->name = 'home_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Home page';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
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
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'poll' => 'poll',
  );

  /* Display: Home page content block */
  $handler = $view->new_display('block', 'Home page content block', 'block');
  $export['home_page'] = $view;

  $view = new view;
  $view->name = 'partner_links';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Partner Links';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
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
  $view->api_version = '3.0-alpha1';
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
