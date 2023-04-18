<?php
	require('funciones.inc');
	
	// --- Miramos si enviamos hoja para mostrar ---
	$sheet = 'main';
	
	if ( !empty( $_SERVER['QUERY_STRING'] ) )
	{
		$sheet = $_SERVER['QUERY_STRING'];
	}
	
	// --- Headers ---
	include( 'headers.inc' );
	
	echo '<body onload="inicio();">';
	
	include( 'sheets/' . $sheet . '.inc' );
	
	echo '</body>';
	
