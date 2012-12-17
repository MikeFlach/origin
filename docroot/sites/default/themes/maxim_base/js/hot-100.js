function doWriteInMsg() {
  var error = jQuery('#messages .messages').html();
  
  //no data entered
  if (error && error.indexOf('field is required' !== -1)) { 
    jQuery('#write-in-status').html("Oops! You forgot to enter a name.").addClass('write-in-error');
    jQuery('#write-in-status').fadeOut(8000);
  }
  else if (error && error.indexOf('You may not submit another' !== -1)) {
    // limit reached
    if (!jQuery('#webform-component-hot-100-write-in').length) { 
      jQuery('.webform-client-form').hide();
      jQuery('#hot100-2013-header-text').after("<div class='no-writein'>Thank you! You've reached your write-in limit for the day. You can still vote for any of the girls below.</div>");
    }
  }
  //vote success
  else {
    if (document.referrer && document.referrer.indexOf('/hot100/2013/vote') !== -1) {    
      jQuery('#write-in-status').html("Your vote has been counted!").addClass('write-in-success');
      jQuery('#write-in-status').show();
      jQuery('#write-in-status').fadeOut(8000);
    }
  }
}

