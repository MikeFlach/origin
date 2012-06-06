jQuery(document).ready(function(){
  maxim_dart('dart_full_ss_button');
});

jQuery('#prev').click(function() {
  currIndex--;
  if (jQuery('#slideAd').is(":visible")){
    jQuery('#ss_title').show();
    jQuery('#slideAd').hide();
    jQuery(".attribution").show();
  }
  if ((currIndex < 0) && (next_ss_link.length > 0)) {
    window.location = next_ss_link;
    return;
  }
  jQuery("#slideCount").html((currIndex+1) + ' of ' + slideShow.length);
  if (slideShow[currIndex]['type'] === 'image') {
    jQuery('#pop').html(replace_undefined(slideShow[currIndex]['slide_title']) + replace_undefined(slideShow[currIndex]['copy']));
    jQuery('#vp').hide();
    jQuery("#dImage").fadeIn(800, function() {
      jQuery("#dispImage").attr('src', slideShow[currIndex]['src']);
    });

    jQuery("#slide-teaser-text").html(get_caption_teaser(slideShow[currIndex]['slide_title'], replace_undefined(slideShow[currIndex]['copy'])) + '<a href="#" onclick="openColorbox();">[read more]</a>');
    jQuery(".attribution").html(slideShow[currIndex]['attribution']);
  }
  else if (slideShow[currIndex]['type'] === 'video') {
    jQuery('#dImage').hide();
    jQuery('#vp').show();
    flowplayer().play(slideShow[currIndex]['src']);
  }
  trackPage();
});

jQuery('#next').click(function() {
  currIndex++;
  if (currIndex == slideShow.length){
    // Display Ad after last slide
    jQuery('#ss_title').hide();
    jQuery('#vp').hide();
    jQuery('#dImage').hide();
    jQuery("#slideCount").html('');
    jQuery("#slide-teaser-text").html('');
    jQuery(".attribution").hide();
    jQuery('#slideAd').show();
    maxim_dart('dart_full_slideshow', 1);
    return;
  }
  if ((currIndex >= slideShow.length) && (prev_ss_link.length > 0)) {
    window.location = prev_ss_link;
    return;
  }
  jQuery("#slideCount").html((currIndex+1) + ' of ' + slideShow.length);
  if (slideShow[currIndex]['type'] === 'image') {
    jQuery('#pop').html(replace_undefined(slideShow[currIndex]['slide_title']) + replace_undefined(slideShow[currIndex]['copy']));
    jQuery('#vp').hide();
    jQuery("#dImage").fadeIn(800, function() {
      jQuery("#dispImage").attr('src', slideShow[currIndex]['src']);
    });

    jQuery("#slide-teaser-text").html(get_caption_teaser(slideShow[currIndex]['slide_title'], replace_undefined(slideShow[currIndex]['copy'])) + '<a href="#" onclick="openColorbox();">[read more]</a>');
    jQuery(".attribution").html(slideShow[currIndex]['attribution']);
  }
  else {
    if (slideShow[currIndex]['type'] === 'video') {
      jQuery('#dImage').hide();
      jQuery('#vp').show();
      flowplayer().play(slideShow[currIndex]['src']);
    }
  }
  trackPage();
});

jQuery("body").keydown(function(e) {
   if (jQuery("#colorbox").css("display")!="block") {
    switch (e.keyCode){
      case 27: //ESC
        location.href=jQuery('.closeLnk a').attr('href');
      break;
      case 84: //t
        location.href=jQuery('.thumbnailLnk a').attr('href');
      break;
      case 37: //LEFT
      case 75: //k
        jQuery('#prev').trigger('click');
      break;
      case 13: //ENTER
      case 39: //RIGHT
      case 74: //j
        jQuery('#next').trigger('click');
      break;
    }
  }
});

// On image load
jQuery('#dispImage').load(function(){
  var imgWidth = jQuery(this).width();
  jQuery('#slide-teaser-text').css('width', imgWidth);
  jQuery('#slideshowFull .attribution').css('width', imgWidth);
  displayLink();
});

var video = document.createElement("video");
var idevice  = (isMobileBrowser() === true) ? true : false;
var noflash = flashembed.getVersion()[0] === 0;
var simulate = !idevice && noflash && !!(video.canPlayType('video/mp4; codecs="avc1.42E01E, mp4a.40.2"').replace(/no/, ''));

flowplayer("a.videoplayer", {src:"http://releases.flowplayer.org/swf/flowplayer-3.2.10.swf", wmode:'opaque'}, {
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
}).ipad({ simulateiDevice:true });

/* Get and Display Link for 2012 Hot 100 */
jQuery(function(){
  if (jQuery("link[rel=canonical]").attr("href").indexOf("/hot-100/2012-hot-100") != -1){
    jQuery("body").append('<div id="slideshowCopy" style="display:none;"></div>');
    displayLink();
  }
});
function displayLink(){
  if (jQuery("link[rel=canonical]").attr("href").indexOf("/hot-100/2012-hot-100") != -1){
    jQuery("#slide-teaser-text").append('<div id="slide-extra-link"></div>');
    jQuery("#slideshowCopy").html(slideShow[currIndex].copy);
    var name = slideShow[currIndex].title.replace(/^[\s\d\.]+/, '');
    var $links = jQuery('#slideshowCopy a');
    if ($links.length >= 2) {
      var $link = $links.eq($links.length-2);
      jQuery("#slide-extra-link").html($link).html( jQuery("#slide-extra-link").html()+ " to see more of " + name + ".");
    }
  }
}

function trackPage(){
  trackURL = window.location.pathname + "?slide=" + eval(currIndex+1);
  _gaq.push(['_trackPageview', trackURL]);
}

function openColorbox(){
  jQuery().colorbox({inline:true, href:'#pop', width:'50%', maxHeight:'60%', opacity:'.4'});
}

function get_caption_teaser(title, caption) {
  title = strip_html(replace_undefined(title));
  caption = strip_html(replace_undefined(caption));

  if (title.length > 0) {
    title = title + "<br/>";
  }
  teaser = title + caption.toString().substr(1,100) + '...';
  return(teaser);
}

function replace_undefined(str) {
  retVal = (typeof str === 'undefined') ? '' : str;

  return(retVal);
}

function strip_html(str) {
  return(str.replace(/(<([^>]+)>)/ig," "));
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
