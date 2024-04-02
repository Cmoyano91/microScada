<?php

	/**
	 * @brief 	Primera versión en la que no utiliza redis
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
	
	//Poner el idioma en español con sus respectivas caracteristicas, para que la fecha salga correctamente
	header( 'Content-Type: application/json; charset=utf-8' );
	setlocale( LC_TIME, "spanish" );
	
	
	$coll = array_unique( array_keys( $_REQUEST ) );
	
	$collOPC = array();
	$collServer = array();

	foreach( $coll as $key=>$value )
	{
		$value = '[' . strtr( $value , '|-_}' , ']:. ' );		

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
	
	
	$outValues .= shell_exec( "ocp\opc -r {$opcList}" );
	
	// --- Procesamos los outValues ---
	$datos = explode( "\n" , trim( $outValues ) );
	
	$vars = array();
	
	foreach( $datos as $linea )
	{
		if ( substr( $linea , 0 , 1 ) == '[' )
		{
			$arg = explode( " " , preg_replace( '/  +/' , ' ' , $linea ) );
			
			$arg[0] = strtr( $arg[0] , ']:.' , '|-_' );
			$arg[0] = str_replace( '[' , '' , $arg[0] );
			
			$vars[ $arg[0] ] = $arg[1];
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
				$valor = utf8_encode( strftime( "%A , %d de %B del %Y" ) ); //%A Dia de la semana, %d Dia del mes, %B Mes %Y Año
				
				
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
	
		
	echo json_encode( $vars );
