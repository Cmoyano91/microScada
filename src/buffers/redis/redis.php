<?php

	/**
	 * @brief 	Archivo que recoge los datos de redis y los devuelve a javascript
	 * @author  Cristian Moyano Ureña <cmoyano18@gmail.com>
	 * @author  Sara Valero Valero
	 * @version 1.0
	 *
	 * @section LICENSE
	 *			
	 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU
	 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
	 * (at your option) any later version.
	 * 
	 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
	 * even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
	 * the GNU General Public License for more details.
	 * 
	 * You should have received a copy of the GNU General Public License along with this program. If not, see
	 * <https://www.gnu.org/licenses/>.
	 * 
	 *
	 */
	 
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
	//file_put_contents("exec.txt" , print_r($output,  true));
	
	if( count( $output ) < 2)
	{
		$cmd = 'start /b C:\xampp\php\php readOPC.php';
		pclose( popen( $cmd , 'r' ) );
	}
	
	
	

