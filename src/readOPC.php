<?php

	/**
	 * @brief 	Archivo encargado de recoger los datos del servidor OPC y ponerlos en el servidor redis
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
