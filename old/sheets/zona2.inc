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
						<span datafield="Com2|V311U1-I_OutputFreq">0</span><span class="unit">Hz</span>
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
						<span datafield="Com2|V313U1-I_OutputFreq">0</span><span class="unit">Hz</span>
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
	</div>
	<div class="datos">
		<div class="estados" >
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
						<span datafield="Com2|Z3_mot1_activo">0</span>
					</td>
				</tr>
				<tr>
					<td>Velocidad cinta</td>
					<td class="value">
						<span datafield="">0</span><span class="unit">Hz</span>
					</td>
				</tr>
				
			</table>
		</div>
	</div>
		<div class="fondo">
			<?= getSvg( "sheets/Images/cinta1.svg" ); ?>	
		</div>
</div>
