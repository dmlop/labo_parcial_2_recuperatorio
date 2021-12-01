

#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"

int parser_LibroFromText(FILE* pFile , LinkedList* pList);
int parser_EditorialFromText(FILE* pFile , LinkedList* pList);

#endif /* PARSER_H_ */
