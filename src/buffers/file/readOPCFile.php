<?php

	/**
	 * @brief 	Archivo encargado de recoger los datos del servidor OPC y ponerlos en un archivo
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
	
	$fileData = '';
	$fileArray = array();

	// --- Existe el fichero? ---
	if( file_exists( DB_FILE ) )
	{
		// --- Leemos todo su contenido ---
		$fileData = file_get_contents( DB_FILE );
	}
	else
	{	// --- Lo creamos y lo cerramos ---
		fclose( fopen( DB_FILE , 'x' ) );
	}
	
	
	// --- Tine contenido el fichero? ---
	if( filesize(DB_FILE) > 0 )
	{
		// --- Separamos la cadena por lineas ---
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

	// --- Recogemos las keys del archivo ---
	$coll = array_unique( array_keys( $fileArray ) );
	
	// --- Creamos la cadena para la consulta con el OPC ---
	$opcList = implode( ' ' , $coll );
	
	// --- Ejecutamos el script ---
	$outValues = shell_exec( "..\..\ocp\opc -r {$opcList}" );
	
	//file_put_contents( "test2.txt" , print_r( $outValues, true ) );
	
	// --- Procesamos los outValues ---
	$datos = explode( "\n" , trim( $outValues ) );
	
	$vars = array();
	
	foreach( $datos as $linea )
	{
		if ( substr( $linea , 0 , 1 ) == '[' )
		{
			$arg = explode( " " , preg_replace( '/  +/', ' ' ,$linea ) );
			
			// --- Guardamos en la variable un dato por fila ---
			
			$fileArray[ $arg[0] ][0] = $arg[1];
		}
	}

	$fileContent = '';
	
	foreach( $fileArray as $key=>$value )
	{
		$fileContent.= $key . '=' . $value[1] . ' ' . $value[0] . PHP_EOL;
	}

	// --- Volcamos la variable en el archivo ---
	file_put_contents( DB_FILE , $fileContent , LOCK_EX );
