function slot_hottie (sid, slot) {
  jQuery(document).ready(function() {
    jQuery.ajax({
      url: '/do/hottie-slotting',
      data: {nid: '36876',
             sid: sid,
             cid: '75',
              no: 0,
            slot: slot.toLowerCase() },
      type: 'GET',
      success: function(data){
        res = jQuery(data).find("slotting-result").text();
        if (res.indexOf('Error!') == -1) {
          jQuery("#status-s-"+sid).show();
          jQuery("#status-f-"+sid).hide();
        }
        else {
          jQuery("#status-s-"+sid).hide();
          jQuery("#status-f-"+sid).show();
        }
      },
      error: function(){
        jQuery("#status-s-"+sid).hide();
        jQuery("#status-f-"+sid).show();
      }
    });
  });
}

function call_cbox(img) {
  jQuery().colorbox({html:'<img class="sm-cbox-pic" src="'+img.src+'"/>'});
}

