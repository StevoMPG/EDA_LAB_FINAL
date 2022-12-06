// -------------------------------------------
// Prototipo de las funciones (usando TipoRetorno de tipos.h)
// -------------------------------------------


// Inserta una nueva linea vacia al final del texto.
TipoRetorno InsertarLinea(nlinea &pgTexto, int  &gLineasEnElTexto);


// Borra la linea en la posicion indicada.
TipoRetorno BorrarLinea(Posicion posicionLinea, 
						nlinea &pgTexto,
						int  &gLineasEnElTexto);


// Imprime el texto por pantalla.
TipoRetorno ImprimirTexto(nlinea pgTexto);


// Inserta una palabra en una linea.
TipoRetorno InsertarPalabraEnLinea(int  &gLineasEnElTexto,
								   nlinea &pgTexto,
								   Posicion posicionLinea, 
								   Posicion posicionPalabra, 
								   Cadena   palabraAIngresar);


// Imprime la linea por pantalla.
TipoRetorno ImprimirLinea(Posicion posicionLinea, 
						  nlinea &pgTexto,
						  int  &gLineasEnElTexto);


// Borra la palabra en la posicion indicada.
TipoRetorno BorrarPalabra(Posicion posicionLinea, 
						  Posicion posicionPalabra,
						  nlinea &pgTexto,
						  int  &gLineasEnElTexto);


// Insertar linea en posicion
TipoRetorno InsertarLineaEnPosicion(Posicion posicionLinea,
									nlinea &pgTexto,
									int  &gLineasEnElTexto);


// Borra todas las lineas del texto.
TipoRetorno BorrarTodo(nlinea &pgTexto, int  &gLineasEnElTexto);


// Borra todas las ocurrencias de una palabra en la linea indicada.
TipoRetorno BorrarOcurrenciasPalabraEnLinea(Posicion posicionLinea,
											Cadena palabraABorrar,
											nlinea &pgTexto,
											int  &gLineasEnElTexto);


// Borra todas las ocurrencias de una palaba en el texto
TipoRetorno BorrarOcurrenciasPalabraEnTexto(Cadena palabraABorrar, 
											nlinea &pgTexto,
											int  &gLineasEnElTexto);



//// ---------------------------------------
//// Metodos para el desarrollo del proyecto
//// ---------------------------------------


// Funcion para crear un nodo de palabra
npalabra nodoPalabraCrear(const char* palabra);


// Funcion para crear un nodo de linea
nlinea nodoLineaCrear();




// Funcion para buscar una palabra en una linea y obtener la posicion
Posicion buscaPalabraEnLinea(Posicion posicionLinea, 
							 Cadena palabraABuscar, 
							 nlinea &pgTexto,
							 int  &gLineasEnElTexto);


// Funcion para comprimir texto
TipoRetorno ComprimirTexto(nlinea &pgTexto,int  &gLineasEnElTexto);


// Funcion complementaria para usar en el main y mostrar el resultado de RETURN
void muestroResultado(int retorno);



// Funciones para la 2da parte DICCIONARIO

diccionario IngresarPalabraDiccionario(diccionario nodo, const char *D);

diccionario BorrarPalabraDiccionario(diccionario nodo, const char *D);

void  ImprimirDiccionario (diccionario nodo);

TipoRetorno ImprimirTextoIncorrecto();
