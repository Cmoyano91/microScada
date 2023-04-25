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
	
	if ( file_exists( 'sheets/head.inc' ) )
	{
		include( 'sheets/head.inc' );
	}
	
	include( 'sheets/' . $sheet . '.inc' );
	
	if ( file_exists( 'sheets/foot.inc' ) )
	{
		include( 'sheets/foot.inc' );
	}
	
	echo '</body>';
	
	
