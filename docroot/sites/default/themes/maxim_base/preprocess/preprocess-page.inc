<?php

function maxim_base_alpha_preprocess_page(&$vars) {
  nest_content_regions($vars);
  add_google_analytics($vars);
  //add_google_plus($vars);
  add_javascript($vars);
	hide_channel_feature_when_pager($vars);
  blackout_theme($vars);
  add_syndication_beacons($vars);
}

function blackout_theme(&$vars) {
	if ( strpos($_SERVER['REQUEST_URI'], 'gallery/')  || strpos($_SERVER['REQUEST_URI'], 'slideshow/')  ){
	  drupal_add_css( drupal_get_path('theme', 'maxim_base') . '/css/slideshow.css',
	    array('group' => CSS_THEME, 'every_page' => FALSE) );
	}
}

/**
 * Add JS to pages
 */
function add_javascript($vars) {
  $maxim_vars = array();
  $maxim_vars['channel'] = array();
  add_menu($vars);
  drupal_add_js(libraries_get_path('jquery') . '/jquery.ba-resize.min.js', array('weight' => -8));
  drupal_add_js( drupal_get_path('theme', 'maxim_base') . '/js/common.js', array('weight' => -1));
  drupal_add_js('http://platform.twitter.com/anywhere.js?id=bv56eopiTVBpYEHJYi1plg&v=1', 'external');
  if (drupal_is_front_page()) {
    add_jumbotron($vars);
    // Set home channel in javascript: Drupal.settings.Maxim.channel
    $maxim_vars['channel'] = array('frontpage');
  }
  drupal_add_js(array('Maxim' => $maxim_vars), 'setting');
  // drupal_add_js(libraries_get_path('wallpaper') . '/wallpaper.js');
}

/**
 * Nests the regions 'feature', 'content' and 'sidebar_first' into the 'content container' region.
 */
function nest_content_regions(&$vars) {
  $vars['page']['content']['content']['content_container']['#sorted'] = FALSE;

  if (!empty($vars['page']['#excluded']['feature'])) {
    $vars['page']['#excluded']['feature']['#data']['weight'] = 1;
    $vars['page']['#excluded']['feature']['#data']['wrapper_css'] = '.alpha .omega';
    $vars['page']['content']['content']['content_container']['feature'] = $vars['page']['#excluded']['feature'];
  }

  if (!empty($vars['page']['#excluded']['content'])) {
    $vars['page']['#excluded']['content']['#data']['weight'] = 3;
    $vars['page']['#excluded']['content']['#data']['wrapper_css'] = '.alpha';
    $vars['page']['content']['content']['content_container']['content'] = $vars['page']['#excluded']['content'];
  }

  if (!empty($vars['page']['#excluded']['sidebar_first'])) {
    $vars['page']['#excluded']['sidebar_first']['#data']['weight'] = 5;
    $vars['page']['#excluded']['sidebar_first']['#data']['wrapper_css'] = '.omega';
    $vars['page']['content']['content']['content_container']['sidebar_first'] = $vars['page']['#excluded']['sidebar_first'];
  }

}

/**
 * Add Google Analytics to head
 */
function add_google_analytics(&$vars) {
  $ga_code = '';

  $ga_code .= <<<CODE
    var _gaq = _gaq || []; _gaq.push(["_setAccount", "UA-4245914-1"]); _gaq.push(["_trackPageview"]);(function() {var ga = document.createElement("script");ga.type = "text/javascript";ga.async = true;ga.src = ("https:" == document.location.protocol ? "https://ssl" : "http://www") + ".google-analytics.com/ga.js";var s = document.getElementsByTagName("script")[0];s.parentNode.insertBefore(ga, s);})();
    (function($){
      $(document).ready(function() {
        $(document.body).click(function(event) {
          // Catch the closest surrounding link of a clicked element.
          $(event.target).closest("a,area").each(function() {
            if(this.href){
              // Track links
              _gaq.push(["_trackEvent", "Outbound links", this.hostname, this.href]);
            }
          });
        });
      });
    })(jQuery);
CODE;
  drupal_add_js($ga_code, array('type' => 'inline', 'scope' => 'header'));

  $ga_social_code = '';
  $ga_social_code .= <<<CODE
      window.fbAsyncInit = function() {
      FB.init({
        appId      : '246188768809841', // ENTER your FB App ID
        //channelUrl : '//WWW.YOUR_DOMAIN.COM/channel.html', // Channel File
        status     : true, // check login status
        cookie     : true, // enable cookies to allow the server to access the session
        xfbml      : true  // parse XFBML
      });
      _ga.trackFacebook(); //Google Analytics tracking
    };

    // Load the Facebook SDK Asynchronously
    (function(d){
      var js, id = 'facebook-jssdk', ref = d.getElementsByTagName('script')[0];
      if (d.getElementById(id)) {return;}
      js = d.createElement('script'); js.id = id; js.async = true;
      js.src = "//connect.facebook.net/en_US/all.js";
      ref.parentNode.insertBefore(js, ref);
    }(document));

    window.twttr = (function (d,s,id) {
      var t, js, fjs = d.getElementsByTagName(s)[0];
      if (d.getElementById(id)) return; js=d.createElement(s); js.id=id;
      js.src="//platform.twitter.com/widgets.js"; fjs.parentNode.insertBefore(js, fjs);
      return window.twttr || (t = { _e: [], ready: function(f){ t._e.push(f) } });
    }(document, "script", "twitter-wjs"));

    // Wait for the asynchronous resources to load
    twttr.ready(function(twttr) {
        _ga.trackTwitter(); //Google Analytics tracking
    });
CODE;
  drupal_add_js($ga_social_code, array('type' => 'inline', 'scope' => 'header'));
  drupal_add_js(libraries_get_path('ga_social_tracking').'/ga_social_tracking.js', 'file');
}

