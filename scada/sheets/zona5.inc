<div class="main">
	
	<div class="datos">
		<div class="estados">	
			<h1 class="titulo"> Zona 5 </h1>
			<table class= "interface">
				<tr>	
					<th colspan="2">
						Motor
					</th>
				</tr>
				<tr>
					<td>Motor Arrastre Activo</td>
					<td class="value">
						<span datafield="Com2|Z5_mot1_activo">0</span>
					</td>
				</tr>
				<tr>
					<td>Velocidad Arrastre</td>
					<td class="value">
						<span datafield="Com2|ValoresEscalados_Z5CadenaActual_output" datafixed="0">0</span><span class="unit">Hz</span>
					</td>
				</tr>
				<tr>
					<th colspan="2">
						Detectores
					</th>
				</tr>
				<tr>
					<td>Detector Entrada</td>
					<td class="value">
						<span datafield="Com2|Z5_det5"=>0</span>
					</td>
				</tr>
				<tr>
					<td>Detector Soporte</td>
					<td class="value">
						<span datafield="Com2|Z5_det1"=>0</span>
					</td>
				</tr>
				<tr>
					<td>Detector Arriba Izquierda</td>
					<td class="value">
						<span datafield="Com2|Z5_det2"=>0</span>
					</td>
				</tr>
				<tr>
					<td>Detector Arriba Derecha</td>
					<td class="value">
						<span datafield="Com2|Z5_det4"=>0</span>
					</td>
				</tr>
				<tr>
					<td>Detector Abajo</td>
					<td class="value">
						<span datafield="Com2|Z5_det3"=>0</span>
					</td>
				</tr>
				<tr>
					<th colspan="2">
						Pistones
					</th>
				</tr>
				<tr>
					<td class="subtitulosz" colspan="2">
						Pistón Arriba
					</td>
				</tr>
				<tr>
					<td>FC1</td>
					<td class="value">
						<span datafield="Com2|Z5_acc1_FC1"=>0</span>
					</td>
				</tr>
				<tr>
					<td>EV</td>
					<td class="value">
						<span datafield="Com2|Z5_acc1_EV"=>0</span>
					</td>
				</tr>
				<tr>
					<td class="subtitulosz" colspan="2">
						Pistones Laterales
					</td>
				</tr>
				<tr>
					<td>FC1</td>
					<td class="value">
						<span datafield="Com2|Z5_acc3_FC1">0</span>
					</td>
				</tr>
				<tr>
					<td>FC2</td>
					<td class="value">
						<span datafield="Com2|Z5_acc3_FC2">0</span>
					</td>
				</tr>
				<tr>
					<td>EV</td>
					<td class="value">
						<span datafield="Com2|Z5_acc3_EV">0</span>
					</td>
				</tr>
				<tr>
					<td class="subtitulosz" colspan="2">
						Pistón Abajo
					</td>
				</tr>
				<tr>
					<td>FC1</td>
					<td class="value">
						<span  datafield="Com2|Z5_acc2_FC1"=>0</span>
					</td>
				</tr>
				<tr>
					<td>EV</td>
					<td class="value">
						<span datafield="Com2|Z5_acc2_EV"=>0</span>
					</td>
				</tr>
				
			</table>
		</div>
	</div>
	<div class="fondo">
		<?= getSvg( "sheets/Images/Zona5.svg" ); ?>	
	</div>
</div>
