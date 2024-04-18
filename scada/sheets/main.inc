<script>
	var conf = new MODAL(
						"conf", 
						"Confirmación",
						[
							"¿Seguro que quieres poner a 0 los contadores?",
							"<button onClick=\"setTimeout( function() { SCADA.sendVariables( 'Com2|ResetContadores' , 0 ) }, 2000 ); SCADA.sendVariables( 'Com2|ResetContadores' , 1 );conf.closeModal();\">Si</button>"+
							"<button onClick=\"conf.closeModal();\">No</button>"
						],
						'center'
					);
					
	var vaci = new MODAL(
						"vaci", 
						"Confirmación",
						[
							"¿Seguro que quieres vaciar las cabinas?",
							"<button onClick=\"setTimeout( function() { SCADA.sendVariables( 'Com2|Vaciado_Button' , 0 ) }, 2000 ); SCADA.sendVariables( 'Com2|Vaciado_Button' , 1 );vaci.closeModal();\">Si</button>"+
							"<button onClick=\"vaci.closeModal();\">No</button>"
						],
						'center'
					);
</script>


<div class="main">
	<div class="estados">
		<h1 class="titulo">Estado</h1>
		<br>
		<table class= "interface">
			<tr>
				<th>
					General
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td>Relé de Seguridad</td> 
				<td class="value">
					<span datafield="Com2|Local-2-I_Pt07_Data">Rele.Ok</span>
				</td>
			</tr>
			<tr>
			<tr>
				<td>Zona superior</td> 
				<td class="value">
					<span datafield="Com2|Seg_ZonaSuperiorOk">Seg.Ok</span>
				</td>
			</tr>
			<tr>
				<th>
					Zona 1
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td>Variador 1</td> 
				<td class="value">
					<span datafield="Com2|Z1_mot1_ready">V1.ok</span>
				</td>
			</tr>	
			<tr>	
				<th>
					Zona 2
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td>Variador 2 Cinta</td>
				<td class="value">
					<span datafield="Com2|Z2_mot1_ready">V2.ok</span>
				</td>
			</tr>
			<tr>
				<td>Variador 3 Lacadora</td>
				<td class="value">
					<span datafield="Com2|Z2_bomba_ready">Bomba.ok</span>
				</td>
			</tr>
			<tr>
				<th>
					Zona 3
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td>Variador 4 </td>
				<td class="value">
					<span datafield="Com2|Z3_mot1_ready">V3.ok</span>
				</td>
			</tr>
			<tr>
				<th>
					Zona 4
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td>Variador 5 Arrastre 1</td>
				<td class="value">
					<span datafield="Com2|Z4_mot1_ready">V4.ok</span>
				</td>
			</tr>
			<tr>
				<th>
					Zona 5
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td>Variador 6 Arrastre 2</td>
				<td class="value">
					<span datafield="Com2|Z5_mot1_ready"> V5.ok</span>
				</td>
			</tr>
				<tr>
				<th>
					Zona 6
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td>Variador 7 Arrastre 3</td>
				<td class="value">
					<span datafield="Com2|Z6_mot1_ready"> V6.ok</span>
				</td>
			</tr>
				<tr>
				<th>
					Zona 7
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td>Variador 8</td>
				<td class="value">
					<span datafield="Com2|Z7_mot1_ready"> V7.ok</span>
				</td>
			</tr>
		</table>
	</div>

	<div class="fondo">
		<?= getSvg( "sheets/Images/esqueleto.svg" ); ?>
		
	</div>

	<div class="acciones">
		<div class="form">
			<h1 class="titulo"> Parametros Zona 2 </h1>
			<br>
			<table class= "interface">
				<tr>
					<td>
						<form method="POST" id="form1">
							<label>Velocidad Cinta: </label>
							<label datafield="Com2|cons_VelCintaZ2"> </label>
							<br />
							<input type ="text" name="Com2|VelocidadCinta">
							<br />

							<label>Velocidad Bomba: </label>
							<label datafield="Com2|cons_VelBombaZ2"> </label>
							<br />
							<input type ="text" name="Com2|VelocidadBomba">
							<br />
							
							<label>Temperatura:</label>
							<label datafield="Com2|cons_Temp"> </label>
							<br />
							<input type ="text" name="Com2|cons_Temp"> 
							<input type="checkbox" value = "1" name="Com2|Scada_selTemp" datafield="Com2|Scada_selTemp" onClick="SCADA.sendChecked( 'Com2|Scada_selTemp' )">
						
							<br />
						
							<label>Viscosidad:</label>
							<label datafield="Com2|cons_Dens" > </label>
							<br />
							<input type ="text" name="Com2|cons_Dens">
							<input type="checkbox" value = "1" name="Com2|Scada_selVisc" datafield="Com2|Scada_selVisc"  onClick="SCADA.sendChecked( 'Com2|Scada_selVisc' )">
					
							<br />
							<input type="submit" value="Enviar" onclick="SCADA.post( 'form1' ); return false;">
								<label> ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ </lbel>
							<input type="reset">
							
						</form>
					</td>
				</tr>
			</table>
		</div>
		
		<div class="form">
			<h1 class="titulo"> Conteo de almacenaje </h1>
			<br />
			<table class= "interface">
				<tr>
					<th>
						Almacen 1
					</th>
				</tr>
				<tr>
					<td class="value">
						&nbsp;
						<span datafield="Com2|Z4_DiscosDentro">0</span>
					</td>
				</tr>
				<tr>
					<th>
						Almacen 2
					</th>
				</tr>
				<tr>
					<td class="value">
						&nbsp;
						<span datafield="Com2|Z5_DiscosDentro">0</span>
					</td>
				</tr>
				<tr>
					<th>
						Almacen 3
					</th>
				</tr>
				<tr>
					<td class="value">
						&nbsp;
						<span datafield="Com2|Z6_DiscosDentro">0</span>
					</td>
				</tr>
			</table>
			<div>
			<br />
				<button onClick="vaci.openModal();">Vaciar</button>
				<button onClick="conf.openModal();">Reset Contadores</button>
			</div>
		</div>
		

	</div>
	
	<div class="estados derecha" style="width:200px">
		<h1 class="titulo">Estado Zona Superior</h1>
		<table class="interface">
		<tr>
				<th>
					Marcha
				</th>
				<th>
					paro
				</th>
				<th>
					Estado
				</th>
			</tr>
			<th colspan="3">
					ventilazion
				</th>
			<tr>

			<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Seg_VentilacionStart' , 1 )" datafield="Com2|Seg_VentilacionStart" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
			<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Seg_VentilacionStart' , 0 )" datafield="Com2|Seg_VentilacionStart" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
				
			<td class="value" datafield = "Com2|Periferia-17-O_0"> 0 </td>
			</tr>
			<tr>
				<th colspan="3">
					Aspiracion
				</th>
			<tr>

			<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Seg_AspiracionStart' , 1 )" datafield="Com2|Seg_AspiracionStart" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
			<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Seg_AspiracionStart' , 0 )" datafield="Com2|Seg_AspiracionStart" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
			
				<td class="value" datafield = "Com2|Periferia-17-O_1"> 0 </td>
			</tr>
			<tr>
				<th colspan="3">
					Calefaccion
				</th>
			<tr>

			<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Seg_CalefaccionStart' , 1 )" datafield="Com2|Seg_CalefaccionStart" dataanimvalues="off;on" dataanimtype="bgcolor"> On </button></td>
			<td class="action"><button value="0" onClick="SCADA.sendVariables( 'Com2|Seg_CalefaccionStart' , 0 )" datafield="Com2|Seg_CalefaccionStart" dataanimvalues="on2;off" dataanimtype="bgcolor"> Off </button></td>
			
			
				<td class="value" datafield = "Com2|Periferia-18-O_7"> 0 </td>
			</tr>
		</table>
		
</div>
