(function($){ $(document).ready(function() {
  $('#hth_vote').bind('click', function() {
    $('#hth_vote').unbind('click');
    uuid = $.cookie('maxim_uuid');
    $.ajax({ url: '/voting/hth/enter-vote',
             type: 'POST',
             data: {nid: Drupal.settings.Maxim.nid, uid: uuid},
             success: function(data) {
                if (data.items.statusMsg.indexOf('vote recorded') != -1) {
                   $('#hth_vote').fadeOut('slow', function() {
                     $('#hth_vote').after('<div id="vote-success"></div>');
                     

                     $('#vote-success').html('Thanks! Vote daily for your favorite Hotties. Enter for a chance to party with the Hometown Hotties Winner <a href="/hthparty" target="_blank">here</a>.');
                   });
                 }
              },
             error: function (xhr, ajaxOptions, thrownError) {
                alert(xhr.status);
                alert(thrownError);
             }});
    });
  });
})(jQuery)
