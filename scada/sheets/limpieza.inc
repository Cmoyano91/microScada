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
								"- Comprueba que el modo Manual esta activado.",
								" ‎",
								"Si todo esta correcto y la pagina no le permite pulsar los botones On/Off, recargue la pagina."
							]
						);
		
		// --- Modal de Modo Manual ---
	var modLimp = new MODAL(
							"modLimp",
							"Modo Limpieza",
							[
								"¿Quieres activar el modo de Limpieza?",
								"<button value=\"0\" onClick=\"SCADA.sendVariables( 'Com2|limp_limpieza' , 1 ); modLimp.closeModal( 'modLimp' );\"> SI </button>"+
								"<button value=\"0\" onClick=\"SCADA.sendVariables( 'Com2|limp_limpieza' , 0 ); modLimp.closeModal( 'modLimp' );\"> NO </button>",
								"Si quieres cambiar el modo otra vez tienes un selector en la parte superior izquierda del modo Limpieza."
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
	modLimp.openModal();
	
		

</script>




<div class="main">
	<div class="estados">
		<h1 class="titulo">Estado Variadores Cinta</h1>
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
				<td>Modo Limpieza</td> 
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Limp_Limpieza' , 1 )" datafield="Com2|Limp_Limpieza" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Limp_Limpieza' , 0 )" datafield="Com2|Limp_Limpieza" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Limp_Limpieza"> 0 </td>
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
				<td>Variador Z1</td> 
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Limp_PZ1Mot1' , 1 )" datafield="Com2|Limp_PZ1Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Limp_PZ1Mot1' , 0 )" datafield="Com2|Limp_PZ1Mot1" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
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
				<td>Variador Z2 Cinta</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Limp_PZ2Mot1' , 1 )" datafield="Com2|Limp_PZ2Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Limp_PZ2Mot1' , 0 )" datafield="Com2|Limp_PZ2Mot1" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Z2_mot1_activo"> 0 </td>
			</tr>
			<tr>
				<td>Variador Z2 Lacadora</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Limp_PZ2Bomba' , 1 )" datafield="Com2|Limp_PZ2Bomba" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Limp_PZ2Bomba' , 0 )" datafield="Com2|Limp_PZ2Bomba" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
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
				<td>Variadores Z3</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Limp_PZ3Mot1' , 1 )" datafield="Com2|Limp_PZ3Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Limp_PZ3Mot1' , 0 )" datafield="Com2|Limp_PZ3Mot1" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="value" datafield = "Com2|Z3_mot1_activo"> 0 </td>
			</tr>
		</table>
		
		<div class="accioneslimpieza" style= "right:41px;" >
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
							<label datafield="Com2|ValoresEscalados_Z3Cinta1_output" datafixed="0"> </label>
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
	</div>

	<div class="fondo" Style="left:30.5%; top:70px;">
		<?= getSvg( "sheets/Images/limpieza.svg" ); ?>
	</div>
	
	
	
<div class="estados derecha">
		<h1 class="titulo">Estado Variadores cadena</h1>
		<table class="interface">
				<th colspan="4">
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
				<td></td>
				<td class="value" datafield = "Com2|scada_selector"> 0 </td>
			</tr>
				<tr>
				<th colspan="3">
					Zona 4
				</th>
				<th>
				Ciclo
				</th>
				<th>
					Estado
				</th>
			</tr>
			<tr>
				<td>Variador Z4 Arrastre 1</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Limp_PZ4Mot1' , 1 )" datafield="Com2|Limp_PZ4Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Limp_PZ4Mot1' , 0 )" datafield="Com2|Limp_PZ4Mot1" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="action">
				<button value="0" 
				onmousedown="SCADA.sendVariables( 'Com2|Limp_PZ4Mot1Movimiento' , 1 )"
				onmouseup="SCADA.sendVariables( 'Com2|Limp_PZ4Mot1Movimiento' , 0 )"
				datafield="Com2|Limp_PZ4Mot1Movimiento" dataanimvalues="off;on" 
				dataanimtype="bgcolor">
				</button></td>

				<td class="value" datafield = "Com2|Z4_mot1_activo"> 0 </td>
			</tr>
			<tr>
				<th colspan="3">
					Zona 5
				<th>
				Ciclo
				</th>
				<th>
					Estado
				</
			</tr>
			<tr>
				<td>Variador Z5 Arrastre 2</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Limp_PZ5Mot1' , 1 )" datafield="Com2|Limp_PZ5Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Limp_PZ5Mot1' , 0 )" datafield="Com2|Limp_PZ5Mot1" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="action">
				<button value="0" 
				onmousedown="SCADA.sendVariables( 'Com2|Limp_PZ5Mot1Movimiento' , 1 )"
				onmouseup="SCADA.sendVariables( 'Com2|Limp_PZ5Mot1Movimiento' , 0 )"
				datafield="Com2|Limp_PZ5Mot1Movimiento" dataanimvalues="off;on" 
				dataanimtype="bgcolor">
				<td class="value" datafield = "Com2|Z5_mot1_activo"> 0 </td>
			</tr>
				<tr>
				<th colspan="3">
					Zona 6
				</th>
				<th>
				Ciclo
				</th>
				<th>
					Estado
				</
			</tr>
			<tr>
				<td>Variador Z6 Arrastre 3</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Limp_PZ6Mot1' , 1 )" datafield="Com2|Limp_PZ6Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Limp_PZ6Mot1' , 0 )" datafield="Com2|Limp_PZ6Mot1" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td class="action">
				<button value="0" 
				onmousedown="SCADA.sendVariables( 'Com2|Limp_PZ6Mot1Movimiento' , 1 )"
				onmouseup="SCADA.sendVariables( 'Com2|Limp_PZ6Mot1Movimiento' , 0 )"
				datafield="Com2|Limp_PZ6Mot1Movimiento" dataanimvalues="off;on" 
				dataanimtype="bgcolor">
				<td class="value" datafield = "Com2|Z6_mot1_activo"> 0 </td>
			</tr>
						<tr>
				<th colspan="4">
					Zona 7
				</th>
				
				<th>
					Estado
				</
			</tr>
			<tr>
				<td>Variador Z7</td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Limp_PZ7Mot1' , 1 )" datafield="Com2|Limp_PZ7Mot1" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
				<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Limp_PZ7Mot1' , 0 )" datafield="Com2|Limp_PZ7Mot1" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				<td></td>
				<td class="value" datafield = "Com2|Z7_mot1_activo"> 0 </td>
			</tr>
		</table>
		
	<div class="accioneslimpieza" style= "top:445px; left:51.5px;">
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
							<input type ="text" name="Com2|ValoresEscalados_Z4cadenaDeseadoLimp">
							<br />
						
							<label>Velocidad Arrastre Z5: </label>
							<label datafield="Com2|ValoresEscalados_Z5Cadena1_output" datafixed="0"> </label>
							<label class="unit"> Hz</label>
							<br />
							<input type ="text" name="="Com2|ValoresEscalados_Z5cadenaDeseadoLimp">
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

	</div>
	
	
	