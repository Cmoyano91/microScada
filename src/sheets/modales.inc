<!-- Modal de prueba -->

<div class="modal-wrapper" id="alerta">
	<div class="modal-dialog modal-dialog-grid">
		<div class="area-header">
			<button onClick="CloseModal( 'alerta' );">X</button>
			<h2> Alerta </h2>
			<span></span>
		</div>
		<div class="area-body">
			<p>Se necesita Rearme</p>
		</div>
	</div>
</div>

<div class="modal-wrapper" id="ayuda">
	<div class="modal-dialog modal-dialog-grid">
		<div class="area-header">
			<button onClick="CloseModal( 'ayuda' );">X</button>
			<h2> Ayuda </h2>
		</div>
		<div class="area-body">
			<pre class="ayuda-texto"><?
				if(file_exists( "sheets/textos/$_SHEET.txt" ))
				{
					include( "sheets/textos/".$_SHEET.".txt" );
				}
			?></pre>
		</div>
	</div>
</div>
