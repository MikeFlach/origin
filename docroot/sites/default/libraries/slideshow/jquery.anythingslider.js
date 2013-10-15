/*
    anythingSlider v1.2

    By Chris Coyier: http://css-tricks.com
    with major improvements by Doug Neiner: http://pixelgraphics.us/
    based on work by Remy Sharp: http://jqueryfordesigners.com/


	To use the navigationFormatter function, you must have a function that
	accepts two paramaters, and returns a string of HTML text.

	index = integer index (1 based);
	panel = jQuery wrapped LI item this tab references
	@return = Must return a string of HTML/Text

	navigationFormatter: function(index, panel){
		return index + " Panel"; // This would have each tab with the text 'X Panel' where X = index
	}
*/
if(typeof flowplayer == 'function') {
  var noflash = flashembed.getVersion()[0] === 0;
} else {
  var noflash = 0;
}

if(typeof console =='undefined'){
  var console = {}
  console.log = function(){}
}

(function($){
  $.anythingSlider = function(el, options) {
    // To avoid scope issues, use 'base' instead of 'this'
    // to reference this class from internal events and functions.
    var base = this;

    // Access to jQuery and DOM versions of element
    base.$el = $(el);
    base.el = el;

    // Set up a few defaults
    base.currentPage = 1;
    base.timer = null;
    base.playing = false;

    base.thumbWidth=0;
    base.thumbPadding=0;
    base.numThumbs=0;
    base.numViewableThumbs=1;
    base.firstThumbPos=1;
    base.lastThumbPos=1;
    base.attribution = [];
    base.caption = [];
    base.slidetitle = [];
    // Add a reverse reference to the DOM object
    base.$el.data("AnythingSlider", base);

    base.init = function(){
      base.options = $.extend({},$.anythingSlider.defaults, options);

      // Cache existing DOM elements for later
      base.$wrapper = base.$el.find('> div').css('overflow', 'hidden');
      base.$slider  = base.$wrapper.find('> ul');
      base.$items   = base.$slider.find('> li');
      base.$single  = base.$items.filter(':first');

      // Build the navigation if needed
      if(base.options.buildNavigation) {
        base.buildNavigation();
      }
      // Get the details
      base.singleWidth = base.$single.outerWidth();
      base.pages = base.$items.length;

      if(base.options.disableInfiniteScroll == 0) {
        // Top and tail the list with 'visible' number of items, top has the last section, and tail has the first
        // This supports the "infinite" scrolling
        base.$items.filter(':first').before(base.$items.filter(':last').clone().addClass('cloned'));
        base.$items.filter(':last' ).after(base.$items.filter(':first').clone().addClass('cloned'));

        // We just added two items, time to re-cache the list
        base.$items = base.$slider.find('> li'); // reselect
      }

      // Setup our forward/backward navigation
      base.buildNextBackButtons();
      // Enable/Disable Next/Back buttons
      base.navDisplay();

      // If autoPlay functionality is included, then initialize the settings
      if(base.options.autoPlay) {
        base.playing = !base.options.startStopped; // Sets the playing variable to false if startStopped is true
        base.buildAutoPlay();
      };

      // If pauseOnHover then add hover effects

      if(base.options.pauseOnHover) {
        base.$el.hover(function() {
          base.clearTimer();
        }, function(){
          base.startStop(base.playing);
        });
      }

      // If a hash can not be used to trigger the plugin, then go to page 1

      if((base.options.hashTags == true && !base.gotoHash()) || base.options.hashTags == false){
        base.setNav(1);
        base.setCurrentPage(1);
      };
    };

    base.gotoPage = function(page, autoplay) {
      if (base.options.disableInfiniteScroll == 1) {
        thisPage = page - 1;
      } else {
        thisPage = page;
      }

      base.$items.eq(thisPage).css('visibility','visible');
      // When autoplay isn't passed, we stop the timer
      bodyTxt = '';
      attributionTxt = '';
      if (base.attribution[page].length > 0) {
        attributionTxt += '<div class="attribution">' + base.attribution[page] + '</div>';
      }
      if (base.slidetitle[page].length > 0) {
        bodyTxt += '<p class="slidetitle">' + base.slidetitle[page] + '</p>';
      }
      if (base.caption[page].length > 0) {
        bodyTxt += '<p>' + base.caption[page] + '</p>';
      }

      document.getElementById("slideshowBody").innerHTML = attributionTxt + bodyTxt; 

      if(autoplay !== true) {
        autoplay = false;
      }

      if(!autoplay) {
        base.startStop(false);
      }

      if(typeof(page) == "undefined" || page == null) {
        page = 1;
        base.setNav(1);
        base.setCurrentPage(1);
      };

      // Just check for bounds
      if(page > base.pages) {
        page = base.pages;
      }

      if(page < 0 ) {
        page = 1;
      }

      var dir = page < base.currentPage ? -1 : 1,
      n = Math.abs(base.currentPage - page),
      left = base.singleWidth * dir * n;

      if (noflash) {
        $('video').each(function() {
          this.pause();
        });
      }
      else {
        if(typeof flowplayer == 'function') {
          flowplayer("*").each(function() {
            if (['0', '1', '2', '3'].indexOf(this.getState().toString()) >= 0) {
              this.stop();
            }
          });
        }
        if (typeof maximVideoPlayers == 'object' && jQuery.isEmptyObject(maximVideoPlayers) === false) {
          for (var key in maximVideoPlayers){
            maximVideoPlayers[key].pause();
          }
        }
      }

      if(base.options.gaPageTrackURL.length > 0) {
        if(base.options.gaPageTrackURL.indexOf('?') > -1) {
          gaPageTrack=base.options.gaPageTrackURL+'&';
        }
        else {
          gaPageTrack=base.options.gaPageTrackURL+'?';
        }
        if(typeof _gaq != 'undefined') {
          _gaq.push(['_trackPageview',gaPageTrack+'slide='+page]);
        }
      }

      base.setNav(page);

      if (typeof(base.options.navigationCallback) == "function") {
        base.options.navigationCallback(dir);
      }

      base.$wrapper.filter(':not(:animated)').animate({
        scrollLeft : '+=' + left
        },
      base.options.animationTime, base.options.easing, function () {
        if (page == 0) {
          base.$wrapper.scrollLeft(base.singleWidth * base.pages);
          page = base.pages;
        }
        else if (page > base.pages) {
          base.$wrapper.scrollLeft(base.singleWidth);
          // reset back to start position
          page = 1;
        };
        base.setCurrentPage(page);
        base.navDisplay();
      });
    };

    base.setNav = function(page) {

      // Set visual
      if (page == 0) {
        page = base.pages;
      }
      else if (page > base.pages) {
        page = 1;
      };

      if(base.options.buildNavigation) {
        base.$nav.find('.cur').removeClass('cur');
        $(base.$navLinks[page - 1]).addClass('cur');
      };
    }

    base.setCurrentPage = function(page, move) {
      //base.setNav();
      if (base.options.disableInfiniteScroll == 1) {
        thisPage = page - 1;
      } else {
        thisPage = page;
      }

      // Only change left if move does not equal false
      if(move !== false) {
        base.$wrapper.scrollLeft(base.singleWidth * thisPage);
      }

      // Update local variable
      base.currentPage = page;
      base.$items.css('visibility','hidden');
      base.$items.eq(thisPage).css('visibility','visible');
    };

    base.goForward = function(autoplay) {
      if(autoplay !== true) {
        autoplay = false;
      }
      base.gotoPage(base.currentPage + 1, autoplay);
      $('.inside').trigger('slide');
    };

    base.goBack = function() {
      base.gotoPage(base.currentPage - 1);
      $('.inside').trigger('slide');
    };

    // This method tries to find a hash that matches panel-X
    // If found, it tries to find a matching item
    // If that is found as well, then that item starts visible

    base.gotoHash = function() {
      if(/^#?slide-\d+$/.test(window.location.hash)) {
        var index = parseInt(window.location.hash.substr(7));
        var $item = base.$items.filter(':eq(' + index + ')');

        if($item.length != 0) {
          base.setNav(index);
          base.setCurrentPage(index);
          return true;
        };
      };
      return false; // A item wasn't found;
    };

    // Creates the numbered navigation links
    base.buildNavigation = function() {
      base.$length = base.$items.length;
      base.classLength = 'count' + base.$length.toString();
      base.$nav = $("<div id='thumbNav' class='" + base.classLength + "'></div>").appendTo(base.$el);
      base.$holder = $("<div id='holder'></div>").appendTo(base.$nav);

      base.$items.each(function(i,el) {
        var index = i + 1;

        try {
          base.attribution[index] = $(this).children().children('img.photo').attr('attribution').trim();
          base.caption[index] = $(this).children().children('img.photo').attr('slidetext').trim();
          base.slidetitle[index] = $(this).children().children('img.photo').attr('slidetitle').trim();
        }
        catch (err) {
          base.attribution[index] = '';
          base.caption[index] = '';
          base.slidetitle[index] = '';
        }

        if(index == 1) {
          var $a = $("<a id='first' href='#'></a>");

          bodyTxt = '';
          attributionTxt = '';
          if (base.attribution[index].length > 0) {
            attributionTxt += '<div class="attribution">' + base.attribution[index] + '</div>';
          }
          if (base.slidetitle[index].length > 0) {
            bodyTxt += '<p class="slidetitle">' + base.slidetitle[index] + '</p>';
          }
          if (base.caption[index].length > 0) {
            bodyTxt += document.getElementById("slideshowBody").innerHTML += '<p>' + base.caption[index] + '</p>';
          }
          document.getElementById("slideshowBody").innerHTML = attributionTxt + bodyTxt;

        }
        else if(index == base.$length) {
          var $a = $("<a id='last' href='#'></a>");
        }
        else {
          var $a = $("<a href='#'></a>");
        }
        // If a formatter function is present, use it
        if( typeof(base.options.navigationFormatter) == "function") {
          if ($(this).children().children('img.photo').attr('thumb') != undefined) {
            $a.html("<img class='slideThumb' src="+$(this).children().children('img.photo').attr('thumb')+" alt=thumb:"+base.options.navigationFormatter(index, $(this))+" />");
          }
          else if ($(this).children().children('img.photo').attr('src') == undefined) {
            $a.html("<img class='slideThumb' src="+$(this).children().children('img.photo').attr('thumb')+" alt=thumb:"+base.options.navigationFormatter(index, $(this))+" />");
          }
          else {
            if ($(this).children().children('img.photo').attr('altImg') != undefined) {
              $a.html("<img class='slideThumb' src="+$(this).children().children('img.photo').attr('altImg')+" alt=thumb:"+base.options.navigationFormatter(index, $(this))+" />");
            }
            else {
              $a.html("<img class='slideThumb' src="+$(this).children().children('img.photo').attr('thumb')+" alt=thumb:"+base.options.navigationFormatter(index, $(this))+" />");
            }
          }
        }
        else {
          $a.text(index);
        }
        // should we display the video icon over the slideshow thumbnail image
        if ($(this).children().children('img.photo').attr('add_thumb_video_icon')) {
          $a.html($a.html() + "<div class='video-circle'><div class='arrow-right'></div></div>");
        }

        $a.click(function(e) {
          base.gotoPage(index);

          if (base.options.hashTags) {
            base.setHash('slide-' + index);
          }

          e.preventDefault();
        });
        base.$holder.append($a);
      });

      base.$navLinks = base.$holder.find('> a');

      base.thumbWidth = $(".slideThumb").width();
      if($("#thumbNav a:nth-child(2)").length > 0) {
        base.thumbPadding = parseInt($("#thumbNav a:nth-child(2)").position().left)-base.thumbWidth;
      }
      base.numViewableThumbs = Math.floor(base.$nav.width() / (base.thumbWidth + base.thumbPadding));
      base.firstThumbPos=1;
      base.lastThumbPos=base.$length;
    };

    // Creates the Forward/Backward buttons
    base.buildNextBackButtons = function() {
      var $forward = $('<a class="arrow forward outside">&gt;</a>'),
          $back    = $('<a class="arrow back outside">&lt;</a>'),
          $forwardInside = $('<a class="arrow forward inside">&gt;</a>'),
          $backInside = $('<a class="arrow back inside">&gt;</a>');

      // Bind to the forward and back buttons
      $back.click(function(e) {
        var element = $("a#first");
        var position = element.position();
        var $backArrow = $(this);
        var thumbNavWidth = base.$nav.width();

        if(base.currentPage > 1){
          base.goBack();
        }
        else {
          bLink = $("#previous a:first-child").attr("href");

          if(typeof bLink != 'undefined') {
            if (bLink.length > 0) {
              window.location = bLink;
            }
          }
        }

        // check the position of previous thumbnail, if exists, otherwise check current thumbnail
        if($("#thumbNav a:nth-child("+eval(base.currentPage-1)+")").length > 0) {
          var thisThumbPos=$("#thumbNav a:nth-child("+eval(base.currentPage-1)+")").position().left;
        }
        else if($("#thumbNav a:nth-child("+base.currentPage+")").length > 0) {
          var thisThumbPos=$("#thumbNav a:nth-child("+base.currentPage+")").position().left;
        }

        if(thisThumbPos && eval(thisThumbPos-base.thumbWidth) < 0) {
          $("#holder:not(:animated)").animate({
            "marginLeft": "+="+eval(base.thumbWidth+base.thumbPadding)+"px"
          }, "slow", function() {
            base.navDisplay();
          }
          );
        }
        else {
          base.navDisplay();
        }

    		if (document.location.hash) {
			  	var index = parseInt(window.location.hash.substr(7));
			  	var newIndex = index - 1;
    			if ((typeof index !== 'undefined') && (index >= 2)) {
				    base.setHash('slide-' + newIndex);
		    	} else {
	        	return true;
	        }
      	}
        base.stopVideos();
      });

      $forward.click(function(e) {
        var element = $("a#last");
        var thumbNavWidth = base.$nav.width();

        if(base.currentPage < base.pages) {
          base.goForward();
        }
        else {
          fLink = $("#next a:first-child").attr("href");
          if(typeof fLink != 'undefined') {
            if (fLink.length > 0) {
              window.location = fLink;
            }
          }
        }

        if(element.length){
          var position = element.position();
          var $nextArrow = $(this);

          // check the position of next thumbnail, if exists, otherwise check current thumbnail
          if($("#thumbNav a:nth-child("+eval(base.currentPage+1)+")").length > 0){
            var thisThumbPos=$("#thumbNav a:nth-child("+eval(base.currentPage+1)+")").position().left;
          }
          else if($("#thumbNav a:nth-child("+base.currentPage+")").length > 0){
            var thisThumbPos=$("#thumbNav a:nth-child("+base.currentPage+")").position().left;
          }


          // if position of thumbnail + thumbnail width is past the width of thumbnail nav window, move the thumbnail nav
          if(thisThumbPos && eval(thisThumbPos+base.thumbWidth) > thumbNavWidth){
            $("#holder:not(:animated)").animate({
              "marginLeft": "-="+eval(base.thumbWidth+base.thumbPadding)+"px"
            }, "slow", function(){
              base.navDisplay();
            }
            );
          }
          base.stopVideos();
        }
        else {
          base.navDisplay();
        }

      	if (document.location.hash) {
	      	var index = parseInt(window.location.hash.substr(7));
	      	var newIndex = index + 1;
	      	if ((typeof index !== 'undefined') && (index < slideshow.length)) {
	        	base.setHash('slide-' + newIndex);
	        } else {
	        	return true;
	        }
        }
      });

      $forwardInside.click(function(e) {
        $forward.click();
      });

      $backInside.click(function(e) {
        $back.click();
      });

      // Append elements to page
      base.$wrapper.after($back).after($forward).after($backInside).after($forwardInside);
    };

    base.stopVideos = function() {
      if (noflash) {
        $(window).load(function() {
          $('video').each(function(){
            this.pause();
          });
        });
      }

      if (typeof maximVideoPlayers == 'object' && jQuery.isEmptyObject(maximVideoPlayers) === false) {
        for (var key in maximVideoPlayers){
          maximVideoPlayers[key].pause();
        }
      }
    }

    base.navDisplay = function() {
      var $firstThumb = $("a#first");
      var $lastThumb = $("a#last");
      var $backArrow = $(".arrow.back");
      var $nextArrow = $(".arrow.forward");

      var thumbNavWidth = $("#thumbNav").width();

      /*
      if(base.currentPage == 1) {
        $backArrow.addClass("disable");
      }
      else {
        $backArrow.removeClass("disable");
      }

      if($lastThumb.length) {
        if(base.currentPage == base.pages) {
          $nextArrow.addClass("disable");
        }
        else {
          $nextArrow.removeClass("disable");
        }
      }
      else {
        $nextArrow.addClass("disable");
      }
      */
    }

    // Creates the Start/Stop button
    base.buildAutoPlay = function(){

      base.$startStop = $("<a href='#' id='start-stop'></a>").html(base.playing ? base.options.stopText :  base.options.startText);
      base.$el.append(base.$startStop);
      base.$startStop.click(function(e){
        base.startStop(!base.playing);
        e.preventDefault();
      });

      // Use the same setting, but trigger the start;
      base.startStop(base.playing);
    };

    // Handles stopping and playing the slideshow
    // Pass startStop(false) to stop and startStop(true) to play
    base.startStop = function(playing) {
      if(playing !== true) playing = false; // Default if not supplied is false

      // Update variable
      base.playing = playing;

      // Toggle playing and text
      if(base.options.autoPlay) base.$startStop.toggleClass("playing", playing).html( playing ? base.options.stopText : base.options.startText );

      if(playing) {
        base.clearTimer(); // Just in case this was triggered twice in a row
        base.timer = window.setInterval(function(){
          base.goForward(true);
        }, base.options.delay);
      }
      else {
        base.clearTimer();
      };
    };

    base.clearTimer = function() {
      // Clear the timer only if it is set
      if(base.timer) window.clearInterval(base.timer);
    };

    // Taken from AJAXY jquery.history Plugin
    base.setHash = function ( hash ) {
      // Write hash
      if ( typeof window.location.hash !== 'undefined' ) {
        if ( window.location.hash !== hash ) {
          window.location.hash = hash;
        };
      }
      else if ( location.hash !== hash ) {
        location.hash = hash;
      };

      // Done
      return hash;
    };
    // <-- End AJAXY code

    // Trigger the initialization
    base.init();
  };

  $.anythingSlider.defaults = {
    resizeContents: false,
    easing: "swing",                    // Anything other than "linear" or "swing" requires the easing plugin
    autoPlay: false,                     // This turns off the entire FUNCTIONALY, not just if it starts running or not
    startStopped: false,                // If autoPlay is on, this can force it to start stopped
    delay: 3000,                        // How long between slide transitions in AutoPlay mode
    animationTime: 600,                 // How long the slide transition takes
    hashTags: true,                     // Should links change the hashtag in the URL?
    buildNavigation: true,              // If true, builds and list of anchor links to link to each slide
    pauseOnHover: true,                 // If true, and autoPlay is enabled, the show will pause on hover
    startText: "Start",                 // Start text
    stopText: "Stop",                   // Stop text
    navigationFormatter: null,          // Details at the top of the file on this use (advanced use)
    thumbWidth: 100,                    // Width of thumbnail
    defaultThumb: '',                   // set the default thumbnail if no other are found
    gaPageTrackURL:'',                  // Google Analytics page track URL
    navigationCallback: null,           // Callback function when user click prev/next buttons
    disableInfiniteScroll: 0            // Disable infinite scroll.  Issue with videos being cloned.
  };

  $.fn.anythingSlider = function(options) {
    if(typeof(options) == "object") {
      return this.each(function(i) {
        (new $.anythingSlider(this, options));

        // This plugin supports multiple instances, but only one can support hash-tag support
        // This disables hash-tags on all items but the first one
        options.hashTags = false;
      });
    }
    else if (typeof(options) == "number") {
      return this.each(function(i) {
        var anySlide = $(this).data('AnythingSlider');

        if(anySlide) {
          anySlide.gotoPage(options);
        }
      });
    }
  };

})(jQuery);
