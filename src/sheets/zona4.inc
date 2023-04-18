<div class="main">
	<button onClick="location.href = 'index.php';" type="button">Volver</button>
	
	<div class="datos">
		<div class="estados">	
			<h1 class="tituloEstado"> Zona4 </h1>
			<table>
				<tr>	
					<th class="titulosz" colspan="4">
						Motor
					</th>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Motor Cadena activo</td>
					<td class="numero" id="Com2|Z4_mot1_activo" datafield = "Com2|Z4_mot1_activo" > 0 </td>
					<td></td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Velocidad Cadena</td>
					<td class="numero" datafield = "Com2|V211U1-I_OutputFreq" > 0 </td>
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
					<td class="numero" datafield = "Com2|Z4_det1" > 1 </td>
					<td></td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Detector Soporte</td>
					<td class="numero" datafield = "Com2|Z4_det2" > 1 </td>
					<td></td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Detector Arriba:</td>
					<td class="numero" datafield = "Com2|Z4_det3" > 1 </td>
					<td></td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Detector Abajo:</td>
					<td class="numero" datafield = "Com2|Z4_det4" > 1 </td>
					<td></td>
				</tr>
				<tr>
					<th class="titulosz" colspan="4">
						Pistones
					</th>
				</tr>
				<tr>
					<td class="subtitulosz" colspan="4">
						Entrada Horizontal
					</td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>FC1</td>
					<td class="numero" datafield = "Com2|Z4_acc1_FC1" > 1 </td>
					<td></td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>FC2</td>
					<td class="numero" datafield = "Com2|Z4_acc1_FC2" > 1 </td>
					<td></td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>EV</td>
					<td class="numero" datafield = "Com2|Z4_acc1_EV" > 1 </td>
					<td></td>
				</tr>
				<tr>
					<td class="subtitulosz" colspan="4">
						Entrada Vertical
					</td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>FC1</td>
					<td class="numero" datafield = "Com2|Z4_acc2_FC1" > 1 </td>
					<td></td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>FC2</td>
					<td class="numero" datafield = "Com2|Z4_acc2_FC2" > 1 </td>
					<td></td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>EV</td>
					<td class="numero" datafield = "Com2|Z4_acc2_EV" > 1 </td>
					<td></td>
				</tr>
				<tr>
					<td class="subtitulosz" colspan="4">
						Piston Arriba
					</td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>FC1</td>
					<td class="numero" datafield = "Com2|Z4_acc3_FC1" > 1 </td>
					<td></td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>FC2</td>
					<td class="numero" datafield = "Com2|Z4_acc3_FC2" > 1 </td>
					<td></td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>EV</td>
					<td class="numero" datafield = "Com2|Z4_acc3_EV" > 1 </td>
					<td></td>
				</tr>
				<tr>
					<td class="subtitulosz" colspan="4">
						Piston Abajo
					</td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>FC1</td>
					<td class="numero" datafield = "Com2|Z4_acc4_FC1" > 1 </td>
					<td></td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>FC2</td>
					<td class="numero" datafield = "Com2|Z4_acc4_FC2" > 1 </td>
					<td></td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>EV</td>
					<td class="numero" datafield = "Com2|Z4_acc4_EV" > 1 </td>
					<td></td>
				</tr>
				
			</table>
		</div>
		<div class="imagen">
			<!-- <object type="image/svg+xml" id="svgimage" data=".\sheets\Images\Zona4.svg" ></object> -->
			<?= getSvg( "sheets/Images/Zona4.svg" ); ?>		
		</div>
	</div>
</div>
