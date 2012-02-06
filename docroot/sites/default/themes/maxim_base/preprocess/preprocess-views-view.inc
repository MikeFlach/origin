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

function maxim_base_alpha_preprocess_views_view__home_page(&$view) {
  view_display_dispatch($view, __FUNCTION__);
}

function maxim_base_alpha_preprocess_views_view__channel(&$view) {
  view_display_dispatch($view, __FUNCTION__);
}

function maxim_base_alpha_preprocess_views_view__slideshow_json(&$view) {
  view_display_dispatch($view, __FUNCTION__);
}

function maxim_base_alpha_preprocess_views_view__maximtv_browser(&$view) {
  // Move the more video links to the top of the content.
  switch ($view['view']->current_display) {
    case 'maxim_tv_channel':
    case 'maxim_tv_latest':
    case 'mtv_channel_block':
      break;
    default:
      $view['title'] = str_replace(array('»','videos'), array('<span>»</span>', $view['view']->build_info['substitutions']['%1']), $view['more']);
      $view['more'] = '';
      break;
  }
}

function maxim_base_alpha_preprocess_views_view__channel__girls_girls_of_maxim(&$view) {
  drupal_add_css(libraries_get_path('girls_of_maxim') . '/gallery_view.css');
}

function maxim_base_alpha_preprocess_views_view__channel__girls_girls_of_maxim_glossary(&$view) {
  setup_girls_of_maxim_glossary($view);
}

/*
 * Regular Slideshow
 */
function maxim_base_alpha_preprocess_views_view__slideshow_json__json_slideshow_block(&$view) {
  drupal_add_js(libraries_get_path('slideshow').'/flowplayer-3.2.6.min.js');
  drupal_add_js(libraries_get_path('slideshow').'/jquery.anythingslider.js');
  drupal_add_js(libraries_get_path('slideshow').'/jquery.easing.1.2.js');
  drupal_add_js(libraries_get_path('slideshow').'/slideshow_display.js');
  drupal_add_css(libraries_get_path('slideshow').'/slider.css');
  drupal_add_css(libraries_get_path('slideshow').'/main_slideshow.css');

  $json_data = json_decode($view['rows'], TRUE);

  if (count($json_data) > 0) {
    for($i = 0; $i < count($json_data); $i++) {
      $media_type = determine_media_type(pathinfo($json_data[$i]['src'], PATHINFO_EXTENSION));
      $json_data[$i]['type'] = $media_type;

      $json_data[$i]['src'] = replace_image_path($json_data[$i]['src'], 'ss_main');
      $json_data[$i]['thumb'] = replace_image_path($json_data[$i]['thumb'], 'ss_carousel');

      $json_data[$i]['attribution'] = '';
      if (strlen(trim($json_data[$i]['creator']))) {
        $json_data[$i]['attribution'] = $json_data[$i]['creator'];
        if (strlen(trim($json_data[$i]['attribution']))) {
          $json_data[$i]['attribution'] = $json_data[$i]['attribution'].' | '.$json_data[$i]['copyright'];
        }
        else {
          $json_data[$i]['attribution'] = $json_data[$i]['copyright'];
        }
      }
      else {
        $json_data[$i]['attribution'] = $json_data[$i]['copyright'];
      }
      //$json_data[$i]['attribution'] = 'Max Dougan, Inc | Disney Productions, LLC';
    }

    $prev_node = get_prev_next($json_data[0]['Nid'], $json_data[0]['TermID'], "p", false);
    $next_node = get_prev_next($json_data[0]['Nid'], $json_data[0]['TermID'], "n", false);

    // if last/first slideshow in channel then loop back to first/last
    if (strlen($prev_node['link']) === 0) {
      $prev_node = get_prev_next($json_data[0]['Nid'], $json_data[0]['TermID'], "p", true);
    }
    if (strlen($next_node['link']) === 0) {
      $next_node = get_prev_next($json_data[0]['Nid'], $json_data[0]['TermID'], "n", true);
    }

    if (strlen($next_node['link']) != 0) {
      $prev_link = '<div id="previous"><a href="'.$next_node['link'].'"><img src="'.replace_image_path($next_node["img_path"], 'ss_prev_next').'" /></a><a href="'.$next_node['link'].'">'.$next_node["title"].'</a><a href="'.$next_node['link'].'">« Previous</a></div>';
    }
    else {
      $prev_link = '';
    }

    if (strlen($next_node['link']) != 0) {
      $next_link = '<div id="next"><a href="'.$prev_node['link'].'"><img src="'.replace_image_path($prev_node["img_path"], 'ss_prev_next').'" /></a><a href="'.$prev_node['link'].'">'.$prev_node["title"].'</a><a href="'.$prev_node['link'].'">Next »</a></div>';
    }
    else {
      $next_link = '';
    }

    $links = '<div id="prevNextLinks">'.$prev_link.$next_link.'</div><div class="clear-both">&nbsp</div>';
    $social_links= add_social_links_ss();

    $js = <<<EOD
      // On Document load
      jQuery(function () {
        loadSlideShowImages(1);
         galleryLink = slideshow[0].galleryLink.toLowerCase();
         jQuery(".anythingSlider").parent().prepend("$social_links<div id='fullscreenLink'><a href='" + replaceChannelPath(slideshow[0].fullscreenLink) + "'><img class='fullScreenLink' src='/sites/default/libraries/slideshow/images/icon_fullscreen.gif' />FULL SCREEN</a></div><div class='clear-both'>&nbsp;</div>");
      });
EOD;

    $addLinks = "jQuery(function () {jQuery(\"#slideshowBody\").parent().append(\"".str_replace('"', "'", $links)."\");});";

    drupal_add_js("var slideshow=".str_replace("'", '&apos;', json_encode($json_data)).';', 'inline');
    drupal_add_js($js, 'inline');
    drupal_add_js($addLinks, 'inline');

    $view['rows'] = ' ';
  }
}

