<script>
	var ayuda = new MODAL(
						"ayuda",
						"Ayuda",
						"<?
							if( file_exists( "sheets/textos/$_SHEET.txt" ) )
							{
								$texto = file_get_contents( "sheets/textos/" . $_SHEET . ".txt" );
								
								$texto = htmlentities( $texto );
								
								$texto = strtr( $texto , [
															"\r"	=> '</p><p>',
															"\n"	=> '</p><p>',
															'<br>' 	=> '</p><p>',
															'"'		=> ''
														]
											);
								
								$texto = strtr( $texto , [
															'<p></p>'	=> ''
														]
											);
								
								$texto = '<p>' . $texto . '</p>';
								
								echo $texto;
							}
						?>"
					);
</script>

<div class="footer">
	<div>
		<b>Modo:</b>
		<span value="0" datafield="Com2|scada_selector" dataanimtype="switch" dataanimvalues="Automatico;Manual"></span>
		<br>
		<div class="button">
			<button class="pulsador" onClick="location.href = '?manual';">Manual</button>	
		</div>
	</div>
	<div>
		<b>Estado de maquina:</b>
		<span value="0" datafield="Com2|Seg_MaquinaOn" dataanimtype="switch" dataanimvalues="Parada;En Marcha"></span>
		
	</div>
	<div>
		<span value="0" datafield="Com2|Seg_ReadyAll" dataanimtype="switch" dataanimvalues="Se necesita rearme;Maquina Rearmada"></span>
	<!--
		<div class="button" value="0" datafield="Com2|Seg_OK" dataanimtype="display" dataanimvalues="none;block">
			<button class="pulsador" onClick="setTimeout( function() { SCADA.sendVariables( 'Com2|Scada_Marcha' , 0 ) }, 4000 ); SCADA.sendVariables( 'Com2|Scada_Marcha' , 1 );"> Marcha </button>
		</div>
	-->
	</div>
	<div >
		<div class="ayuda" >
			<button title="Ayuda" onclick="ayuda.openModal();">?</button>
		</div>
	</div>
</div>
