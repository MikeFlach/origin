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
      $related_content = _get_content_data($vars['items'][$i]['#markup']);
      // $icon_overlay = ($related_content['type'] === 'slideshow') ? '<div class="icon-overlay"></div>' : '';

      // we need to add custom alt text to hot100 related links in celebrity profile
      $hot100_alt = '';
      if ($vars['element']['#bundle'] == 'celebrity_profile') {
        // 78821 is the nid for the 2013 hot 100
        if ($vars['items'][$i]['#markup'] == 78821) {
          $hot100_alt = $vars['element']['#object']->title.' Hot 100 2013';
        }
        // -1 is the nid for the 2013 hot 100
        elseif ($vars['items'][$i]['#markup'] == 43451) {
          $hot100_alt = $vars['element']['#object']->title.' Hot 100 2012';
        }
        if (strlen($hot100_alt)) {
          $related_content['img_path'] = str_replace('alt=""', "alt='$hot100_alt'", $related_content['img_path']);
        }
      }

      $vars['items'][$i]['#markup'] =  '<h2 class="related-content-title">'. $related_content['title'] . '</h2>';
      $vars['items'][$i]['#markup'] .= '<div class="related-image">' . $related_content['img_path'] . '</div>';
      $vars['items'][$i]['#markup'] .= '<div class="related-content-summary">' .  $related_content['summary'] . '</div>';
      $vars['items'][$i]['#markup'] .= '<div class="related-more-link">' .  $related_content['more_link'] . '</div>';
    }
  }
}

function _get_content_data($nid) {
  $node = node_load($nid);

  $title = $node->title;
  $channel_data = reset(field_get_items('node',$node, 'field_channel'));
  $channel = taxonomy_term_load($channel_data['tid'], 'field_channel')->name;

  $title = (strlen($channel)) ?  "$channel: $title" : $title;
  if ($node->type === 'slideshow')  {
    $link_txt = "Click to see more of " . $node->title. "'s pics...";
  }
  elseif ($node->type === 'video')  {
    $link_txt = "Click to see more of " . $node->title . "'s video...";
  }
  else {
    $link_txt = "Click to read more...";
  }

  $main_image = reset(field_get_items('node',$node, 'field_main_image'));
  $summary = $node->body[LANGUAGE_NONE][0]['safe_summary'];
  $link_path = url('node/'.$node->nid);

  $content = array();
  if (is_array($main_image)) {
    // $content['img_path'] = theme('image_style', array('path' => file_load($main_image['fid'])->uri, 'alt' => t($main_image['field_media_caption']), 'style_name' => 'thumbnail_medium'));
    $content['img_path'] =  theme_image(array('path' => file_load($main_image['fid'])->uri, 'alt' => t($main_image['field_media_caption'])));
  }
  else {
    $content['img_path'] = '';
  }

  $content['img_path'] = _wrap_href($content['img_path'], $link_path);
  $content['title'] = _wrap_href($title, $link_path);
  $content['summary'] = $summary;
  $content['type'] = $node->type;
  $content['link'] = $link_path;
  $content['more_link'] = _wrap_href($link_txt, $link_path);

  return($content);
}

function _wrap_href($item, $href) {
  return ("<a href='" . $href . "'>$item</a>");
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

/**
 * Implements theme_brightcove_field_formatter_default().
 * Returns an embedded player with default site player.
 *
 * @param $element
 *   Element with the Video ID.
 * @return
 *   Player HTML code.
 */
function maxim_base_brightcove_field_formatter_default($variables) {
  $output = NULL;

  if (isset($variables['element']['brightcove_id'])) {
    $vidcount = &drupal_static(__FUNCTION__, 1);
    if ($vidcount == 1) {
      drupal_add_js('http://admin.brightcove.com/js/BrightcoveExperiences.js', array('weight'=>4));
      drupal_add_js('http://admin.brightcove.com/js/APIModules_all.js', array('weight'=>5));
      drupal_add_js(path_to_theme() . '/js/videoplayer.js', array('weight'=>5));
    }
    $params['id'] = 'myExperience_' . $variables['element']['brightcove_id'];

    // Check display for player override
    if(isset($variables['player_override']) && !empty($variables['player_override'])) {
      $player = $variables['player_override'];
    } else {
      $player = $variables['element']['player'];
    }

    $output = theme('brightcove_field_embed', array(
      'type' => $variables['type'],
      'brightcove_id' => $variables['element']['brightcove_id'],
      'params' => $params,
      'player' => brightcove_field_get_value($variables['instance'], $player),
      'width' => $variables['width'],
      'height' => $variables['height'],
      'video_autoplay' => $variables['video_autoplay'],
      'video_volume' => $variables['video_volume'],
      'player_override' => $variables['player_override'],
    ));

    $vidcount++;
  }

  return $output;
}

/**
 * Process variables for search-results.tpl.php.
 *
 * The $variables array contains the following arguments:
 * - $results: Search results array.
 * - $module: Module the search results came from (module implementing
 *   hook_search_info()).
 *
 * @see search-results.tpl.php
 */
function maxim_base_preprocess_search_results(&$variables) {
  $variables['search_results'] = '';
  if (!empty($variables['module'])) {
    $variables['module'] = check_plain($variables['module']);
  }

  foreach ($variables['results'] as $result) {
    if($result['entity_type'] === 'node') {
      $result['link'] = url('node/' . $result['fields']['entity_id']);
    }
    $variables['search_results'] .= theme('search_result', array('result' => $result, 'module' => $variables['module']));
  }
  $variables['pager'] = theme('pager', array('tags' => NULL));
  $variables['theme_hook_suggestions'][] = 'search_results__' . $variables['module'];
}

/**
 * Theme callback for a rel link tag.
 * This overides the hteme function for the metatag module to change canonical tags
 *
 * The format is:
 * <link rel="[name]" href="[value]" />
 */
function maxim_base_metatag_link_rel($variables) {
  $element = &$variables['element'];

  //MAXIM override: if doing canonical metatag, we want to remove page= for everything before page 1
  if ($element['#name'] == 'canonical') {
    //find if the current canonical val has a page=
    //$urlPieces = explode('?page=', $element['#value']);
    //if there is a page = and the value after page is < 1, then we want to remove all the text after ?page=
    /*if (isset($urlPieces['1']) && $urlPieces['1'] < 1) {
      $element['#value'] = $urlPieces[0];
    }*/
    //if we are in girls of maxim/all we want the canonical to be the same as the regular girls of maxim page
    if (strpos($element['#value'], 'girls-of-maxim/all') !== false) {
      $urlVal = $element['#value'];
      $newUrlVal = str_replace("/all", "", $urlVal);
      $element['#value'] = $newUrlVal;
    }
    element_set_attributes($element, array('#name' => 'rel', '#value' => 'href'));
    unset($element['#value']);
  } //end MAXIM override for canonical tag

  return theme('html_tag', $variables);
}
