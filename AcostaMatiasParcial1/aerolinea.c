#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aerolinea.h"

int listarAerolinea (eAerolinea aerolineas[], int cantAero)
{
    int retorno =0;
    if (aerolineas!= NULL && cantAero > 0)
    {
        printf("        * * * LISTA DE AEROLINEAS * * *       \n");
        printf(" Id      Descripcion\n");
        printf("------------------------\n");
        for (int i = 0; i < cantAero; i++)
        {
            printf("%d   %10s\n",aerolineas[i].id,aerolineas[i].desc);
        }

        retorno = 1;
    }
    return retorno;
}


int cargarDescAero(eAerolinea aerolineas[], int cantAero, int idAeroBusc, char* descripccion)
{
    int retorno = 0;
    if (aerolineas!= NULL && cantAero >0  && idAeroBusc >=1000 && descripccion != NULL)
    {
        for (int i = 0; i < cantAero; i++)
        {
            if (aerolineas[i].id == idAeroBusc)
            {
                strcpy(descripccion,aerolineas[i].desc);
            }
        }
        retorno = 1;
    }
    return retorno;
}
