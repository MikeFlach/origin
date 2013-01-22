var maximVideoPlayers = {};

/**
 * Video Player Object
 */
function MaximVideoPlayer(experienceID) {
  this.experienceID = experienceID;
  var volume = getParameterByName(jQuery("#"+experienceID).attr('data'), 'volume');
  var player = bcPlayer.getPlayer(experienceID);
  var vp = player.getModule(APIModules.VIDEO_PLAYER);
  var vpExp = player.getModule(APIModules.EXPERIENCE);
  var vpContent = player.getModule(APIModules.CONTENT);
  vpExp.addEventListener(BCExperienceEvent.TEMPLATE_READY, function(evt) { maximVideoPlayers[experienceID].onTemplateReady(evt); });

  this.onTemplateReady = function (evt) {
    console.log('template ready: ' + experienceID);
    vp.addEventListener(BCMediaEvent.BEGIN, function(evt) { maximVideoPlayers[experienceID].onMediaEventFired(evt); });
    vp.addEventListener(BCMediaEvent.COMPLETE, function(evt) { maximVideoPlayers[experienceID].onMediaEventFired(evt); });
    vp.addEventListener(BCMediaEvent.ERROR, function(evt) { maximVideoPlayers[experienceID].onMediaEventFired(evt); });
    vp.addEventListener(BCMediaEvent.PLAY, function(evt) { maximVideoPlayers[experienceID].onMediaEventFired(evt); });
    vp.addEventListener(BCMediaEvent.STOP, function(evt) { maximVideoPlayers[experienceID].onMediaEventFired(evt); });
    if (volume.length>0) {
      this.changeVolume(volume);
    }
  };

  this.changeVolume = function(volume) {
    vp.setVolume(volume/100);
    console.log('volume : ' + vp.getVolume());
  }

  this.pause = function() {
    vp.pause();
  };

  this.play = function() {
    vp.play();
  };

  this.onMediaEventFired = function (evt) {
    var title = evt.media.displayName;
    console.log(title + ": MEDIA EVENT: " + evt.type + " fired at position: " + evt.position);
  };

}

// Brightcove Template Loaded
function bcPlayerLoaded(experienceID) {
  console.log('player loaded: ' + experienceID);
  maximVideoPlayers[experienceID] = new MaximVideoPlayer(experienceID);
}

/**
* Get parameter from query string
* @param  string url
* @param  string name   parameter name
* @return string        parameter value
*/
function getParameterByName (url, name) {
  name = name.replace(/[\[]/, "\\\[").replace(/[\]]/, "\\\]");
  var regexS = "[\\?&]" + name + "=([^&#]*)";
  var regex = new RegExp(regexS);
  var results = regex.exec(url);
  if(results == null)
    return "";
  else
    return decodeURIComponent(results[1].replace(/\+/g, " "));
}
