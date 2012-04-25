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

/*
 * Don't show main image on Found Porn articles.
 */
function maxim_base_alpha_preprocess_node__tid_49(&$node) {
  // Trick drupal into thinking main image was already rendered so it wont display.
  $node['content']['field_main_image']['#printed'] = TRUE;
}

/*
 * implement the display Main image field on Article, Blog, List, Webform and Review
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

function maxim_base_alpha_preprocess_node_webform(&$node) {
  hide_main_image($node);
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
  $fb_login = get_faceobok_login_btn();
  //drupal_add_js($fb_login['fb_js'], 'inline');

  $node['content']['body']['0']['#prefix'] = '<div class="gallery anythingSlider"><div class="wrapper"><ul></ul></div></div><div id="slideshowBody" style="margin-top:15px"></div>';

  $view_name = 'slideshow_json';
  $display = 'slideshow_hth_profile';

  $args = array();

  //not sure why [und] is only sometimes present
  if (isset($node['field_profile_ref_slideshow'][0]['nid'])) {
    $args[0] = $node['field_profile_ref_slideshow'][0]['nid'];
  }
  else {
     $args[0] = $node['field_profile_ref_slideshow'][LANGUAGE_NONE][0]['nid'];
  }

  $view_result = views_embed_view($view_name, $display, $args);
  $json_data = '';
  if (strlen($view_result)) {
    preg_match('/\<div class\=[\"]{0,1}view-content[\"]{0,1}\>(.*?)\<\/div\>/s', $view_result, $slideshow_data);
    $json_data = json_decode(trim($slideshow_data[1]), TRUE);

    add_slideshow($json_data);
  }

  $vote_html = '<div id="hth_vote">Vote For Me!</div>';


  $node['content']['body']['0']['#markup'] .= $fb_login['fb_html'].$vote_html;
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

  $twitter_link = '<a href="https://twitter.com/share" class="twitter-share-button" data-via="MaximMag">Tweet</a>';
  $twitter_js = '!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs")';


  drupal_add_js($twitter_js, array('type' => 'inline', 'scope' => 'footer'));

 return('<div class="'.$add_class.'">'.$twitter_link.$fb_link.'</div>');
}

function add_slideshow($json_data) {
  drupal_add_js(libraries_get_path('slideshow').'/flowplayer-3.2.6.min.js');
  drupal_add_js(libraries_get_path('slideshow').'/jquery.anythingslider.js');
  drupal_add_js(libraries_get_path('slideshow').'/jquery.easing.1.2.js');
  drupal_add_js(libraries_get_path('slideshow').'/slideshow_display.js');
  drupal_add_css(libraries_get_path('slideshow').'/slider.css');
  drupal_add_css(libraries_get_path('slideshow').'/main_slideshow_hth.css');

  if (count($json_data) > 0) {
    for($i = 0; $i < count($json_data); $i++) {
      $json_data[$i]['type'] = determine_media_type(pathinfo($json_data[$i]['src'], PATHINFO_EXTENSION));
      $json_data[$i]['src'] = replace_image_path($json_data[$i]['src'], 'ss_main');
      $json_data[$i]['thumb'] = replace_image_path($json_data[$i]['thumb'], 'ss_carousel');
      $json_data[$i]['attribution'] = '';
      $json_data[$i]['slide_title'] = '';
    }

    $js = <<<EOD
      // On Document load
      jQuery(function () {
        loadSlideShowImages(1);
        galleryLink = slideshow[0].galleryLink.toLowerCase();
        jQuery(".anythingSlider").parent().prepend("<div id='fullscreenLink'><a href='" + replaceChannelPath(slideshow[0].fullscreenLink) + "'><img class='fullScreenLink' src='/sites/default/libraries/slideshow/images/icon_fullscreen.gif' />FULL SCREEN</a></div><div class='clear-both'>&nbsp;</div>");

        jQuery('#hth_vote').click(function() {
          jQuery.ajax({
            url: '/js-api/vote',
            type: 'POST',
            data: {nid: 11,
                   uid: 666},
            success: function() { alert('s'); },
            error: function() { alert('f'); },
            cache:false
          });
        });
      });

EOD;
    drupal_add_js("var slideshow=".str_replace("'", '&apos;', json_encode($json_data)).';', 'inline');
    drupal_add_js($js, 'inline');
  }
}

function get_faceobok_login_btn () {
  $fb = array();

  $fb['fb_html'] = <<<EOD
    <div id="fb-root"></div>
    <div id="auth-status">
      <div id="auth-loggedout">
        <div class="fb-login-button" data-show-faces="false" data-width="200" data-max-rows="1"></div>
      </div>
    </div>
EOD;

  $fb['fb_js'] = <<<EOD
      // Init the SDK upon load
      window.fbAsyncInit = function() {
        FB.init({
          appId      : '246188768809841', // App ID
         // channelUrl : '//'+window.location.hostname+'/channel', // Path to your Channel File
          status     : true, // check login status
          cookie     : true, // enable cookies to allow the server to access the session
          xfbml      : true  // parse XFBML
        });


EOD;

  return ($fb);
}

