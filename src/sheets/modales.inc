<!-- Modal de prueba -->

<div class="modal-wrapper" id="alerta">
	<div class="modal-dialog modal-dialog-grid">
		<div class="area-header">
			<button onClick="CloseModal( 'alerta' );">X</button>
			<h2> Alerta </h2>
			<span></span>
		</div>
		<div class="area-body ayuda-texto">
			<p>
				Se necesita Rearme.
			</p>
			<p>
				Comprueba si esta la seta pulsada.
			</p>
			<p>
				Comprueba que la presión de aire está bien.
			</p>
		</div>
	</div>
</div>

<div class="modal-wrapper" id="ayuda">
	<div class="modal-dialog modal-dialog-grid">
		<div class="area-header">
			<button onClick="CloseModal( 'ayuda' );">X</button>
			<h2> Ayuda </h2>
			<div></div>
		</div>
		<div class="area-body ayuda-texto">
			<?
				if(file_exists( "sheets/textos/$_SHEET.txt" ))
				{
					$texto = file_get_contents( "sheets/textos/".$_SHEET.".txt" );
					
					$texto = nl2br( $texto , false );
					
					$texto = strtr( $texto , [ '<br>' => '</p><p>' ] );
					
					$texto = '<p>' . $texto . '</p>';
					
					echo $texto;
				}
			?>
		</div>
	</div>
</div>

<div class="modal-wrapper" id="modManual">
	<div class="modal-dialog modal-dialog-grid">
		<div class="area-header">
			<button onClick="CloseModal( 'modManual' );">X</button>
			<h2> Modo Manual </h2>
			<span></span>
		</div>
		<div class="area-body ayuda-texto">
			<p>
				¿Quieres activar el modo manual?
			</p>
			<p class="action">
				<button value="0" onClick="envioVariables( 'Com2|scada_selector' , 1 ); CloseModal( 'modManual' );"> SI </button>
				<button value="0" onClick="envioVariables( 'Com2|scada_selector' , 0 ); CloseModal( 'modManual' );"> NO </button>
			</p>
			<p>
				Si quieres cambiar el modo otra vez tienes un selector en la parte superior del modo manual.
			</p>
		</div>
	</div>
</div>
