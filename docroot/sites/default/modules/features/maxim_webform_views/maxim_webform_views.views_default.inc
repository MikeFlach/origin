<?php
/**
 * @file
 * maxim_webform_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function maxim_webform_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hometown_hotties_full_gmap';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Hometown Hotties Full GMap';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Hometown Hotties 2013 Map';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'gmap';
  $handler->display->display_options['style_options']['macro'] = '[gmap zoom=4 |center=33.578014746143985,-95.185546875 |width=940px |height=600px |control=Small |type=Map]';
  $handler->display->display_options['style_options']['markertype'] = 'small bpink';
  $handler->display->display_options['style_options']['latfield'] = 'title';
  $handler->display->display_options['style_options']['lonfield'] = 'title';
  $handler->display->display_options['style_options']['markerfield'] = 'title';
  $handler->display->display_options['style_options']['enablermt'] = 0;
  $handler->display->display_options['style_options']['rmtfield'] = 'title';
  $handler->display->display_options['style_options']['tooltipenabled'] = 1;
  $handler->display->display_options['style_options']['tooltipfield'] = 'title';
  $handler->display->display_options['style_options']['bubbletextenabled'] = 1;
  $handler->display->display_options['style_options']['bubbletextfield'] = 'title';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'hometown_hotties_2013:hth_2013_finals';
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_medium',
    'image_link' => '',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View Her Profile';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]<br/>[field_main_image]<br/>[view_node]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Location: Distance / Proximity */
  $handler->display->display_options['sorts']['distance']['id'] = 'distance';
  $handler->display->display_options['sorts']['distance']['table'] = 'location';
  $handler->display->display_options['sorts']['distance']['field'] = 'distance';
  $handler->display->display_options['sorts']['distance']['origin'] = 'postal_default';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hotties_profile' => 'hotties_profile',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    0 => '16231',
  );
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'hotties_contest_year';
  /* Filter criterion: Content: Contest Week (field_hotties_contest_week) */
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['id'] = 'field_hotties_contest_week_tid';
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['table'] = 'field_data_field_hotties_contest_week';
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['field'] = 'field_hotties_contest_week_tid';
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['value'] = array(
    14092 => '14092',
    14107 => '14107',
    14108 => '14108',
    14109 => '14109',
    14110 => '14110',
    14111 => '14111',
    14112 => '14112',
    14113 => '14113',
    14114 => '14114',
    14115 => '14115',
    14116 => '14116',
    14117 => '14117',
  );
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['expose']['operator_id'] = 'field_hotties_contest_week_tid_op';
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['expose']['label'] = 'Contest Week';
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['expose']['operator'] = 'field_hotties_contest_week_tid_op';
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['expose']['identifier'] = 'field_hotties_contest_week_tid';
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    9 => 0,
    7 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['vocabulary'] = 'hotties_contest_week';
  /* Filter criterion: Location: Distance / Proximity */
  $handler->display->display_options['filters']['distance']['id'] = 'distance';
  $handler->display->display_options['filters']['distance']['table'] = 'location';
  $handler->display->display_options['filters']['distance']['field'] = 'distance';
  $handler->display->display_options['filters']['distance']['operator'] = 'dist';
  $handler->display->display_options['filters']['distance']['value'] = array(
    'latitude' => '',
    'longitude' => '',
    'postal_code' => '',
    'country' => '',
    'php_code' => '',
    'nid_arg' => '',
    'nid_loc_field' => 'node',
    'uid_arg' => '',
    'search_distance' => '25',
    'search_units' => 'mile',
  );
  $handler->display->display_options['filters']['distance']['group'] = 1;
  $handler->display->display_options['filters']['distance']['exposed'] = TRUE;
  $handler->display->display_options['filters']['distance']['expose']['operator_id'] = 'distance_op';
  $handler->display->display_options['filters']['distance']['expose']['label'] = 'Distance / Proximity';
  $handler->display->display_options['filters']['distance']['expose']['operator'] = 'distance_op';
  $handler->display->display_options['filters']['distance']['expose']['identifier'] = 'distance';
  $handler->display->display_options['filters']['distance']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    9 => 0,
    7 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['distance']['expose']['gmap_macro'] = array(
    'default' => '[gmap ]',
  );
  $handler->display->display_options['filters']['distance']['expose']['user_location_choose'] = array(
    'default' => FALSE,
  );
  $handler->display->display_options['filters']['distance']['origin'] = 'postal_default';
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_1']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_1']['operator'] = 'not';
  $handler->display->display_options['filters']['tid_1']['value'] = array(
    0 => '17806',
  );
  $handler->display->display_options['filters']['tid_1']['vocabulary'] = 'hotties_contest_week';

  /* Display: 2013 Map */
  $handler = $view->new_display('page', '2013 Map', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'hometown-hotties/2013/hth-map';

  /* Display: 2014 Map */
  $handler = $view->new_display('page', '2014 Map', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'hometown-hotties/2014/hth-map';
  $export['hometown_hotties_full_gmap'] = $view;

  $view = new view();
  $view->name = 'hth_2014_admin_view';
  $view->description = 'Default view for data table Hth 2014 admin view';
  $view->tag = 'data table';
  $view->base_table = 'hth_2014_admin_view';
  $view->human_name = 'Hotties Admin';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Default */
  $handler = $view->new_display('default', 'Default', 'default');
  $handler->display->display_options['title'] = 'Hometown Hotties 2014 Entries';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Hth 2014 admin view: Sid */
  $handler->display->display_options['fields']['sid']['id'] = 'sid';
  $handler->display->display_options['fields']['sid']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['sid']['field'] = 'sid';
  $handler->display->display_options['fields']['sid']['label'] = 'sid';
  $handler->display->display_options['fields']['sid']['separator'] = '';
  /* Field: Hth 2014 admin view: First name */
  $handler->display->display_options['fields']['first_name']['id'] = 'first_name';
  $handler->display->display_options['fields']['first_name']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['first_name']['field'] = 'first_name';
  $handler->display->display_options['fields']['first_name']['label'] = 'first_name';
  /* Field: Hth 2014 admin view: Last name */
  $handler->display->display_options['fields']['last_name']['id'] = 'last_name';
  $handler->display->display_options['fields']['last_name']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['last_name']['field'] = 'last_name';
  $handler->display->display_options['fields']['last_name']['label'] = 'last_name';
  /* Field: Hth 2014 admin view: Date of birth */
  $handler->display->display_options['fields']['date_of_birth']['id'] = 'date_of_birth';
  $handler->display->display_options['fields']['date_of_birth']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['date_of_birth']['field'] = 'date_of_birth';
  $handler->display->display_options['fields']['date_of_birth']['label'] = 'date_of_birth';
  /* Field: Hth 2014 admin view: Email address */
  $handler->display->display_options['fields']['email_address']['id'] = 'email_address';
  $handler->display->display_options['fields']['email_address']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['email_address']['field'] = 'email_address';
  $handler->display->display_options['fields']['email_address']['label'] = 'email_address';
  /* Field: Hth 2014 admin view: Photo 1 */
  $handler->display->display_options['fields']['photo_1']['id'] = 'photo_1';
  $handler->display->display_options['fields']['photo_1']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['photo_1']['field'] = 'photo_1';
  $handler->display->display_options['fields']['photo_1']['label'] = 'photo_1';
  /* Field: Hth 2014 admin view: Photo 2 */
  $handler->display->display_options['fields']['photo_2']['id'] = 'photo_2';
  $handler->display->display_options['fields']['photo_2']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['photo_2']['field'] = 'photo_2';
  $handler->display->display_options['fields']['photo_2']['label'] = 'photo_2';
  /* Field: Hth 2014 admin view: Photo 3 */
  $handler->display->display_options['fields']['photo_3']['id'] = 'photo_3';
  $handler->display->display_options['fields']['photo_3']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['photo_3']['field'] = 'photo_3';
  $handler->display->display_options['fields']['photo_3']['label'] = 'photo_3';
  /* Field: Hth 2014 admin view: Photo 4 */
  $handler->display->display_options['fields']['photo_4']['id'] = 'photo_4';
  $handler->display->display_options['fields']['photo_4']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['photo_4']['field'] = 'photo_4';
  $handler->display->display_options['fields']['photo_4']['label'] = 'photo_4';
  $handler->display->display_options['fields']['photo_4']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['photo_4']['hide_alter_empty'] = FALSE;
  /* Field: Hth 2014 admin view: Photo 5 */
  $handler->display->display_options['fields']['photo_5']['id'] = 'photo_5';
  $handler->display->display_options['fields']['photo_5']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['photo_5']['field'] = 'photo_5';
  $handler->display->display_options['fields']['photo_5']['label'] = 'photo_5';
  $handler->display->display_options['fields']['photo_5']['hide_empty'] = TRUE;
  /* Field: Hth 2014 admin view: Photo 6 */
  $handler->display->display_options['fields']['photo_6']['id'] = 'photo_6';
  $handler->display->display_options['fields']['photo_6']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['photo_6']['field'] = 'photo_6';
  $handler->display->display_options['fields']['photo_6']['label'] = 'photo_6';
  $handler->display->display_options['fields']['photo_6']['hide_empty'] = TRUE;
  /* Field: Hth 2014 admin view: Photo 7 */
  $handler->display->display_options['fields']['photo_7']['id'] = 'photo_7';
  $handler->display->display_options['fields']['photo_7']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['photo_7']['field'] = 'photo_7';
  $handler->display->display_options['fields']['photo_7']['label'] = 'photo_7';
  $handler->display->display_options['fields']['photo_7']['hide_empty'] = TRUE;
  /* Field: Hth 2014 admin view: Photo 8 */
  $handler->display->display_options['fields']['photo_8']['id'] = 'photo_8';
  $handler->display->display_options['fields']['photo_8']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['photo_8']['field'] = 'photo_8';
  $handler->display->display_options['fields']['photo_8']['label'] = 'photo_8';
  $handler->display->display_options['fields']['photo_8']['hide_empty'] = TRUE;
  /* Field: Hth 2014 admin view: Photo 9 */
  $handler->display->display_options['fields']['photo_9']['id'] = 'photo_9';
  $handler->display->display_options['fields']['photo_9']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['photo_9']['field'] = 'photo_9';
  $handler->display->display_options['fields']['photo_9']['label'] = 'photo_9';
  $handler->display->display_options['fields']['photo_9']['hide_empty'] = TRUE;
  /* Field: Hth 2014 admin view: Photo 10 */
  $handler->display->display_options['fields']['photo_10']['id'] = 'photo_10';
  $handler->display->display_options['fields']['photo_10']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['photo_10']['field'] = 'photo_10';
  $handler->display->display_options['fields']['photo_10']['label'] = 'photo_10';
  $handler->display->display_options['fields']['photo_10']['hide_empty'] = TRUE;
  /* Field: Hth 2014 admin view: Entry slotting */
  $handler->display->display_options['fields']['entry_slotting']['id'] = 'entry_slotting';
  $handler->display->display_options['fields']['entry_slotting']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['entry_slotting']['field'] = 'entry_slotting';
  $handler->display->display_options['fields']['entry_slotting']['label'] = 'entry_slotting';
  /* Field: Hth 2014 admin view: Contest week */
  $handler->display->display_options['fields']['contest_week']['id'] = 'contest_week';
  $handler->display->display_options['fields']['contest_week']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['contest_week']['field'] = 'contest_week';
  $handler->display->display_options['fields']['contest_week']['label'] = 'contest_week';
  /* Field: Hth 2014 admin view: Submitted */
  $handler->display->display_options['fields']['submitted']['id'] = 'submitted';
  $handler->display->display_options['fields']['submitted']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['submitted']['field'] = 'submitted';
  $handler->display->display_options['fields']['submitted']['label'] = 'submitted';
  /* Field: Hth 2014 admin view: Remote addr */
  $handler->display->display_options['fields']['remote_addr']['id'] = 'remote_addr';
  $handler->display->display_options['fields']['remote_addr']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['fields']['remote_addr']['field'] = 'remote_addr';
  $handler->display->display_options['fields']['remote_addr']['label'] = 'remote_addr';
  /* Sort criterion: Hth 2014 admin view: Email address */
  $handler->display->display_options['sorts']['email_address']['id'] = 'email_address';
  $handler->display->display_options['sorts']['email_address']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['sorts']['email_address']['field'] = 'email_address';
  /* Sort criterion: Hth 2014 admin view: Submitted */
  $handler->display->display_options['sorts']['submitted']['id'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['sorts']['submitted']['field'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['order'] = 'DESC';
  /* Contextual filter: Hth 2014 admin view: Sid */
  $handler->display->display_options['arguments']['sid']['id'] = 'sid';
  $handler->display->display_options['arguments']['sid']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['arguments']['sid']['field'] = 'sid';
  $handler->display->display_options['arguments']['sid']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['sid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['sid']['title'] = 'Hth 2014 admin view %1';
  $handler->display->display_options['arguments']['sid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['sid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Hth 2014 admin view: Entry slotting */
  $handler->display->display_options['filters']['entry_slotting']['id'] = 'entry_slotting';
  $handler->display->display_options['filters']['entry_slotting']['table'] = 'hth_2014_admin_view';
  $handler->display->display_options['filters']['entry_slotting']['field'] = 'entry_slotting';
  $handler->display->display_options['filters']['entry_slotting']['exposed'] = TRUE;
  $handler->display->display_options['filters']['entry_slotting']['expose']['operator_id'] = 'entry_slotting_op';
  $handler->display->display_options['filters']['entry_slotting']['expose']['label'] = 'Entry slotting';
  $handler->display->display_options['filters']['entry_slotting']['expose']['operator'] = 'entry_slotting_op';
  $handler->display->display_options['filters']['entry_slotting']['expose']['identifier'] = 'entry_slotting';
  $handler->display->display_options['filters']['entry_slotting']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['entry_slotting']['group_info']['label'] = 'Filter By';
  $handler->display->display_options['filters']['entry_slotting']['group_info']['identifier'] = 'entry_slotting';
  $handler->display->display_options['filters']['entry_slotting']['group_info']['default_group'] = '1';
  $handler->display->display_options['filters']['entry_slotting']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Unslotted',
      'operator' => 'empty',
      'value' => 'nonw',
    ),
    2 => array(
      'title' => 'Yes',
      'operator' => '=',
      'value' => 'yes',
    ),
    3 => array(
      'title' => 'No',
      'operator' => '=',
      'value' => 'no',
    ),
    4 => array(
      'title' => 'Maybe',
      'operator' => '=',
      'value' => 'maybe',
    ),
  );

  /* Display: HTH 2014 Admin */
  $handler = $view->new_display('page', 'HTH 2014 Admin', 'hotties_2014_admin');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '5, 10, 15, 20, 25,30,35,40,45,50';
  $handler->display->display_options['path'] = 'hotties-admin/2014';
  $handler->display->display_options['menu']['title'] = 'Hth 2014 admin view';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $export['hth_2014_admin_view'] = $view;

  return $export;
}
