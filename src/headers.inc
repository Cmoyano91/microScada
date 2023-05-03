<head>
	<script src="http://code.jquery.com/jquery-latest.js"></script>
	<script src="script.js"></script>
	
	<script src="https://cdn.jsdelivr.net/npm/gsap"></script>
	
	
	<?
		if ( file_exists( 'sheets/headers.inc' ) )
		{
			include( 'sheets/headers.inc' );
		}
	?>	
	
	<link rel="stylesheet" href="style.css">
	
	<?
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
