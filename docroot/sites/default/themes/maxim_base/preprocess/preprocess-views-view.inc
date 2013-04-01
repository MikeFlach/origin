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
  set_page_channel_js();
  view_display_dispatch($view, __FUNCTION__);
}

function maxim_base_alpha_preprocess_views_view__slideshow_json(&$view) {
  require('preprocess-views-slideshow.inc');
  view_display_dispatch($view, __FUNCTION__);
}

function maxim_base_alpha_preprocess_views_view__hth_2014_admin_view(&$view) {
  include_once libraries_get_path('php').'/shared/preprocess-functions.php';
  view_display_dispatch($view, __FUNCTION__);
}

function maxim_base_alpha_preprocess_views_view__webform_results (&$view) {
  drupal_add_css(libraries_get_path('slideshow') . '/colorbox.css');
  drupal_add_js(libraries_get_path('slideshow') . '/jquery.colorbox.js');

  drupal_add_css(drupal_get_path('theme', 'maxim_base') . '/css/webform-results.css', array('group' => CSS_DEFAULT,'preprocess'=> FALSE, 'every_page' => FALSE));
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
    case 'maximtv_player':
      //kpr($view);
      if (count($view['view']->result) == 0) {
        $video_id = implode($view['view']->args);
        $video_details = brightcove_video_load($video_id);
        if ($video_details !== FALSE) {
          $variables = array(
            'type' => 'brightcove',
            'brightcove_id' => $video_id,
            'player' => 1,
            'width' => 620,
            'height' => 398,
            'video_autoplay' => true,
          );
          $player = theme('brightcove_field_embed', $variables);
          $video_html = "<div class=\"content-feature\"><h1 class=\"feature-title\">{$video_details->name}</h1><div class=\"feature-body\">{$video_details->shortDescription}</div></div>";

          $view['rows'] = $player . $video_html;
          drupal_set_title($video_details->name);
        } else {
          drupal_goto('maximtv', array(), '301');
        }

      } else {
        if (is_numeric($view['view']->result[0]->nid)) {
          $qry = array();
          if (isset($_REQUEST['src'])) {
            $qry['src'] = $_REQUEST['src'];
          }
          drupal_goto('node/' . $view['view']->result[0]->nid, array('query' => $qry), '301');
        } else {
          drupal_goto('maximtv', array(), '301');
        }
      }
      break;
    default:
      $view['title'] = str_replace(array('»','videos'), array('<span>»</span>', $view['view']->build_info['substitutions']['%1']), $view['more']);
      $view['more'] = '';
      break;
  }
}

function maxim_base_alpha_preprocess_views_view__hot_100 (&$view) {
  drupal_add_js(drupal_get_path('theme', 'maxim_base').'/js/hot-100.js', array('preprocess'=> FALSE, 'every_page' => FALSE));
  drupal_add_css(drupal_get_path('theme', 'maxim_base') . '/css/hot-100.css', array('group' => CSS_DEFAULT,'preprocess'=> FALSE, 'every_page' => FALSE));
  drupal_add_css(drupal_get_path('theme', 'maxim_base') . '/css/multi-vote.css', array('group' => CSS_DEFAULT,'preprocess'=> FALSE, 'every_page' => FALSE));
  drupal_add_js(drupal_get_path('theme', 'maxim_base').'/js/multi-vote.js', array('preprocess'=> FALSE, 'every_page' => FALSE));

  $generic_mv_settings = array('btn_txt' => 'Vote For Me!', 'response_txt' => 'Thanks for voting!', 'btn_class' => 'hot100-2013', 'campaign' => 'hot100-2013',
                               'limit_txt' => 'Vote again tomorrow!', 'inactive_txt' => 'Voting is closed!', 'main_class' => 'hot100vote', 'custom_vote_txt' => 'Your vote has been counted!');

  drupal_add_js(array('Maxim' => array('generic_multivote_settings' => $generic_mv_settings)), 'setting');
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
  $pager = generate_nq_slider ($view, 'hottie');

  $view['pager'] = $pager;
}

/*
 * Preprocess for General Profile NQ Slider.
 * Custom ajax pager
 */
function maxim_base_alpha_preprocess_views_view__general_profile_nq_slider(&$view) {
  $pager = generate_nq_slider ($view, 'gprofile');

  $view['pager'] = $pager;
}

