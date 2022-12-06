// -------------------------------------------
// Proyecto: Simulador de editor de textos
// Materia : Algoritmos y Estructuras de Datos
// Alumno: Steven Pereira

// ----------------------------------------------
// Consideraciones generales
// ----------------------------------------------
// 1.- El texto esta¡ compuesto por 0 o mas lineas.
// 2.- No hay limite en la cantidad de lineas a manejar.
// 3.- La linea esta¡ compuesta por 0 o mas palabras.
// 4.- La cantidad maxima de palabras por linea esta definida por una 
//     constante del sistema (MAX_CANT_PALABRAS_X_LINEA). La cual se encuentra en un archivo de cabecera.
// 5.- Las palabras no deben tener espacios en blanco.
// 6.- En una linea, las palabras existentes deben ocupar posiciones consecutivas, desde la posicion 1 (no hay huecos posibles entre palabras).
// 7.- Se deben ignorar mayusuculas y minusculas para las palabras. Pero los comandos del editor que muestren texto deben hacerlo segun este sea 
//     ingresado (respetando mayusuculas y minusculas).
// 8.- Al iniciar el sistema el texto sera vacio (0 lineas) y el diccionario ortografico no contendra palabras.

// Librerias
#include "librerias.h"

// Constantes
#include "constantes.h"

// Tipos
#include "tipos.h"

// Prototipos de funciones
#include "funciones.h"

// Programa Principal
int main(int argc, char *argv[])
{
	nlinea pgTexto = nullptr;
	int  gLineasEnElTexto = 0;
	
	
	diccionario raiz = NULL;
	char D[MAX_LARGO_PALABRA];
	
	int numOper = 0;
	bool salir = false;
	TipoRetorno retorno = NO_IMPLEMENTADA;
	Posicion posicionLinea = 0;
	Posicion posicionPalabra = 0;
	char opcion = 'n';
	Cadena palabraAux = NULL;
	
	do {
		
		system ("cls");

		cout <<"Procesador de Textos - EDA - Steven Pereira\n\n" << endl;
		
		cout <<"Lista de operaciones disponibles:\n" << endl;
		cout <<"1)  InsertarLinea" << endl;
		cout <<"2)  InsertarLineaEnPosicion" << endl;
		cout <<"3)  BorrarLinea" << endl;
		cout <<"4)  BorrarTodo" << endl;
		cout <<"5)  BorrarOcurrenciasPalabraEnTexto" << endl;
		cout <<"6)  ImprimirTexto" << endl;
		cout <<"7)  InsertarPalabraEnLinea" << endl;
		cout <<"8)  BorrarPalabra" << endl;
		cout <<"9)  BorrarOcurrenciasPalabraEnLinea" << endl;
		cout <<"10) buscaPalabraEnLinea" << endl;
		cout <<"11) ImprimirLinea" << endl;
		cout <<"12) ComprimirTexto" << endl;
		cout <<"13) IngresarPalabraDiccionario" << endl;
		cout <<"14) BorrarPalabraDiccionario" << endl;
		cout <<"15) ImprimirDiccionario" << endl;
		cout <<"16) Salir\n\n" << endl;
		
		cout << "Ingrese el numero de la operacion a realizar: ";
		fflush(stdin);
		scanf("%d", &numOper);
		
		switch (numOper){
		case 1:
			retorno = InsertarLinea(pgTexto, gLineasEnElTexto);
			muestroResultado(retorno);
			break;
		case 2:
			cout << "Ingrese la posicion de la nueva linea: ";
			fflush(stdin);
			scanf("%d", &posicionLinea);
			fflush(stdin);
			retorno = InsertarLineaEnPosicion(posicionLinea,pgTexto,gLineasEnElTexto);
			muestroResultado(retorno);
			break;
		case 3:
			cout << "Ingrese la posicion de la linea que quiere borrar: ";
			fflush(stdin);
			scanf("%d", &posicionLinea);
			retorno = BorrarLinea(posicionLinea, pgTexto, gLineasEnElTexto);
			muestroResultado(retorno);
			break;                
		case 4:
			cout << "Esta seguro de que desea borrar todas las lineas del texto (s/n)?: ";                  
			fflush(stdin);
			scanf("%c", &opcion);
			if (opcion == 's' || opcion == 'S'){
				retorno = BorrarTodo(pgTexto,gLineasEnElTexto);
				muestroResultado(retorno);
			}
			break;
		case 5:                
			cout << "Ingrese la palabra que desea borrar: ";
			palabraAux = new char[MAX_LARGO_PALABRA];
			fflush(stdin);
			scanf("%s", palabraAux);
			retorno = BorrarOcurrenciasPalabraEnTexto(palabraAux,pgTexto,gLineasEnElTexto);
			muestroResultado(retorno);
			delete palabraAux;
			break;
		case 6:
			retorno =  ImprimirTexto(pgTexto);
			muestroResultado(retorno);
			break;
		case 7:
			cout << "Ingrese la palabra que desea agregar: ";
			palabraAux = new char[MAX_LARGO_PALABRA];
			fflush(stdin);
			scanf("%s", palabraAux);
			cout << "Ingrese la posicion de la linea donde la va a agregar: ";
			fflush(stdin);
			scanf("%d", &posicionLinea);
			cout << "Ingrese la posicion que debe tener la palabra dentro de las palabras de la linea: ";
			fflush(stdin);
			scanf("%d", &posicionPalabra);
			retorno = InsertarPalabraEnLinea(gLineasEnElTexto,pgTexto,posicionLinea,posicionPalabra,palabraAux);
			muestroResultado(retorno);
			delete palabraAux;
			break;
		case 8:
			cout << "Ingrese la posicion de la linea donde se encuentra la palabra a borrar: ";
			fflush(stdin);
			scanf("%d", &posicionLinea);
			cout << "Ingrese la posicion de la palabra a borrar: ";
			fflush(stdin);
			scanf("%d", &posicionPalabra);
			retorno = BorrarPalabra(posicionLinea,posicionPalabra, pgTexto, gLineasEnElTexto);
			muestroResultado(retorno);
			break;
		case 9:
			cout << "Ingrese la palabra que desea borrar: ";
			palabraAux = new char[MAX_LARGO_PALABRA];
			fflush(stdin);
			scanf("%s", palabraAux);
			cout << "Ingrese la posicion de la linea donde se debe borrar la palabra: ";
			fflush(stdin);
			scanf("%d", &posicionLinea);
			retorno =  BorrarOcurrenciasPalabraEnLinea(posicionLinea, palabraAux , pgTexto ,gLineasEnElTexto);
			muestroResultado(retorno);
			delete palabraAux;
			break;
		case 11:
			cout << "Ingrese la posicion de la linea que desea imprimir: ";
			fflush(stdin);
			scanf("%d", &posicionLinea);
			retorno =  ImprimirLinea(posicionLinea,pgTexto,gLineasEnElTexto);
			muestroResultado(retorno);
			break;

			
		case 12:
			cout << "Desea comprimir el texto (s/n)?: ";
				fflush(stdin);
			scanf("%c", &opcion);
			if (opcion == 's' || opcion == 'S'){
				retorno = ComprimirTexto(pgTexto,gLineasEnElTexto);
				muestroResultado(retorno);
			}
			break;
			
		case 13:
			cout << "Ingrese la palabra que desea agregar al diccionario: ";
			scanf ("%s", D);
			raiz = IngresarPalabraDiccionario (raiz, D);
			break;          
			
		case 14:
			cout <<"Ingrese la palabra que desea borrar del diccionario: ";
			scanf ("%s", D);
			raiz = BorrarPalabraDiccionario (raiz, D);
			break;
			
		case 15:
			ImprimirDiccionario(raiz);
			break;
				
		case 16:
			cout << "Esta seguro de que desea salir (s/n)?: ";                  
			fflush(stdin);
			scanf("%c", &opcion);
			if (opcion == 's' || opcion == 'S'){
				cout << "Saliendo...\n"; 
				salir = true;
			}
			break;
		default:
			cout <<"\n\nNo ingreso una opcion valida, vuelva a intentarlo!\n\n";
		}
		
		printf("\n");
		system("PAUSE");
		
		system("cls");
		
	} while (!salir);
	
	return EXIT_SUCCESS;
}

