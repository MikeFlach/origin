<?php
/**
* @file views-view.tpl.php
* Main view template
*
* Variables available:
* - $classes_array: An array of classes determined in
* template_preprocess_views_view(). Default classes are:
* .view
* .view-[css_name]
* .view-id-[view_name]
* .view-display-id-[display_name]
* .view-dom-id-[dom_id]
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
// **************************** Regular Slideshow View *****************************************
if ($view->display[$view->current_display]->display_title === 'Slideshow json') {
  drupal_add_js(libraries_get_path('slideshow') . '/flowplayer-3.2.6.min.js');
  drupal_add_js(libraries_get_path('slideshow') . '/jquery.anythingslider.js');
  drupal_add_js(libraries_get_path('slideshow') . '/jquery.easing.1.2.js');

  drupal_add_css(libraries_get_path('slideshow') . '/slider.css');

  $json_data = json_decode($rows, TRUE);
  for($i = 0; $i < count($json_data); $i++) {
    $mediaType = determineMediaType(pathinfo($json_data[$i]['src'], PATHINFO_EXTENSION));
    $json_data[$i]['type'] = $mediaType;
    // replace image path with cdn
    $json_data[$i]['src'] = replaceLocalFilesWithCDN($json_data[$i]['src']);
    $json_data[$i]['thumb'] = replaceLocalFilesWithCDN($json_data[$i]['thumb']);
  }

  $prevLink = getPrevNext($json_data[0]['Nid'], $json_data[0]['TermID'], "p");
  $nextLink = getPrevNext($json_data[0]['Nid'], $json_data[0]['TermID'], "n");
  $links = '<div id="prevNextLinks"><span id="prev">'.$prevLink.'</span>&nbsp;&nbsp;&nbsp;<span id="next">'.$nextLink.'</span></div>';

  $js = <<<EOD
<script type="text/javascript">
  function formatText(index, panel) {
    return index + "";
  }

  function initSlideshow() {
    jQuery('.anythingSlider').anythingSlider({
      resizeContents: false,
      easing: "easeInOutExpo", // Anything other than "linear" or "swing" requires the easing plugin
      autoPlay: false, // This turns off the entire FUNCTIONALY, not just if it starts running or not.
      delay: 5000, // How long between slide transitions in AutoPlay mode
      startStopped: false, // If autoPlay is on, this can force it to start stopped
      animationTime: 600, // How long the slide transition takes
      hashTags: false, // Should links change the hashtag in the URL?
      buildNavigation: true, // If true, builds and list of anchor links to link to each slide
      pauseOnHover: true, // If true, and autoPlay is enabled, the show will pause on hover
      startText: "", // Start text
      stopText: "", // Stop text
      navigationFormatter: formatText, // Details at the top of the file on this use (advanced use)
      defaultThumb: '', // set the default thumbnail if no other are found
      gaPageTrackURL: '' // Google Analytics Page Track URL
    });

    var cdnURL = '';
    flowplayer("a.videoplayer", "http://releases.flowplayer.org/swf/flowplayer-3.2.7.swf", {
      clip: {
      autoPlay: false,
      auttoBuffer: true,
      scaling: 'fit',

      // track start event for this clip
      onStart: function(clip) {
        if(clip.url.indexOf('.jpg')==-1) {
          _gaq.push(['_trackEvent', 'Videos', 'Play', clip.url]);
        }
      },

      // track when playback is resumed after having been paused
      onResume: function(clip) {
        if(clip.url.indexOf('.jpg')==-1) {
          _gaq.push(['_trackEvent', 'Videos', 'Resume', clip.url]);
        }
      },

      // track pause event for this clip. time (in seconds) is also tracked
      onPause: function(clip) {
        if(clip.url.indexOf('.jpg')==-1) {
          _gaq.push(['_trackEvent', 'Videos', 'Pause', clip.url, parseInt(this.getTime())]);
        }
      },

      // track stop event for this clip. time is also tracked
      onStop: function(clip) {
        if(clip.url.indexOf('.jpg')==-1) {
          _gaq.push(['_trackEvent', 'Videos', 'Stop', clip.url, parseInt(this.getTime())]);
        }
      },

      // track finish event for this clip
      onFinish: function(clip) {
        if(clip.url.indexOf('.jpg')==-1) {
          _gaq.push(['_trackEvent', 'Videos', 'Finish', clip.url]);
        }
      }
    },

    // show stop button so we can see stop events too
    plugins: {
      controls: {
        stop: true
       }
    }
  });
}

function loadSlideShowImages(group) {
  var str = "",
  grpCnt = 10;
  begin = 0,
  end = 0;

  if (group === 1) {
    begin = 0;
    end = slideshow.length;
    //end = grpCnt;
  }
  else {
    begin = grpCnt * (group - 1);
    end =   (grpCnt * group) - 1;
  }

  for(var i = begin; i < end; i++) {
    if(slideshow[i].type === "image") {
      newCopy = replaceAll(slideshow[i].copy, "'", "&apos;");
      newCopy = replaceAll(newCopy, "<br><br>", "<br/>");
      newCopy = replaceAll(newCopy, "<br /><br />", "<br/>");
      str += "<li class='slide_image'><a href='" + slideshow[i].fullscreenLink + "/?slide=" + i + "'><img slidetext='" + newCopy + "' class='photo' src='" + slideshow[i].src+"' thumb='" + slideshow[i].thumb + "' /></a></li>";
    }
    else if(slideshow[i].type === "video") {
      str += "<li class='slide_video'><a href='" + slideshow[i].src + "' class='videoplayer'></a><a href='" + slideshow[i].thumb + "'><img class='photo thumbnailNav' src='" + slideshow[i].thumb + "' altImg='http://cdn2.maxim.com/maximonline/assets/vid_thumb_1.jpg' /></a></li>";
    }
  }
  if (group === 1) {
    jQuery('.anythingSlider').html('<div class="wrapper"><ul id="ssAddImage">' + str + '</ul></div>');
    initSlideshow();
  }
  else {
    jQuery("#ssAddImage").append(str);
  }
}

function replaceAll(txt, replace, with_this) {
  return txt.replace(new RegExp(replace, 'g'),with_this);
}
</script>

<script>
  // On Document load
  jQuery(function () {
    loadSlideShowImages(1);
    jQuery("#slideshowBody").parent().append("<div id='galleryLink' style='margin: 20px 0 50px 20px;display:block;'><a href='/gallery/" + slideshow[0].Nid + "'>Gallery Link</a></div>");
  });
</script>
EOD;

  $addLinks = "<script>jQuery(function () {jQuery(\"#slideshowBody\").parent().append(\"".str_replace('"', "'", $links)."\");});</script>";

  $rows = '<h2>'.$json_data[0]['ssTitle'].'</h2><script type="text/javascript">var slideshow='.json_encode($json_data).'</script>'.$js.$addLinks;
  print $rows;
}

// **************************** Blackout View *****************************************
elseif ($view->display[$view->current_display]->display_title === 'Slideshow Blackout') {
  drupal_add_js(libraries_get_path('slideshow') . '/jquery.colorbox.js');
  drupal_add_js(libraries_get_path('slideshow') . '/flowplayer-3.2.6.min.js');
  drupal_add_css(libraries_get_path('slideshow') . '/colorbox.css');
  drupal_add_css(libraries_get_path('slideshow') . '/slider.css');
  drupal_add_css(libraries_get_path('slideshow') . '/blackoutSlideshow.css');

  $flowplayerJS = <<<EOD
  <script type="text/javascript">
     flowplayer("a.videoplayer", "http://releases.flowplayer.org/swf/flowplayer-3.2.7.swf", {
      clip: {
      autoPlay: false,
      auttoBuffer: true,
      scaling: 'fit',

      // track start event for this clip
      onStart: function(clip) {
        if(clip.url.indexOf('.jpg')==-1) {
          _gaq.push(['_trackEvent', 'Videos', 'Play', clip.url]);
        }
      },

      // track when playback is resumed after having been paused
      onResume: function(clip) {
        if(clip.url.indexOf('.jpg')==-1) {
          _gaq.push(['_trackEvent', 'Videos', 'Resume', clip.url]);
        }
      },

      // track pause event for this clip. time (in seconds) is also tracked
      onPause: function(clip) {
        if(clip.url.indexOf('.jpg')==-1) {
          _gaq.push(['_trackEvent', 'Videos', 'Pause', clip.url, parseInt(this.getTime())]);
        }
      },

      // track stop event for this clip. time is also tracked
      onStop: function(clip) {
        if(clip.url.indexOf('.jpg')==-1) {
          _gaq.push(['_trackEvent', 'Videos', 'Stop', clip.url, parseInt(this.getTime())]);
        }
      },

      // track finish event for this clip
      onFinish: function(clip) {
        if(clip.url.indexOf('.jpg')==-1) {
          _gaq.push(['_trackEvent', 'Videos', 'Finish', clip.url]);
        }
      }
    },

    // show stop button so we can see stop events too
    plugins: {
      controls: {
        stop: true
       }
    }
  });
</script>
EOD;

  $json_data = json_decode($rows, TRUE);
  $initialSlide = (isset($_GET["slide"]) && is_numeric($_GET["slide"]) && ($_GET["slide"] > 0 && $_GET["slide"] < count($json_data)) === true ? $_GET["slide"] : 0);

  for($i = 0; $i < count($json_data); $i++) {
    $mediaType = determineMediaType(pathinfo($json_data[$i]['src'], PATHINFO_EXTENSION));
    $json_data[$i]['type'] = $mediaType;
    $json_data[$i]['src'] = replaceLocalFilesWithCDN($json_data[$i]['src']);
    $json_data[$i]['thumb'] = replaceLocalFilesWithCDN($json_data[$i]['thumb']);
  }

  $prev = "<div id='prev' class='lnk'>&lt;&lt;</div>";
  $next = "<div id='next' class='lnk'>&gt;&gt;</div>";

  // special case where first thumbnail is a video
  if (determineMediaType(pathinfo($json_data[$initialSlide]['src'], PATHINFO_EXTENSION)) === 'video') {
    $dImage = "<div id='dImage'><img class='dispCopy cboxElement' id='dispImage' src='' /></div>";
    $displInitialVideo = "<script>jQuery('#dImage').hide(); jQuery('#vp').show(); flowplayer().play(slideShow[".$initialSlide."]['src']); //flowplayer().play();</script>";
  }
  else {
    $dImage = "<div id='dImage'><img class='dispCopy cboxElement' id='dispImage' src='".replaceLocalFilesWithCDN($json_data[$initialSlide]['src'])."' /></div>";
    $displInitialVideo = "";
  }

  $slideTxt = "<div style='display:none'><div id='pop'>".$json_data[$initialSlide]['copy']."</div></div>";
  $setupVars = "<script>var currIndex = ".$initialSlide."; slideShow=".json_encode($json_data).";</script>";

  $prevClick = <<<EOD
<script>
  jQuery('#prev').click(function() {
    currIndex--;
    if (currIndex < 0) {
      currIndex = slideShow.length-1;
    }

    if (slideShow[currIndex]['type'] === 'image') {
      jQuery('#dispImage').attr('src', slideShow[currIndex]['src']);
      jQuery('#pop').html(slideShow[currIndex]['copy']);
      jQuery('#vp').hide();
      jQuery("#dispImage").fadeIn(800, function() {
        jQuery("#dispImage").attr('src', slideShow[currIndex]['src'] + '?' + new Date().getTime());
        jQuery("#dImage").show();
      });
    }
    else if (slideShow[currIndex]['type'] === 'video') {
      jQuery('#dImage').hide();
      jQuery('#vp').show();
      flowplayer().play(slideShow[currIndex]['src']);
    }
  });
</script>
EOD;

  $nextClick = <<<EOD
<script>
jQuery('#next').click(function() {
  currIndex++;

  if (currIndex >= slideShow.length) {
    currIndex = 0;
  }
  if (slideShow[currIndex]['type'] === 'image') {
    jQuery('#dispImage').attr('src', slideShow[currIndex]['src'] + '?' + new Date().getTime());
    jQuery('#pop').html(slideShow[currIndex]['copy']);
    jQuery('#vp').hide();
    jQuery("#dispImage").fadeIn(800, function() {
      jQuery("#dispImage").attr('src', slideShow[currIndex]['src'] + '?' + new Date().getTime());
      jQuery("#dImage").show();
    });
  }
  else {
    if (slideShow[currIndex]['type'] === 'video') {
      jQuery('#dImage').hide();
      jQuery('#vp').show();
      flowplayer().play(slideShow[currIndex]['src']);
      //flowplayer().play();
    }
  }
});
</script>
EOD;

  $txtPop = "<script>if (jQuery('#pop').html.length > 0) {jQuery('.dispCopy').click(function() { jQuery(this).colorbox({inline:true, href:'#pop', width:'400'})});}</script>";

  $flowPlayerHTML = "<div id='dVideo'><a href='' class='videoplayer' id='vp' style='display:none;'></a></div>";
  $html = "<div id='slideshowFull'>".$slideTxt.$setupVars.$prev.$flowPlayerHTML.$flowplayerJS.$dImage.$next.$txtPop.$prevClick.$nextClick.$displInitialVideo;

  print $html;
}
// **************************** Gallery View *****************************************
elseif ($view->display[$view->current_display]->display_title === 'Slideshow Gallery') {
  drupal_add_css(libraries_get_path('slideshow') . '/slideshowGallery.css');

  // add the slide number to the url & replace video images with default thumbnails
  $galleryLink = <<<EOD
<script type="text/javascript">
  jQuery('.galleryImg').each(function(index) {
    currLnk = jQuery(this).parent().attr('href');
    jQuery(this).parent().attr('href', currLnk+index);

    if ((this.src.indexOf('.flv') != -1) || (this.src.indexOf('.mp4') != -1)) {
      this.src = 'http://cdn2.maxim.com/maximonline/assets/video_1.jpg'
    }
  });
</script>
EOD;

  $html = print("<div class=".$classes." <div class='view-header'>".$header."</div>".replaceLocalFilesWithCDN($rows)."</div>".$galleryLink);
}


// Local Functions
function determineMediaType ($fileExtension) {
  $imageTypes = array("jpg", "png");
  $videoTypes = array("flv", "mp4");

  if (in_array($fileExtension, $imageTypes)) {
    return ('image');
  }
  elseif (in_array($fileExtension, $videoTypes)) {
    return ('video');
  }
}

function replaceLocalFilesWithCDN($file) {
  return(str_replace('http://localhost.maxim.com/sites/default/files/maxim/', 'http://cdn2.maxim.com/maxim/', $file));
}

function getPrevNext($currentNode = NULL, $channelID = NULL, $op = 'p') {
  if ($op === 'p') {
    $sql_op = '<';
    $order = 'DESC';
  }
  elseif ($op == 'n') {
    $sql_op = '>';
    $order = 'ASC';
  }
  else {
    return NULL;
  }

  $output = NULL;
  $sqlSelect = "SELECT n.nid, n.title ";
  $sqlFrom = "FROM {node} n, {taxonomy_index} t ";
  $sqlWhere = "WHERE n.nid = t.nid AND n.nid ".$sql_op." :nid AND t.tid=".$channelID." AND type IN ('slideshow') AND status = 1 ";
  $sqlOrder = "ORDER BY nid ".$order." LIMIT 1";
  $sql = $sqlSelect.$sqlFrom.$sqlWhere.$sqlOrder;

  $result = db_query($sql, array(':nid' => $currentNode));
  foreach ($result as $data) {}
  if (isset($data)) {
    if ($op == 'n') {
      return l("Next", "node/$data->nid", array('html' => TRUE));
    }
    else if ($op == 'p') {
      return l("Previous", "node/$data->nid", array('html' => TRUE));
    }
  }
}