<div class="main">
	
	<div class="datos">
		<div class="estados">	
			<h1 class="titulo"> Zona5 </h1>
			<table class= "interface">
				<tr>	
					<th colspan="2">
						Motor
					</th>
				</tr>
				<tr>
					<td>Motor Arrastre activo</td>
					<td class="value">
						<span datafield="Com2|Z5_mot1_activo">0</span>
					</td>
				</tr>
				<tr>
					<td>Velocidad Arrastre</td>
					<td class="value">
						<span datafield="Com2|V212U1-I_OutputFreq">0</span><span class="unit">Hz</span>
					</td>
				</tr>
				<tr>
					<th colspan="2">
						Detectores
					</th>
				</tr>
				<tr>
					<td>Detector Soporte</td>
					<td class="value">
						<span datafield="Com2|Z5_det1"=>0</span>
					</td>
				</tr>
				<tr>
					<td>Detector Arriba</td>
					<td class="value">
						<span datafield="Com2|Z5_det2"=>0</span>
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
						Piston Arriba
					</td>
				</tr>
				<tr>
					<td>FC1</td>
					<td class="value">
						<span datafield="Com2|Z5_acc1_FC1"=>0</span>
					</td>
				</tr>
				<tr>
					<td>FC2</td>
					<td class="value">
						<span datafield="Com2|Z5_acc1_FC2"=>0</span>
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
						Piston Abajo
					</td>
				</tr>
				<tr>
					<td>FC1</td>
					<td class="value">
						<span  datafield="Com2|Z5_acc2_FC1"=>0</span>
					</td>
				</tr>
				<tr>
					<td>FC2</td>
					<td class="value">
						<span datafield="Com2|Z5_acc2_FC2"=>0</span>
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

