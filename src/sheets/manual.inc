<script>
	var manualTestRelay_status = true;
	
	// --- Modal de alertas ---
	creaModal( 
				"alerta",
				"Alerta", 
				[
					"Se necesita Rearme.", 
					"Comprueba si esta la seta pulsada.",
					"Comprueba que la presión de aire está bien."
				]
			);
	
	// --- Modal de Modo Manual ---
	creaModal(
				"modManual",
				"Modo Manual",
				[
					"¿Quieres activar el modo manual?",
					"<button value=\"0\" onClick=\"envioVariables( 'Com2|scada_selector' , 1 ); CloseModal( 'modManual' );\"> SI </button>"+
					"<button value=\"0\" onClick=\"envioVariables( 'Com2|scada_selector' , 0 ); CloseModal( 'modManual' );\"> NO </button>",
					"Si quieres cambiar el modo otra vez tienes un selector en la parte superior del modo manual."
				],
				'center'
			);
	
	function manualTestRelay( data )
	{
		// --- Comprobar el Rele de Seguridad ---
		if ( data['Com2|Local-2-I_Pt07_Data'] == 0 )
		{
			// --- Desabilita los Botones ---
			$( ".estados button" ).attr( "disabled" , true );
			
			if ( manualTestRelay_status )
			{
				// --- Pintar alerta ---
				OpenModal( "alerta" );
			}
			
			manualTestRelay_status = false;
			
		}
		else
		{
			// --- Habilitar los Botones ---
			$( ".estados button" ).attr( "disabled" , false );
		}
	}
	
	subsSet( ["Com2|Local-2-I_Pt07_Data"] , manualTestRelay );
	OpenModal( 'modManual' );
</script>

