<?php

/**
 * @file brightcove-field-player.tpl.php
 * Default template for embeding brightcove players.
 *
 * Available variables:
 * - $id
 * - $width
 * - $height
 * - $classes_array
 * - $bgcolor
 * - $flashvars
 *
 * @see template_preprocess_brightcove_field_embed().
 */

/*
// Smart Player API does allow you to change volume because not supported by IOS, HTML5
<div style="display:none"></div>
<object id="<?php print $id;?>" class="BrightcoveExperience <?php print join($classes_array, ',');?>">
  <param name="bgcolor" value="#FFFFFF" />
  <param name="width" value="<?php print $width; ?>" />
  <param name="height" value="<?php print $height; ?>" />
  <param name="playerID" value="<?php print $playerID; ?>" />
  <param name="playerKey" value="<?php print $playerKey; ?>" />
  <param name="isVid" value="true" />
  <param name="dynamicStreaming" value="true" />
  <param name="includeAPI" value="true" />
  <param name="templateLoadHandler" value="bcSmartPlayerLoaded" />
  <param name="@videoPlayer" value="<?php print $brightcove_id; ?>" />
  <param name="isUI" value="true" />
  <param name="autoStart" value="<?php print ($video_autoplay) ? 'true' : 'false';?>" />
  <param name="volume" value="<?php print $video_volume;?>" />
</object>
<script type="text/javascript">brightcove.createExperiences();</script>
 */
?>
<div class="bcvideo">
  <object id="<?php print $id;?>" class="BrightcoveExperience <?php print join($classes_array, ',');?>">
    <param name="bgcolor" value="#FFFFFF" />
    <param name="wmode" value="transparent" />
    <param name="width" value="<?php print $width; ?>" />
    <param name="height" value="<?php print $height; ?>" />
    <param name="playerID" value="<?php print $playerID; ?>" />
    <param name="playerKey" value="<?php print $playerKey; ?>" />
    <param name="@videoPlayer" value="<?php print $brightcove_id; ?>" />
    <param name="dynamicStreaming" value="true" />
    <param name="isVid" value="true" />
    <param name="isUI" value="true" />
    <param name="templateLoadHandler" value="bcPlayerLoaded" />
    <param name="autoStart" value="<?php print ($video_autoplay) ? 'true' : 'false';?>" />
    <?php if (isset($_REQUEST['src']) && $_REQUEST['src'] === 'bb') { ?>
      <param name="forceHTML" value="true" />
    <?php } ?>
    <param name="linkBaseURL" value="<?php print 'http://www.maxim.com' . url($_GET['q']) ?>" />
    <param name="volume" value="<?php print $video_volume;?>" />
  </object>
</div>
<?php // For HTML5 freewheel ads ?>
<script src="http://adm.fwmrm.net/p/maxim_brightcove_html5_live/BrightcovePlugin.js" type="text/javascript"></script>
