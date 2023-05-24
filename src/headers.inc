<head>
	<!-- Libreria JQuery -->
	<script src="http://code.jquery.com/jquery-latest.js"></script>
	<!-- Libreria para crear las modales -->
	<script src="libraries/modals.js"></script>
	<!-- Libreria para animaciones de graficos -->
	<script src="https://cdn.jsdelivr.net/npm/gsap"></script>
	
	
	<?
		// --- Existe headers dentro de sheets? ---
		if ( file_exists( 'sheets/headers.inc' ) )
		{
			include( 'sheets/headers.inc' );
		}
	?>	
	
	<link rel="stylesheet" href="style.css">
	
	<?
		// --- Existe style dentro dde sheets? ---
		if ( file_exists( 'sheets/style.css' ) )
		{?>
			<style>
			<?
				include( 'sheets/style.css' );
			?>
			</style>
		<?}
	?>
	
	<?
		// --- Existe la pagina dentro de sheets? ---
		if ( file_exists( "sheets/{$_SHEET}.css" ) )
		{?>
			<style>
			<?
				include( "sheets/{$_SHEET}.css" );
			?>
			</style>
		<?}
	?>
	
</head>
