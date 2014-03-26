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
  $img_fid_array = explode(":", $output);
  if (!empty($img_fid_array)) {
    foreach ($img_fid_array as $fid) {
      $file_path = file_load($fid)->uri;
      $img = theme(
        'image', 
        array(
          'path' => $file_path, 
          'width' => 150, 
          'height' =>200,
          'attributes' => array('onclick' => 'jQuery().colorbox({html:\'<img style = "max-height:700px; max-width:700px" class="sm-cbox-pic" src="'. file_create_url(file_load($fid)->uri) .'\"/>\'})')
        )
      );
      $markup[] = array(
        '#type' => 'markup',
        '#markup' => $img,
        '#prefix' => "<span class='model-image'>",
        '#suffix' => "</span>",  
      );
    }
    
    $img_output = array(
      '#type' => 'markup',
      '#markup' => render($markup),
      '#prefix' => '<div class="all-model-images">',
      '#suffix' => '</div>',  
    ); 
    
    $output = trim(render($img_output));
  }
  print $output;?>