function generate_nq_slider ($view, $type) {
  if ($type == 'gprofile') {
    $maxim_settings_name = 'general_profile_data';
  }
  else if ($type == 'hottie') {
    $maxim_settings_name = 'hottie';
  }

  $total_count = $view['view']->total_rows;
  $num_per_page = $view['view']->query->limit;
  $first_pos = $view['view']->result[0]->nodequeue_nodes_node_position;
  $active_pg = ($first_pos-1)/$num_per_page;

  $pager = '<div class="item-list"><ul class="pager clearfix">';
  $num_pages = ceil($total_count/$num_per_page);

  $sliderJS = array();
  $sliderJS[$maxim_settings_name] = array('slider_show_max' => $num_per_page);
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
      $pager .= '<a href="?page='. $i .'" onclick="'.$type.'Loading(' . $i . ')">' . ($i*$num_per_page+1) . '-' . $end_page . '</a></li>';
    }
    if ($i != $num_pages-1) {
      $pager .= '<li> | </li>';
    }
  }
  $pager .= '</ul></div>';
  if ($active_pg > 0) {
    $pager .= '<div class="slider-prev item-list"><ul class="pager"><li class="pager-prev"><a href="?page=' . ($active_pg-1)  . '" onclick="'.$type.'Loading();"> </a></li></ul></div>';
  }
  if ($active_pg < $num_pages-1) {
    $pager .= '<div class="slider-next item-list"><ul class="pager"><li class="pager-next"><a href="?page=' . ($active_pg+1) . '" onclick="'.$type.'Loading();"> </a></li></ul></div>';
  }
  $pager .= '<div class="slider-loading">L O A D I N G . . .</div>';
  $pager .= '<script>'.$type.'SliderLoader();</script>';

  return($pager);
}
function maxim_base_alpha_preprocess_views_view__hth_2014_admin_view__2014_hth_slotting_details(&$view) {
  drupal_add_css(drupal_get_path('theme', 'maxim_base') . '/css/hotties-admin.css', array('group' => CSS_THEME, 'every_page' => FALSE));
  drupal_add_css(libraries_get_path('slideshow') . '/colorbox.css');
  drupal_add_js(libraries_get_path('slideshow') . '/jquery.colorbox.js');

  $out = '<div class="slotting-detail">';
  $view_name = 'hth_2014_admin_view_';
  $view_results = $view['view']->result;
  $data = '<div id="hth-count">Total Entries: '.views_get_current_view()->total_rows.'</div><ul>';

  foreach ($view_results as $result) {
    $f_name = $view_name.'first_name'; $l_name = $view_name.'last_name'; $pic=$view_name.'photo_1';
    $file = file_load($result->$pic);
    $file_path = str_replace('localhost', 'edit', file_create_url($file->uri));
    $pic_path =
      theme('image',
        array(
          'path' => replace_image_path($file_path),
          'attributes' => array('onclick' => 'jQuery().colorbox({html:\'<img class="sm-cbox-pic" src="'.$file_path.'\"/>\'})')
        )
      );
    //$f_name = $view_name.'first_name'; $l_name = $view_name.'last_name';
    //$name_link = '<a href="'.'/node/67256'.'/submission/'.$result->sid.'" target="_new">'.$result->$f_name.' '. $result->$l_name.'</a>';
    $data .= '<li class="name">'.$pic_path.'</a></li>';
  }
  $data .= '</ul>';
  $out .= $data.'</div>';
  $view['rows'] = $out;
}

