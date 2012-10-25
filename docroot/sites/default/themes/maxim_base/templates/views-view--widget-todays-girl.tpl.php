<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>

<?php
  // set minimum widths
  $width=200;
  $border='BE1E2D';

  if (isset($_GET['w']) && is_numeric($_GET['w']) && $_GET['w'] > $width) {
    $width = $_GET['w'];
  } else {
    $width = 300;
  }
  if (isset($_GET['b'])) {
    $border = $_GET['b'];
  }

  $img_max_width = $width-40;
  $html = <<<HTMLBLOCK
<style>
.mxm-widget-girl { background-color:#ECECEC; margin:5px 0; width:{$width}px; border-top:5px solid #{$border}; border-bottom:5px solid #{$border}; font-family: "Avant Garde", Avantgarde, "Century Gothic", CenturyGothic, "AppleGothic", sans-serif; text-align:center; }
.mxm-widget-head { margin:10px 0 0; }
.mxm-widget-head-text { margin-top:5px; font-size:29px; }
.mxm-widget-body img { max-width:260px; width:90%; }
.mxm-widget-fname { margin-top:5px; font-size:18px; }
.mxm-widget-foot { text-align:left; margin:10px;}
.mxm-widget-links { text-align:center; font-size:13px; font-color:#000; margin-bottom:15px; }
.mxm-widget-links a:link, .mxm-widget-links a:visited, .mxm-widget-links a:active { color:#000; text-decoration:underline; }
.mxm-widget-social a { margin-right:4px; }
.mxm-widget-embed { float:right; }
</style>
<div class="mxm-widget-girl">
  <div class="mxm-widget-head">
    {$header}
  </div>
  <div class="mxm-widget-body">
    {$rows}
  </div>
  <div class="mxm-widget-foot">
    {$footer}
  </div>
</div>
HTMLBLOCK;

// remove whitespace
$html = trim(preg_replace('/\n|\r/', '', $html));
$js_str = json_encode($html);
echo 'document.write(' . $js_str . ');';

exit();
