<?php
	/**
	*	Envio de formularios 
	*/
	
	
	$coll = $_REQUEST ;
	
	//file_put_contents( "datos.txt" , print_r( $coll , true )) ;
	
	$cmd = '';
	
	foreach( $coll as $key=>$value )
	{
		if( $value != '')
		{
			$cmd .= '[' . strtr( $key , '|_-' , '].:' ) . '="' . $value . '" ';
		}
	}
	
	file_put_contents( "datos.txt" , print_r( $cmd , true )) ;
	$succes = shell_exec( "ocp\opc -w {$cmd}" );
	
	echo json_encode( $succes );
	
