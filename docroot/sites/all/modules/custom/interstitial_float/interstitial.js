var interstitial = new ( function($) { 
	var me = this;
	var intCircCookieExp = 1; //interstitial circ cookie exp (days)
	var intAnimDelay = 2000; //milliseconds for animation
	var windowTimeout;
	var secsLeft = 60; //seconds before window closes
	
	$(function() {
		/* close event for the modal (interstitial circ) */
		$(".modal .close").bind("click", function() {
			$(this).parents(".modal").fadeOut(300);
			return false;
		});
		
		/* for testing - display interstitial */
		//if(window.location.hash == "#interstitial") {
			$(window).load(function() {
				if(!$.cookie('mxm_intcirc')) {
					$("#interstitialCirc").css({"display":"block","visibility":"hidden"});
					
					me.positionModal($("#interstitialCirc"));
					$.cookie('mxm_intcirc', true, { expires: intCircCookieExp }, '/');
				}
			});
		//}
	}); 
	
	/* positions the modal in the middle of the page */
	me.positionModal = function(el) {
		if(!el){
			el = ".modal";
		}
		
    modalW = $(el).outerWidth();
		modalH = $(el).outerHeight();
		$(el).css({"left" : -1 * $(el).outerWidth(), "top": ($(window).height()/2) - (modalH/2), "visibility":"visible" });
		$(el).animate({"left": ($(window).width()/2) - (modalW/2)}, intAnimDelay, function() {
			windowTimeout = setInterval(function() {
				if(secsLeft > 0) {
					$(el).find("small").find("span").text(secsLeft--);
				}
				else {
					clearInterval(windowTimeout);
					$(el).fadeOut(300);
				}
			}, 1000);
		});
	};
	
})(jQuery);
