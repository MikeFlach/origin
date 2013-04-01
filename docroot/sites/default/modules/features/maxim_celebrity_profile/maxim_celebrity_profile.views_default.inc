<?php
/**
 * @file
 * maxim_celebrity_profile.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function maxim_celebrity_profile_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hot_100';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Hot 100';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Hot 100 - 2013';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'infinite_scroll';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '1';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'hot100-entry';
  $handler->display->display_options['style_options']['wrapper_class'] = 'hot100-list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header/social/text';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<img src= "http://cdn2.maxim.com/maxim/sites/default/files/header_hot100_2013_voting.jpg" class="hot100-2013-header-img" /><div class="social-links"><a href="https://twitter.com/share" class="twitter-share-button" data-via="MaximMag">Tweet</a><div class=\'g-plusone\' data-size=\'medium\'></div><div class="fb-like" data-send="true" data-layout="button_count" data-width="450" data-show-faces="false"></div></div><p id="hot100-2013-header-text">There are thousands of beautiful women in the world, and we need your help to whittle down the list to just the best of the best.  Look through the gallery below and vote for the ladies you think should be immortalized in the 2013 Hot 100!</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Entity: Rendered entity */
  $handler->display->display_options['header']['entity']['id'] = 'entity';
  $handler->display->display_options['header']['entity']['table'] = 'entity__global';
  $handler->display->display_options['header']['entity']['field'] = 'entity';
  $handler->display->display_options['header']['entity']['empty'] = TRUE;
  $handler->display->display_options['header']['entity']['entity_id'] = '62411';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['label'] = 'write in status message placeholder';
  $handler->display->display_options['header']['area_1']['content'] = '<div id="write-in-status">&nbsp;</div>';
  $handler->display->display_options['header']['area_1']['format'] = 'filtered_html';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'hot_100_2013' => 'hot_100_2013',
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
    'athlete_bodyfort_nq' => 0,
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['empty'] = ' ';
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_medium',
    'image_link' => 'content',
  );
  /* Field: Content: Hot 100 Display Name */
  $handler->display->display_options['fields']['field_hot_100_display_name']['id'] = 'field_hot_100_display_name';
  $handler->display->display_options['fields']['field_hot_100_display_name']['table'] = 'field_data_field_hot_100_display_name';
  $handler->display->display_options['fields']['field_hot_100_display_name']['field'] = 'field_hot_100_display_name';
  $handler->display->display_options['fields']['field_hot_100_display_name']['label'] = '';
  $handler->display->display_options['fields']['field_hot_100_display_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_hot_100_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_hot_100_display_name']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_hot_100_display_name']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<div class="multi-vote"><div id="vb-[nid]" class="btn">Vote For Me</div><div class="msg" id="vmsg-[nid]"></div></div>';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'celebrity_profile' => 'celebrity_profile',
  );
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';

  /* Display: Hot 100 - 2013 */
  $handler = $view->new_display('page', 'Hot 100 - 2013', 'hot100_2013');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header/social/text';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<img src= "http://cdn2.maxim.com/maxim/sites/default/files/header_hot100_2013_voting.jpg" class="hot100-2013-header-img" /><div class="social-links"><a href="https://twitter.com/share" class="twitter-share-button" data-via="MaximMag">Tweet</a><div class=\'g-plusone\' data-size=\'medium\'></div><div class="fb-like" data-send="true" data-layout="button_count" data-width="450" data-show-faces="false"></div></div><p id="hot100-2013-header-text">There are thousands of beautiful women in the world, and we need your help to whittle down the list to just the best of the best.  Look through the gallery below and vote for the ladies you think should be immortalized in the 2013 Hot 100!</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Entity: Rendered entity */
  $handler->display->display_options['header']['entity']['id'] = 'entity';
  $handler->display->display_options['header']['entity']['table'] = 'entity__global';
  $handler->display->display_options['header']['entity']['field'] = 'entity';
  $handler->display->display_options['header']['entity']['empty'] = TRUE;
  $handler->display->display_options['header']['entity']['entity_id'] = '62411';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['label'] = 'write in status message placeholder';
  $handler->display->display_options['header']['area_1']['content'] = '<div id="write-in-status">&nbsp;</div>';
  $handler->display->display_options['header']['area_1']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['empty'] = ' ';
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_medium',
    'image_link' => 'content',
  );
  /* Field: Content: Hot 100 Display Name */
  $handler->display->display_options['fields']['field_hot_100_display_name']['id'] = 'field_hot_100_display_name';
  $handler->display->display_options['fields']['field_hot_100_display_name']['table'] = 'field_data_field_hot_100_display_name';
  $handler->display->display_options['fields']['field_hot_100_display_name']['field'] = 'field_hot_100_display_name';
  $handler->display->display_options['fields']['field_hot_100_display_name']['label'] = '';
  $handler->display->display_options['fields']['field_hot_100_display_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_hot_100_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_hot_100_display_name']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_hot_100_display_name']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<div class="multi-vote"><div id="vb-[nid]" class="btn">Vote For Me</div><div class="msg" id="vmsg-[nid]"></div></div>';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['path'] = 'hot100/2013/vote';

  /* Display: Hot 100 2013 - Results */
  $handler = $view->new_display('page', 'Hot 100 2013 - Results', 'hot100_2013_results');
  $handler->display->display_options['display_description'] = 'Results for hot100 2013';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    4 => '4',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'infinite_scroll';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '1';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Hot100 2013 Vote Count';
  $handler->display->display_options['relationships']['votingapi_cache']['required'] = TRUE;
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'hot100-2013',
    'function' => 'count',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['empty'] = ' ';
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_medium',
    'image_link' => 'content',
  );
  /* Field: Content: Hot 100 Display Name */
  $handler->display->display_options['fields']['field_hot_100_display_name']['id'] = 'field_hot_100_display_name';
  $handler->display->display_options['fields']['field_hot_100_display_name']['table'] = 'field_data_field_hot_100_display_name';
  $handler->display->display_options['fields']['field_hot_100_display_name']['field'] = 'field_hot_100_display_name';
  $handler->display->display_options['fields']['field_hot_100_display_name']['label'] = '';
  $handler->display->display_options['fields']['field_hot_100_display_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_hot_100_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_hot_100_display_name']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_hot_100_display_name']['element_label_colon'] = FALSE;
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = '';
  $handler->display->display_options['fields']['value']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['value']['alter']['text'] = 'Votes: [value]';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['element_wrapper_class'] = 'vote-count';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['value']['coalesce'] = 0;
  $handler->display->display_options['path'] = 'hot100/2013/results';

  /* Display: Hot 100 2013 - Reveal Admin */
  $handler = $view->new_display('page', 'Hot 100 2013 - Reveal Admin', 'reveal_admin');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Hot 100 - 2013 - Reveal Admin';
  $handler->display->display_options['display_description'] = 'Reveal Page Admin for Hot 100 2013';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    4 => '4',
    9 => '9',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'infinite_scroll';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '1';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'hot100-entry';
  $handler->display->display_options['style_options']['wrapper_class'] = 'hot100-list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header/social/text';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<img src= "http://cdn2.maxim.com/maxim/sites/default/files/header_hot100_2013_voting.jpg" class="hot100-2013-header-img" style="margin-top:10px" />';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'hot_100_2013' => 'hot_100_2013',
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
    'athlete_bodyfort_nq' => 0,
  );
  /* Relationship: Flags: hot100_reveal */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'hot100_reveal';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['empty'] = ' ';
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_medium',
    'image_link' => 'content',
  );
  /* Field: Content: Hot 100 Display Name */
  $handler->display->display_options['fields']['field_hot_100_display_name']['id'] = 'field_hot_100_display_name';
  $handler->display->display_options['fields']['field_hot_100_display_name']['table'] = 'field_data_field_hot_100_display_name';
  $handler->display->display_options['fields']['field_hot_100_display_name']['field'] = 'field_hot_100_display_name';
  $handler->display->display_options['fields']['field_hot_100_display_name']['label'] = '';
  $handler->display->display_options['fields']['field_hot_100_display_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_hot_100_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_hot_100_display_name']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_hot_100_display_name']['element_label_colon'] = FALSE;
  /* Field: Nodequeue: Position */
  $handler->display->display_options['fields']['position']['id'] = 'position';
  $handler->display->display_options['fields']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['fields']['position']['field'] = 'position';
  $handler->display->display_options['fields']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['fields']['position']['separator'] = '';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['link_type'] = 'toggle';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['sorts']['position']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['path'] = 'hot100/2013/reveal-admin';

  /* Display: Hot 100 2013 - Reveal */
  $handler = $view->new_display('page', 'Hot 100 2013 - Reveal', 'hot100_reveal');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Hot 100 2013 - Reveal';
  $handler->display->display_options['display_description'] = 'Reveal Page Admin for Hot 100 2013';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    7 => '7',
    5 => '5',
    4 => '4',
    9 => '9',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'infinite_scroll';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '1';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'hot100-entry';
  $handler->display->display_options['style_options']['wrapper_class'] = 'hot100-list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header/social/text';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<img src= "http://cdn2.maxim.com/maxim/sites/default/files/header_hot100_2013_voting.jpg" class="hot100-2013-header-img" /><div class="social-links"><a href="https://twitter.com/share" class="twitter-share-button" data-via="MaximMag">Tweet</a><div class=\'g-plusone\' data-size=\'medium\'></div><div class="fb-like" data-send="true" data-layout="button_count" data-width="450" data-show-faces="false"></div></div><p id="hot100-2013-header-text">There are thousands of beautiful women in the world, and we need your help to whittle down the list to just the best of the best.  Look through the gallery below and vote for the ladies you think should be immortalized in the 2013 Hot 100!</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'hot_100_2013' => 'hot_100_2013',
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
    'athlete_bodyfort_nq' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['empty'] = ' ';
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_medium',
    'image_link' => 'content',
  );
  /* Field: Content: Hot 100 Display Name */
  $handler->display->display_options['fields']['field_hot_100_display_name']['id'] = 'field_hot_100_display_name';
  $handler->display->display_options['fields']['field_hot_100_display_name']['table'] = 'field_data_field_hot_100_display_name';
  $handler->display->display_options['fields']['field_hot_100_display_name']['field'] = 'field_hot_100_display_name';
  $handler->display->display_options['fields']['field_hot_100_display_name']['label'] = '';
  $handler->display->display_options['fields']['field_hot_100_display_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_hot_100_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_hot_100_display_name']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_hot_100_display_name']['element_label_colon'] = FALSE;
  /* Field: Nodequeue: Position */
  $handler->display->display_options['fields']['position']['id'] = 'position';
  $handler->display->display_options['fields']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['fields']['position']['field'] = 'position';
  $handler->display->display_options['fields']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['fields']['position']['label'] = '# ';
  $handler->display->display_options['fields']['position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['position']['separator'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['sorts']['position']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['path'] = 'hot100/2013/reveal';
  $export['hot_100'] = $view;

  return $export;
}
