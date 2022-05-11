#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "vuelo.h"
#define INTENTOSINF -1


int inicializarVuelos(eVuelo  vuelos[], int maxVuelos)
{
    int retorno = 0;
    if (vuelos!= NULL && maxVuelos> 0)
    {
        for (int i = 0; i < maxVuelos; i++)
        {
            vuelos[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}
int buscarIndexLibreVuelo(eVuelo vuelos[],int maxVuelos, int* pIndex)
{
    int retorno = 0;
    if (vuelos !=  NULL && maxVuelos >0 && pIndex != NULL)
    {
        *pIndex = -1;
        for (int i = 0; i < maxVuelos; i++)
        {
            if (vuelos[i].isEmpty ==1)
            {
                *pIndex =  i;
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}
int listarVuelo(eVuelo vuelo,eAvion aviones[],int maxAviones,eDestino destinos[],int cantDestinos)
{
    int retorno = 0;
    char descDestino[20];
    if (aviones != NULL && destinos != NULL && maxAviones >0 && cantDestinos >0)
    {
        cargarDescDestino(destinos,cantDestinos,vuelo.idDestino,descDestino);
        printf("%d       %d       %s      %02d/%02d/%04d\n",vuelo.id,vuelo.idAvion,descDestino,vuelo.fecha.dia,vuelo.fecha.mes,vuelo.fecha.anio);
    }
    return retorno;
}
int listarVuelos(eVuelo vuelo[],int cantVuelos,eAvion aviones[],int maxAviones,eDestino destinos[],int cantDestinos)
{
    int retorno = 0;
    if (aviones != NULL && destinos != NULL && maxAviones >0 && cantDestinos >0)
    {
        printf("ID VUELO   ID AVION   DESTINO        FECHA\n");
        printf("-------------------------------------------\n");
        for (int i = 0; i < cantVuelos; i++)
        {
            if (vuelo[i].isEmpty == 0)
            {
                listarVuelo(vuelo[i],aviones,maxAviones,destinos,cantDestinos);
                retorno = 1;
            }
        }
    }
    return retorno;
}
int altaVuelo(eVuelo vuelos[],int maxVuelos,eAvion aviones[],int cantAviones,eTipo tipos [],int cantTipos,eAerolinea aerolineas[],int cantAerolineas,eDestino destinos[], int cantDestinos,int* nextIdVuelo)
{
    int retorno = 0;
    int posLibre;
    char mensajeIdAvion[]="Ingrese el Id del avion a partir del 10000: ";
    char mensajeDestino[]="Ingrese capacidad 10 a 30 pasajeros: ";
    char mensajeError[]="ERROR=";
    int indiceAvionEncontrado;
    char confirmaAlta;
    eVuelo auxVuelo;
    if (vuelos != NULL && destinos != NULL && nextIdVuelo != NULL && aviones !=NULL && cantAviones >0 && maxVuelos > 0 && cantDestinos >0)
    {
        if(!buscarIndexLibreVuelo(vuelos,maxVuelos,&posLibre))
        {
            printf("No hay espacio para cargar mas aviones.\n");
        }
        else
        {
            if (!listarAviones(aviones,cantAviones,tipos,cantTipos,aerolineas,cantAerolineas))
            {
                printf("No hay aviones cargados.\n");
            }
            else
            {
                utn_getNumeroInt(&auxVuelo.idAvion,mensajeIdAvion,mensajeError,10000,99999999,INTENTOSINF);

                if (!buscarAvionExistente(aviones,cantAviones,auxVuelo.idAvion,&indiceAvionEncontrado) )
                {
                    printf("No se encontro el id del avion ingresado.\n");
                }
                else
                {
                    auxVuelo.id = *nextIdVuelo;

                    listarAviones(aviones,cantAviones,tipos,cantTipos,aerolineas,cantAerolineas);

                    listarDestinos(destinos,cantDestinos);
                    utn_getNumeroInt(&auxVuelo.idDestino,mensajeDestino,mensajeError,20000,20004,INTENTOSINF);

                    printf("Ingrese Fecha dd/mm/aaaa: ");
                    scanf("%d/%d/%d",&auxVuelo.fecha.dia,&auxVuelo.fecha.mes,&auxVuelo.fecha.anio);
                    printf("ID VUELO   ID AVION   DESTINO        FECHA\n");
                    printf("-------------------------------------------\n");
                    listarVuelo(auxVuelo,aviones,cantAviones,destinos,cantDestinos);

                    printf("\n\nConfirma Alta del vuelo?s/n: ");
                    fflush(stdin);
                    scanf("%c",&confirmaAlta);
                    confirmaAlta = tolower(confirmaAlta);
                    while (confirmaAlta!= 's' && confirmaAlta!= 'n')
                    {

                        printf("ERROR: Confirma Alta? S/N: ");
                        fflush(stdin);
                        scanf("%c",&confirmaAlta);
                        confirmaAlta = tolower(confirmaAlta);
                    }
                    if (confirmaAlta == 's')
                    {
                        vuelos[posLibre]= auxVuelo;
                        vuelos[posLibre].isEmpty = 0;
                        *nextIdVuelo = *nextIdVuelo +1;
                    }
                    else
                    {
                        printf("Se cancelo el alta del vuelo.\n");
                    }
                }
            }
        }
    }
    return retorno;
}
