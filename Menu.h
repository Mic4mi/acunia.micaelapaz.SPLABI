#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "LinkedList.h"
#include "Bike.h"

/** \brief Imprime el menu principal
 *
 *
 */
void menu_main();

/** \brief Imprime una bicicleta
 *
 * \param eBike* currentbicicleta
 *
 */
void menu_imprimirBicicleta(eBike* currentBike);

/** \brief Imprime una lista de bicicletas
 *
 * \param LinkedList* duenos
 * \param eBike* currentbicicleta
 * \return [0]
 *
 */
int menu_imprimirBicicletas(LinkedList* pLLBicicletas);

/** \brief Imprime el sub-menu de filtros
 *
 *
 */
void menu_submenu_filter();

#endif // MENU_H_INCLUDED
