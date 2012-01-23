// Example call to wallpaper skin
var skin_large = '/sites/default/files/skin_Soul_final.jpg';
var skin_tablet = '/sites/default/files/ipad_skin.jpg';
var skin_mobile = '/sites/default/files/mobile_skin_final.jpg';
var skin_bgcolor = 'black';
var skin_jump = '/tough';  

document.write('<scr'+'ipt type="text/javascript" src="http://www.maxim.com/sites/default/libraries/wallpaper/wallpaper.js"></sc'+'ript>');

/* old code */
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
