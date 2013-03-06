/**
* Main JavaScript file for Maxim GMap Extensions module.
* Provides geolocation functionality for a GMap.
*/

// Namespace $ for jQuery.
(function($) {

/**
* Wrap handlers in a Drupal behavior so that we can be sure that everything is available.
*/
Drupal.behaviors.maxim_gmap_extensions = {
  'attach': function(context, settings) {
    // The following ensures that the behavior is only performed
    // once. Since we are adding a handler for all GMap maps,
    // we are not concerned with context.
    $('body').once(function() {
      // Add a handler to the map
      Drupal.gmap.addHandler('gmap', function(elem) {
        var gmap = this;
        // gmap (this) is the main gmap module with the following main properties:
        // - map: The Google Maps API object.
        // - vars: The configuration passed from Drupal.
        // elem is the DOM object that holds the Google Map.
        // The ready event is fired when things are ready with the map.
        gmap.bind('ready', function() {
          // We would normally check the map object to see
          // if this behavior has been enabled, but for some reason
          // this setting it is not available. (bug with gmap)
          // We utilize jQuery to turn our block into a link
          // to update the map with user's location.
          // Add a listener here to ensure users cannot zoom in too far.
          google.maps.event.addListener(gmap.map, 'zoom_changed', function() {
            minZoom = 3;
            maxZoom = 11;
            if (gmap.map.getZoom() > maxZoom) {
              gmap.map.setZoom(maxZoom);
            } else if (gmap.map.getZoom() < minZoom) {
              gmap.map.setZoom(minZoom);
            }
          });
          $('.maxim-gmap-geolocate-action')
            .show()
            .html(Drupal.t('Show me the contestants near my Hometown'))
            .click(function(e) {
              Drupal.behaviors.maxim_gmap_extensions.geolocate(gmap.map);
              e.preventDefault();
            });
        });
      });
    });
  },
  // General function to geolocate user.
  'geolocate': function(map) {
    // First ensure that the HTML5 geolocation controls are available.
    if (typeof navigator != 'undefined' && typeof navigator.geolocation != 'undefined') {
      navigator.geolocation.getCurrentPosition(function (position) {
        lat = position.coords.latitude;
        lng = position.coords.longitude;
        map.setCenter(new google.maps.LatLng(lat, lng));
        map.setZoom(11);
      });
    }
  }
};

})(jQuery);
