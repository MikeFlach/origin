//global var to hold all nids voted by this user for this day
var node_list = [];
var initialized = false;

(function ($) {
  Drupal.behaviors.hot100_voting = {
    attach: function (context) {   
      var campaign = Drupal.settings.Maxim.generic_multivote_settings.campaign;
      var uuid = $.cookie('maxim_uuid');
      
      $('.multi-vote .btn', context).each(function() {
        $(this).bind('click', function() {
          $(this).unbind('click');

          $.ajax({ 
              url: '/js-api/multi-vote',
              type: 'POST',
              data: 
                {
                  campaign: campaign, 
                  uid: uuid,
                  nid: $(this).attr('id').split('-')[1]
                },
                success:
                  function(data) {
                    if (data.indexOf('vote_entered') != -1) {
                      nid = $.trim(data.split('::nid=')[1]);
                      $('#vb-'+nid).fadeOut('fast', function() {
                        $('#vb-'+nid).after('<div class="vote-success" id="vote-success-'+nid+'"></div>');
                        $('#vote-success-'+nid).html(Drupal.settings.Maxim.generic_multivote_settings.response_txt).fadeIn('fast');
                      });
                    }
                  },
                error: function() {}
          });
        });
      });
      processVotes(node_list, context);
    }
  }
})(jQuery);

function storeNids(nid_list) {
  nid_list = jQuery.parseJSON(nid_list);
  node_list = nid_list;
  initialized = true;
  processVotes(node_list);
}

function processVotes(nid_list, context) {
  if (initialized) {
    jQuery('.multi-vote .btn', context).each(function() {
      nid = parseInt(jQuery(this).attr('id').split('-')[1]);
      if (jQuery.inArray(nid, nid_list) > -1 ) {
        jQuery('#vb-'+nid).hide();
        jQuery('#vmsg-'+nid).html(Drupal.settings.Maxim.generic_multivote_settings.limit_txt);
        jQuery('#vmsg-'+nid).show();
      }
      else {
        jQuery('#vb-'+nid).show();
      }
    });  
  }
}