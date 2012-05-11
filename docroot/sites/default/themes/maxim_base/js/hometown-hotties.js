/* For Hometown Hotties Slider */
function hottieSliderLoader(){
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
  Drupal.settings.Maxim.hottie.curr_slider_page = 0;
  hottieSliderGoTo();
});
