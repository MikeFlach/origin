var compareWidth; //previous width used for comparison
var detector; //the element used to compare changes
var backcolor = 'black';
var skin = '/sites/default/files/skin_Soul_final.jpg';
var tabskin = '/sites/default/files/ipad_skin.jpg';
var mobskin = '/sites/default/files/mobile_skin_final.jpg';
var dartJump = '/tough';  

jQuery(document).ready(function(){  
    //set the initial values
    detector = jQuery('body');
    
    detector.append('<img src="http://view.atdmt.com/MDS/view/368170309/direct/01/" width="1" height="1" alt="_" />');
    detector.append('<a href="' + dartJump + '" id="bglink" target="_blank"></a>');   
    
    compareWidth = detector.width();

    jQuery(window).resize(function(){
        //compare everytime the window resize event fires
        if(detector.width()!=compareWidth){

            //a change has occurred so update the comparison variable
            compareWidth = detector.width();
            setBackground(detector.width());
        }
    });

    // set global vars backcolor, skin, tabskin
    function setBackground(width) {
      if (width > 980) {
        detector.css('background', 'url("' + skin + '") no-repeat top center fixed').css('background-color', backcolor);
        // alert(jQuery('a#bglink').attr('width');
      }
      else if ( width <= 980 && width >= 680 ) {
        detector.css('background', 'url(\'' + tabskin + '\') no-repeat top center fixed').css('background-color', backcolor);
      }
      else if (width <= 680 && width >= 480) {
        detector.css('background', 'url(\'' + mobskin + '\') no-repeat top center fixed').css('background-color', backcolor);
      }
      else {
        detector.css('background', 'none').css('background-color', backcolor);
      }
    }
    setBackground(detector.width());
});

// document.write('<img src="http://view.atdmt.com/MDS/view/368170309/direct/01/" width="1" height="1" alt="_" />');
// document.write('<a href="' + dartJump + '1284067124958?" id="bglink" target="_blank"></a>');   

/* Existing site code.
//<![CDATA[
var isDisplayableSkin = true;
var bgURL = 'http://ad.doubleclick.net/ad/maxim.dart/index;marketing=;sect1=index;sz=1000x1000;ord=1284067124958?';
dartJump = "http://ad.doubleclick.net/jump/maxim.dart/index;marketing=;sect1=index;sz=1000x1000;ord=";
 if (portalFriendlyURI != undefined  &&  portalFriendlyURI != null) {
   isDisplayableSkin = false;
   dartJump = dartJump.replace(/index;/gi, portalFriendlyURI + ";");
   bgURL = bgURL.replace(/index;/gi, portalFriendlyURI + ";");
 }
if (isDisplayableSkin) {
 $("html").css("background","url('" + bgURL + "') no-repeat fixed top");
 //$("html").css("color","#000000");
 document.write('<img src="http://view.atdmt.com/MDS/view/368170309/direct/01/" width="1" height="1" alt="_" />');
 document.write('<a href="' + dartJump + '1284067124958?" id="bglink" target="_blank"></a>');
}
//]]>

<img src="http://view.atdmt.com/MDS/view/368170309/direct/01/" width="1" height="1" alt="_">
<a href="http://ad.doubleclick.net/jump/maxim.dart/index;marketing=;sect1=index;sz=1000x1000;ord=1284067124958?" id="bglink" target="_blank"></a>
*/