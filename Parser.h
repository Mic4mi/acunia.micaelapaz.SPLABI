#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include <stdio.h>
#include "LinkedList.h"

/** \brief Parsea los datos de las bicicletass desde un archivo (modo texto).
 *
 * \param FILE* pFile
 * \param LinkedList* pLinkedListbicicletass
 * \return int [0] si no hay errores, [-1] si el archivo no existe y/o la lista es NULL
 *
 */
int parser_FromText(FILE* pFile, LinkedList* this);

#endif // PARSER_H_INCLUDED
