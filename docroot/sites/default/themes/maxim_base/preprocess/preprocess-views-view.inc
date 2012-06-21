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

function maxim_base_alpha_preprocess_views_view__hometown_hotties_2013(&$view) {
  drupal_add_css(libraries_get_path('hth') . '/hth_gallery.css', array('group' => CSS_DEFAULT,'preprocess'=> FALSE, 'every_page' => FALSE));
  drupal_add_css(drupal_get_path('theme', 'maxim_base') . '/css/hometown-hotties.css', array('group' => CSS_THEME, 'every_page' => FALSE));

  // there's a probably a better weay to do this
  $path_elems = explode("/", $_SERVER['REQUEST_URI']);
  $hottie_week = str_replace('week', '', $path_elems [sizeof($path_elems)-1]);
  $hottie_year = $path_elems [sizeof($path_elems)-2];

  drupal_add_js(array('Maxim' => array('hottie' => array('hottie_year' => $hottie_year))), 'setting');
  drupal_add_js(array('Maxim' => array('hottie' => array('hottie_week' => $hottie_week))), 'setting');
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
  setup_girls_of_maxim_glossary($view);
}

function maxim_base_alpha_preprocess_views_view__channel__girls_girls_of_maxim_glossary(&$view) {
  setup_girls_of_maxim_glossary($view);
}

function maxim_base_alpha_preprocess_views_view__hot_100_2012(&$view) {
  drupal_add_css(libraries_get_path('hot_100') . '/hot100_view.css');
}

function maxim_base_alpha_preprocess_views_view__hub_landing_pages(&$view) {
  drupal_add_css(drupal_get_path('theme', 'maxim_base') . '/css/hub_landing_page.css', array('group' => CSS_DEFAULT,'preprocess'=> FALSE, 'every_page' => FALSE));
}

/*
 * Preprocess for Hometown Hotties Slider.
 * Custom ajax pager
 */
function maxim_base_alpha_preprocess_views_view__hometown_hotties_slider(&$view) {
  $total_count = $view['view']->total_rows;
  $num_per_page = $view['view']->query->limit;
  $first_pos = $view['view']->result[0]->nodequeue_nodes_node_position;
  $active_pg = ($first_pos-1)/$num_per_page;
  $pager = '<div class="item-list"><ul class="pager clearfix">';
  $num_pages = ceil($total_count/$num_per_page);

  $sliderJS = array('hottie');
  $sliderJS['hottie'] = array('slider_show_max' => $num_per_page);
  drupal_add_js(array('Maxim' => $sliderJS), 'setting');

  for ($i=0; $i < $num_pages; $i++) {
    if ($total_count > $i*$num_per_page+$num_per_page) {
      $end_page = $i*$num_per_page+$num_per_page;
    } else {
      $end_page = $total_count;
    }
    $pager .= '<li class="pager-item">';
    if ($i == $active_pg){
      $pager .= '<span class="active">' . ($i*$num_per_page+1) . '-' . $end_page . '</span>';
    } else {
      $pager .= '<a href="?page='. $i .'" onclick="hottieLoading(' . $i . ')">' . ($i*$num_per_page+1) . '-' . $end_page . '</a></li>';
    }
    if ($i != $num_pages-1) {
      $pager .= '<li> | </li>';
    }
  }
  $pager .= '</ul></div>';
  //$pager .= '<div class="slider-nextprev">';
  if ($active_pg > 0) {
    $pager .= '<div class="slider-prev item-list"><ul class="pager"><li class="pager-prev"><a href="?page=' . ($active_pg-1)  . '" onclick="hottieLoading();"> </a></li></ul></div>';
  }
  if ($active_pg < $num_pages-1) {
    $pager .= '<div class="slider-next item-list"><ul class="pager"><li class="pager-next"><a href="?page=' . ($active_pg+1) . '" onclick="hottieLoading();"> </a></li></ul></div>';
  }
  $pager .= '<div class="slider-loading">L O A D I N G . . .</div>';
  $pager .= '<script>hottieSliderLoader();</script>';
  $view['pager'] = $pager;
}

