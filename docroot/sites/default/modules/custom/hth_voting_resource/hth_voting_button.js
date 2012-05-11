(function($){ $(document).ready(function() {
  $('#hth_vote').click(function() {
    uuid = $.cookie('maxim_uuid');
    $.ajax({ url: '/js-api/vote/'+Drupal.settings.Maxim.nid+':::::'+uuid+'.json', type: 'GET',
      success: function() { alert('s'); },
      error: function() { alert('f'); },cache:false});
});});})(jQuery)