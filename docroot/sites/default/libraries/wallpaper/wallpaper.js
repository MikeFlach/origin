jQuery(document).ready(function(){
  var compareWidth; //previous width used for comparison
  var detector; //the element used to compare changes
  if (typeof skin_pixel == 'undefined' || skin_pixel.length == 0) { skin_pixel = 'http://view.atdmt.com/MDS/view/368170309/direct/01/' }
  if (typeof skin_bgcolor == 'undefined') { skin_bgcolor = ''; }
  if (typeof skin_large == 'undefined') { skin_large = ''; }
  if (typeof skin_tablet == 'undefined') { skin_tablet = ''; }
  if (typeof skin_mobile == 'undefined') { skin_mobile = ''; }
  if (typeof skin_jump == 'undefined') { skin_jump = ''; }
  if (typeof skin_attachment == 'undefined') { skin_attachment = 'fixed'; }

  //set the initial values
  detector = jQuery('body');

  detector.prepend('<img src="' + skin_pixel +'" width="1" height="1" alt="_" style="display:none;" />');
  detector.prepend('<div id="wallpaper"></div>');

  $wallpaper = jQuery('#wallpaper');
  if (skin_attachment == 'scroll') {
    $wallpaper.css('position', 'absolute');
  }

  compareWidth = detector.width();

  jQuery(window).resize(function(){
    //compare everytime the window resize event fires
    if(detector.width()!=compareWidth){
      //a change has occurred so update the comparison variable
      compareWidth = detector.width();
      setBackground(detector.width());
    }
  });

  // set background to large, tablet, or mobile skin depending on browser width
  function setBackground(width) {
    if ( skin_bgcolor.length ) {
      detector.css('background-color', skin_bgcolor);
    }
    if ( skin_large.length && width > 980 ) {
      $wallpaper.css('background', 'url("' + skin_large + '") no-repeat top center ' + skin_attachment);
      toggle_top_bg(0);
    }
    else if ( skin_tablet.length && width <= 980 && width >= 680 ) {
      $wallpaper.css('background', 'url("' + skin_tablet + '") no-repeat top center ' + skin_attachment);
      toggle_top_bg(0);
    }
    else if ( skin_mobile.length && width <= 680 && width >= 480) {
      $wallpaper.css('background', 'url("' + skin_mobile + '") no-repeat top center ' + skin_attachment);
      toggle_top_bg(0);
    }
    else {
      $wallpaper.css('background', 'none');
      toggle_top_bg(1);
    }
  }
  setBackground(detector.width());

  function toggle_top_bg(show){
    if (typeof show == 'undefined') { show=1; }
    if(show == 1){
      jQuery('#zone-pushdown-wrapper').removeClass('hide-bg');
      jQuery('#zone-utility-menu-wrapper').removeClass('hide-bg');
      jQuery('#zone-menu-wrapper').removeClass('hide-bg');
    } else {
      jQuery('#zone-pushdown-wrapper').addClass('hide-bg');
      jQuery('#zone-utility-menu-wrapper').addClass('hide-bg');
      jQuery('#zone-menu-wrapper').addClass('hide-bg');
    }
  }

  if(skin_jump.length){
    jQuery('body').click(function(e){
      // check to see if no toolbar exists if and click on page
      if ((typeof Drupal.toolbar != 'object') && (e.pageX != 0 && e.pageY != 0)) {
        var contentWidth = jQuery('#zone-content').width();
        var diff = (jQuery(this).width() - contentWidth) / 2;
        if(e.pageX < diff || e.pageX > contentWidth + diff){
          // skip wallpaper click if user clicked on any html input on the page
          if (!jQuery(":input").is(e.target)) {
            window.open(skin_jump, '_blank');
          }
        }
      }
    });
  }
});