// -----------------------------
// Funciones desarrolladas
// -----------------------------

// Funcion apra crear un nodo de palabra
npalabra nodoPalabraCrear(const char* palabra){
    
    int longitudPalabra; // Variable para la longitud de la palabra

    npalabra nvaPalabra; // Creo el puntero a la nueva palabra
    
    nvaPalabra = new nodoPalabra; // Creo el dato

    if ( nvaPalabra == nullptr ){
        
        cout << "\nError en nodoPalabraCrear. Falla al liberar memoria con new.\n" << endl; // Error
	
        exit(1); // Salida del Programa
    }

    longitudPalabra = strlen(palabra)+1; // Obtengo la longitud de la palabra

    nvaPalabra->contenido = (char*) malloc(longitudPalabra * sizeof(char)); // Reservo memoria para el contenido

    if (nvaPalabra->contenido == NULL){ // Verifica que haya podido reservar la memoria
        
        cout << "\nError en nodoPalabraCrear. Falla al liberar memoria con malloc.\n" << endl; // Error
        
        exit(1); // Salida del programa
    }

    strcpy(nvaPalabra->contenido,palabra); // Copio la palabra al nodo 
	
    nvaPalabra->siguientePalabra=nullptr; // Asigno a null el puntero de siguiente

    return nvaPalabra; // Retorna la nueva palabra
}


// Funcion para crear un nodo de linea
nlinea nodoLineaCrear(){
    
    nlinea nvaLinea; // Creo el puntero a la nueva linea

    nvaLinea = new nodoLinea; // Creo el dato

    if ( nvaLinea == nullptr ){
        
        cout << "\nError en nodoLineaCrear. Falla al liberar memoria con new\n" << endl; // Error
        
        exit(1); // Salida del Programa
    }

    // Asigno a null el puntero de siguiente
    nvaLinea->siguienteLinea   = nullptr;
    nvaLinea->siguientePalabra = nullptr;

    return nvaLinea; // Retorna la nueva linea
}

