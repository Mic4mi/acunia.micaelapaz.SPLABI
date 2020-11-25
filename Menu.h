#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "LinkedList.h"
#include "Bike.h"

void menu_main();

void menu_imprimirBicicleta(eBike* currentBike);

int menu_imprimirBicicletas(LinkedList* pLLBicicletas);

#endif // MENU_H_INCLUDED
