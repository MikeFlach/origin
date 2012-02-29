<?php
  /**
   * Override or insert variables into the html template.
   */

  // add title meta tag to blackout slideshow/gallery
  function maxim_base_alpha_preprocess_html(&$vars) {
    if ((strstr($_GET['q'], 'slideshow')) || (strstr($_GET['q'], 'gallery'))) {
      $nid = end(explode("/", $_GET['q']));
      if (is_numeric($nid)) {
        $vars['head_title'] = node_load($nid)->title.' | Maxim';
      }
      elseif (strstr($_GET['q'], 'slideshow')) {
        $vars['head_title'] = 'Slideshow | Maxim';
      }
      else {
        $vars['head_title'] = 'Gallery | Maxim';
      }
    }
    elseif (strstr($_GET['q'], 'oscarsmadness')) {
     $vars['head_title'] = 'Oscars Madness | Maxim';
    }
  }

