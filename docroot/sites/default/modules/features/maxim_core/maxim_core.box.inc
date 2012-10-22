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

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'android_wallpaper_app';
  $box->plugin_key = 'simple';
  $box->title = 'Download Maxim\'s Apps';
  $box->description = 'Maxim Apps Block';
  $box->options = array(
    'body' => array(
      'value' => '<p><a href="https://itunes.apple.com/us/app/maximum-arcade/id524788321?mt=8" target="_blank"><img src="http://cdn2.maxim.com/maxim/sites/default/files/300x120_Maximum_Arcade.jpeg"></a></p>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['android_wallpaper_app'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'buzzfeed_widget';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Buzzfeed Widget';
  $box->options = array(
    'body' => array(
      'value' => '<div id="BF_WIDGET_1">&nbsp;</div>
<script type="text/javascript">
(function( ){
BF_WIDGET_JS=document.createElement("script"); BF_WIDGET_JS.type="text/javascript";
BF_WIDGET_SRC="http://ct.buzzfeed.com/wd/UserWidget?u=maxim.com&to=1&or=vb&wid=1&cb=" + (new Date()).getTime();
setTimeout(function() {document.getElementById("BF_WIDGET_1").appendChild(BF_WIDGET_JS);BF_WIDGET_JS.src=BF_WIDGET_SRC},1);
})();
</script>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['buzzfeed_widget'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'devils_cut_2012_sidebar';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Gallery Listing of Devil\'s Cut 2012 Slideshows';
  $box->options = array(
    'body' => array(
      'value' => '    <div id="dc-sidepanel">
      <div id="dc-girls">
        <div class="dc-row">
          <div class="item"><a href="/devils-cut/meet-aja"><img src="http://cdn2.maxim.com/maxim/sites/default/files/girl1.jpg" alt="devils cut girl"></a></div>
          <div class="item"><a href="/devils-cut/meet-becky"><img src="http://cdn2.maxim.com/maxim/sites/default/files/girl2.jpg" alt="devils cut girl"></a></div>
          <div class="item"><a href="/devils-cut/meet-brooke"><img src="http://cdn2.maxim.com/maxim/sites/default/files/girl3.jpg" alt="devils cut girl"></a></div>
        </div>
        <div class="dc-row">
          <div class="item"><a href="/devils-cut/meet-erin"><img src="http://cdn2.maxim.com/maxim/sites/default/files/girl4.jpg" alt="devils cut girl"></a></div>
          <div class="item"><a href="/devils-cut/meet-lindsey"><img src="http://cdn2.maxim.com/maxim/sites/default/files/girl5.jpg" alt="devils cut girl"></a></div>
          <div class="item"><a href="/devils-cut/meet-jordan"><img src="http://cdn2.maxim.com/maxim/sites/default/files/girl6.jpg" alt="devils cut girl"></a></div>
        </div>
      </div>
    </div>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['devils_cut_2012_sidebar'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'facebookrecentactivity';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Facebook Recent Activiy';
  $box->options = array(
    'body' => array(
      'value' => '<div class="module"><div class="fb-recommendations" data-site="maxim.com" data-app-id="230097690335739" data-action="like" data-width="300" data-height="290" data-header="true"></div></div>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['facebookrecentactivity'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'fb_hth_block';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Facebook hth sharing';
  $box->options = array(
    'body' => array(
      'value' => '<iframe src="/sites/default/libraries/php/fb_hth_share/widget.php" scrolling="no" id="fb-hth"></iframe>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['fb_hth_block'] = $box;

  $box = new stdClass();
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

  $box = new stdClass();
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

  $box = new stdClass();
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

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'in_this_issue';
  $box->plugin_key = 'simple';
  $box->title = 'Get Maxim Today';
  $box->description = 'In this issue';
  $box->options = array(
    'body' => array(
      'value' => '<div id="in-this-issue-content">
  [[{"type":"media","view_mode":"media_original","fid":"82302","attributes":{"alt":"","class":"media-image"}}]]
  <div id="in-this-issue-items">
      <ul>
          <li><a href="https://secure.palmcoastd.com/pcd/eSv?iMagId=0815B&i4Ky=I653" target="_blank">Only $1.09 an Issue!</a></li>
          <li><a href="http://www.maxim.com/digital-editions" target="_blank">Go Digital, get it anywhere</a></li>
          <li><a href="https://secure.palmcoastd.com/pcd/eSv?iMagId=0815B&i4Ky=IG96" target="_blank">Give it as a gift</a></li>
          <p>&nbsp;</p>
      </ul>
     <div class="btn-subscribe">
       <a href="https://secure.palmcoastd.com/pcd/eSv?iMagId=0815B&i4Ky=I650">Subscribe</a>
     </div>
  </div>
</div>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['in_this_issue'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'magazine_subscription_link';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Magazine Subscription Link';
  $box->options = array(
    'body' => array(
      'value' => '<p>Subscribe to <a href="https://secure.palmcoastd.com/pcd/eSv?iMagId=0815B&amp;i4Ky=I579" target="_blank">Maxim Magazine</a> | Download <a href="/digital-editions">Maxim Apps</a></p>
<p>&nbsp;</p>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['magazine_subscription_link'] = $box;

  $box = new stdClass();
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

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'partner_links_side_header';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'header text for partner links on the sidebar';
  $box->options = array(
    'body' => array(
      'value' => '<div class="partner-links-header-text"><div class="text-line">&nbsp;</div><div class="link-text">FROM OUR PARTNERS</div><div class="text-line">&nbsp;</div></div><div class="partner_large_img" style="clear:both;">&nbsp;</div>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['partner_links_side_header'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'slingshot_video';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'slingshot video rec widget';
  $box->options = array(
    'body' => array(
      'value' => '<script src="http://theslingshot.com/w/267/122/js"></script>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['slingshot_video'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'slingshot_widget';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'slingshot recommendation widget';
  $box->options = array(
    'body' => array(
      'value' => '<script src="http://theslingshot.com/w/256/122/js"></script>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['slingshot_widget'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'top_link_uk_channel';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Top Link to the UK Channel';
  $box->options = array(
    'body' => array(
      'value' => '<div class="uk-banner-content">
<a href="/uk">More content from Maxim UK</a>
<img src="http://cdn2.maxim.com/maxim/sites/default/themes/maxim_base/images/icon_flag_uk.png"/>
</div>',
      'format' => 'full_html',
    ),
    'additional_classes' => 'uk-banner',
  );
  $export['top_link_uk_channel'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'uk_channel_link';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Link to the UK Channel';
  $box->options = array(
    'body' => array(
      'value' => '<div class="uk-banner-content">
<a href="/uk">More content from Maxim UK</a>
<img src="http://cdn2.maxim.com/maxim/sites/default/themes/maxim_base/images/icon_flag_uk.png"/>
</div>',
      'format' => 'full_html',
    ),
    'additional_classes' => 'uk-banner',
  );
  $export['uk_channel_link'] = $box;

  return $export;
}
