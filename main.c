#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Validations.h"
#include "Controller.h"
#include "Menu.h"
#include "LinkedList.h"

int main()
{
    LinkedList* bicicletas = ll_newLinkedList();
    //LinkedList* bicicletasConTiempo = NULL;
    char pathPrincipal[100];
    int opcion, seleccion;

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
                printf("\nMantenimiento...\n");
                break;
            case 4:
                printf("\nMantenimiento...\n");
                break;
            case 5:
                printf("\nMantenimiento...\n");
                break;
            case 6:
                printf("\nMantenimiento...\n");
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