function maxim_base_alpha_preprocess_views_view__hotties2013(&$view) {
  drupal_add_css(drupal_get_path('theme', 'maxim_base') . '/css/hotties-admin.css', array('group' => CSS_THEME, 'every_page' => FALSE));
  drupal_add_js(drupal_get_path('theme', 'maxim_base') . '/js/hotties-admin.js', array('every_page' => FALSE));
  drupal_add_library('system', 'drupal.collapse');
  drupal_add_css(libraries_get_path('slideshow') . '/colorbox.css');
  drupal_add_js(libraries_get_path('slideshow') . '/jquery.colorbox.js');

  $select_options = array('UNSLOTTED','YES','NO','MAYBE');
  $contest_week = array('NOT ASSIGNED','WEEK 1','WEEK 2','WEEK 3','WEEK 4','WEEK 5');

  $out = '<div class="hottie-admin">';
  for ($i=0; $i < count($view['view']->result); $i++) {
    $view_results = $view['view']->result[$i];

    $pic1 = replace_image_path(get_file_data($view_results->webform_submissions_webform_hometown_hotties_2013_36876__web_7));
    $pic2 = replace_image_path(get_file_data($view_results->webform_submissions_webform_hometown_hotties_2013_36876__web_8));
    $pic3 = replace_image_path(get_file_data($view_results->webform_submissions_webform_hometown_hotties_2013_36876__web_9));
    $email = $view_results->webform_submissions_webform_hometown_hotties_2013_36876__web_3;

    $sub_id = $view_results->webform_submissions_webform_hometown_hotties_2013_36876__web;
    $complete_submission = '/node/36876/submission/'.$sub_id;

    $name = $view_results->webform_submissions_webform_hometown_hotties_2013_36876__web_1.' '.$view_results->webform_submissions_webform_hometown_hotties_2013_36876__web_2;
    $dob = $view_results->webform_submissions_webform_hometown_hotties_2013_36876__web_4;

    $current_slot = $view_results->webform_submissions_webform_hometown_hotties_2013_36876__web_6;
    if (strlen($current_slot) === 0) {
      $current_slot = 'unslotted';
    }

    $current_week = $view_results->webform_hometown_hotties_2013_36876_contest_week;
    if (strlen($current_week) === 0) {
      $current_week = 'Not Assigned';
    }

    $pic4 = replace_image_path(get_file_data($view_results->webform_submissions_webform_hometown_hotties_2013_36876__web_10));
    $pic5 = replace_image_path(get_file_data($view_results->webform_submissions_webform_hometown_hotties_2013_36876__web_11));
    $pic6 = replace_image_path(get_file_data($view_results->webform_submissions_webform_hometown_hotties_2013_36876__web_12));
    $pic7 = replace_image_path(get_file_data($view_results->webform_submissions_webform_hometown_hotties_2013_36876__web_13));
    $pic8 = replace_image_path(get_file_data($view_results->webform_submissions_webform_hometown_hotties_2013_36876__web_14));
    $pic9 = replace_image_path(get_file_data($view_results->webform_submissions_webform_hometown_hotties_2013_36876__web_15));
    $pic10 = replace_image_path(get_file_data($view_results->webform_submissions_webform_hometown_hotties_2013_36876__web_16));

    $out .= '<ul>';
    $out .= '<li class="name"><span class="label">Name: </span>'.$name.'</li>';;
    $out .= '<li class="dob"><span class="label">DoB: </span>'.$dob.'</li>';
    $out .= '<li class="email"><span class="label">Email: </span><a href="mailto:'.$email.'">'.$email.'</a></li>';
    $out .= '<li class="view-all"><span class="label"></span><a href="'.$complete_submission.'" target="_new">View Complete Submission</a></li></ul>';
    $out .= '<div class="clear2">&nbsp;</div>';
    $out .= '<div class="pic"><img onclick="javascript:call_cbox(this);" src="'.$pic1.'"/></div>';
    $out .= '<div class="pic"><img onclick="javascript:call_cbox(this);" src="'.$pic2.'"/></div>';
    $out .= '<div class="pic last"><img onclick="javascript:call_cbox(this);" src="'.$pic3.'"/></div>';
    $out .= '<div class="clear-no-bar">&nbsp</div>';

    $small_pics = '<div class="sm-pic"><img onclick="javascript:call_cbox(this);" src="'.$pic4.'"/></div>';
    $small_pics .= '<div class="sm-pic"><img onclick="javascript:call_cbox(this);" src="'.$pic5.'"/></div>';
    $small_pics .= '<div class="sm-pic"><img onclick="javascript:call_cbox(this);" src="'.$pic6.'"/></div>';
    $small_pics .= '<div class="sm-pic"><img onclick="javascript:call_cbox(this);" src="'.$pic7.'"/></div>';
    $small_pics .= '<div class="sm-pic"><img onclick="javascript:call_cbox(this);" src="'.$pic8.'"/></div>';
    $small_pics .= '<div class="sm-pic"><img onclick="javascript:call_cbox(this);" src="'.$pic9.'"/></div>';
    $small_pics .= '<div class="sm-pic"><img onclick="javascript:call_cbox(this);" src="'.$pic10.'"/></div>';

    $collapsible_fs = '<fieldset class="collapsible collapsed"><legend><span class="fieldset-legend">Additional Photos</span></legend><div class="fieldset-wrapper">'.$small_pics.'</div></fieldset>';

    // Setup selectbox for slotting
    $options = '<div class="styled-select"><select onchange="javascript:slot_hottie('.$sub_id.',this.options[this.selectedIndex].innerHTML)" class="hottie-select">';
    for ($j=0; $j<count($select_options); $j++) {
      if ($current_slot === strtolower($select_options[$j])) {
        $display_weeks = false;
        if ($current_slot === 'yes') {
          $display_weeks = true;
        }
        $options .= '<option selected="selected">'.$select_options[$j].'</option>';
      }
      else {
        $options .= '<option>'.$select_options[$j].'</option>';
      }
    }
    $options .= '</select><img id="status-s-'.$sub_id.'" class="status-img" src="/'.drupal_get_path('theme', 'maxim_base').'/images/green-check-circle.jpeg"/><img id="status-f-'.$sub_id.'" class="status-img" src="/'.drupal_get_path('theme', 'maxim_base').'/images/red-x-circle.jpeg"></div>';

    // Setup selectbox for week selection
    $display_class = ($display_weeks) ? 'visible' : 'hidden';

    $weeks = '<div class="styled-select '.$display_class.'" id="dw'.$sub_id.'"><select onchange="javascript:slot_week('.$sub_id.', \'yes\', this.options[this.selectedIndex].innerHTML)" class="hottie-select">';
    for ($j=0; $j<count($contest_week); $j++) {
      if ($current_week === strtolower($contest_week[$j])) {
        $weeks .= '<option selected="selected">'.$contest_week[$j].'</option>';
      }
      else {
        $weeks .= '<option>'.$contest_week[$j].'</option>';
      }
    }
    $weeks .= '</select><img id="week-s-'.$sub_id.'" class="status-img" src="/'.drupal_get_path('theme', 'maxim_base').'/images/green-check-circle.jpeg"/><img id="week-f-'.$sub_id.'" class="status-img" src="/'.drupal_get_path('theme', 'maxim_base').'/images/red-x-circle.jpeg"></div>';

    $out .= $collapsible_fs.$options.$weeks.'<div class="clear">&nbsp</div>';
  }
  $out .= '</div>';

  $view['rows'] = $out;
}

