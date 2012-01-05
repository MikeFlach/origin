<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 *
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

/**
 * Replace the bundled version of jQuery with jQuery 1.7.1
 * TBD - Move this code to a module.
 */
function maxim_base_js_alter(&$javascript) {
  $javascript['misc/jquery.js']['data'] = libraries_get_path('jquery')  . '/jquery-1.7.1.min.js';
}

/*
 * Implements theme_menu_link()
 */
function maxim_base_menu_link__main_menu($variables){
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  // add term id to top level menu
  $element['#attributes']['class'][] = 'mtid-' . str_replace('taxonomy/term/', '', $element['#href']);

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/*
 * Implements theme_menu_tree()
 * For dropdown menu
 */
function maxim_base_menu_tree__menu_block__1($variables){
  $str = $variables['tree'];
  $test = '</optgroup>';
  if(substr_compare($str, $test, -strlen($test), strlen($test)) === 0){
    return $str;
  } else {
    return $str . '</optgroup>';
  }
}

/*
 * Implements theme_menu_link()
 * For dropdown menu
 */
function maxim_base_menu_link__menu_block__1($variables){
  $element = $variables['element'];
  $sub_menu = '';
  $menu_link = '';
  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  unset($element['#attributes']['class']);
  if($element['#original_link']['in_active_trail'] == 1){
    $element['#attributes']['selected'][] = 'selected';
  }
  $element['#attributes']['value'][] = '/' . drupal_get_path_alias($element['#href']);
  if($element['#original_link']['depth'] == 1){
    $menu_link = '<optgroup label="' . $element['#title'] . '"><option' . drupal_attributes($element['#attributes']) . '>' . $element['#title'] . " Home</option>\n" . $sub_menu ;
  } else {
    $menu_link = '<option' . drupal_attributes($element['#attributes']) . '>' . $element['#title'] . "</option>\n";
  }
  return $menu_link;
}

/*
 * Implements theme_delta_blocks_logo()
 * For adding image map to the main logo
 */
function maxim_base_delta_blocks_logo($variables) {
  if ($variables['logo']) {
    $image = array(
      '#theme' => 'image',
      '#path' => $variables['logo'],
      '#alt' => $variables['site_name'],
      '#attributes' => array( 'usemap' => '#logomap'),
    );
    $image = render($image);

    $img_map = '<map name="logomap"><area href="/" shape="poly" coords="0,58,100,0,186,0,13,102,13,108,0,108,0,58" title="Back to ' . $variables['site_name'] . ' Homepage" alt="' . $variables['site_name'] . ' Homepage" /></map>';
    
    return '<div class="logo-img">' . $img_map . $image . '</div>';
  }
}

/*
 * Implements theme_form_alter()
 * For modififying search box
 */
function maxim_base_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    $form['search_block_form']['#title'] = t('Search'); // Change the text on the label element
    $form['search_block_form']['#title_display'] = 'invisible'; // Toggle label visibilty
    $form['search_block_form']['#size'] = 40;  // define size of the textfield
    $form['search_block_form']['#default_value'] = t('Search'); // Set a default value for the textfield

    // Add extra attributes to the text box
    $form['search_block_form']['#attributes']['onblur'] = "if (this.value == '') {jQuery(this).removeClass('expanded'); this.value = 'Search';}";
    $form['search_block_form']['#attributes']['onfocus'] = "jQuery(this).addClass('expanded'); if (this.value == 'Search') {this.value = '';}";
  }
} 
