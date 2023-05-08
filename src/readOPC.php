<?php
	
	// --- Creamos la conexión con redis ---
	$redis = new Redis();
	$redis->connect( '172.23.184.244' , 6379 );
	
	// --- Recogemos todas las keys de redis
	$coll = array_unique( $redis->keys( '*' ) );
	
	
	// --- Creamos la cadena para la consulta con el OPC ---
	$opcList = implode( ' ' , $coll );
	
	// --- Ejecutamos el script ---
	$outValues = shell_exec( "ocp\opc -r {$opcList}" );
	
	
	
	// --- Procesamos los outValues ---
	$datos = explode( "\n" , trim( $outValues ) );
	
	$vars = array();
	
	foreach( $datos as $linea )
	{
		if ( substr( $linea , 0 , 1 ) == '[' )
		{
			$arg = explode( " " , preg_replace( '/  +/', ' ' ,$linea ));
			
			// --- Guardamos el expire que tenia para ponerlo otra vez cuando la creamos de nuevo ---

			$exp = $redis->ttl( $arg[0] );
			
			$redis->set( $arg[0] , $arg[1] );
			$redis->expire( $arg[0], $exp );
			
			
			$vars[ $arg[0] ] = [ 
									$arg[1],
									$redis->ttl( $arg[0] )
								];
			
			//$redis->set( $arg[0] , $arg[1] , [ 'KEEPTTL' ] )
		}
	}
	
	
	file_put_contents( "datos31.txt" , print_r( $vars , true )) ;
