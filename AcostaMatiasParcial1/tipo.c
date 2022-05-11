#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tipo.h"
int listarTipos (eTipo tipos[], int cantTipo)
{
    int retorno =0;
    if (tipos!= NULL && cantTipo > 0)
    {
        printf("        * * * LISTA DE TIPOS * * *       \n");
        printf("  Id          TIPO\n");
        printf("------------------------\n");
        for (int i = 0; i < cantTipo; i++)
        {
            printf("%d   %10s\n",tipos[i].id,tipos[i].descTipo);
        }
        retorno = 1;
    }
    return retorno;
}


int cargarDescTipo (eTipo tipos[], int cantTipo, int idTipoBusc, char* descripccion)
{
    int retorno = 0;
    if (tipos!= NULL && cantTipo >0  && idTipoBusc >=1000 && descripccion != NULL)
    {
        for (int i = 0; i < cantTipo; i++)
        {
            if (tipos[i].id == idTipoBusc)
            {
                strcpy(descripccion,tipos[i].descTipo);
            }
        }
        retorno = 1;
    }
    return retorno;
}
