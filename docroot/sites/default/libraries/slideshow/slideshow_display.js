var video = document.createElement("video");
var noflash = flashembed.getVersion()[0] === 0;

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
    gaPageTrackURL: window.location.pathname, // Google Analytics Page Track URL
    navigationCallback: slideshowAdCheck
  });

  hashCheck();

  if (noflash) {
    var showControls = true;
  }
  else {
    var showControls = false;
  }

  flowplayer("a.videoplayer", "http://releases.flowplayer.org/swf/flowplayer-3.2.10.swf", {
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
  }).ipad({ simulateiDevice:noflash, controls:showControls });
}

jQuery(function(){
  // For resize
  jQuery('.anythingSlider').resize(function () {
    loadSlideShowImages();
  });
});

jQuery(window).keydown(function(e) {
  if(window.disableKeyEvents && window.disableKeyEvents==1){
    return;
  }
  switch (e.keyCode){
    case 70: //f
      location.href=jQuery('#fullscreenLink a').attr('href');
    break;
    case 37: //LEFT
    case 75: //k
      jQuery('.arrow.back.inside').trigger('click');
    break;
    case 13: //ENTER
    case 39: //RIGHT
    case 74: //j
      jQuery('.arrow.forward.inside').trigger('click');
    break;
  }
});

function slideshowAdCheck(){
  var refreshAdInterval = 5; // Refresh ad interval
  if (typeof window.slideshowClickIndex === 'undefined') {
    window.slideshowClickIndex=0;
  }
  slideshowClickIndex++;
  if (slideshowClickIndex >= refreshAdInterval){
    slideshowClickIndex=0;
    maxim_dart('dart_big_box', 1);
    maxim_dart('dart_leaderboard', 1);
  }
}

function loadSlideShowImages() {
  str = "";

  jQuery('#slideshowBody').html('');

  for(var i = 0; i < slideshow.length; i++) {
    if(slideshow[i].type === "image") {
      if (jQuery.trim(slideshow[i].copy).length === 0) {
        slideshow[i].copy = slideshow[i].body;
      }

      if (typeof slideshow[i].copy === 'string') {
        newCopy = replaceAll(slideshow[i].copy, "'", "&apos;");
        newCopy = replaceAll(newCopy, "<br><br>", "<br/>");
        newCopy = replaceAll(newCopy, "<br /><br />", "<br/>");
      }
      else {
        newCopy = '';
      }

      if (typeof slideshow[i].title === 'string') {
        title = replaceAll(slideshow[i].title, "'", "&apos;");
      }
      else {
        title = '';
      }

      str += "<li class='slide_image'><a href='" + replaceChannelPath(slideshow[i].fullscreenLink.toLowerCase()) + "/?slide=" + i + "'><img slidetitle='" + title + "' slidetext='" + newCopy + "' class='photo' src='" + slideshow[i].src+ "' attribution='" + slideshow[i].attribution + "' thumb='" + slideshow[i].thumb + "' /></a></li>";

    }
    else if(slideshow[i].type === "video") {
      str += "<li class='slide_video'><a href='" + slideshow[i].src + "' class='videoplayer'></a><a href='" + slideshow[i].thumb + "'><img class='photo thumbnailNav' src='" + slideshow[i].thumb + "' altImg='http://cdn2.maxim.com/maximonline/assets/vid_thumb_1.jpg' /></a></li>";
    }
  }

  jQuery('.anythingSlider').html('<div class="wrapper"><ul id="ssAddImage">' + str + '</ul></div>');
  initSlideshow();
}

function replaceAll(txt, replace, with_this) {
  return txt.replace(new RegExp(replace, 'g'),with_this);
}

function replaceChannelPath(path) {
  var str  = (typeof path === 'undefined') ? '' : path;

  if (str.length > 0) {
    str = path.replace(/\s/g , "-");
    str = str.replace('&#039;', '');
    str = str.replace('%27', '');
    str = str.replace('%20', '-');
  }

  return(str.toLowerCase());
}

function isNumber(n) {
	"use strict";
	return !isNaN(parseFloat(n)) && isFinite(n);
}

// push slideshow object properties to corresponding dom elements
function assignSlideCopy(index) {
  "use strict";
  jQuery('#slideshowBody').empty();

  if (typeof slideshow[index].copy === 'string') {
    newCopy = replaceAll(slideshow[index].copy, "'", "&apos;");
    newCopy = replaceAll(newCopy, "<br><br>", "<br/>");
    newCopy = replaceAll(newCopy, "<br /><br />", "<br/>");
  }
  else {
    newCopy = '';
  }

  if (typeof slideshow[index].title === 'string') {
    title = replaceAll(slideshow[index].title, "'", "&apos;");
  }
  else {
    title = '';
  }

  jQuery('<div class="attribution">' + slideshow[index].attribution + '</div>').appendTo('#slideshowBody');
  jQuery('<p class="slidetitle">' + title + '</p>').appendTo('#slideshowBody');
  jQuery(newCopy).appendTo('#slideshowBody');
}

/*
jQuery(window).hashchange( function(){
  hashCheck();
});
*/
function hashCheck() {
  "use strict";
  var index, multiple;
  if (document.location.hash) {
    // where slide index is some number in the hash
    // get the numeric position after the dash (-)
    index = parseInt(document.location.hash.substring(document.location.hash.indexOf('-') + 1, document.location.hash.length));
    if (isNumber(index)) {
      if (index > 8) {
	multiple = ((index - 8) * 69);
	jQuery('#holder').css('margin-left', '-' + multiple + 'px');
      }
      index = index - 1;
      assignSlideCopy(index);
    } else {
      //
      // slideshow seems to default to the first slide
      // if index is not a number
      // OR if (index > slideshow.length)
      //
    }
  }
}

function isMobileBrowser() {
  if (navigator.userAgent.match(/Android/i)
      || navigator.userAgent.match(/webOS/i)
      || navigator.userAgent.match(/iPhone/i)
      || navigator.userAgent.match(/iPad/i)
      || navigator.userAgent.match(/iPod/i)
      || navigator.userAgent.match(/BlackBerry/i)
     ) {
    return(true);
  }
  else {
    return(false);
  }
}

if (noflash) {
  // we only need this css/js if we don't have a flash player
  jQuery('head').append('<link rel="stylesheet" type="text/css" href="/sites/default/libraries/slideshow/video-js.css">');
  jQuery.getScript('/sites/default/libraries/slideshow/video.js');

  jQuery(window).load(function() {
    jQuery('.slide_video').each(function(index) {
      jQuery(this).html(jQuery(this).find('a:first div').html());
      jQuery(this).find('video').attr('type', 'video/mp4');
      jQuery(this).find('video').attr('poster', 'http://cdn2.maxim.com/maximonline/assets/video_1.jpg');
      jQuery(this).find('video').attr('preload', 'auto');
      jQuery(this).find('video').attr('data-setup', '{}');
      jQuery(this).find('video').addClass('video-js');
      jQuery(this).find('video').addClass('vjs-default-skin');
      jQuery(this).find('video').css('width', '85%');
      jQuery(this).find('video').css('margin', '0 auto');
    });
  });
}