<?php

/*
 * Implements hook_preprocess_node().
 */
function maxim_base_alpha_preprocess_node(&$node) {
  // Dispatch function based on node type
  $function = 'maxim_base_alpha_preprocess_node_' . $node['node']->type;
  if (function_exists($function)) {
   $function($node);
  }

  // Dispatch function based on taxonomy id
  if ( !empty($node['field_channel']['0']['tid']) ) {
    $taxonomy_function = 'maxim_base_alpha_preprocess_node__tid_' . $node['field_channel']['0']['tid'];
    if (function_exists($taxonomy_function)) {
     $taxonomy_function($node);
    }
  }
  // Set JavaScript variables
  node_set_js_vars($node);
}

/*
 * Set JS variables to page
 */
function node_set_js_vars(&$node) {
  $maxim_vars = array();
  $maxim_vars['nid'] = $node['nid'];
  $maxim_vars['title'] = trim($node['title']);
  $maxim_vars['nType'] = $node['type'];
  $maxim_vars['nURL'] = $node['node_url'];

  if (array_key_exists('field_channel', $node) && count($node['field_channel']['und'])) {
    $maxim_vars['nChannelID'] = $node['field_channel']['und'][0]['tid'];
    $maxim_vars['channel'] = array();
    $arChannel = taxonomy_get_parents_all($maxim_vars['nChannelID']);
    foreach($arChannel as $ch){
      array_unshift($maxim_vars['channel'], $ch->name);
    }
  }

  if (count($maxim_vars)) {
    drupal_add_js(array('Maxim' => $maxim_vars), 'setting');
  }
}

function maxim_base_alpha_preprocess_node_celebrity_profile (&$node) {
  drupal_add_css(drupal_get_path('theme', 'maxim_base').'/css/celebrity-profile.css', array('group' => CSS_DEFAULT,'preprocess'=> FALSE, 'every_page' => FALSE, 'weight' => 5));
}

/*
 * Don't show main image on Found Porn articles.
 */
function maxim_base_alpha_preprocess_node__tid_49(&$node) {
  // Trick drupal into thinking main image was already rendered so it wont display.
  $node['content']['field_main_image']['#printed'] = TRUE;
}

/*
 * implement the display Main image field on Article, Blog, List, Webform, Personality Test, Poll and Review
 */
function maxim_base_alpha_preprocess_node_article(&$node) {
  hide_main_image($node);
  // $node['content']['body']['0']['#markup'] = cleanText($node['content']['body']['0']['#markup']);

  // Set pagination_showall field if pagination exists
  set_pagination_showall($node);

  //don't display fb/twitter links on 404 page
  if ($node['nid'] != 36482) {
    $node['content']['body']['0']['#prefix'] = add_social_links();
    $node['content']['body']['0']['#suffix'] = add_social_links('','bottom');
  }
}

function maxim_base_alpha_preprocess_node_blog(&$node) {
  hide_main_image($node);
  $node['content']['body']['0']['#prefix'] = add_social_links();
  $node['content']['body']['0']['#suffix'] = add_social_links('','bottom');

  // $node['content']['body']['0']['#markup'] = cleanText($node['content']['body']['0']['#markup']);
}

function maxim_base_alpha_preprocess_node_review(&$node) {
  hide_main_image($node);
  $node['content']['body']['0']['#prefix'] = add_social_links();
  $node['content']['body']['0']['#suffix'] = add_social_links('','bottom');

  // $node['content']['body']['0']['#markup'] = cleanText($node['content']['body']['0']['#markup']);
}

function maxim_base_alpha_preprocess_node_webform(&$node) {
  hide_main_image($node);

  /*add social links to webofrm header of hot 100 vote view */
  //if ($node['nid'] === '62411') {
    //$node['content']['body']['0']['#prefix'] = add_social_links();
  //}
}


function maxim_base_alpha_preprocess_node_poll(&$node) {
  hide_main_image($node);
}

function maxim_base_alpha_preprocess_node_personality_test(&$node) {
  hide_main_image($node);
}

function maxim_base_alpha_preprocess_node_list(&$node) {
  hide_main_image($node);
  // $node['content']['body']['0']['#markup'] = cleanText($node['content']['body']['0']['#markup']);
}

function maxim_base_alpha_preprocess_node_joke(&$node) {
  $node['content']['body']['0']['#prefix'] = add_social_links();
  $node['content']['body']['0']['#suffix'] = add_social_links('','bottom');
}

