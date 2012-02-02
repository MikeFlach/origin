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

  drupal_add_css(libraries_get_path('webforms').'/hot100vote.css');

  $js = <<<EOD
  jQuery(function(){
    jQuery('.overlay').each(function(){
      var OverlayIndex = jQuery(this).index();
      jQuery(this).mouseenter(function(){
        jQuery("." + OverlayIndex).show();
      }).mouseleave(function(){
        jQuery("." + OverlayIndex).fadeOut(100);
      });
    });

  });
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


/*
  <a href="http://www.maxim.com/amg/GIRLS/Girls+of+Maxim/Abby+Elliott" target="_blank" title="Click to view Abby Elliott's portfolio!">Abby Elliott</a><div class="overlay 0" style="display: none; "><img src="http://cdn2.maxim.com/maximonline/hot100vote/images/thumbs/Abby_elliot.png "></div>
  <a href="http://www.heavy.com/action/girls/2011/03/the-20-hottest-photos-of-adriana-lima/" target="_blank" title="Click to view Adriana Lima's portfolio!">Adriana Lima</a><div class="overlay 1" style="display: none; "><img src="http://cdn2.maxim.com/maximonline/hot100vote/images/thumbs/Adriana_Lima.png ">
 */