<?php
  if($_COOKIE['over_age'] != 'true' ){
    header('Location: ../index.php');
  }
?>
<!doctype html>
<!--[if IEMobile 7 ]>    <html class="no-js iem7" > <![endif]-->
<!--[if (gt IEMobile 7)|!(IEMobile)]><!--> <html class="no-js" > <!--<![endif]-->
<head>
  <meta charset="utf-8">
  <title>Bloody_Ghost</title>
  <meta name="description" content=""/>
  <meta name="keywords" content=""/>
  <meta name="HandheldFriendly" content="True"/>
  <meta name="MobileOptimized" content="320"/>
  <meta name="format-detection" content="telephone=yes"/>

  <meta name="viewport" content="width=device-width,initial-scale=1.0,maximum-scale=1.0,maximum-scale=1.0,user-scalable=no">
  <link rel="stylesheet" type="text/css" href="../js/jquery/jquery.mobile.theme-1.1.0.min.css" />
  <link rel="stylesheet" type="text/css" href="../css/mobile-style.css">
  <link rel="stylesheet" type="text/css" href="../css/style.css">
  <script>
var geocoder;
var map;
</script>
<script type="text/javascript" src="//ajax.googleapis.com/ajax/libs/jquery/1.8.0/jquery.min.js"></script>
<script>
$(document).bind('mobileinit',function(){
	$.mobile.page.prototype.options.keepNative = "select, input, textarea, button";


$(document).on("submit", function(){
  $(this).find(":submit").attr("disabled","disabled");
});

});
</script>
<script type="text/javascript" src="../js/jquery/jquery.mobile-1.1.0.min.js"></script>
<script src="../js/mobile-js.js" type="text/javascript"></script>

</head>
</head>
<body data-role="body" >
	<div style="display:block;width:100%;max-width:640px !important;margin:0px auto;">
	<div data-role="page" id="bloody_ghost47440">

				<div data-role="header">

				<a href="#" class="ui-btn-left" data-direction="reverse" data-icon="arrow-l" onclick="history.back();">Back</a>
				<h1>Bloody_Ghost</h1>
				<a href="../" data-icon="home" data-iconpos="notext" data-direction="reverse" class="ui-btn-right jqm-home">Home</a>
				</div>

		<ul class="column ui-sortable ui-droppable" style="visibility: visible;"><li rel="logo" class="widget widget-type-logo box-logo " id="widget1" ><div class="widget-content"><div class="logo"><a href="../"><img src="../images/JACOBS_BLOODY_02_1.png" alt=""/></a></div></div></li>
<li rel="code" class="widget widget-type-code box-code " id="widget2" ><div class="widget-content">

<style>
#BCLcontainingBlock {
  width: 100%;
  margin-left: 10px;
  margin-bottom: 10px;
  float: right;
}
.BCLvideoWrapper {
  position: relative;
  padding-top: 1px;
  padding-bottom: 56.25%;
  height: 0;
}
* html .BCLvideoWrapper {
  margin-bottom: 45px;
  margin-top: 0;
  width: 100%;
  height: 100%;
}
.BCLvideoWrapper div,
.BCLvideoWrapper embed,
.BCLvideoWrapper object,
.BrightcoveExperience {
  position: absolute;
  width: 100%;
  height: 100%;
  left: 0;
  top: 0;
}
</style>

<div id="BCLcontainingBlock">
   <div class="BCLvideoWrapper">
     <!-- Start of Brightcove Player -->
     <div style="display:none"></div>
<script language="JavaScript" type="text/javascript" src="http://admin.brightcove.com/js/BrightcoveExperiences.js"></script>

