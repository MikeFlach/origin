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

  week_display(slot, sid);
}

function call_cbox(img) {
  jQuery().colorbox({html:'<img class="sm-cbox-pic" src="'+img.src+'"/>'});
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
      url: '/do/hottie-week-slotting',
      data: {nid: '36876',
             sid: sid,
             cid: '78',
              no: 0,
            week: week.toLowerCase() },
      type: 'GET',

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