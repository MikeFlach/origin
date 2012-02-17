<?php
  /**
   * Override or insert variables into the html template.
   */

  // add title meta tag to blackout slideshow/gallery
  function maxim_base_alpha_preprocess_html(&$vars) {
    if (strstr($_GET['q'], 'slideshow')) {
      $vars['head_title'] = get_text_between_tags($vars['page']['content']['content']['content']['system_main']['content']['main']['#markup'], 'h1').' | Maxim';
    }
    elseif (strstr($_GET['q'], 'gallery')) {
     $vars['head_title'] = get_text_between_tags($vars['page']['content']['content']['content']['system_main']['content']['main']['#markup'], 'h2').' | Maxim';
    }
    elseif (strstr($_GET['q'], 'oscarsmadness')) {
     $vars['head_title'] = 'Oscars Madness | Maxim';
    }
  }

  function get_text_between_tags($string, $tagname) {
    $pattern = "/<$tagname ?.*>(.*)<\/$tagname>/";
    preg_match($pattern, $string, $matches);

    return $matches[1];
 }