// Inserta una nueva linea vacia al final del texto.
TipoRetorno InsertarLinea(nlinea &pgTexto, int  &gLineasEnElTexto){
	
    nlinea pTemporal= nullptr; // Variable temporal para recorrer el texto

    nlinea nuevaLinea; // Declara un objeto para nueva linea
    
    nuevaLinea = nodoLineaCrear(); // Crea una nueva linea

    if (pgTexto==nullptr){ // Verifica si no hay lineas, para agregar al inicio
        
        pgTexto = nuevaLinea; // Si tiene lineas, hace que apunte a la nueva linea
	}else{
        
        pTemporal = pgTexto; 

        while (pTemporal->siguienteLinea != nullptr) // Ciclo para recorrer las lineas del texto
            
            pTemporal = pTemporal->siguienteLinea; // Se mueve a la siguiente linea

        pTemporal->siguienteLinea = nuevaLinea;   // Ya que ha llegado al final, la agrega
    }

    gLineasEnElTexto++; // Incrementa el Contador de Lineas
	
    return OK; // Retorna OK
}

// Imprime el texto por pantalla.
TipoRetorno ImprimirTexto(nlinea pgTexto){
	
    int contadorLineas = 1; // Variable para el conteo de lineas

    nlinea pTmpLinea = nullptr; // Variable temporal para recorrer el texto

    npalabra pTmpPalabra = nullptr; // Variable temporal para recorrer las palabdas
	
    if (pgTexto==nullptr){ // Verifica que hay texto
        
        cout << "\nEl texto esta vacio.\n" << endl; // Imprime que esta vacio el texto
    }else{
        
        pTmpLinea = pgTexto; // Le asignamo el puntero del texto

        while (pTmpLinea != nullptr){ // Ciclo para recorrer e imprimir las lineas del texto
		
            cout << contadorLineas++ << ":["<< pTmpLinea->palabras <<"]"; // Imprime el numero de la linea

            pTmpPalabra = pTmpLinea->siguientePalabra; // Obtiene el puntero a la siguiente palabra

            while(pTmpPalabra!=nullptr){ // Ciclo para imprimir cada palabra en la linea
                
                cout << pTmpPalabra->contenido << " "; // Imprime la palabra

                pTmpPalabra = pTmpPalabra->siguientePalabra; // Se mueve a la siguiente palabra
            }

            pTmpLinea = pTmpLinea->siguienteLinea; // Se mueve a la siguiente linea

            cout << endl; // Cambia de linea
        }
    }
    cout << endl; // Cambia de linea

    return OK; // Retornamos
}

