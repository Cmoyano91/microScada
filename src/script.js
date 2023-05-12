var subsFunction = null;
var subsVars = null;


/**
 * carga
 *
 * Se encarga de recoger los campos de datafield y hacer una consulta con ellos para sacar los valores de redis
 *
 * @param
 *
 */
function carga()
{
	// --- Carga todos los Campos a Actualizar ---
	var col = $("[datafield]");
	
	var vars = "";
	
	for(var index = 0; index < col.length; index++)
	{
		vars = vars + col[ index ].getAttribute( "datafield" ) + "&";
	}
	
	// --- Añadimos las variables que tenemos suscritas ---
	if ( subsVars !== null )
	{
		if( Array.isArray( subsVars ))
		{
			for(var i = 0; i < subsVars.length; i++)
			{
				vars = vars + subsVars[ i ] + "&";
			}
		}
	}
	
	vars = vars.replace( /&+/gm , '&');
	vars = vars.replace( /&+$/gm , '');
	
	// --- Peticion AJAX ---
	$.ajax(
			{
				url: "data_redis.php",
				data: vars,
//				dataType: "json",
				success: function ( result ) { cargaOk( result ); }
			}
		);
}

/**
 * cargaOk
 *
 * Se encarga de poner los datos en sus correspondientes sitios que coincidan con el datafield
 *
 * @param
 * 		result		array		Array asociativo en el que estan los nombres de las variables y los valores
 *
 */
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
							// --- tiene Formateo ? ---
							if ( $( ctrl ).attr( 'datafixed' ) )
							{
								val = parseFloat( val ).toFixed( $( ctrl ).attr( 'datafixed' ) );
							}
							
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
											
											break;hide
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
	
	// --- Vamos a la funcion que tenemos definida ---
	if ( typeof subsFunction == "function" )
	{
		var valores = {};
		$.each( result, function( key, val )
			{
				for( var i = 0 ; i < subsVars.length ; i++ )
				{
					if( subsVars[i] == key )
					{
						valores[ key ] =  val;
					}
				}
			}
		);
		subsFunction( valores );
	}
	
	// --- Vamos a la funcion generica ---
	
}

/**
 * subsSet
 *
 * Sirve para pedir datos que no esten en un campo con datafield
 *
 * @param
 * 			elementos		array		Array con nombres de las variables en el PLC
 * 			funcAcciones	function	Función que llamara cuando tenga esos datos
 *
 */
function subsSet( elementos , funcAcciones )
{
	subsFunction = funcAcciones;
	subsVars = elementos;
}

/**
 * inicio
 *
 * Cargamos los datos al principio cuando acaba de cargar la pagina y añadimos los intervalos para que se mantengan actualizados
 *
 * @param
 *
 */
function inicio()
{
	carga();
	
	// --- Actualización de datos ---
	setInterval( carga , 1000 );
	
	// --- Actualización de animaciones ---
	setInterval( animTimeout , 500 );
}


/**
 * animTimeout
 *
 * Agregamos las animaciones pertinentes a cada campo dependiendo del dataanimtype que tenga
 *
 * @param
 *
 */
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
						
						break;
					}
					
					case "display":
					{
						coll[ x ].style.display = values[ status ];
						
						break;
					}
					
					case "switch":
					{
						coll[ x ].innerHTML = values[ status ];
						break;
					}
					
					case "bgcolor":
					{
						coll [ x ].className = values [ status ];
						break;
					}
					
					/**
					 * 
					 * values[ 0 ] --> Duración
					 * values[ 1 ] --> Repeticiones(-1 = infinito)
					 * 
					 * */
					case "rotate":
					{
						// --- Tenemos asignado el GSAP al Objeto ? ---
						if (( $( coll[ x ] ).data( 'gsap' ) == undefined ) )
						{
							var objGsap = gsap.to( coll[ x ] ,
													{
														duration: values[ 0 ],
														repeat: values[ 1 ],
														rotation: "360", 
														ease: 'none',
														transformOrigin: "50% 50%",
														paused: true
													}
												);
							// --- Asignamos la animación al elemento ---
							$( coll[ x ] ).data( 'gsap' , objGsap );
						}
						
						if( status == "1" )
						{
							var objGsap = $( coll[ x ] ).data( 'gsap' );
							objGsap.play();
						}
						else
						{
							var objGsap = $( coll[ x ] ).data( 'gsap' );
							objGsap.pause();
						}


						
						
						break;
					}					
				}
				
				// --- Aqui ya tiene asignada la animacion ---
				
			}
		}
	}
}