/*
 * Slideshow Blackout View
 */
function maxim_base_alpha_preprocess_views_view__slideshow_json__slideshow_blackout_block(&$view) {
  drupal_add_js(libraries_get_path('slideshow') . '/jquery.colorbox.js');
  drupal_add_js(libraries_get_path('slideshow') . '/flowplayer-3.2.6.min.js');
  drupal_add_css(libraries_get_path('slideshow') . '/colorbox.css');
  drupal_add_css(libraries_get_path('slideshow') . '/slider.css');
  drupal_add_css(libraries_get_path('slideshow') . '/blackoutSlideshow.css');
  drupal_add_js(libraries_get_path('slideshow') . '/blackout_slideshow.js', array('scope' => 'footer'));

  $json_data = json_decode($view['rows'], TRUE);
  $initialSlide = (isset($_GET["slide"]) && is_numeric($_GET["slide"]) && ($_GET["slide"] > 0 && $_GET["slide"] < count($json_data)) === true ? $_GET["slide"] : 0);

  for($i = 0; $i < count($json_data); $i++) {
    if (strlen(trim($json_data[$i]['copy'])) === 0) {
      $json_data[$i]['copy'] = $json_data[$i]['body'];
    }

    $mediaType = determine_media_type(pathinfo($json_data[$i]['src'], PATHINFO_EXTENSION));

    // some dirty txt comes in with escaped html ex (&lt;b&gt; XXX &lt;/b&gt;)
    $json_data[$i]['title'] = str_replace('&gt;', '>', str_replace('&lt;', '<', $json_data[$i]['title']));

    $json_data[$i]['type'] = $mediaType;
    $json_data[$i]['src'] = replace_image_path($json_data[$i]['src']);
    $json_data[$i]['thumb'] = replace_image_path($json_data[$i]['thumb']);
    $json_data[$i]['type'] = $mediaType;
    $json_data[$i]['slide_title'] = ((strlen(trim($json_data[$i]['title'])) === 0) ? '' : '<div class="slideTitle">'.$json_data[$i]["title"].'</div>');

    $json_data[$i]['attribution'] = '';
    if (strlen(trim($json_data[$i]['creator']))) {
      $json_data[$i]['attribution'] = $json_data[$i]['creator'];
      if (strlen(trim($json_data[$i]['attribution']))) {
        $json_data[$i]['attribution'] = $json_data[$i]['attribution'].' | '.$json_data[$i]['copyright'];
      }
      else {
        $json_data[$i]['attribution'] = $json_data[$i]['copyright'];
      }
    }
    else {
      $json_data[$i]['attribution'] = $json_data[$i]['copyright'];
    }
    //$json_data[$i]['attribution'] = 'Max Dougan, Inc | Disney Productions, LLC';
  }

  if (count($json_data) > 0) {
    $ss_title = '<div id ="ss_title"><h1>'.$json_data[0]["ssTitle"].'</h1></div>';
    $prev = '<span id="prev" class="lnk"><img src="/sites/default/libraries/jumbotron/images/lt_arrow.png"></span>';
    $next = '<span id="next" class="lnk"><img src="/sites/default/libraries/jumbotron/images/rt_arrow.png"></span>';
    $main_ss_link = '<div class="ssLink closeLnk"><a href="'.url('node/'.$json_data[0]['Nid']).'">CLOSE <img src="/'.libraries_get_path('slideshow').'/images/close.png'.'" width="24" height="24"/></a></div>';
    $gallery_link = '<div class="ssLink thumbnailLnk"><a href="'.strtolower($json_data[0]["galleryLink"]).'"> <img src="/'.libraries_get_path('slideshow').'/images/icon_thumbnail.png'.'"/> Thumbnail view</a></div>';

    $prev_node = get_prev_next($json_data[0]['Nid'], $json_data[0]['TermID'], "p", false);
    $next_node = get_prev_next($json_data[0]['Nid'], $json_data[0]['TermID'], "n", false);

    // if last/first slideshow in channel then loop back to first/last
    if (strlen($prev_node['link']) === 0) {
      $prev_node = get_prev_next($json_data[0]['Nid'], $json_data[0]['TermID'], "p", true);
    }
    if (strlen($next_node['link']) === 0) {
      $next_node = get_prev_next($json_data[0]['Nid'], $json_data[0]['TermID'], "n", true);
    }
    $prevNextJS = 'var prev_ss_link = "/slideshow/'.$json_data[0]['channel'].'/'.$prev_node["nid"].'"; var next_ss_link = "/slideshow/'.$json_data[0]['channel'].'/'.$next_node["nid"].'";';

  }
  else {
    $ss_title = '';
    $prev = '';
    $next = '';
    $main_ss_link = '';
    $gallery_link = '';
    $prevNextJS = '';
  }
  drupal_add_js($prevNextJS, 'inline');

  // special case where first thumbnail is a video
  if (count($json_data) > 0) {
    $slideNum = $initialSlide + 1;
    $nav = "<div id='nav'>$prev$next</div>";
    if (determine_media_type(pathinfo($json_data[$initialSlide]['src'], PATHINFO_EXTENSION)) === 'video') {
      $dImage = "<div id='dImage' class='clearfix'><img id='dispImage' src='' /></div>";
      $displInitialVideo = "jQuery('#dImage').hide(); jQuery('#vp').show(); flowplayer().play(slideShow[".$initialSlide."]['src']); //flowplayer().stop();";
    }
    else {
      $dImage = "<div id='dImage' class='clearfix'><img id='dispImage' src='".replace_image_path($json_data[$initialSlide]['src'])."' /></div>";
      $displInitialVideo = '';
    }
    $slideTitle = $json_data[$initialSlide]['slide_title'];
    $slideCopy = $json_data[$initialSlide]['copy'];
    $slideAttribution = "<div class='attribution'>".$json_data[$initialSlide]['attribution']."</div>";
    $slideTxt = "<div style='display:none'><div id='pop'>".$slideTitle . $slideCopy."</div></div>";
    $slideCount = '<div id="slideCount">' . $slideNum .' of ' . count($json_data) . '</div>';

    $slide_teaser_text = wordwrap(str_replace('<', ' <', $slideCopy), 100, '~~');
    $slide_teaser_text = explode('~~', $slide_teaser_text);
    $slide_teaser_text = $slide_teaser_text[0] . '...';
    $slide_teaser_text = '<div id="slide-teaser-text">'. strip_tags($slideTitle) . strip_tags($slide_teaser_text).'<a href="#" onclick="openColorbox();">[read more]</a></div>';

    $setupVars = "var currIndex = ".$initialSlide."; slideShow=".json_encode($json_data).";";
  }
  else {
    $nav = '';
    $dImage = '';
    $displInitialVideo = '';
    $slideTitle = '';
    $slideCopy = '';
    $slideTxt = '';
    $setupVars = '';
    $slideCount = '';
    $slide_teaser_text = '';
  }

  // click image will go to next image
  $imgNext = "jQuery('#dispImage').click(function() { jQuery('#next').trigger('click'); });";
  // Slide Ad
  $slideAd = '';
  variable_set('dart_load_last', '1');
  //$slideAd = '<div id="slideAd">' . dart_tag('dart_big_box') . '</div>';

  $flowPlayerHTML = "<div id='dVideo' class='clearfix'><a href='' class='videoplayer' id='vp' style='display:none;'></a></div>";
  $html = '<div class="slideshow-links">'.$gallery_link.$main_ss_link.'</div>'.$ss_title.'<div class="clearfix"></div><div id="slideshowFull" class="clearfix">'.$nav.$slideTxt.$slideAd.$flowPlayerHTML.$dImage.$slideAttribution.$slide_teaser_text.$slideCount.'</div>';

  drupal_add_js($setupVars.$displInitialVideo.$imgNext, array('type' => 'inline', 'scope' => 'footer'));

  $view['rows'] = $html;
}

