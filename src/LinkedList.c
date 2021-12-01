#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex); //no se hace
static int addNode(LinkedList* this, int nodeIndex,void* pElement); //no se hace

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this= (LinkedList*)calloc(1,sizeof(LinkedList));
    if(this!=NULL){
    	this->size=0;
    	this->pFirstNode=NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
    	returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o
 * 			(si el indice es menor a 0 o mayor al len de la lista)
           (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* node;
	int len;
	len=ll_len(this);
	node=NULL;
	if(this!=NULL&&nodeIndex>=0&&nodeIndex<len){
		node=this->pFirstNode;
		for(int i=0;i<nodeIndex;i++){
			node=node->pNextNode;
		}
	}
	return node;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)//no se hace
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	Node* nodeGot;
	Node* newNode;
	int returnAux = -1;

    if(this!=NULL){
    	newNode=(Node*)calloc(1,sizeof(Node));

    	if(newNode!=NULL){
			if(nodeIndex==0){
				newNode->pNextNode=this->pFirstNode;
				this->pFirstNode=newNode;
				returnAux=0;
			}
			else{
		    	nodeGot=getNode(this, nodeIndex-1);
				if(nodeGot!=NULL){
					newNode->pNextNode=nodeGot->pNextNode;
					nodeGot->pNextNode=newNode;
					returnAux=0;
				}
			}
	    	newNode->pElement=pElement;
			this->size=this->size+1;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)//no se hace
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;

    if(this!=NULL){//si agrego pElement!=NULL me tira un fail
    	len=ll_len(this);
    	if(addNode(this, len, pElement)!=-1){
        	returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* aux;

    aux=getNode(this, index);

    if(aux!=NULL){
    	returnAux=aux->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodeGot;

    if(this!=NULL){
    	nodeGot=getNode(this, index);
    	if(nodeGot!=NULL){
        	nodeGot->pElement=pElement;
        	returnAux=0;
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodeToRemove;
    Node* nodePrevius;

    if(this!=NULL){
		nodeToRemove=getNode(this,index);
		if(nodeToRemove!=NULL){
			if(index==0){
				this->pFirstNode=nodeToRemove->pNextNode;
			}
			else{
				nodePrevius=getNode(this, index-1);
				if(nodePrevius!=NULL){
					nodePrevius->pNextNode=nodeToRemove->pNextNode;
				}
			}
			free(nodeToRemove);
			this->size--;
    		returnAux=0;
		}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;

    if(this!=NULL){
        len=ll_len(this);

        for(int i=len-1;i>-1;i--){
         	ll_remove(this, i);
        }

        if(ll_len(this)==0){
        	returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL&&ll_clear(this)==0){
    	free(this);
    	returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    Node* node;

    if(this!=NULL){
        len=ll_len(this);
        for(int i=0;i<len;i++){
        	node=getNode(this, i);
        	if(node->pElement==pElement){
        		returnAux=i;
        		break;
        	}
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len;
    if(this!=NULL){
    	len=ll_len(this);
    	if(len==0){
    		returnAux=1;
    	}
    	else{
    		returnAux=0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;


    if(this!=NULL){
    	if(addNode(this, index, pElement)==0){
    		returnAux=0;
    	}

    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* node;
    if(this!=NULL){
    	node=getNode(this, index);
    	if(node!=NULL){
    		returnAux=node->pElement;
    		ll_remove(this, index);
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* node;
    int len;
    len=ll_len(this);
    if(this!=NULL){
    	returnAux=0;
    	for(int i=0;i<len;i++){
    		node=getNode(this, i);
    		if(node->pElement==pElement){
    			returnAux=1;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    Node* node2;
    int len2;

    if(this!=NULL&&this2!=NULL){
    	len2=ll_len(this2);
		returnAux=1;
		for(int i=0;i<len2;i++){
			node2=getNode(this2, i);
			if(node2!=NULL&&ll_indexOf(this, node2->pElement)==-1){
					returnAux=0;
					break;
			}
		}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len;
    Node* nodeToCopy;

    if(this!=NULL){

    	len=ll_len(this);
    	if(from>-1&&from<len&&to>from&&to<=len){
    		cloneArray=ll_newLinkedList();
    		if(cloneArray!=NULL){
            	for(int i=from;i<to;i++){
            		nodeToCopy=getNode(this, i);
            		if(nodeToCopy!=NULL){
            			ll_add(cloneArray, nodeToCopy->pElement);
            		}
            	}
    		}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len;

    if(this!=NULL){
    	cloneArray=ll_newLinkedList();
    	if(cloneArray!=NULL){
    		len=ll_len(this);
    		cloneArray=ll_subList(this, 0, len);
    	}
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux =-1;
    int len;
    void* pElement1;
    void* pElement2;
    void* pElementAux;

    if(this!=NULL&&pFunc!=NULL&&(order==0||order==1)){
    	len=ll_len(this);
    	for(int i=0;i<len-1;i++){
			for(int j=i+1;j<len;j++){
	    		pElement1=ll_get(this, i);
				pElement2=ll_get(this, j);
				if(pFunc(pElement1,pElement2)>0&&order==1){
					pElementAux=pElement1;
					ll_set(this, i, pElement2);
					ll_set(this, j, pElementAux);
				}
				else{
					if(pFunc(pElement1,pElement2)<0&&order==0){
						pElementAux=pElement1;
						ll_set(this, i, pElement2);
						ll_set(this, j, pElementAux);
					}
				}
			}
    	}
    	returnAux=0;
    }
    return returnAux;
}
/// @brief Filtra los elementos de la lista utilizando la funcion criterio recibida como parametro
///
/// @param this puntero de la LinkedList a utilizar
/// @param fn funcion de la cual usa su retorno para decidir si filtrar o no.
/// @return retorna la nueva lista con los elementos filtrados
LinkedList* ll_filter(LinkedList* this, int(*fn)(void*)){

	LinkedList* listFiltrada;
	void* element;
	int len;

	if(this!=NULL){
		listFiltrada= ll_newLinkedList();
		len=ll_len(this);
		for(int i=0;i<len;i++){
			element=ll_get(this, i);
			if(fn(element)==1){
				ll_add(listFiltrada, element);
			}
		}
	}
	return listFiltrada;
}
/// @brief Mapea los elementos de la lista utilizando la funcion criterio recibida como parametro
///
///
/// @param this this puntero de la LinkedList a utilizar
/// @param fnfuncion de la cual usa su retorno para decidir si mapear o no.
/// @return devuelve una nueva lista con los elemetos mapeados.
LinkedList* ll_map(LinkedList* this, void* (*fn)(void*)){
	void* element;
	void* elementRetorno;
	LinkedList* listMapeada;

	int len;
	if(this!=NULL){
		listMapeada=ll_newLinkedList();
		len=ll_len(this);
		for(int i=0;i<len;i++){
			element=ll_get(this,i);
			elementRetorno=fn(element);
			if(elementRetorno!=NULL){
				ll_add(listMapeada,elementRetorno);
			}
		}
	}
	return listMapeada;
}

float ll_count(LinkedList* this,float(*fn)(void* element)){
	float contador;
	void* element;
	contador=0;

	int len;
	if(this!=NULL){
		len=ll_len(this);
		for(int i=0;i<len;i++){
			element=ll_get(this,i);
			if(element!=NULL){
				contador=contador+fn(element);
			}
			else{
				contador=-1;
				break;
			}
		}
	}
	return contador;
}

