var promoFloat = new ( function($) {
  var me = this;
  var adTimeout = 15000; // promo ad - collapses after x milliseconds
  var adTimeoutCall;
  var pAdCookieCollapseExp = 2; // promo ad - first time check cookie exp (days)
  var pAdCookieCloseExp = 1; // promo ad - close button cookie exp (days)
  var bottomOffset = 50;
  var disablePromoMag = 0;

  $(function() {
    /* Only display for larger screens */
    if($(window).width() < 980 || $('#promoFloatAd').length == 0 || disablePromoMag == 1){
      return;
    }

    $("#promoFloatAd").css({"left": (10 + $("#zone-content").offset().left) + 'px' });

    /* promo expandable event listeners */
    $("#promoFloatAd .expanded").live("click", function() {
      $this = $(this);
      contentH = $("#promoFloatAd .promoAdContent").outerHeight();
      $("#promoFloatAd").animate({"bottom" : -1 * contentH}, 700, function() {
        $this.removeClass("expanded").addClass("collapsed");
      });
      clearTimeout(adTimeoutCall);
      return false;
    });
    $("#promoFloatAd .collapsed").live("click", function() {
      $this = $(this);
      $("#promoFloatAd").animate({"bottom" : 0}, 700, function() {
        $this.removeClass("collapsed").addClass("expanded");
      });
      clearTimeout(adTimeoutCall);
      return false;
    });
    $("#promoFloatAd .close").bind("click", function() {
      $.cookie('mxm_promoad_closed', true, { expires: pAdCookieCloseExp, path:'/' } );
      disablePromoMag = 1;
      $("#promoFloatAd").fadeOut(500);
      return false;
    });

    $(window).resize(function() {
      $("#promoFloatAd").css({"left": (10 + $("#zone-content").offset().left) + 'px' });
    });

    /* attach scroll event if mxm_promoad_closed cookie does not exist - display when user scrolls beyond 1000px */
    if(!$.cookie('mxm_promoad_closed')) {
      $(window).bind("scroll", function() {
        if($("#promoFloatAd").is(":hidden") && disablePromoMag == 0) {
          sTop = $(window).scrollTop();
          if(sTop > 1000) {
            /* check if its not user's first time  to see the ad */
            if($.cookie('mxm_promoad')) {
              me.showCollapsedPromoAd();
            }
            else {
              $.cookie('mxm_promoad', true, { expires: pAdCookieCollapseExp, path:'/' });
              me.showExpandedPromoAd();
            }
            adTimeoutCall = setTimeout(function() {
              $("#promoFloatAd .expanded").click();
            }, adTimeout);
          }
        }
      });
    }
  });

  me.showPromoPixelTracking = function() {
    var timestamp = new Date().getTime();
    var pixelTracking = '<img src="http://ad.doubleclick.net/ad/maxim.dart/;adid=259836500;sz=1x1;ord=[timestamp]?" border="0" alt="" />';
    $("#promoFloatAd .promoFloatPixel").html(pixelTracking.replace(/\[timestamp\]/g, timestamp));
  }

  /* displays the collapsed expandable promo ad */
  me.showCollapsedPromoAd = function() {
    $("#promoFloatAd").css({"display":"block","visibility":"hidden"});
    contentH = $("#promoFloatAd .promoAdContent").outerHeight();
    startBottom = $("#promoFloatAd").outerHeight() + bottomOffset;
    $("#promoFloatAd .expanded").removeClass("expanded").addClass("collapsed");
    $("#promoFloatAd").css({"bottom" : -1 * startBottom, "visibility":"visible"});
     me.showPromoPixelTracking();
    $("#promoFloatAd").animate({"bottom" : -1 * contentH}, 500);
  };

  /* displays the expandable promo ad */
  me.showExpandedPromoAd = function() {
    $("#promoFloatAd").css({"display":"block","visibility":"hidden"});
    startBottom = $("#promoFloatAd").outerHeight() + bottomOffset;
    $("#promoFloatAd").css({"bottom" : -1 * startBottom, "visibility":"visible"});
    me.showPromoPixelTracking();
    $("#promoFloatAd").animate({"bottom" : 0}, 800);
  };

})(jQuery);
