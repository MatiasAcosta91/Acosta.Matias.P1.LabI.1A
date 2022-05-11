
#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED
typedef struct
{
    int id;
    char descTipo[20];
}eTipo;



#endif // TIPO_H_INCLUDED

/** \brief lista las los tipos de aviones
 *
 * \param eTipos tipos[] array de tipos de aviones a mostrar
 * \param cantipo int largo del array de tipos
 * \return 0 en caso de error o no poder mostrar los tipos, 1 si todo ok
 *
 */
 int listarTipos (eTipo tipos[], int cantTipo);

/** \brief Carga en un array descripccion la descripccion buscada dentro del array de tipos
 *
 * \param  eTipos tipos[]  array de tipos de aviones
 * \param canttipos int largo del array
 * \param idTipoBusc int valor del id de la descripccion
 * \param descripccion char* cadena donde se copiara la descripccion correspondiente al id buscado
 * \return 0 en caso de error o no encontrar el tipo, 1 si pudo encontrar el tipo y copiarlo en descripccion
 *
 */int cargarDescTipo (eTipo tipos[], int cantTipo, int idTipoBusc, char* descripccion);