/*
 * Slideshow Gallery View
 */
function maxim_base_alpha_preprocess_views_view__slideshow_json__slideshow_gallery_block(&$view) {
  $imgCount = 0;
  $vidCount = 0;
  $strCount = '';

  drupal_add_css(libraries_get_path('slideshow') . '/slideshowGallery.css');

  $arSlides = $view['view']->result;
  for ($i = 0; $i < count($arSlides); $i++){
    $mimeType = $arSlides[$i]->field_field_slides[0]['raw']['filemime'];
    if (strpos($mimeType, 'image') !== false){
      $imgCount++;
    } else if (strpos($mimeType, 'video') !== false) {
      $vidCount++;
    }
  }

  if($imgCount > 0){
    $strCount .= $imgCount . ' image';
    if($imgCount > 1){ $strCount .= 's';}
  }
  if(strlen($strCount) > 0 && $vidCount > 0){ $strCount .= ', '; }
  if($vidCount > 0){
    $strCount .= $vidCount . ' video';
    if($vidCount > 1){ $strCount .= 's'; }
  }

  $main_ss_link = '<div class="closeLnk"><a href="'.url('node/'.$view['view']->argument['nid']->value[0]).'">CLOSE <img src="/'.libraries_get_path('slideshow').'/images/close.png'.'" width="24" height="24"/></a></div>';

  $ss_links = '<div class="slideshow-links">' . $main_ss_link . '</div>';

  // add the slide number to the url & replace video images with default thumbnails
  $gallery_link = <<<EOD
    function replaceChannelPath(path) {
      var str  = (typeof path === 'undefined') ? '' : path;

      if (str.length > 0) {
        str = path.replace(/\s/g , "-");
        str = str.replace('&#039;', '');
        str = str.replace('%27', '');
        str = str.replace('%20', '-');
      }

      return(str.toLowerCase());
    }

    jQuery('.galleryImg').each(function(index) {
      currLnk = jQuery(this).parent().attr('href');
      jQuery(this).parent().attr('href', replaceChannelPath(currLnk)+index);

      if ((this.src.indexOf('.flv') != -1) || (this.src.indexOf('.mp4') != -1)) {
        this.src = 'http://cdn2.maxim.com/maximonline/assets/video_1.jpg';
        this.height = '197';
      }
    });
EOD;

  $html = replace_image_path($view['rows']);
  drupal_add_js($gallery_link, array('type' => 'inline', 'scope' => 'footer'));

  $view['rows'] = $ss_links . '<div class="slideCount">' . $strCount . '</div>' . replace_image_path($html, 'ss_gallery');
}

