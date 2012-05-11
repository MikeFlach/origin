(function($){ $(document).ready(function() {
  $('#hth_vote').click(function() {
    uuid = $.cookie('maxim_uuid');
    $.ajax({ url: '/js-api/vote', type: 'POST', data: {nid: Drupal.settings.Maxim.nid, uid: uuid},
      success: function() { alert('s'); },
      error: function() { alert('f'); },cache:false});
});});})(jQuery)