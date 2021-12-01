

#ifndef CONTROLLER_H_
#define CONTROLLER_H_



int Controller_loadLibroFromText(LinkedList* pListLibro);
int Controller_loadEditorialFromText(LinkedList* pListEditorial);
int Controller_MostrarListaLibros(LinkedList* Libros,LinkedList* Editorial);
int Controller_OrderPorAutor(LinkedList* pListLibros);
int Controller_SaveArchivoLibro(LinkedList* pListLibros);
int Controller_FiltroMinotauro(LinkedList* pListLibros,LinkedList* pListEditorial);
int Controller_MapeoDescuento(LinkedList* pListLibros,LinkedList* pListEditorial);
int Controller_ContarLibroPrecioMayorA(LinkedList* pListLibros);
int Controller_SumarPrecioDeEditorial(LinkedList* pListLibros);


#endif /* CONTROLLER_H_ */
