/* For Hometown Hotties Slider */
function gprofileSliderLoader(){
  jQuery(".section-content .region-wide-feature.grid-12").show();
  setTimeout(function(){ gprofileSliderHighlight(); }, 100);
}

function gprofileLoading(num){
  jQuery(".view-hometown-gprofiles-slider .slider-loading").show();
}

function gprofileSliderGoTo(num) {
  var num_per_page = 10;
  if (typeof Drupal.settings.Maxim.general_profile_data.slider_show_max !== 'undefined') {
    num_per_page = Drupal.settings.Maxim.general_profile_data.slider_show_max;
  }
  if (typeof num === 'undefined' && typeof Drupal.settings.Maxim.general_profile_data.gprofile_position !== 'undefined') {
    num = Drupal.settings.Maxim.general_profile_data.gprofile_position;
  }
  if (!isNaN(num) && !isNaN(num_per_page)) {
    var pg = Math.floor((num-1)/num_per_page);
    Drupal.settings.Maxim.general_profile_data.gprofile_position=num;
    if(pg !== Drupal.settings.Maxim.general_profile_data.curr_slider_page) {
      Drupal.settings.Maxim.general_profile_data.curr_slider_page = pg;
      jQuery(".view-id-hometown_gprofiles_slider .pager .pager-item").eq(pg).children("a").click();
    } else {
      gprofileSliderHighlight();
    }
  }
}

function gprofileSliderHighlight() {
  if(typeof Drupal.settings.Maxim.general_profile_data.gprofile_position !== "undefined"){
    jQuery(".gprofile-list .views-row").each( function(index, element){
      pos = jQuery('.position', this).html().trim();
      if (pos == Drupal.settings.Maxim.general_profile_data.gprofile_position) {
        jQuery(".view-hometown-gprofiles-slider .gprofile-list ul li").removeClass("active");
        jQuery(this).addClass('active');
      }
    });
  }
}

jQuery(function(){
  var prev_button_url = Drupal.settings.Maxim.general_profile_data.gprofile_prev_url;
  var next_button_url = Drupal.settings.Maxim.general_profile_data.gprofile_next_url;
  var prev_button_img = Drupal.settings.Maxim.general_profile_data.prev_btn_img;
  var next_button_img = Drupal.settings.Maxim.general_profile_data.next_btn_img;
  
  if (typeof prev_button_url != 'undefined' && prev_button_url.length > 0){
    jQuery(".field-name-general-profile-previous-next .gprofile-prev-btn").html('<a href="' + prev_button_url + '"><img src="'+prev_button_img+'" width="111" height="22" alt="Previous Profile" /></a>');
    jQuery(".field-name-general-profile-previous-next .gprofile-prev-btn").show();
  }         
  if (typeof next_button_url != 'undefined' && next_button_url.length > 0){
    jQuery(".field-name-general-profile-previous-next .gprofile-next-btn").html('<a href="' + next_button_url + '"><img src="'+next_button_img+'" width="111" height="22" alt="Next Profile" /></a>');
    jQuery(".field-name-general-profile-previous-next .gprofile-next-btn").show();
  }
  
  Drupal.settings.Maxim.general_profile_data.curr_slider_page = 0;
  
  // can't for the life of me get the contexts straightened out. for some reson semifinals displays 2 sliders. remove week slider if emi is present
  /*
  if (jQuery(".view-display-id-gprofiles_slider_semis").length) {
    jQuery(".view-display-id-gprofiles_slider_wk_1").remove();
    jQuery(".view-display-id-gprofiles_slider_wk_2").remove();
    jQuery(".view-display-id-gprofiles_slider_wk_3").remove();
    jQuery(".view-display-id-gprofiles_slider_wk_4").remove();
    jQuery(".view-display-id-gprofiles_slider_wk_5").remove();
  }
  */
  //gprofileSliderGoTo();
  
});
