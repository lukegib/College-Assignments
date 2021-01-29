$(document).ready(function(){

	$('.setButton').click(function() {
		var clicks = $(this).data('clicks');
		
		if (!clicks) {
			$('#settings').width("100%");
			$('#emailchange').addClass('visible');
		} else {
			$('#settings').width("0");
			$('.visible').removeClass('visible');
		}
		
		$(this).data("clicks", !clicks);
	});


	$('.emailOp').click(function() {
		$('.visible').removeClass('visible');
		$('#emailchange').addClass('visible');
	});

	$('.passwordOp').click(function() {
		$('.visible').removeClass('visible');
		$('#oldPass').addClass('visible');
	});

	$('.profileOp').click(function() {
		$('.visible').removeClass('visible');
		$('#imageChange').addClass('visible');
	});

});