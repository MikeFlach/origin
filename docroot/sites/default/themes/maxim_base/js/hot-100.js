function doWriteInMsg() {
  var posted = getURLParameter('cv');
  var error = jQuery('#messages .messages').html();
  
  //no data entered
  if (error && error.indexOf('field is required' !== -1)) { 
    jQuery('#edit-submit').after("<div class='hth-error'>Oops! You forgot to enter a name.</div>");
    jQuery('.hth-error').fadeOut(8000);
  }
  else if (posted) {
    // vote counted and limit reached
    if (!jQuery('#webform-component-hot-100-write-in').length) { 
      jQuery('#page-title').after("<div class='no-writein'>Your vote has been counted! You've reached your write-in limit for the day. Please come back again tomrrow!</div>");
    }
    //vote success and no limit reached
    else {
     jQuery('#edit-submit').after("<div class='v-success'>Your vote has been counted!</div>");
     jQuery('.v-success').fadeOut(8000);
    }
  }
  //user came back and limit reached
  else if (!jQuery('#webform-component-hot-100-write-in').length) { 
    jQuery('#page-title').after("<div class='no-writein'>You've reached your write-in limit for the day. Please come back again tomrrow!</div>");
  }
}

function getURLParameter(name) {
    return decodeURIComponent((new RegExp('[?|&]' + name + '=' + '([^&;]+?)(&|#|;|$)').exec(location.search)||[,""])[1].replace(/\+/g, '%20'))||null;
}
