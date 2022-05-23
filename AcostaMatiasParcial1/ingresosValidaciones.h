#ifndef INGRESOSVALIDACIONES_H_INCLUDED
#define INGRESOSVALIDACIONES_H_INCLUDED



#endif // INGRESOSVALIDACIONES_H_INCLUDED

/** \brief Solicita un numero int entre dos rangos establecidos
 *
 * \param pResultado int* puuntero donde se guardara el resultado en caso de ser valido
 * \param mensaje *char mensaje que se muestra al usuario solicitando los numeros
 * \param mensajeError *char mensaje que se muestra en caso de ingresar un numero invalido o fuera de rango.
 * \param minimo int valor minimo que se solicitara
 * \param maximo int valor maximo que se solicitara
 * \param reintentos int cantidada de intentos que se le otorgara para ingresar la informacion, -1 para ingresos infinitos.
 * \return retorno int, 1 si salio todo Ok, 0 en caso de error
 *
 */int utn_getNumeroInt (int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/** \brief Solicita un numero float entre dos rangos establecidos
 *
 * \param pResultado float* puuntero donde se guardara el resultado en caso de ser valido
 * \param mensaje *char mensaje que se muestra al usuario solicitando los numeros
 * \param mensajeError *char mensaje que se muestra en caso de ingresar un numero invalido o fuera de rango.
 * \param minimo float valor minimo que se solicitara
 * \param maximo float valor maximo que se solicitara
 * \param reintentos int cantidada de intentos que se le otorgara para ingresar la informacion, -1 para ingresos infinitos.
 * \return retorno int, 1 si salio todo Ok, 0 en caso de error
 *
 */int utn_getNumeroFloat (float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


/** \brief Solicita el ingreso de una de un array de char validando que solo se ingresen letras hasta un maxino de caracteres indicado
 *
 * \param pResultado char* puuntero donde se guardara el la cadena en caso de ser validada.
 * \param mensaje *char mensaje que se muestra al usuario solicitando que ingrese la cadena
 * \param mensajeError *char mensaje que se muestra en caso de ingresar un caracter invalido o fuera de rango.
 * \param minCaracteres int cantidad minima de caracteres que debera contener la cadena
  * \param maxCaracteres intcantidad maximad de caracteres de debera contener la cadena
 * \param reintentos int cantidada de intentos que se le otorgara para ingresar la informacion, -1 para ingresos infinitos.
 * \return retorno int, 1 si salio todo Ok, 0 en caso de error
 *
 */int utn_getNombreOApellido(char* pResultado, char* mensaje, char* mensajeError,int minCaractres,int maxCaracteres, int reintentos);

/** \brief Solicita el ingreso de una de un array de char validando que solo se ingresen letras  y numeros hasta un maxino de caracteres indicado
 *
 * \param pResultado char* puuntero donde se guardara el la cadena en caso de ser validada.
 * \param mensaje *char mensaje que se muestra al usuario solicitando que ingrese la cadena
 * \param mensajeError *char mensaje que se muestra en caso de ingresar un caracter invalido o fuera de rango.
 * \param minCaracteres int cantidad minima de caracteres que debera contener la cadena
  * \param maxCaracteres intcantidad maximad de caracteres de debera contener la cadena
 * \param reintentos int cantidada de intentos que se le otorgara para ingresar la informacion, -1 para ingresos infinitos.
 * \return retorno int, 1 si salio todo Ok, 0 en caso de error
 *
 */int utn_getAlfanumerico(char* pResultado, char* mensaje, char* mensajeError,int minCaracteres,int maxCaracteres, int reintentos);

int utn_getFecha(int* dia, int* mes, int* anio);


