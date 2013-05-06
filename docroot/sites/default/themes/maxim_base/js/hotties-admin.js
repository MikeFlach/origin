function slot_hottie (sid, slot) {
  jQuery(document).ready(function() {
    jQuery.ajax({
      url: '/voting/hth/hottie-slotting',
      data: {nid: '67256',
             sid: sid,
             cid: '41',
              no: 0,
            slot: slot.toLowerCase() },
      type: 'POST',

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

  week_display(slot, sid);
}

function week_display(slot, sid) {
 if (slot.toLowerCase() === 'yes') {
   jQuery("#dw"+sid).show();
 }
 else {
   jQuery("#dw"+sid).hide();
 }
}

function slot_week (sid, slot, week) {
  if (slot.toLowerCase() != 'yes') {
    week = 'not_assigned';
  }

  jQuery(document).ready(function() {
    jQuery.ajax({
      url: '/voting/hottie-slotting',
      data: {nid: '67256',
             sid: sid,
             cid: '42',
              no: 0,
            week: week.toLowerCase() },
      type: 'POST',

      success: function(data){
        res = jQuery(data).find("slotting-result").text();
        if (res.indexOf('Error!') == -1) {
          jQuery("#week-s-"+sid).show();
          jQuery("#week-f-"+sid).hide();
        }
        else {
          jQuery("#week-s-"+sid).hide();
          jQuery("#week-f-"+sid).show();
        }
      },

      error: function(){
        jQuery("#week-s-"+sid).hide();
        jQuery("#week-f-"+sid).show();
      }
    });
  });
}