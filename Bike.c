#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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

    if(this != NULL && tipo != NULL && validations_isValidType(tipo))
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

    if(this != NULL && tiempo >= 50 && tiempo <= 120)
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
