<script>
	var manualTestRelay_status = true;
	
	// --- Modal de alertas ---
	var alerta = new MODAL( 
							"alerta",
							"Alerta", 
							[
								" ‎",
								"- Se necesita Rearme.", 
								"- Comprueba si esta la seta pulsada.",
								"- Comprueba que la presión de aire está corectamente.",
								"- Comprueba que el modo Limpieza esta desactivado.",
								" ‎",
								"Si todo esta correcto y la pagina no le permite pulsar los botones On/Off, recargue la pagina."
							]
						);
		
		// --- Modal de Modo Manual ---
	var modManual = new MODAL(
							"modManual",
							"Modo Manual",
							[
								"¿Quieres activar el modo manual?",
								"<button value=\"0\" onClick=\"SCADA.sendVariables( 'Com2|scada_selector' , 1 ); modManual.closeModal( 'modManual' );\"> SI </button>"+
								"<button value=\"0\" onClick=\"SCADA.sendVariables( 'Com2|scada_selector' , 0 ); modManual.closeModal( 'modManual' );\"> NO </button>",
								"Si quieres cambiar el modo otra vez tienes un selector en la parte superior izquierda del modo manual."
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
				alerta.openModal();
			}
			
			manualTestRelay_status = false;
			SCADA.subsSet( [ "Com2|Bloqueo" ] , bloqueos  );
		}
		else
		{
			// --- Habilitar los Botones ---
			$( ".estados button" ).attr( "disabled" , false );
		}
	}
	
	SCADA.subsSet( [ "Com2|Local-2-I_Pt07_Data" ] , manualTestRelay );
	modManual.openModal();
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
				<td>Modo Manual</td> 
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_selector' , 1 )" datafield="Com2|scada_selector" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_selector' , 0 )" datafield="Com2|scada_selector" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
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
				<td>Variador 1</td> 
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ1Mot1' , 1 )" datafield="Com2|scada_PZ1Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ1Mot1' , 0 )" datafield="Com2|scada_PZ1Mot1" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
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
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ2Mot1' , 1 )" datafield="Com2|scada_PZ2Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ2Mot1' , 0 )" datafield="Com2|scada_PZ2Mot1" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Z2_mot1_activo"> 0 </td>
			</tr>
			<tr>
				<td>Variador 3 Lacadora</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ2Bomba' , 1 )" datafield="Com2|scada_PZ2Bomba" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ2Bomba' , 0 )" datafield="Com2|scada_PZ2Bomba" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
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
				<td>Variador 4 Cintas</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ3Mot1' , 1 )" datafield="Com2|scada_PZ3Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ3Mot1' , 0 )" datafield="Com2|scada_PZ3Mot1" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
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
				<td>Variador 5 Arrastre 1</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ4Mot1' , 1 )" datafield="Com2|scada_PZ4Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ4Mot1' , 0 )" datafield="Com2|scada_PZ4Mot1" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
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
				<td>Variador 6 Arrastre 2</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ5Mot1' , 1 )" datafield="Com2|scada_PZ5Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ5Mot1' , 0 )" datafield="Com2|scada_PZ5Mot1" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
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
				<td>Variador 7 Arrastre 3</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ6Mot1' , 1 )" datafield="Com2|scada_PZ6Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ6Mot1' , 0 )" datafield="Com2|scada_PZ6Mot1" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
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
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ7Mot1' , 1 )" datafield="Com2|scada_PZ7Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ7Mot1' , 0 )" datafield="Com2|scada_PZ7Mot1" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Z7_mot1_activo"> 0 </td>
			</tr>
		</table>
	</div>
	<div class="estados derecha">
		<h1 class="titulo">Estado Pistones</h1>
		<table class="interface">
				<th colspan="3">
					Zona 4
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td>Pistón 1 Vertical</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ4Pist1' , 1 )" datafield="Com2|scada_PZ4Pist1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ4Pist1' , 0 )" datafield="Com2|scada_PZ4Pist1" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Periferia-15-O_3"> 0 </td>
			</tr>
			<tr>
				<td>Pistón 2 Horizontal</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ4Pist2' , 1 )" datafield="Com2|scada_PZ4Pist2" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ4Pist2' , 0 )" datafield="Com2|scada_PZ4Pist2" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Periferia-15-O_2"> 0 </td>
			</tr>
			<tr>
				<td>Pistón 3 Arriba</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ4Pist3' , 1 )" datafield="Com2|scada_PZ4Pist3" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ4Pist3' , 0 )" datafield="Com2|scada_PZ4Pist3" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Periferia-15-O_4"> 0 </td>
			</tr>
			<tr>
				<td>Pistón 4 Abajo</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ4Pist4' , 1 )" datafield="Com2|scada_PZ4Pist4" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ4Pist4' , 0 )" datafield="Com2|scada_PZ4Pist4" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Periferia-15-O_1"> 0 </td>
			</tr>
			<tr>
				<td>Pistones 5 Laterales</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ4Pist5' , 1 )" datafield="Com2|scada_PZ4Pist5" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ4Pist5' , 0 )" datafield="Com2|scada_PZ4Pist5" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Local-3-O_Pt09_Data"> 0 </td>
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
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ5Pist1' , 1 )" datafield="Com2|scada_PZ5Pist1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ5Pist1' , 0 )" datafield="Com2|scada_PZ5Pist1" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Periferia-15-O_0"> 0 </td>
			</tr>
			<tr>
				<td>Pistón 2 Abajo</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ5Pist2' , 1 )" datafield="Com2|scada_PZ5Pist2" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ5Pist2' , 0 )" datafield="Com2|scada_PZ5Pist2" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Periferia-15-O_5"> 0 </td>
			</tr>
			<tr>
				<td>Pistones 3 Laterales</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ5Pist3' , 1 )" datafield="Com2|scada_PZ5Pist3" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ5Pist3' , 0 )" datafield="Com2|scada_PZ5Pist3" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Local-3-O_Pt10_Data"> 0 </td>
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
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ6Pist1' , 1 )" datafield="Com2|scada_PZ6Pist1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ6Pist1' , 0 )" datafield="Com2|scada_PZ6Pist1" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Periferia-15-O_6"> 0 </td>
			</tr>
			<tr>
				<td>Pistón 2 Abajo</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ6Pist2' , 1 )" datafield="Com2|scada_PZ6Pist2" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ6Pist2' , 0 )" datafield="Com2|scada_PZ6Pist2" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Local-3-O_Pt08_Data"> 0 </td>
			</tr>
			<tr>
				<td>Pistones 3 Laterales</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ6Pist3' , 1 )" datafield="Com2|scada_PZ6Pist3" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|scada_PZ6Pist3' , 0 )" datafield="Com2|scada_PZ6Pist3" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Local-3-O_Pt11_Data"> 0 </td>
			</tr>
		</table>
	</div>
	

	<div class="fondo centrado" style="left: 37.5%; top: 20;">
		<center><?= getSvg( "sheets/Images/manual.svg" ); ?></center>
	</div>
	
	<div class="accionesVel" style="left:375;">
		<div class="form">
			<h1 class="titulo"> Parametros Variadores </h1>
			<br>
			<table class= "interface">
				<tr>
					<td>
						<form method="POST" id="form2">
							<label>Velocidad Inyector Z1: </label>
							<label datafield="Com2|ValoresEscalados_Z1Inyector1_output" datafixed="0"> </label>
							<label class="unit"> Hz</label>
							<br />
							<input type ="text" name="Com2|ValoresEscalados_Z1InyectorDeseadoLimp">
							<br />
							
							<label>Velocidad Cinta Z2: </label>
							<label datafield="Com2|ValoresEscalados_Z2Cinta1_output" datafixed="0"> </label>
							<label class="unit"> Hz</label>
							<br />
							<input type ="text" name="Com2|ValoresEscalados_Z2CintaDeseadoLimp">
							<br />
						
							<label>Velocidad Bomba Z2: </label>
							<label datafield="Com2|ValoresEscalados_Z2Bomba1_output" datafixed="0"> </label>
							<label class="unit"> Hz</label>
							<br />
							<input type ="text" name="Com2|ValoresEscalados_Z2BombaDeseadoLimp">
							<br />
							
							<label>Velocidad Cinta Z3: </label>
							<label datafield="Com2|ValoresEscalados_Z3Cinta1P1_output" datafixed="0"> </label>
							<label class="unit"> Hz</label>
							<br />
							<input type ="text" name="Com2|ValoresEscalados_Z3CintaDeseadoLimp">
							<br />
							<br />
							
							<input type="submit" value="Enviar" onclick="SCADA.post( 'form2' ); return false;">
									<label> ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ </lbel>
							<input type="reset">
							
						</form>
					</td>
				</tr>
			</table>
		</div>
	</div>
	
	<div class="accionesVel" style="left:616;">
		<div class="form">
			<h1 class="titulo"> Parametros Variadores </h1>
			<br>
			<table class= "interface">
				<tr>
					<td>
						<form method="POST" id="form3">
	
							<label>Velocidad Arrastre Z4: </label>
							<label datafield="Com2|ValoresEscalados_Z4Cadena1_output" datafixed="0"> </label>
							<label class="unit"> Hz</label>
							<br />
							<input type ="text" name="Com2|ValoresEscalados_Z4CadenaDeseadoLimp">
							<br />
						
							<label>Velocidad Arrastre Z5: </label>
							<label datafield="Com2|ValoresEscalados_Z5Cadena1_output" datafixed="0"> </label>
							<label class="unit"> Hz</label>
							<br />
							<input type ="text" name="Com2|ValoresEscalados_Z5cadenaDeseadoLimp">
							<br />
							
							<label>Velocidad Arrastre Z6: </label>
							<label datafield="Com2|ValoresEscalados_Z6Cadena1_output" datafixed="0"> </label>
							<label class="unit"> Hz</label>
							<br />
							<input type ="text" name="Com2|ValoresEscalados_Z6cadenaDeseadoLimp">
							<br />
							
							<label>Velocidad Cinta Z7: </label>
							<label datafield="Com2|ValoresEscalados_Z7Cinta1_output" datafixed="0"> </label>
							<label class="unit"> Hz</label>
							<br />
							<input type ="text" name="Com2|ValoresEscalados_Z7CintaDeseadoLimp">
							<br />
							<br />
							
							<input type="submit" value="Enviar" onclick="SCADA.post( 'form3' ); return false;"> 
								<label> ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ </lbel>
							<input type="reset">

						</form>
					</td>
				</tr>
			</table>
		</div>
	</div>
</div>
