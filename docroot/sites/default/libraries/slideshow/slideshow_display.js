var video = document.createElement("video");
if (typeof flowplayer == 'function') {
  var noflash = flashembed.getVersion()[0] === 0;
} else {
  var noflash = 0;
}

function formatText(index, panel) {
  return index + "";
}

if (noflash) {
  var showControls = true;
  var do_autoplay = true;
}
else {
  var showControls = false;
  var do_autoplay = false;
}

function initSlideshow() {
  jQuery('.anythingSlider').anythingSlider({
    resizeContents: false,
    easing: "easeInOutExpo", // Anything other than "linear" or "swing" requires the easing plugin
    autoPlay: do_autoplay, // This turns off the entire FUNCTIONALY, not just if it starts running or not.
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
    navigationCallback: slideshowAdCheck,
    disableInfiniteScroll: 1 // Disable infinite scroll on slideshow. Issue with brightcove videos not working properly.
  });

  hashCheck();

  if (typeof flowplayer == 'function') {
    flowplayer("a.videoplayer", "http://releases.flowplayer.org/swf/flowplayer-3.2.10.swf", {
      playlist: [
        {
          autoPlay: false,

          // video will be buffered when splash screen is visible
          autoBuffering: false,
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
        }
      ],

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
  // Refresh ad interval
  var refreshAdInterval = Drupal.settings.Maxim.slideshow.ad_frequency ? Drupal.settings.Maxim.slideshow.ad_frequency : 1;

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

  var j = 1;
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

      str += "<li class='slide_image'><a href='" + replaceChannelPath(slideshow[i].fullscreenLink.toLowerCase()) + "/?slide=" + i + "'><img slidetitle='" + title + "' slidetext='" + newCopy + "' class='photo' src='" + slideshow[i].src+ "' attribution='" + slideshow[i].attribution + "' thumb='" + slideshow[i].thumb + "' alt='" + slideshow[i].alt_image + "' /></a></li>";
    }
    else if(slideshow[i].type === "video") {
      video_class = 'v_'+j++;
      if (jQuery.trim(slideshow[i]['video_image']).length == 0) {
        vi = 'http://cdn2.maxim.com/maximonline/assets/video_1.jpg';
        alt_vi = 'http://cdn2.maxim.com/maximonline/assets/vid_thumb_1.jpg';
        add_thumb_video_icon = false;
      }
      else {
        vi = slideshow[i]['video_image'];
        alt_vi = jQuery.trim(slideshow[i]['video_image']);
        add_thumb_video_icon = true;
      }

      if (slideshow[i]['mime_type'] === 'video/brightcove') {
        str += "<li class='slide_video "+video_class+"'>" + slideshow[i].html + "<a href='" + slideshow[i].thumb + "'><img class='photo thumbnailNav' src='" + vi + "' add_thumb_video_icon='"+add_thumb_video_icon+"' altImg='"+alt_vi+"' alt='slide:"+slideshow[i].alt_image+"' /><div></div></a></li>";
      } else {
        if (noflash) {
          str += "<li class='slide_video "+video_class+"'><a href='" + slideshow[i].src + "' class='videoplayer' onclick=\"javascript:remove_bad_emements('."+video_class+"');\"><img src='"+vi+"' class='video_image' alt='video image'></img><div class='ss-video-overlay'></div></a><a href='" + slideshow[i].thumb + "'><img class='photo thumbnailNav' src='" + vi + "' add_thumb_video_icon='"+add_thumb_video_icon+"' altImg='"+alt_vi+"' alt='slide:"+slideshow[i].alt_image+"' /></a></li>";
        }
        else {
          str += "<li class='slide_video "+video_class+"'><a href='" + slideshow[i].src + "' class='videoplayer'><img src='"+vi+"' class='video_image' alt='video image'></img><div class='ss-video-overlay'></div></a><a href='" + slideshow[i].thumb + "'><img class='photo thumbnailNav' src='" + vi + "' add_thumb_video_icon='"+add_thumb_video_icon+"' altImg='"+alt_vi+"' alt='slide:"+slideshow[i].alt_image+"' /><div></div></a></li>";
        }
      }
    }
  }
  jQuery('.anythingSlider').html('<div class="wrapper"><ul id="ssAddImage">' + str + '</ul></div>');

  jQuery("#ssAddImage").hammer({
    prevent_default: false,
    drag_vertical: false
  })
  .bind("dragstart", function(ev) {
    if (ev.direction == 'left') {
      // slide left
      jQuery('.arrow.forward.inside').trigger('click');
    }
    if (ev.direction == 'right') {
      // slide right
      jQuery('.arrow.back.inside').trigger('click');
    }
  });

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
    str = str.replace('#&amp;', '');
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

function remove_bad_emements(video_class) {
  setTimeout( function() {
    jQuery(video_class).each(function() {
      if(!jQuery(this).hasClass('cloned')) {
        if(jQuery(this).find('a:first div').html().length) {
          jQuery(this).html(jQuery(this).find('a:first div').html());
          jQuery(this).find('video').attr('type', 'video/mp4');
          //jQuery(this).find('video').attr('poster', 'http://cdn2.maxim.com/maximonline/assets/video_1.jpg');
          //jQuery(this).find('video').attr('preload', 'auto');
          //jQuery(this).find('video').attr('autoplay', 'autoplay');
        }
      }
    })
  }, 250);
}