// Inserta una palabra en una linea.
TipoRetorno InsertarPalabraEnLinea(int  &gLineasEnElTexto, 
								   nlinea &pgTexto,
								   Posicion posicionLinea, 
                                   Posicion posicionPalabra, 
                                   Cadena   palabraAIngresar){
    
    _retorno resultado = OK; // Variable para resultado
	
    char palabraRecorrer[255]; // Variable temporal para recorrer la ultima palabra

    int contadorLineas = 1; // Variable para contar las lineas

    int contadorPalabras = 1; // Variable para contar las palabras

    npalabra nvaPalabra; // Variable para la nueva palabra

    nlinea pTmpLinea = nullptr; // Variable temporal para recorrer el texto

    npalabra pTmpPalabra = nullptr; // Variable temporal para recorrer las palabdas

    if (posicionLinea<0 || posicionLinea>gLineasEnElTexto){ // Verifica que quiera insertar en una linea correcta
        
        cout << "\nError en InsertarPalabraEnLinea: posicionLinea ["<< posicionLinea << "] es incorrecta!\n" << endl; // Despliega el mensaje de error

        resultado = ERROR; // Coloca el valor del resultado
    }else{
        
        if (posicionPalabra <= 0 || posicionPalabra > MAX_CANT_PALABRAS_X_LINEA){ // Valida que no sea menor igual que 0
            
            cout << "\nError en InsertarPalabraEnLinea: posicionPalabra ["<< posicionPalabra<< "] es incorrecta!\n" << endl; // Despliega el mensaje de error

            resultado = ERROR; // Coloca el valor del resultado
        }else{
            
            pTmpLinea = pgTexto; // Le asignamos el puntero del texto

            
            while (contadorLineas < posicionLinea){ // Ciclo para recorrer e ir a la linea indicada
                
                contadorLineas++; // Incrementa el contador de lineas

                pTmpLinea = pTmpLinea->siguienteLinea; // Se mueve a la siguiente linea
            }            
            if (posicionPalabra > pTmpLinea->palabras + 1){ // Verifica en la linea cuantas palabras hay
                
                cout << "\nError en InsertarPalabraEnLinea: posicionPalabra ["<< posicionPalabra<< "] es incorrecta!\n" << endl; // Despliega el mensaje de error

                resultado = ERROR; // Coloca el valor del resultado
            }else{
                
                nvaPalabra = nodoPalabraCrear(palabraAIngresar); // Creo la palabra

                if (pTmpLinea->palabras< MAX_CANT_PALABRAS_X_LINEA){ // Verifica que todavia hay espacio para la linea
                    
                    if (posicionPalabra==1){ // Verificamos si es la primera palabra
                        
                        nvaPalabra->siguientePalabra = pTmpLinea->siguientePalabra; // La nueva palabra su siguiente apunta a donde apunta el tmp

                        pTmpLinea->siguientePalabra = nvaPalabra; // Apuntamos la linea a la primera palabra
                    }else{
                       
                        pTmpPalabra = pTmpLinea->siguientePalabra;  // Obtengo el enlace a la primera palabra

                        while (contadorPalabras< posicionPalabra-1){ // Ciclo para ir a la palabra indicada
                              
                              pTmpPalabra = pTmpPalabra->siguientePalabra; // Se mueve a la siguiente palabra
							  
                              contadorPalabras++; // Incrementa el Contador
                        }
                        nvaPalabra->siguientePalabra = pTmpPalabra->siguientePalabra; // Actualiza la nueva palabra
                    
                        pTmpPalabra->siguientePalabra = nvaPalabra; // La palabra donde estoy apunta a la nueva palabra                
                    }

                    pTmpLinea->palabras++; //  Incrementa el contador de palabras de la linea
                }else{
                    
                    if (posicionPalabra==MAX_CANT_PALABRAS_X_LINEA){ // Verifica si es la ultima palabra en donde va a insertar
                        
                        cout << "\nBuscando la ultima palabra...\n" << endl; // Busco la ultima palabra

                        pTmpPalabra = pTmpLinea->siguientePalabra; // Obtengo el enlace a la primera palabra

                        while (contadorPalabras< posicionPalabra-1){ // Ciclo para ir a la palabra indicada 
                            
                            pTmpPalabra = pTmpPalabra->siguientePalabra; // Se mueve a la siguiente palabra

                            contadorPalabras++; // Incrementa el Contador
                        }

                        strcpy(palabraRecorrer,pTmpPalabra->siguientePalabra->contenido); // Obtengo la ultima palabra
                        cout << "\nLa ultima palabra es: " << palabraRecorrer << "\n" << endl;

                        delete(pTmpPalabra->siguientePalabra); // Elimino el nodo

                        pTmpPalabra->siguientePalabra = nvaPalabra; // Hago que ahora apunte a la nueva palabra

                        if (posicionLinea==gLineasEnElTexto){ // Verifico si estoy en la ultima linea
                            
                            InsertarLinea(pgTexto,gLineasEnElTexto); // Inserto una nueva linea

                            InsertarPalabraEnLinea(gLineasEnElTexto,pgTexto, gLineasEnElTexto,1,palabraRecorrer); // Coloco la palabra a recorrer en la nueva linea
                        }else{
							
                            
                            InsertarPalabraEnLinea(gLineasEnElTexto,pgTexto, posicionLinea+1,1,palabraRecorrer); // Coloco la palabra a recorrer en la nueva linea
                        }
                    }else{
                        // Insercionn en medio con recorrido de la ultima palabra
                        // Busco la palabra donde insertar
                        cout << "\nBuscando donde insertar palabra en medio...\n" << endl;

                        
                        pTmpPalabra = pTmpLinea->siguientePalabra; // Obtengo el enlace a la primera palabra

                        while (contadorPalabras< posicionPalabra-1){ // Ciclo para ir a la palabra indicada
                            
                            pTmpPalabra = pTmpPalabra->siguientePalabra; // Se mueve a la siguiente palabra

                            contadorPalabras++; // Incrementa el Contador
                        }

                        nvaPalabra->siguientePalabra = pTmpPalabra->siguientePalabra; // La nueva palabra apunta a donde esta apuntando la actual

                        pTmpPalabra->siguientePalabra = nvaPalabra; // La palabra previa apunta al nuevo nodo

                        while (pTmpPalabra->siguientePalabra->siguientePalabra!=nullptr){ // Ir a la penultima palabra
                            
                            pTmpPalabra = pTmpPalabra->siguientePalabra; // Se mueve al siguiente
                        }

                        strcpy(palabraRecorrer,pTmpPalabra->siguientePalabra->contenido); // Obtengo la palabra a recorrer
                        cout << "\nUltima palabra la cual se recorre: " << palabraRecorrer << "\n" << endl;

                        delete(pTmpPalabra->siguientePalabra); // Elimino el Nodo

                        pTmpPalabra->siguientePalabra = nullptr; // Apunta a null la ultima palabra

                        if (posicionLinea==gLineasEnElTexto){ // Verifico si estoy en la ultima linea
                            
                            InsertarLinea(pgTexto,gLineasEnElTexto); // Inserto una nueva linea

                            InsertarPalabraEnLinea(gLineasEnElTexto,pgTexto, gLineasEnElTexto,1,palabraRecorrer); // Coloco la palabra a recorrer en la nueva linea
                        }else{

                            
                            InsertarPalabraEnLinea(gLineasEnElTexto,pgTexto, posicionLinea+1,1,palabraRecorrer); // Coloco la palabra a recorrer en la nueva linea
                        }
                    }                 
                }
            }
        }
    }
    return resultado; // Retorna
}

