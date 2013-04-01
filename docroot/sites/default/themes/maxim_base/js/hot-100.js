function doWriteInMsg() {
  var error = jQuery('#messages .messages').html();
   
  /* The form was styled with the expectaion of a capptcha div being present.  When logged in, no captcha is rendered to the page. This
     code makes the write-in sction for hot 100 appear normal for logged in users */
  if (!jQuery(".form-item-mollom-captcha")[0]){
    var mollumHolder = '<div class="form-item form-type-textfield form-item-mollom-captcha">';
    mollumHolder = mollumHolder + '<span class="field-prefix"><span class="mollom-captcha-content mollom-image-captcha">CAPTCHA:LOG OUT TO VIEW.</span><a href="#" class="mollom-switch-captcha mollom-audio-captcha"></a></span><input autocomplete="off" type="text" id="edit-mollom-captcha" name="mollom[captcha]" value="" size="10" maxlength="128" class="form-text required"><div style="display: none;"><div class="form-item form-type-textfield form-item-mollom-homepage"><input title="Homepage" autocomplete="off" type="text" id="edit-mollom-homepage" name="mollom[homepage]" value="" size="60" maxlength="128" class="form-text"></div></div>';
    jQuery('#webform-component-hot100-write-in').after(mollumHolder);
  }

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
