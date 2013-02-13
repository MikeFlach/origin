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
  $view->name = 'hometown_hotties_2013';
  $view->description = 'Weekly display of HTH entrants';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'Hometown Hotties 2013';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Hometown Hotties 2013';
  $handler->display->display_options['css_class'] = 'hth_wrapper';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'infinite_scroll';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'hth_entry';
  $handler->display->display_options['style_options']['wrapper_class'] = 'gallery-list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>The first round of voting is closed! While we tally votes to determine the Semifinalists, get reacquainted with all 1,000 Hotties by browsing their photo galleries. Take your time. We’ll wait.</p>
<div class="hth-sponsor"><iframe src="http://ad.doubleclick.net/adi/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?" width="145" height="40" marginwidth="0" marginheight="0" frameborder="0" scrolling="no">
<script type="text/javascript" src="http://ad.doubleclick.net/adj/maxim.dart/;adid=257123122;sz=145x40;abr=!ie;ord=[timestamp]?"></script>
</iframe>
<noscript><a href="http://ad.doubleclick.net/jump/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?"><img src="http://ad.doubleclick.net/ad/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?" border="0" alt="" /></a></noscript></div>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'hth_2013_contestants_week_1' => 'hth_2013_contestants_week_1',
  );
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_medium',
    'image_link' => 'content',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_profile_first_name']['id'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['table'] = 'field_data_field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['field'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_first_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profile_first_name']['alter']['text'] = '<a href="[path]">[field_profile_first_name]</a>';
  $handler->display->display_options['fields']['field_profile_first_name']['element_class'] = 'hth_name';
  $handler->display->display_options['fields']['field_profile_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_first_name']['type'] = 'text_plain';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_profile_city']['id'] = 'field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['table'] = 'field_data_field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['field'] = 'field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['label'] = '';
  $handler->display->display_options['fields']['field_profile_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_city']['type'] = 'text_plain';
  /* Field: Content: State/Province */
  $handler->display->display_options['fields']['field_profile_state']['id'] = 'field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['table'] = 'field_data_field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['field'] = 'field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['label'] = '';
  $handler->display->display_options['fields']['field_profile_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_state']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[path]">[field_profile_city], [field_profile_state]</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
  /* Filter criterion: Content: State/Province (field_profile_state) */
  $handler->display->display_options['filters']['field_profile_state_tid']['id'] = 'field_profile_state_tid';
  $handler->display->display_options['filters']['field_profile_state_tid']['table'] = 'field_data_field_profile_state';
  $handler->display->display_options['filters']['field_profile_state_tid']['field'] = 'field_profile_state_tid';
  $handler->display->display_options['filters']['field_profile_state_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profile_state_tid']['expose']['operator_id'] = 'field_profile_state_tid_op';
  $handler->display->display_options['filters']['field_profile_state_tid']['expose']['label'] = 'Search by State:';
  $handler->display->display_options['filters']['field_profile_state_tid']['expose']['operator'] = 'field_profile_state_tid_op';
  $handler->display->display_options['filters']['field_profile_state_tid']['expose']['identifier'] = 'field_profile_state_tid';
  $handler->display->display_options['filters']['field_profile_state_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_profile_state_tid']['vocabulary'] = 'states_provinces';

  /* Display: HTH - Week 1 */
  $handler = $view->new_display('page', 'HTH - Week 1', 'hth_2013_w1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'hth_wrapper';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'hth_entry';
  $handler->display->display_options['style_options']['wrapper_class'] = 'gallery-list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<!--<p>Semifinals has officially begun and we\'re proud to present your top 100. Each Hottie profile has a video so get clicking and vote early and often (one vote per-girl per-day to be exact)</p>
-->
<div class="hth-sponsor"><iframe src="http://ad.doubleclick.net/adi/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?" width="145" height="40" marginwidth="0" marginheight="0" frameborder="0" scrolling="no">
<script type="text/javascript" src="http://ad.doubleclick.net/adj/maxim.dart/;adid=257123122;sz=145x40;abr=!ie;ord=[timestamp]?"></script>
</iframe>
<noscript><a href="http://ad.doubleclick.net/jump/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?"><img src="http://ad.doubleclick.net/ad/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?" border="0" alt="" /></a></noscript></div>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
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
    'hth_2013_contestants_week_semi_f' => 0,
    'hth_2013_contestants_finals' => 0,
  );
  $handler->display->display_options['path'] = 'hometown-hotties/2013/week1';

  /* Display: HTH - Week 2 */
  $handler = $view->new_display('page', 'HTH - Week 2', 'hth_2013_w2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="hth-sponsor"><iframe src="http://ad.doubleclick.net/adi/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?" width="145" height="40" marginwidth="0" marginheight="0" frameborder="0" scrolling="no">
<script type="text/javascript" src="http://ad.doubleclick.net/adj/maxim.dart/;adid=257123122;sz=145x40;abr=!ie;ord=[timestamp]?"></script>
</iframe>
<noscript><a href="http://ad.doubleclick.net/jump/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?"><img src="http://ad.doubleclick.net/ad/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?" border="0" alt="" /></a></noscript></div>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'hth_2013_contestants_week_2' => 'hth_2013_contestants_week_2',
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
    'hth_2013_contestants_week_3' => 0,
    'hth_2013_contestants_week_4' => 0,
    'hth_2013_contestants_week_5' => 0,
    'hot100_2012' => 0,
  );
  $handler->display->display_options['path'] = 'hometown-hotties/2013/week2';

  /* Display: HTH - Week 3 */
  $handler = $view->new_display('page', 'HTH - Week 3', 'hth_2013_w3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="hth-sponsor"><iframe src="http://ad.doubleclick.net/adi/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?" width="145" height="40" marginwidth="0" marginheight="0" frameborder="0" scrolling="no">
<script type="text/javascript" src="http://ad.doubleclick.net/adj/maxim.dart/;adid=257123122;sz=145x40;abr=!ie;ord=[timestamp]?"></script>
</iframe>
<noscript><a href="http://ad.doubleclick.net/jump/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?"><img src="http://ad.doubleclick.net/ad/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?" border="0" alt="" /></a></noscript></div>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'hth_2013_contestants_week_3' => 'hth_2013_contestants_week_3',
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
    'hth_2013_contestants_week_4' => 0,
    'hth_2013_contestants_week_5' => 0,
    'hot100_2012' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_medium',
    'image_link' => 'content',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_profile_first_name']['id'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['table'] = 'field_data_field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['field'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_first_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profile_first_name']['alter']['text'] = '<a href="[path]">[field_profile_first_name]</a>';
  $handler->display->display_options['fields']['field_profile_first_name']['element_class'] = 'hth_name';
  $handler->display->display_options['fields']['field_profile_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_first_name']['type'] = 'text_plain';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_profile_city']['id'] = 'field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['table'] = 'field_data_field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['field'] = 'field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['label'] = '';
  $handler->display->display_options['fields']['field_profile_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_city']['type'] = 'text_plain';
  /* Field: Content: State/Province */
  $handler->display->display_options['fields']['field_profile_state']['id'] = 'field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['table'] = 'field_data_field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['field'] = 'field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['label'] = '';
  $handler->display->display_options['fields']['field_profile_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_state']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[path]">[field_profile_city], [field_profile_state]</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'hometown-hotties/2013/week3';

  /* Display: HTH - Week 4 */
  $handler = $view->new_display('page', 'HTH - Week 4', 'hth_2013_w4');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="hth-sponsor"><iframe src="http://ad.doubleclick.net/adi/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?" width="145" height="40" marginwidth="0" marginheight="0" frameborder="0" scrolling="no">
<script type="text/javascript" src="http://ad.doubleclick.net/adj/maxim.dart/;adid=257123122;sz=145x40;abr=!ie;ord=[timestamp]?"></script>
</iframe>
<noscript><a href="http://ad.doubleclick.net/jump/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?"><img src="http://ad.doubleclick.net/ad/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?" border="0" alt="" /></a></noscript></div>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'hth_2013_contestants_week_4' => 'hth_2013_contestants_week_4',
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
    'hth_2013_contestants_week_5' => 0,
    'hot100_2012' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_medium',
    'image_link' => 'content',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_profile_first_name']['id'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['table'] = 'field_data_field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['field'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_first_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profile_first_name']['alter']['text'] = '<a href="[path]">[field_profile_first_name]</a>';
  $handler->display->display_options['fields']['field_profile_first_name']['element_class'] = 'hth_name';
  $handler->display->display_options['fields']['field_profile_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_first_name']['type'] = 'text_plain';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_profile_city']['id'] = 'field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['table'] = 'field_data_field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['field'] = 'field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['label'] = '';
  $handler->display->display_options['fields']['field_profile_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_city']['type'] = 'text_plain';
  /* Field: Content: State/Province */
  $handler->display->display_options['fields']['field_profile_state']['id'] = 'field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['table'] = 'field_data_field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['field'] = 'field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['label'] = '';
  $handler->display->display_options['fields']['field_profile_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_state']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[path]">[field_profile_city], [field_profile_state]</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'hometown-hotties/2013/week4';

  /* Display: HTH - Week 5 */
  $handler = $view->new_display('page', 'HTH - Week 5', 'hth_2013_w5');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="hth-sponsor"><iframe src="http://ad.doubleclick.net/adi/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?" width="145" height="40" marginwidth="0" marginheight="0" frameborder="0" scrolling="no">
<script type="text/javascript" src="http://ad.doubleclick.net/adj/maxim.dart/;adid=257123122;sz=145x40;abr=!ie;ord=[timestamp]?"></script>
</iframe>
<noscript><a href="http://ad.doubleclick.net/jump/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?"><img src="http://ad.doubleclick.net/ad/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?" border="0" alt="" /></a></noscript></div>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'hth_2013_contestants_week_5' => 'hth_2013_contestants_week_5',
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
    'hot100_2012' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_medium',
    'image_link' => 'content',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_profile_first_name']['id'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['table'] = 'field_data_field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['field'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_first_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profile_first_name']['alter']['text'] = '<a href="[path]">[field_profile_first_name]</a>';
  $handler->display->display_options['fields']['field_profile_first_name']['element_class'] = 'hth_name';
  $handler->display->display_options['fields']['field_profile_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_first_name']['type'] = 'text_plain';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_profile_city']['id'] = 'field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['table'] = 'field_data_field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['field'] = 'field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['label'] = '';
  $handler->display->display_options['fields']['field_profile_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_city']['type'] = 'text_plain';
  /* Field: Content: State/Province */
  $handler->display->display_options['fields']['field_profile_state']['id'] = 'field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['table'] = 'field_data_field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['field'] = 'field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['label'] = '';
  $handler->display->display_options['fields']['field_profile_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_state']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[path]">[field_profile_city], [field_profile_state]</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'hometown-hotties/2013/week5';

  /* Display: HTH - Semi Finals */
  $handler = $view->new_display('page', 'HTH - Semi Finals', 'hth_2013_semi');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="hth-sponsor"><iframe src="http://ad.doubleclick.net/adi/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?" width="145" height="40" marginwidth="0" marginheight="0" frameborder="0" scrolling="no">
<script type="text/javascript" src="http://ad.doubleclick.net/adj/maxim.dart/;adid=257123122;sz=145x40;abr=!ie;ord=[timestamp]?"></script>
</iframe>
<noscript><a href="http://ad.doubleclick.net/jump/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?"><img src="http://ad.doubleclick.net/ad/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?" border="0" alt="" /></a></noscript></div>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'hth_2013_semi_finals' => 'hth_2013_semi_finals',
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
    'hth_2013_finals' => 0,
    'gamer_girl_finalists' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_medium',
    'image_link' => 'content',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_profile_first_name']['id'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['table'] = 'field_data_field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['field'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_first_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profile_first_name']['alter']['text'] = '<a href="[path]">[field_profile_first_name]</a>';
  $handler->display->display_options['fields']['field_profile_first_name']['element_class'] = 'hth_name';
  $handler->display->display_options['fields']['field_profile_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_first_name']['type'] = 'text_plain';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_profile_city']['id'] = 'field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['table'] = 'field_data_field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['field'] = 'field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['label'] = '';
  $handler->display->display_options['fields']['field_profile_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_city']['type'] = 'text_plain';
  /* Field: Content: State/Province */
  $handler->display->display_options['fields']['field_profile_state']['id'] = 'field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['table'] = 'field_data_field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['field'] = 'field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['label'] = '';
  $handler->display->display_options['fields']['field_profile_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_state']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[path]">[field_profile_city], [field_profile_state]</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'hometown-hotties/2013/semi-finals';

  /* Display: HTH - Finals */
  $handler = $view->new_display('page', 'HTH - Finals', 'hth_2013_finals');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>You guys have cast your votes and whittled down this year\'s entrants to ten beautiful finalists. Check out their profile photos and videos below. Vote for your winner -- there can only be one! </p>
<div class="hth-sponsor"><iframe src="http://ad.doubleclick.net/adi/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?" width="145" height="40" marginwidth="0" marginheight="0" frameborder="0" scrolling="no">
<script type="text/javascript" src="http://ad.doubleclick.net/adj/maxim.dart/;adid=257123122;sz=145x40;abr=!ie;ord=[timestamp]?"></script>
</iframe>
<noscript><a href="http://ad.doubleclick.net/jump/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?"><img src="http://ad.doubleclick.net/ad/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?" border="0" alt="" /></a></noscript></div>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'hth_2013_finals' => 'hth_2013_finals',
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
    'gamer_girl_finalists' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_medium',
    'image_link' => 'content',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_profile_first_name']['id'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['table'] = 'field_data_field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['field'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_first_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profile_first_name']['alter']['text'] = '<a href="[path]">[field_profile_first_name]</a>';
  $handler->display->display_options['fields']['field_profile_first_name']['element_class'] = 'hth_name';
  $handler->display->display_options['fields']['field_profile_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_first_name']['type'] = 'text_plain';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_profile_city']['id'] = 'field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['table'] = 'field_data_field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['field'] = 'field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['label'] = '';
  $handler->display->display_options['fields']['field_profile_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_city']['type'] = 'text_plain';
  /* Field: Content: State/Province */
  $handler->display->display_options['fields']['field_profile_state']['id'] = 'field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['table'] = 'field_data_field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['field'] = 'field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['label'] = '';
  $handler->display->display_options['fields']['field_profile_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_state']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[path]">[field_profile_city], [field_profile_state]</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;
  $handler->display->display_options['path'] = 'hometown-hotties/2013/finals';

  /* Display: HTH - Vote Counts */
  $handler = $view->new_display('page', 'HTH - Vote Counts', 'hotties_2013_results');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Hometown Hotties 2013 - Results';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'infinite_scroll';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['required'] = TRUE;
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'vote',
    'function' => 'count',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_profile_first_name']['id'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['table'] = 'field_data_field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['field'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_profile_last_name']['id'] = 'field_profile_last_name';
  $handler->display->display_options['fields']['field_profile_last_name']['table'] = 'field_data_field_profile_last_name';
  $handler->display->display_options['fields']['field_profile_last_name']['field'] = 'field_profile_last_name';
  $handler->display->display_options['fields']['field_profile_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_last_name']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_profile_first_name] [field_profile_last_name]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_large',
    'image_link' => 'content',
  );
  /* Field: Content: Contest Week */
  $handler->display->display_options['fields']['field_hotties_contest_week']['id'] = 'field_hotties_contest_week';
  $handler->display->display_options['fields']['field_hotties_contest_week']['table'] = 'field_data_field_hotties_contest_week';
  $handler->display->display_options['fields']['field_hotties_contest_week']['field'] = 'field_hotties_contest_week';
  $handler->display->display_options['fields']['field_hotties_contest_week']['label'] = '';
  $handler->display->display_options['fields']['field_hotties_contest_week']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_hotties_contest_week']['alter']['text'] = 'Week [field_hotties_contest_week] ';
  $handler->display->display_options['fields']['field_hotties_contest_week']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hotties_contest_week']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_hotties_contest_week']['delta_offset'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = '';
  $handler->display->display_options['fields']['value']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['value']['alter']['text'] = '[value] votes';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['value']['coalesce'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;
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
  );
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['expose']['operator_id'] = 'field_hotties_contest_week_tid_op';
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['expose']['label'] = 'Contest Week';
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['expose']['operator'] = 'field_hotties_contest_week_tid_op';
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['expose']['identifier'] = 'field_hotties_contest_week_tid';
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_hotties_contest_week_tid']['vocabulary'] = 'hotties_contest_week';
  $handler->display->display_options['path'] = 'hometown-hotties/2013/results';

  /* Display: HTH - Semi Final Counts */
  $handler = $view->new_display('page', 'HTH - Semi Final Counts', 'hth_sf_results');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Hometown Hotties 2013 - Results';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'infinite_scroll';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['required'] = TRUE;
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'vote_semi_finals',
    'function' => 'count',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_profile_first_name']['id'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['table'] = 'field_data_field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['field'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_profile_last_name']['id'] = 'field_profile_last_name';
  $handler->display->display_options['fields']['field_profile_last_name']['table'] = 'field_data_field_profile_last_name';
  $handler->display->display_options['fields']['field_profile_last_name']['field'] = 'field_profile_last_name';
  $handler->display->display_options['fields']['field_profile_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_last_name']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_profile_first_name] [field_profile_last_name]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_large',
    'image_link' => 'content',
  );
  /* Field: Content: Contest Week */
  $handler->display->display_options['fields']['field_hotties_contest_week']['id'] = 'field_hotties_contest_week';
  $handler->display->display_options['fields']['field_hotties_contest_week']['table'] = 'field_data_field_hotties_contest_week';
  $handler->display->display_options['fields']['field_hotties_contest_week']['field'] = 'field_hotties_contest_week';
  $handler->display->display_options['fields']['field_hotties_contest_week']['label'] = '';
  $handler->display->display_options['fields']['field_hotties_contest_week']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_hotties_contest_week']['alter']['text'] = 'Week [field_hotties_contest_week] ';
  $handler->display->display_options['fields']['field_hotties_contest_week']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hotties_contest_week']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_hotties_contest_week']['delta_offset'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = '';
  $handler->display->display_options['fields']['value']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['value']['alter']['text'] = '[value] votes';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['value']['coalesce'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;
  $handler->display->display_options['path'] = 'hometown-hotties/2013/semi-finals-results';

  /* Display: Gamer Girl Finalists */
  $handler = $view->new_display('page', 'Gamer Girl Finalists', 'gamer_girl_finalists');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Gamer Girl Finalists';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'gamer_girl_wrapper';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'gamer_girl_entry';
  $handler->display->display_options['style_options']['wrapper_class'] = 'gallery-list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>Maxim Gamer Girl: Round 2. The Finalists videos are in and we need your vote for the Ultimate Maxim Gamer Girl. Click on a Finalist below to watch her Pilot Video and see her profile, and if you like what you see, hit that Vote button, too. You can vote for each Finalist once a day, so be sure to come back daily to make your pick. Voting end July 13, 2012.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'gamer_girl_finalists' => 'gamer_girl_finalists',
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
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'feature_large',
    'image_link' => 'content',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_profile_first_name']['id'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['table'] = 'field_data_field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['field'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_first_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profile_first_name']['alter']['text'] = '<a href="[path]">[field_profile_first_name]</a>';
  $handler->display->display_options['fields']['field_profile_first_name']['element_class'] = 'hth_name';
  $handler->display->display_options['fields']['field_profile_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_first_name']['type'] = 'text_plain';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_profile_city']['id'] = 'field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['table'] = 'field_data_field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['field'] = 'field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['label'] = '';
  $handler->display->display_options['fields']['field_profile_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_city']['type'] = 'text_plain';
  /* Field: Content: State/Province */
  $handler->display->display_options['fields']['field_profile_state']['id'] = 'field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['table'] = 'field_data_field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['field'] = 'field_profile_state';
  $handler->display->display_options['fields']['field_profile_state']['label'] = '';
  $handler->display->display_options['fields']['field_profile_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_state']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[path]">[field_profile_city], [field_profile_state]</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'gamer-girl-location';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['path'] = 'gamergirl/finalists';

  /* Display: HTH - Semi Final Counts */
  $handler = $view->new_display('page', 'HTH - Semi Final Counts', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Hometown Hotties 2013 - Results';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'infinite_scroll';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['required'] = TRUE;
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'vote_semi_finals',
    'function' => 'count',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_profile_first_name']['id'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['table'] = 'field_data_field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['field'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_profile_last_name']['id'] = 'field_profile_last_name';
  $handler->display->display_options['fields']['field_profile_last_name']['table'] = 'field_data_field_profile_last_name';
  $handler->display->display_options['fields']['field_profile_last_name']['field'] = 'field_profile_last_name';
  $handler->display->display_options['fields']['field_profile_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_last_name']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_profile_first_name] [field_profile_last_name]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_large',
    'image_link' => 'content',
  );
  /* Field: Content: Contest Week */
  $handler->display->display_options['fields']['field_hotties_contest_week']['id'] = 'field_hotties_contest_week';
  $handler->display->display_options['fields']['field_hotties_contest_week']['table'] = 'field_data_field_hotties_contest_week';
  $handler->display->display_options['fields']['field_hotties_contest_week']['field'] = 'field_hotties_contest_week';
  $handler->display->display_options['fields']['field_hotties_contest_week']['label'] = '';
  $handler->display->display_options['fields']['field_hotties_contest_week']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_hotties_contest_week']['alter']['text'] = 'Week [field_hotties_contest_week] ';
  $handler->display->display_options['fields']['field_hotties_contest_week']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hotties_contest_week']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_hotties_contest_week']['delta_offset'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = '';
  $handler->display->display_options['fields']['value']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['value']['alter']['text'] = '[value] votes';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['value']['coalesce'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;
  $handler->display->display_options['path'] = 'hometown-hotties/2013/semi-finals-results';

  /* Display: HTH - Final Counts */
  $handler = $view->new_display('page', 'HTH - Final Counts', 'htt_finals_vote_results');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Hometown Hotties 2013 - Results';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'infinite_scroll';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<style>
.page-hometown-hotties-2013 .gallery-list li { height:220px; }
</style>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['required'] = TRUE;
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'vote_finals',
    'function' => 'count',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_profile_first_name']['id'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['table'] = 'field_data_field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['field'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_profile_last_name']['id'] = 'field_profile_last_name';
  $handler->display->display_options['fields']['field_profile_last_name']['table'] = 'field_data_field_profile_last_name';
  $handler->display->display_options['fields']['field_profile_last_name']['field'] = 'field_profile_last_name';
  $handler->display->display_options['fields']['field_profile_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_last_name']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_profile_first_name] [field_profile_last_name]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'thumbnail_large',
    'image_link' => 'content',
  );
  /* Field: Content: Contest Week */
  $handler->display->display_options['fields']['field_hotties_contest_week']['id'] = 'field_hotties_contest_week';
  $handler->display->display_options['fields']['field_hotties_contest_week']['table'] = 'field_data_field_hotties_contest_week';
  $handler->display->display_options['fields']['field_hotties_contest_week']['field'] = 'field_hotties_contest_week';
  $handler->display->display_options['fields']['field_hotties_contest_week']['label'] = '';
  $handler->display->display_options['fields']['field_hotties_contest_week']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_hotties_contest_week']['alter']['text'] = 'Week [field_hotties_contest_week] ';
  $handler->display->display_options['fields']['field_hotties_contest_week']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hotties_contest_week']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_hotties_contest_week']['delta_offset'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = '';
  $handler->display->display_options['fields']['value']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['value']['alter']['text'] = '[value] votes';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['value']['coalesce'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;
  $handler->display->display_options['path'] = 'hometown-hotties/2013/finals-results';
  $export['hometown_hotties_2013'] = $view;

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

  return $export;
}
