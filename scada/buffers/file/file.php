<?php

	/**
	 * @brief 	Archivo que recoge los datos del archivo y los devuelve a javascript
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
	
	// --- incluimos la configuración ---
	require( "../../config.inc" );
	
	header( 'Content-Type: application/json; charset=utf-8' );
	setlocale( LC_TIME, "spanish" );
	
	
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
	
	// --- Pedimos los datos al archivo ---
	
	$result = array();
	$fileData = '';
	$fileArray = array();
	
	// --- Existe el archivo? ---
	if( file_exists( DB_FILE ) )
	{
		// --- Recogemos los datos del archivo ---
		$fileData = file_get_contents( DB_FILE );
		
		if( filesize( DB_FILE ) > 0 )
		{
			$fileData = explode( PHP_EOL , $fileData );
			
			foreach( $fileData as $value )
			{
				if ( !empty( $value ) )
				{
					// --- Separamos por los Campos ---
					$valueFields = explode( ' ' , strtr( $value , '=' , ' ' ) );
					
					// --- Tenemos todos los Campos ? ---
					if ( count( $valueFields ) == 3 )
					{
						list( $key , $timestamp , $val ) = $valueFields;
						
						if ( $timestamp > time() )
						{
							$fileArray[ $key ] = [ $val , $timestamp ];
						}
					}
				}
			}
		}
	}
	else
	{
		fclose( fopen( DB_FILE , 'x' ) );
	}
	
	foreach( $collOPC as $key )
	{
		if( array_key_exists( $key , $fileArray ) )
		{
			// --- Datos a enviar ---
			$result[ $key ] = $fileArray[ $key ][0];
			
			// --- Actualizamos el Array de Salida ---
			$fileArray[ $key ][1] = time() + ( 60 );
		}
		else
		{	
			$fileArray[ $key ] = [ "0" , ( time() + ( 60 ) ) ];
		}
	}
	
	
	// --- Creamos el fichero de salida ---
	$fileContent = '';
	
	foreach( $fileArray as $key=>$value )
	{
		$fileContent.= $key . '=' . $value[1] . ' ' . $value[0] . PHP_EOL;
	}
	
	file_put_contents( DB_FILE , $fileContent , LOCK_EX );
	
	// --- Procesamos los outValues ---
	
	$vars = array();
	
	
	// --- Comprobamos que el resultado no este vacio ---
	if( !empty( $result ) )
	{
		foreach( $result as $key => $value )
		{
			$key = strtr( $key, ']:.' ,'|-_' );
			$key = str_replace( '[', '', $key );
			
			$vars[ $key ] = $value;
		}
	}
	
	// --- Añadimos los datos del SERVER ---
	foreach( $collServer as $key )
	{
		$valor = '';
		$key = strtr( $key, ']:.' ,'|-_' );
		$key = str_replace( '[', '', $key );
		
		switch( strtolower( $key ) )
		{
			case "server|timestamp":
			{
				$valor = time();
				
				break;
			}
			case "server|fecha":
			{
				$valor = utf8_encode( strftime( "%A %d de %B del %Y" ) );
				
				
				break;
			}
			case "server|hora":
			{
				$valor = date( "h:i:s" );
				
				break;
			}
		}
		
		$vars[ $key ] = $valor;
	}

	// --- Devolvemos los datos ---
	echo json_encode( $vars );
	
	// --- Aqui ya hemos enviado los datos que tenemos en el Servidor REDIS ---
	// --- Actualizamos los datos del fichero ---

	//--- comprobamos que el scrip opc no este en marcha ---
	$execstring= 'tasklist /FI "IMAGENAME eq opc.exe"';
	$output="";
	exec( $execstring, $output );
	
	// --- Se esta ejecutando ya el refresco? ---
	if(( count( $output )) < 2 )
	{	
		$cmd = 'start /b C:\xampp\php\php readOPCFile.php';
		pclose( popen( $cmd , 'r' ) );
	}
