// For refreshing DART ads
function maxim_dart(dart_tag, refresh) {
  if (typeof refresh == 'undefined') {
    refresh = 0;
  }
  if (typeof Drupal.DART.settings.loadLastTags !== 'undefined') {
    if (refresh == 1) {
      ord = 1000000000 + Math.floor(Math.random() * 900000000);
      jQuery('.dart-name-'+dart_tag).removeClass('dart-processed');
      jQuery('.dart-name-'+dart_tag + ' .dart-processed-ad').remove();
    }
    if (typeof Drupal.DART.settings.loadLastTags[dart_tag] !== 'undefined' && jQuery('.dart-name-'+dart_tag).hasClass('dart-processed') === false) {
      var scriptTag = Drupal.DART.tag(Drupal.DART.settings.loadLastTags[dart_tag]);
      jQuery('.dart-name-'+dart_tag + ' script').nextAll().remove();

      if (typeof(postscribe) == 'function') {
        postscribe(jQuery('.dart-name-'+dart_tag), '<span class="dart-processed-ad">' + scriptTag + '</span>', function () { jQuery('.dart-name-'+dart_tag).addClass('dart-processed'); });
      } else if (typeof(jQuery('.dart-name-'+dart_tag).writeCapture) == 'function') {
        jQuery('.dart-name-'+dart_tag).writeCapture().append('<span class="dart-processed-ad">' + scriptTag + '</span>').addClass('dart-processed');
      }
    }
  }
}

// Infocus ad setup
function maxim_dart_infocus(dart_tag) {
  var adBlock = '.block-dart-tag-' + dart_tag.replace(/_/g, '-');
  if (jQuery(adBlock).length > 0) {
    var infocusAdPos = jQuery(adBlock).offset().top;
    jQuery(window).bind('scroll', function() {
      if (jQuery(window).scrollTop() >= infocusAdPos) {
        jQuery(window).unbind('scroll');
        jQuery('.dart-name-' + dart_tag).show();
        maxim_dart(dart_tag);
      }
    });
  }
}

// Initialize infocus ads
jQuery(function(){
  maxim_dart_infocus('dart_big_box_infocus');
  jQuery(".sbd a").click(function(){
    var player = jQuery(this).data("player");
    jQuery('audio').each(function(){
      if(!this.paused){
         this.pause();
         this.currentTime=0;
      }
    });
    jQuery("#"+player).find('audio').get(0).play();
  });
});

// For reinitializing elements on page. Especially after Genesis Media ads.
function mxm_page_callback() {
  if (window.loadSlideShowImages) {
    loadSlideShowImages();
  }
}
