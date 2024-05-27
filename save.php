<?php

	/**
	 * @brief 	Este archivo se encarga del envio de formularios
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
	 
	
	$coll = $_REQUEST ;
	
		//file_put_contents("codecoll.txt" , print_r($coll,  true));
	
	$cmd = '';
	$cmdFirst = '';
	
	$items = 0;

	
	foreach( $coll as $key=>$value )
	{
		// --- $value tiene valor? ---
		if( $value != '')
		{
			// --- convertimos la cadena y añadimos la variable ---
			$cmd.= '[' . strtr( $key , '|_-' , '].:' ) . '="' . $value . '" ';
			
			// --- El primero  ??? ---
			if ( $items == 0)
			{
				$cmdFirst = $cmd;
			}
			
			$items++;
		}
	}
	
	// --- Miramos si el Numero de Elementos es PAR ---
	if (( $items % 2 ) == 0 )
	{
		$cmd.= $cmdFirst;
	}
		//file_put_contents("codecmd.txt" , print_r($cmd,  true));
		

	$succes = shell_exec( "ocp\opc -w {$cmd}" );

		//file_put_contents("codesuces.txt" , print_r($succes,  true));
	
	echo json_encode( $succes );
