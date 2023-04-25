<head>
	<!--<meta http-equiv="refresh" content="5">-->
	<script src="http://code.jquery.com/jquery-latest.js"></script>
	<script src="script.js"></script>
	
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
		if ( file_exists( "sheets/{$sheet}.css" ) )
		{?>
			<style>
			<?
				include( "sheets/{$sheet}.css" );
			?>
			</style>
		<?}
	?>
</head>
