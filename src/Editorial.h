

#ifndef EDITORIAL_H_
#define EDITORIAL_H_

typedef struct{
	int idEditorial;
	char nombre[51];

}eEditorial;
#include "LinkedList.h"


eEditorial* editorial_new();
int Editorial_setIdEditorial(eEditorial* this,int idEditorial);
int Editorial_setNombre(eEditorial* this,char* nombre);
eEditorial* Editorial_NewParametros(char* idStr,char* nombreStr);
eEditorial* BuscarEditorialDelLibro(LinkedList* listEditorial,int id);

#endif /* EDITORIAL_H_ */
