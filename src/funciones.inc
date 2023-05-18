<?php
	/**
	 * @brief 	Archivo de finciones en PHP
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
	 
	 
	 
	/**
	 * getSvg
	 *
	 * Función para poner un archivo SVG en el codigo eliminando la primera linea si tiene la etiqueta xml
	 *
	 * @param
	 *		$file		string		Ruta del archivo svg
	 * 		$return		bool		Si devuelve el codigo del archivo o lo imprime directamente
	 * 
	 */
	function getSvg( $file , $return = true )
	{
		$content = file( $file );
		
		// --- Comprobamos la primera ---
		if ( substr( $content[0] , 0 , 5 ) == '<?xml' )
		{
			unset( $content[0] );
		}
		
		if ( $return )
		{
			return implode( "\r\n" , $content );
		}
		
		echo implode( "\r\n" , $content );
	}
