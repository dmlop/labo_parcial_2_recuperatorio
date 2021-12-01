
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libro.h"
#include "Editorial.h"
#include "parser.h"
#include "LinkedList.h"
#include "biblioteca.h"

/// @brief  crear espacio en memoria de una variable tipo eEditorial
///
/// @return	devuelve el puntero
eEditorial* editorial_new(){
	eEditorial* editorial;
	editorial=(eEditorial*)calloc(1,sizeof(eEditorial));
	return editorial;
}
/// @brief setea el idEditorial en un elemento tipo eEditorial
///
/// @param this	puntero al LinkedList eEditorial
/// @param idEditorial el valor que tomara
/// @return devuelve 1 si esta ok
int Editorial_setIdEditorial(eEditorial* this,int idEditorial){
	int retorno;
	retorno=0;
	if(this!=NULL){
		this->idEditorial=idEditorial;
		retorno=1;
	}
	return retorno;
}
/// @brief setea el nombre en un elemento tipo eEditorial
///
/// @param this	puntero al LinkedList eEditorial
/// @param nombre el valor que tomara
/// @return devuelve 1 si esta ok
int Editorial_setNombre(eEditorial* this,char* nombre){
	int retorno;
	retorno=0;
	if(this!=NULL){
		strcpy(this->nombre,nombre);
		retorno=1;
	}
	return retorno;
}

/// @brief crea espacio en memoria de una variable del tipo eEditorial y le setea los paremos pasados
///
/// @param idStr   id pero en formato string
/// @param nombreStr nombre en formato string
/// @return retorna el puntero tipo eEditorial
eEditorial* Editorial_NewParametros(char* idStr,char* nombreStr){
	eEditorial* aux;
	if(idStr!=NULL&&nombreStr!=NULL){
		aux=editorial_new();
		Editorial_setIdEditorial(aux, atoi(idStr));
		Editorial_setNombre(aux, nombreStr);
	}
	return aux;
}
/// @brief busca la editorial del libro dentro de la linkedlist
///
/// @param listEditorial linkedlist de la estructura eEditorial
/// @param id  el id de la editorial que posee el libro.
/// @return devuelve el elemento tipo eEditorial que pertenece al id pasado por parametro.
eEditorial* BuscarEditorialDelLibro( LinkedList* listEditorial,int id){
	int len;

	eEditorial* aux=NULL;
	len=ll_len(listEditorial);
	if(listEditorial!=NULL){
		for(int i=0;i<len;i++){
			aux=ll_get(listEditorial, i);
			if(id==aux->idEditorial){
				break;
			}
		}
	}
	return aux;
}

