<?php
 /**
  * This template is used to print a single field in a view. It is not
  * actually used in default Views, as this is registered as a theme
  * function which has better performance. For single overrides, the
  * template is perfectly okay.
  *
  * Variables available:
  * - $view: The view object
  * - $field: The field handler object that can process the input
  * - $row: The raw SQL result that can be used
  * - $output: The processed output that will normally be used.
  *
  * When fetching output from the $row, this construct should be used:
  * $data = $row->{$field->field_alias}
  *
  * The above will guarantee that you'll always get the correct data,
  * regardless of any changes in the aliasing that might happen if
  * the view is modified.
  */
?>
<?php 
  // add alt&title image field attributes
  // we don't want escaped html in alt&title fields, so don't use safe_value
  $img_desc = isset($row->field_field_main_image[0]['raw']['field_media_description'][LANGUAGE_NONE][0][value]) ? strip_tags($row->field_field_main_image[0]['raw']['field_media_description'][LANGUAGE_NONE][0][value]) : '';
  $img_caption = isset($row->field_field_main_image[0]['raw']['field_media_caption'][LANGUAGE_NONE][0][value]) ? strip_tags($row->field_field_main_image[0]['raw']['field_media_caption'][LANGUAGE_NONE][0][value]) : '';
  $node_title = isset($row->node_title) ? strip_tags($row->node_title) : '';
  
  $alt = strlen($img_desc) ? $img_desc : $node_title;
  $title = strlen($node_title) ? $node_title : $img_caption;
  
  $add_fields = " alt='$alt' title='$title' ";
  $replace_img_txt = '<img';
  $replace_with = $replace_img_txt.$add_fields;
  
  print str_replace($replace_img_txt, $replace_with, $output); 
