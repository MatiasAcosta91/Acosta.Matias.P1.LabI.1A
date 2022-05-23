#include "fecha.h"
#include "destino.h"
#include "avion.h"
#include "tipo.h"
#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED

typedef struct
{
    int id;
    int idAvion;
    int idDestino;
    char desc[20];
    eFecha fecha;
    int isEmpty;
} eVuelo;

#endif // VUELO_H_I'NCLUDED

/** \brief Inicializa el array de vuelos inicializando todos los campos isEmpty en 1;
 *
 * \param vuelos[] eVuelo array de vuelos que sera recorrido
 * \param maxVuelos int largo del array
 * \return int 0 en caso de error, 1 si logro inicializarlo correctamente
 *
 */
int inicializarVuelos(eVuelo  vuelos[], int maxVuelos);

/** \brief busca en el array de vuelos si existe lugar libre (campo isEmpty = 1), y retorna el indice encontrado
 *
 * \param vuelos[] eVuelo array de vuelos a recorrer
 * \param maxVuelos int largo del array de vuelos
 * \param pIndex int* devuelve un entero que corresponde indice del lugar libre, -1 en caso de no haber espacio disponible
 * \return int 0 en caso del array lleno o error, 1 en caso de encontrar posicion libre,
 *
 */
int buscarIndexLibreVuelo(eVuelo vuelos[],int maxVuelos, int* pIndex);

/** \brief permite ingresar un nuevo vuelo dentro del array de vuelos
 *
 * \param vuelos[] eVuelo array de vuelos a recorrer donde sera cargado el nuevo vuelo
 * \param maxVuelos int largo del arrayt de vuelos
 * \param aviones[] eAvion array de aviones, se utiliza para cargar la desc del avion.
 * \param cantAviones int largo del array de aviones
 * \param [] eTipo tipos array de tipos se utiliza para cargar la desc del tipo de avion
 * \param cantTipos int largo del array de tipos
 * \param aerolineas[] eAerolinea array de aerolineas, se utiliza para poder cargar la desc de la aerolinea
 * \param cantAerolineas int largo de la cadena de aerolineas
 * \param destinos[] eDestino array de destinos, se utiliza para poder cargar la desc del destino
 * \param cantDestinos int largo del array de destino
 * \param nextIdVuelo int* entero que representa el id del vuelo, en caso de cargarse exitosamente se incremente para que el siguiente vuelo tenga un id distinto
 * \return int 0 en caso de error o no confirmar alta, 1 en caso de alta exitosa.
 *
 */
int altaVuelo(eVuelo vuelos[],int maxVuelos,eAvion aviones[],int cantAviones,eTipo tipos [],int cantTipos,eAerolinea aerolineas[],int cantAerolineas,eDestino destinos[], int cantDestinos,int* nextIdVuelo);

/** \brief lista los vuelos activos (campo isEmpty == 0)
 *
 * \param vuelo[] eVuelo array de vuelos a recorrer
 * \param cantVuelos int largo del array de vuelos
 * \param aviones[] eAvion array de aviones, se tuliza para cargar la desc desc del avion
 * \param maxAviones int largo del array de aviones
 * \param destinos[] eDestino array de destinos, se utiliza para poder cargar la desc del destino
 * \param cantDestinos int largo del array de destinos
 * \return int 0 en caso de error o no encontrar ningun vuelo para listar, 1 en caso de poder listar correctamente.
 *
 */
int listarVuelos(eVuelo vuelo[],int cantVuelos,eAvion aviones[],int maxAviones,eDestino destinos[],int cantDestinos);
int harcodearVuelos(eVuelo vuelos[], int cantVuelos,int* pIdAvion,int* pIdVuelo);
int listarVuelosPorAvion(eVuelo vuelos[],int cantVuelos,eAvion aviones[],int maxAviones,eDestino destinos[],int cantDestinos,eTipo tipos[],int cantTipos,eAerolinea aerolineas[],int cantAero);
int informarCostoTotalSegunAvion(eVuelo vuelos[],int cantVuelos,eAvion aviones[],int maxAviones,eDestino destinos[],int cantDestinos,eTipo tipos[],int cantTipos,eAerolinea aerolineas[],int cantAero);
int avionesSegunDestino (eVuelo vuelos[],int cantVuelos,eAvion aviones[],int maxAviones,eDestino destinos[],int cantDestinos,eTipo tipos[],int cantTipos,eAerolinea aerolineas[],int cantAero);
int vuelosPorFecha (eVuelo vuelos[],int cantVuelos,eAvion aviones[],int maxAviones,eDestino destinos[],int cantDestinos,eTipo tipos[],int cantTipos,eAerolinea aerolineas[],int cantAero);
