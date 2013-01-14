(function($){ $(document).ready(function() {
  $('#generic_vote').bind('click', function() {
    $('#generic_vote').unbind('click');
    uuid = $.cookie('maxim_uuid');
    $.ajax({ 
        url: '/vote/generic-vote',
        type: 'POST',
        data: 
          {
            nid: Drupal.settings.Maxim.nid, 
            uid: uuid, 
             vc: Drupal.settings.Maxim.general_profile_data.vote_campaign_name
          },
          success: 
            function(data) {
              if (data.indexOf('vote_entered') != -1) {
                 $('#generic_vote').fadeOut('slow', function() {
                   $('#generic_vote').after('<div id="generic-vote-success"></div>');
                   $('#generic-vote-success').html(Drupal.settings.Maxim.general_profile_data.vote_success_text);
                 });
               }
            },
          error: function() {}
    });
  });
});})(jQuery)