/*
 * Regular Slideshow
 */
function maxim_base_alpha_preprocess_views_view__slideshow_json__json_slideshow_block(&$view) {
  drupal_add_js(libraries_get_path('slideshow') . '/flowplayer-3.2.9.min.js');
  drupal_add_js(libraries_get_path('slideshow') . '/flowplayer.ipad-3.2.9.min.js');
  drupal_add_js(libraries_get_path('slideshow').'/jquery.anythingslider.js');
  drupal_add_js(libraries_get_path('slideshow').'/jquery.easing.1.2.js');
  drupal_add_js(libraries_get_path('slideshow').'/slideshow_display.js');
  drupal_add_css(libraries_get_path('slideshow').'/slider.css');
  drupal_add_css(libraries_get_path('slideshow').'/main_slideshow.css');


  $json_data = json_decode($view['rows'], TRUE);

  if (count($json_data) > 0) {
    $hidden_body_txt = '<div id="hide-ss-text"><p class="slide-text-body">'.$json_data[0]['body'].'</p>';
    for($i = 0; $i < count($json_data); $i++) {
      if ((strlen(trim($json_data[$i]['title'])) > 0) && (strlen(trim($json_data[$i]['copy'])) > 0)) {
        $hidden_body_txt .= '<p class="title-plus-copy">'.$json_data[$i]['title'].'-'.$json_data[$i]['copy'].'</p>';
      }
      elseif (strlen(trim($json_data[$i]['copy'])) > 0) {
        $hidden_body_txt .= '<p class="copy-only">'.$json_data[$i]['copy'].'</p>';
      }
      elseif (strlen(trim($json_data[$i]['title'])) > 0) {
        $hidden_body_txt .= '<p class="title-only">'.$json_data[$i]['title'].'</p>';
      }

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
    }
    $hidden_body_txt .= '</div>';

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
        loadSlideShowImages();
         galleryLink = slideshow[0].galleryLink.toLowerCase();
         jQuery(".anythingSlider").parent().prepend("$social_links<div id='fullscreenLink'><a href='" + replaceChannelPath(slideshow[0].fullscreenLink) + "'><img class='fullScreenLink' src='/sites/default/libraries/slideshow/images/icon_fullscreen.gif' />FULL SCREEN</a></div><div class='clear-both'>&nbsp;</div>");
      });