<div class="main">
	<div class="estados">
		<h1 class="titulo">Estado Variadores</h1>
		<table class="interface">
			<tr>
				<th colspan="3">
					Selector
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td>Manual</td> 
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_selector' , 1 )" datafield="Com2|scada_selector" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_selector' , 0 )" datafield="Com2|scada_selector" dataanimvalues="on;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|scada_selector"> 0 </td>
			</tr>
			<tr>
				<th colspan="3">
					Zona 1
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td>Variador1</td> 
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ1Mot1' , 1 )" datafield="Com2|scada_PZ1Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ1Mot1' , 0 )" datafield="Com2|scada_PZ1Mot1" dataanimvalues="on;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Z1_mot1_activo"> 0 </td>
			</tr>	
			<tr>	
				<th colspan="3">
					Zona 2
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td>Variador 2 Cinta</td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ2Mot1' , 1 )" datafield="Com2|scada_PZ2Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ2Mot1' , 0 )" datafield="Com2|scada_PZ2Mot1" dataanimvalues="on;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Z2_mot1_activo"> 0 </td>
			</tr>
			<tr>
				<td>Variador 3 Lacadora</td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ2Bomba' , 1 )" datafield="Com2|scada_PZ2Bomba" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ2Bomba' , 0 )" datafield="Com2|scada_PZ2Bomba" dataanimvalues="on;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Z2_bomba_activo"> 0 </td>
			</tr>
			<tr>
				<th colspan="3">
					Zona 3
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td>Variador 4</td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ3Mot1' , 1 )" datafield="Com2|scada_PZ3Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ3Mot1' , 0 )" datafield="Com2|scada_PZ3Mot1" dataanimvalues="on;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Z3_mot1_activo"> 0 </td>
			</tr>
			<tr>
				<th colspan="3">
					Zona 4
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td>Variador 5 Arrastre1</td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ4Mot1' , 1 )" datafield="Com2|scada_PZ4Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ4Mot1' , 0 )" datafield="Com2|scada_PZ4Mot1" dataanimvalues="on;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Z4_mot1_activo"> 0 </td>
			</tr>
			<tr>
				<th colspan="3">
					Zona 5
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td>Variador 6 Arrastre2</td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ5Mot1' , 1 )" datafield="Com2|scada_PZ5Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ5Mot1' , 0 )" datafield="Com2|scada_PZ5Mot1" dataanimvalues="on;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Z5_mot1_activo"> 0 </td>
			</tr>
				<tr>
				<th colspan="3">
					Zona 6
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td>Variador 7 Arrastre3</td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ6Mot1' , 1 )" datafield="Com2|scada_PZ6Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ6Mot1' , 0 )" datafield="Com2|scada_PZ6Mot1" dataanimvalues="on;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Z6_mot1_activo"> 0 </td>
			</tr>
				<tr>
				<th colspan="3">
					Zona 7
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td>Variador 8</td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ7Mot1' , 1 )" datafield="Com2|scada_PZ7Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ7Mot1' , 0 )" datafield="Com2|scada_PZ7Mot1" dataanimvalues="on;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Z7_mot1_activo"> 0 </td>
			</tr>
		</table>
	</div>
	<div class="estados derecha">
		<h1 class="titulo">Estado Pistones</h1>
		<table class="interface">
			<tr>
				<th colspan="3">
					Selector
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td>Manual</td> 
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_selector' , 1 )" datafield="Com2|scada_selector" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_selector' , 0 )" datafield="Com2|scada_selector" dataanimvalues="on;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|scada_selector"> 0 </td>
			</tr>
			<tr>
				<th colspan="3">
					Zona 4
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td>Pistón 1 Vertical</td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ4Pist1' , 1 )" datafield="Com2|scada_PZ4Pist1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ4Pist1' , 0 )" datafield="Com2|scada_PZ4Pist1" dataanimvalues="on;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Periferia-15-O_2"> 0 </td>
			</tr>
			<tr>
				<td>Pistón 2 Horizontal</td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ4Pist2' , 1 )" datafield="Com2|scada_PZ4Pist2" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ4Pist2' , 0 )" datafield="Com2|scada_PZ4Pist2" dataanimvalues="on;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Periferia-15-O_3"> 0 </td>
			</tr>
			<tr>
				<td>Pistón 3 Arriba</td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ4Pist3' , 1 )" datafield="Com2|scada_PZ4Pist3" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ4Pist3' , 0 )" datafield="Com2|scada_PZ4Pist3" dataanimvalues="on;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Periferia-15-O_4"> 0 </td>
			</tr>
			<tr>
				<td>Pistón 4 Abajo</td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ4Pist4' , 1 )" datafield="Com2|scada_PZ4Pist4" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ4Pist4' , 0 )" datafield="Com2|scada_PZ4Pist4" dataanimvalues="on;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Periferia-15-O_5"> 0 </td>
			</tr>
			<tr>
				<th colspan="3">
					Zona 5
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td>Pistón 1 Arriba</td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ5Pist1' , 1 )" datafield="Com2|scada_PZ5Pist1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ5Pist1' , 0 )" datafield="Com2|scada_PZ5Pist1" dataanimvalues="on;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Periferia-15-O_0"> 0 </td>
			</tr>
			<tr>
				<td>Pistón 2 Abajo</td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ5Pist2' , 1 )" datafield="Com2|scada_PZ5Pist2" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ5Pist2' , 0 )" datafield="Com2|scada_PZ5Pist2" dataanimvalues="on;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = ""> 0 </td>
			</tr>
				<tr>
				<th colspan="3">
					Zona 6
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td>Pistón 1 Arriba</td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ6Pist1' , 1 )" datafield="Com2|scada_PZ6Pist1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ6Pist1' , 0 )" datafield="Com2|scada_PZ6Pist1" dataanimvalues="on;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = ""> 0 </td>
			</tr>
			<tr>
				<td>Pistón 2 Abajo</td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ6Pist2' , 1 )" datafield="Com2|scada_PZ6Pist2" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="envioVariables( 'Com2|scada_PZ6Pist2' , 0 )" datafield="Com2|scada_PZ6Pist2" dataanimvalues="on;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = ""> 0 </td>
			</tr>
		</table>
	</div>
	<div class="fondo centrado">
		<center><?= getSvg( "sheets/Images/manual.svg" ); ?></center>
	</div>
	
</div>
