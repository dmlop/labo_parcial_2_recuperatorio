#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

/// @brief Menu que mostrara el programa constantemente y pide ingresar la opcion que usuario quiera
///
/// @param pResultado - puntero que devolvera la opcion que el usuario haya ingresado.

void Menu(int*pOpcion){
	printf("\n=================MENU=================\n");
	printf("||1.Cargar Archivo de Libros\n"
			"||2.Cargar Archivo de Editoriales\n"
			"||3.Mostrar Lista de Libros\n"
			"||4.Ordenar por autor.\n"
			"||5.Filtrar Solo Editorial MINOTAURO.\n"
			"||6.Lista Descuento.\n"
			"||7.Contar libros precio mayor a $500.\n"
			"||8.Sumar Precio De Editorial.\n"
			"||9.Salir\n"
			"=======================================\n");

	if(GetIntRango(pOpcion,"Ingrese la opcion elegida: ","ERROR! NUMERO INVALIDO!\n",1,9,99)==0){
		printf("Se agotaron los intentos!");
		*pOpcion=-1;
	}
}
/// @brief Menu de modificacion que pide ingresar la opcion que usuario quiera
/// @param pOpcion la opcion elejida por el usuario
void MenuModificacion(int*pOpcion){

	printf("\n============MENU=MODIFICACION===========\n");
	printf("||1.Modificar Nombre del Empleado.\n");
	printf("||2.Modificar Horas Trabajadas del Empleado.\n");
	printf("||3.Modificar Sueldo del Empleado.\n");
	printf("||4.Atras.\n");
	printf("=======================================\n");

	if(GetIntRango(pOpcion,"Ingrese el numero de la modificacion deseada: ","ERROR! NUMERO INVALIDO!\n",1,6,99)==0){
		printf("Se agotaron los intentos!");
		*pOpcion=-1;
	}

}
/// @brief Menu de informes que mostrara el programa constantemente y pide ingresar la opcion que usuario quiera
/// @param pOpcion la opcion elejida por el usuario
void MenuInformes(int*pOpcion){

	printf("\n============MENU=LISTADO===========\n");
	printf("||1.Imprimir Copia de Clientes Ordenados por Nombre.\n");
	printf("||2.Imprimir Copia de Clientes Ordenados por Horas Trabajadas.\n");
	printf("||3.Imprimir Copia de Clientes Ordenados por Sueldo.\n");
	printf("||4.Atras.\n");
	printf("=======================================\n");

	GetIntRango(pOpcion,"Ingrese el numero de la opcion deseada: ","ERROR! NUMERO INVALIDO!\n",1,4,99);
}
void MenuOrden(int*pOpcion){

	printf("\n============MENU=ORDEN===========\n");
	printf("||1.Orden Descendente.\n");
	printf("||2.Orden Ascendente.\n");
	printf("=======================================\n");

	GetIntRango(pOpcion,"Ingrese el numero de la opcion deseada: ","ERROR! NUMERO INVALIDO!\n",1,2,99);
	*pOpcion=*pOpcion-1;
}

