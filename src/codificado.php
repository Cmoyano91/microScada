<?php
	header('Content-Type: application/json; charset=utf-8');
	$_ERRORS = array(
						"Zona 4: Pistones de entrada",
						"Zona 4: Pistón superior",
						"Zona 4: Pistón inferior",
						"Zona 5: Pistón superior",
						"Zona 5: Pistón inferior",
						"Zona 6: Pistón superior",
						"Zona 6: Pistón inferior",
						"",
						"",
						"",
						"",
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
