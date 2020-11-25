#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parser.h"
#include "LinkedList.h"
#include "Bike.h"

int parser_FromText(FILE* pFile, LinkedList* this)
{
    int amountOfDataRead;
    char id[50], nombre[100], tipo[100], tiempo[50];

    if (pFile == NULL || this == NULL)
    {
        return -1;
    }

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,tipo,tiempo);

    do
    {
        amountOfDataRead = fscanf(
                               pFile,
                               "%[^,],%[^,],%[^,],%[^\n]\n",
                               id,
                               nombre,
                               tipo,
                               tiempo
                           );

        if (amountOfDataRead == 4)
        {
            eBike* newBike = bicicletas_newParams(id,nombre,tipo,tiempo);

            if (newBike != NULL)
            {
                ll_add(this, newBike);
            }
        }
        else
        {
            printf("\nHubo un problema al leer los datos de una linea del archivo. La misma sera ignorada\n");
        }

    }
    while (!feof(pFile));

    return 0;
}
