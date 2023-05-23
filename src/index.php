<?php
	require('libraries/funciones.inc');
	require('config.inc');
	
	// --- Miramos si enviamos hoja para mostrar ---
	$_SHEET = 'main';
	
	if ( !empty( $_SERVER['QUERY_STRING'] ) )
	{
		$_SHEET = $_SERVER['QUERY_STRING'];
	}
	
	// --- Headers ---
	include( 'headers.inc' );
	
	echo '<body onload="SCADA.inicio();">';
	
	if ( file_exists( 'sheets/head.inc' ) )
	{
		include( 'sheets/head.inc' );
	}
	
	include( 'sheets/' . $_SHEET . '.inc' );
	
	if ( file_exists( 'sheets/foot.inc' ) )
	{
		include( 'sheets/foot.inc' );
	}
	
	echo '</body>';
