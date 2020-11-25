#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "LinkedList.h"


int controller_loadFromText(LinkedList* pLLPosteos, char* nombreDelArchivo);
int controller_ListarBicicletas(LinkedList* pLLBicicletas);
int controller_mapPosteos(LinkedList* pLLBicicletas);
int controller_ordenarXTipoXTiempo(LinkedList* pLLBicicletas);
int controller_filtrarBicicletas(LinkedList* pLLBicicletas);
int controller_saveAsText(char* path, LinkedList* pLLPosts);

#endif // CONTROLLER_H_INCLUDED
