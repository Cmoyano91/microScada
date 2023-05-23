<?php

	/**
	 * @brief 	
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
	
	
