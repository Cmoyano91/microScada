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
								"Zona 4: Bloqueo Pistones de Entrada",
								"Zona 4: Bloqueo Pistón Superior o Laterales",
								"Zona 4: Bloqueo Pistón Inferior",
								"Zona 5: Bloqueo Pistón Superior o Laterales",
								"Zona 5: Bloqueo Pistón Inferior",
								"Zona 6: Bloqueo Pistón Superior o Laterales",
								"Zona 6: Bloqueo Pistón Inferior",
								"Zona 2: Error Variador Cinta 1 (V311U1)",
								"Zona 2: Error Variador Cinta 2 (V312U1)",
								"Zona 2: Error Variador Bomba (V313U1)",
								"Zona 3: Error Variador Cinta 1 (V315U1)",
								"Zona 4: Error Variador Arrastre (V211U1)",
								"Zona 5: Error Variador Arrastre (V212U1)",
								"Zona 6: Error Variador Arrastre (V215U1)",
								"",
								"",
								""
						) 
			);
			