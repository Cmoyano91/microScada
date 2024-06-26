<div class="main">
	<div class="datos">
		<br>
		<div class="estados"  style="position:relative;" >	
			<h1 class="titulo"> Zona 2 </h1>
			<table class= "interface">
				<tr>	
					<th colspan="2" >
						Motores
					</th>
				</tr>
				<tr>
					<td class="subtitulosz" colspan="2">
						Cinta 1
					</td>
				</tr>
				<tr>
					<td>Motor Cinta Activo</td>
					<td class="value">
						<span datafield="Com2|Z2_mot1_activo">0</span>
					</td>
				</tr>
				<tr>
					<td>Velocidad Cinta</td>
					<td class="value">
						<span datafield="Com2|ValoresEscalados_Z2Cinta1Actual_output" datafixed="0">0</span><span class="unit"> Hz</span>
					</td>
				</tr>
				<tr>
					<td class="subtitulosz" colspan="2">
						Cinta 2
					</td>
				</tr>
				<tr>
					<td>Motor Cinta Activo</td>
					<td class="value">
						<span datafield="Com2|Z2_mot2_activo">0</span>
					</td>
				</tr>
				<tr>
					<td>Velocidad Cinta</td>
					<td class="value">
						<span datafield="Com2|ValoresEscalados_Z2Cinta2Actual_output" datafixed="0">0</span><span class="unit"> Hz</span>
					</td>
				</tr>
				<tr>
					<td class="subtitulosz" colspan="2">
						Lacadora
					</td>
				</tr>
				<tr>
					<td>Motor Lacadora Activo</td>
					<td class="value">
						<span datafield="Com2|Z2_Bomba_activo">0</span>
					</td>
				</tr>
				<tr>
					<td>Velocidad Lacadora</td>
					<td class="value">
						<span datafield="Com2|ValoresEscalados_Z2BombaActual_output" datafixed="0">0</span><span class="unit"> Hz</span>
					</td>
				</tr>
				<tr>
					<th colspan="2">
						Temperatura
					</th>
				</tr>
				<tr>
					<td>Temperatura del Producto</td>
					<td class="value">
						<span datafield="Com2|ValoresEscalados_scpTemp1_Output" datafixed="1">0</span><span class="unit"> ºC</span>
					</td>
				</tr>
				<tr>
					<th colspan="2">
						Viscosidad
					</th>
				</tr>
				<tr>
					<td>Viscosidad del Producto</td>
					<td class="value">
						<span datafield="Com2|resul_viscosidad">0</span><span class="unit"> η</span>
					</td>
				</tr>
			</table>
		</div>
	</div>
	<div class="datos">
		<div class="estados" >
			<h1 class="titulo"> Zona 3 </h1>
			<table class= "interface">
				<tr>	
					<th colspan="2">
						Motor
					</th>
				</tr>
				<tr>
					<td class="subtitulosz" colspan="2">
						Cinta 1
					</td>
				</tr>
				<tr>
					<td>Motor Cinta Activo</td>
					<td class="value">
						<span datafield="Com2|Z3_mot1_activo">0</span>
					</td>
				</tr>
				<tr>
					<td>Velocidad Cinta</td>
					<td class="value">
						<span datafield="Com2|ValoresEscalados_Z3Cinta1P1_output" datafixed="0">0</span><span class="unit"> Hz</span>
					</td>
				</tr>
				<tr>
					<td class="subtitulosz" colspan="2">
						Cinta 2
					</td>
				</tr>
				<tr>
					<td>Motor Cinta  Activo</td>
					<td class="value">
						<span datafield="Com2|Z3_mot2_activo">0</span>
					</td>
				</tr>
				<tr>
					<td>Velocidad Cinta </td>
					<td class="value">
						<span datafield="Com2|ValoresEscalados_Z3Cinta1P2_output" datafixed="0">0</span><span class="unit"> Hz</span>
					</td>
					<tr>
					<td class="subtitulosz" colspan="2">
						Cinta 3
					</td>
				</tr>
					<tr>
					<td>Motor Cinta  Activo</td>
					<td class="value">
						<span datafield="Com2|Z3_mot3_activo">0</span>
					</td>
				</tr>
				<tr>
					<td>Velocidad Cinta</td>
					<td class="value">
						<span datafield="Com2|ValoresEscalados_Z3Cinta1P3_output" datafixed="0">0</span><span class="unit"> Hz</span>
					</td>
				</tr>
				</tr>
			</table>
		</div>
	</div>
		<div class="fondo" style="left: 35%; top: 35;">
			<?= getSvg( "sheets/Images/Zona2Zona3.svg" ); ?>	
		</div>
</div>
