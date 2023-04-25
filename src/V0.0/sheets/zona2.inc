<div class="main">
	
	<div class="datos">
		<br>
		<div class="estados"  style="position:relative;" >	
			<h1 class="titulo"> Zona2 </h1>
			<table>
				<tr>	
					<th class="titulosz" colspan="4" >
						Motores
					</th>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Motor Cinta activo</td>
					<td class="numero" datafield = "Com2|Z2_mot1_activo" > 0 </td>
					<td></td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Velocidad cinta</td>
					<td class="numero" datafield = "Com2|V210U1-I_OutputFreq" > 0 </td>
					<td>Hz</td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Motor Bomba Activo</td>
					<td class="numero" datafield = "Com2|Z2_Bomba_activo" > 0 </td>
					<td></td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Velocidad Bomba</td>
					<td class="numero" datafield = "Com2|V212U1-I_OutputFreq" > 0 </td>
					<td>Hz</td>
				</tr>
				<tr>
					<th class="titulosz" colspan="4">
						Temperatura
					</th>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Temperatura de producto</td>
					<td class="numero" datafield = "Com2|scpTemp1_Output"> 0 </td>
					<td>ºC</td>
				</tr>
				<tr>
					<th class="titulosz" colspan="4">
						Viscosidad
					</th>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Viscosidad de producto</td>
					<td class="numero" datafield = "Com2|Periferia-11-I_Ch0Data" > 0 </td>
					<td></td>
				</tr>
			</table>
		</div>
		<br>
		<div class="estados" style="position:relative;">
			<h1 class="tituloEstado"> Zona3 </h1>
			<table>
				<tr>	
					<th class="titulosz" colspan="4">
						Motor
					</th>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Motor Cinta activo</td>
					<td class="numero" datafield = "Com2|Z1_mot1_activo" > 0 </td>
					<td></td>
				</tr>
				<tr>
					<td class="spacer"></td>
					<td>Velocidad cinta</td>
					<td class="numero" datafield = "Com2|V210U1-I_OutputFreq" > 0 </td>
					<td>Hz</td>
				</tr>
				
			</table>
		</div>

	</div>
	<div class="imagen">
		<!-- <object type="image/svg+xml" id="svgimage" data=".\sheets\Images\cinta.svg" ></object> -->
		<?= getSvg( "sheets/Images/cinta.svg" ); ?>	
	</div>
</div>
