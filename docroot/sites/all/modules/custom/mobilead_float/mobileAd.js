(function ($) {

/**
 * Mobile Ads
 *
 * Sample options:
 * Drupal.settings.mobileAds.options = { 'minScrollTop': 200, 'maxWidth': 500 };
 *
 * Sample ad:
 * Drupal.settings.mobileAds.ads.push({
 *  'name': 'doritos',
 *  'url': 'http://www.doritos.com',
 *  'img':  '/sites/default/files/ads/mobile_ad_doritos.png'
 * });
 */
Drupal.mobilead_float = {
  options:{
    minScrollTop: 500,
    fadeInterval: 500,
    maxWidth: 980
  },
  showAdIndex : -1
};

/* Load options */
Drupal.mobilead_float.loadOptions = function(){
  if (typeof Drupal.settings.mobileAds === 'object' && typeof Drupal.settings.mobileAds.options === 'object') {
    for(var option in Drupal.settings.mobileAds.options){
      Drupal.mobilead_float.options[option] = Drupal.settings.mobileAds.options[option];
    }
  }
};

/* Load mobile ad */
Drupal.mobilead_float.loadAd = function() {
  var rNum = Math.random(); // Random number 
  var numAds = Drupal.settings.mobileAds.ads.length;
  var ads = [];
  var cookieVal = [];
  // Remove any ads already seen
  if ($.cookie('mxm_mobileAd')) {
    cookieVal = $.cookie('mxm_mobileAd').split('|');
    for (var i=0; i < numAds; i++) {
      if($.inArray(Drupal.settings.mobileAds.ads[i].name, cookieVal) === -1){
        ads.push(Drupal.settings.mobileAds.ads[i]);
      }
    }
    numAds = ads.length;
    Drupal.settings.mobileAds.ads = ads;
  }

  if(numAds > 0){
    var freq = 1/numAds; // Calculate frequency of ad display
    // Get random ad 
    for (var i=0; i < numAds; i++) {
      if (rNum < (i+1)*freq) {
        this.showAdIndex = i;
        break;
      }
    }
  }
};

/* Show mobile ad */
Drupal.mobilead_float.showAd = function(){
  var adHeight = $("#mobileAdFloat").outerHeight();
  $(window).unbind("scroll");

  $("#mobileAdFloat .adImage").attr("src", Drupal.settings.mobileAds.ads[this.showAdIndex].img);
  $("#mobileAdFloat").fadeIn(this.options.fadeInterval);

  $("#mobileAdFloat").bind("click", function() {
	  Drupal.mobilead_float.saveToCookie();
    window.open(Drupal.settings.mobileAds.ads[Drupal.mobilead_float.showAdIndex].url, '_blank');
    return false;
  });

  $("#mobileAdFloat .close").bind("click", function() {
    Drupal.mobilead_float.closeAd();
    return false;
	});
};

/* Close mobile ad */
Drupal.mobilead_float.closeAd = function(){
  Drupal.mobilead_float.saveToCookie();
  $("#mobileAdFloat").fadeOut(this.options.fadeInterval);
};

/* Add ad to cookie */
Drupal.mobilead_float.saveToCookie = function(){
  var val=[];
  var valExists = 0;
  var currentAdName = Drupal.settings.mobileAds.ads[Drupal.mobilead_float.showAdIndex].name;
  if ($.cookie('mxm_mobileAd')) {
    val = $.cookie('mxm_mobileAd').split('|');
  }
  for (var i; i < val.length; i++) {
    if (val[i] == currentAdName) {
      valExists = 1;
      break;
    }
  }

  if (valExists == 0){
    val.push(currentAdName);
  }
  
  $.cookie('mxm_mobileAd', val.join('|'), { path:'/' } );
};

/* Attach mobilead to page */
Drupal.behaviors.mobilead_float = {
  attach: function(context, settings){ 
    /* Load options */
    Drupal.mobilead_float.loadOptions();
    /* Only display on smaller screens */
    if ($(window).width() >= Drupal.mobilead_float.options.maxWidth || (typeof settings.mobileAds !== 'object' || typeof settings.mobileAds.ads !== 'object' && settings.mobileAds.ads.length > 0)) {
      return;
    }

    /* See what ads are available */
    Drupal.mobilead_float.loadAd();

    // If there is an ad to display, bind scroll event
    if(Drupal.mobilead_float.showAdIndex !== -1) {
      $(window).bind("scroll", function() {
		    sTop = $(window).scrollTop();
		    if(sTop > Drupal.mobilead_float.options.minScrollTop) {
          Drupal.mobilead_float.showAd();
        }
      });
    }
  }
};

})(jQuery);