EOD;

    $addLinks = "jQuery(function () {jQuery(\"#slideshowBody\").parent().append(\"".str_replace('"', "'", $links)."\");});";

    drupal_add_js("var slideshow=".str_replace("'", '&apos;', json_encode($json_data)).';', 'inline');
    drupal_add_js($js, 'inline');
    drupal_add_js($addLinks, 'inline');

    $view['rows'] = $hidden_body_txt;
  }
}

/*
 * Slideshow Blackout View
 */
function maxim_base_alpha_preprocess_views_view__slideshow_json__slideshow_blackout_block(&$view) {
  drupal_add_js(libraries_get_path('slideshow') . '/jquery.colorbox.js');
  drupal_add_js(libraries_get_path('slideshow') . '/flowplayer-3.2.9.min.js');
  drupal_add_js(libraries_get_path('slideshow') . '/flowplayer.ipad-3.2.9.min.js');
  drupal_add_css(drupal_get_path('theme', 'maxim_base') . '/css/typography.css', array('group' => CSS_THEME, 'every_page' => TRUE));
  drupal_add_css(libraries_get_path('slideshow') . '/colorbox.css');
  drupal_add_css(libraries_get_path('slideshow') . '/slider.css');
  drupal_add_css(libraries_get_path('slideshow') . '/blackoutSlideshow.css');
  drupal_add_js(libraries_get_path('slideshow') . '/blackout_slideshow.js', array('scope' => 'footer'));
  drupal_add_css($ss_lib_path.'/slider.css');

  $channel = null;
  $json_data = json_decode($view['rows'], TRUE);
  $initialSlide = (isset($_GET["slide"]) && is_numeric($_GET["slide"]) && ($_GET["slide"] > 0 && $_GET["slide"] < count($json_data)) === true ? $_GET["slide"] : 0);

  for($i = 0; $i < count($json_data); $i++) {
    if (strlen(trim($json_data[$i]['copy'])) === 0) {
      $json_data[$i]['copy'] = $json_data[$i]['body'];
    }
    // Get Channel for slideshow and set to Drupal.setting JavaScript
    if ($channel === null && array_key_exists('TermID', $json_data[$i])) {
      $channel = $json_data[$i]['TermID'];
      $maxim_vars = array();
      $maxim_vars['channel'] = array();
      $arChannel = taxonomy_get_parents_all($json_data[$i]['TermID']);
      foreach($arChannel as $ch){
        array_unshift($maxim_vars['channel'], $ch->name);
      }
      if (count($maxim_vars)) {
        drupal_add_js(array('Maxim' => $maxim_vars), 'setting');
      }
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
  }

  if (count($json_data) > 0) {
    $meta_element = array();
    $ss_title = '<div id ="ss_title"><h1>'.$json_data[0]["ssTitle"].'</h1></div>';
    $prev = '<span id="prev" class="lnk"><img src="/sites/default/libraries/jumbotron/images/lt_arrow.png"></span>';
    $next = '<span id="next" class="lnk"><img src="/sites/default/libraries/jumbotron/images/rt_arrow.png"></span>';
    $main_ss_link = '<div class="ssLink closeLnk"><a href="'.url('node/'.$json_data[0]['Nid']).'">CLOSE <img src="/'.libraries_get_path('slideshow').'/images/close.png'.'" width="24" height="24"/></a></div>';
    $gallery_link = '<div class="ssLink thumbnailLnk"><a href="'.strtolower($json_data[0]["galleryLink"]).'"> <img src="/'.libraries_get_path('slideshow').'/images/icon_thumbnail.png'.'"/> Thumbnail view</a></div>';
    $meta_element = array(
        '#tag' => 'link', // The #tag is the html tag - <link />
        '#attributes' => array( // Set up an array of attributes inside the tag
        'rel' => 'canonical',
        'href' => 'http://www.maxim.com' . url('node/'.$json_data[0]['Nid']),
      ),
    );
    drupal_add_html_head($meta_element, 'maximmeta_canonical');
    // Button Ad
    $small_ad = '<div class="ss_ad_button">' . dart_tag('dart_full_ss_button') . '</div>';

    //get prev next from nodequeues
    $taxonomy_term = taxonomy_term_load($channel);
    $hth = node_load(get_hth_from_ss($json_data[0]['Nid']));
    if (($channel != null) && (($taxonomy_term->name === 'Hometown Hotties') || is_profile_gamer_girl($hth))) {
      // we need to get the hth_nid connected to the current slideshow in order to process prev/next from the NQs
      $hottie_week = taxonomy_term_load($hth->field_hotties_contest_week[LANGUAGE_NONE][0]['tid'])->name;
      $hottie_year = taxonomy_term_load($hth->field_hotties_contest_year[LANGUAGE_NONE][0]['tid'])->name;

      $nodequeue_pos = get_nqueue_pos($hth, $hottie_year, $hottie_week);
      $nodequeue_links = get_hth_next_prev($hth, $hottie_year, $hottie_week, $nodequeue_pos);

      // if post-2013 - we need to do the reverse of above and get the slideshows associated with the hth_nid
      if ($hottie_year >= 2013) {
        $prev_node['nid'] = get_ss_from_hth($nodequeue_links['prev_nid']);
        $next_node['nid'] = get_ss_from_hth($nodequeue_links['next_nid']);
      }
      else {
        $prev_node['nid'] = $nodequeue_links['prev_nid'];
        $next_node['nid'] = $nodequeue_links['next_nid'];
      }
    }
    else {
      $prev_node = get_prev_next($json_data[0]['Nid'], $json_data[0]['TermID'], "p", false);
      $next_node = get_prev_next($json_data[0]['Nid'], $json_data[0]['TermID'], "n", false);

      //special case of only 1 slideshow (no prev/next)
      if ((strlen($prev_node['link']) === 0) && (strlen($next_node['link']) === 0)) {
        $prev_node["nid"] = $json_data[0]['Nid'];
        $next_node["nid"] = $json_data[0]['Nid'];
      }
      else {
        // if last/first slideshow in channel then loop back to first/last
        if (strlen($prev_node['link']) === 0) {
          $prev_node = get_prev_next($json_data[0]['Nid'], $json_data[0]['TermID'], "p", true);
        }
        if (strlen($next_node['link']) === 0) {
          $next_node = get_prev_next($json_data[0]['Nid'], $json_data[0]['TermID'], "n", true);
        }
      }
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
    $small_ad = '';
  }
  drupal_add_js($prevNextJS, 'inline');

  // special case where first thumbnail is a video
  if (count($json_data) > 0) {
    $slideNum = $initialSlide + 1;
    $nav = "<div id='nav'>$prev$next</div>";
    if (determine_media_type(pathinfo($json_data[$initialSlide]['src'], PATHINFO_EXTENSION)) === 'video') {
      $dImage = "<div id='dImage' class='clearfix'><img id='dispImage' src='' /></div>";
      $displInitialVideo = "jQuery('#dImage').hide(); jQuery('#dVideo a').addClass('firstVideo'); jQuery('#dVideo').show(); flowplayer().play(slideShow[".$initialSlide."]['src']); //flowplayer().stop();";
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
    $slide_teaser_text = '<div id="slide-teaser-text">'. strip_tags($slideTitle) . "<br/>" . strip_tags($slide_teaser_text).'<a href="#" onclick="openColorbox();">[read more]</a></div>';

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
  $slideAd = '<div id="slideAd"><span class="slug">Advertisement</span>' . dart_tag('dart_full_slideshow') . '</div>';

  $flowPlayerHTML = "<div id='dVideo' class='clearfix' style='display:none;'><a href='' class='videoplayer' id='vp'></a></div>";
  $html = '<div class="slideshow-links">'.$small_ad.$gallery_link.$main_ss_link.'</div>'.$ss_title.'<div class="clearfix"></div><div id="slideshowFull" class="clearfix">'.$nav.$slideTxt.$slideAd.$flowPlayerHTML.$dImage.$slideAttribution.$slide_teaser_text.$slideCount.'</div>';

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
  $arSlides = array();
  $meta_element = array();

  drupal_add_css(libraries_get_path('slideshow') . '/slideshowGallery.css');

  for ($i = 0; $i < count($arSlides); $i++){
    $arSlides = $view['view']->result;
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
  $meta_element = array(
    '#tag' => 'link', // The #tag is the html tag - <link />
    '#attributes' => array( // Set up an array of attributes inside the tag
      'rel' => 'canonical',
      'href' => 'http://www.maxim.com' . url('node/'.$view['view']->argument['nid']->value[0]),
    ),
  );
  drupal_add_html_head($meta_element, 'maximmeta_canonical');
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
        str = str.replace(/%20/g, '-');

      }

      return(str.toLowerCase());
    }

    jQuery('.galleryImg').each(function(index) {
      currLnk = jQuery(this).parent().attr('href');
      slideLink = replaceChannelPath(currLnk);
      if (slideLink.indexOf('?slide=') != -1) {
        slideLink += index;
      } else {
        slideLink += '?slide=' + index;
      }
      jQuery(this).parent().attr('href', slideLink);

      if ((this.src.indexOf('.flv') != -1) || (this.src.indexOf('.mp4') != -1)) {
        this.src = 'http://cdn2.maxim.com/maximonline/assets/video_1.jpg';
        this.height = '197';
      }
    });
EOD;

  $html = replace_image_path($view['rows']);
  drupal_add_js($gallery_link, array('type' => 'inline', 'scope' => 'footer'));

  $view['rows'] = $ss_links . '<div class="slideCount">' . $strCount . '</div>' . replace_image_path($html, 'ss_gallery', true, true);
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
  $sql_where = 'WHERE n.nid = t.nid AND n.created '.$sql_op.' (SELECT created FROM node WHERE nid = :nid) AND t.tid= :tid AND type IN (\'slideshow\') AND status = 1 ';
  $sql_order = 'ORDER BY n.created '.$order.' LIMIT 1';
  $sql = $sql_select.$sql_from.$sql_where.$sql_order;
  $params = array(':nid' => $currentNode, ':tid' => $channelID);
  $result = db_query($sql, $params);

  foreach ($result as $data) {
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
    $image_path = file_create_url($node->field_main_image[LANGUAGE_NONE][0]['uri']);
    $return_value['img_path'] = replace_image_path($image_path);
  }
  else {
    $return_value['img_path'] = '';
  }
  $return_value['title'] = $node->title;

  return($return_value);
}

function get_file_data($fid) {
  $file = file_load($fid);
  if (strlen($file->uri) > 0) {
    return(file_create_url($file->uri));
  }
  else {
    return('');
  }
}

/*
 * Determine the media file type based on file extension.
 */
function determine_media_type($file_extension) {
  $image_types = array('jpg', 'png', 'gif', 'jpeg');
  $video_types = array('flv', 'mp4');

  if (in_array(strtolower($file_extension), $image_types)) {
    return ('image');
  }
  elseif (in_array(strtolower($file_extension), $video_types)) {
    return ('video');
  }
}

/*
 * Replace local file paths with CDN path.
 */
function replace_image_path($file, $style_type = '', $replace_local_images = true, $is_image_gallery = false) {
  //quick and dirty fix to get images displayed on local machines without having to have content stored locally
  /*
  if ($replace_local_images  === true) {
    $file = str_replace('localhost.maxim', 'maximdev.prod.acquia-sites', $file);
  }
  */

  //image styling paths
  if ((determine_media_type(pathinfo($file, PATHINFO_EXTENSION)) === 'image') || ($is_image_gallery === true)) {
    if ($style_type == 'ss_prev_next') {
      $file = str_replace('/default/files/', '/default/files/styles/thumbnail_medium/public/', $file);
    }
    elseif ($style_type == 'ss_carousel') {
      $file = str_replace('/default/files/', '/default/files/styles/carousel_icon/public/', $file);
    }
    elseif ($style_type == 'ss_carousel_watermark') {
      $file = str_replace('/default/files/', '/default/files/styles/carousel_wmark_main/public/', $file);
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
    elseif ($style_type == 'ss_watermark') {
      $file = str_replace('/default/files/', '/default/files/styles/carousel_wmark_main/public/', $file);
    }
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

 return("<div class='social-links-no-byline'>".$twitter_link.$fb_link."</div>");
}

function get_hth_from_ss($ss_nid) {
  $sql = 'SELECT entity_id  ';
  $sql .= 'FROM field_data_field_profile_ref_slideshow ';
  $sql .= 'where field_profile_ref_slideshow_nid = :hth_nid';
  $params = array(':hth_nid' => $ss_nid);

  $result = db_query($sql,$params);
  foreach ($result as $data) {}

  $node_data = array();
  if (isset($data)) {
    return($data->entity_id);
  }
  else {
    return(0);
  }
}

function get_ss_from_hth($hth_nid) {
  $sql = 'SELECT field_profile_ref_slideshow_nid ';
  $sql .= 'FROM field_data_field_profile_ref_slideshow ';
  $sql .= 'where entity_id = :hth_nid';
  $params = array(':hth_nid' => $hth_nid);

  $result = db_query($sql,$params);
  foreach ($result as $data) {}

  $node_data = array();
  if (isset($data)) {
    return($data->field_profile_ref_slideshow_nid);
  }
  else {
    return(0);
  }
}

function get_nqueue_pos($node, $hottie_year, $hottie_week) {
  $nid = $node->nid;

  if (is_profile_gamer_girl($node)) {
    $nq_name = 'gamer_girl_finalists';
  }
  else if ($hottie_year >= 2013 && $hottie_week != 0) {
    $nq_name = 'hth_'.$hottie_year.'_contestants_week_'.$hottie_week;
  }
  else {
    return 0;
  }

  $sql = 'SELECT n.position ';
  $sql .= 'FROM nodequeue_nodes n, nodequeue_queue q, nodequeue_subqueue sq ';
  $sql .= 'WHERE q.qid = sq.qid AND sq.sqid = n.sqid AND n.qid = q.qid AND n.nid = :nid AND q.name = :nq';
  $params = array(':nid' => $nid, ':nq' => $nq_name);

  $result = db_query($sql,$params);
  foreach ($result as $data) {}

  $node_data = array();
  if (isset($data)) {
    return($data->position);
  }
  else {
    return(0);
  }
}

/*
 * Get previous/next girl using nodequeue
 * TODO:  by published date if position not defined
 */
function get_hth_next_prev($node, $hottie_year, $hottie_week, $pos = 0){
  $nid = $node->nid;
  $gamer_girl = is_profile_gamer_girl($node);
   $links = array('next_nid'=>'', 'prev_nid'=>'');

  // If position defined, then use nodequeue
  if ($pos != 0){
    if ($gamer_girl || ($hottie_year >= 2013 && $hottie_week != 0)) {
     if ($pos == '1') {
        $pos1 = $pos+1;
        $pos2 = 200;
      }
      elseif ($pos == '200') {
        $pos1 = 1;
        $pos2 = $pos-1;
      }
      else {
        $pos1 = $pos+1;
        $pos2 = $pos-1;
      }

      if (!$gamer_girl) {
        $nq_name = 'hth_'.$hottie_year.'_contestants_week_'.$hottie_week;
      }
      else {
         $nq_name = 'gamer_girl_finalists';
      }

      $sql = 'select n.nid, n.position FROM nodequeue_nodes n ';
      $sql .= 'left join nodequeue_queue q on n.qid = q.qid ';
      $sql .= 'where q.name = :nq and ';
      $sql .= '(n.position = :pos1 or n.position = :pos2) ';
      $sql .= 'order by n.position asc';
      $params = array(':nq' => $nq_name, ':pos1' => $pos1, ':pos2' => $pos2);

      $result = db_query($sql,$params);
      foreach ($result as $row) {
        if ($row->position == $pos1) {
          $links['prev_nid'] = $row->nid;
        } else if ($row->position == $pos2){
          $links['next_nid'] = $row->nid;
        }
      }
    }
    else {
      $links['prev_nid'];
      $links['next_nid'] = '';
    }
  }
  // don't look in nodeques for prev/next. use channel instead
  else {
    // 9 - homwtoewn hotties channel
    $prev_node = get_prev_next($nid, 9, "p", false);
    $next_node = get_prev_next($nid, 9, "n", false);

    $links['prev_nid'] = $prev_node['nid'];
    $links['next_nid'] = $next_node['nid'];
  }

  return $links;
}

function get_ss_taxonomomy_tags($node) {
  if (isset($node->field_tags[LANGUAGE_NONE][0])) {
    $terms =$node->field_tags[LANGUAGE_NONE][0];
  }
  else {
    $terms = $node->field_tags[0];
  }
  return($terms);
}

function is_profile_gamer_girl($node) {
  $tags = get_ss_taxonomomy_tags($node);

  foreach ($tags as $term_id) {
    if (taxonomy_term_load($term_id)->name == '_gamergirl_2012_contest') {
      return (true);
    }
  }

  return(false);
}
