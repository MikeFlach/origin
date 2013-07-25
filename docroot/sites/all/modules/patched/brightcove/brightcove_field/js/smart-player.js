// create var for reference to the player
var player;

// create vars for references to the modules in the player
var modVP,modExp,modCon;

// The function below is a handler for the template load event
// It receives the ID of the player (the id of the object in the publishing code)
// We can use that ID to get a reference to the player, and then the modules
// The name of this method can vary but should match the value you specified
// in the player publishing code for <E2><80><9C>templateLoadHandler<E2><80><9D>.

bcSmartPlayerLoaded = function(experienceID) {
  // Get a reference to the player itself
  player = brightcove.api.getExperience(experienceID);
  // Get a reference to individual modules in the player
  modVP = player.getModule(brightcove.api.modules.APIModules.VIDEO_PLAYER);
  modExp = bcPlayer.getModule(brightcove.api.modules.APIModules.EXPERIENCE);
  modCon = bcPlayer.getModule(brightcove.api.modules.APIModules.CONTENT);
}

bcSmartPlayerReady = function(evt) {
  // resizing function - newWidth is percentage of content width as a decimal value
  BCL.resizePlayer = function(newWidth) {
    var $BCLcontainingBlock = $('#BCLcontainingBlock');
    $BCLcontainingBlock.width($('#BCLbodyContent').width() * newWidth);
    BCL.experienceModule.setSize($BCLcontainingBlock.width(),$BCLcontainingBlock.height());
    BCL.currentPlayerWidth = newWidth;
  }
}

