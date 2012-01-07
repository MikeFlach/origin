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

    canvas: {
        backgroundColor:'#000000',
        backgroundGradient: 'none'
      },

    // show stop button so we can see stop events too
    plugins: {
      controls: {
        stop: true
       }
    }
  })
}

(function ($) {
  // For resize
  var waitForFinalEvent = (function () {
    var timers = {};
    return function (callback, ms, uniqueId) {
    if (!uniqueId) {
      uniqueId = "Don't call this twice without a uniqueId";
    }
    if (timers[uniqueId]) {
      clearTimeout (timers[uniqueId]);
    }
    timers[uniqueId] = setTimeout(callback, ms);
    };
  })();

  $(window).resize(function () {
    waitForFinalEvent(function(){
      loadSlideShowImages(1);
    }, 500, "slideshowResize");
  });

}(jQuery));

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
      str += "<li class='slide_image'><a href='" + slideshow[i].fullscreenLink.toLowerCase() + "/?slide=" + i + "'><img slidetext='" + newCopy + "' class='photo' src='" + slideshow[i].src+"' thumb='" + slideshow[i].thumb + "' /></a></li>";
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
