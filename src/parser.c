
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libro.h"
#include "Editorial.h"
#include "parser.h"
#include "LinkedList.h"
#include "biblioteca.h"
/// @brief  analiza un archivo del formato libro y lo carga
///
/// @param pFile puntero al archivo
/// @param pList puntero a la lista LinkedList del libro
/// @return retorna 0 si esta ok
int parser_LibroFromText(FILE* pFile , LinkedList* pList){
	int retorno;
	char buff1[128];
	char buff2[128];
	char buff3[128];
	char buff4[128];
	char buff5[128];
	eLibro* libro;

	retorno=1;
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buff1,buff2,buff3,buff4,buff5);

	if(pFile!=NULL&&pList!=NULL){
		while(!feof(pFile)){
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buff1,buff2,buff3,buff4,buff5);

			libro=Libro_NewParametros(buff1,buff2,buff3,buff4,buff5);

			ll_add(pList,libro);
			retorno=0;
		}
	}
	return retorno;
}
/// @brief  analiza un archivo del formato editorial y lo carga
///
/// @param pFile puntero al archivo
/// @param pList puntero a la lista LinkedList de Editorial
/// @return retorna 0 si esta ok
int parser_EditorialFromText(FILE* pFile , LinkedList* pList){
	int retorno;
	char buff1[128];
	char buff2[128];
	eEditorial* editorial;

	retorno=1;
	fscanf(pFile,"%[^,],%[^\n]\n",buff1,buff2);

	if(pFile!=NULL&&pList!=NULL){
		while(!feof(pFile)){
			fscanf(pFile,"%[^,],%[^\n]\n",buff1,buff2);
			editorial=Editorial_NewParametros(buff1,buff2);
			ll_add(pList,editorial);
			retorno=0;
		}
	}
	return retorno;
}

