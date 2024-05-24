// --- Generación del Array de Forma Automatica ---

var cadenaJSON = [];
var secciones = [ 'A' , 'B' ];
var maxPages = 25;

var NumPag = 0;

// --- Bucle de Secciones ---
for( var s = 0 ; s < secciones.length ; s++ )
{
	cadenaJSON[ secciones[ s ] ] = [];
	
	for( var p = 0 ; p < maxPages ; p++ )
	{
		var url = "content/" + secciones[ s ] + p + ".json";
		
		// --- Peticion ---
		var Promise = fetch( url ,
			{
				mode: 'no-cors'
				}
					).then((response) => {
						//status – código de estado HTTP, por ejemplo: 200.
						//ok – booleana, true si el código de estado HTTP es 200 a 299.
						//Si .ok es falso no realiza bien el then y no pasa correctamente dejando la Y vacia.
						console.log(response.status);
						if (response.ok) {
							return response.json().then( data => ({
									data: data,
									url: response.url
								
								})); 
						}
						throw new Error('Error en petición');
						})
							.then((Res) => {
								
								var ValorS = Res.url.substring(43,44);
								var ValorP = Res.url.substring(44,45);
								
								cadenaJSON[ ValorS ][ ValorP ] = Res.data;

							}
						)
							.catch((error) => {
								console.log(error)
							});
					
		// --- Añadimos al Array ---
		//
	}
}

