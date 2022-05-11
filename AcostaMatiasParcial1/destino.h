
#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct
{
    int id;
    char desc[20];
    float precio;
} eDestino;

#endif // DESTINO_H_INCLUDED
/** \brief lista las los destinos de los vuelos
 *
 * \param eDestinos destinos[] array de tipos de destinos
 * \param cantipo int largo del array de destinoos
 * \return 0 en caso de error o no poder mostrar los destinos, 1 si todo ok
 *
 */
int listarDestinos (eDestino destinos[], int cantDest);

/** \brief Carga en un array descripccion la descripccion buscada dentro del array de destinos
 *
 * \param  eDestinos destinos[] array de tipos de destinos
 * \param cantDest int largo del array de destinos
 * \param idTipoBusc int valor del id del destino
 * \param descripccion char* cadena donde se copiara la descripccion correspondiente al id del destino
 * \return 0 en caso de error o no encontrar el destino, 1 si pudo encontrar el destino y copiarlo en *descripccion
 *
 */
int cargarDescDestino (eDestino destinos[], int cantDest, int idDestBusc, char* descripccion);
