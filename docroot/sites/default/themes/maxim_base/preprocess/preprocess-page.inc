<?php

function maxim_base_alpha_preprocess_page(&$vars) {
  nest_content_regions($vars);
 //  add_syndication_beacons($vars);
  add_jumbotron($vars);
}

/**
 * Nests the regions 'feature', 'content' and 'sidebar_first' into the 'content container' region.
 */
function nest_content_regions(&$vars) {
  $vars['page']['content']['content']['content_container']['#sorted'] = FALSE;

  if (!empty($vars['page']['#excluded']['feature'])) {
    $vars['page']['#excluded']['feature']['#data']['weight'] = 1;
    $vars['page']['#excluded']['feature']['#data']['wrapper_css'] = '.alpha .omega';
    $vars['page']['content']['content']['content_container']['feature'] = $vars['page']['#excluded']['feature'];
  }

  if (!empty($vars['page']['#excluded']['content'])) {
    $vars['page']['#excluded']['content']['#data']['weight'] = 3;
    $vars['page']['#excluded']['content']['#data']['wrapper_css'] = '.alpha';
    $vars['page']['content']['content']['content_container']['content'] = $vars['page']['#excluded']['content'];
  }

  if (!empty($vars['page']['#excluded']['sidebar_first'])) {
    $vars['page']['#excluded']['sidebar_first']['#data']['weight'] = 5;
    $vars['page']['#excluded']['sidebar_first']['#data']['wrapper_css'] = '.omega';
    $vars['page']['content']['content']['content_container']['sidebar_first'] = $vars['page']['#excluded']['sidebar_first'];
  }

}

/**
 * Adds 'comscore', and 'quantcast' syndicated research beacons.
 */
function add_syndication_beacons(&$vars) {
  $syndication_data = '';

  $syndication_data .= <<<EOD
  <script>
  <!-- Begin comScore Tag -->
    document.write(unescape("%3Cscript src='" + (document.location.protocol == "https:" ? "https://sb" : "http://b") + ".scorecardresearch.com/beacon.js' %3E%3C/script%3E"));
  </script>
  <script type="text/javascript">
    COMSCORE.beacon({
    c1:2,
    c2:6036003,
    c3:"",
    c4:"",
    c5:"",
    c6:"",
    c15:""
    });
  </script>
  <!-- <noscript><img src="http://b.scorecardresearch.com/b?c1=2&amp;c2=6036003&amp;c3=&amp;c4=&amp;c5=&amp;c6=&amp;c15=&amp;cv=1.3&amp;cj=1" style="display:none" width="0" height="0" alt="comscore" /></noscript>-->
  <!-- End comScore Tag -->
EOD;

  $syndication_data .= <<<EOD
  <!-- Start Quantcast tag -->
    <script type="text/javascript" src="http://edge.quantserve.com/quant.js"></script>
    <script type="text/javascript">_qacct='p-94eQvyyY-EFy2';quantserve();</script>
  <!--<noscript>
    <a href="http://www.quantcast.com/p-94eQvyyY-EFy2"><img src="http://pixel.quantserve.com/pixel/p-94eQvyyY-EFy2.gif" style="display: none" height="1" width="1" alt="Quantcast" /></a>
  </noscript>-->
  <!-- End Quantcast tag -->
EOD;

  $vars['page']['footer']['beacons'] = array('#markup' => $syndication_data);
}


/**
 * Adds jumbotron javascript file to the sites frontpage.
 */
function add_jumbotron(&$vars) {
  if (drupal_is_front_page()) {
    drupal_add_js(libraries_get_path('jumbotron') . '/jumbotron.jquery.js');
    drupal_add_css(libraries_get_path('jumbotron') . '/jumbotron.jquery.css');
  }
}