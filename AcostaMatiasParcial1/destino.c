#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "destino.h"
int listarDestinos (eDestino destinos[], int cantDest)
{
    int retorno =0;
    if (destinos!= NULL && cantDest > 0)
    {
        printf("        * * * LISTA DE DESTINOS* * *       \n");
        printf("  Id       DESTINO       PRECIO\n");
        printf("--------------------------------\n");
        for (int i = 0; i < cantDest; i++)
        {
            printf("%d   %10s    %10.2f\n",destinos[i].id,destinos[i].desc,destinos[i].precio);
        }
        retorno = 1;
    }
    return retorno;
}


int cargarDescDestino (eDestino destinos[], int cantDest, int idDestBusc, char* descripccion)
{
    int retorno = 0;
    if (destinos!= NULL && cantDest >0  && idDestBusc >=1000 && descripccion != NULL)
    {
        for (int i = 0; i < cantDest; i++)
        {
            if (destinos[i].id == idDestBusc)
            {
                strcpy(descripccion,destinos[i].desc);
            }
        }
        retorno = 1;
    }
    return retorno;
}