/*
 * retrives the previous or next node given  a node/channel combo
 */
function get_prev_next($currentNode = NULL, $channelID = NULL, $op = 'p', $no_result = false) {
  if ($op === 'p') {
    if ($no_result === true) {
       $sql_op = '>';
    }
    else {
      $sql_op = '<';
    }
    $no_result_sql_op = '>';
    $order = 'DESC';
  }
  elseif ($op == 'n') {
    if ($no_result === true) {
      $sql_op = '<';
    }
    else {
      $sql_op = '>';
    }
    $order = 'ASC';
  }
  else {
    return NULL;
  }

  $output = NULL;
  $sql_select = 'SELECT n.nid, n.title ';
  $sql_from = 'FROM node n, taxonomy_index t ';
  $sql_where = 'WHERE n.nid = t.nid AND n.created '.$sql_op.' (SELECT created FROM node WHERE nid = '.$currentNode. ') AND t.tid='.$channelID.' AND type IN (\'slideshow\') AND status = 1 ';
  $sql_order = 'ORDER BY n.created '.$order.' LIMIT 1';
  $sql = $sql_select.$sql_from.$sql_where.$sql_order;

  $result = db_query($sql, array(':nid' => $currentNode));
  foreach ($result as $data) {}

  $node_data = array();
  if (isset($data)) {
    $node = get_node_data($data->nid);
    $node_data['img_path'] = $node['img_path'];
    $node_data['title'] = $node['title'];
    $node_data['link'] = url("node/$data->nid");
    $node_data['nid'] = $data->nid;
  }
  else {
    $node_data['img_path'] = '';
    $node_data['title'] = '';
    $node_data['link'] = '';
    $node_data['nid'] = '';
  }

  return($node_data);
}

