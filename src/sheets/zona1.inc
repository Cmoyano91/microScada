<div class="main">
	<button onClick="location.href = 'index.php';" type="button">Volver</button>
	
	<div class="datos">
		<div class="estados">	
			<h1 class="tituloEstado"> Zona1 </h1>
			<table>
				<tr>	
					<th class="titulosz" colspan="4">
						Motor
					</th>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Motor Cadena activo</td>
					<td class="numero" datafield = "Com2|Z1_mot1_activo"> 0 </td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Velocidad Cadena</td>
					<td class="numero">  0 </td>
					<td>Hz</td>
				</tr>
				<tr>
					<th class="titulosz" colspan="4">
						Detectores
					</th>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Detector Entrada</td>
					<td class="numero" datafield = "Com2|Z1_det1"> 0 </td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Detector Soporte</td>
					<td class="numero" datafield = "Com2|Z1_det2"> 0 </td>
				</tr>
				
			</table>
		</div>
		<div class="imagen">
			<?//= getSvg( "sheets/Images/Zona1.svg" ); ?>	
		</div>
	</div>
</div>

