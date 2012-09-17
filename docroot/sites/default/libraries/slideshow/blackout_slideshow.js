jQuery(document).ready(function(){
  maxim_dart('dart_full_ss_button');
});

jQuery('#prev').click(function() {
  currIndex--;
  jQuery("#slide-teaser-text").show();
  if (jQuery('#slideAd').is(":visible")){
    jQuery('#ss_title').show();
    jQuery('#slideAd').hide();
    jQuery(".attribution").show();
    jQuery('.dart-name-dart_full_ss_button').show();
  }
  maxim_dart('dart_full_ss_button', 1);
  if ((currIndex < 0) && (next_ss_link.length > 0)) {
    window.location = next_ss_link;
    return;
  }
  jQuery("#slideCount").html((currIndex+1) + ' of ' + slideShow.length);
  jQuery("#slide-teaser-text").html(get_caption_teaser(slideShow[currIndex]['slide_title'], replace_undefined(slideShow[currIndex]['copy'])) + '<a href="#" onclick="openColorbox();">[read more]</a>');
  jQuery(".attribution").html(slideShow[currIndex]['attribution']);
  if (slideShow[currIndex]['type'] === 'image') {
    jQuery('#pop').html(replace_undefined(slideShow[currIndex]['slide_title']) + replace_undefined(slideShow[currIndex]['copy']));
    hideVideo();

      jQuery("#dispImage").attr('src', slideShow[currIndex]['src']);
      jQuery("#dispImage").attr('alt', slideShow[currIndex]['alt_image']);
      jQuery("#dispImage").attr('title', slideShow[currIndex]['title_image']);
        jQuery("#dImage").fadeIn(2500, function() {});

  }
  else if (slideShow[currIndex]['type'] === 'video') {
    displayVideo();
  }
  trackPage();
});

jQuery('#next').click(function() {
  currIndex++;
  if (currIndex == slideShow.length){
    // Display Ad after last slide
    jQuery('#ss_title').hide();
    hideVideo();
    jQuery('#dImage').hide();
    jQuery("#slideCount").html('');
    jQuery("#slide-teaser-text").html('');
    jQuery(".attribution").hide();
    jQuery('#slideAd').show();
    maxim_dart('dart_full_slideshow', 1);
    jQuery('.dart-name-dart_full_ss_button').hide();
    return;
  } 
  else {
    maxim_dart('dart_full_ss_button', 1);
  }
  if ((currIndex >= slideShow.length) && (prev_ss_link.length > 0)) {
    window.location = prev_ss_link;
    return;
  }
  jQuery("#slideCount").html((currIndex+1) + ' of ' + slideShow.length);
  if (slideShow[currIndex]['type'] === 'image') {
    jQuery('#pop').html(replace_undefined(slideShow[currIndex]['slide_title']) + replace_undefined(slideShow[currIndex]['copy']));
    hideVideo();
 
      jQuery("#dispImage").attr('src', slideShow[currIndex]['src']);
      jQuery("#dispImage").attr('alt', slideShow[currIndex]['alt_image']);
      jQuery("#dispImage").attr('title', slideShow[currIndex]['title_image']);
    jQuery("#dImage").fadeIn(2500, function() {});

    jQuery("#slide-teaser-text").html(get_caption_teaser(slideShow[currIndex]['slide_title'], replace_undefined(slideShow[currIndex]['copy'])) + '<a href="#" onclick="openColorbox();">[read more]</a>');
    jQuery(".attribution").html(slideShow[currIndex]['attribution']);
  }
  else {
    if (slideShow[currIndex]['type'] === 'video') {
      displayVideo();
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

jQuery("#slideshowFull").hammer({
  prevent_default: false,
  drag_vertical: false
})
.bind("dragstart", function(ev) {
  if (ev.direction == 'left') {
    // slide left
    jQuery('#next').trigger('click');
  }
  if (ev.direction == 'right') {
    // slide right
    jQuery('#prev').trigger('click');
  }
});

var video = document.createElement("video");
var noflash = flashembed.getVersion()[0] === 0;

if (noflash) {
  var showControls = true;
}
else {
  var showControls = false;
}

flowplayer("a.videoplayer", {src:"http://releases.flowplayer.org/swf/flowplayer-3.2.10.swf", wmode:'opaque'}, {
  clip: {
    autoPlay: true,
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

/* Get and Display Link for 2012 Hot 100 */
jQuery(function(){
  if (jQuery("link[rel=canonical]").attr("href").indexOf("/hot-100/2012-hot-100") != -1){
    jQuery("body").append('<div id="slideshowCopy" style="display:none;"></div>');
    displayLink();
  }
});

function displayVideo(){
  jQuery('#dImage').hide();
  jQuery("#slide-teaser-text").show();
  jQuery(".attribution").show();
  showVideo();

  if (noflash) {
    if (jQuery("#dVideo a:first").length > 0){
      jQuery('#dVideo').html(jQuery("#dVideo a:first div").html());
    }

    jQuery('#dVideo video').attr('src', slideShow[currIndex]['src']);
    jQuery('#dVideo video').attr('type', 'video/mp4');
    jQuery('#dVideo video').attr('autoplay', 'autoplay');

    if (jQuery.trim(slideShow[currIndex]['video_image']).length == 0) {
      jQuery('#dVideo video').attr('poster', 'http://cdn2.maxim.com/maximonline/assets/video_1.jpg');
    }
    else {
      jQuery('#dVideo video').attr('poster', slideShow[currIndex]['video_image']);
    }
  }
  else {
    flowplayer().play(slideShow[currIndex]['src']);
  }
};

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

function hideVideo () {
 if (!noflash) {
  flowplayer().stop();
 }
 else {
   jQuery('#vp_api')[0].pause();
   jQuery('#vp').addClass('hide-video');
 }
 jQuery('#dVideo').hide();
}

function showVideo () {
  if (!noflash) {
   jQuery('#dVideo').show();
   jQuery('#vp').removeClass('hide-video');
  }
  else {
    jQuery('#dVideo').show();
  }
}
