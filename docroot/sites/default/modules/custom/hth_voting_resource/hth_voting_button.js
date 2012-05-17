(function($){ $(document).ready(function() {
  $('#hth_vote').click(function() {
    uuid = $.cookie('maxim_uuid');
    $.ajax({ url: '/js-api/vote',
             type: 'POST',
             data: {nid: Drupal.settings.Maxim.nid, uid: uuid},
             success: function(data) {
                //alert(data);
                //for some reason dashes are being appended to the result.
                if (data.indexOf('vote_entered') != -1) {
                   $('#hth_vote').after('<div id="vote-success"></div>');
                   $('#hth_vote').fadeOut('slow', function() {
                     $('#vote-success').text('Thank You For Your Vote!');
                    });
                 }
              },
             error: function() { alert('f'); }, cache:false});
           });
     });
})(jQuery)

