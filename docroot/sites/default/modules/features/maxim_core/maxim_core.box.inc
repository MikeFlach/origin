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
      'value' => '<div class="module"><div class="fb-recommendations" data-site="maxim.com" data-app-id="230097690335739" data-action="like,share,recommendation" data-width="300" data-height="290" data-header="true"></div></div>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['facebookrecentactivity'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'follow_us';
  $box->plugin_key = 'simple';
  $box->title = 'Follow us:';
  $box->description = 'Follow us buttons';
  $box->options = array(
    'body' => array(
      'value' => '<div class="fb-like-box" data-href="http://www.facebook.com/maximmagazine" data-width="300" data-show-faces="false" data-stream="false" data-header="true"></div>
<div id="fb-root"></div>
<script>(function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id)) return;
  js = d.createElement(s); js.id = id;
  js.src = "//connect.facebook.net/en_US/all.js#xfbml=1&appId=230097690335739";
  fjs.parentNode.insertBefore(js, fjs);
}(document, \'script\', \'facebook-jssdk\'));</script>
<a href="https://twitter.com/maximmag" class="twitter-follow-button" data-show-count="true" data-size="large">Follow @maximmag</a>
<script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>',
      'format' => 'full_html',
    ),
  );
  $export['follow_us'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'footer_copyright';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Footer Copyright';
  $box->options = array(
    'body' => array(
      'value' => '<p style="text-align: center;">&nbsp;"Maxim Digital", "MAXIM", "MAXIM ONLINE", "Maximonline.com", "Maxim.com" and the "M" Logo" are registered trademarks owned by Alpha Media Group Inc. "Maxim.com" and "MAXIM TO GO" are trademark owned by Alpha Media Group Inc.</p>
',
      'format' => 'filtered_html',
    ),
  );
  $export['footer_copyright'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'footer_max';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Max in Footer';
  $box->options = array(
    'body' => array(
      'value' => '<p><a href="/"><img alt="" src="/sites/default/themes/maxim_base/images/devil_side.png" style="width: 103px; height: 161px; "></a></p>',
      'format' => 'full_html',
    ),
  );
  $export['footer_max'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'in_this_issue';
  $box->plugin_key = 'simple';
  $box->title = 'In This Issue';
  $box->description = 'In this issue';
  $box->options = array(
    'body' => array(
      'value' => '<div id="in-this-issue-content">
  [[{"type":"media","view_mode":"media_original","fid":"82302","attributes":{"alt":"","class":"media-image"}}]]
  <div id="in-this-issue-items">
      <ul>
          <li><a href="https://secure.palmcoastd.com/pcd/eSv?iMagId=0815B&i4Ky=I650" target="_blank">30 Rock\'s Katrina Bowden</a></li>
          <li><a href="https://secure.palmcoastd.com/pcd/eSv?iMagId=0815B&i4Ky=I650" target="_blank">Where to Meet Women Who Want to Use You For Sex</a></li>
          <li><a href="https://secure.palmcoastd.com/pcd/eSv?iMagId=0815B&i4Ky=I650" target="_blank">Is Everything Better With a Monkey?  Find out in this issue!</a></li>
      </ul>
     <div class="btn-subscribe">
       <a href="https://secure.palmcoastd.com/pcd/eSv?iMagId=0815B&i4Ky=I650">Subscribe</a>   
     </div>
  </div>
</div>',
      'format' => 'full_html',
    ),
  );
  $export['in_this_issue'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'mostrecenttweets';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Most Recent Tweets';
  $box->options = array(
    'body' => array(
      'value' => '<div class="module module-twitter"><script src="http://widgets.twimg.com/j/2/widget.js"></script><script>new TWTR.Widget({version: 2, type: \'search\', search: \'maximmag\', interval: 30000, title: \'Maxim Magazine\', subject: \'\', width: 300, height: 220, theme: {	shell: { background: \'#8ec1da\',  color: \'#ffffff\' },tweets: { background: \'#ffffff\', color: \'#444444\', links: \'#1985b5\' } }, features: { scrollbar: false, loop: true,	live: true,	hashtags: true,	timestamp: true, avatars: true,	toptweets: true, behavior: \'default\' }}).render().start();</script></div>',
      'format' => 'full_html',
    ),
  );
  $export['mostrecenttweets'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'va_article';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Vertical Acuity Article';
  $box->options = array(
    'body' => array(
      'value' => '<div class="va-widget va-widget-ref-maxim-article2"></div>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['va_article'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'va_slideshow';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Vertical Acuity Slideshow';
  $box->options = array(
    'body' => array(
      'value' => '<div class="va-widget va-widget-ref-maxim-slideshow2"></div>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['va_slideshow'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'va_video';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Vertical Acuity Video';
  $box->options = array(
    'body' => array(
      'value' => '<div class="va-widget va-widget-ref-maxim-video2"></div>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['va_video'] = $box;

  return $export;
}
