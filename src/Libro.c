
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libro.h"
#include "Editorial.h"
#include "parser.h"
#include "LinkedList.h"
#include "biblioteca.h"
/// @brief crea espacio en memoria de una variable tipo eLibro
///
/// @return
eLibro* libro_new(){
	eLibro* libro;
	libro=(eLibro*)calloc(1,sizeof(eLibro));
	return libro;
}
/// @brief setea el ID de un elemento del tipo eLibro
///
/// @param this puntero del elemento eLibro
/// @param id - lo que se va a setear
/// @return retorna 1 si esta ok
int libro_setId(eLibro* this,int id){
	int retorno;
	retorno=0;
	if(this!=NULL){
		this->id=id;
		retorno=1;
	}
	return retorno;
}
/// @brief setea el titulo de un elemento del tipo eLibro
///
/// @param this puntero del elemento eLibro
/// @param titulo - lo que se va a setear
/// @return retorna 1 si esta ok
int libro_setTitulo(eLibro* this,char* titulo){
	int retorno;
	retorno=0;
	if(this!=NULL){
		strcpy(this->titulo,titulo);
		retorno=1;
	}
	return retorno;
}
/// @brief setea el autor de un elemento del tipo eLibro
///
/// @param this puntero del elemento eLibro
/// @param autor- lo que se va a setear
/// @return retorna 1 si esta ok
int libro_setAutor(eLibro* this,char* autor){
	int retorno;
	retorno=0;
	if(this!=NULL){
		strcpy(this->autor,autor);
		retorno=1;
	}
	return retorno;
}
/// @brief setea el precio de un elemento del tipo eLibro
///
/// @param this puntero del elemento eLibro
/// @param precio - lo que se va a setear
/// @return retorna 1 si esta ok
int libro_setPrecio(eLibro* this,float precio){
	int retorno;
	retorno=0;
	if(this!=NULL){
		this->precio=precio;
		retorno=1;
	}
	return retorno;
}
/// @brief setea el IdEditorial de un elemento del tipo eLibro
///
/// @param this puntero del elemento eLibro
/// @param IdEditorial - lo que se va a setear
/// @return retorna 1 si esta ok
int libro_setIdEditorial(eLibro* this,int idEditorial){
	int retorno;
	retorno=0;
	if(this!=NULL){
		this->idEditorial=idEditorial;
		retorno=1;
	}
	return retorno;
}
/// @brief obtiene el valor de id de un elemento tipo eLibro
///
/// @param this puntero del elemento eLibro
/// @param id lo que obtiene
/// @return devuelve 1 si esta ok
int libro_getid(eLibro* this,int* id){
	int retorno;
	retorno=0;
	if(this!=NULL&&id!=NULL){
		*id=this->id;
		retorno=1;
	}
	return retorno;
}
/// @brief obtiene el valor de titulo de un elemento tipo eLibro
///
/// @param this puntero del elemento eLibro
/// @param titulo lo que obtiene
/// @return devuelve 1 si esta ok
int libro_getTitulo(eLibro* this,char* titulo){
	int retorno;
	retorno=0;
	if(this!=NULL&&titulo!=NULL){
		strcpy(titulo,this->autor);
		retorno=1;
	}
	return retorno;
}
/// @brief obtiene el autor de id de un elemento tipo eLibro
///
/// @param this puntero del elemento eLibro
/// @param autor lo que obtiene
/// @return devuelve 1 si esta ok
int libro_getAutor(eLibro* this,char* autor){
	int retorno;
	retorno=0;
	if(this!=NULL&&autor!=NULL){
		strcpy(autor,this->autor);
		retorno=1;
	}
	return retorno;
}
/// @brief obtiene el idEditorial de id de un elemento tipo eLibro
///
/// @param this puntero del elemento eLibro
/// @param idEditorial lo que obtiene
/// @return devuelve 1 si esta ok
int libro_getIdEditorial(eLibro* this,int* idEditorial){
	int retorno;
	retorno=0;
	if(this!=NULL&&idEditorial!=NULL){
		*idEditorial=this->idEditorial;
		retorno=1;
	}
	return retorno;
}
/// @brief obtiene el precio de id de un elemento tipo eLibro
///
/// @param this puntero del elemento eLibro
/// @param precio lo que obtiene
/// @return devuelve 1 si esta ok
int libro_getPrecio(eLibro* this,float* precio){
	int retorno;
	retorno=0;
	if(this!=NULL&&precio!=NULL){
		*precio=this->precio;
		retorno=1;
	}
	return retorno;
}

