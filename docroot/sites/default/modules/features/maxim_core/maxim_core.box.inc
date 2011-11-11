<?php
/**
 * @file
 * maxim_core.box.inc
 */

/**
 * Implements hook_default_box().
 */
function maxim_core_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'facebookrecentactivity';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Facebook Recent Activiy';
  $box->options = array(
    'body' => array(
      'value' => '<div class="module"><iframe allowtransparency="true" frameborder="0" scrolling="no" src="http://www.facebook.com/plugins/activity.php?site=maxim.com&amp;width=300&amp;height=340&amp;header=true&amp;colorscheme=light&amp;recommendations=true" style="background-color: rgb(255, 255, 255); border: medium none; overflow: hidden; width: 300px; height: 340px;"></iframe></div>',
      'format' => 'full_html',
    ),
  );
  $export['facebookrecentactivity'] = $box;

  return $export;
}