/**
 * post
 *
 * Envio de un formulario
 *
 * @param
 * 		source		string			El id del formulario a enviar Para guardar datos en el PLC
 *
 */
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
				success: function ( data ) { console.log( data )  }
			}
		);
}

/**
 * envioVariables
 *
 * Guarda variables en el PLC
 *
 * @param
 * 		source		string			El nombre de la variable en el PLC
 * 		val			string/int		El valor de la variable que queremos guardar
 *
 */
function envioVariables( source , val )
{
	var items = {};
	items[source] = val;

	items = $.param( items );
	$.ajax(
			{
				url: "save.php",
				data: items,
				success: function ( data ) { console.log( data )  }
			}
		);
}

function enviaChecked( source )
{
	var coll = $("[datafield~='" + source + "']" );
	if( coll.prop( 'checked' ) == true )
	{
		envioVariables( source , 1 );
	}
	else
	{
		envioVariables( source , 0 );
	}
}

/**
 * OpenModal
 *
 * Abre una modal creada
 *
 * @param
 * 		idModal			string			Id de la modal que queremos modificar
 *
 */
function OpenModal( idModal )
{
	$( '#'+idModal ).show();
}

/**
 * CloseModal
 *
 * Cierra una modal abierta
 *
 * @param
 * 		idModal			string			Id de la modal que queremos modificar
 *
 */
function CloseModal( idModal )
{
	$( '#'+idModal ).hide();
}

/**
 * setTextModal
 *
 * Le cambia el texto del cuerpo a una modal creada
 *
 * @param
 * 		bodyModal		string/array	Texto que le pondremos al cuerpo de la modal creada
 * 		idModal			string			Id de la modal que queremos modificar
 * 		align			string			Alineado del texto
 *
 */
function setTextModal( bodyModal , idModal , align = 'left')
{
	modal = "#" + idModal + " .area-body";
	var body = '';
	if( Array.isArray( bodyModal ) )
	{
		for( var i = 0; i < bodyModal.length; i++)
		{
			body += "<p style='text-align:" + align + "'>" + bodyModal[i] + "</p>";
		}
	}
	else
	{
		if( bodyModal.substr(0, 1) == '[')
		{
			regex = /[\['\]]/gm;
			result = bodyModal.replace(regex, '');
			bodyModal = result.split(',');
			for( var i = 0; i < bodyModal.length; i++)
			{
				body += "<p>" + bodyModal[i] + "</p>";
			}
		}
		else
		{
			body = "<p>" + bodyModal + "</p>";
		}
	}
	$( modal ).html( body );
}

/**
 * setTitleModal
 *
 * Le cambia el titulo a una modal creada
 *
 * @param
 * 		titleModal		string			Titulo que le pondremos a la modal
 * 		idModal			string			Id de la modal que queremos modificar
 *
 */
function setTitleModal( titleModal, idModal )
{
	modal = "#" + idModal + " h2";
	$( modal ).html( titleModal );
}

/**
 * creaModal
 *
 * Crea una Modal oculta con un titulo y un ID
 *
 * @param
 * 		idModal			string			Id que le pondremos a la modal creada
 * 		titleModal		string			Titulo que le pondremos a la modal creada
 * 		bodyModal		string/array	Texto para el cuerpo de la modal, si es una array pone cada campo en un <p>
 * 		align			string			Alineado del texto
 *
 */
function creaModal( idModal , titleModal , bodyModal = '' , align = 'left')
{
	document.write(
					"<div class='modal-wrapper' id=" + idModal + ">" +
						"<div class='modal-dialog modal-dialog-grid'>" +
							"<div class='area-header'>" +
								"<button onClick=\"CloseModal( '" + idModal + "' );\">X</button>" +
								"<h2> " + titleModal + " </h2>" +
								"<span></span>" +
							"</div>" +
							"<div class='area-body ayuda-texto'>" +
							"</div>" +
						"</div>" +
					"</div>"
				);
	setTextModal( bodyModal, idModal, align );
}
