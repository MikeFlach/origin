// Jumbotron - need to convert to jQuery plugin

var currentPanel = 0;
var jumboDelay = 7000;
var animateTime = 1000;
var overlaySlideUp = 400;
var overlaySlideDown = 500;
var overlayDelay = 1500;
var overlayDuration = 5500;
var jumboTimer, jumboOverlayShowTimer, jumboOverlayHideTimer, panelWidth, panelLeftValue, jumboNavWidth, jumboNavLeftValue;
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

  jQuery("#jumboNav_" + currentPanel).addClass('selected');
  showOverlay(1);
}

function showOverlay(show){
  if(show==1){
    /* Don't show overlay for smaller screens */
    if(jQuery(window).width() >= 480){
      jQuery(".jumbotron .textOverlay").show();  
    }
  } else {
    jQuery(".jumbotron .textOverlay").hide();  
  }
}

function buildJumbotron(){
	// Reset jumbotron
	jQuery(".jumboNav").html('');
	jQuery(".jumbotron .nextprev, .jumbotron .navtitle, .jumbotron .jumboNavNext, .jumbotron .jumboNavPrev,.jumbotron #navIndicator, .jumbotron .textOverlay").remove();
	currentPanel=0;
	clearInterval(jumboTimer);

	var strPanels="<ul>";
	for(var i=0; i<arJumbotron.length; i++){
		strPanels += '<li id="jpanel_'+i+'">';
		if(i==0){
			strPanels += '<a href="'+arJumbotron[i].link+'"><img src="'+arJumbotron[i].src+'" alt="'+arJumbotron[i].alt_image+'" title="'+arJumbotron[i].title_image+'" /></a>'
		} else {
			strPanels += "&nbsp;";
		}
		strPanels += '</li>';
	}
	strPanels += "</ul>";
	jQuery(".jumbotron .panels").html(strPanels);
  strTextOverlay='<div class="textOverlay"><div class="title title_0">'+convertToHTML(arJumbotron[0].title)+'</div><div class="subtitle">'+convertToHTML(arJumbotron[0].subtitle)+'</div></div>';
  jQuery('.jumbotron .panels').after(strTextOverlay);

	// Build Next/Previous buttons
	var strPrevNext="";
	//strPrevNext+='<div class="navtitle" onclick="jumboClick(\'-\');">TOP<br/ ><span>'+arJumbotron.length+'</span></div>';
	strPrevNext+='<div class="nextprev leftNav"><a href="#" onclick="jumboClick(\'-\');return false;"><div class="prevButton"></div></a></div>';
	strPrevNext+='<div class="nextprev rightNav"><a href="#" onclick="jumboClick(\'+\');return false;"><div class="nextButton"></div></a></div>';
	jQuery('.jumbotron').append(strPrevNext);

	// Build Nav
	var strNav="<ul>";
  var numColors=5;
	for(var i=0; i<arJumbotron.length; i++){
		strNav += '<li id="jumboNav_'+i+'">';
		strNav += '<div class="details"><a href="'+arJumbotron[i].link+'"> <img src="'+arJumbotron[i].thumb+'" alt="'+arJumbotron[i].alt_image+'" title="'+arJumbotron[i].title_image+'" class="reflect" /><div class="title">'+convertToHTML(arJumbotron[i].title)+'</div></a></div></li>';
	}
	strNav += "</ul>";

	jQuery(".jumboNav").html(strNav);

	jumbotronInit();
}

function convertToHTML(str){
  return jQuery('<span />', { html: str }).text();
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
					$nextPanel.html('<a href="'+arJumbotron[nextPanel].link+'"><img alt="'+arJumbotron[nextPanel].alt_image+'" title="'+arJumbotron[nextPanel].title_image+'"src="'+arJumbotron[nextPanel].src+'" /></a>');
				}
				jumboAnimate(dir, currentPanel, fromTimer);
			break;
			case 'ajax':
				if($nextPanel.html().length < 10){
					$nextPanel.load(arJumbotron[nextPanel].src, function() {
						jumboAnimate(dir, currentPanel, fromTimer);
					});
				} else {
					jumboAnimate(dir, currentPanel, fromTimer);
				}
			break;
		}
    currentPanel=nextPanel;
	}
}

function jumboAnimate(dir, oldPanel, fromTimer){
	animating=1;

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

        //text overlay
        jQuery(".textOverlay .title").attr('class','').addClass('title title_'+currentPanel%5);
        jQuery(".textOverlay .title").html(convertToHTML(arJumbotron[currentPanel]['title']));
        jQuery(".textOverlay .subtitle").html(convertToHTML(arJumbotron[currentPanel]['subtitle']));
        jQuery(".jumboNav ul li").removeClass('selected');
        jQuery("#jumboNav_" + currentPanel).addClass('selected');
			});

			//get the right position of nav
			var navLeftIndent = parseInt($jumboNav.css('left')) + jumboNavWidth;
		break;
    default:
		  //get the right position
		  var panelLeftIndent = parseInt($jumboPanels.css('left')) - panelWidth;
		  //slide the item
		  $jumboPanels.animate({'left' : panelLeftIndent}, animateTime, function () {
			  //move the first item and put it as last item
			  $jumboPanels.children().last().after($jumboPanels.children().first());
			  //set the default item to correct position
			  $jumboPanels.css({'left' : panelLeftValue});
			  animating=0;

        //text overlay
        jQuery(".textOverlay .title").attr('class','').addClass('title title_'+currentPanel%5);
        jQuery(".textOverlay .title").html(convertToHTML(arJumbotron[currentPanel]['title']));
        jQuery(".textOverlay .subtitle").html(convertToHTML(arJumbotron[currentPanel]['subtitle']));
        jQuery(".jumboNav ul li").removeClass('selected');
        jQuery("#jumboNav_" + currentPanel).addClass('selected');
		  });
    break;
	}
}

function setJumboTimer(){
	jumboTimer=setInterval(function(){
		jumboClick('+',1);
	}, jumboDelay);
}

jQuery(function(){
  // For resize
  jQuery('.jumbotron').resize(function () { 
    console.log(jQuery('.jumbotron').width());
    buildJumbotron();
  });
});