function maxim_base_alpha_preprocess_node_video(&$node) {
  // Hide the 5min player if brightcove video player exists
  /*if (array_key_exists('field_brightcove_video', $node) && count($node['field_brightcove_video']) > 0) {
    hide($node['content']['field_media_file']);
  }*/
  //$node['content']['body']['0']['#prefix']= add_social_links();
}

function maxim_base_alpha_preprocess_node_hotties_profile(&$node) {
  include_once libraries_get_path('php').'/shared/preprocess-functions.php';
  process_slideshow_ads(1);

  drupal_add_js(drupal_get_path('theme', 'maxim_base').'/js/hometown-hotties.js', array('type' => 'file', 'scope' => 'header', 'weight' => 5));
  drupal_add_css(drupal_get_path('theme', 'maxim_base').'/css/hometown-hotties.css', array('group' => CSS_DEFAULT,'preprocess'=> FALSE, 'every_page' => FALSE, 'weight' => 5));
  drupal_add_css(libraries_get_path('slideshow').'/colorbox.css');
  drupal_add_js(libraries_get_path('slideshow').'/jquery.colorbox.js');
  drupal_add_js(libraries_get_path('slideshow').'/hammer.js');
  drupal_add_js(libraries_get_path('slideshow').'/jquery.hammer.js');

  if (is_gamer_girl($node)) {
    drupal_add_js(drupal_get_path('module', 'gamer_girl_voting_resource').'/gg_voting_button.js');
  }
  else {
    drupal_add_js(drupal_get_path('module', 'hth_voting_resource').'/hth_voting_button.js');
  }

  $hottie_year = ''; $hottie_week = '';
  //not sure why [und] is only sometimes present
  if (isset($node['field_hotties_contest_year'][0]['tid'])) {
     $hottie_year = taxonomy_term_load($node['field_hotties_contest_year'][0]['tid'])->name;
  }
  elseif (isset($node['field_hotties_contest_year'][LANGUAGE_NONE][0]['tid'])) {
     $hottie_year = taxonomy_term_load($node['field_hotties_contest_year'][LANGUAGE_NONE][0]['tid'])->name;
  }

  //make sure only 1 weeks is set (important to not display 2 different sliders)
  $hottie_weeks = array();
  if (isset($node['field_hotties_contest_week'][LANGUAGE_NONE])) {
    $week_vals = $node['field_hotties_contest_week'][LANGUAGE_NONE];
  }
  else {
    $week_vals = $node['field_hotties_contest_week'];
  }

  foreach ($week_vals as $week) {
    array_push($hottie_weeks, strtolower(taxonomy_term_load($week['tid'])->name));
  }
  if (count($hottie_weeks) > 1) {
    if (in_array('finalists', $hottie_weeks)) {
      $hottie_week = 'finals';
    }
    else if (in_array('semifinalist', $hottie_weeks)) {
      $hottie_week = 'semi-finals';
    }
  }
  else {
    $hottie_week = $hottie_weeks[0];
  }

  $nodequeue_pos = get_nq_pos($node, $hottie_year, $hottie_week);
  $nodequeue_links = get_hottie_next_prev($node, $hottie_year, $hottie_week, $nodequeue_pos);

  drupal_add_js(array('Maxim' => array('hottie' => array('hottie_position' => $nodequeue_pos))), 'setting');
  drupal_add_js(array('Maxim' => array('hottie' => array('hottie_year' => $hottie_year))), 'setting');
  drupal_add_js(array('Maxim' => array('hottie' => array('hottie_week' => $hottie_week))), 'setting');
  drupal_add_js(array('Maxim' => array('hottie' => array('hottie_prev' => $nodequeue_links['prev']))), 'setting');
  drupal_add_js(array('Maxim' => array('hottie' => array('hottie_next' => $nodequeue_links['next']))), 'setting');
}

