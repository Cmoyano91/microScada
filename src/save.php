<?php
	/**
	*	Envio de formularios 
	*/
	
	
	$coll = $_REQUEST ;
	
	$cmd = '';
	
	foreach( $coll as $key=>$value )
	{
		if( $value != '')
		{
			$cmd .= '[' . strtr( $key , '|_' , '].' ) . '="' . $value . '" ';
		}
	}
	
	$succes = shell_exec( "ocp\opc -w {$cmd}" );
	
	echo json_encode( $succes );
	
