function slot_hottie (sid, slot) {
  jQuery(document).ready(function() {
    jQuery.ajax({
      url: '/do/hottie-slotting',
      data: {nid: '36876',
             sid: sid,
             cid: '75',
              no: 0,
            slot: slot.toLowerCase() },
      type: 'POST',
      success: function(){
        jQuery("#status-s-"+sid).show();
        jQuery("#status-f-"+sid).hide();
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

