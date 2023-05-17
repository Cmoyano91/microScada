<script>
	var bloqueo = true;
	var res = 0;
	function bloqueos( result )
	{
		res = parseInt( result['Com2|Bloqueo'] , 10 );
		if( res > 0 )
		{
			$('.alert').css("display" ,"block");
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
			$('.alert').css("display" , "none") ;
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
		}
	}
	
	creaModal( "bloqueos" , "BLOQUEOS y ERRORES");
	
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
	<div>
		<img class="alert" src="sheets/images/alert.png" onClick="OpenModal('bloqueos');"></img>
	</div>
	
	<div class="date">
		<span datafield = "SERVER|fecha"> Fecha </span>
		<br>
		<span datafield = "SERVER|hora"> Hora </span>
	</div>
</div>
