
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libro.h"
#include "Editorial.h"
#include "parser.h"
#include "LinkedList.h"
#include "biblioteca.h"

/// @brief Le pide al usuario el ingreso de un nombre de archivo de libros que este en la carpeta principal del programa
/// 		o la direccion del archivo para cargarlo
///
/// @param pListLibro	puntero de la lista LinkedList
/// @return devuelve 0 si esta OK
int Controller_loadLibroFromText(LinkedList* pListLibro){
	int retorno;
	char nombreArchivo[128];
	FILE* pFile;
	retorno=1;//nombre del archivo o LL NULL
	if(pListLibro!=NULL){
		GetCharR(nombreArchivo, 128, "Ingrese el nombre del archivo de Libro: ","ERROR!\n", 99);
		PrimerasLetrasMayuscula(nombreArchivo);
		retorno=2;//nombre del archivo incorrecto
		retorno=3;//problema al analizar el archivo
		ll_clear(pListLibro);
		pFile=fopen(nombreArchivo,"r");
		if(parser_LibroFromText(pFile, pListLibro)==0){
			retorno=0;
		}
		fclose(pFile);
	}
	return retorno;
}
/// @brief Le pide al usuario el ingreso de un nombre de archivo de Editoriales que este en la carpeta principal del programa
/// 		o la direccion del archivo para cargarlo
///
/// @param pListLibro	puntero de la lista LinkedList
/// @return devuelve 0 si esta OK
int Controller_loadEditorialFromText(LinkedList* pListEditorial){
	int retorno;
	char nombreArchivo[128];
	FILE* pFile;
	retorno=1;//nombre del archivo o LL NULL
	if(pListEditorial!=NULL){
		GetCharR(nombreArchivo, 128, "Ingrese el nombre del archivo de Editorial: ","ERROR!\n", 99);
		PrimerasLetrasMayuscula(nombreArchivo);
		retorno=2;//nombre del archivo incorrecto
		if(strcmp(nombreArchivo,"Editoriales")==0){
			retorno=3;//problema al analizar el archivo
			pFile=fopen(nombreArchivo,"r");
			if(parser_EditorialFromText(pFile, pListEditorial)==0){
				retorno=0;
			}
			fclose(pFile);
		}
	}
	return retorno;
}

/// @brief  Muestra la lista de Libros con su Editorial
///
/// @param Libros 	puntero de la lista LinkedList de libros
/// @param Editorial	puntero de la lista LinkedList de Editoriales
/// /// @return devuelve 0 si ok
int Controller_MostrarListaLibros(LinkedList* Libros,LinkedList* Editorial){
	int retorno;
	int lenLibros;
	eLibro* auxLibro;
	eEditorial* auxEditorial;

	retorno=1;
	lenLibros=ll_len(Libros);
	if(Libros!=NULL&&Editorial!=NULL){
		for(int i=0;i<lenLibros;i++){
			auxLibro=ll_get(Libros, i);
			auxEditorial=BuscarEditorialDelLibro(Editorial,auxLibro->idEditorial);

			printf("%-4d  %-31s  %-25s  %-20s  %-6.2f\n",auxLibro->id,auxLibro->titulo,
					auxLibro->autor,auxEditorial->nombre,auxLibro->precio);
			retorno=0;
		}
	}
	return retorno;
}
/// @brief  Ordela la lista autor de A-Z
///
/// @param pListLibros puntero de la lista LinkedList de libros
/// @return devuelve 0 si esta ok
int Controller_OrderPorAutor(LinkedList* pListLibros){
	int retorno;
	retorno=1;

	ll_sort(pListLibros, Libro_OrdernarAutor, 1);

	return retorno;
}
/// @brief
///
/// @param pListLibros
/// @return
int Controller_SaveArchivoLibro(LinkedList* pListLibros){
	int retorno;
	int len;
	FILE* pFile;
	eLibro* libro;
	char nombre[125];

	retorno=0;

	if(pListLibros!=NULL){
		GetCharR(nombre, 125, "ingrese el nombre del archivo a guardar: ", "ERROR!\n", 99);
		len=ll_len(pListLibros);
		pFile=fopen(nombre,"w");

		fprintf(pFile,"id,titulo,autor,precio,idEditorial\n");

		for(int i=0;i<len;i++){
			libro=(eLibro*)ll_get(pListLibros,i);
			fprintf(pFile,"%d,%s,%s,%.2f,%d\n",libro->id,libro->titulo,
					libro->autor,libro->precio,libro->idEditorial);
			retorno=1;
		}
		fclose(pFile);
	}

	return retorno;
}
/// @brief Filtra y muestra una lista de solo editorial Minotauro y pide
/// al usuario un nombre para guardarla
///
/// @param pListLibros
/// @param pListEditorial
/// @return
int Controller_FiltroMinotauro(LinkedList* pListLibros,LinkedList* pListEditorial){
	int retorno;
	LinkedList* ListaFiltrada;

	retorno =1;

	ListaFiltrada=ll_filter(pListLibros, Libro_EsMinotauro);

	Controller_MostrarListaLibros(ListaFiltrada, pListEditorial);
	Controller_SaveArchivoLibro(ListaFiltrada);

	ll_deleteLinkedList(ListaFiltrada);

	return retorno;
}
/// @brief Crea una lista con los descuentos de 2 editoriales y pide al usuario un nombre para guardarla
///
/// @param pListLibros
/// @param pListEditorial
/// @return
int Controller_MapeoDescuento(LinkedList* pListLibros,LinkedList* pListEditorial){
	int retorno;
	LinkedList* listMapeada;

	retorno=1;

	if(pListLibros!=NULL&&pListEditorial!=NULL){
		listMapeada=ll_map(pListLibros, Libro_Descuentos);

		if(!Controller_MostrarListaLibros(listMapeada, pListEditorial)){
			Controller_SaveArchivoLibro(listMapeada);
			retorno=0;
		}
	}
	ll_deleteLinkedList(listMapeada);

	return retorno;
}

float Controller_ContarLibroPrecioMayorA(LinkedList* pListLibros){
	float retorno;
	retorno=-1;

	retorno=ll_count(pListLibros, Libro_ContarPrecioMayor);
	if(retorno!=-1){
		printf("La cantidad de libros mayor a 500$ es: %.0f",retorno);
	}
	return retorno;
}
float Controller_SumarPrecioDeEditorial(LinkedList* pListLibros){
	float retorno;
	retorno=-1;

	retorno=ll_count(pListLibros, Libro_SumarPrecioDeEditorial);

	if(retorno!=-1){
		printf("La Suma de precio de la editorial PEARSON es: $%.2f",retorno);
	}

	return retorno;
}

