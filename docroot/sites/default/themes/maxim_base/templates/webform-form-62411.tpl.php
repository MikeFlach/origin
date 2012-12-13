<?php

/**
 * @file
 * Customize the display of a complete webform.
 *
 * This file may be renamed "webform-form-[nid].tpl.php" to target a specific
 * webform on your site. Or you can leave it "webform-form.tpl.php" to affect
 * all webforms on your site.
 *
 * Available variables:
 * - $form: The complete form array.
 * - $nid: The node ID of the Webform.
 *
 * The $form array contains two main pieces:
 * - $form['submitted']: The main content of the user-created form.
 * - $form['details']: Internal information stored by Webform.
 */


  $js = <<<EOD
    (function($){ $(document).ready(function() {
      $('#edit-submitted-hot100-write-in').focus(function() {
        if (this.value == 'Suggest a girl if she\'s not below!') {
            $(this).val("");
        }
      }).blur(function() {
        if ($.trim(this.value) == "") {
            $(this).val('Suggest a girl if she\'s not below!');
        }
      });
      $("#webform-client-form-62411").submit(function(e) {
        if ($('#edit-submitted-hot100-write-in').val() == 'Suggest a girl if she\'s not below!') {
          $('#write-in-status').html("Oops! You forgot to enter a name.").addClass('write-in-error');
          $('#write-in-status').show();
          $('#write-in-status').fadeOut(8000);
          e.preventDefault();
        }
      })
    })
  })(jQuery);
EOD;
  drupal_add_js($js, array('type' => 'inline', 'scope' => 'footer'));
 
  // If editing or viewing submissions, display the navigation at the top.
  if (isset($form['submission_info']) || isset($form['navigation'])) {
    print drupal_render($form['navigation']);
    print drupal_render($form['submission_info']);
  }

  // Print out the main part of the form.
  // Feel free to break this up and move the pieces within the array.
  print drupal_render($form['submitted']);

  // Always print out the entire $form. This renders the remaining pieces of the
  // form that haven't yet been rendered above.
  print drupal_render_children($form);

  // Print out the navigation again at the bottom.
  if (isset($form['submission_info']) || isset($form['navigation'])) {
    unset($form['navigation']['#printed']);
    print drupal_render($form['navigation']);
  }
