<script>
	// --- Esta es la funcion que se hace cargo de procesar los datos ---
	function manualSub( datos )
	{
		if ( datos['SERVER|timestamp'].slice( 0 , 7 ) == '09:10:0' )
		{
			alert( "Vamos a tomar cafe!!!" );
		}
	}
	
	// --- Suscribimos la funcion ---
	subsSet( [ "SERVER|timestamp" ] , manualSub );
</script>

<div class="main">
	<div class="estados">
		<h1 class="titulo">Estado</h1>
		<table>
			<tr>
				<th class="titulosz" colspan="4">
					Selector
				</th>
				<th class="titulosz">
					Estado
				</th>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Manual</td> 
				<td><button onClick="envioVariables( 'Com2|scada_selector' , 1 )" type="button">Activado</button></td>
				<td><button onClick="envioVariables( 'Com2|scada_selector' , 0 )" type="button">Desactivado</button></td>
				<td class="numero" datafield = "Com2|scada_selector"> 0 </td>
			</tr>
			<tr>
				<th class="titulosz" colspan="4">
					Zona 1
				</th>
				<th class="titulosz">
					Estado
				</th>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Variador 1</td> 
				<td><button onClick="envioVariables( 'Com2|scada_PZ1Mot1' , 1 )" type="button">Marcha</button></td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ1Mot1' , 0 )" type="button"> Paro </button></td>
				<td class="numero" datafield = "Com2|Z1_mot1_activo"> 0 </td>
			</tr>	
			<tr>	
				<th class="titulosz" colspan="4">
					Zona 2
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Variador 2</td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ2Mot1' , 1 )" type="button">Marcha</button></td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ2Mot1' , 0 )" type="button"> Paro </button></td>
				<td class="numero" datafield = "Com2|Z2_mot1_activo"> 0 </td>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Variador 3 Bomba</td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ2Bomba' , 1 )" type="button">Marcha</button></td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ2Bomba' , 0 )" type="button"> Paro </button></td>
				<td class="numero" datafield = "Com2|Z2_bomba_activo"> 0 </td>
			</tr>
			<tr>
				<th class="titulosz" colspan="4">
					Zona 3
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Variador 4</td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ3Mot1' , 1 )" type="button">Marcha</button></td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ3Mot1' , 0 )" type="button"> Paro </button></td>
				<td class="numero" datafield = "Com2|Z3_mot1_activo"> 0 </td>
			</tr>
			<tr>
				<th class="titulosz" colspan="4">
					Zona 4
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Variador 5</td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ4Mot1' , 1 )" type="button">Marcha</button></td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ4Mot1' , 0 )" type="button"> Paro </button></td>
				<td class="numero" datafield = "Com2|Z4_mot1_activo"> 0 </td>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Pistón 1</td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ4Pist1' , 1 )" type="button">Marcha</button></td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ4Pist1' , 0 )" type="button"> Paro </button></td>
				<td class="numero" datafield = "Com2|Periferia-15-O_3"> 0 </td>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Pistón 2</td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ4Pist2' , 1 )" type="button">Marcha</button></td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ4Pist2' , 0 )" type="button"> Paro </button></td>
				<td class="numero" datafield = "Com2|Periferia-15-O_2"> 0 </td>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Pistón 3</td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ4Pist3' , 1 )" type="button">Marcha</button></td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ4Pist3' , 0 )" type="button"> Paro </button></td>
				<td class="numero" datafield = "Com2|Periferia-15-O_4"> 0 </td>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Pistón 4</td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ4Pist4' , 1 )" type="button">Marcha</button></td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ4Pist4' , 0 )" type="button"> Paro </button></td>
				<td class="numero" datafield = "Com2|Periferia-15-O_5"> 0 </td>
			</tr>
			<tr>
				<th class="titulosz" colspan="4">
					Zona 5
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Variador 6</td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ5Mot1' , 1 )" type="button">Marcha</button></td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ5Mot1' , 0 )" type="button"> Paro </button></td>
				<td class="numero" datafield = "Com2|Z5_mot1_activo"> 0 </td>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Pistón 1</td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ5Pist1' , 1 )" type="button">Marcha</button></td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ5Pist1' , 0 )" type="button"> Paro </button></td>
				<td class="numero" datafield = "Com2|Periferia-15-O_0"> 0 </td>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Pistón 2</td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ5Pist2' , 1 )" type="button">Marcha</button></td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ5Pist2' , 0 )" type="button"> Paro </button></td>
				<td class="numero" datafield = ""> 0 </td>
			</tr>
				<tr>
				<th class="titulosz" colspan="4">
					Zona 6
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Variador 7</td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ6Mot1' , 1 )" type="button">Marcha</button></td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ6Mot1' , 0 )" type="button"> Paro </button></td>
				<td class="numero" datafield = "Com2|Z6_mot1_activo"> 0 </td>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Pistón 1</td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ6Pist1' , 1 )" type="button">Marcha</button></td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ6Pist1' , 0 )" type="button"> Paro </button></td>
				<td class="numero" datafield = ""> 0 </td>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Pistón 2</td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ6Pist2' , 1 )" type="button">Marcha</button></td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ6Pist2' , 0 )" type="button"> Paro </button></td>
				<td class="numero" datafield = ""> 0 </td>
			</tr>
				<tr>
				<th class="titulosz" colspan="4">
					Zona 7
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Variador 8</td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ7Mot1' , 1 )" type="button">Marcha</button></td>
				<td><button onClick="envioVariables( 'Com2|scada_PZ7Mot1' , 0 )" type="button"> Paro </button></td>
				<td class="numero" datafield = "Com2|Z7_mot1_activo"> 0 </td>
			</tr>
		</table>
	</div>
	<div class="imagen" style="border:1px solid; padding:10px;">
		<?= getSvg( "sheets/Images/manual.svg" ); ?>
	</div>
</div>