function maxim_base_alpha_preprocess_node_generic_profile(&$node) {
  include_once libraries_get_path('php').'/shared/preprocess-functions.php';
  process_slideshow_ads(1);

  drupal_add_js(drupal_get_path('theme', 'maxim_base').'/js/generic-profile.js', array('type' => 'file', 'scope' => 'header', 'weight' => 5));
  drupal_add_css(drupal_get_path('theme', 'maxim_base').'/css/generic-profile.css', array('group' => CSS_DEFAULT,'preprocess'=> FALSE, 'every_page' => FALSE, 'weight' => 5));
  drupal_add_css(libraries_get_path('slideshow').'/colorbox.css');
  drupal_add_js(libraries_get_path('slideshow').'/jquery.colorbox.js');
  drupal_add_js(libraries_get_path('slideshow').'/hammer.js');
  drupal_add_js(libraries_get_path('slideshow').'/jquery.hammer.js');
  drupal_add_js(drupal_get_path('module', 'generic_voting_resource').'/generic_voting_button.js');

  $nodequeue_pos = get_nq_pos($node);
  $nodequeue_links = get_hottie_next_prev($node, NULL, NULL, $nodequeue_pos);

  drupal_add_js(array('Maxim' => array('general_profile_data' => array('gprofile_position' => $nodequeue_pos))), 'setting');
  drupal_add_js(array('Maxim' => array('general_profile_data' => array('gprofile_prev_url' => $nodequeue_links['prev']))), 'setting');
  drupal_add_js(array('Maxim' => array('general_profile_data' => array('gprofile_next_url' => $nodequeue_links['next']))), 'setting');
}

function maxim_base_alpha_preprocess_node_slideshow(&$node) {
  drupal_add_js('http://prod.contentunlock.s3.amazonaws.com/pub/maxim/cu/cunlock.js', 'external');
  drupal_add_js('http://prod.contentunlock.s3.amazonaws.com/pub/maxim/config/maxim.js', 'external');
  $node['content']['body']['0']['#prefix'] = '<div class="gallery anythingSlider cunlock_main_content"><div class="wrapper"><ul></ul></div></div><div id="slideshowBody" style="margin-top:15px"></div>';
  $node['content']['body']['0']['#markup'] = '';
}

/*
 * Set pagination_showall field with Show Full Page link.  This is displayed using display suite.
 */
function set_pagination_showall(&$node) {
  $showfull = variable_get('pagination_showall', 1);
  if ($showfull && isset($node['content']['pagination_pager']['#markup']) && strlen($node['content']['pagination_pager']['#markup'])) {
    $page = isset($_GET['page']) ? $_GET['page'] : 0;
    if ($page !== 'show') {
      $show_url = url('node/' . $node['nid'], array(
        'query' => array( 'page' => 'show' ),
        )
      );
      $node['content']['pagination_showall'] = array(
          '#markup' => '<div class="pagination-showall"><a href="' . $show_url . '">Single Page View</a></div>',
      );
    }
  }
}

/*
 * Strip extra break tags from content.
 */
function cleanText ($text) {
  return str_replace(array('<br><br>','<br /><br />'), '<br />', $text);
}

/*
 * Hide the main image unless Show Main Image is set.
 */
function hide_main_image(&$node) {
  if (empty($node['node']->field_display_main_image['und']['0']['value'])) {
    $node['content']['field_main_image']['#printed'] = TRUE;
  }
}

/*
 * Hide the main image unless Show Main Image is set.
 */
function add_social_links($byline = '', $position = 'top') {
  if ($byline === 'no-byline') {
    $add_class = 'social-links-no-byline';
  }
  else {
    $add_class = 'social-links';
  }
  if ($position === 'bottom') {
    $add_class .= ' social-bottom';
  }

  $fb_link = '<div class="fb-like" data-send="true" data-layout="button_count" data-width="450" data-show-faces="false"></div>';

  $gplus_link = "<div class='g-plusone' data-size='medium'></div>";

  $twitter_link = '<a href="https://twitter.com/share" class="twitter-share-button" data-via="MaximMag">Tweet</a>';
  $twitter_js = '!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs")';

  drupal_add_js($twitter_js, array('type' => 'inline', 'scope' => 'footer'));

 return('<div class="'.$add_class.'">'.$twitter_link.$gplus_link.$fb_link.'</div>');
}

/*
 * Get previous/next girl using nodequeue
 * TODO:  by published date if position not defined
 */
