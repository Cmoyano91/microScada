var viewFamily = {
					A: {
							0 : [
									[	1	,	47	,	34	],
									[	2	,	47	,	45	],
									[	3	,	47	,	56	]
								],
							1 :	[
									[	1	,	47	,	34	],
									[	2	,	47	,	45	],
									[	3	,	47	,	56	]
								],
							2 :	[
									[	1	,	27	,	66.5	],
									[	2	,	33.5	,	32	]
								],
							3 :	[
									[	1	,	68	,	21	],
									[	2	,	57	,	36.5	],
									[	3	,	20	,	47	]
								],
							4 : [
									[	1	,	43	,	30	],
									[	2	,	31.75	,	60.5	],
									[	3	,	31.75	,	68.5	],
									[	4	,	55	,	4	],
									[	5	,	65.5	,	9.5	],
									[	6	,	55	,	83	],
									[	7	,	42.5	,	58	],
									[	8	,	42.5	,	63	],
									[	9	,	61.35 ,	12.5	],
									[	10	,	44.25	,	21.5	],
									[	11	,	64.75	,	83	]
								],
							5 :	[
									[	1	,	42.5	,	30	],
									[	2	,	53.5	,	73.85	],
									[	3	,	32.5	,	74.5	],
									[	4	,	54.5	,	4	],
									[	5	,	69.25	,	11.5	],
									[	6	,	54.5	,	83.25	],
									[	7	,	42.25	,	72	],
									[	8	,	61 ,	13	],
									[	9	,	43.15	,	22.5	],
									[	10	,	64.75	,	83	]
								],
							6 :	[
									[	1	,	42.5	,	30	],
									[	2	,	53.5	,	73.85	],
									[	3	,	32.5	,	74.5	],
									[	4	,	54.5	,	4	],
									[	5	,	69.25	,	11.5	],
									[	6	,	54.5	,	83.25	],
									[	7	,	42.25	,	72	],
									[	8	,	61 ,	13	],
									[	9	,	43.15	,	22.5	],
									[	10	,	64.75	,	83	]
								],
							7 :	[
									[	1	,	25.15	,	22.35	],
									[	2	,	33	,	35	]
								],
							8 : [
									[	1	,	25	,	25	],
									[	5	,	64	,	36	]
								],
							9 :	[
									[	1	,	25	,	25	],
									[	5	,	64	,	36	]
								]
						}
					,
					B: {
							0 :	[
									[	1	,	25	,	25	],
									[	5	,	64	,	36	]
								],
							1 :	[
									[	1	,	25	,	25	],
									[	5	,	64	,	36	]
								],
							2 :	[
									[	1	,	25	,	25	],
									[	5	,	64	,	36	]
								],
							3 : [
									[	1	,	25	,	25	],
									[	5	,	64	,	36	]
								],
							4 :	[
									[	1	,	25	,	25	],
									[	5	,	64	,	36	]
								],
							5 :	[
									[	1	,	25	,	25	],
									[	5	,	64	,	36	]
								],
							6 :	[
									[	1	,	25	,	25	],
									[	5	,	64	,	36	]
								],
							7 :	[
									[	1	,	25	,	25	],
									[	5	,	64	,	36	]
								],
							8 :	[
									[	1	,	25	,	25	],
									[	5	,	64	,	36	]
								],
							9 :	[
									[	1	,	25	,	25	],
									[	5	,	64	,	36	]
								]
						}
				};



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
							NumPag = response.url;
							return response.json().then( data => ({
									data: data,
									url: response.url
								
								});; //lee y devuelve la respuesta en formato json
					
						
						}
						throw new Error('Error en petición');
						})
							.then((Res) => {
							
								var prue = Res;
								
								//Cuando acaba el .then anterior el response.url es undefined en el siguente .then. Si creo una variable en el .then, en el
								//siguiente sale undefined.
								
								 //Revisar como  remplazar la url "http://localhost:8080/sacad/fallos/content/A0.json", al poner 8080,
								 //quita tambien el 0 del A0. si quito los 0, el resultado que da 00A0
								
								
								//const regex = /[http://localhost:8080/sacad/fallos/content/ .json]/g;
								//var NumPag = response.url;
								//var NumPag = "http://localhost:8080/sacad/fallos/content/A0.json";
								
								//var valorUrl1 = "http://localhost:8080/sacad/fallos/content/A0.json";
								//var valorUrl2 = SUBSTRING(valorUrl1 AFTER 'http://localhost:8080/sacad/fallos/content/');
								//var Seccion = SUBSTRING(valorUrl2 BEFORE '.json');
								//var Valor1 = NumPag.substring(43,45);
								//var Valor2 = Valor1.substring(0,2);
								var ValorS = NumPag.substring(43,44);
								var ValorP = NumPag.substring(44,45);
								
								//var Seccion = Valor2; // cadenaJSON aparece A[0] A0[3] B[0]
								
								//console cadenaJSON['A'][0]
								
								
								//cadenaJSON [[ValorS]+[ValorP]]=aparece A[0] A0[3] B[0], cadenaJSON[ValorS][ValorP]= aparece A[0] B[0],
								//cadenaJSON[ValorS]+ [ValorP]= Error, cadenaJSON[secciones[ ValorS ] + ValorP] = aparece A[0] B[0] undefined0 [3],
								//cadenaJSON[secciones[ ValorS ][ValorP]]= aparece A[0] B[0], cadenaJSON[secciones[ ValorS ] + [ValorP]] = aparece A[0] B[0] undefined0 [3],
								//cadenaJSON[[ValorS][ValorP]]= aparece A[3] B[0], cadenaJSON[ValorS[ValorP]]=aparece A[3] B[0],
								//cadenaJSON[ ValorS + {ValorP}] = aparece A[0]  B[0] A object Object [3],cadenaJSON[ 'ValorS' ['ValorP']] = aparece A[0] B[0] undefined0 [3],
								//cadenaJSON['ValorS']['ValorP']= aparece A[0] B[0], cadenaJSON[ValorS].ValorP= aparece A[1](ValorP[3]) B[0],
								//cadenaJSON[ValorS].[ValorP]= Error, cadenaJSON[ValorS].{ValorP}= Error, cadenaJSON[ValorS].'ValorP'= Error,
								//cadenaJSON[ValorS]."ValorP"= Error, cadenaJSON[ValorS]= ValorP[Res] = Aparece A undefined B[0]
								
								
								
								//Al estar solo el A0.json lo realiza bien, al añadir el A1.Json, realiza ese primero dejando el [0] vacia, al poner
								// el A2.json, deja el [0] y [1] vacios.
								//[A: Array(3), B: Array(0)] | A: (3) [vacío × 2, Array(2)] |B: []
								
								var ValorR = [];
								ValorR[ValorP]= Res;
								cadenaJSON[ValorS]= ValorR;
								//cadenaJSON[ValorS]= ValorP[Res];
										
							}
						)
							.catch((error) => {
								console.log(error)
							});
					
		// --- Añadimos al Array ---
		//
	}
}