// Borra la linea en la posicion indicada
TipoRetorno BorrarLinea(Posicion posicionLinea,
						nlinea &pgTexto,
						int  &gLineasEnElTexto){
    
    _retorno resultado=OK; // Declara e inicializa la variable de resultado
	
    int contadorLineas = 1; // Variable para contar lineas

    // Variable temporal para recorrer el texto
    nlinea pTmpLinea     = nullptr;
    nlinea pTmpLineaPrev = nullptr;

    // Variable temporal para recorrer las palabdas
    npalabra pTmpPalabra    = nullptr;
    npalabra pTmpPalabraAux = nullptr;

    if (posicionLinea>0 && posicionLinea<=gLineasEnElTexto){ // Verifica que sea una linea correcta
        
        pTmpLinea = pgTexto; // Le asignamos el puntero del texto

        pTmpLineaPrev = pTmpLinea; // Guardo la linea previa

        while (contadorLineas < posicionLinea){ // Ciclo para recorrer e ir a la linea indicada
            
            contadorLineas++; // Incrementa el contador de lineas

            pTmpLineaPrev = pTmpLinea; // Guardo la linea previa

            pTmpLinea = pTmpLinea->siguienteLinea; // Se mueve a la siguiente linea
        }  

        if (posicionLinea==1){ // Verifica si es la linea 1 para mover el puntero del Texto
            
            pgTexto = pTmpLineaPrev->siguienteLinea; // Mueve el puntero a la siguiente linea
        }

        pTmpLineaPrev->siguienteLinea = pTmpLinea->siguienteLinea; // Linea Previa apunta a la siguiente de la que se elimina

        pTmpPalabra = pTmpLinea->siguientePalabra; // Obtengo el puntero a la primera palabra

        while (pTmpPalabra!=nullptr){ // Ciclo para eliminar los nodos
            
            pTmpPalabraAux = pTmpPalabra->siguientePalabra; // Obtengo el puntero a siguiente palabra en el auxiliar

            delete(pTmpPalabra); // Elimino el nodo

            pTmpPalabra = pTmpPalabraAux; // Recorro el nodo
        }
    }else{
        
        cout << "\nError en BorrarLinea: posicionLinea ["<< posicionLinea<< "] es incorrecta!\n"; // Mensaje de Error

        resultado = ERROR; // Cambia el resultado
    }
    gLineasEnElTexto--; // Decrementa el contador de lineas
	
    return resultado; // Retorna el resultado
}

// Imprime la linea por pantalla.
TipoRetorno ImprimirLinea(Posicion posicionLinea, 
						  nlinea &pgTexto, 
						  int  &gLineasEnElTexto){
    
    _retorno resultado= OK; // Variable de resultado
	
    nlinea pTmpLinea = nullptr; // Variable temporal para recorrer el texto

    npalabra pTmpPalabra = nullptr; // Variable temporal para recorrer las palabdas

    int contadorLineas = 1; // Contador de lineas

    if (posicionLinea>0 && posicionLinea<=gLineasEnElTexto){ // Verifica que sea una linea correcta        
        
        pTmpLinea = pgTexto; // Le asignamo el puntero del texto

        while (contadorLineas < posicionLinea){ // Ciclo para recorrer e ir a la linea indicada
            
            contadorLineas++; // Incrementa el contador de lineas

            pTmpLinea = pTmpLinea->siguienteLinea; // Se mueve a la siguiente linea
        }  

        cout << contadorLineas << "[" << pTmpLinea->palabras << "]:"; // Imprime la linea

        pTmpPalabra = pTmpLinea->siguientePalabra; // Obtiene el puntero a la siguiente palabra

        while(pTmpPalabra!=nullptr){ // Ciclo para imprimir cada palabra en la linea
            
            cout << pTmpPalabra->contenido << " "; // Imprime la palabra

            pTmpPalabra = pTmpPalabra->siguientePalabra; // Se mueve a la siguiente palabra
        }

        cout << endl << endl; // Termina de imprimir

    }else{
        
        cout << "\nError en BorrarLinea: posicionLinea ["<< posicionLinea<< "] es incorrecta!\n"; // Mensaje de error

        resultado = ERROR; // Cambia el resultado
    }
    return resultado; // Retorna el resultado
}

