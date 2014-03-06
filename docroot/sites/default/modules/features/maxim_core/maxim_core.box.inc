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
  $box->delta = 'countdown_dos_mayo';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Countdown Clock - Dos De Mayo';
  $box->options = array(
    'body' => array(
      'value' => '<link rel="stylesheet" type="text/css" href="http://cdn2.maxim.com/maxim/sites/all/libraries/jquery/jquery.countdown.css">
<link rel="stylesheet" type="text/css" href="http://cdn2.maxim.com/maxim/sites/default/libraries/ads/countdown.css">
<div class="countdown_block">
	<!-- begin ad tag -->
	<script type="text/javascript" src="http://ad.doubleclick.net/adj/maxim.dart/;adid=53337272;sz=300x100;ord=[timestamp]?"></script>
	<noscript><a href="http://ad.doubleclick.net/jump/maxim.dart/;adid=53337272;sz=300x100;ord=[timestamp]?"><img src="http://ad.doubleclick.net/ad/maxim.dart/;adid=53337272;sz=300x100;ord=[timestamp]?" border="0" alt="" /></a></noscript>
	<IMG SRC="http://ad.doubleclick.net/ad/N3220.no_url_specifiedOX2494/B7437907.45;sz=1x1;pc=[TPAS_ID];ord=[timestamp]?" BORDER=0 WIDTH=1 HEIGHT=1 ALT="Advertisement">
	<!-- end ad tag -->
	<div class="clearfix"><div id="countdown_clock"></div></div>
</div>
<script type="text/javascript" src="http://cdn2.maxim.com/maxim/sites/all/libraries/jquery/jquery.countdown.min.js"></script>
<script type="text/javascript">
	jQuery(function(){
		var liftoffTime = new Date(2013,4,3,1,0);
		jQuery(\'#countdown_clock\').countdown({
			until: liftoffTime,
			format: "DHMS",
		});
	});
</script>',
      'format' => 'full_html',
    ),
  );
  $export['countdown_dos_mayo'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'crowd_ignite';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Crowd Ignite Partner Links';
  $box->options = array(
    'body' => array(
      'value' => '<script type=\'text/javascript\'>
  var _CI = _CI || {};
  (function() {
    var script = document.createElement(\'script\');
    ref = document.getElementsByTagName(\'script\')[0];
    _CI.counter = (_CI.counter) ? _CI.counter + 1 : 1;
    document.write(\'<div id="_CI_widget_\');
    document.write(_CI.counter+\'" style="display: inline-block"></div>\');
    script.type = \'text/javascript\';
    script.src = \'http://widget.crowdignite.com/widgets/28642?_ci_wid=_CI_widget_\'+_CI.counter;
    script.async = true;
    ref.parentNode.insertBefore(script, ref);
  })();
</script>
<style>
  #_ci_widget_div_28642{
    display: inline-block !important;
  }
  #_ci_widget_div_28642 table{border-spacing:0;}
  #widget_table_28642 td{display:inline-block;text-align:left;width:150px!important;}
  #widget_table_28642 td:first-child{text-align:left;}
  #widget_table_28642 td{text-align:right;}
  #widget_table_28642 a{color:#333!important;font-family:Helvetica,Arial,Sans-serif;text-decoration:none;line-height:18px;}
  #widget_table_28642 img{border:medium none;}
  #widget_table_28642 tr:first-child td{margin-bottom:10px;}
  @media (max-width: 664px) {
    #_ci_widget_div_28642 {float:left!important;width:auto;}
    #_ci_widget_div_28642 table {border-spacing:0;height:auto;width:auto;}
    #widget_table_28642 td:first-child {text-align:center!important;}
    #widget_table_28642 td {display:inline-block;margin-left:30px!important;text-align:right!important;width:150px!important;}
    #_CI_widget_1{
      display: inline-block !important;
    }
  }
  /*@media (max-width: 800px) {
    #_ci_widget_div_28642 table {margin-left:10px!important;}
    #_CI_widget_1{
      display: inline-block !important;
    }
  }*/
  @media (max-width: 464px) {
    #_CI_widget_1{
      display: inline-block !important;
    }
    #_ci_widget_div_28642 table {margin-left:0!important;}
    #widget_table_28642 td:first-child {text-align:left!important;}
    #widget_table_28642 td:first-child div {text-align:left!important;}
    #widget_table_28642 td {text-align:right!important;margin-left:0!important;}
  }
</style>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['crowd_ignite'] = $box;

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
  $box->delta = 'footer_copyright';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Footer Copyright';
  $box->options = array(
    'body' => array(
      'value' => '<p style="text-align: center;">© 2013 Alpha Media Publishing, Inc. All rights reserved Use of this site constitutes your acceptance of our <a href="http://www.maxim.com/corporate/terms-conditions" target="_blank">User Agreement</a> and <a href="http://www.maxim.com/corporate/privacy-policy" target="_blank">Privacy Policy</a>. Your <a href="http://www.maxim.com/corporate/privacy-policy#California" target="_blank">California Privacy Rights</a>. The material on this site may not be reproduced, distributed, transmitted, cached or otherwise used, except with the prior written permission of Alpha Media.</p>
',
      'format' => 'filtered_html',
    ),
    'additional_classes' => '',
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
  $box->title = '';
  $box->description = 'In this issue';
  $box->options = array(
    'body' => array(
      'value' => '<h4 class="rhs-block-title">Get Maxim Today</h4>
<div id="in-this-issue-content">
  <a href="https://ssl.palmcoastd.com/0815B/apps/3OFFERS?ikey=I**PA4" target="_blank"><img src="http://cdn2.maxim.com/maxim/sites/default/files/mini_mag_cover.jpg"></a>
  <div id="in-this-issue-items">
      <ul>
          <li><a href="https://ssl.palmcoastd.com/0815B/apps/3OFFERS?ikey=I**PA4" target="_blank">Only $1.09 an Issue!</a></li>
          <li><a href="http://www.maxim.com/digital-editions" target="_blank">Go Digital, get it anywhere</a></li>
          <li><a href="https://secure.palmcoastd.com/pcd/eSv?iMagId=0815B&i4Ky=IG96" target="_blank">Give it as a gift</a></li>
          <p>&nbsp;</p>
      </ul>
     <div class="btn-subscribe">
       <a href="https://ssl.palmcoastd.com/0815B/apps/3OFFERS?ikey=I**PA6">Subscribe</a>
     </div>
  </div>
</div>

<script>jQuery(function() { if (window.location.href.indexOf("/uk") > -1 || jQuery(\'.uk-banner\').length > 0) { jQuery("#in-this-issue-content .btn-subscribe a").attr(\'href\',\'/digital-editions\'); } });</script>',
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
      'value' => '<p>Subscribe to <a href="https://ssl.palmcoastd.com/0815B/apps/3OFFERS?ikey=I**PA7" target="_blank">Maxim Magazine</a> | Download <a href="/digital-editions">Maxim Apps</a></p>
<p>&nbsp;</p>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['magazine_subscription_link'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'match_rail_widget';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'match widget';
  $box->options = array(
    'body' => array(
      'value' => '<!-- iframe/script/href/image tag -->
<IFRAME SRC="http://media.match.com/cookE/geoip/iframe?spacedesc=12194240_12194238_300x200_12194239_12194240&target=_blank&@CPSC@=" WIDTH=300 HEIGHT=200 SCROLLING="No" FRAMEBORDER=0 MARGINHEIGHT=0 MARGINWIDTH=0>
<SCRIPT SRC="http://media.match.com/cookE/geoip/jscript?spacedesc=12194240_12194238_300x200_12194239_12194240&ML_NIF=Y&target=_blank&@CPSC@="></SCRIPT>
<NOSCRIPT>
  <A HREF="http://media.match.com/cookE/geoip/click?spacedesc=12194240_12194238_300x200_12194239_12194240&ML_NIF=Y" TARGET="_blank">
  <IMG SRC="http://media.match.com/cookE/geoip/image?spacedesc=12194240_12194238_300x200_12194239_12194240&ML_NIF=Y" WIDTH=300 HEIGHT=200 ALT="Click Here" BORDER=0>
  </A>
</NOSCRIPT>
</IFRAME>',
      'format' => 'full_html',
    ),
  );
  $export['match_rail_widget'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'max_press_block';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'show the max icon for author pages';
  $box->options = array(
    'body' => array(
      'value' => '<img src="http://cdn2.maxim.com/maxim/sites/default/files/press_max.png" width="103">',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['max_press_block'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'maxim_newsletter';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Subscribe to Maxim\'s Newsletter';
  $box->options = array(
    'body' => array(
      'value' => '<a href="http://www.maxim.com/subscribe/form"><img src="http://cdn2.maxim.com/maxim/sites/default/files/sixpack_newsletter_promo.jpg"></a><p/>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['maxim_newsletter'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'mostrecenttweets';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Most Recent Tweets';
  $box->options = array(
    'body' => array(
      'value' => '<a class="twitter-timeline" href="https://twitter.com/MaximMag" data-widget-id="308681926607257600">Tweets by @MaximMag</a>
<script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['mostrecenttweets'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'outbrain_articles';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Outbrain Widget - Articles';
  $box->options = array(
    'body' => array(
      'value' => '<div class="OUTBRAIN" data-widget-id="AR_1" data-ob-template="maxim" ></div>
<script type="text/javascript" src="http://widgets.outbrain.com/outbrain.js"></script>',
      'format' => 'full_html',
    ),
  );
  $export['outbrain_articles'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'outbrain_tv';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Outbrain Widget - Maxim TV';
  $box->options = array(
    'body' => array(
      'value' => '<div class="OUTBRAIN" data-widget-id="VR_1" data-ob-template="maxim" ></div>
<script type="text/javascript" src="http://widgets.outbrain.com/outbrain.js"></script>
',
      'format' => 'full_html',
    ),
  );
  $export['outbrain_tv'] = $box;

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
  $box->delta = 'social_media';
  $box->plugin_key = 'simple';
  $box->title = 'Follow Us';
  $box->description = 'Social Media';
  $box->options = array(
    'body' => array(
      'value' => '<div class="social-media clearfix">
<ul>
<li><a href="https://www.facebook.com/maximmagazine" target="_blank"><img src="http://cdn2.maxim.com/maxim/sites/default/themes/maxim_base/images/facebook.png" height="40" width="40" alt="Facebook" title="Facebook" /></a></li>
<li><a href="https://twitter.com/MaximMag" target="_blank"><img src="http://cdn2.maxim.com/maxim/sites/default/themes/maxim_base/images/twitter.png" height="40" width="40" alt="Twitter" title="Twitter" /></a></li>
<li><a href="https://plus.google.com/+MaximMag" target="_blank"><img src="http://cdn2.maxim.com/maxim/sites/default/themes/maxim_base/images/googleplus.png" height="40" width="40" alt="Google+" title="Google+" /></a></li>
<li><a href="http://instagram.com/maximmag/" target="_blank"><img src="http://cdn2.maxim.com/maxim/sites/default/themes/maxim_base/images/instagram.png" height="40" width="40" alt="Instagram" title="Instagram" /></a></li>
<li><a href="https://www.youtube.com/user/videosbyMaxim" target="_blank"><img src="http://cdn2.maxim.com/maxim/sites/default/themes/maxim_base/images/youtube.png" height="40" width="40" alt="YouTube" title="YouTube" /></a></li>
</ul>
</div>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['social_media'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'sub_info';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Magazine Subscription contact link';
  $box->options = array(
    'body' => array(
      'value' => '<div id="contact-form-subscription">Do you have questions about your Maxim Magazine subscription? &nbsp;<a href="http://www.maxim.com/corporate/subscription-issues">Click here.</a></div>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['sub_info'] = $box;

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
