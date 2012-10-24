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
  $width=100;
  $height=100;
  $border='FFFFFF';

  if (isset($_GET['w']) && is_numeric($_GET['w']) && $_GET['w'] > $width) {
    $width = $_GET['w'];
  }
  if (isset($_GET['h']) && is_numeric($_GET['h']) && $_GET['h'] > $height) {
    $height = $_GET['h'];
  }
  if (isset($_GET['border']) && strlen($_GET['border']) == 6) {
    $border = $_GET['border'];
  }

  $img_max_width = $width-100;
  $html = <<<HTMLBLOCK
<style>.mxm_widget_girl { width:{$width}px;border:1px solid #{$border}; }
.mxm_widget_girl img { max-width:{$img_max_width}px; }
</style>
<div class="mxm_widget_girl">
{$rows}
</div>
HTMLBLOCK;

// remove whitespace
$html = trim(preg_replace('/\n|\r/', '', $html));
$js_str = json_encode($html);
echo 'document.write(' . $js_str . ');';

exit();
