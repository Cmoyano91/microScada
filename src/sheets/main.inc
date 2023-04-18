<div class="main">
	<div class="estados">
		<h1 class="tituloEstado">Estado</h1>
		<table>
			<tr>
				<th class="titulosz" colspan="2">
					Zona 1
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Variador1</td> 
				<td class="numero" datafield = "Com2|Z1_mot1_ready"> V1.ok </td>
			</tr>	
			<tr>	
				<th class="titulosz" colspan="2">
					Zona 2
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Variador2</td>
				<td class="numero" datafield = "Com2|Z2_mot1_ready"> V2.ok </td>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Variador3 Bomba</td>
				<td class="numero" datafield = "Com2|Z2_bomba_ready"> Bomba.ok </td>
			</tr>
			<tr>
				<th class="titulosz" colspan="2">
					Zona 3
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Variador4</td>
				<td class="numero" datafield = "Com2|Z3_mot1_ready"> V3.ok </td>
			</tr>
			<tr>
				<th class="titulosz" colspan="2">
					Zona 4
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Variador5</td>
				<td class="numero" datafield = "Com2|Z4_mot1_ready"> V4.ok </td>
			</tr>
			<tr>
				<th class="titulosz" colspan="2">
					Zona 5
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Variador6</td>
				<td class="numero" datafield = "Com2|Z5_mot1_ready"> V5.ok </td>
			</tr>
				<tr>
				<th class="titulosz" colspan="2">
					Zona 6
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Variador7</td>
				<td class="numero" datafield = "Com2|Z6_mot1_ready"> V6.ok </td>
			</tr>
				<tr>
				<th class="titulosz" colspan="2">
					Zona 7
				</th>
				<th>
					Ready
				</th>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Variador8</td>
				<td class="numero" datafield = "Com2|Z7_mot1_ready"> V7.ok </td>
			</tr>
			<tr>
				<td class="spacer"></td>
				<td>Hora</td>
				<td class="numero" datafield = "SERVER|timestamp"> Hora </td>
			</tr>
		</table>
	</div>
	

	<div class="fondo">
		<? include("sheets/Images/esqueleto.svg"); ?>
		
		<div class="Zona1" onClick="location.href = '?zona1';"></div>
		<div class="Zona12" onClick="location.href = '?zona1';"></div>
		<div class="Zona2" onClick="location.href = '?zona2';"></div>
		<div class="Zona4" onClick="location.href = '?zona4';"></div>
		<div class="Zona5" onClick="location.href = '?zona5';"></div>
		<div class="Zona6" onClick="location.href = '?zona6';"></div>
		<div class="Zona7" onClick="location.href = '?zona7';"></div>
	</div>

	
	<div class="form">
		<h1 class="tituloForm"> Param Zona2 </h1>
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
		
	</div>
	
	<div class="conteo">
		<h1 class="tituloCont"> Conteo </h1>
			<table>
				<tr>
					<th>
						Almacen1
					</th>
				</tr>
				<tr>
					<td datafield = "Com2|Z4_DiscosDentro">0</td>
				</tr>
				<tr>
					<th>
						Almacen2
					</th>
				</tr>
				<tr>
					<td datafield = "Com2|Z5_DiscosDentro">0</td>
				</tr>
				<tr>
					<th>
						Almacen3
					</th>
				</tr>
				<tr>
					<td datafield = "Com2|Z6_DiscosDentro">0</td>
				</tr>
			</table>
		<form action="" method="POST">
			<input type="submit" value="Vaciar"> 
		</form>
		 
	</div>
</div>
