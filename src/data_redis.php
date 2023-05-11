<?php
	header('Content-Type: application/json; charset=utf-8');
	setlocale(LC_TIME, "spanish");
	
	// --- Creacion y conexion a redis ---
	$redis = new Redis();
	$redis->connect( '172.23.184.244' , 6379 );
	
	// --- Recogemos los nombres de las variables ---
	$coll = array_unique( array_keys( $_REQUEST ) );

	
	$collOPC = array();
	$collServer = array();

	foreach( $coll as $key=>$value )
	{
		// --- Cambiamos la codificación de las variables ---
		$value = '[' . strtr( $value , '|-_}' , ']:. ');		

		// --- Separamos las variables del OPC y las de SERVER ---
		if ( substr( $value , 0 , 8 ) == '[SERVER]' )
		{
			$collServer[] = $value;
		}
		else
		{
			$collOPC[] = $value;
		}
	}
	
	// --- Pedimos los datos a redis ---
	
	$result = array();
	
	
	foreach( $collOPC as $value )
	{
		// --- Existe el dato? ---
		if( $redis->exists( $value ) > 0 )
		{
			// --- Recogemos el dato de REDIS y le actualizamos el expire ---
			$result[ $value ] = $redis->get( $value );
			$redis->expire( $value , 60 );
		}
		else
		{
			// --- Creamos el valor en Redis y le ponemos un expire ---
			
			$redis->set( $value , '');
			$redis->expire( $value  , 60 );
		}
		
	}

	
	// --- Procesamos los outValues ---
	
	$vars = array();
	
	
	// --- Comprobamos que el resultado no este vacio ---
	if( !empty( $result ) )
	{
		foreach( $result as $key => $value )
		{
			$key = strtr( $key, ']:.' ,'|-_' );
			$key = str_replace('[', '', $key);
			
			$vars[ $key ] = $value;
		}
	}
	
	
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

	// --- Devolvemos los datos ---
	echo json_encode( $vars );
	
	// --- Aqui ya hemos enviado los datos que tenemos en el Servidor REDIS ---
	// --- Actualizamos los datos de REDIS ---
	
	//--- comprobamos que el scrip opc no este en marcha ---
	$execstring= 'tasklist /FI "IMAGENAME eq opc.exe"';
	$output="";
	exec($execstring, $output);
	file_put_contents("exec.txt" , print_r($output,  true));
	
	if( count( $output ) < 2)
	{
		$cmd = 'start /b C:\xampp\php\php readOPC.php';
		pclose( popen( $cmd , 'r' ) );
	}
	
	
	

