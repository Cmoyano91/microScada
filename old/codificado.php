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

	header('Content-Type: application/json; charset=utf-8');
	$_ERRORS = array(
						"Zona 4: Pistones de entrada",
						"Zona 4: Pistón superior",
						"Zona 4: Pistón inferior",
						"Zona 5: Pistón superior",
						"Zona 5: Pistón inferior",
						"Zona 6: Pistón superior",
						"Zona 6: Pistón inferior",
						"Zona 2: Error Variador cinta",
						"Zona 2: Error Variador bomba",
						"Zona 4: Error Variador arrastre",
						"Zona 5: Error Variador arrastre",
						"",
						"",
						"",
						""
					);


	// --- Recogemos en valor de bloqueo y lo transformamos en entero---
	$result = intval( $_REQUEST['Com2|Bloqueo'] );
	
	// --- Pasamos el valos a binario ---
	$resBin = decbin($result);
	
	// --- Completamos 16 bits con 0 ---
	$resPad = str_pad( $resBin , 16 , '0' , STR_PAD_LEFT );
	
	// --- Invertimos la cadena ---
	$resInv = strrev( $resPad );
	
	// --- Separamos los bits en una array ---
	$resArray = str_split( $resInv );

	$blocs = array();
	for( $i = 0; $i < count($resArray) ; $i++ )
	{
		if( $resArray[ $i ] == 1 )
		{
			$blocs[] = $_ERRORS[ $i ];
		}
	}
	//file_put_contents("code.txt" , print_r($resArray,  true));
	
	echo json_encode( $blocs );
