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
		<span value="0" datafield="Com2|Seg_MotActivos" dataanimtype="switch" dataanimvalues="Parada;En Marcha"></span>
	</div>
	<div>
		<span value="0" datafield="Com2|Seg_OK" dataanimtype="switch" dataanimvalues="Se necesita rearme;Maquina Rearmada"></span>
		<div class="button" value="0" datafield="Com2|Seg_OK" dataanimtype="display" dataanimvalues="none;block">
			<button class="pulsador" onClick="setTimeout( function() { envioVariables( 'Com2|Scada_Marcha' , 0 ) }, 4000 ); envioVariables( 'Com2|Scada_Marcha' , 1 );"> Marcha </button>
		</div>
	</div>
</div>
