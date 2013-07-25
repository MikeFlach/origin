/* For Hometown Hotties Slider */
function hottieSliderLoader(){
  jQuery(".section-content .region-wide-feature.grid-12").show();
  setTimeout(function(){ hottieSliderHighlight(); }, 100);
}

function hottieLoading(num){
  jQuery(".view-hometown-hotties-slider .slider-loading").show();
}

function hottieSliderGoTo(num) {
  var num_per_page = 10;
  if (typeof Drupal.settings.Maxim.hottie.slider_show_max !== 'undefined') {
    num_per_page = Drupal.settings.Maxim.hottie.slider_show_max;
  }
  if (typeof num === 'undefined' && typeof Drupal.settings.Maxim.hottie.hottie_position !== 'undefined') {
    num = Drupal.settings.Maxim.hottie.hottie_position;
  }
  if (!isNaN(num) && !isNaN(num_per_page)) {
    var pg = Math.floor((num-1)/num_per_page);
    Drupal.settings.Maxim.hottie.hottie_position=num;
    if(pg !== Drupal.settings.Maxim.hottie.curr_slider_page) {
      Drupal.settings.Maxim.hottie.curr_slider_page = pg;
      jQuery(".view-id-hometown_hotties_slider .pager .pager-item").eq(pg).children("a").click();
    } else {
      hottieSliderHighlight();
    }
  }
}

function hottieSliderHighlight() {
  if(typeof Drupal.settings.Maxim.hottie.hottie_position !== "undefined"){
    jQuery(".hottie-list .views-row").each( function(index, element){
      pos = jQuery('.position', this).html().trim();
      if (pos == Drupal.settings.Maxim.hottie.hottie_position) {
        jQuery(".view-hometown-hotties-slider .hottie-list ul li").removeClass("active");
        jQuery(this).addClass('active');
      }
    });
  }
}

jQuery(function(){
  if (typeof Drupal.settings.Maxim.hottie.hottie_week != 'undefined' &&
      Drupal.settings.Maxim.hottie.hottie_week == 'Gamer Girl Finalist') {
    var prev_button = 'http://cdn2.maxim.com/maxim/sites/default/files/gg_prev_finalist.gif';
    var next_button = 'http://cdn2.maxim.com/maxim/sites/default/files/gg_next_finalist.gif';
  }
  else {
    var prev_button = 'http://cdn2.maxim.com/maxim/sites/default/libraries/hth/hottie_prev.png';
    var next_button = 'http://cdn2.maxim.com/maxim/sites/default/libraries/hth/hottie_next.png';
  }

  if (typeof Drupal.settings.Maxim.hottie.hottie_prev != 'undefined' && Drupal.settings.Maxim.hottie.hottie_prev.length > 0){
    jQuery(".field-name-hotties-previous-next .hottie-prev-btn").html('<a href="' + Drupal.settings.Maxim.hottie.hottie_prev + '"><img src="'+prev_button+'" width="111" height="22" alt="Previous Hottie" title="Previous Hottie"  /></a>');
    jQuery(".field-name-hotties-previous-next .hottie-prev-btn").show();
  }
  if (typeof Drupal.settings.Maxim.hottie.hottie_next != 'undefined' && Drupal.settings.Maxim.hottie.hottie_next.length > 0){
    jQuery(".field-name-hotties-previous-next .hottie-next-btn").html('<a href="' + Drupal.settings.Maxim.hottie.hottie_next + '"><img src="'+next_button+'" width="111" height="22" alt="Next Hottie" title="Next Hottie" /></a>');
    jQuery(".field-name-hotties-previous-next .hottie-next-btn").show();
  }
  Drupal.settings.Maxim.hottie.curr_slider_page = 0;
  
  // can't for the life of me get the contexts straightened out. for some reson semifinals displays 2 sliders. remove week slider if emi is present
  if ((jQuery(".hotties-slider-semifinals").length) || ((jQuery(".hotties-slider-finals").length)))  {
    jQuery(".hotties-slider-week1").remove();
    jQuery(".hotties-slider-week2").remove();
    jQuery(".hotties-slider-week3").remove();
    jQuery(".hotties-slider-week4").remove();
    jQuery(".hotties-slider-week5").remove();
    
    if (jQuery(".hotiies-slider-finals").length) {
      jQuery(".hotties-slider-semifinals").remove();
    }
  }
  
  hottieSliderGoTo();
});
