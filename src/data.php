<?php
	header('Content-Type: application/json; charset=utf-8');
	setlocale(LC_TIME, "spanish");
	
	$coll = array_unique( array_keys( $_REQUEST ) );
	
	$collOPC = array();
	$collServer = array();
	
	//file_put_contents( "datos.txt" , print_r( $coll , true )) ;
	foreach( $coll as $key=>$value )
	{
		$value = '[' . strtr( $value , '|-_}' , ']:. ');		

		if ( substr( $value , 0 , 8 ) == '[SERVER]' )
		{
			$collServer[] = $value;
		}
		else
		{
			$collOPC[] = $value;
		}
	}
	
	$outValues = '';
	$opcList = implode( ' ' , $collOPC );
	
	//file_put_contents( "datos.txt" , print_r( $opcList , true )) ;
	
	$outValues .= shell_exec( "ocp\opc -r {$opcList}" );
	
	// --- Procesamos los outValues ---
	$datos = explode( "\n" , trim( $outValues ) );
	
	//file_put_contents( "datos.txt" , print_r( $datos , true )) ;
	
	$vars = array();
	
	foreach( $datos as $linea )
	{
		if ( substr( $linea , 0 , 1 ) == '[' )
		{
			$arg = explode( " " , preg_replace( '/  +/', ' ' ,$linea ));
			
			$arg[0] = strtr( $arg[0], ']:.' ,'|-_' );
			$arg[0] = str_replace('[', '', $arg[0]);
			
			$vars[ $arg[0] ] = $arg[1];
		}
	}
	
	//file_put_contents( "datos2.txt" , print_r( $vars , true )) ;
	
	// --- Añadimos los datos del SERVER ---
	foreach( $collServer as $key )
	{
		$valor = '';
		$key = strtr( $key, ']:.' ,'|-_' );
		$key = str_replace('[', '', $key);
		
		switch( strtolower( $key ) )
		{
			case "server|timestamp":
			{
				$valor = time();
				
				break;
			}
			case "server|fecha":
			{
				$valor = utf8_encode( strftime("%A %d de %B del %Y") );
				
				
				break;
			}
			case "server|hora":
			{
				$valor = date("h:i:s");
				
				break;
			}
		}
		
		
		$vars[ $key ] = $valor;
	}
	
	
	echo json_encode( $vars );
	
	//file_put_contents( "datos.txt" , print_r( $vars , true )) ;
