#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "Validations.h"
#include "Bike.h"

eBike* bicicleta_new()
{
    eBike* nueva = (eBike*) malloc(sizeof(eBike));

    if(nueva != NULL)
    {
        nueva->id_bike = 0;
        nueva->tiempo = 0;
        strcpy(nueva->nombre, "");
        strcpy(nueva->tipo, "");
    }

    return nueva;
}

eBike* bicicletas_newParams(
    char* idAsChar,
    char* nombre,
    char* tipo,
    char* tiempoAsChar)
{
    int id, tiempo, validId, validTiempo;

    validId = validations_isValidNumber(idAsChar);
    validTiempo = validations_isValidNumber(tiempoAsChar);

    if(!validId || !validTiempo)
    {
        if(!validId)
        {
            printf("\nEl Id del post es invalido. Valor recibido: %s\n", idAsChar);
        }
        else if (!validTiempo)
        {
            printf("\nEl valor del tiempo del post es invalido. Valor recibido: %s\n", tiempoAsChar);
        }

        return NULL;
    }

    id = atoi(idAsChar);
    tiempo = atoi(tiempoAsChar);

    eBike* newBike = bicicleta_new();

    if(newBike != NULL)
    {
        if(
            !(!bicicletas_setId(newBike,id) &&
              !bicicletas_setNombre(newBike,nombre) &&
              !bicicletas_setTipo(newBike,tipo) &&
              !bicicletas_setTiempo(newBike,tiempo)
             ))
        {
            printf("\nOcurrio un problema al inicializar las propiedades de la bicicleta. La misma no sera creada.\n");
            newBike = NULL;
            free(newBike);
        }
    }
    return newBike;
}

int bicicletas_setId(eBike* this,int id)
{
    int error = -1;

    if(this != NULL && id > 0)
    {
        this->id_bike = id;
        error = 0;
    }
    return error;
}

int bicicletas_getId(eBike* this,int* id)
{
    int error = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id_bike;
        error = 0;
    }
    return error;
}

int bicicletas_setNombre(eBike* this,char* nombre)
{
    int error = -1;

    if(this != NULL && nombre != NULL && validations_isValidName(nombre))
    {
        strcpy(this->nombre, nombre);
        error = 0;
    }
    return error;
}

int bicicletas_getNombre(eBike* this,char* nombre)
{
    int error = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        error = 0;
    }
    return error;
}


int bicicletas_setTipo(eBike* this,char* tipo)
{
    int error = -1;

    if(this != NULL && tipo != NULL /*&& validations_isValidType(tipo)*/)
    {
        strcpy(this->tipo, tipo);
        error = 0;
    }
    return error;
}

int bicicletas_getTipo(eBike* this,char* tipo)
{
    int error = -1;

    if(this != NULL && tipo != NULL)
    {
        strcpy(tipo, this->tipo);
        error = 0;
    }
    return error;
}

int bicicletas_setTiempo(eBike* this,int tiempo)
{
    int error = -1;

    if(this != NULL && tiempo >= 0 && tiempo <= 120)
    {
        this->tiempo = tiempo;
        error = 0;
    }
    return error;
}

int bicicletas_getTiempo(eBike* this,int* tiempo)
{
    int error = -1;

    if(this != NULL && tiempo != NULL)
    {
        *tiempo = this->tiempo;
        error = 0;
    }
    return error;
}

int bicicletas_compararPorTipoYTiempo(void* bicicletaA, void* bicicletaB)
{
    int retorno = 0;
    int compararXTipo;
    eBike* bA;
    eBike* bB;

    if(bicicletaA != NULL && bicicletaB != NULL)
    {
        bA = (eBike*)bicicletaA;
        bB = (eBike*)bicicletaB;

        compararXTipo = strcmp(bA->tipo, bB->tipo);

        if (compararXTipo != 0)
        {
            retorno = compararXTipo;
        }
        else if (compararXTipo == 0 && bA->tiempo < bB->tiempo)
        {
            retorno = -1;
        }
        else if (compararXTipo == 0 && bA->tiempo > bB->tiempo)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int bicicletas_map(void* bicicleta)
{
    int retorno = -1;
    eBike* bicicletaActual = NULL;
    int tiempoAleatorio;

    if(bicicleta != NULL)
    {
        bicicletaActual = (eBike*) bicicleta;

        if(bicicletaActual != NULL)
        {
            //Calcular
            tiempoAleatorio = rand()%(71)+50;
            //Setear
            bicicletas_setTiempo(bicicletaActual,tiempoAleatorio);
            retorno = 0;
        }
    }

    return retorno;
}

int bicicletas_filtrarBMX(void* bicicleta)
{
    int retorno = 0;
    eBike* bike = NULL;

    if(bicicleta != NULL)
    {
        bike = (eBike*) bicicleta;

        if(strcmp(bike->tipo,"BMX") == 0)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int bicicletas_filtrarPlayera(void* bicicleta)
{
    int retorno = 0;
    eBike* bike = NULL;

    if(bicicleta != NULL)
    {
        bike = (eBike*) bicicleta;

        if(strcmp(bike->tipo,"PLAYERA") == 0)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int bicicletas_filtrarMTB(void* bicicleta)
{
    int retorno = 0;
    eBike* bike = NULL;

    if(bicicleta != NULL)
    {
        bike = (eBike*) bicicleta;

        if(strcmp(bike->tipo,"MTB") == 0)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int bicicletas_filtrarPaseo(void* bicicleta)
{
    int retorno = 0;
    eBike* bike = NULL;

    if(bicicleta != NULL)
    {
        bike = (eBike*) bicicleta;

        if(strcmp(bike->tipo,"PASEO") == 0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
