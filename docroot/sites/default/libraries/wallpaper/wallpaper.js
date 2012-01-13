var compareWidth; //previous width used for comparison
var detector; //the element used to compare changes
var backcolor = 'black';
var skin = '/sites/default/files/skin_Soul_final.jpg';
var tabskin = '/sites/default/files/ipad_skin.jpg';

jQuery(document).ready(function(){
    //set the initial values
    detector = jQuery('body');
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
      if (width > 980) {detector.css('background', 'url(\'' + skin + '\') no-repeat top center fixed').css('background-color', backcolor);}
      else if ( width <= 980 && width >= 680 ) {
        detector.css('background', 'url(\'' + tabskin + '\') no-repeat top center fixed').css('background-color', backcolor);}
      else { detector.css('background', 'none').css('background-color', backcolor);}
    }
    setBackground(detector.width());
});