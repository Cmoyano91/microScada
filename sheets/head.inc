<script>
	var bloqueo = true;
	var res = 0;
	function bloqueos( result )
	{
		res = parseInt( result[ 'Com2|Bloqueo' ] , 10 );
		if( res > 0 )
		{
			$( '.alert' ).css( "display" , "block" );
			$.ajax(
					{
						url: "codificado.php",
						data: result,
						success: function ( data ) { asignar( data ); }
					}
				);
		}
		else
		{
			$( '.alert' ).css( "display" , "none" );
			varBloqueos.closeModal( );
		}
	}
	
	function asignar( data )
	{
		varBloqueos.setTextModal( data );
		if( bloqueo )
		{
			varBloqueos.openModal();
			bloqueo = false;
		}
	}
	
	var varBloqueos = new MODAL( "modBloqueos" , "BLOQUEOS y ERRORES" );
	
	SCADA.subsSet( [ "Com2|Bloqueo" ] , bloqueos  );

</script>

<div class="header">
	<div>
		<?
			if ( $_SHEET != 'main' )
			{?>
				<div class="button">
					<button title="Inicio" class="pulsador" style="font-size: 30px;" onClick="location.href = '?';" > &#8962; </button>
				</div>
			<?}
		?>
	</div>
	<div>
		<img class="alert" src="sheets/images/alert.png" title="Alarmas" onClick="varBloqueos.openModal();"></img>
	</div>
	
	<div class="date">
		<span datafield = "SERVER|fecha"> Fecha </span>
		<br>
		<span datafield = "SERVER|hora"> Hora </span>
	</div>
</div>
