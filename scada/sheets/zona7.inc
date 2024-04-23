<div class="main">
	
	<div class="datos">
		<div class="estados">	
			<h1 class="titulo"> Zona 7 </h1>
			<table class= "interface">
				<tr>	
					<th colspan="2">
						Motor
					</th>
				</tr>
				<tr>
					<td>Motor Cinta Activo</td>
					<td class="value">
						<span datafield="Com2|Z7_mot1_activo">0</span>
					</td>
				</tr>
				<tr>
					<td>Velocidad Cinta</td>
					<td class="value">
						<span datafield="Com2|ValoresEscalados_Z7CintaActual_output" datafixed="0">0</span><span class="unit"> Hz</span>
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
						<spandatafield="Com2|Z7_det1">0</span>
					</td>
				</tr>
			</table>
		</div>
	</div>
	<div class="fondo">
		<?=  getSvg( "sheets/Images/Zona7.svg" ); ?>	
	</div>
</div>
