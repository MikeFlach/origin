<?php

/*
 * Implements hook_preprocess_views_view
 */
function maxim_base_alpha_preprocess_views_view(&$view) {
  $function = 'maxim_base_alpha_preprocess_views_view__'.$view['view']->name;
  if (function_exists($function)) {
   $function($view);
  }
}

/*
 * Dispatch to individual view displays. Pass __FUNCTION__ for $calling_function.
 */
function view_display_dispatch(&$view, $calling_function) {
  $function = $calling_function.'__'.$view['view']->current_display;
  if (function_exists($function)) {
   $function($view);
  }
}

function maxim_base_alpha_preprocess_views_view__slideshow_json(&$view) {
  view_display_dispatch($view, __FUNCTION__);
}

function maxim_base_alpha_preprocess_views_view__slideshow_json__json_slideshow_block(&$view) {
  drupal_add_js(libraries_get_path('slideshow').'/flowplayer-3.2.6.min.js');
  drupal_add_js(libraries_get_path('slideshow').'/jquery.anythingslider.js');
  drupal_add_js(libraries_get_path('slideshow').'/jquery.easing.1.2.js');
  drupal_add_js(libraries_get_path('slideshow').'/slideshow_display.js');
  drupal_add_css(libraries_get_path('slideshow').'/slider.css');
  drupal_add_css(libraries_get_path('slideshow') . '/main_slideshow.css');

  $json_data = json_decode($view['rows'], TRUE);
  for($i = 0; $i < count($json_data); $i++) {
    $media_type = determine_media_type(pathinfo($json_data[$i]['src'], PATHINFO_EXTENSION));
    $json_data[$i]['type'] = $media_type;

    // replace image path with cdn
    $json_data[$i]['src'] = replace_local_files_with_cdn_path($json_data[$i]['src']);
    $json_data[$i]['thumb'] = replace_local_files_with_cdn_path($json_data[$i]['thumb']);
  }

  $prev_link = get_prev_next($json_data[0]['Nid'], $json_data[0]['TermID'], "p");
  $next_link = get_prev_next($json_data[0]['Nid'], $json_data[0]['TermID'], "n");
  $links = '<div id="prevNextLinks"><span id="prev">'.$prev_link.'</span><span id="next">'.$next_link.'</span></div>';

  $js = <<<EOD
    // On Document load
    jQuery(function () {
      loadSlideShowImages(1);
       galleryLink = slideshow[0].galleryLink.toLowerCase();
       jQuery("#slideshowBody").parent().append("<div id='galleryLink'><a href='" + galleryLink + "'>View All Slides</a></div>");
    });
EOD;

  $addLinks = "jQuery(function () {jQuery(\"#slideshowBody\").parent().append(\"".str_replace('"', "'", $links)."\");});";

  drupal_add_js("var slideshow=".str_replace("'", '&apos;', json_encode($json_data)).';', 'inline');
  drupal_add_js($js, 'inline');
  drupal_add_js($addLinks, 'inline');

  $view['rows'] = ' ';
}

