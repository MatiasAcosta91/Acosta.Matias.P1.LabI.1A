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
        printf("%d       %d       %s      \t%02d/%02d/%04d\n",vuelo.id,vuelo.idAvion,descDestino,vuelo.fecha.dia,vuelo.fecha.mes,vuelo.fecha.anio);
    }
    return retorno;
}
int listarVuelos(eVuelo vuelo[],int cantVuelos,eAvion aviones[],int maxAviones,eDestino destinos[],int cantDestinos)
{
    int retorno = 0;
    if (aviones != NULL && destinos != NULL && maxAviones >0 && cantDestinos >0)
    {
        printf("ID VUELO   ID AVION   DESTINO            FECHA\n");
        printf("-----------------------------------------------\n");
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
    char mensajeDestino[]="Ingrese el destino: ";
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

                    utn_getFecha(&auxVuelo.fecha.dia,&auxVuelo.fecha.mes,&auxVuelo.fecha.anio);

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
int harcodearVuelos(eVuelo vuelos[], int cantVuelos,int* pIdAvion,int* pIdVuelo)
{
    int retorno = 0;
    int j = 0;
    eVuelo aux[10]=
    {
        {0,0,20000,"",{1,1,2001},0},
        {0,0,20001,"",{27,2,2007},0},
        {0,0,20002,"",{29,3,2020},0},
        {0,0,20003,"",{21,5,2022},0},
        {0,0,20004,"",{22,7,1990},0},
        {0,0,20004,"",{24,8,2000},0},
        {0,0,20002,"",{21,12,2003},0},
        {0,0,20003,"",{1,1,2001},0},
        {0,0,20001,"",{12,4,2010},0},
        {0,0,20002,"",{13,7,2012},0}

    };
    if (vuelos != NULL && pIdAvion != NULL && pIdVuelo != NULL && cantVuelos >0)
    {
        for (int i = 0; i < cantVuelos &&  j < 10; i++)
        {
           if (vuelos[i].isEmpty == 1)
           {
               vuelos[i] = aux[j];
               vuelos[i].id = *pIdVuelo;
               *pIdVuelo = *pIdVuelo +1;
               vuelos[i].idAvion = *pIdAvion;
               *pIdAvion = *pIdAvion +1;
               j++;
           }
        }
        retorno = 1;
    }
    return retorno;
}

int listarVuelosPorAvion(eVuelo vuelos[],int cantVuelos,eAvion aviones[],int maxAviones,eDestino destinos[],int cantDestinos,eTipo tipos[],int cantTipos,eAerolinea aerolineas[],int cantAero)
{
    int retorno = 0;
    char mensajeAvion[]="Seleccione un avion: ";
    char mensajeError[]="ERROR=";
    int avionBuscado;
    int indexAvionBucado;
    if (vuelos != NULL && aviones != NULL && destinos != NULL && tipos != NULL && aerolineas != NULL && cantVuelos >0 && maxAviones >0 && cantDestinos >0 && cantTipos >0 && cantAero >0)
    {
        listarAviones (aviones,maxAviones,tipos,cantTipos,aerolineas,cantAero);
        utn_getNumeroInt(&avionBuscado,mensajeAvion,mensajeError,10000,99999,INTENTOSINF);
       if (!buscarAvionId(aviones,maxAviones,avionBuscado,&indexAvionBucado))
       {
           printf("No se encontro el avion.\n");
       }
       else
       {
           for (int i = 0; i <cantVuelos; i++ )
           {
               if ( vuelos [i].isEmpty == 0 &&  vuelos[i].idAvion == avionBuscado)
               {
                   listarVuelo (vuelos[i],aviones,maxAviones,destinos,cantDestinos);
                   retorno = 1;
               }
           }
       }
    }
    return retorno;
}

int informarCostoTotalSegunAvion(eVuelo vuelos[],int cantVuelos,eAvion aviones[],int maxAviones,eDestino destinos[],int cantDestinos,eTipo tipos[],int cantTipos,eAerolinea aerolineas[],int cantAero)
{
    int retorno = 0;
    char mensajeAvion[]="Seleccione un avion: ";
    char mensajeError[]="ERROR=";
    int avionBuscado;
    int indexAvionBucado;
    float acumPrecios = 0;
    if (vuelos != NULL && aviones != NULL && destinos != NULL && tipos != NULL && aerolineas != NULL && cantVuelos >0 && maxAviones >0 && cantDestinos >0 && cantTipos >0 && cantAero >0)
    {
        listarAviones (aviones,maxAviones,tipos,cantTipos,aerolineas,cantAero);
        utn_getNumeroInt(&avionBuscado,mensajeAvion,mensajeError,10000,99999,INTENTOSINF);
       if (!buscarAvionId(aviones,maxAviones,avionBuscado,&indexAvionBucado))
       {
           printf("No se encontro el avion.\n");
       }
       else
       {
           for (int i = 0; i <cantVuelos; i++ )
           {
               if ( vuelos [i].isEmpty == 0 &&  vuelos[i].idAvion == avionBuscado)
               {
                   for(int j = 0; j<cantDestinos; j++)
                   {
                       if (destinos[i].id == vuelos[i].idDestino)
                       {
                           acumPrecios = acumPrecios + destinos[i].precio;
                       }
                   }

                   retorno = 1;
               }
           }
       }
       printf("La suma de los precios del avion seleccionado es %.2f\n",acumPrecios);
    }
    return retorno;
}

int avionesSegunDestino (eVuelo vuelos[],int cantVuelos,eAvion aviones[],int maxAviones,eDestino destinos[],int cantDestinos,eTipo tipos[],int cantTipos,eAerolinea aerolineas[],int cantAero)
{
    int retorno = 0;
    char mensajeDestino[]="Seleccione un destino: ";
    char mensajeError[]="ERROR=";
    int destinoElegido;
    int avionEncontrado;
    int flag = 0;
    if (vuelos != NULL && aviones != NULL && destinos != NULL && tipos != NULL && aerolineas != NULL && cantVuelos >0 && maxAviones >0 && cantDestinos >0 && cantTipos >0 && cantAero)
    {
        listarDestinos(destinos,cantDestinos);
        utn_getNumeroInt(&destinoElegido,mensajeDestino,mensajeError,20000,20003,INTENTOSINF);
        printf("ID VUELO   ID AVION   DESTINO        FECHA\n");
        printf("-------------------------------------------\n");
        for (int i = 0; i < cantVuelos; i++)
        {
            if (vuelos[i].isEmpty == 0 && vuelos[i].idDestino == destinoElegido)
            {
                buscarAvionExistente(aviones,maxAviones,vuelos[i].idAvion,&avionEncontrado);
                listarAvion(aviones[avionEncontrado],aerolineas,cantAero,tipos,cantTipos);
                flag = 1;
            }
        }
        if (!flag)
        {
            printf("No se encontraron aviones para el destino seleccionado.\n");
        }
        retorno = 1;
    }
    return retorno;
}
int vuelosPorFecha (eVuelo vuelos[],int cantVuelos,eAvion aviones[],int maxAviones,eDestino destinos[],int cantDestinos,eTipo tipos[],int cantTipos,eAerolinea aerolineas[],int cantAero)
{
    int retorno = 0;
    eFecha fechaAux;
    int flag = 0;
    if (aviones != NULL && destinos != NULL && maxAviones >0 && cantDestinos >0)
    {

        utn_getFecha(&fechaAux.dia,&fechaAux.mes,&fechaAux.anio);
        printf("ID VUELO   ID AVION   DESTINO        FECHA\n");
        printf("-------------------------------------------\n");
        for (int i = 0; i < cantVuelos; i++)
        {
            if (vuelos[i].fecha.anio == fechaAux.anio && vuelos[i].fecha.mes == fechaAux.mes && vuelos[i].fecha.dia == fechaAux.dia)
            {
                listarVuelo(vuelos[i],aviones,maxAviones,destinos,cantDestinos);
                flag = 1;
            }
        }
        if (!flag)
        {
            printf("No se encontraron  vuelos para la fecha seleccionada. \n");
        }
        retorno = 1;
    }
    return retorno;
}