/*
 * retrives main image path & title from a node
 */
function get_node_data($nid) {
  $return_value = array();

  $node = node_load($nid);
  if (count($node->field_main_image) > 0) {
    $image_path = file_create_url($node->field_main_image['und'][0]['uri']);
    $return_value['img_path'] = replace_image_path($image_path);
  }
  else {
    $return_value['img_path'] = '';
  }
  $return_value['title'] = $node->title;

  return($return_value);
}

/*
 * Determine the media file type based on file extension.
 */
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

/*
 * Replace local file paths with CDN path.
 */
function replace_image_path($file, $style_type = '', $replace_local_images = true) {
  //quick and dirty fix to get images displayed on local machines without having to have content stored locally
  if ($replace_local_images  === true) {
    $file = str_replace('localhost.maxim', 'maximdev.prod.acquia-sites', $file);
  }

  //image styling paths
  if ($style_type == 'ss_prev_next') {
    $file = str_replace('/default/files/', '/default/files/styles/thumbnail_medium/public/', $file);
  }
  elseif ($style_type == 'ss_carousel') {
    $file = str_replace('/default/files/', '/default/files/styles/carousel_icon/public/', $file);
  }
  elseif ($style_type == 'ss_main') {
    $file = str_replace('/default/files/', '/default/files/styles/carousel_main/public/', $file);
  }
  elseif ($style_type == 'ss_gallery') {
    $file = str_replace('/default/files/', '/default/files/styles/thumbnail_gallery/public/', $file);
  }
  elseif ($style_type == 'ss_blackout_main') {
    $file = str_replace('/default/files/', '/default/files/styles/slideshow_large/public/', $file);
  }

  return($file);
}

/*
 * Setup A-Z glossary links for views configured to be a glossary.
 */
function setup_girls_of_maxim_glossary(&$view) {
  drupal_add_css(libraries_get_path('girls_of_maxim') . '/gallery_view.css');

  $glossary_letter = ((count($view['view']->args) > 0)) ? strtolower($view['view']->args[0]) : '';
  $all_class = ((strlen($glossary_letter) === 0) || ($glossary_letter == 'all')) ? ' class="selected-letter" ' : ' ';
  $num_class = ((count($view['view']->args) > 0) && (strpos($view['view']->args[0], '8') > 0)) ? ' class="selected-letter" ' : ' ';
  $glossary = '<ul><li><a'.$all_class.'href="/girls/girls-of-maxim/all">ALL</a></li><li><a'.$num_class.'href="/girls/girls-of-maxim/0+1+2+3+4+5+6+7+8+9">#</a></li>';

  foreach(range('a', 'z') as $letter) {
    if ($letter == $glossary_letter) {
      $glossary = $glossary.'<li><a class="selected-letter" href="/girls/girls-of-maxim/'.$letter.'">'.strtoupper($letter).'</a></li>';
    }
    else {
      $glossary = $glossary.'<li><a href="/girls/girls-of-maxim/'.$letter.'">'.strtoupper($letter).'</a></li>';
    }
  }
  $glossary = $glossary.'</ul>';

  $js = 'jQuery(function () {jQuery("#alpha_list").html('.'\''.$glossary.'\');});';
  drupal_add_js($js, array('type' => 'inline', 'scope' => 'footer'));
}

function add_social_links_ss() {
  $fb_link = "<div class='fb-like' data-send='false' data-layout='button_count' data-width='450' data-show-faces='false'></div>";

  $twitter_link = "<a href='https://twitter.com/share' class='twitter-share-button'>Tweet</a>";
  $twitter_js = '!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");';

  drupal_add_js($twitter_js, array('type' => 'inline', 'scope' => 'footer'));

 return("<div class='social-links-no-byline'>".$fb_link.$twitter_link."</div>");
}
