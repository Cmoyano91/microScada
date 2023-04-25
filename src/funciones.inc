<?php

	// --- Cargar imagen SVG ---
	function getSvg( $file , $return = true )
	{
		$content = file( $file );
		
		// --- Comprobamos la primera ---
		if ( substr( $content[0] , 0 , 5 ) == '<?xml' )
		{
			unset( $content[0] );
		}
		
		if ( $return )
		{
			return implode( "\r\n" , $content );
		}
		
		echo implode( "\r\n" , $content );
	}
