<html>
<head>
  <title>Brightcove Player</title>
</head>
<body>
<?php if (isset($_GET['id'])): ?>
<!-- Start of Brightcove Player --><div style="display:none"></div>
<!--By use of this code snippet, I agree to the Brightcove Publisher T and C found at https://accounts.brightcove.com/en/terms-and-conditions/. -->
<script language="JavaScript" type="text/javascript" src="http://admin.brightcove.com/js/BrightcoveExperiences.js"></script>
<object id="myExperience1812878228001" class="BrightcoveExperience">
  <param name="bgcolor" value="#FFFFFF" />
  <param name="width" value="480" />
  <param name="height" value="270" />
  <param name="playerID" value="1783580181001" />
  <param name="playerKey" value="AQ~~,AAABnwxt8sE~,TdyFq09iMr7kioKT_wX2C8w8xLyk5_f2" />
  <param name="isVid" value="true" />
  <param name="isUI" value="true" />
  <param name="dynamicStreaming" value="true" />
  <param name="@videoPlayer" value="<?php echo $_GET['id']; ?>" />
</object>
<!-- This script tag will cause the Brightcove Players defined above it to be created as soonas the line is read by the browser. If you wish to have the player instantiated only afterthe rest of the HTML is processed and the page load is complete, remove the line.-->
<script type="text/javascript">brightcove.createExperiences();</script><!-- End of Brightcove Player -->
<?php endif; ?>
</body>
</html>
