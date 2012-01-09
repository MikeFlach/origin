// Jumbotron - need to convert to jQuery plugin

var currentPanel = 0;
var jumboDelay = 6000;
var animateTime = 1000;
var overlayFadeOut = 400;
var overlayFadeIn = 200;
var overlayDelay = 1500;
var jumboTimer, jumboOverlayTimer ,panelWidth, panelLeftValue, jumboNavWidth, jumboNavLeftValue;
var $jumboPanels, $jumboNav;
var animating = 0;

function jumbotronInit(){
  $jumboPanels = jQuery('.jumbotron .panels ul');
  $jumboNav = jQuery('.jumboNav ul');
  //grab the panel width and calculate left value
  panelWidth = $jumboPanels.children().outerWidth();
  panelLeftValue = panelWidth * (-1);
  //move the last item before first item, just in case user click prev button
  $jumboPanels.children().first().before($jumboPanels.children().last());
  //set the default item to the correct position
  $jumboPanels.css({'left' : panelLeftValue});

  //grab the nav width and calculate left value
  jumboNavWidth = $jumboNav.children().outerWidth();
  jumboNavLeftValue = jumboNavWidth * (-1);

  //clone last item and put it as  first item, just in case user click prev button
  $jumboNav.children().first().before($jumboNav.children().clone().addClass('clone').last());

  //set the default item to the correct position
  $jumboNav.css({'left' : jumboNavLeftValue});

  /*$jumboNav.mouseenter(function(){
    jQuery(".jumbotron .textOverlay").slideDown();
  }).mouseleave(function(){
    jQuery(".jumbotron .textOverlay").slideUp();
  });*/
  jumboOverlayTimer=setTimeout(function(){ jQuery(".jumbotron .textOverlay").slideDown(); }, overlayDelay);
  setJumboTimer();
}

function buildJumbotron(){
	// Reset jumbotron
	jQuery(".jumboNav").html('');
	jQuery(".jumbotron .nextprev, .jumbotron .navtitle, .jumbotron .jumboNavNext, .jumbotron #navIndicator, .jumbotron .textOverlay").remove();
	currentPanel=0;
	clearInterval(jumboTimer);

	var strPanels="<ul>";
	for(var i=0; i<arJumbotron.length; i++){
		strPanels += '<li id="jpanel_'+i+'">';
		if(i==0){
			strPanels += '<a href="'+arJumbotron[i].link+'"><img src="'+arJumbotron[i].src+'" /></a>'
		} else {
			strPanels += "&nbsp;";
		}
		strPanels += '</li>';
	}
	strPanels += "</ul>";
	jQuery(".jumbotron .panels").html(strPanels);
  strTextOverlay='<div class="textOverlay"><div class="title title_0">'+arJumbotron[0].title+'</div><div class="subtitle">'+arJumbotron[0].subtitle+'</div></div>';
  strNext="<div class=\"jumboNavNext\"><a href=\"#\" onclick=\"jumboClick('+');return false;\"><div class=\"jumboNavNextImg\"></div></a></div>";
  jQuery('.jumbotron .panels').after(strTextOverlay + strNext);

	// Build Next/Previous buttons
	var strPrevNext="";
	strPrevNext+='<div class="navtitle" onclick="jumboClick(\'-\');">TOP<br/ ><span>'+arJumbotron.length+'</span></div>';
	//strPrevNext+='<div id="navIndicator" class="selector_arrow_0"></div>';
	strPrevNext+='<div class="nextprev leftNav"><a href="#" onclick="jumboClick(\'-\');return false;"><div class="prevButton"></div></a></div>';
	strPrevNext+='<div class="nextprev rightNav"><a href="#" onclick="jumboClick(\'+\');return false;"><div class="nextButton"></div></a></div>';
	jQuery('.jumbotron').append(strPrevNext);

	// Build Nav
	var strNav="<ul>";
  var numColors=5;
	for(var i=0; i<arJumbotron.length; i++){
		strNav += '<li id="jumboNav_'+i+'" class="jumboNav_'+i%numColors+'">';
		//strNav += '<div class="selector"></div>';
    //strNav += '<div class="details"><a href="#" onclick="jumboClick('+i+');return false;"> <img src="'+arJumbotron[i].thumb+'" class="reflect" /><div class="navNum">'+eval(i+1)+'</div><div class="title">'+arJumbotron[i].title+'</div></a></div></li>';
		strNav += '<div class="details"><a href="'+arJumbotron[i].link+'"> <img src="'+arJumbotron[i].thumb+'" class="reflect" /><div class="navNum">'+eval(i+1)+'</div><div class="title">'+arJumbotron[i].title+'</div></a></div></li>';
	}
	strNav += "</ul>";

	jQuery(".jumboNav").html(strNav);

	jumbotronInit();
}

