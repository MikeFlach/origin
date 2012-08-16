<?php
/**
 * @file views-view--jumb.tpl.php
 * Main view template
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
$jtHTML = <<<EOD
  <div class="jumbotron"><div class="panels clearfix"></div><nav class="jumboNav clearfix"></nav></div>
EOD;

$jtJS = <<<EOD
  <script>
    (function ($) { buildJumbotron(); }(jQuery));
   </script>
EOD;

print $jtHTML;

$json_data = json_decode($rows, TRUE);

for($i = 0; $i < count($json_data); $i++) {
  $json_data[$i]['alt_image'] = str_replace(array('"', "'"), '', $json_data[$i]['alt_image']);
  $json_data[$i]['alt_title'] = str_replace(array('"', "'"), '', $json_data[$i]['alt_title']);
  $link = url('node/'.$json_data[$i]['Nid']);
  $json_data[$i]['link'] = $link;
}

print '<script type="text/javascript">var arJumbotron='.json_encode($json_data).'</script>';
print $jtJS;
