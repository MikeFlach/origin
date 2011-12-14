<?php
/**
 * @file views-view.tpl.php
 * Main view template
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>

<?php

drupal_add_js(libraries_get_path('slideshow') . '/jquery.anythingslider.js');
drupal_add_js(libraries_get_path('slideshow') . '/jquery.colorbox.js');
drupal_add_js(libraries_get_path('slideshow') . '/jquery.easing.1.2.js');
//drupal_add_js(libraries_get_path('slideshow') . '/jquery.slideshow.js');
drupal_add_css(libraries_get_path('slideshow') . '/colorbox.css');
drupal_add_css(libraries_get_path('slideshow') . '/slider.css');

$js = <<<EOD
  <script type="text/javascript">
    function formatText(index, panel) {
      return index + "";
    }

    function initSlideshow() {
      jQuery('.anythingSlider').anythingSlider({
        resizeContents: false,
        easing: "easeInOutExpo",                                // Anything other than "linear" or "swing" requires the easing plugin
        autoPlay: false,                                        // This turns off the entire FUNCTIONALY, not just if it starts running or not.
        delay: 5000,                                            // How long between slide transitions in AutoPlay mode
        startStopped: false,                                    // If autoPlay is on, this can force it to start stopped
        animationTime: 600,                                     // How long the slide transition takes
        hashTags: false,                                        // Should links change the hashtag in the URL?
        buildNavigation: true,                                  // If true, builds and list of anchor links to link to each slide
        pauseOnHover: true,                                     // If true, and autoPlay is enabled, the show will pause on hover
        startText: "",                                          // Start text
        stopText: "",                                           // Stop text
        navigationFormatter: formatText,                        // Details at the top of the file on this use (advanced use)
        defaultThumb: '',                                       // set the default thumbnail if no other are found
        gaPageTrackURL: ''                                      // Google Analytics Page Track URL
      });

      jQuery(".anythingSlider li a").colorbox({ width:"600", height:"600" });
    }

    function startSlideshow() {
			var str = "";

			for(var i=0; i < slideshow.length; i++) {
				if(slideshow[i].type === "image") {
         str += "<li class='slide_image'><a href='" + slideshow[i].src + "'><img slidetext='" + slideshow[i].copy.replace("'", "&apos;") + "' class='photo' src='" + slideshow[i].src+"' thumb='" + slideshow[i].thumb + "' /></a></li>";
				}
        else if(slideshow[i].type === "video") {
					str += "<li class='slide_video'><a href='" + slideshow[i].src + "' class='videoplayer'></a><a href='" + slideshow[i].thumb + "'><img class='photo thumbnailNav' src='" + slideshow[i].thumb + "' /></a></li>";
				}
			}

			// Reset slideshow
			jQuery('.anythingSlider').html('<div class="wrapper"><ul>' + str + '</ul></div>');
			initSlideshow();
		}
  </script>
  <script>
		// On Document load
		jQuery(function () {
			startSlideshow();		});
	</script>
EOD;

$json_data = json_decode($rows, TRUE);
for($i = 0; $i < count($json_data); $i++) {
  $mediaType = determineMediaType(pathinfo($json_data[$i]['src'], PATHINFO_EXTENSION));
  $json_data[$i]['type'] = $mediaType;
  // replace image path with cdn
  $json_data[$i]['src'] = str_replace('http://localhost.maxim.com/sites/default/files/maxim/', 'http://cdn2.maxim.com/maxim/', $json_data[$i]['src']);
  $json_data[$i]['thumb'] = str_replace('http://localhost.maxim.com/sites/default/files/maxim/', 'http://cdn2.maxim.com/maxim/', $json_data[$i]['thumb']);

}
 
$rows = '<script type="text/javascript">var slideshow='.json_encode($json_data).'</script>'. $js;
print $rows;

function determineMediaType ($fileExtension) {
  $imageTypes = array('jpg', 'png');
  $videoTypes = array('flv');

  if (in_array($fileExtension, $imageTypes)) {
    return ('image');
  }
  elseif (in_array($fileExtension, $videoTypes)) {
    return ('video');
  }
}