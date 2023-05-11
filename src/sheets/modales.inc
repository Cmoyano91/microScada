<!-- Modal de prueba -->

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
