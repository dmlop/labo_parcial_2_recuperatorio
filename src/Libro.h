

#ifndef LIBRO_H_
#define LIBRO_H_


typedef struct{
	int id;
	char titulo[51];
	char autor[51];
	float precio;
	int idEditorial;
}eLibro;




eLibro* libro_new();

int libro_setId(eLibro* this,int id);
int libro_setTitulo(eLibro* this,char* titulo);
int libro_setAutor(eLibro* this,char* autor);
int libro_setPrecio(eLibro* this,float precio);
int libro_setIdEditorial(eLibro* this,int idEditorial);

int libro_getid(eLibro* this,int* id);
int libro_getTitulo(eLibro* this,char* titulo);
int libro_getAutor(eLibro* this,char* autor);
int libro_getPrecio(eLibro* this,float* precio);
int libro_getIdEditorial(eLibro* this,int* idEditorial);

eLibro* Libro_NewParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr,char* idEditorialStr);
int Libro_OrdernarAutor(void* ElementoUno,void* ElementoDos);
int Libro_EsMinotauro(void* element);
void* Libro_Descuentos(void* element);
float Libro_ContarPrecioMayor(void* element);
float Libro_SumarPrecioDeEditorial(void* element);
#endif /* LIBRO_H_ */
