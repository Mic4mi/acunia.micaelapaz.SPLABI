#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "LinkedList.h"

/** \brief Carga los datos de las bicicletas desde un archivo (modo texto).
 *
 * \param path char*
 * \param pLLBicicletas LinkedList*
 * \return int [0] si no hay errores, [-1] si el archivo es NULL
 *
 */
int controller_loadFromText(LinkedList* pLLPosteos, char* nombreDelArchivo);

/** \brief Lista la bicicletas de la lista de bicicletas
 *
 * \param pLLbicicletas LinkedList*
 * \return int int [0] si no hay errores, [-1] si la lista esta vacia o es NULL
 *
 */
int controller_ListarBicicletas(LinkedList* pLLBicicletas);

/** \brief Ejecuta un mapeo que rellena los campos de los elementos de un LL
 * bicicletas
 * \param LinkedList* pLLBicicletas
 * \return int retorno [0] ai no hay errores, [-1] si la lista esta vacia
 *
 */
int controller_mapPosteos(LinkedList* pLLBicicletas);

/** \brief Ejecuta una funcion que ordena bicicletas mediante la seleccion de una opcion en un menu
 *
 * \param pLLbicicletas LinkedList*
 * \return int int [0] si no hay errores, [-1] si la lista esta vacia o es NULL
 *
 */
int controller_ordenarXTipoXTiempo(LinkedList* pLLBicicletas);

/** \brief Ejecuta una funcion que filtra bicicletas mediante la seleccion de una opcion en un menu
 *
 * \param pLLbicicletas LinkedList*
 * \return int int [0] si no hay errores, [-1] si la lista esta vacia o es NULL
 *
 */
int controller_filtrarBicicletas(LinkedList* pLLBicicletas);

/** \brief Guarda los datos de las bicicletas en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pLLbicicletas LinkedList*
 * \return int [0] si no hay errores, [-1] si el archivo es NULL o la lista esta vacia
 *
 */
int controller_saveAsText(char* path, LinkedList* pLLPosts);

#endif // CONTROLLER_H_INCLUDED
