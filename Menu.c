#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Menu.h"

void menu_main()
{
    system("cls");
    printf("__________________________________________________________________________________\n");
    printf("                                   PARCIAL 2          \n");
    printf("__________________________________________________________________________________\n");
    printf("                                   Bicicletas                  \n");
    printf("__________________________________________________________________________________\n");
    printf("1. Cargar archivo.\n");
    printf("2. Imprimir lista.\n");
    printf("3. Asignar tiempos.\n");
    printf("4. Filtrar por tipo.\n");
    printf("5. Mostrar posiciones.\n");
    printf("6. Guardar posiciones.\n");
    printf("7. Salir.\n");
    printf("\n\n");
}

void menu_imprimirBicicleta(eBike* currentBike)
{
    int idActual, tiempoActual;
    char nombre[100], tipo[100];

    bicicletas_getId(currentBike,&idActual);
    bicicletas_getNombre(currentBike,nombre);
    bicicletas_getTiempo(currentBike,&tiempoActual);
    bicicletas_getTipo(currentBike,tipo);

    printf("\n%4d  %15s       %15s           %4d   \n",
           idActual,
           nombre,
           tipo,
           tiempoActual);
}

int menu_imprimirBicicletas(LinkedList* pLLBicicletas)
{
    int currentNodeIndex = 0;
    int linkedListSize = ll_len(pLLBicicletas);

    eBike* currentBike;
    Node* currentNode = pLLBicicletas->pFirstNode;

    printf("_____________________________________________________________\n");
    printf("                             BICICLETAS \n");
    printf("_____________________________________________________________\n");
    printf("  ID        Nombre            TIPO                    TIEMPO    \n");
    printf("_____________________________________________________________\n");

    while (currentNodeIndex < linkedListSize)
    {
        currentBike = (eBike*)ll_get(pLLBicicletas, currentNodeIndex);

        menu_imprimirBicicleta(currentBike);

        currentNode = currentNode->pNextNode;
        currentNodeIndex++;
    }

    return 0;
}

