<?php

function maxim_base_alpha_preprocess_page(&$vars) {
  nest_content_regions($vars);
  add_google_analytics($vars);
  add_syndication_beacons($vars);
  add_vertacuity_monitor($vars);
  add_jumbotron($vars);
  add_menu($vars);
	blackout_theme($vars);
	hide_channel_feature_when_pager($vars);
  // drupal_add_js(libraries_get_path('wallpaper') . '/wallpaper.js');
}

function blackout_theme(&$vars) {
	if ( strpos($_SERVER['REQUEST_URI'], 'gallery/')  || strpos($_SERVER['REQUEST_URI'], 'slideshow/')  ){
	  drupal_add_css( drupal_get_path('theme', 'maxim_base') . '/css/slideshow.css',
	    array('group' => CSS_THEME, 'every_page' => FALSE) );
	}
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

    var _gaq = _gaq || []; _gaq.push(["_setAccount", "UA-4245914-1"]); _gaq.push(["_trackPageview"]);(function() {var ga = document.createElement("script");ga.type = "text/javascript";ga.async = true;ga.src = ("https:" == document.location.protocol ? "https://ssl" : "http://www") + ".google-analytics.com/ga.js";var s = document.getElementsByTagName("script")[0];s.parentNode.insertBefore(ga, s);})();
CODE;
  drupal_add_js($ga_code, array('type' => 'inline', 'scope' => 'header'));
}


/**
 * Adds 'comscore', and 'quantcast', and nielsen syndicated research beacons.
 */
function add_syndication_beacons(&$vars) {
  $syndication_data = '';

  $syndication_data .= <<<EOD
  <script>
  <!-- Begin comScore Tag -->
    document.write(unescape("%3Cscript src='" + (document.location.protocol == "https:" ? "https://sb" : "http://b") + ".scorecardresearch.com/beacon.js' %3E%3C/script%3E"));
  </script>
  <script type="text/javascript">
    COMSCORE.beacon({
    c1:2,
    c2:6036003,
    c3:"",
    c4:"",
    c5:"",
    c6:"",
    c15:""
    });
  </script>
  <!-- <noscript><img src="http://b.scorecardresearch.com/b?c1=2&amp;c2=6036003&amp;c3=&amp;c4=&amp;c5=&amp;c6=&amp;c15=&amp;cv=1.3&amp;cj=1" style="display:none" width="0" height="0" alt="comscore" /></noscript>-->
  <!-- End comScore Tag -->
EOD;

  $syndication_data .= <<<EOD
  <!-- Start Quantcast tag -->
    <script type="text/javascript" src="http://edge.quantserve.com/quant.js"></script>
    <script type="text/javascript">_qacct='p-94eQvyyY-EFy2';quantserve();</script>
  <!--<noscript>
    <a href="http://www.quantcast.com/p-94eQvyyY-EFy2"><img src="http://pixel.quantserve.com/pixel/p-94eQvyyY-EFy2.gif" style="display: none" height="1" width="1" alt="Quantcast" /></a>
  </noscript>-->
  <!-- End Quantcast tag -->
EOD;

  $syndication_data .= <<<EOD
<!-- start nielsen tag -->
<script type="text/javascript" src="http://cdn2.maxim.com/maxim/files/maxim2/Maxim/static_files/js/external/nielsen_digital_ratings_NSE.js"></script>
<!-- START Nielsen Online SiteCensus V6.0 -->
<!-- COPYRIGHT 2010 Nielsen Online -->
<script type="text/javascript">
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

  $vars['page']['footer']['beacons'] = array('#markup' => $syndication_data);
}

/**
 * Adds Vertical acuity js include.
 */
function add_vertacuity_monitor(&$vars) {
  drupal_add_js('http://scripts.verticalacuity.com/vat/mon/vtw.js', 'external');
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
 * Adds jumbotron javascript file to the sites frontpage.
 */
function add_jumbotron(&$vars) {
  if (drupal_is_front_page()) {
    drupal_add_js(libraries_get_path('jumbotron') . '/jumbotron.jquery.js');
    drupal_add_css(libraries_get_path('jumbotron') . '/jumbotron.jquery.css');
  }
}

function add_menu(&$vars){
  drupal_add_js( drupal_get_path('theme', 'maxim_base') . '/js/nav.overlay.js');
}

