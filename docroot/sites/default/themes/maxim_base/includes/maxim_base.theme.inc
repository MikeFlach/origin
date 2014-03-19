<?php

/**
 * @file
 * Theme functions for the Maxim Base theme.
 * For functions that return HTML
 */

/**
 * Returns HTML for a query pager.
 *
 * Menu callbacks that display paged query results should call theme('pager') to
 * retrieve a pager control so that users can view other results. Format a list
 * of nearby pages with additional query results.
 *
 * @param $vars
 *   An associative array containing:
 *   - tags: An array of labels for the controls in the pager.
 *   - element: An optional integer to distinguish between multiple pagers on
 *     one page.
 *   - parameters: An associative array of query string parameters to append to
 *     the pager links.
 *   - quantity: The number of pages in the list.
 *   - firstlast: Boolean to show first/last links, default = 0
 *   - ellipsis:  Boolean to show ellipsis, default = 0
 *
 * @ingroup themeable
 */
function maxim_base_pager($vars) {
  global $pager_page_array, $pager_total;

  $tags = $vars['tags'];
  $element = $vars['element'];
  $parameters = $vars['parameters'];
  $quantity = $vars['quantity'];
  if (array_key_exists('firstlast', $vars)){
    $show_first_last = $vars['firstlast'];
  } else {
    $show_first_last = 0;
  }
  if (array_key_exists('ellipsis', $vars)){
    $show_ellipsis = $vars['ellipsis'];
  } else {
    $show_ellipsis = 0;
  }

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }

  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.
  if ($show_first_last){
    $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('« first')), 'element' => $element, 'parameters' => $parameters));
  }
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_previous = str_replace('‹ ', '', $li_previous);
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = str_replace(' ›', '', $li_next);
  if ($show_first_last){
    $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last »')), 'element' => $element, 'parameters' => $parameters));
  }

  if ($pager_total[$element] > 1) {
    if ($show_first_last && $li_first) {
      $items[] = array(
        'class' => array('pager-first'),
        'data' => $li_first,
      );
    }

    if ($li_previous) {
      $items[] = array(
        'class' => array('pager-previous'),
        'data' => '<span class="prev-image"></span>' . $li_previous,
      );

      // Add prev head link tag
      $count = preg_match('/href=(["\'])(.*?)\1/', $li_previous, $match);
      if ($count !== FALSE) {
        drupal_add_html_head_link(array('rel' => 'prev', 'href' => 'http://www.maxim.com' . $match[2]));
      }
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($show_ellipsis && $i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }

      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
          );
        }

        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-current'),
            'data' => $i,
          );
        }

        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
          );
        }
      }

      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
    }

    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next'),
        'data' => $li_next . '<span class="next-image"></span>',
      );

      // Add next head link tag
      $count = preg_match('/href=(["\'])(.*?)\1/', $li_next, $match);
      if ($count !== FALSE) {
        drupal_add_html_head_link(array('rel' => 'next', 'href' => 'http://www.maxim.com' . $match[2]));
      }

    }
    if ($show_first_last && $li_last) {
      $items[] = array(
        'class' => array('pager-last'),
        'data' => $li_last,
      );
    }

    return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pager', 'clearfix')),
    ));
  }
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
function maxim_base_menu_tree__menu_block__dropdown_menu_1($variables){
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
function maxim_base_menu_link__menu_block__dropdown_menu_1($variables){
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
      '#path' => 'http://cdn2.maxim.com/maxim/sites/default/themes/maxim_base/logo2.png',
      '#alt' => $variables['site_name'] . ' Homepage',
    );
    $image = render($image);

    //return '<div class="logo-img">' . $img_map . $image . '</div><div class="logo-img-sm"><a href="/"><img src="' . base_path() . path_to_theme() . '/images/logo_maxim_main_small.png" width="123" height="28" /></a></div>';
    return '<div class="logo-img"><a href="/">' . $image .' </a></div>';
  }
}
