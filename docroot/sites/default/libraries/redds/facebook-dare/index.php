<!doctype html>
<!--[if IEMobile 7 ]>    <html class="no-js iem7" > <![endif]-->
<!--[if (gt IEMobile 7)|!(IEMobile)]><!--> <html class="no-js" > <!--<![endif]-->
<head>
  <meta charset="utf-8">
  <title>Facebook Dare</title>
  <meta name="description" content=""/>
  <meta name="keywords" content=""/>
  <meta name="HandheldFriendly" content="True"/>
  <meta name="MobileOptimized" content="320"/>
  <meta name="format-detection" content="telephone=yes"/>
  
  <meta name="viewport" content="width=device-width,initial-scale=1.0,maximum-scale=1.0,maximum-scale=1.0,user-scalable=no">  
  <link rel="stylesheet" type="text/css" href="../js/jquery/jquery.mobile.theme-1.1.0.min.css" />
  <link rel="stylesheet" type="text/css" href="../css/mobile-style.css">
  <link rel="stylesheet" type="text/css" href="../css/style.css"> 
  <script src="//code.jquery.com/jquery-1.7.2.min.js"></script>
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
<script src="../js/global.js" type="text/javascript"></script>
<style>
.ui-header, .ui-footer{display:none !important}
</style>
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
</head>
<body data-role="body" >
	<div style="display:block;width:100%;max-width:640px !important;margin:0px auto;">
	<div data-role="page" id="facebook-dare48798">
		
				<div data-role="header">

				<a href="#" class="ui-btn-left" data-direction="reverse" data-icon="arrow-l" onClick="history.back();">Back</a>
				<h1>Facebook Dare</h1>
				<a href="/" data-icon="home" data-iconpos="notext" data-direction="reverse" class="ui-btn-right jqm-home">Home</a>
				</div>
			
		<ul class="column ui-sortable ui-droppable" style="visibility: visible;"><li rel="logo" class="widget widget-type-logo box-logo " id="widget1" ><div class="widget-content"><div class="logo"><a href="/"><img src="../images/Redds_01.jpg" alt=""/></a></div></div></li>
<li rel="code" class="widget widget-type-code box-code " id="widget4" ><div class="widget-content">
<div id="BCLcontainingBlock">
   <div class="BCLvideoWrapper">
<div style="display:none;width:100%; height:270px;"></div>
<!--
By use of this code snippet, I agree to the Brightcove Publisher T and C 
found at https://accounts.brightcove.com/en/terms-and-conditions/. 
-->

<script language="JavaScript" type="text/javascript" src="http://admin.brightcove.com/js/BrightcoveExperiences.js"></script>

<object id="myExperience2390717878001" class="BrightcoveExperience">
  <param name="bgcolor" value="#FFFFFF" />
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
  <param name="@videoPlayer" value="2390717878001" />
</object>

<!-- 
This script tag will cause the Brightcove Players defined above it to be created as soon
as the line is read by the browser. If you wish to have the player instantiated only after
the rest of the HTML is processed and the page load is complete, remove the line.
-->
<script type="text/javascript">brightcove.createExperiences();</script>

<!-- End of Brightcove Player -->
</div>
</div></li>
<li rel="image" class="widget widget-type-image box-image " id="widget2" ><div class="widget-content"><div class="image"><img src="../images/Redds_MobileSite_v2_03_3.jpg" alt=""/></div></div></li>
<li rel="text" class="widget widget-type-text box-text " id="widget3" ><div class="widget-content"><div class="text"><div style="text-align:center;font-size:xx-small;color:#ffffff"><br>© 2013 Alpha Media Publishing, Inc.  <br>Use of this site constitutes your acceptance of our User Agreement and Privacy Policy. PLEASE PERFORM YOUR DARES RESPONSIBILY - YOU ASSUME ALL RISK OF INJURING YOURSELF OR OTHERS  </div>  </div></div></li>
</ul></div></div>
	<script>    
      var BCL = {};
      BCL.currentPlayerWidth = 1;
      var $BCLbodyContent = $('.widget-content');
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
        //BCL.log("curent width " + BCL.currentPlayerWidth);
        BCL.experienceModule = BCL.player.getModule(brightcove.api.modules.APIModules.EXPERIENCE);
        BCL.resizePlayer(BCL.currentPlayerWidth);
        //BCL.log("Window Resized");
       // console.log(BCL.experienceModule);
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
