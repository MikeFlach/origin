jQuery('#prev').click(function() {
  currIndex--;
  if (currIndex < 0) {
    // currIndex = slideShow.length-1;
    window.location = prev_ss_link;
  }

  if (slideShow[currIndex]['type'] === 'image') {
    jQuery('#dispImage').attr('src', slideShow[currIndex]['src']);
    jQuery('#pop').html(replace_undefined(slideShow[currIndex]['slidetitle']) + replace_undefined(slideShow[currIndex]['copy']));
    jQuery('#vp').hide();
    jQuery("#dispImage").fadeIn(800, function() {
      jQuery("#dispImage").attr('src', slideShow[currIndex]['src'] + '?' + new Date().getTime());
      jQuery("#dImage").show();
    });
      jQuery("#slide-teaser-text").html("");
    //jQuery("#slide-teaser-text").html(replace_undefined(slideShow[currIndex]['slidetitle']) + replace_undefined(slideShow[currIndex]['copy'])).toString().substr(1, 100) + "...";
  }
  else if (slideShow[currIndex]['type'] === 'video') {
    jQuery('#dImage').hide();
    jQuery('#vp').show();
    flowplayer().play(slideShow[currIndex]['src']);
  }
});

jQuery('#next').click(function() {
  currIndex++;

  if (currIndex >= slideShow.length) {
    //currIndex = 0;
    window.location = next_ss_link;
  }
  if (slideShow[currIndex]['type'] === 'image') {
    jQuery('#dispImage').attr('src', slideShow[currIndex]['src'] + '?' + new Date().getTime());
    jQuery('#pop').html(slideShow[currIndex]['slidetitle'] + slideShow[currIndex]['copy']);
    jQuery('#vp').hide();
    jQuery("#dispImage").fadeIn(800, function() {
      jQuery("#dispImage").attr('src', slideShow[currIndex]['src'] + '?' + new Date().getTime());
      jQuery("#dImage").show();
    });

    //jQuery("#slide-teaser-text").html(replace_undefined(slideShow[currIndex]['slidetitle']) + replace_undefined(slideShow[currIndex]['copy'])).toString().substr(1, 100) + "...";
    jQuery("#slide-teaser-text").html("");
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
});

function replace_undefined(str) {
  if (typeof str === 'undefined') {
    return ('');
  }
  else {
    return(str);
  }
}

