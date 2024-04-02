<script src="http://code.jquery.com/jquery-latest.js"></script>

<script>
	/**
	 * @brief 	Archivo de funciones en Javascript
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
	var SCADA = {
					subsFunction: null,  	/**< Funcion que llama al actualizar */
					subsVars: null,		/**< Variables que se añaden al actualizar */
					
					
					/**
					 * load
					 *
					 * Se encarga de recoger los campos de datafield y hacer una consulta con ellos para sacar los valores de redis
					 *
					 * @param
					 *
					 */
					load()
					{
						// --- Carga todos los Campos a Actualizar ---
						var col = $( "[datafield]" );
						
						var vars = "";
						
						for( var index = 0; index < col.length; index++ )
						{
							vars = vars + col[ index ].getAttribute( "datafield" ) + "&";
						}
						
						// --- Añadimos las variables que tenemos suscritas ---
						if ( SCADA.subsVars !== null )
						{
							if( Array.isArray( SCADA.subsVars ))
							{
								for( var i = 0; i < SCADA.subsVars.length; i++ )
								{
									vars = vars + SCADA.subsVars[ i ] + "&";
								}
							}
						}
						
						vars = vars.replace( /&+/gm , '&' );
						vars = vars.replace( /&+$/gm , '' );
						
						// --- Peticion AJAX ---
						$.ajax(
								{
									url: "<?= BUFFER ?>",
									data: vars,
					//				dataType: "json",
									success: function ( result ) { SCADA.refresh( result ); }
								}
							);
					},
					
					/**
					 * refresh
					 *
					 * Se encarga de poner los datos en sus correspondientes sitios que coincidan con el datafield
					 *
					 * @param
					 * 		result		array		Array asociativo en el que estan los nombres de las variables y los valores
					 *
					 */
					refresh( result )
					{
						// --- Actualizamos los campos ---
						$.each( result, function( key, val )
								{
									// --- Buscamos todos los Objetos del DOM que tienen ese DATAFIELD ---
									var coll = $( "[datafield~='" + key + "']" );
									
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
						if ( typeof this.subsFunction == "function" )
						{
							var valores = {};
							$.each( result, function( key, val )
								{
									for( var i = 0 ; i < SCADA.subsVars.length ; i++ )
									{
										if( SCADA.subsVars[i] == key )
										{
											valores[ key ] =  val;
										}
									}
								}
							);
							this.subsFunction( valores );
						}
						
						// --- Vamos a la funcion generica ---
					},
					
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
					subsSet( elementos , funcAcciones )
					{
						this.subsFunction = funcAcciones;
						this.subsVars = elementos;
						
					},
					
					
				
					/**
					 * inicio
					 *
					 * Cargamos los datos al principio cuando acaba de cargar la pagina y añadimos los intervalos para que se mantengan actualizados
					 *
					 * @param
					 *
					 */
					inicio()
					{
						this.load();
						
						// --- Actualización de datos ---
						setInterval( this.load , 1000 );
						
						// --- Actualización de animaciones ---
						setInterval( this.animTimeout , 500 );
					},
					
					/**
					 * animTimeout
					 *
					 * Agregamos las animaciones pertinentes a cada campo dependiendo del dataanimtype que tenga
					 *
					 * @param
					 *
					 */
					animTimeout()
					{
						// --- Recogemos todos los campos con datafield ---
						var coll = $( "[datafield]" );
						
						for( x = 0 ; x < coll.length ; x++ )
						{
							var status = $( coll[ x ] ).attr( "value" ) ;
							
							// --- Solo ejecuta si tiene Valor ---
							if ( status != undefined )
							{
								var type = $( coll[ x ] ).attr( "dataanimtype" ) ;
								
								if ( type != undefined )
								{
									var values = $( coll[ x ] ).attr( "dataanimvalues" ) ;
									
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
					},
					
					/**
					 * post
					 *
					 * Envio de un formulario
					 *
					 * @param
					 * 		source		string			El id del formulario a enviar Para guardar datos en el PLC
					 *
					 */
					post( source )
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
					},

					/**
					 * sendVariables
					 *
					 * Guarda variables en el PLC
					 *
					 * @param
					 * 		source		string			El nombre de la variable en el PLC
					 * 		val			string/int		El valor de la variable que queremos guardar
					 *
					 */
					sendVariables( source , val )
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
					},
					
					/**
					 * sendChecked
					 *
					 * Cambia el estado de un checkbox al pulsarlo
					 *
					 * @param
					 * 		source		string			El datafield del checkbox
					 *
					 */
					sendChecked( source )
					{
						var coll = $( "[datafield~='" + source + "']" );
						if( coll.prop( 'checked' ) == true )
						{
							this.sendVariables( source , 1 );
						}
						else
						{
							this.sendVariables( source , 0 );
						}
					}
				};
</script>
