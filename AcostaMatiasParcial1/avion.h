#include "aerolinea.h"
#include "tipo.h"
#include "ingresosValidaciones.h"
#include "tipo.h"
#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED
typedef struct
{
    int id;
    int idAerolinea;
    int idTipo;
    int capacidad;
    int isEmpty;
} eAvion;

#endif // AVION_H_INCLUDED

/** \brief inicializa el array de aviones poniendo el campo isEmpty en 1;
 *
 * \param eAvion aviones[] array de aviones
 * \param maxAviones int, largo del array de aviones
 * \return  0 en caso de error, 1 si lo pudo inicializar
 *
 */
int inicializarAviones (eAvion aviones[], int maxAviones);

/** \brief Recorre el array de aviones buscando un campo libre isEmpty == 1
 *
 * \param aviones[] eAvion array de aviones
 * \param maxAviones int largo del array
 * \param pIndex int* devuelve el indice de la posicion libre del array de aviones
 * \return int 0 en caso de error o no haber lugar libre, 1 si devolvio alguna posicion libre
 *
 */
int buscarIndexLibre(eAvion aviones[],int maxAviones, int* pIndex);
/** \brief Lista un avion
 *
 * \param aviones eAvion avion que sera listado
 * \param aerolineas[] eAerolinea array deaerolineas se usara para poder cargar la descripccion de la aerolinea
 * \param cantAero int largo del array de aerolinea
 * \param tipos[] eTipo array de tipos se usara para poder cargar la descripccion del tipo correspondiente
 * \param cantTipos int largo del array de tipos
 * \return int 0 en caso de error, 1 en caso de poder listar el avion correctamente
 *
 */
int listarAvion(eAvion aviones,eAerolinea aerolineas[],int cantAero, eTipo tipos[],int cantTipos);
/** \brief lista el todos los aviones del array de aviones cuyo campo isEmpty == 0
 *
 * \param aviones[] eAvion array de aviones que seran listado
 * \param tamAviones int tamaño del array
 * \param tipos[] eTipo array de tipos se usara para cargar la descripccion del tipo de avionc
 * \param aerolineas[] eAerolinea array de aerolineas se usara para cargar la desc de la aerolinea
 * \param cantAerolineas int largo del array de aerolineas
 * \return int 0 en caso de error o que no se encuentre ningun avion para listar, 1 si pudo listar algun avion
 *
 */
int listarAviones( eAvion aviones[],int tamAviones,eTipo tipos[],int cantTipos,eAerolinea aerolineas[],int cantAerolineas);
/** \brief permite dar el alta de un nuevo avion en el array de aviones
 *
 * \param aviones[] eAvion array de aviones sobre el cual se ingresara el nuevo avion en algun campo libre (isEmpty =1)
 * \param maxAviones int largo del array de aviones
 * \param aerolineas[] eAerolinea  eAerolinea array de aerolineas se usara para cargar la desc de la aerolinea
 * \param cantAero int largo del array de aerolineas
 * \param tipos[] eTipo array de tipos se usara para cargar la descripccion del tipo de avionc
 * \param cantTipos int largo del array de tipos
 * \param nextIdAvion int* puntero que cargara el valor del id del nuevo avion ingresado,confirmada la carga de un nuevo avion se incremetara en 1 para que el siguiente avion posea un id distinto.
 * \return int 0 en caso de error o no confirmar el alta del avion, 1 si se dio de alta algun avion nuevo
 *
 */
int altaAvion(eAvion aviones[],int maxAviones,eAerolinea aerolineas[],int cantAero, eTipo tipos[],int cantTipos,int* nextIdAvion);
/** \brief Busca el id de un avion detro del array de aviones, devuelve el indice del avion en caso de que se encuentre
 *
 * \param aviones[] eAvion array de aviones donde se hara la busqueda
 * \param tamAviones int tamaño del array
 * \param idBuscado int id del avion buscado
 * \param posEncontrada int* puntero donde se devolvera la posicion  entera del array en la que se encuentra el avion, en caso de no encontrarlo se carga -1;
 * \return int 0 en caso de error o no encontrarlo, 1 en caso de haber encontrado el avion.
 *
 */
int buscarAvionId(eAvion aviones[],int tamAviones, int idBuscado,int* posEncontrada);

/** \brief Permite realizar la baja logica de un avion cambiando si campo isEmpty a 1;
 *
 * \param aviones[] eAvion array sobre el cual se realizara la busqueda del avion a dar de baja
* \param    maxAviones int largo del array de aviones
 * \param aerolineas[] eAerolinea array deaerolineas se usara para poder cargar la descripccion de la aerolinea
 * \param cantAero int largo del array de aerolinea
 * \param tipos[] eTipo array de tipos se usara para poder cargar la descripccion del tipo correspondiente
 * \param cantTipos int largo del array de tipos
 * \return int 0 en caso de error o no concretar la baja, 1 en caso de baja exitosa
 *
 */
int bajaAvion (eAvion aviones[],int maxAviones,eAerolinea aerolineas[],int cantAero, eTipo tipos[],int cantTipos);


/** \brief permite dar el modificar un avion activo cuyo campo isEmpty == 0;
 * \param aviones[] eAvion array de aviones sobre el cual se realizara la busqueda del avion a modificar
 * \param maxAviones int largo del array de aviones
 * \param aerolineas[] eAerolinea  eAerolinea array de aerolineas se usara para cargar la desc de la aerolinea
 * \param cantAero int largo del array de aerolineas
 * \param tipos[] eTipo array de tipos se usara para cargar la descripccion del tipo de avion
 * \param cantTipos int largo del array de tipos
 * \return int 0 en caso de error o no confirmar el cambio de algun campo, 1 si modifico algun campo.
 *
 */
int modificarAvion (eAvion aviones[],int maxAviones,eAerolinea aerolineas[],int cantAero, eTipo tipos[],int cantTipos);

/** \brief muestra un menu de opciones para poder elegir la modificacion a realizar
 *
 * \return int devuelve la opcion elegida por el usuario
 *
 */
int menuModificacion();


/** \brief Recorre el array de aviones para encontrar si el id del avion existe y retorna la posicion del array de ese avion.
 *
 * \param aviones[] eAvion array de aviones a recorrer
 * \param cantAviones int largod el array de aviones
 * \param idAvionBuscado int id del avion que se buscara
 * \param indiceAvionBusc int* indice del avion, si no se encuentra devuelve -1
 * \return int 0 en caso de no encontrarlo o en caso de error, 1 si pudo encontrarlo y devolver la posicion
 *
 */
int buscarAvionExistente(eAvion aviones[],int cantAviones,int idAvionBuscado,int* indiceAvionBusc);
