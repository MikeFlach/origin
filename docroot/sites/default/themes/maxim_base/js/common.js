// For refreshing DART ads
function maxim_dart(dart_tag, refresh) {
  if (typeof refresh == 'undefined') {
    refresh = 0;
  }
  if (refresh == 1) {
    ord = 1000000000 + Math.floor(Math.random() * 900000000);
    jQuery('.dart-name-'+dart_tag).removeClass('dart-processed');
    jQuery('.dart-name-'+dart_tag + ' .dart-processed-ad').remove();
  }
  if (typeof Drupal.DART.settings.loadLastTags[dart_tag] !== 'undefined' && jQuery('.dart-name-'+dart_tag).hasClass('dart-processed') === false) {
    var scriptTag = Drupal.DART.tag(Drupal.DART.settings.loadLastTags[dart_tag]);
    jQuery('.dart-name-'+dart_tag + ' script').nextAll().remove();
    jQuery('.dart-name-'+dart_tag).writeCapture().append('<span class="dart-processed-ad">' + scriptTag + '</span>').addClass('dart-processed');
  }
}
