#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ingresosValidaciones.h"



/** \brief lee desde la entrada hasta que se encuentra un \n o  hasta que haya copiado la cadena con un maximo de longitud.
 *
 * \param  cadena char* puntero donde se copiara la cadena obtenida,
 * \param len int longitud de la cadena buffer
 * \param maxCaracteres int, cantidad maxima de caracteres que escribira, tener el cuenta el \0, por lo cual escribira maxcaracteres-1
 * \return retoirno int -1 en caso de error 0 si salio todo Ok.
 *
 */

static int myGets (char* cadena, int len)
{
    int retorno = 0;
    if (cadena != NULL && len >0)
    {
        fflush(stdin);
        fgets(cadena,len,stdin); //f gets tambien toma el ENTER del buffer de entrada stdin,
        if(cadena[strlen(cadena)-1] == '\n')//elimino el enter que toma fgets
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        retorno = 1;

    }
    return retorno;
}
/** \brief verifica si la cadena ingresada solo contiene letras y numeros sin caracteres especiales.
 *
 * \param cadena char* cadena de caracteres que sera analizada
 * \return int 1 (EXITO) la cadena solo tiene letras o numeros, 0 (ERROR) la cadena contiene caracteres especiales.
 *
 */
static int esAlfanumerica (char* cadena)
{
    int retorno = 1;
    if(cadena != NULL && strlen(cadena)>0)
    {
        for (int i = 0; cadena[i] != '\0'; i++)
        {

            if ( cadena[i] < '0' || (cadena [i] > '9' && cadena[i] < 'A')  || (cadena [i] > 'Z' && cadena[i] < 'a') || cadena[i] >'z')
            {
                retorno = 0;
                break;
            }
            if (i == 0)
            {
                cadena[i] = toupper(cadena[i]);
            }
            else
            {
                cadena[i] = tolower(cadena[i]);
            }
        }
    }

    return retorno;
}

/** \brief verifica si la cadena ingresada solo contiene letras y le otorga formato poniendo en mayuscula el caracter del indice 0 y en minusculas los siguientes ej: Juan.
 *
 * \param cadena char* cadena de caracteres que sera analizada
 * \return int 1 (EXITO) la cadena solo tiene letras, 0 (ERROR).
 *
 */
static int esString(char* cadena)
{
    int retorno = 1;
    if(cadena != NULL && strlen(cadena)>0)
    {
        for (int i = 0; cadena[i] != '\0'; i++)
        {

            if ( cadena[i] < 'A' || (cadena [i] > 'Z' && cadena[i] < 'a') || cadena[i] >'z')
            {
                retorno = 0;
                break;
            }
            if (i == 0)
            {
                cadena[i] = toupper(cadena[i]);
            }
            else
            {
                cadena[i] = tolower(cadena[i]);
            }
        }
    }

    return retorno;
}

/** \brief verifica si la cadena ingresada es numerica
 *
 * \param cadena char* cadena de caracteres que sera analizada
 * \return int 1 (EXITO) la cadena es numerica, 0 (ERROR) la cadena no es numerica
 *
 */
