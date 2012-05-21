<?php
/**
 * @file
 * maxim_webform_views.box.inc
 */

/**
 * Implements hook_default_box().
 */
function maxim_webform_views_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'hth_axe_profilelink';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Axe Promo link for hth profile pages';
  $box->options = array(
    'body' => array(
      'value' => '<p style="font-size:1.6em;"><a href="http://www.maxim.com/keepingupwithhotties" target="_blank">Keep Up With The Hotties Here</a></p>
<p>&nbsp;</p>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['hth_axe_profilelink'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'hth_axe_sponsor';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'hth axe sponsorship button';
  $box->options = array(
    'body' => array(
      'value' => '<!-- begin ad tag -->
<iframe src="http://ad.doubleclick.net/adi/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?" width="145" height="40" marginwidth="0" marginheight="0" frameborder="0" scrolling="no">
<script type="text/javascript" src="http://ad.doubleclick.net/adj/maxim.dart/;adid=257123122;sz=145x40;abr=!ie;ord=[timestamp]?"></script>
</iframe>
<noscript><a href="http://ad.doubleclick.net/jump/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?"><img src="http://ad.doubleclick.net/ad/maxim.dart/;adid=257123122;sz=145x40;ord=[timestamp]?" border="0" alt="" /></a></noscript>
<!-- end ad tag -->',
      'format' => 'full_html',
    ),
  );
  $export['hth_axe_sponsor'] = $box;

  return $export;
}
