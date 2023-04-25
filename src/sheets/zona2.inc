<div class="main">
	
	<div class="datos">
		<br>
		<div class="estados"  style="position:relative;" >	
			<h1 class="titulo"> Zona2 </h1>
			<table class= "interface">
				<tr>	
					<th colspan="2" >
						Motores
					</th>
				</tr>
				<tr>
					<td>Motor Cinta activo</td>
					<td class="value">
						<span datafield="Com2|Z2_mot1_activo">0</span>
					</td>
				</tr>
				<tr>
					<td>Velocidad cinta</td>
					<td class="value">
						<span datafield="Com2|V210U1-I_OutputFreq">0</span><span class="unit">Hz</span>
					</td>
				</tr>
				<tr>
					<td>Motor Bomba Activo</td>
					<td class="value">
						<span datafield="Com2|Z2_Bomba_activo">0</span>
					</td>
				</tr>
				<tr>
					<td>Velocidad Bomba</td>
					<td class="value">
						<span datafield="Com2|V212U1-I_OutputFreq">0</span><span class="unit">Hz</span>
					</td>
				</tr>
				<tr>
					<th colspan="2">
						Temperatura
					</th>
				</tr>
				<tr>
					<td>Temperatura de producto</td>
					<td class="value">
						<span datafield="Com2|scpTemp1_Output" datafixed="1">0</span><span class="unit">ºC</span>
					</td>
				</tr>
				<tr>
					<th colspan="2">
						Viscosidad
					</th>
				</tr>
				<tr>
					<td>Viscosidad de producto</td>
					<td class="value">
						<span datafield="Com2|Periferia-11-I_Ch0Data">0</span>
					</td>
				</tr>
			</table>
		</div>
		<br>
		<div class="estados" style="position:relative;">
			<h1 class="titulo"> Zona3 </h1>
			<table class= "interface">
				<tr>	
					<th colspan="2">
						Motor
					</th>
				</tr>
				<tr>
					<td>Motor Cinta activo</td>
					<td class="value">
						<span datafield="Com2|Z1_mot1_activo">0</span>
					</td>
				</tr>
				<tr>
					<td>Velocidad cinta</td>
					<td class="value">
						<span datafield="Com2|V210U1-I_OutputFreq">0</span><span class="unit">Hz</span>
					</td>
				</tr>
				
			</table>
		</div>

	</div>
	<div class="imagen">
		<!-- <object type="image/svg+xml" id="svgimage" data=".\sheets\Images\cinta.svg" ></object> -->
		<?= getSvg( "sheets/Images/cinta.svg" ); ?>	
	</div>
</div>