static int esNumerica(char* cadena)
{
    int retorno = 1;
    int i=0;
    if(cadena != NULL && strlen(cadena)>0)
    {
        if (cadena[0] == '-' || cadena [0] == '+')
        {
            i = 1;
        }
        for (; cadena[i] != '\0'; i++)
        {

            if (cadena[i] > '9' || cadena [i] < '0' )
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}
/** \brief verifica si la cadena ingresada es es numerica con decimales y un unico punto
 *
 * \param cadena char* cadena de caracteres que sera analizada
 * \return int 1 (EXITO) la cadena tiene decimales y un unico punto, 0 (ERROR) la cadena no no tiene decimales o tiene mas de un punto
 *
 */
static int esDecimal(char* cadena)
{
    int retorno = 1;
    int i=0;
    int contPuntoComa = 0;
    if(cadena != NULL && strlen(cadena)>0)
    {
        if (cadena[0] == '-' || cadena [0] == '+')
        {
            i = 1;
        }
        for (; cadena[i] != '\0'; i++)
        {
            if(cadena[i] == '.' || cadena[i] == ',')
            {
                contPuntoComa++;
            }
            if ( ((cadena[i] > '9'  || cadena [i] < '0') && cadena[i] != '.' )  ||  contPuntoComa > 1 )

            {

                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}
/** \brief Obtiene un numero una cadena que solo contenga letras desde la terminal.
 *
 * \param pResultado int* donde se devolvera un resultado.
 * \return int 0 en caso de error 1 si salio todo Ok.
 *
 */
static int getString(char* pResultado)
{
    int retorno = 0;
    char buffer[4096];
    if (pResultado != NULL)
    {
        if ( myGets(buffer,sizeof(buffer)) && esString(buffer))
        {
            strcpy(pResultado,buffer);
            retorno = 1;
        }
    }
    return retorno;
}
/** \brief Obtiene un numero entero desde la terminal.
 *
 * \param pResultado int* donde se devolvera un resultado.
 * \return int 0 en caso de error 1 si salio todo Ok.
 *
 */
int getInt(int* pResultado)
{
    int retorno = 0;
    char buffer[4096];
    if (pResultado != NULL)
    {
        if ( myGets(buffer,sizeof(buffer)) && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);
            retorno = 1;
        }
    }
    return retorno;
}
/** \brief Obtiene un numero flotante desde la terminal
 *
 * \param pResultado float* donde se devolvera un resultado.
 * \return int 0 en caso de error 1 si salio todo Ok.
 *
 */
static int getFloat(float* pResultado)
{
    int retorno = 0;
    char buffer[4096];
    if (pResultado != NULL)
    {
        if ( myGets(buffer,sizeof(buffer)) && esDecimal(buffer))
        {
            *pResultado = atof(buffer);
            retorno = 1;
        }
    }
    return retorno;
}

/** \brief Obtiene una cadena alfanumerica desde la terminal
 *
 * \param pResultado char* donde se devolvera un resultado.
 * \return int 0 en caso de error 1 si salio todo Ok.
 *
 */
static int getAlfanumerico (char* pResultado)
{
    int retorno = -1;
    char buffer[4096];
    if (pResultado != NULL)
    {
        if ( myGets(buffer,sizeof(buffer)) && esAlfanumerica(buffer))
        {
            strcpy(pResultado,buffer);
            retorno = 0;
        }
    }
    return retorno;
}


int utn_getNumeroInt (int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = 0;
    int buffer;
    int flagInfinito = 0;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= -1)
    {
        if(reintentos == -1)
        {
            flagInfinito = 1;
        }
        do
        {
            printf("%s",mensaje);
            if (getInt(&buffer) && buffer <= maximo && buffer >= minimo)
            {
                *pResultado = buffer;
                retorno = 1;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos --;
            }

        }
        while (reintentos >= 0 || flagInfinito);
    }
    return retorno;
}
int utn_getNumeroFloat (float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
    int retorno = 0;
    float buffer;
    int flagInfinito = 0;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= -1)
    {
        if(reintentos == -1)
        {
            flagInfinito = 1;
        }
        do
        {
            printf("%s",mensaje);
            if (getFloat(&buffer) && buffer <= maximo && buffer >= minimo)
            {
                *pResultado = buffer;
                retorno = 1;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos --;
            }

        }
        while (reintentos >= 0 || flagInfinito);
    }
    return retorno;
}

int utn_getNombreOApellido(char* pResultado, char* mensaje, char* mensajeError,int minCaracteres,int maxCaracteres, int reintentos)
{
    int retorno = 0;
    char buffer[4096];
    int flagInfinito = 0;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= -1)
    {
        if(reintentos == -1)
        {
            flagInfinito = 1;
        }
        do
        {
            printf("%s",mensaje);
            if (getString(buffer) && strlen(buffer) <= maxCaracteres && strlen(buffer) >= minCaracteres )
            {
                strcpy(pResultado,buffer);
                retorno = 1;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos --;
            }

        }
        while (reintentos >= 0 || flagInfinito);
    }
    return retorno;
}

int utn_getAlfanumerico(char* pResultado, char* mensaje, char* mensajeError,int minCaracteres,int maxCaracteres, int reintentos)
{
    int retorno = 0;
    char buffer[4096];
    int flagInfinito = 0;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minCaracteres > 0 && minCaracteres<=maxCaracteres && reintentos >= -1)
    {
        if(reintentos == -1)
        {
            flagInfinito = 1;
        }
        do
        {
            printf("%s",mensaje);
            if (getAlfanumerico(buffer) == 0 && strlen(buffer)>= minCaracteres && strlen(buffer)<=maxCaracteres)
            {
                strcpy(pResultado,buffer);
                retorno = 1;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos --;
            }

        }
        while (reintentos >= 0 || flagInfinito);

    }
    return retorno;
}
int esFecha(int dia, int mes, int anio)
{
    int retorno = 0;
    if ( mes >= 1 && mes <= 12 )
    {
        retorno = 1;
        switch ( mes )
        {
        case  1 :
        case  3 :
        case  5 :
        case  7 :
        case  8 :
        case 10 :
        case 12 :
            if ( dia < 1 || dia > 31 )
            {
                retorno = 0;
            }
            break;
        case  4 :
        case  6 :
        case  9 :
        case 11 :
            if ( dia < 1 || dia >30 )
            {
                retorno = 0;
            }
            break;

        case  2 :
            if ( dia < 1 ||  dia > 28 )
            {
                retorno = 0;
            }

        }
    }
    return retorno;
}
int utn_getFecha(int* dia, int* mes, int* anio)
{
    int retorno = 0;
    char mensajeDia[]="Ingrese el dia 1 a 31 (puede variar segun el mes): ";
    char mensajeMes[]="Ingrese el mes 1 a 12: ";
    char mensajeAnio[]="Ingrese el anio 1900 a 2022: ";
    char mensajeError[]="Error=";
    int auxDia;
    int auxMes;
    int auxAnio;
    int flagSeguir;
    if (dia != NULL && mes != NULL && anio != NULL)
    {
        do
        {
            utn_getNumeroInt(&auxDia,mensajeDia,mensajeError,1,31,-1);
            utn_getNumeroInt(&auxMes,mensajeMes,mensajeError,1,12,-1);
            utn_getNumeroInt(&auxAnio,mensajeAnio,mensajeError,1900,2022,-1);
            if (!esFecha(auxDia,auxMes,auxAnio))
            {
                flagSeguir = 1;
                printf("ERROR=La fecha ingresada es invalida, ingresela nuevamente.\n");
            }
            else
            {
                *dia = auxDia;
                *mes = auxMes;
                *anio = auxAnio;
                flagSeguir = 0;
                retorno = 1;
            }
        }while(flagSeguir == 1);
    }
    return retorno;
}
