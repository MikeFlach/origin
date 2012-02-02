var circMag = new ( function($) { 
  var me = this;
  var circTimeout = 15000; // circ ad - collapses after x milliseconds
  var circTimeoutCall;
  var cAdCookieCollapseExp = 7; // circ ad - first time check cookie exp (days)
  var cAdCookieCloseExp = 1; // circ ad - close button cookie exp (days)
  var bottomOffset = 50;
	
  $(function() {
    /* Only display for larger screens */
    if($(window).width() < 980){
      return;
    }

    /* circ expandable event listeners */
	  $("#circAd .expanded").live("click", function() {
		  $this = $(this);
		  contentH = $("#circAd .circAdContent").outerHeight();
		  $("#circAd").animate({"bottom" : -1 * contentH}, 700, function() {
			  $this.removeClass("expanded").addClass("collapsed");
		  });
		  clearTimeout(circTimeoutCall);
		  return false;
	  });
	  $("#circAd .collapsed").live("click", function() {
		  $this = $(this);
		  $("#circAd").animate({"bottom" : 0}, 700, function() {
			  $this.removeClass("collapsed").addClass("expanded");
		  });
		  clearTimeout(circTimeoutCall);
		  return false;
	  });
	  $("#circAd .close").bind("click", function() {
		  $.cookie('mxm_circad_closed', true, { expires: cAdCookieCloseExp, path:'/' } );
		  $(window).unbind("scroll");
		  $("#circAd").fadeOut(500);
		  return false;
	  });
		
	  /* attach scroll event if mxm_circad_closed cookie does not exist - display when user scrolls beyond 1000px */
	  if(!$.cookie('mxm_circad_closed')) {
		  $(window).bind("scroll", function() {
			  if($("#circAd").is(":hidden")) {
				  sTop = $(window).scrollTop();
				  if(sTop > 1000) {
					  /* check if its not user's first time  to see the ad */ 
					  if($.cookie('mxm_circad')) {
						  me.showCollapsedCircAd();
					  }
					  else {
						  $.cookie('mxm_circad', true, { expires: cAdCookieCollapseExp, path:'/' });
						  me.showExpandedCircAd();
					  }
					  circTimeoutCall = setTimeout(function() {
						  $("#circAd .expanded").click();
					  }, circTimeout); 
				  }
			  }
		  });
	  }
  }); 
	
  /* displays the collapsed expandable circ ad */
  me.showCollapsedCircAd = function() {
	  $("#circAd").css({"display":"block","visibility":"hidden"});
	  contentH = $("#circAd .circAdContent").outerHeight();
	  startBottom = $("#circAd").outerHeight() + bottomOffset;
	  $("#circAd .expanded").removeClass("expanded").addClass("collapsed");
	  $("#circAd").css({"bottom" : -1 * startBottom, "visibility":"visible"});
	  $("#circAd").animate({"bottom" : -1 * contentH}, 500);
  };
	
  /* displays the expandable circ ad */
  me.showExpandedCircAd = function() {
	  $("#circAd").css({"display":"block","visibility":"hidden"});
	  startBottom = $("#circAd").outerHeight() + bottomOffset;
	  $("#circAd").css({"bottom" : -1 * startBottom, "visibility":"visible"});
	  $("#circAd").animate({"bottom" : 0}, 800);
  };

})(jQuery);
