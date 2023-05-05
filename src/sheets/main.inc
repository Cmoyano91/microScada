<script>
/*	
	// --- Suscribimos la funcion ---
	subsSet( [ "Com2|Local-2-I_Pt07_Data", "Com2|Buttons_Start" ] , rearme );
	
*/
</script>
<div class="main">
	<div class="estados">
		<h1 class="titulo">Estado</h1>
		<br>
		<table class= "interface">
			<tr>
				<th>
					General
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td>Relé de Seguridad</td> 
				<td class="value">
					<span datafield="Com2|Local-2-I_Pt07_Data">Rele.Ok</span>
				</td>
			</tr>
			<tr>
				<th>
					Zona 1
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td>Variador 1</td> 
				<td class="value">
					<span datafield="Com2|Z1_mot1_ready">V1.ok</span>
				</td>
			</tr>	
			<tr>	
				<th>
					Zona 2
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td>Variador 2 Cinta</td>
				<td class="value">
					<span datafield="Com2|Z2_mot1_ready">V2.ok</span>
				</td>
			</tr>
			<tr>
				<td>Variador 3 Lacadora</td>
				<td class="value">
					<span datafield="Com2|Z2_bomba_ready">Bomba.ok</span>
				</td>
			</tr>
			<tr>
				<th>
					Zona 3
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td>Variador 4 </td>
				<td class="value">
					<span datafield="Com2|Z3_mot1_ready">V3.ok</span>
				</td>
			</tr>
			<tr>
				<th>
					Zona 4
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td>Variador 5 Arrastre 1</td>
				<td class="value">
					<span datafield="Com2|Z4_mot1_ready">V4.ok</span>
				</td>
			</tr>
			<tr>
				<th>
					Zona 5
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td>Variador 6 Arrastre 2</td>
				<td class="value">
					<span datafield="Com2|Z5_mot1_ready"> V5.ok</span>
				</td>
			</tr>
				<tr>
				<th>
					Zona 6
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td>Variador 7 Arrastre 3</td>
				<td class="value">
					<span datafield="Com2|Z6_mot1_ready"> V6.ok</span>
				</td>
			</tr>
				<tr>
				<th>
					Zona 7
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td>Variador 8</td>
				<td class="value">
					<span datafield="Com2|Z7_mot1_ready"> V7.ok</span>
				</td>
			</tr>
		</table>
	</div>

	<div class="fondo">
		<?= getSvg( "sheets/Images/esqueleto.svg" ); ?>
		
	</div>

	<div class="acciones">
		<div class="form">
			<h1 class="titulo"> Param Zona2 </h1>
			<br>
			<table class= "interface">
				<tr>
					<td>
						<form method="POST" id="form1">
							<label>Velocidad: </label>
							<label datafield="Com2|cons_VelCinta2"> </label>
							<br />
							<input type ="text" name="Com2|cons_VelCinta2">
							<br />
							
							<label>Temperatura:</label>
							<label datafield="Com2|cons_Temp"> </label>
							<br />
							<input type ="text" name="Com2|cons_Temp"> 
							<input type="checkbox" value = "1" name="Com2|Scada_selTemp" datafield="Com2|Scada_selTemp" >
							<br />
						
							<label>Viscosidad:</label>
							<label datafield="Com2|cons_Dens" > </label>
							<br />
							<input type ="text" name="Com2|cons_Dens">
							<input type="checkbox" value = "1" name="Com2|Scada_selVisc" datafield="Com2|Scada_selVisc" >
							
							<br />
							<input type="submit" value="Enviar" onclick="post('form1'); return false;"> 
						</form>
					</td>
				</tr>
			</table>
		</div>
		
		<div class="form">
			<h1 class="titulo"> Conteo </h1>
			<br />
			<table class= "interface">
				<tr>
					<th>
						Almacen1
					</th>
				</tr>
				<tr>
					<td class="value">
						<span datafield="Com2|Z4_DiscosDentro">0</span>
					</td>
				</tr>
				<tr>
					<th>
						Almacen2
					</th>
				</tr>
				<tr>
					<td class="value">
						<span datafield="Com2|Z5_DiscosDentro">0</span>
					</td>
				</tr>
				<tr>
					<th>
						Almacen3
					</th>
				</tr>
				<tr>
					<td class="value">
						<span datafield="Com2|Z6_DiscosDentro">0</span>
					</td>
				</tr>
			</table>
			<form action="" method="POST">
				<input type="submit" value="Vaciar"> 
			</form>
			 
		</div>
	</div>
</div>




