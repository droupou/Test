$(document).ready(function() {
	var delay= 500;

	// Hide the data at first
	$("#EdData").hide();
	$("#ExpData").hide();
	$("#CompData").hide();
	$('h2').hide();

	// Begin hiding the companies
	$('#egsdata').hide();
	$('#cldata').hide();
	$('#htdata').hide();
	$('#usardata').hide();
	$('#RlpgData').hide();

	// Toggle the data fields
	$("#EdHead").click(function(){
		$("#EdData").slideToggle(delay);
	});
	$("#ExpHead").click(function(){
		$("#ExpData").slideToggle(delay);
	});
	$("#CompHead").click(function(){
		$("#CompData").slideToggle(delay);
	});
	$("#egs").click(function(){
		$("#egsdata").slideToggle(delay);
	});
	$("#cl").click(function(){
		$("#cldata").slideToggle(delay);
	});
	$("#ht").click(function(){
		$("#htdata").slideToggle(delay);
	});
	$("#usar").click(function(){
		$("#usardata").slideToggle(delay);
	});
	$("#Rlpg").click(function(){
		$("#RlpgData").slideToggle(delay);
	});
	
	// Slide down my title
	$('h2').slideDown(6000);
});
