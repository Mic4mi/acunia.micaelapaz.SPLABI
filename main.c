#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "Validations.h"
#include "Controller.h"
#include "Menu.h"
#include "LinkedList.h"

int main()
{
    srand (time(NULL));
    LinkedList* bicicletas = ll_newLinkedList();
    char pathPrincipal[100];
    int opcion, seleccion;
    int flagMap = 0;

    if(bicicletas == NULL)
    {
        printf("\nNo se consiguio espacio en memoria para la lista.\n");
        return -1;
    }

    do
    {
        menu_main();
        seleccion = validations_getOption(
                        &opcion,
                        "\nOpcion invalida, vuelva a intentar\n",
                        1,
                        7
                    );

        if(!seleccion)
        {
            switch(opcion)
            {
            case 1:
                if(!controller_loadFromText(bicicletas,pathPrincipal))
                {
                    printf("\nSe han cargado %d bicicletas desde el archivo %s\n", ll_len(bicicletas), pathPrincipal);
                }
                else
                {
                    printf("\nNo se ha podido cargar el archivo.\n");
                }
                break;
            case 2:
                if(!controller_ListarBicicletas(bicicletas))
                {
                    printf("\nOperacion exitosa\n");
                }
                else
                {
                    printf("\nNo se ha podido cargar el archivo.\n");
                }
                break;
            case 3:
                if(!controller_mapPosteos(bicicletas))
                {
                    flagMap = 1;
                    printf("\nOperacion exitosa\n");
                }
                else
                {
                    printf("\nNo se ha podido cargar el archivo.\n");
                }
                break;
            case 4:
                if(!flagMap)
                {
                    printf("\nPrimero deben mapearse los posteos.\n");
                    break;
                }

                if(!controller_filtrarBicicletas(bicicletas))
                {
                    printf("\nOperacion exitosa\n");
                }
                else
                {
                    printf("\nNo se ha podido cargar el archivo.\n");
                }
                break;
            case 5:
                if(!flagMap)
                {
                    printf("\nPrimero deben mapearse los posteos.\n");
                    break;
                }

                if(!controller_ordenarXTipoXTiempo(bicicletas))
                {
                    printf("\nOperacion exitosa\n");
                }
                else
                {
                    printf("\nNo se ha podido cargar el archivo.\n");
                }
                break;
            case 6:
                if(!controller_saveAsText("bicicletasOrdenadas.csv",bicicletas))
                {
                    printf("\nOperacion exitosa\n");
                }
                else
                {
                    printf("\nNo se ha podido cargar el archivo.\n");
                }
                break;
            case 7:
                ll_deleteLinkedList(bicicletas);
                printf("\nSaliendo...\n");
                break;
            }
            system("pause");
        }

    }
    while (opcion != 7);

    return 0;
}
