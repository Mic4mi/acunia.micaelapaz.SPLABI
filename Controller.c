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
        printf("\nNo existen bicicletas en el sistema. Intente cargarlos desde el menu para poder visualizarlos.\n");
        return -1;
    }

    system("cls");
    menu_imprimirBicicletas(pLLBicicletas);

    return 0;
}