function maxim_base_alpha_preprocess_views_view__slideshow_json__slideshow_blackout_block(&$view) {
  drupal_add_js(libraries_get_path('slideshow') . '/jquery.colorbox.js');
  drupal_add_js(libraries_get_path('slideshow') . '/flowplayer-3.2.6.min.js');
  drupal_add_css(libraries_get_path('slideshow') . '/colorbox.css');
  drupal_add_css(libraries_get_path('slideshow') . '/slider.css');
  drupal_add_css(libraries_get_path('slideshow') . '/blackoutSlideshow.css');
  drupal_add_js(libraries_get_path('slideshow') . '/blackout_flowplayer.js', array('scope' => 'footer'));

  $json_data = json_decode($view['rows'], TRUE);
  $initialSlide = (isset($_GET["slide"]) && is_numeric($_GET["slide"]) && ($_GET["slide"] > 0 && $_GET["slide"] < count($json_data)) === true ? $_GET["slide"] : 0);

  for($i = 0; $i < count($json_data); $i++) {
    $mediaType = determine_media_type(pathinfo($json_data[$i]['src'], PATHINFO_EXTENSION));
    $json_data[$i]['type'] = $mediaType;
    $json_data[$i]['src'] = replace_local_files_with_cdn_path($json_data[$i]['src']);
    $json_data[$i]['thumb'] = replace_local_files_with_cdn_path($json_data[$i]['thumb']);
  }

  if (count($json_data) > 0) {
    $prev = '<span id="prev" class="lnk">&lt;</span>';
    $next = '<span id="next" class="lnk">&gt;</span>';
    $main_ss_link = '<div id="links"><div id="backLink" class="closeLnk"><a href="'.url('node/'.$json_data[0]['Nid']).'"><img src="/'.libraries_get_path('slideshow').'/images/close.png'.'"/></a></div>';
    $gallery_link = '<div id="galleryLink" class="galleryLnk"><a href="'.strtolower($json_data[0]["galleryLink"]).'">GALLERY</a></div></div>';
  }
  else {
    $prev = '';
    $next = '';
    $main_ss_link = '';
    $gallery_link = '';
  }
  // special case where first thumbnail is a video
  if (count($json_data) > 0) {
    if (determine_media_type(pathinfo($json_data[$initialSlide]['src'], PATHINFO_EXTENSION)) === 'video') {
      $dImage = "<div id='dImage'><img class='dispCopy cboxElement' id='dispImage' src='' /></div>";
      $displInitialVideo = "jQuery('#dImage').hide(); jQuery('#vp').show(); flowplayer().play(slideShow[".$initialSlide."]['src']); //flowplayer().stop();";
    }
    else {
      $dImage = "<div id='dImage'><img class='dispCopy cboxElement' id='dispImage' src='".replace_local_files_with_cdn_path($json_data[$initialSlide]['src'])."' /></div>";
      $displInitialVideo = '';
    }
    $slideTxt = "<div style='display:none'><div id='pop'>".$json_data[$initialSlide]['copy']."</div></div>";
    $setupVars = "var currIndex = ".$initialSlide."; slideShow=".json_encode($json_data).";";
  }
  else {
    $dImage = '';
    $displInitialVideo = '';
    $slideTxt = '';
    $setupVars = '';
  }

  $txtPop = "if (jQuery('#pop').html.length > 0) {jQuery('.dispCopy').click(function() { jQuery(this).colorbox({inline:true, href:'#pop', width:'400'})});}";

  $flowPlayerHTML = "<div id='dVideo'><a href='' class='videoplayer' id='vp' style='display:none;'></a></div>";
  $html = '<div>'.$main_ss_link.$gallery_link.'</div><div id="slideshowFull">'.$slideTxt.$prev.$flowPlayerHTML.$dImage.$next;
  drupal_add_js($setupVars.$displInitialVideo.$txtPop, array('type' => 'inline', 'scope' => 'footer'));

  $view['rows'] = $html;
}

function maxim_base_alpha_preprocess_views_view__slideshow_json__slideshow_gallery_block(&$view) {
  drupal_add_css(libraries_get_path('slideshow') . '/slideshowGallery.css');

  // add the slide number to the url & replace video images with default thumbnails
  $gallery_link = <<<EOD
    jQuery('.galleryImg').each(function(index) {
      currLnk = jQuery(this).parent().attr('href');
      jQuery(this).parent().attr('href', currLnk+index);

      if ((this.src.indexOf('.flv') != -1) || (this.src.indexOf('.mp4') != -1)) {
        this.src = 'http://cdn2.maxim.com/maximonline/assets/video_1.jpg'
      }
    });
EOD;

  $html = replace_local_files_with_cdn_path($view['rows']);
  drupal_add_js($gallery_link, array('type' => 'inline', 'scope' => 'footer'));

  $view['rows'] = $html;
}

// Supporting Functions
function get_prev_next($currentNode = NULL, $channelID = NULL, $op = 'p') {
  if ($op === 'p') {
    $sql_op = '<';
    $order = 'DESC';
  }
  elseif ($op == 'n') {
    $sql_op = '>';
    $order = 'ASC';
  }
  else {
    return NULL;
  }

  $output = NULL;
  $sql_select = "SELECT n.nid, n.title ";
  $sql_from = "FROM {node} n, {taxonomy_index} t ";
  $sql_where = "WHERE n.nid = t.nid AND n.nid ".$sql_op." :nid AND t.tid=".$channelID." AND type IN ('slideshow') AND status = 1 ";
  $sql_order = "ORDER BY nid ".$order." LIMIT 1";
  $sql = $sql_select.$sql_from.$sql_where.$sql_order;

  $result = db_query($sql, array(':nid' => $currentNode));
  foreach ($result as $data) {}
  if (isset($data)) {
    if ($op == 'n') {
      return l("Next Slideshow", "node/$data->nid", array('html' => TRUE));
    }
    else if ($op == 'p') {
      return l("Previous Slideshow", "node/$data->nid", array('html' => TRUE));
    }
  }
}

function determine_media_type ($file_extension) {
  $image_types = array('jpg', 'png');
  $video_types = array('flv', 'mp4');

  if (in_array($file_extension, $image_types)) {
    return ('image');
  }
  elseif (in_array($file_extension, $video_types)) {
    return ('video');
  }
}

function replace_local_files_with_cdn_path($file) {
  //thius is quick and dirty to get images displayed on local machines without having to have the content local.
  $newFile = str_replace(' http://maxim.localhost:8082/sites/default/files/maxim', 'http://cdn2.maxim.com/maxim/', $file);
  $newFile = str_replace('http://localhost.maxim.com/sites/default/files/maxim/', 'http://cdn2.maxim.com/maxim/', $file);

  return($newFile);
}