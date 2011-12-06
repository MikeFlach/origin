<?php
/**
 * @file views-view-list.tpl.php
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>
<?php
  $i = 0;

  $out = '<ul>';
  foreach ($rows as $id => $row) {
    $out = $out.'<li>'.$row.'<small>'.++$i.' of '.count($view->result).'</small></li>';
  }
  $out = $out.'</ul>';
  print $out;