function jumboClick(dir,fromTimer){
	if(!animating){
		var numPanels=arJumbotron.length;
		if(typeof fromTimer=='undefined') { fromTimer=0; }
		if(fromTimer==0){
			clearInterval(jumboTimer);
		}

		if(dir=="+"){
			var nextPanel=currentPanel+1;
		} else if (dir=='-') {
			var nextPanel=currentPanel-1;
		} else if (!isNaN(dir)){
			var nextPanel=dir;
		}

		if(nextPanel >= numPanels){ nextPanel = 0; }
		if(nextPanel < 0){ nextPanel=numPanels-1; }

		var $nextPanel=jQuery("#jpanel_"+nextPanel);

		currentPanel=nextPanel;

		switch (arJumbotron[nextPanel].panelType){
			case 'image':
				if($nextPanel.html().length < 10){
					$nextPanel.html('<a href="'+arJumbotron[nextPanel].link+'"><img src="'+arJumbotron[nextPanel].src+'" /></a>');
				}
				jumboAnimate(dir, currentPanel);
			break;
			case 'ajax':
				if($nextPanel.html().length < 10){
					$nextPanel.load(arJumbotron[nextPanel].src, function() {
						jumboAnimate(dir, currentPanel);
					});
				} else {
					jumboAnimate(dir, currentPanel);
				}
			break;
		}
    currentPanel=nextPanel;
	}
}

function jumboAnimate(dir, oldPanel){
	animating=1;
  clearTimeout(jumboOverlayTimer);
	switch (dir) {
		case '-':
			//get the right position
			var panelLeftIndent = parseInt($jumboPanels.css('left')) + panelWidth;

			//slide the item
			$jumboPanels.stop(true,true).animate({'left' : panelLeftIndent}, animateTime, function () {
				//move the last item and put it as first item
				$jumboPanels.children().first().before($jumboPanels.children().last());
				//set the default item to correct position
				$jumboPanels.css({'left' : panelLeftValue});
				animating=0;
			});

			//get the right position of nav
			var navLeftIndent = parseInt($jumboNav.css('left')) + jumboNavWidth;

			//slide the nav item
      jQuery(".jumbotron .textOverlay").hide();

			$jumboNav.stop(true,true).animate({'left' : navLeftIndent}, animateTime, function () {
        jQuery(".jumbotron .textOverlay").hide();
				//remove clone class from 1st el
				jQuery("li", $jumboNav).first().removeClass('clone');
				//clone 2nd to last item and put it as last item
				$jumboNav.children().first().before(jQuery("li", $jumboNav).eq(arJumbotron.length-1).clone().addClass('clone'));
				//remove last element
				jQuery("li", $jumboNav).last().remove();
				//set the default item to correct position
				$jumboNav.css({'left' : jumboNavLeftValue});

        //text overlay
        jQuery(".textOverlay .title").attr('class','').addClass('title title_'+currentPanel%5);
        jQuery(".textOverlay .title").html(arJumbotron[currentPanel]['title']);
        jQuery(".textOverlay .subtitle").html(arJumbotron[currentPanel]['subtitle']);
        jumboOverlayTimer=setTimeout(function(){ jQuery(".jumbotron .textOverlay").slideDown(); }, overlayDelay);
			});
		break;
    default:
     /* var movePos = 1;
      if(!isNaN(dir)){
        movePos= dir - oldPanel;
      }
      console.log('pos:' + movePos); 
      for(var pos=0; pos < movePos; pos++){*/
			  //get the right position
			  var panelLeftIndent = parseInt($jumboPanels.css('left')) - panelWidth;
			  //slide the item
			  $jumboPanels.animate({'left' : panelLeftIndent}, animateTime, function () {
				  //move the first item and put it as last item
				  $jumboPanels.children().last().after($jumboPanels.children().first());
				  //set the default item to correct position
				  $jumboPanels.css({'left' : panelLeftValue});
				  animating=0;
			  });

			  //get the right position of nav
			  var navLeftIndent = parseInt($jumboNav.css('left')) - jumboNavWidth;

			  //clone non-cloned first item and put it as last item
			  $jumboNav.children().last().after(jQuery("li:not(.clone)", $jumboNav).eq(0).clone());
			  jQuery("li:not(.clone)", $jumboNav).eq(0).addClass('clone');
        
        jQuery(".jumbotron .textOverlay").hide();
			  //slide the item
			  $jumboNav.stop(true,true).animate({'left' : navLeftIndent}, animateTime, function () {
				  //remove first cloned nav
				  $jumboNav.children('.clone').first().remove();
				  //set the default item to correct position
				  $jumboNav.css({'left' : jumboNavLeftValue});
          //text overlay
          jQuery(".textOverlay .title").attr('class','').addClass('title title_'+currentPanel%5);
          jQuery(".textOverlay .title").html(arJumbotron[currentPanel]['title']);
          jQuery(".textOverlay .subtitle").html(arJumbotron[currentPanel]['subtitle']);
          jumboOverlayTimer=setTimeout(function(){ jQuery(".jumbotron .textOverlay").slideDown(); }, overlayDelay);
			  });
      /* } */
    break;
	}
}

function setJumboTimer(){
	jumboTimer=setInterval(function(){
		jumboClick('+',1);
	}, jumboDelay);
}

(function ($) {
  // For resize
  var waitForFinalEvent = (function () {
    var timers = {};
    return function (callback, ms, uniqueId) {
    if (!uniqueId) {
      uniqueId = "Don't call this twice without a uniqueId";
    }
    if (timers[uniqueId]) {
      clearTimeout (timers[uniqueId]);
    }
    timers[uniqueId] = setTimeout(callback, ms);
    };
  })();
  $(window).resize(function () {
    waitForFinalEvent(function(){
      buildJumbotron();
    }, 500, "jumbotronResize");
  });
}(jQuery));

