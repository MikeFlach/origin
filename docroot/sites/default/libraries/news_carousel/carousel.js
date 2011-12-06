var carousel = new ( function($) { 
	var me = this;
	
	$(function() {
		$(window).load(function() {
			$(".carouselLong .jCarouselLite").jCarouselLite({
				btnNext: ".carouselLong .nextBtn",
				btnPrev: ".carouselLong .prevBtn",
				scroll: 1,
				visible: 5,
				speed: 500,
				circular: true
			});
			
			$(".carouselWLongAd .jCarouselLite").jCarouselLite({
				btnNext: ".carouselWLongAd .nextBtn",
				btnPrev: ".carouselWLongAd .prevBtn",
				scroll: 1,
				visible: 1,
				speed: 500,
				circular: true
			});
		});
	}); 
	
	
})(jQuery);


