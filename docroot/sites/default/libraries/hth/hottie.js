(function($){ $(document).ready(function() {
    if (typeof Drupal.settings.Maxim.hottie.hottie_prev != 'undefined' && Drupal.settings.Maxim.hottie.hottie_prev.length > 0){
      $(".field-name-hotties-previous-next .hottie-prev-btn").html('<a href="' + Drupal.settings.Maxim.hottie.hottie_prev + '"><img src="http://cdn2.maxim.com/maxim/sites/default/libraries/hth/hottie_prev.png" width="111" height="22" alt="Previous Hottie" title="Previous Hottie"  /></a>');
      $(".field-name-hotties-previous-next .hottie-prev-btn").show();
    }
    if (typeof Drupal.settings.Maxim.hottie.hottie_next != 'undefined' && Drupal.settings.Maxim.hottie.hottie_next.length > 0){
      $(".field-name-hotties-previous-next .hottie-next-btn").html('<a href="' + Drupal.settings.Maxim.hottie.hottie_next + '"><img src="http://cdn2.maxim.com/maxim/sites/default/libraries/hth/hottie_next.png" width="111" height="22" alt="Next Hottie" title="Next Hottie" /></a>');
      $(".field-name-hotties-previous-next .hottie-next-btn").show();
    }
  });
})(jQuery)
