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
		<span  datafield = "SERVER|hora"> Hora </span>
	</div>
</div>
