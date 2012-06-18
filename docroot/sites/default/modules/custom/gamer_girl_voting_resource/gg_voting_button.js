(function($){ $(document).ready(function() {
  $('#gg_vote').bind('click', function() {
    $('#gg_vote').unbind('click');
    uuid = $.cookie('maxim_uuid');
    $.ajax({ url: '/js-api/gamer-girl-vote',
             type: 'POST',
             data: {nid: Drupal.settings.Maxim.nid, uid: uuid},
             success: function(data) {
                if (data.indexOf('vote_entered') != -1) {
                   $('#gg_vote').fadeOut('slow', function() {
                     $('#gg_vote').after('<div id="vote-success"></div>');
                     $('#vote-success').text('Thanks! Now feel free to cast your ballot for other gamer girls.');
                   });
                 }
              },
             error: function() {}
          });
    });
  });
})(jQuery)
