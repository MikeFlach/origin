(function($){ $(document).ready(function() {
  $('#hth_vote').click(function() {
    uuid = $.cookie('maxim_uuid');
    $.ajax({ url: '/js-api/vote',
             type: 'POST',
             data: {nid: Drupal.settings.Maxim.nid, uid: uuid},
             success: function(data) {
                if (data.indexOf('vote_entered') != -1) {
                   $('#hth_vote').fadeOut('slow', function() {
                     $('#hth_vote').after('<div id="vote-success"></div>');
                     $('#vote-success').text('Thanks! Now feel free to cast your ballot for other girls.');
                   });
                 }
              },
             error: function() {}});
           });
     });
})(jQuery)
