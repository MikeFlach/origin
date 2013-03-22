<html>
<head>
  <title>Maxim Video Player</title>
</head>
<body style="margin:0;background-color:#000;">
<?php if (isset($_GET['id'])): ?>
<!-- Start of Brightcove Player --><div style="display:none"></div>
<!--By use of this code snippet, I agree to the Brightcove Publisher T and C found at https://accounts.brightcove.com/en/terms-and-conditions/. -->
<script language="JavaScript" type="text/javascript" src="https://sadmin.brightcove.com/js/BrightcoveExperiences.js"></script>
<object id="myExperience" class="BrightcoveExperience">
  <param name="bgcolor" value="#FFFFFF" />
  <param name="width" value="100%" />
  <param name="height" value="100%" />
  <param name="secureConnections" value="true" />
  <param name="playerID" value="2207494593001" />
  <param name="playerKey" value="AQ~~,AAABnwxt8sE~,TdyFq09iMr5QZlchMYh_m_W4MlnuIdgg" />
  <param name="isVid" value="true" />
  <param name="isUI" value="true" />
  <param name="dynamicStreaming" value="true" />
  <param name="@videoPlayer" value="<?php echo $_GET['id']; ?>" />
</object>
<!-- This script tag will cause the Brightcove Players defined above it to be created as soonas the line is read by the browser. If you wish to have the player instantiated only afterthe rest of the HTML is processed and the page load is complete, remove the line.-->
<script type="text/javascript">brightcove.createExperiences();</script><!-- End of Brightcove Player -->
<?php /*
<script>
  if (window.self === window.top) {
    location.href='http://www.maxim.com/maximtv/player/' + <?php echo $_GET['id']; ?>;
  }
</script>
 */ ?>
<?php endif; ?>
<?php if (strlen($_SERVER['HTTP_REFERER'])) { ?>
  <!-- ref:'<?php echo $_SERVER['HTTP_REFERER']; ?>' -->
<?php } ?>
</body>
</html>
