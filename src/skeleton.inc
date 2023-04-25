<?php
	/**
	 */
	function opcExec()
	{
		$buffer = ob_get_contents();
		
		$output = array();
		
		preg_match_all('/\<\%([^\%]*)\%\>/', $buffer , $output );
		
		foreach( $output[1] as $key=>$value )
		{
			$output[1][ $key ] = trim( $value );
		}
		
		// --- Organiza ---
		$vars = array_combine( $output[0] , $output[1] );
		
		$opcList = implode( ' ' , $output[1] );
		
		$outValues = shell_exec( "ocp\opc -r {$opcList}" );
		
		// --- Procesamos los outValues ---
		$datos = explode( "\n" , trim( $outValues ) );
		
		foreach( $datos as $linea )
		{
			if ( substr( $linea , 0 , 1 ) == '[' )
			{
				$arg = explode( " " , preg_replace( '/  +/', ' ' ,$linea ));
				
				while( $index = array_search( $arg[0] , $vars ) )
				{
					$vars[ $index ] = $arg[1];
				}
			}
		}
		
		$buffer = strtr( $buffer , $vars );
		ob_end_clean();
		
		echo $buffer;
		
	}
	
	
	// --- Capturamos el Buffer ---
	ob_start();
	
	