// Borra la palabra en la posicion indicada.
TipoRetorno BorrarPalabra(Posicion posicionLinea, 
                          Posicion posicionPalabra,
						  nlinea &pgTexto,
						  int  &gLineasEnElTexto){
    
    _retorno resultado; // Variable de Resultado

    nlinea pTmpLinea = nullptr; // Variable temporal para recorrer el texto

    npalabra pTmpPalabra = nullptr;  // Variable temporal para recorrer las palabras
	
    npalabra pTmpPalabraPrev = nullptr; // Variable temporal previa para recorrer las palabras

    int contadorLineas  = 1; // Contador de Lineas

    int contadorPalabras = 1; // Contador de Palabras

    if (posicionLinea>0 && posicionLinea<=gLineasEnElTexto){  // Verifica que sea una linea correcta      
        
        pTmpLinea = pgTexto; // Le asignamo el puntero del texto

        while (contadorLineas < posicionLinea){ // Ciclo para recorrer e ir a la linea indicada
            
            contadorLineas++; // Incrementa el contador de lineas

            pTmpLinea = pTmpLinea->siguienteLinea; // Se mueve a la siguiente linea
        }  

        if (pTmpLinea->palabras>=posicionPalabra){ // Verifica que la palabra sea correcta
            
            if (posicionPalabra == 1){ // Verifica si es la palabra 1
                
                pTmpPalabraPrev = pTmpLinea->siguientePalabra; // Obtengo la primera palabra para borrarloa

                pTmpLinea->siguientePalabra = pTmpLinea->siguientePalabra->siguientePalabra; // Apunta a siguiente palabra

                delete(pTmpPalabraPrev); // Borro el Nodo
            }else{
                
                pTmpPalabra = pTmpLinea->siguientePalabra; // Obtiene el puntero guiente palabra

                while(contadorPalabras<posicionPalabra) { // Ciclo para imprimir cada palabra en la linea
                    
                    pTmpPalabraPrev = pTmpPalabra; // Guarda el Previo

                    pTmpPalabra = pTmpPalabra->siguientePalabra; // Se mueve a la siguiente palabra

                    contadorPalabras++; // Incrementa el contador de palabras
                }

                pTmpPalabraPrev->siguientePalabra = pTmpPalabra->siguientePalabra; // Hacemos que la siguiente del previo apunte al siguiente de la actual

                delete(pTmpPalabra); // Borramos el Nodo
            }

            pTmpLinea->palabras--;  // Decrementa el contador de palabras de la linea           
        }else{
            
            cout << "\nError en BorrarPalabra: posicionPalabra ["<< posicionPalabra<< "] es incorrecta!\n" << endl; // Mensaje de Error

            resultado = ERROR; // Cambia el resultado
        }        
    }else{
        
        cout << "\nError en BorrarPalabra: posicionLinea ["<< posicionLinea<< "] es incorrecta!\n"; // Mensaje de Error

        resultado = ERROR; // Cambia el resultado
    }

    return resultado; // Retorna el resultado
}

// Insertar Linea en Posicion
TipoRetorno InsertarLineaEnPosicion(Posicion posicionLinea, 
									nlinea &pgTexto,
									int  &gLineasEnElTexto){
    
    _retorno resultado = OK; // Variable de resultado

    nlinea pTmpLinea = nullptr; // Variable temporal para recorrer el texto 

    int contadorLineas = 1; // Contador de Lineas

    nlinea nuevaLinea; // Declara un objeto para nueva linea;
	
    if (posicionLinea>0 && posicionLinea<=gLineasEnElTexto+1){ // Verifica la posicion de la linea
        
        if (posicionLinea==gLineasEnElTexto+1){ // Verifica si la quiere insertar al final
			
            InsertarLinea(pgTexto,gLineasEnElTexto); // Llama a insertar linea
        }else{        
            
            nuevaLinea = nodoLineaCrear(); // Crea una nueva linea
			
            if (posicionLinea==1){ // Verifica que sea la posicion 1
                
                nuevaLinea->siguienteLinea = pgTexto; // La nueva linea apunta a donde apunta el inicio del texto
                
                pgTexto = nuevaLinea; // El puntero general apunta a la nueva linea
            }else{
                
                pTmpLinea = pgTexto; // Coloco el puntero del etxto en el temporal

                while (contadorLineas<posicionLinea-1){ // Ciclo para ir a la linea previa
                    
                    pTmpLinea = pTmpLinea->siguienteLinea; // Se desplaza a la siguiente linea

                    contadorLineas++; // Incrementa el contador
                }
                nuevaLinea->siguienteLinea = pTmpLinea->siguienteLinea; // Coloco el puntero actual en el auxiliar

                pTmpLinea->siguienteLinea = nuevaLinea; // Muevo el puntero al siguiente siguiente

            }
            gLineasEnElTexto++; // Se incrementa el contador de lineas
        }
    }else{
        
        cout << "\nError en InsertarLineaEnPosicion: posicionLinea ["<< posicionLinea<< "] es incorrecta!\n"; // Mensaje de Error

        resultado = ERROR; // Cambia el resultado
    }
    return resultado; // retorna el resultado
}

// Borra todas las lineas del texto.
TipoRetorno BorrarTodo(nlinea &pgTexto, int  &gLineasEnElTexto){
    
    _retorno resultado = OK; // Variable de Resultado

    if (gLineasEnElTexto>0){ // Verifica que haya lineas
        
        while(gLineasEnElTexto>0){ // Ciclo para borrar todas las lineas
            
            if (BorrarLinea(1, pgTexto, gLineasEnElTexto)==ERROR){ // Elimina la linea 1 siempre
                
                cout << "\nError en BorrarTodo. Error inesperado!\n" << endl; // Mensaje

                resultado = ERROR; // Cambia el retorno

                break; // Sale del Ciclo
            }
        }
    }else{
        cout << "\nEl Texto no contiene lineas!\n" << endl; // Mensaje        
    }
    return resultado; // Retorna el Resultado
}

