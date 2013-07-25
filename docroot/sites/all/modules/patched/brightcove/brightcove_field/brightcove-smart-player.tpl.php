<!-- Start of Brightcove  Smart Player -->
<?php echo $responsiveStart; ?>
    <div style="display:none">

    </div>
    <!--
    player used: <?php print $playerName; ?>
    -->
    <object id="myExperience" class="BrightcoveExperience">
      <param name="bgcolor" value="#FFFFFF" />
      <param name="width" value="<?php print $width; ?>" />
      <param name="height" value="<?php print $height; ?>" />
      <param name="playerID" value="<?php print $playerID; ?>" />
      <param name="playerKey" value="<?php print $playerKey; ?>" />
      <param name="isVid" value="true" />
      <param name="dynamicStreaming" value="true" />
      <param name="includeAPI" value="true" />
      <param name="templateLoadHandler" value="bcSmartPlayerLoaded" />
      <param name="templateReadyHandler" value="bcSmartPlayerReady" />
      <param name="@videoPlayer" value="<?php print $video_id; ?>" />
      <param name="isUI" value="true" />
      <?php echo $secureConnections; ?>
    </object>
<?php echo $responsiveEnd; ?>
<!-- End of Brightcove Smart Player -->