<object id="myExperience2318790764001" class="BrightcoveExperience">
  <param name="bgcolor" value="#000000" />
  <param name="width" value="100%" />
  <param name="height" value="100%" />
  <param name="playerID" value="2317585072001" />
  <param name="playerKey" value="AQ~~,AAABnwxt8sE~,TdyFq09iMr67wpDZRJpl-uwNEXlRwZ9U" />
  <param name="isVid" value="true" />
  <param name="isUI" value="true" />
  <param name="dynamicStreaming" value="true" />
  <param name="includeAPI" value="true" />
  <param name="templateLoadHandler" value="onTemplateLoaded" />
  <param name="templateReadyHandler" value="onTemplateReady" />
  <param name="@videoPlayer" value="2318790764001" />
</object>
  <script type="text/javascript">brightcove.createExperiences();</script>
</div>
</div>
</div></li>
<li rel="image" class="widget widget-type-image box-image " id="widget3" ><div class="widget-content"><div class="image"><img src="../images/JACOBS_BLOODY_05.png" alt=""/></div></div></li>
<li rel="icon_navigation" class="widget widget-type-icon_navigation box-icon_navigation " id="widget4" ><div class="widget-content"><div class="image"><img class="icon_nav_img imgmap201341913543" src="../images/JACOBS_BLOODY_06.png" usemap="#imgmap201341913543"  alt=""/><map id="imgmap201341913543" name="imgmap201341913543"><area shape="rect" alt="" title="" coords="71,1,182,51" href="https://www.facebook.com" target="" /><area shape="rect" alt="" title="" coords="71,57,182,107" href="https://www.twitter.com" target="" /><area shape="rect" alt="" title="" coords="188,2,318,108" href="http://www.jimbeam.com/jacobs-ghost" target="" /></map><script>$(document).ready(function() {
		$(".imgmap201341913543").mapster({clickNavigate:true, fillOpacity: 0,scaleMap:true});

		$(window).resize(function() {

			var screenImage = $(".imgmap201341913543");
			var theImage = new Image();
			theImage.src = screenImage.attr("src");
			var imageWidth = theImage.width;
			var winWidth = $(window).width();

			if( winWidth > 640)
			{
				if(imageWidth > 640)
				{
					$(".imgmap201341913543").mapster("resize",640);
				}
				else
				{
					$(".imgmap201341913543").mapster("resize",parseInt(imageWidth));
				}
			}
			else
			{
				$(".imgmap201341913543").mapster("resize",parseInt(winWidth));
			}
		});

		$(".imgmap201341913543").load(function() {

			var screenImage = $(".imgmap201341913543");
			var theImage = new Image();
			theImage.src = screenImage.attr("src");
			var imageWidth = theImage.width;
			var winWidth = $(window).width();
			if( winWidth > 640)
			{
				if(imageWidth > 640)
				{
					$(".imgmap201341913543").mapster("resize",640);
				}
				else
				{
					$(".imgmap201341913543").mapster("resize",parseInt(imageWidth));
				}
			}
			else
			{
				$(".imgmap201341913543").mapster("resize",parseInt(winWidth));
			}
		});
		});</script></div></div></li>