// Funcion para buscar una palabra en una linea y obtener la posicion
Posicion buscaPalabraEnLinea(Posicion posicionLinea,
							 Cadena palabraABuscar,
							 nlinea &pgTexto,
							 int  &gLineasEnElTexto){
    
    Posicion resultado = 0; // Variable para el resultado

    nlinea pTmpLinea = nullptr; // Variable temporal para recorrer el texto

    npalabra pTmpPalabra = nullptr; // Variable temporal para recorrer las palabras

    int contadorLineas  = 1; // Contador de Lineas

    bool encontro = false; // Variable para saber si la encontro
	
    if (posicionLinea>0 && posicionLinea<=gLineasEnElTexto){ // Verifica que sea una linea correcta        
	
        pTmpLinea = pgTexto; // Le asignamos el puntero del texto

        while (contadorLineas < posicionLinea){ // Ciclo para recorrer e ir a la linea indicada
            
            contadorLineas++; // Incrementa el contador de lineas
			
            pTmpLinea = pTmpLinea->siguienteLinea; // Se mueve a la siguiente linea
        }  

        pTmpPalabra = pTmpLinea->siguientePalabra; // Obtiene el puntero a la primera siguiente palabra

        while(pTmpPalabra!=nullptr){ // Ciclo para imprimir cada palabra en la linea
           
            resultado++;  // Incrementa el Contador

            if (strcmp(pTmpPalabra->contenido,palabraABuscar)==0){ // Verifica si es la palabra a buscar
                
                cout << "\nLa palabra fue encontrada en la posicion: "<< resultado << endl; // Mensaje

                encontro = true; // Cambia el estado de encontrado
				
                break;// Sale del Ciclo
            }else{
                
                pTmpPalabra = pTmpPalabra->siguientePalabra; // Se mueve a la siguiente palabra
            }
        }    
		
        if (!encontro){ // Verifica si no lo encontro para colocar 0
            
            cout << "\nLa palabra " << palabraABuscar << " no fue encontrada!\n" << endl;

            resultado = 0; // Coloca en 0 el resultado
        }               
    }else{
        
        cout << "\nError en BorrarPalabra: posicionLinea ["<< posicionLinea<< "] es incorrecta!\n"; // Mensaje de Error

        resultado = -1; // Cambia el resultado
    }
    return resultado; // Devuelve el resultado
}

// Borra todas las ocurrencias de una palabra en la linea indicada.
TipoRetorno BorrarOcurrenciasPalabraEnLinea(Posicion posicionLinea,
                                            Cadena   palabraABorrar,
											nlinea &pgTexto,
											int  &gLineasEnElTexto){
    
    _retorno resultado = OK; // Variable de Resultado

    int ocurrencias=0; // Contador de ocurrencias

    int posicionBorrar=1; // Posicion a borrar

    do { // Ciclo para borrar las ocurrencias de la palabra
        
        posicionBorrar = buscaPalabraEnLinea(posicionLinea,palabraABorrar, pgTexto,gLineasEnElTexto); // Obtiene la posicion a borrar

        if (posicionBorrar>0) { // Verifica si lo encontro
            
            BorrarPalabra(posicionLinea,posicionBorrar, pgTexto, gLineasEnElTexto); // Borra la palabra

            ocurrencias++; // Incrementa las ocurrencias
        }

    }while (posicionBorrar>0);
          
    cout << "\nLa Palabra " << palabraABorrar << " se ha eliminado " << ocurrencias << " veces!\n" << endl; // Despliega el mensaje

    return resultado; // Retorna el resultado
}                                            

// Borra todas las ocurrencias de una palaba en el texto
TipoRetorno BorrarOcurrenciasPalabraEnTexto(Cadena palabraABorrar, 
											nlinea &pgTexto,
											int  &gLineasEnElTexto){
    
    _retorno resultado; // Variable de Resultado

    int contadorLineas; // Variable para las lineas

    if (gLineasEnElTexto>0){ // Verifica que haya lineas
        
        for (contadorLineas=1; contadorLineas<=gLineasEnElTexto; contadorLineas++) { // Ciclo para buscar y eliminar ocurrencias en cada linea
            
            BorrarOcurrenciasPalabraEnLinea(contadorLineas,palabraABorrar, pgTexto, gLineasEnElTexto); // Busca y elimina en la linea
        }
    }else{
        
        cout << "\nEl Texto no tiene lineas!\n" << endl; // Mensaje
    }
    return resultado; // Devuelve el resultado
}


