/*
 * DANIEL MANRESA DIV C
	1. Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades  eLibro.
	ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de  comandos.
	2. Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades  eEditorial.
	ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de  comandos.
	3. Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de  ordenamiento “Autor” de manera ascendente.
	4. Imprimir por pantalla todos los datos de los libros.
	ACLARACIÓN: Se deberá imprimir la descripción de la editorial.
	5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la  función ll_filter* del LinkedList. Guardar el listado en un archivo csv.
*/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "menu.h"
#include "controller.h"
#include "biblioteca.h"

int main(void) {
	setbuf(stdout,NULL);
	LinkedList* listLibro = ll_newLinkedList();
	LinkedList* listEditorial = ll_newLinkedList();
	int opcionMenu;
	if(listLibro!=NULL&&listEditorial!=NULL){
		do{
			Menu(&opcionMenu);
			switch(opcionMenu){
			case 1:
				if(!Controller_loadLibroFromText(listLibro)){
					printf("SE CARGO EL ARCHIVO LIBROS\n");
				}
				break;
			case 2:
				if(!Controller_loadEditorialFromText(listEditorial)){
					printf("SE CARGO EL ARCHIVO EDITORIALES\n");

				}
				break;
			case 3:
				if(!ll_len(listLibro)||!ll_len(listEditorial)){
					printf("FALTA CARGAR ALGUN ARCHIVO\n");
					break;
				}
				if(Controller_MostrarListaLibros(listLibro, listEditorial)){
					printf("NO SE PUDO MOSTRAR LA LISTA\n");
				}
				break;
			case 4:
				if(!ll_len(listLibro)||!ll_len(listEditorial)){
					printf("FALTA CARGAR ALGUN ARCHIVO\n");
					break;
				}
				if(Controller_OrderPorAutor(listLibro)){
					printf("LA LISTA SE ORDENO CORRECTAMENTE!\n");
				}
				break;
			case 5:
				if(!ll_len(listLibro)||!ll_len(listEditorial)){
					printf("FALTA CARGAR ALGUN ARCHIVO\n");
					break;
				}
				if(Controller_FiltroMinotauro(listLibro,listEditorial)){
					printf("========FIN FILTRO MINOTAURO===========\n");
				}
				break;
			case 6:
				if(!ll_len(listLibro)||!ll_len(listEditorial)){
					printf("FALTA CARGAR ALGUN ARCHIVO\n");
					break;
				}
				if(!Controller_MapeoDescuento(listLibro, listEditorial)){
					printf("SE CREO EL ARCHIVO CON EXITO!\n");
				}
				break;
			case 7:
				if(!ll_len(listLibro)||!ll_len(listEditorial)){
					printf("FALTA CARGAR ALGUN ARCHIVO\n");
					break;
				}
				if(Controller_ContarLibroPrecioMayorA(listLibro)!=-1){

				}
				break;
			case 8:
				if(!ll_len(listLibro)||!ll_len(listEditorial)){
					printf("FALTA CARGAR ALGUN ARCHIVO\n");
					break;
				}
				Controller_SumarPrecioDeEditorial(listLibro);
				break;
			case 9:
				break;
			}
		}while(opcionMenu!=9);
	}
	return EXIT_SUCCESS;
}
