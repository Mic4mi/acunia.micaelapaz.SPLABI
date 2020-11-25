#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "LinkedList.h"


int controller_loadFromText(LinkedList* pLLPosteos, char* nombreDelArchivo);
int controller_ListarBicicletas(LinkedList* pLLBicicletas);

#endif // CONTROLLER_H_INCLUDED
