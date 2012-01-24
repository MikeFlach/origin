jQuery('#prev').click(function() {
  currIndex--;
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
  jQuery('#slide-teaser-text').css('width', jQuery(this).width());
});

flowplayer("a.videoplayer", {src:"http://releases.flowplayer.org/swf/flowplayer-3.2.7.swf", wmode:'opaque'}, {
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
});

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

  teaser = title + caption.toString().substr(1,100) + '...';
  return(teaser);
}

function replace_undefined(str) {
  retVal = (typeof str === 'undefined') ? '' : str;

  return(retVal);
}

function strip_html(str) {
  return(str.replace(/<(?:.|\n)*?>/gm, ' '));
}

