<?php

	/**
	 * @brief 	Archivo encargado de comprobar los fallos y bloqueos y devolver los mensages correspondientes a javascript
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

	header( 'Content-Type: application/json; charset=utf-8' );
	require( 'config.inc' );


	// --- Recogemos en valor de bloqueo y lo transformamos en entero---
	$result = intval( $_REQUEST['Com2|Bloqueo'] );
	
	// --- Pasamos el valos a binario ---
	$resBin = decbin( $result );
	
	// --- Completamos 16 bits con 0 ---
	$resPad = str_pad( $resBin , 16 , '0' , STR_PAD_LEFT );
	
	// --- Invertimos la cadena ---
	$resInv = strrev( $resPad );
	
	// --- Separamos los bits en una array ---
	$resArray = str_split( $resInv );

	$blocs = array();
	for( $i = 0; $i < count( $resArray ) ; $i++ )
	{
		if( $resArray[ $i ] == 1 )
		{
			$blocs[] = ERRORS[ $i ];
		}
	}
	//file_put_contents("code.txt" , print_r($resArray,  true));
	
	echo json_encode( $blocs );