function maxim_base_alpha_preprocess_views_view__hth_2014_admin_view__hotties_2014_admin(&$view) {
  drupal_add_css(drupal_get_path('theme', 'maxim_base') . '/css/hotties-admin.css', array('group' => CSS_THEME, 'every_page' => FALSE));
  drupal_add_js(drupal_get_path('theme', 'maxim_base') . '/js/hotties-admin.js', array('every_page' => FALSE));
  drupal_add_library('system', 'drupal.collapse');
  drupal_add_css(libraries_get_path('slideshow') . '/colorbox.css');
  drupal_add_js(libraries_get_path('slideshow') . '/jquery.colorbox.js');

  $view_name = 'hth_2014_admin_view_';
  $out = '<div class="hottie-admin">';
  $select_options = array('Unslotted','Yes','No','Maybe');
  $contest_week = array('None','Week 1','Week 2','Week 3','Week 4','Week 5');
  $pic_count = 0;

  //generate images from fids
  $view_results = $view['view']->result;
  foreach ($view_results as $result) {
    $visible_pics = array(); $hidden_pics = array(); $pic_count = 0;
    foreach ($result as $field => $key) {
      if ((strpos($field, 'photo') !== false) && (strlen($key) > 0)) {
        $file = file_load($key);
        $file_path = str_replace('localhost', 'edit', file_create_url($file->uri));
        $pic_path =
          theme('image',
            array(
              'path' => replace_image_path($file_path),
              'attributes' => array('class' => 'scale-img', 'onclick' => 'jQuery().colorbox({html:\'<img class="sm-cbox-pic" src="'.$file_path.'\"/>\'})')
            )
          );
        ($pic_count++ < 3) ? array_push($visible_pics, $pic_path) : array_push($hidden_pics, $pic_path);
      }
    }

    //sometimes we loose the second page of entry and can't count on is_draft being accurate
    if ($pic_count >= 3) {
      $f_name = $view_name.'first_name'; $l_name = $view_name.'last_name'; $dob = $view_name.'date_of_birth'; $email = $view_name.'email_address'; $slot = $view_name.'entry_slotting'; $week = $view_name.'contest_week';
      $current_slot = $result->$slot;  $current_week = $result->$week;

      //display basic data
      $data = '<ul>';
      $data .= '<li class="name"><span class="label">Name: </span>'.$result->$f_name.' '.$result->$l_name.'</li>';
      $data .= '<li class="dob"><span class="label">DoB: </span>'.$result->$dob.'</li>';
      $data .= '<li class="email"><span class="label">Email: </span><a href="mailto:'.$result->$email.'">'.$result->$email.'</a></li>';
      $data .= '<li class="view-all"><span class="label"></span><a href="'.'/node/67256'.'/submission/'.$result->sid.'" target="_new">View Complete Submission</a></li></ul>';
      $data .= '<div class="clear2">&nbsp;</div>';

      //first 3 pics make visible
      $pics = '';
      for ($i=0; $i<3; $i++) {
        $last_class = ($i == 2) ? ' last ' : '';
        $pics .= '<div class="pic '.$last_class.'">'.$visible_pics[$i].'</div>';
      }

      //other pics go inside collapsible dev
      if ($pic_count > 3) {
        $small_pics = '';
        foreach ($hidden_pics as $h_pic) {
          $small_pics .= '<div class="sm-pic">'.$h_pic.'</div>';
        }

        $collapsible_fs = '';
        if (strlen($small_pics)) {
          $collapsible_fs = '<fieldset class="hotties-hidden-images collapsible "><legend><d class="fieldset-legend">Additional Photos</span></legend><div class="fieldset-wrapper">'.$small_pics.'</div></fieldset>';
        }
      }
      else {
        $collapsible_fs = '';
      }

      // Setup selectbox for slotting
      $options = '<div class="styled-select"><select onchange="javascript:slot_hottie('.$result->sid.',this.options[this.selectedIndex].innerHTML)" class="hottie-select">';
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
      $options .= '</select><img id="status-s-'.$result->sid.'" class="status-img" src="/'.drupal_get_path('theme', 'maxim_base').'/images/green-check-circle.jpeg"/><img id="status-f-'.$result->sid.'" class="status-img" src="/'.drupal_get_path('theme', 'maxim_base').'/images/red-x-circle.jpeg"></div>';

      // Setup selectbox for week selection
      $display_class = ($display_weeks) ? 'visible' : 'hidden';

      $weeks = '<div class="styled-select '.$display_class.'" id="dw'.$result->sid.'"><select onchange="javascript:slot_week('.$result->sid.', \'yes\', this.options[this.selectedIndex].innerHTML)" class="hottie-select">';
      for ($j=0; $j<count($contest_week); $j++) {
        if ($current_week === strtolower($contest_week[$j])) {
          $weeks .= '<option selected="selected">'.$contest_week[$j].'</option>';
        }
        else {
          $weeks .= '<option>'.$contest_week[$j].'</option>';
        }
      }
      $weeks .= '</select><img id="week-s-'.$result->sid.'" class="status-img" src="/'.drupal_get_path('theme', 'maxim_base').'/images/green-check-circle.jpeg"/><img id="week-f-'.$result->sid.'" class="status-img" src="/'.drupal_get_path('theme', 'maxim_base').'/images/red-x-circle.jpeg"></div>';

      $out .= $data.$options.$weeks.$pics.$collapsible_fs.'<div class="clear">&nbsp</div>';
    }
  }

  $out .= '</div>';
  $view['rows'] = $out;
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


/*
 * Replace local file paths with CDN path.
 */
function replace_image_path($file, $style_type = '') {
  if ((determine_media_type(pathinfo($file, PATHINFO_EXTENSION)) === 'image') && !empty($style_type)) {
    $split_on = '/sites/default/files/';
    $base_file = basename($file);
    $image_path = explode($split_on, dirname($file));
    if (count($image_path) > 1) {
      $image_path = $image_path[1].'/';
    }
    else {
      $image_path = '';
    }
    $internal_name = 'public://'.$image_path.$base_file;
    $file = image_style_url($style_type, $internal_name);
  }
  return($file);
}

/*
 * Set channel in javascript: Drupal.settings.Maxim.channel
 */
function set_page_channel_js($channel = null){
  $maxim_vars = array();
  $maxim_vars['channel'] = array();
  if ($channel === null) {
    $url_path = drupal_get_normal_path(drupal_get_path_alias());
    if (strpos($url_path, 'taxonomy/term/') !== false) {
      $term_id = str_replace('taxonomy/term/', '', $url_path);
      if (is_numeric($term_id)){
        $arChannel = taxonomy_get_parents_all($term_id);
        foreach($arChannel as $ch){
          array_unshift($maxim_vars['channel'], $ch->name);
        }
      }
    }
  } else if (is_array($channel)) {
    $maxim_vars['channel'] = $channel;
  }
  drupal_add_js(array('Maxim' => $maxim_vars), 'setting');
}
