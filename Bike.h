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

/** \brief Crea un puntero a Bicicleta, setea los valores en cero o string vacio
 * le asigna espacio en memoria dinamica.
 * \return un puntero a bicicleta o NULL si no consigue espacio en memoria
 *
 */
eBike* bicicleta_new();

/** \brief Crea un puntero a bicicleta, setea los valores y le asigna espacio en memoria dinamica.
 *
 * \param char* id
 * \param char* nombre
 * \param char* tipo
 * \param char* tiempo
 * \return un puntero a bicicleta o NULL si no consigue espacio en memoria
 *
 */
eBike* bicicletas_newParams(
    char* idAsChar,
    char* nombre,
    char* tipo,
    char* tiempoAsChar);

/** \brief Asigna un ID a una bicicleta
 *
 * \param bicicleta* this
 * \param int id
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el id es menor a cero)
 *
 */
int bicicletas_setId(eBike* this,int id);

/** \brief Obtiene un ID de una bicicleta
 *
 * \param bicicleta* this
 * \param int* id
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el id es menor a cero)
 *
 */
int bicicletas_getId(eBike* this,int* id);

/** \brief Asigna un nombre a una bicicleta
 *
 * \param bicicleta* this
 * \param char* nombre
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o nombre no es valido)
 *
 */
int bicicletas_setNombre(eBike* this,char* nombre);

/** \brief Obtiene el nombre de una bicicleta
 *
 * \param bicicleta* this
 * \param char* nombre
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el nombre no es valido)
 *
 */
int bicicletas_getNombre(eBike* this,char* nombre);

/** \brief Asigna un tipo a una bicicleta
 *
 * \param bicicleta* this
 * \param char* tipo
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o tipo no es valido)
 *
 */
int bicicletas_setTipo(eBike* this,char* tipo);

/** \brief Obtiene el tipo de una bicicleta
 *
 * \param bicicleta* this
 * \param char* tipo
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el tipo no es valido)
 *
 */
int bicicletas_getTipo(eBike* this,char* tipo);

/** \brief Asigna un tiempo a una bicicleta
 *
 * \param bicicleta* this
 * \param int tiempo
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el tiempo es menor a cero)
 *
 */
int bicicletas_setTiempo(eBike* this,int tiempo);

/** \brief Obtiene un tiempo de una bicicleta
 *
 * \param bicicleta* this
 * \param int* tiempo
 * \return [0] si esta todo bien, [-1] si hay errores (El puntero es NULL o el tiempo es menor a cero)
 *
 */
int bicicletas_getTiempo(eBike* this,int* tiempo);

/** \brief Rellena el campo tiempo de una bicicleta
 *
 * \param void* bicicleta
 * \return int retorno
 *
 */
int bicicletas_map(void* bicicleta);

/** \brief Filtra las bicicletas por tipo BMX
 *
 * \param void* bicicleta
 * \return [0] si no es del tipo indicado, o [1] si es del tipo indicado
 *
 */
int bicicletas_filtrarBMX(void* bicicleta);

/** \brief Filtra las bicicletas por tipo PLAYERA
 *
 * \param void* bicicleta
 * \return [0] si no es del tipo indicado, o [1] si es del tipo indicado
 *
 */
int bicicletas_filtrarPlayera(void* bicicleta);

/** \brief Filtra las bicicletas por tipo MTB
 *
 * \param void* bicicleta
 * \return [0] si no es del tipo indicado, o [1] si es del tipo indicado
 *
 */
int bicicletas_filtrarMTB(void* bicicleta);

/** \brief Filtra las bicicletas por tipo PASEO
 *
 * \param void* bicicleta
 * \return [0] si no es del tipo indicado, o [1] si es del tipo indicado
 *
 */
int bicicletas_filtrarPaseo(void* bicicleta);

/** \brief Compara el campo tipo y tiempo de dos bicicletas
 *
 * \param void* bicicletaA
 * \param void* bicicletaB
 * \return [0] si son iguales, [-1] si el primero esta después en la tabla ASCII
 * o [1] si el primero esta antes en la tabla ASCII
 *
 */
int bicicletas_compararPorTipoYTiempo(void* bicicletaA, void* bicicletaB);

#endif // BIKE_H_INCLUDED
