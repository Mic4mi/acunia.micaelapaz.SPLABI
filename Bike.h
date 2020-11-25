#ifndef BIKE_H_INCLUDED
#define BIKE_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id_bike;
    char nombre[100];
    char tipo[100];
    int  tiempo;
}eBike;

eBike* bicicleta_new();

eBike* bicicletas_newParams(
    char* idAsChar,
    char* nombre,
    char* tipo,
    char* tiempoAsChar);

int bicicletas_setId(eBike* this,int id);
int bicicletas_getId(eBike* this,int* id);

int bicicletas_setNombre(eBike* this,char* nombre);
int bicicletas_getNombre(eBike* this,char* nombre);

int bicicletas_setTipo(eBike* this,char* tipo);
int bicicletas_getTipo(eBike* this,char* tipo);

int bicicletas_setTiempo(eBike* this,int tiempo);
int bicicletas_getTiempo(eBike* this,int* tiempo);

int bicicletas_combArarPorTipoYTiempo(void* bicicletaA, void* bicicletaB);
#endif // BIKE_H_INCLUDED
