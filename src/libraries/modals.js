/**
	 * @brief 	Archivo que contiene la clase modal
	 * @author  Cristian Moyano Ureña <cmoyano18@gmail.com>
	 * @author  Sara Valero Valero
	 * @version 1.0
	 *
	 * @section LICENSE
	 *			
	 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU
	 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
	 * (at your option) any later version.
	 * 
	 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
	 * even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
	 * the GNU General Public License for more details.
	 * 
	 * You should have received a copy of the GNU General Public License along with this program. If not, see
	 * <https://www.gnu.org/licenses/>.
	 * 
	 *
	 */

class MODAL
{
	/**
	 * creaModal
	 *
	 * Crea una Modal oculta con un titulo y un ID
	 *
	 * @param
	 * 		id				string			Id que le pondremos a la modal creada
	 * 		title			string			Titulo que le pondremos a la modal creada
	 * 		text			string/array	Texto para el cuerpo de la modal, si es una array pone cada campo en un <p>
	 * 		align			string			Alineado del texto
	 *
	 */
	constructor( id , title , text = '' , align = 'left')
	{
		this.id 	= id;
		this.title 	= title;
		this.text 	= text;
		this.align 	= align;
	}
	
	
	/**
	 * openModal
	 *
	 * Abre una modal creada
	 *
	 * @param
	 * 		
	 *
	 */
	openModal( )
	{
		var contDiv = document.createElement("div");
		contDiv.id = this.id + "_cont";
		
		contDiv.innerHTML = "<div class='modal-wrapper' id=" + this.id + ">" +
						"<div class='modal-dialog modal-dialog-grid'>" +
							"<div class='area-header'>" +
								"<button>X</button>" +
								"<h2> " + this.title + " </h2>" +
								"<span></span>" +
							"</div>" +
							"<div class='area-body ayuda-texto'>" +
							"</div>" +
						"</div>" +
					"</div>";
					
		document.body.appendChild( contDiv );
		this.setTextModal( this.text , this.align );
		
		this.closeBtn = $( '#'+this.id )[0].children[0].children[0].children[0];
		this.closeBtn.addEventListener('click', this.closeModal.bind(this));
		$( '#'+this.id ).show();
	}

	/**
	 * closeModal
	 *
	 * Cierra una modal abierta
	 *
	 * @param
	 * 		
	 *
	 */
	closeModal(  )
	{
		$( '#'+this.id + "_cont" ).remove();
	}

	/**
	 * setTextModal
	 *
	 * Le cambia el texto del cuerpo a una modal creada
	 *
	 * @param
	 * 		id				string			Id de la modal que queremos modificar
	 * 		text			string/array	Texto que le pondremos al cuerpo de la modal creada
	 * 		align			string			Alineado del texto
	 *
	 */
	setTextModal( text , align = 'left')
	{
		var modal = "#" + this.id + " .area-body";
		var body = '';
		if( Array.isArray( text ) )
		{
			for( var i = 0; i < text.length; i++)
			{
				body += "<p style='text-align:" + align + "'>" + text[i] + "</p>";
			}
		}
		else
		{
			if( text.substr(0, 1) == '[')
			{
				regex = /[\['\]]/gm;
				result = text.replace(regex, '');
				text = result.split(',');
				for( var i = 0; i < text.length; i++)
				{
					body += "<p style='text-align:" + align + "'>" + text[i] + "</p>";
				}
			}
			else
			{
				body = "<p style='text-align:" + align + "'>" + text + "</p>";
			}
		}
		$( modal ).html( body );
	}

	/**
	 * setTitleModal
	 *
	 * Le cambia el titulo a una modal creada
	 *
	 * @param
	 *		id			string			Id de la modal que queremos modificar
	 * 		title		string			Titulo que le pondremos a la modal
	 *
	 */
	setTitleModal( title )
	{
		modal = "#" + this.id + " h2";
		$( modal ).html( title );
	}
}
