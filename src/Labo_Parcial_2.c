/*
 * DANIEL MANRESA DIV C
	1. Leer un archivo con los datos de libros, guard�ndolos en un linkedList de entidades  eLibro.
	ACLARACI�N: El nombre del archivo se debe pasar como par�metro por l�nea de  comandos.
	2. Leer un archivo con los datos de editoriales, guard�ndolos en un linkedList de entidades  eEditorial.
	ACLARACI�N: El nombre del archivo se debe pasar como par�metro por l�nea de  comandos.
	3. Ordenar la lista generada en el �tem anterior, con la funci�n ll_sort, seg�n el criterio de  ordenamiento �Autor� de manera ascendente.
	4. Imprimir por pantalla todos los datos de los libros.
	ACLARACI�N: Se deber� imprimir la descripci�n de la editorial.
	5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deber� utilizar la  funci�n ll_filter* del LinkedList. Guardar el listado en un archivo csv.
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
