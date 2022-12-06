// Tipos de datos a manejar (dado por letra del trabajo y auxiliares)	
// -------------------------------------------

typedef char* Cadena;

// Enumerado para los valores de Retorno de las funciones
enum _retorno{
	
	OK,              // Se produjo la accion
	ERROR,           // Hubo un error en la accion
	NO_IMPLEMENTADA  // No se encuentra implementada
};

// El Tipo de datos para los valores de _retorno
typedef enum _retorno TipoRetorno;

// Posicion de la palabra
typedef unsigned int Posicion;



// Estructuras de los Nodos
// ------------------------

// Nodo para las palabras
typedef struct nodoPalabra{
	
	Cadena       contenido;
	nodoPalabra *siguientePalabra;
} *npalabra;

// Nodo para las lineas
typedef struct nodoLinea{
	
	// Puntero a la siguiente palabra
	nodoLinea *siguienteLinea;
	
	// Puntero a su primera palabra
	npalabra siguientePalabra;
	
	// Palabras en la linea
	int palabras=0;
} *nlinea;


// Estructuras para la 2da parte DICCIONARIO

typedef struct _nodoDiccionario
{
	struct _nodoDiccionario *izq;
	struct _nodoDiccionario *der;
	char *D;
} *diccionario;
