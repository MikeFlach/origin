<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
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
  // change fileIDs to images pointed to edit and add classes/colorbox js
  if ($view->current_display == 'hottie_admin_2014') {
    if (strpos($field->field, 'photo') !== false) {
      $file =  file_load($output);
      $file_path = str_replace('localhost', 'edit', file_create_url($file->uri));
      print theme('image', 
        array(
         'path' => $file_path,
         'width' => $img->width,                                
         'height' => $img->height,                                
         'alt' => t($img->title),
         'attributes' => array('class' => 'scale-img', 'onclick' => 'jQuery().colorbox({html:\'<img class="sm-cbox-pic" src="'.$file_path.'\"/>\'})')
        )
      );  
    }
    else {
      print $output;
    }    
  }