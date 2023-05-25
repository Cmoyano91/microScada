<?php

	// --- Libreria BUFFER ---
	define( "BUFFER" , "buffers/redis/redis.php" );
	//define( "BUFFER" , "buffers/file/file.php" );
	
	/**
	 * 
	 *	Configuración en caso de usar redis
	 * 
	 * */
	 
	// --- IP servidor redis ---
	define( "IP_REDIS" , '172.23.184.244' );
	// --- Puerto servidor redis (6379 por defecto) ---
	define( "PUERTO_REDIS" , 6379 );
	
	/**
	 * 
	 *	Configuración en caso de usar file
	 * 
	 *	En el archivo guardamos las variables que necesitamos junto a su valor y un timestamp para controlar la caducidad de estas
	 * 
	 * */
	 
	// --- Fichero donde guardamos los datos ---
	define( "DB_FILE" , "db.txt" );
	
	
	define( "ERRORS" , array(
								"Zona 4: Bloqueo Pistones de entrada",
								"Zona 4: Bloqueo Pistón superior",
								"Zona 4: Bloqueo Pistón inferior",
								"Zona 5: Bloqueo Pistón superior",
								"Zona 5: Bloqueo Pistón inferior",
								"Zona 6: Bloqueo Pistón superior",
								"Zona 6: Bloqueo Pistón inferior",
								"Zona 2: Error Variador cinta",
								"Zona 2: Error Variador bomba",
								"Zona 4: Error Variador arrastre",
								"Zona 5: Error Variador arrastre",
								"",
								"",
								"",
								""
						) 
			);