/// @brief crea un nuevo elemento del tipo eLibro y le setea todos los valores pasados por parametros
///
/// @param idStr	el id a setear en formato String
/// @param tituloStr titulo a setear en formato String
/// @param autorStr autor a setear en formato String
/// @param precioStr precio a setear en formato String
/// @param idEditorialStr idEditorial a setear en formato String
///
/// @return retorna el puntero al elemento
eLibro* Libro_NewParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr,char* idEditorialStr){
	eLibro* aux;
	if(idStr!=NULL&&tituloStr!=NULL&&autorStr!=NULL&&precioStr!=NULL&&idEditorialStr!=NULL){
		aux=libro_new();
		libro_setId(aux, atoi(idStr));
		libro_setTitulo(aux, tituloStr);
		libro_setAutor(aux, autorStr);
		libro_setPrecio(aux, atof(precioStr));
		libro_setIdEditorial(aux, atoi(idEditorialStr));
	}
	return aux;
}
/// @brief funcion para ordenar la lista por autor
///
/// @param ElementoUno primer elemento a checkear
/// @param ElementoDos segundo elemento a checkear
/// @return devuelve -1 si elemento 1 es mas chico, 1 si es mayor, 0 si son iguales.
int Libro_OrdernarAutor(void* ElementoUno,void* ElementoDos){
	int retorno;
	retorno=-5;
	eLibro* libroUno;
	eLibro* libroDos;
	char autorUno[128];
	char autorDos[128];
	if(ElementoUno!=NULL&&ElementoDos!=NULL){
		libroUno=(eLibro*)ElementoUno;
		libroDos=(eLibro*)ElementoDos;

		libro_getAutor(libroUno, autorUno);
		libro_getAutor(libroDos, autorDos);

		retorno=strcmpi(autorUno,autorDos);
	}

	return retorno;
}
/// @brief analiza el elemento y checkea si es de la editorial Minotauro
///
/// @param Element elemento void a checkear
/// @return  devuelve 1 si esta ok
int Libro_EsMinotauro(void* Element){
	int retorno;
	eLibro* libro;
	int idEditorial;
	retorno=0;

	libro=(eLibro*)Element;
	libro_getIdEditorial(libro, &idEditorial);

	if(idEditorial==4){
		retorno=1;
	}

	return retorno;
}
/// @brief checkea si el elemento esta en los parametros para aplicar el descuento
/// 		si es asi retorna el elemento con el precio con descuento.
///
///
/// @param element devuelve el elemento != NULL si aplica el descuento
void* Libro_Descuentos(void* element){
	eLibro* libroRetorno;
	float precioFinal;
	if(element!=NULL){
		libroRetorno=libro_new();
		libro_getAutor(element, libroRetorno->autor);
		libro_getIdEditorial(element, &libroRetorno->idEditorial);
		libro_getPrecio(element, &libroRetorno->precio);
		libro_getTitulo(element, libroRetorno->titulo);
		libro_getid(element, &libroRetorno->id);

		if(libroRetorno->idEditorial==1&&libroRetorno->precio>=300){
			precioFinal=libroRetorno->precio-(libroRetorno->precio*20/100);
			libro_setPrecio(libroRetorno, precioFinal);
		}
		else{
			if(libroRetorno->idEditorial==2&&libroRetorno->precio<=200){
				precioFinal=libroRetorno->precio-(libroRetorno->precio*10/100);
				libro_setPrecio(libroRetorno, precioFinal);
			}
		}
	}

	return libroRetorno;
}
float Libro_ContarPrecioMayor(void* element){
	float retorno;
	float precio;
	retorno=0;

	libro_getPrecio(element, &precio);
	if(precio>500){
		retorno=1;
	}

	return retorno;
}
float Libro_SumarPrecioDeEditorial(void* element){
	float precio;
	int idEditorial;
	precio=0;
	libro_getIdEditorial(element, &idEditorial);

	if(idEditorial>0&&idEditorial==3){
		libro_getPrecio(element, &precio);
	}

	return precio;
}
