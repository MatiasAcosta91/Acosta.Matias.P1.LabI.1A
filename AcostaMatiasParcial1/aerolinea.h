#ifndef AEROLINEA_H_INCLUDED
#define AEROLINEA_H_INCLUDED
typedef struct
{
    int id;
    char desc[20];
} eAerolinea;


#endif // AEROLINEA_H_INCLUDED
/** \brief lista las aerolineas
 *
 * \param eAerolineas aerolineas[] array de aerolineas a mostrar
 * \param cantAero int largo del array de aerolineas
 * \return 0 en caso de error o no poder mostrar aerolineas, 1 si todo ok
 *
 */
int listarAerolinea (eAerolinea aerolineas[], int cantAero);
/** \brief Carga en un array descripccion la descripccion buscada dentro del array de aerolineas
 *
 * \param aerolineas[] eAerolinea array de aerolineas
 * \param cantAero int largo del array
 * \param idAeroBusc int valor del id de la descripccion
 * \param descripccion char* cadena donde se copiara la descripccion correspondiente al id buscado
 * \return int 0 en caso de error o no encontrar el la aerolinea, 1 si pudo encontrar la aerolinea  y copiar la descripccion en en *descripccion
 *
 */
int cargarDescAero(eAerolinea aerolineas[], int cantAero, int idAeroBusc, char* descripccion);
