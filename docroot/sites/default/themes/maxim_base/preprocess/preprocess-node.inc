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
}

/*
 * Don't show main image on Found Porn articles.
 */
function maxim_base_alpha_preprocess_node__tid_49(&$node) {
  // Trick drupal into thinking main image was already rendered so it wont display.
  $node['content']['field_main_image']['#printed'] = TRUE;
}

/*
 * implement the display Main image field on Article, Blog, List, and Review
 */
function maxim_base_alpha_preprocess_node_article(&$node) {
  hide_main_image($node);
  // $node['content']['body']['0']['#markup'] = cleanText($node['content']['body']['0']['#markup']);

  //don't display fb/twitter links on 404 page
  if ($node['nid'] != 36482) {
    $node['content']['body']['0']['#prefix']= add_social_links();
  }
}

function maxim_base_alpha_preprocess_node_blog(&$node) {
  hide_main_image($node);
  $node['content']['body']['0']['#prefix']= add_social_links();
  // $node['content']['body']['0']['#markup'] = cleanText($node['content']['body']['0']['#markup']);
}

function maxim_base_alpha_preprocess_node_review(&$node) {
  hide_main_image($node);
  $node['content']['body']['0']['#prefix']= add_social_links();
  // $node['content']['body']['0']['#markup'] = cleanText($node['content']['body']['0']['#markup']);
}

function maxim_base_alpha_preprocess_node_list(&$node) {
  hide_main_image($node);
  // $node['content']['body']['0']['#markup'] = cleanText($node['content']['body']['0']['#markup']);
}

function maxim_base_alpha_preprocess_node_joke(&$node) {
  $node['content']['body']['0']['#prefix']= add_social_links();
}
function maxim_base_alpha_preprocess_node_video(&$node) {
  //$node['content']['body']['0']['#prefix']= add_social_links();
}
function maxim_base_alpha_preprocess_node_hotties_profile(&$node) {
  $node['content']['body']['0']['#prefix']= add_social_links();
}

function maxim_base_alpha_preprocess_node_slideshow(&$node) {
  $node['content']['body']['0']['#prefix'] = '<div class="gallery anythingSlider"><div class="wrapper"><ul></ul></div></div><div id="slideshowBody" style="margin-top:15px"></div>';
  $node['content']['body']['0']['#markup'] = '';
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
function add_social_links($byline = '') {
  if ($byline === 'no-byline') {
    $add_class = 'social-links-no-byline';
  }
  else {
    $add_class = 'social-links';
  }

  $fb_link = '<div class="fb-like" data-send="false" data-layout="button_count" data-width="450" data-show-faces="false"></div>';

  $twitter_link = '<a href="https://twitter.com/share" class="twitter-share-button">Tweet</a>';
  $twitter_js = '!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");';

  drupal_add_js($twitter_js, array('type' => 'inline', 'scope' => 'footer'));

 return('<div class="'.$add_class.'">'.$fb_link.$twitter_link.'</div>');
}
