function carga()
{
	// --- Carga todos los Campos a Actualizar ---
	var col = $("[datafield]");
	
//	col.push( $( "[dataanim]" ) );
	
	var vars = "";
	
	for(var index = 0; index < col.length; index++)
	{
		vars = vars + col[ index ].getAttribute( "datafield" ) + "&";
	}
	
	// --- Peticion AJAX ---
	$.ajax(
			{
				url: "data.php",
				data: vars,
//					dataType: "json",
				success: function ( result ) { cargaOk( result ); }
			}
		);
}

function cargaOk( result )
{
	// --- Actualizamos los campos ---
	$.each( result, function( key, val )
			{
				// --- Buscamos todos los Objetos del DOM que tienen ese DATAFIELD ---
				var coll = $("[datafield~='" + key + "']" );
				
				// --- Añadimos los de Animacion ---
				coll.push( $( "[dataanim~='" + key + "']" ) );

				// --- Comprobamos de que tipo es cada elemento ---
				$.each( coll,
						function ( index , ctrl )
						{
							// --- Segun el tipo ---
							switch ( $( ctrl ).prop( "nodeName" ) )
							{
								case "INPUT":
								{
									switch ( $( ctrl ).prop( "type" ) )
									{
										case "checkbox":
										{
											if ( val == "1" )
											{
												$( ctrl ).prop( "checked" , true );
											}
											else
											{
												$( ctrl ).prop( "checked" , false );
											}
											
											break;
										}
										
										case "number":
										case "text":
										{
											$( ctrl ).val( val );
											
											break;
										}
									}
									
									break;
								}
								
								case "path":
								case "circle":
								{
									$( ctrl ).attr( "value" , val );
									
									break;
								}
								
								// --- Los de Bloque ---
								default:
								{
									// --- Tiene VALUE ? ---
									if ( $( ctrl ).attr( "value" ) !== undefined )
									{
										$( ctrl ).attr( "value" , val );
									}
									else
									{
										$( ctrl ).html( val );
									}
									
									break;
								}
							}
						}
					);
			}
		);
}

function inicio()
{
	carga();
	
	// --- Actualización de datos ---
	setInterval( carga , 20000 );
	
	// --- Actualización de animaciones ---
	setInterval( animTimeout , 500 );
}

function animTimeout()
{
	// --- Recogemos todos los campos con datafield ---
	var coll = $("[datafield]");
	
	for( x = 0 ; x < coll.length ; x++ )
	{
		var status = $( coll[ x ] ).attr( "value" ) ;
		
		// --- Solo ejecuta si tiene Valor ---
		if ( status != undefined )
		{
			var type = $( coll[ x ] ).attr( "dataanimtype" ) ;
			
			if ( type != undefined )
			{
				var values = $( coll[ x ] ).attr( "dataanimvalues") ;
				
				if ( values == undefined )
				{
					values = "";
				}
				
				values = values.split( ";" );
				
				// --- Comprobamos el tipo de animación que es ---
				switch( $( coll[ x ] ).attr( "dataanimtype" ) )
				{
					case "fill":
					{				
						coll[ x ].style.fill = values[ status ];
						
						break;
					}
					case "offset":
					{
						if( status == "1" )
						{
							var length = coll[ x ].style.strokeDashoffset;
							length -= values[ 0 ];
							
							coll[ x ].style.strokeDashoffset = length;
						}
						else
						{
							coll[ x ].style.strokeDashoffset = values[ 1 ];
						}
					}
				}		
			}
		}
	}
}

function post( source )
{
	// --- Los Estandar ---
	var formulario = $( "#" + source );
	
	var items = formulario.serializeArray();
	
	// --- Añadimos los que estan a CERO ---
	formulario.children( "input:checkbox:not(:checked)" ).each(
						function()
						{
							items.push(
										{
											name : this.name,
											value : 0
										}
									);
						});
	
	items = $.param( items );
					
	$.ajax(
			{
				url: "save.php",
				data: items,
//				dataType: "json",
				success: function ( data ) { alert( data ) }
			}
		);
			
	
	//console.log( items );
}
