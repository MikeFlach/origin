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

/**
 * Suppresses the more link for aggreagtor blocks. This is useful for SEO purposes
 *
 */
function maxim_base_more_link ($array)
{
  if (stristr($array['url'], 'aggregator')){
    return "";
  }
}

function maxim_base_preprocess_field(&$vars) {
  if($vars['element']['#field_name'] == 'field_related_content') {
    for ($i=0; $i < count($vars['items']); $i++) {
      $related_content = get_content_data($vars['items'][$i]['#markup']);
      $icon_overlay = ($related_content['type'] === 'slideshow') ? '<div class="icon-overlay"></div>' : '';
      $vars['items'][$i]['#markup'] = '<a href="'.$related_content['link'].'"><div class="related-image">'.$related_content['img_path'].$icon_overlay.'</div></a>';
    }
  }
}

function get_content_data($nid) {
  $node = node_load($nid);
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $main_image = $node_wrapper->field_main_image->value();

  $content = array();
  if (is_array($main_image)) {
    $content['img_path'] = theme('image_style', array('path' => file_load($main_image['fid'])->uri, 'alt' => t($main_image['field_media_caption']), 'style_name' => 'thumbnail_medium'));
  }
  else {
    $content['img_path'] = '';
  }
  $content['type'] = $node->type;
  $content['link'] = url('node/'.$node_wrapper->nid->value());

  return($content);
}

function maxim_base_preprocess_views_view_row_rss(&$vars) {
  $view = &$vars['view'];
  if ($view->name === 'syndicated_content_feeds')
  {
    $options = &$vars['options'];
    $item = &$vars['row'];

    // Use the [id] of the returned results to determine the nid in [results]
    $result = &$vars['view']->result;
    $id  = &$vars['id'];
    $node  = node_load( $result[$id-1]->nid );

    $vars['title'] = check_plain($item->title);
    $vars['link'] = check_url($item->link);
    $vars['description'] = check_plain($item->description);
    $vars['node'] = $node;

    $term = taxonomy_term_load($node->field_content_author[und][0][tid]);
    $vars['author_name'] = check_plain($term->name);
    $vars['item_elements'] = empty($item->elements) ? '' : format_xml_elements($item->elements);
  }
}