/**
 * Add Google Plus code to pages
 */
function add_google_plus(&$vars) {
  $gplus_async_code = '';
  $gplus_code = '';

  drupal_add_js('https://apis.google.com/js/plusone.js', 'external');

  $gplus = array(
    '#tag' => 'link', // The #tag is the html tag - <link />
    '#attributes' => array( // Set up an array of attributes inside the tag
      'href' => 'https://plus.google.com/109577250522656249315',
      'rel' => 'publisher',
    ),
  );
  drupal_add_html_head($gplus, 'google_plus_pub');

 /* $gplus_async_code .= <<<CODE
    (function() {
      var po = document.createElement('script'); po.type = 'text/javascript'; po.async = true;
      po.src = 'https://apis.google.com/js/plusone.js';
      var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(po, s);
    })();
CODE;
  drupal_add_js($gplus_async_code, array('type' => 'inline', 'scope' => 'footer')); */
}

/**
 * Adds 'comscore', and 'quantcast', and nielsen syndicated research beacons.
 */
function add_syndication_beacons(&$vars) {
  $syndication_data = '';

  $syndication_data .= <<<EOD
  <!-- Begin comScore Tag -->
  <script>
    var _comscore = _comscore || [];
    _comscore.push({ c1: "2", c2: "6036003" });
    (function() {
      var s = document.createElement("script"), el = document.getElementsByTagName("script")[0]; s.async = true;
      s.src = (document.location.protocol == "https:" ? "https://sb" : "http://b") + ".scorecardresearch.com/beacon.js";
      el.parentNode.insertBefore(s, el);
    })();
  </script>
  <noscript>
    <img src="http://b.scorecardresearch.com/p?c1=2&c2=6036003&cv=2.0&cj=1" />
  </noscript>
  <!-- End comScore Tag -->
EOD;

  $syndication_data .= <<<EOD
  <!-- Quantcast Tag -->
  <script>
    var _qevents = _qevents || [];
    (function() {
    var elem = document.createElement('script');
    elem.src = (document.location.protocol == "https:" ? "https://secure" : "http://edge") + ".quantserve.com/quant.js";
    elem.async = true;
    elem.type = "text/javascript";
    var scpt = document.getElementsByTagName('script')[0];
    scpt.parentNode.insertBefore(elem, scpt);
    })();
    _qevents.push({
    qacct:"p-94eQvyyY-EFy2"
    });
  </script>
  <noscript>
    <div style="display:none;">
    <img src="//pixel.quantserve.com/pixel/p-94eQvyyY-EFy2.gif" border="0" height="1" width="1" alt="Quantcast"/>
    </div>
  </noscript>
  <!-- End Quantcast tag -->
EOD;

  $syndication_data .= <<<EOD
<!-- start nielsen tag -->
<script src="http://cdn2.maxim.com/maxim/files/maxim2/Maxim/static_files/js/external/nielsen_digital_ratings_NSE.js"></script>
<!-- START Nielsen Online SiteCensus V6.0 -->
<!-- COPYRIGHT 2010 Nielsen Online -->
<script>
  (function () {
    var d = new Image(1, 1);
    d.onerror = d.onload = function () {
      d.onerror = d.onload = null;
    };
    d.src = ["//secure-us.imrworldwide.com/cgi-bin/m?ci=us-204353h&cg=0&cc=1&si=", escape(window.location.href), "&rp=", escape(document.referrer), "&ts=compact&rnd=", (new Date()).getTime()].join('');
  })();
</script>
<noscript>
  <div>
    <img src="//secure-us.imrworldwide.com/cgi-bin/m?ci=us-204353h&amp;cg=0&amp;cc=1&amp;ts=noscript" width="1" height="1" alt="" />
  </div>
</noscript>
<!-- END Nielsen Online SiteCensus V6.0 -->
<!-- end nielsen tag -->
EOD;

  $syndication_data .= <<<EOD
<!--PubMatic Universal Pixel tag (Javascript) http://www.maxim.com/US-->
<script type='text/javascript'>
var pubId=30175;
var pixId=127;
</script>
<script src='http://ads.pubmatic.com/AdServer/js/universalpixel.js' type='text/javascript'>
</script>
<!-- End PubMatic Universal Pixel tag -->
EOD;

  $syndication_data .= <<<EOD
<!-- sailthru horizon data collection script -->
<script type="text/javascript" src="http://ak.sail-horizon.com/horizon/v1.js"></script>
<script type="text/javascript">
jQuery(function() {
    // Sailthru Concierge
    if (window.Sailthru) {
        Sailthru.setup({
            domain: 'horizon.maxim.com'
        });
    }
});
</script>
<!-- end sailthru horizon data collection script -->
EOD;

  $vars['page']['footer']['beacons'] = array('#markup' => $syndication_data);
}

/*
 * Remove the channel feature view when there is a pager present
 */
function hide_channel_feature_when_pager(&$vars) {
	if ( strpos($_SERVER['REQUEST_URI'], 'page=') !== FALSE ) {
		if (!empty($vars['page']['content']['content']['content_container']['feature']['views_channel_feature-block'])) {
			$vars['page']['content']['content']['content_container']['feature']['views_channel_feature-block']['#printed'] = TRUE;
		}
	}
}

/**
 * Adds jumbotron javascript/css files.
 */
function add_jumbotron(&$vars) {
  drupal_add_js(libraries_get_path('jumbotron') . '/jumbotron.jquery.js');
  drupal_add_css(libraries_get_path('jumbotron') . '/jumbotron.jquery.css');
}

function add_menu(&$vars){
  drupal_add_js( drupal_get_path('theme', 'maxim_base') . '/js/nav.overlay.js');
}