<li rel="icon_navigation" class="widget widget-type-icon_navigation box-icon_navigation " id="widget5" ><div class="widget-content"><div class="image"><img class="icon_nav_img imgmap201342316353" src="../images/JACOBS_STORM_07_12.png" usemap="#imgmap201342316353"  alt=""/><map id="imgmap201342316353" name="imgmap201342316353"><area shape="rect" alt="" title="" coords="60,11,226,84" href="../bloody_ghost/index.php" target="" /><area shape="rect" alt="" title="" coords="239,12,402,85" href="../ghost_cosmo/index.php" target="" /><area shape="rect" alt="" title="" coords="413,12,578,84" href="../jacobs_storm/index.php" target="" /></map><script>$(document).ready(function() {
		$(".imgmap201342316353").mapster({clickNavigate:true, fillOpacity: 0,scaleMap:true});

		$(window).resize(function() {

			var screenImage = $(".imgmap201342316353");
			var theImage = new Image();
			theImage.src = screenImage.attr("src");
			var imageWidth = theImage.width;
			var winWidth = $(window).width();

			if( winWidth > 640)
			{
				if(imageWidth > 640)
				{
					$(".imgmap201342316353").mapster("resize",640);
				}
				else
				{
					$(".imgmap201342316353").mapster("resize",parseInt(imageWidth));
				}
			}
			else
			{
				$(".imgmap201342316353").mapster("resize",parseInt(winWidth));
			}
		});

		$(".imgmap201342316353").load(function() {

			var screenImage = $(".imgmap201342316353");
			var theImage = new Image();
			theImage.src = screenImage.attr("src");
			var imageWidth = theImage.width;
			var winWidth = $(window).width();
			if( winWidth > 640)
			{
				if(imageWidth > 640)
				{
					$(".imgmap201342316353").mapster("resize",640);
				}
				else
				{
					$(".imgmap201342316353").mapster("resize",parseInt(imageWidth));
				}
			}
			else
			{
				$(".imgmap201342316353").mapster("resize",parseInt(winWidth));
			}
		});
		});</script></div></div></li>
<li rel="text" class="widget widget-type-text box-text " id="widget6" ><div class="widget-content"><div class="text"><style>
a {text-decoration:none;}
</style>
<div style="text-align:center"></div><div style="text-align:center;color:#808080;font-size:x-small"><div style="text-align:center"><div><a style="font-weight:bold;color:#808080;font-size:xx-small" href="http://www.jimbeam.com/contact-us">Contact Us</a><span style="font-weight:bold;font-size:xx-small;color:#999999"> &nbsp; |  &nbsp; </span><a style="font-weight:bold;color:#808080;font-size:xx-small" href="http://www.jimbeam.com/privacy">Privacy Policy</a><span style="font-weight:bold;font-size:xx-small;color:#999999"> &nbsp; | &nbsp; </span><a style="font-weight:bold;color:#808080;font-size:xx-small" href="http://www.jimbeam.com/terms">Terms</a><br></div></div><br><span style="font-size:xx-small">©  2013 Beam Global Spirits and Wine, Inc. Deerfield, IL  <br>Jim Beam Brands Co. | 510 Lake Cook Rd. | Deerfield, IL  60015-4964. <br>All trademarks are property of their   respective owners.</span><br><br></div>  </div></div></li>
</ul></div></div>
  
  <script>    
      var BCL = {};
      BCL.currentPlayerWidth = 1;
      var $BCLbodyContent = $('#BCLbodyContent');
      var $BCLvideoWrapper = $('.BCLvideoWrapper');
      var $BCLcontainingBlock = $('#BCLcontainingBlock');
      var $html5 = $('#HTML5');
      var $flash = $('#FLASH');
      var onTemplateLoaded = function (experienceID) {
        //BCL.log("template loaded")
        BCL.player = brightcove.api.getExperience(experienceID);
      }
      var onTemplateReady = function(evtObj) {
        //BCL.log("template ready")
        BCL.experienceModule = BCL.player.getModule(brightcove.api.modules.APIModules.EXPERIENCE);
        //console.log(BCL.experienceModule);
      }
      // dynamic resizer
      $(window).on('resize',function() {
        //BCL.log("window resize");
        BCL.resizePlayer(BCL.currentPlayerWidth);
      });
     
      // resizing function
      BCL.resizePlayer = function(newWidth) {
        //BCL.log(newWidth);
        $BCLcontainingBlock.width($BCLbodyContent.width() * newWidth);
        BCL.experienceModule.setSize($BCLcontainingBlock.width(),$BCLcontainingBlock.height());
        BCL.currentPlayerWidth = newWidth;
      }
      // debugging tool - wraps console.log to avoid errors in IE 7 & 8
      BCL.log = function(message) {
        if (window["console"] && console["log"]) {
          var d = new Date();
          console.log(d + ": ");
          console.log(message);
        }
      }
</script>

	</body>
	</html>
