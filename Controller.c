#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Controller.h"
#include "Parser.h"
#include "Menu.h"
#include "Validations.h"

int controller_loadFromText(LinkedList* pLLBicicletas, char* nombreDelArchivo)
{
    int status = -1;
    char path[100];

    printf("\nIngrese el nombre del archivo a leer: ");
    fflush(stdin);
    gets(path);

    FILE *pFile = fopen(path, "r");

    if (pFile == NULL)
    {
        printf("\nEl archivo en la ruta %s no existe.\n", path);
        return status;
    }

    strcpy(nombreDelArchivo,path);
    status = parser_FromText(pFile,pLLBicicletas);
    printf("\nLei el archivo\n");
    fclose(pFile);

    return status;
}

int controller_ListarBicicletas(LinkedList* pLLBicicletas)
{
    if (ll_isEmpty(pLLBicicletas) == 1)
    {
        printf("\nNo existen bicicletas en el sistema. Intente cargarlas desde el menu para poder visualizarlas.\n");
        return -1;
    }

    system("cls");
    menu_imprimirBicicletas(pLLBicicletas);

    return 0;
}


int controller_mapPosteos(LinkedList* pLLBicicletas)
{
    int error = -1;
    if (ll_isEmpty(pLLBicicletas) == 1)
    {
        printf("\nNo existen bicicletas en el sistema. Intente cargarlas desde el menu para poder mapearlas.\n");
        return -1;
    }

    LinkedList* bicicletasConTiempo = ll_map(pLLBicicletas,bicicletas_map);

    if(bicicletasConTiempo != NULL)
    {
        system("cls");
        pLLBicicletas = bicicletasConTiempo;
        menu_imprimirBicicletas(pLLBicicletas);
        error = 0;
    }

    return error;
}

int controller_ordenarXTipoXTiempo(LinkedList* pLLBicicletas)
{
    if (ll_isEmpty(pLLBicicletas) == 1)
    {
        printf("\nNo existen bicicletas en el sistema. Intente cargarlas desde el menu para poder ordenarlas.\n");
        return -1;
    }

    int error = -1;


    error = ll_sort(pLLBicicletas,bicicletas_compararPorTipoYTiempo,1);

    system("cls");
    printf("_____________________________________________________________\n");
    printf("                  Orden x tipo x tiempo \n");
    menu_imprimirBicicletas(pLLBicicletas);

    return error;
}

int controller_saveAsText(char* path, LinkedList* pLLBicicletas)
{
    if (ll_isEmpty(pLLBicicletas) == 1)
    {
        printf("\nPrimero deben haber bicicletas cargadas.\n");
        return -1;
    }

    FILE *pFile;

    pFile = fopen(path, "w");

    if (pFile == NULL || pLLBicicletas == NULL)
    {
        return -1;
    }

    int currentNodeIndex = 0;
    int linkedListSize = ll_len(pLLBicicletas);
    int idActual, tiempoActual;
    char nombreActual[100], tipoActual[100];

    eBike* currentBike;
    Node* currentNode = pLLBicicletas->pFirstNode;

    fprintf(pFile, "id_bike,nombre,tipo,tiempo\n");

    while (currentNodeIndex < linkedListSize)
    {
        currentBike = (eBike*)ll_get(pLLBicicletas, currentNodeIndex);

        bicicletas_getId(currentBike, &idActual);
        bicicletas_getNombre(currentBike, nombreActual);
        bicicletas_getTipo(currentBike, tipoActual);
        bicicletas_getTiempo(currentBike, &tiempoActual);

        fprintf(pFile, "%d,%s,%s,%d\n",
                idActual,
                nombreActual,
                tipoActual,
                tiempoActual);

        currentNode = currentNode->pNextNode;
        currentNodeIndex++;
    }

    fclose(pFile);

    printf("\nLos cambios para la lista de bicicletas, han sido guardados correctamente.\n");

    return 0;
}

int controller_filtrarBicicletas(LinkedList* pLLBicicletas)
{
    if (ll_isEmpty(pLLBicicletas) == 1)
    {
        printf("\nNo existen bicicletas en el sistema. Intente cargarlas para poder filtrarlas.\n");
        return -1;
    }

    int optionSort = 0;
    int selectSort = 0;

    do
    {
        menu_submenu_filter();
        selectSort = validations_getOption(
                         &optionSort,
                         "\nOpcion invalida, vuelva a intentarlo.\n",
                         1,
                         5);
        if(!selectSort)
        {
            switch(optionSort)
            {
            case 1:
            {
                LinkedList* BMX = ll_filter(pLLBicicletas,bicicletas_filtrarBMX);
                if(BMX != NULL)
                {
                    system("cls");
                    printf("_____________________________________________________________\n");
                    printf("                           BMX \n");
                    menu_imprimirBicicletas(BMX);
                    controller_saveAsText("BMX.csv",BMX);
                    ll_deleteLinkedList(BMX);
                }
                else
                {
                    ll_deleteLinkedList(BMX);
                }
            }
            break;
            case 2:
            {
                LinkedList* PLAYERA = ll_filter(pLLBicicletas,bicicletas_filtrarPlayera);
                if(PLAYERA != NULL)
                {
                    system("cls");
                    printf("_____________________________________________________________\n");
                    printf("                           PLAYERA \n");
                    menu_imprimirBicicletas(PLAYERA);
                    controller_saveAsText("PLAYERA.csv",PLAYERA);
                    ll_deleteLinkedList(PLAYERA);
                }
                else
                {
                    ll_deleteLinkedList(PLAYERA);
                }
            }
            break;
            case 3:
            {
                LinkedList* MTB = ll_filter(pLLBicicletas,bicicletas_filtrarMTB);
                if(MTB != NULL)
                {
                    system("cls");
                    printf("_____________________________________________________________\n");
                    printf("                           MTB \n");
                    menu_imprimirBicicletas(MTB);
                    controller_saveAsText("MTB.csv",MTB);
                    ll_deleteLinkedList(MTB);
                }
                else
                {
                    ll_deleteLinkedList(MTB);
                }
            }
            break;
            case 4:
            {
                LinkedList* PASEO = ll_filter(pLLBicicletas,bicicletas_filtrarPaseo);
                if(PASEO != NULL)
                {
                    system("cls");
                    printf("_____________________________________________________________\n");
                    printf("                           PASEO \n");
                    menu_imprimirBicicletas(PASEO);
                    controller_saveAsText("PASEO.csv",PASEO);
                    ll_deleteLinkedList(PASEO);
                }
                else
                {
                    ll_deleteLinkedList(PASEO);
                }
            }
            break;
            case 5:
                printf("Volviendo al menu principal...\n");
                break;
            }
            system("pause");
        }
    }
    while(optionSort != 5);

    return 0;
}
