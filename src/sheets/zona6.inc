<div class="main">
	<button onClick="location.href = 'index.php';" type="button">Volver</button>
	
	<div class="datos">
		<div class="estados">	
			<h1 class="tituloEstado"> Zona6 </h1>
			<table>
				<tr>	
					<th class="titulosz" colspan="4">
						Motor
					</th>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Motor Cadena activo</td>
					<td class="numero" datafield = "Com2|Z6_mot1_activo"> 0 </td>
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
					<td class="numero" datafield = "Com2|Z6_det1"> 0 </td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Detector Soporte</td>
					<td class="numero" datafield = "Com2|Z6_det2"> 0 </td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Detector Arriba:</td>
					<td class="numero" datafield = "Com2|Z6_det3"> 0  </td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Detector Abajo:</td>
					<td class="numero" datafield = "Com2|Z6_det4"> 0  </td>
				</tr>
				<tr>
					<th class="titulosz" colspan="4">
						Pistones
					</th>
				</tr>
				<tr>
					<td class="subtitulosz" colspan="4">
						Piston Arriba
					</td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>FC1</td>
					<td class="numero" datafield = "Com2|Z6_acc1_FC1" > 0 </td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>FC2</td>
					<td class="numero" datafield = "Com2|Z6_acc1_FC2" > 0 </td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>EV</td>
					<td class="numero" datafield = "Com2|Z6_acc1_EV" > 0 </td>
				</tr>
				<tr>
					<td class="subtitulosz" colspan="4">
						Piston Abajo
					</td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>FC1</td>
					<td class="numero" datafield = "Com2|Z6_acc2_FC1" > 0 </td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>FC2</td>
					<td class="numero" datafield = "Com2|Z6_acc2_FC2" > 0 </td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>EV</td>
					<td class="numero" datafield = "Com2|Z6_acc2_EV" > 0 </td>
				</tr>
				
			</table>
		</div>
		<div class="imagen">
			<!-- <object type="image/svg+xml" id="svgimage" data=".\sheets\Images\Zona6.svg" ></object> -->
			<?= getSvg( "sheets/Images/Zona6.svg" ); ?>	

			
		</div>
		
	</div>
	
</div>
