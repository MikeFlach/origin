<?php

// Functions that return HTML goes in the theme.inc file
require_once dirname(__FILE__) . '/includes/maxim_base.theme.inc';

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
 * Implements theme_form_alter()
 * For modififying search box
 */
function maxim_base_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    $form['search_block_form']['#title'] = t('Search'); // Change the text on the label element
    $form['search_block_form']['#title_display'] = 'invisible'; // Toggle label visibilty
    $form['search_block_form']['#size'] = 40;  // define size of the textfield
    $form['search_block_form']['#default_value'] = t(''); // Set a default value for the textfield

    // Add extra attributes to the text box
    $form['search_block_form']['#attributes']['onblur'] = "if (this.value == '') { jQuery(this).removeClass('expanded'); jQuery(this).parent().children('label').show(); window.disableKeyEvents=0; }";
    $form['search_block_form']['#attributes']['onfocus'] = "jQuery(this).addClass('expanded'); if (this.value == '') { jQuery(this).parent().children('label').hide(); window.disableKeyEvents=1; }";
  }
}

/**
 * Implements hook_html_head_alter().
 * Look for any meta tags defined with maximmeta_*tagname*.
 * The code will then find the metatag module equilavent and unset it giving us the ability to override any metatag needed on a more granular level.
 */
function maxim_base_html_head_alter(&$elements) {
  foreach (array_keys($elements) as $key) {
    if (strpos($key, 'maximmeta_') !== false) {
      $name = array_pop(explode("_", $key));
      if (isset($elements['metatag_' . $name ])) {
        unset($elements['metatag_' . $name ]);
      }
    }
  }
}

/**
 * Returns HTML for an individual feed item for display in the block.
 *
 * @param $variables
 *   An associative array containing:
 *   - item: The item to be displayed.
 *   - feed: Not used.
 *
 * @ingroup themeable
 */
function maxim_base_aggregator_block_item($variables) {
  // Display the external link to the item.
  return '<a href="' . check_url($variables['item']->link) . '" target="_blank" rel="nofollow">' . check_plain($variables['item']->title) . "</a>\n";
}
