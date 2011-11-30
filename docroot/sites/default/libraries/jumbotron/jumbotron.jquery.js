// Jumbotron - need to convert to jQuery plugin

var currentPanel = 0;
var jumboDelay = 3000;
var animateTime = 1000;
var jumboTimer, panelWidth, panelLeftValue, jumboNavWidth, jumboNavLeftValue;
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
	if(arJumbotron.length < 5){
		//clone first item and put it as last item
		//$jumboNav.children().last().after($jumboNav.children().first().clone().addClass('clone'));
	}

	//set the default item to the correct position
	$jumboNav.css({'left' : jumboNavLeftValue});
}

function buildJumbotron(){
	// Reset jumbotron
	jQuery(".jumboNav").html('');
	jQuery(".jumbotron .nextprev, .jumbotron .navtitle, .jumbotron #navIndicator").remove();
	currentPanel=0;
	clearInterval(jumboTimer);

	var strPanels="<ul>";
	for(var i=0; i<arJumbotron.length; i++){
		strPanels += '<li id="jpanel_'+i+'">';
		if(i==0){
			strPanels += '<a href="#" onclick="alert(\'Go to article\'); return false;"><img src="'+arJumbotron[i].src+'" /></a>'
		} else {
			strPanels += "&nbsp;";
		}
		strPanels += '</li>';
	}
	strPanels += "</ul>";
	jQuery(".jumbotron .panels").html(strPanels);
        strNext="<div class=\"jumboNavNext\"><a href=\"#\" onclick=\"jumboClick('+');return false;\"><img src=\"/sites/default/themes/maxim_base/images/jumbotron_nav_next.png\" /></a></div>";
        jQuery('.jumbotron .panels').after(strNext);

	// Build Next/Previous buttons
	var prevImg="http://cdn2.maxim.com/maxim/files/maxim2/Maxim/static_files/images/jumbotron/lt_arrow.png";
	var nextImg="http://cdn2.maxim.com/maxim/files/maxim2/Maxim/static_files/images/jumbotron/rt_arrow.png";
	var strPrevNext="";

	strPrevNext+='<div class="navtitle" onclick="jumboClick(\'-\');">TOP<br/ ><span>'+arJumbotron.length+'</span></div>';
	strPrevNext+='<div id="navIndicator" class="selector_arrow_0"></div>';
	strPrevNext+='<div class="nextprev leftNav"><a href="#" onclick="jumboClick(\'-\');return false;"><img src="'+prevImg+'" /></a></div>';
	strPrevNext+='<div class="nextprev rightNav"><a href="#" onclick="jumboClick(\'+\');return false;"><img src="'+nextImg+'" /></a></div>';
	jQuery('.jumbotron').append(strPrevNext);

	// Build Nav
	var strNav="<ul>";
	for(var i=0; i<arJumbotron.length; i++){
		strNav += '<li id="jumboNav_'+i+'">';
		strNav += '<div class="selector"></div><div class="selector_arrow selector_arrow_'+i+'"></div>';
		strNav += '<div class="details"><a href="#" onclick="alert(\'Go to article\'); return false;"> <img src="'+arJumbotron[i].thumb+'" class="reflect" /><div class="navNum">'+eval(i+1)+'</div><div class="title">'+arJumbotron[i].title+'</div></a></div></li>';
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
					$nextPanel.html('<a href="#" onclick="alert(\'Go to article\'); return false;"><img src="'+arJumbotron[nextPanel].src+'" /></a>');
				}
				jumboAnimate(dir);
			break;
			case 'ajax':
				if($nextPanel.html().length < 10){
					$nextPanel.load(arJumbotron[nextPanel].src, function() {
						jumboAnimate(dir);
					});
				} else {
					jumboAnimate(dir);
				}
			break;
		}
	}
}

function jumboAnimate(dir){
	animating=1;
	switch (dir) {
		case '+':
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

			//fade out the nav indicator
			jQuery(".jumbotron #navIndicator").fadeOut(400,function(){ jQuery(this).attr('class',''); });

			//clone non-cloned first item and put it as last item
			$jumboNav.children().last().after(jQuery("li:not(.clone)", $jumboNav).eq(0).clone());
			jQuery("li:not(.clone)", $jumboNav).eq(0).addClass('clone');
			//slide the item
			$jumboNav.stop(true,true).animate({'left' : navLeftIndent}, animateTime, function () {
				//remove first cloned nav
				$jumboNav.children('.clone').first().remove();

				//set the default item to correct position
				$jumboNav.css({'left' : jumboNavLeftValue});
				jQuery(".jumbotron #navIndicator").fadeIn(200).addClass('selector_arrow_'+currentPanel);
			});
		break;
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
			jQuery(".jumbotron #navIndicator").fadeOut(400,function(){ jQuery(this).attr('class',''); });

			$jumboNav.stop(true,true).animate({'left' : navLeftIndent}, animateTime, function () {
				//remove clone class from 1st el
				jQuery("li", $jumboNav).first().removeClass('clone');
				//clone 2nd to last item and put it as last item
				$jumboNav.children().first().before(jQuery("li", $jumboNav).eq(arJumbotron.length-1).clone().addClass('clone'));
				//remove last element
				jQuery("li", $jumboNav).last().remove();
				//set the default item to correct position
				$jumboNav.css({'left' : jumboNavLeftValue});

				jQuery(".jumbotron #navIndicator").fadeIn(200).addClass('selector_arrow_'+currentPanel);
			});
		break;
	}
}

function setJumboTimer(){
	jumboTimer=setInterval(function(){
		jumboClick('+',1);
	}, jumboDelay);
}