<script>
	var bloqueo = true;
	var res = 0;
	let nIntervId;
	function bloqueos( result )
	{
		res = parseInt( result['Com2|Bloqueo'] , 10 );
		if( res > 0 )
		{
			if (!nIntervId)
			{
				boqueo = true;
				nIntervId = setInterval( function(){ bloqueo = true;}, 10000 );
			}
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
			clearInterval( nIntervId );
			CloseModal( "bloqueos" );
		}
	}
	
	function asignar( data )
	{
		setTextModal( data, "bloqueos" );
		if( bloqueo )
		{
			OpenModal("bloqueos");
			bloqueo = false;
			nIntervId = '';
		}
	}
	
	creaModal( "bloqueos" , "BLOQUEOS");
	
	subsSet( [ "Com2|Bloqueo" ] , bloqueos  );
</script>

<div class="header">
	<span>
		<?
			if ( $_SHEET != 'main' )
			{?>
				<div class="button">
					<button title="Inicio" class="pulsador" style="font-size: 30px;" onClick="location.href = '?';" > &#8962; </button>
				</div>
			<?}
		?>
	</span>
	
	<div class="date">
		<span datafield = "SERVER|fecha"> Fecha </span>
		<br>
		<span datafield = "SERVER|hora"> Hora </span>
	</div>
</div>