// Funcion para Comprimir Texto
TipoRetorno ComprimirTexto(nlinea &pgTexto,int  &gLineasEnElTexto){
    
    _retorno resultado = OK; // Variable de Resultado

    int lineasActuales; // Variable para el Numero de Lineas Actuales

    int contadorLineas = 1;  // Contador de Lineas

    int contadorPalabrasInsertadas = 1; // Contador de Palabras

    nlinea pTmpLinea     = nullptr; // Variable temporal para recorrer el texto

    npalabra pTmpPalabra = nullptr; // Variable temporal para recorrer las palabras

    if (gLineasEnElTexto > 1){ // Verifica que haya por lo menos 2 lineas
        
        lineasActuales = gLineasEnElTexto; // Obtiene las Lineas Actuales

        pTmpLinea = pgTexto; // Le asignamo el puntero del texto

        while (contadorLineas <= lineasActuales){ // Ciclo para recorrer e imprimir las lineas del texto                       
            
            pTmpPalabra = pTmpLinea->siguientePalabra; // Obtiene el puntero a la siguiente palabra

            while(pTmpPalabra!=nullptr){ // Ciclo para imprimir cada palabra en la linea
                
                if (contadorPalabrasInsertadas==1) // Verifica si debe insertar una linea
                   
                   InsertarLinea(pgTexto,gLineasEnElTexto); // Inserta una linea
            
                cout << "\nInsertando:"<< pTmpPalabra->contenido << " " << endl; // Imprime la palabra

                InsertarPalabraEnLinea(gLineasEnElTexto,pgTexto, gLineasEnElTexto,contadorPalabrasInsertadas,pTmpPalabra->contenido); // Llama a la funcion de insertar palabra

                if (contadorPalabrasInsertadas < MAX_CANT_PALABRAS_X_LINEA) // Verificamos si ya estamos en la maxima
                   
                   contadorPalabrasInsertadas++; // Incrementamos el contador
                else
                   
                   contadorPalabrasInsertadas = 1; // Lo inicializamos a 1   
                
                pTmpPalabra = pTmpPalabra->siguientePalabra; // Se mueve a la siguiente palabra
            }
            pTmpLinea = pTmpLinea->siguienteLinea; // Se mueve a la siguiente linea
			
            contadorLineas++; // Incrementa el contador de Lineas
        }
        
        for (contadorLineas=1; contadorLineas<=lineasActuales; contadorLineas++) // Ciclo para eliminar las lineas previas
            
            BorrarLinea(1, pgTexto, gLineasEnElTexto); // Elimina la Linea 1
    }else{
        
        cout << "\nEl Texto no tiene lineas!\n" << endl; // Mensaje
    }
    return resultado; // Retorna resultado
}
	
	
	char* strdup (const char* string){ //Asigna suficiente memoria para una copia del cadena str, hace la copia y le devuelve un puntero. Es el algoritmo de como funciona strdup que no se podía usar. 
		
		size_t longitudString = strlen(string);
		char* RESULTADO = (char*)malloc(longitudString + 1);
		if(RESULTADO == NULL){
			
			return NULL;
		}
		memcpy(RESULTADO, string, longitudString + 1);
		return RESULTADO;
	}

	// Funcion complementaria para usar en el main y mostrar el resultado de RETURN
	void muestroResultado(int retorno){
		switch(retorno){
		case OK:
			cout << "\nResultado: OK\n";
			break;
		case ERROR:
			cout << "\nResultado: ERROR\n";
			break;
		case NO_IMPLEMENTADA:
			cout << "\nResultado: NO_IMPLEMENTADA\n";
			break;
		}
		cout << endl << endl;
	}
		
		
	// Funciones desarrolladas para la 2da parte DICCIONARIO
		
// Funcion para agregar palabras al diccionario
diccionario IngresarPalabraDiccionario (diccionario nodo, const char *D){

	
	if (nodo == NULL){ //Si el nodo donde se va a agregar la palabra esta vacio
		
		nodo = (diccionario) malloc (sizeof (struct _nodoDiccionario));
		nodo->izq = NULL; //Nodo al hijo izquierdo null
		nodo->der = NULL; // nodo al hijo derecho null
		nodo->D = strdup(D); //devuelve un puntero a la cadena siendo este un duplicado
	}
	else if (strcmp (D, nodo->D) == 0){ // compara D con el nodo, si es == 0 significa que ya está ingresada la palabra al diccionario y da ERROR
		printf("\nResultado: ERROR\n");
	}
	else if (strcmp (D, nodo->D) < 0){ // Compara y lo agrega a la izquierda al ser D menor que nodo->D
		nodo->izq = IngresarPalabraDiccionario (nodo->izq, D);
	}else if (strcmp (D, nodo->D) > 0){ // Compara y lo agrega a la derecha al ser D mayor que nodo->D
		nodo->der = IngresarPalabraDiccionario (nodo->der, D);
	}return nodo;
}


// Funcion para borrar palabras de el diccionario
diccionario BorrarPalabraDiccionario (diccionario nodo, const char *D){
				
	diccionario auxiliar; // Auxiliar
	int comparacion; // Variable para la comparacion
	if (nodo != NULL){ // Si el nodo es distinto de NULL
		
		comparacion = strcmp (D, nodo->D); // Compara la palabra a borrar con el puntero para ver si esta
		if (comparacion==0){ 
			if (nodo->izq == NULL)
				auxiliar = nodo->der;
			else if (nodo->der == NULL)
				auxiliar = nodo->izq;
			else{
				for (auxiliar = nodo->izq; auxiliar->der != NULL; auxiliar = auxiliar->der);
					auxiliar->der = nodo->der;
					auxiliar = nodo->izq;
				}
				free (nodo->D);
				free (nodo);
				nodo = auxiliar;
		}
		else if (comparacion < 0)
			nodo->izq = BorrarPalabraDiccionario (nodo->izq, D);
		else
			nodo->der = BorrarPalabraDiccionario (nodo->der, D);
	}
	return nodo;
}
			
// Funcion para imprimir el diccionario INorder
void ImprimirDiccionario (diccionario nodo){
	
	if (nodo != NULL){ 
		
	// Imprime en orden alfabetico (InOrder)
		ImprimirDiccionario (nodo->izq);
		cout << nodo->D <<endl;
		ImprimirDiccionario (nodo->der);
	}
//	else{
//		cout <<"\nDiccionario vacio\n"<<endl;
//	}
}

	