function get_hottie_next_prev($node, $hottie_year = NULL, $hottie_week = NULL, $pos = 0){
  $nid = $node['nid'];
  $links = array('next'=>'', 'prev'=>'');

  $gamer_girl = is_gamer_girl($node);
  $general_profile = is_general_profile($node);

  // If position defined, then use nodequeue
  if ($pos != 0){
    if ($gamer_girl || $hottie_year >= 2013 || $general_profile) {
      $pos1 = $pos-1;
      $pos2 = $pos+1;

      if (!$gamer_girl && is_numeric($hottie_week)) {
        $nq_name = 'hth_'.$hottie_year.'_contestants_week_'.$hottie_week;
      }
      else if ($hottie_week == 'finals' || $hottie_week == 'semi-finals') {
        $nq_name = 'hth_'.$hottie_year.'_'.str_replace('-', '_', $hottie_week);
      }
      else if($general_profile) {
        $nq_name = get_gen_profile_nq($node);
      }
      else {
         $nq_name = 'gamer_girl_finalists';
      }

      $sql = 'select n.nid, n.position FROM {nodequeue_nodes} n ';
      $sql .= 'left join {nodequeue_queue} q on n.qid = q.qid ';
      $sql .= 'where q.name = :nq and ';
      $sql .= '(n.position = :pos1 or n.position = :pos2) ';
      $sql .= 'order by n.position asc';
      $params = array(':nq' => $nq_name, ':pos1' => $pos1, ':pos2' => $pos2);

      $result = db_query($sql,$params);
      foreach ($result as $row) {
        if ($row->position == $pos1) {
          $links['prev'] = url('node/'.$row->nid);
        }
        else if ($row->position == $pos2) {
          $links['next'] = url('node/'.$row->nid);
        }
      }
    }
    else {
      $links['prev'] = '';
      $links['next'] = '';
    }
  }
  else {
    if ($general_profile) {
      $links['prev'] = '';
      $links['next'] = '';
    }
    else {
      $p_sql = 'SELECT n.nid, n.title ';
      $p_sql .= 'FROM {node} n, {taxonomy_index} t ';
      $p_sql .= 'WHERE n.nid = t.nid AND n.created < (SELECT created FROM {node} WHERE nid = :nid) AND t.tid=9 AND type IN (\'slideshow\') AND status = 1 ';
      $p_sql .= 'ORDER BY n.created DESC LIMIT 1';

      $n_sql = 'SELECT n.nid, n.title ';
      $n_sql .= 'FROM {node} n, {taxonomy_index} t ';
      $n_sql .= 'WHERE n.nid = t.nid AND n.created > (SELECT created FROM {node} WHERE nid = :nid) AND t.tid=9 AND type IN (\'slideshow\') AND status = 1 ';
      $n_sql .= 'ORDER BY n.created ASC LIMIT 1';

      $params = array(':nid' => $nid);

      $result = db_query($p_sql,$params);
      foreach ($result as $row) {
        $links['prev'] = url('node/'.$row->nid);
      }
      $result = db_query($n_sql,$params);
      foreach ($result as $row) {
        $links['next'] = url('node/'.$row->nid);
      }
    }
  }

  return $links;
}

function get_nq_pos($node, $hottie_year = NULL, $hottie_week = NULL) {
  $nid = $node['nid'];

  if (is_gamer_girl($node)) {
    $nq_name = 'gamer_girl_finalists';
  }
  else if (is_general_profile($node)) {
    $nq_name = get_gen_profile_nq($node);
  }
  else if ($hottie_year >= 2013) {
    if ($hottie_week == 'finals' || $hottie_week == 'semi-finals') {
      $nq_name = 'hth_'.$hottie_year.'_'.str_replace('-', '_', $hottie_week);
    }
    else {
      $nq_name = 'hth_'.$hottie_year.'_contestants_week_'.$hottie_week;
    }
  }
  else {
    return 0;
  }

  $sql = 'SELECT n.position ';
  $sql .= 'FROM {nodequeue_nodes} n, {nodequeue_queue} q, {nodequeue_subqueue} sq ';
  $sql .= 'WHERE q.qid = sq.qid AND sq.sqid = n.sqid AND n.qid = q.qid AND n.nid = :nid AND q.name = :nq';
  $params = array(':nid' => $nid, ':nq' => $nq_name);

  $result = db_query($sql,$params)->fetchObject();
  if ($result) {
    return($result->position);
  }
  else {
    return(0);
  }
}

function get_gen_profile_nq($node) {
  $tags = get_all_taxonomomy_tags($node);
  $gp_taxonomy_search = 'gprofile_';
  $nq_suffix = '_nq';

  foreach ($tags as $tag) {
    if (strrpos($tag, $gp_taxonomy_search) !== false) {
      $nq_name_parts = explode($gp_taxonomy_search, $tag);
      return ($nq_name_parts[1].$nq_suffix);
    }
  }

  return ('');
}

function is_general_profile($node) {
  $is_gen_prof = ($node['type'] == 'generic_profile') ? true : false;

  return($is_gen_prof);
}

