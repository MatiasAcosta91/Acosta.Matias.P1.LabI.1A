#include <stdio.h>
#include <stdlib.h>

#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#include "destino.h"
#include "vuelo.h"

#define CANT_AERO 5
#define CANT_TIPO 4
#define CANT_DEST 4
#define MAX_AVIONES 5000
#define MAX_VUELOS 5000
/*
MATERIA: LABORATORIO 1
PARCIAL: 1 PARTE 1
FECHA: 11/5/2022.
AUTOR: ACOSTA MATIAS JORDAN
DNI: 36.401.197
DIVISION: 1A TURNO MAÑANA
PROFESOR: CHRISTIAN BAUS
*/

int menu();

char continuar = 's';
int main()
{
    eAerolinea aerolineas[CANT_AERO]=
    {
        {1000,"Lan"},
        {1001,"Iberia"},
        {1002,"Norwegian"},
        {1003,"American"},
        {1004,"Austral"}
    };
    eTipo tipos[CANT_TIPO]=
    {
        {5000,"Jet"},
        {5001,"Helice"},
        {5002,"Planeador"},
        {5003,"Carga"}
    };
    eDestino destinos[CANT_DEST]=
    {
        {20000,"Calafate",22250},
        {20001,"Miami",103000},
        {20002,"Madrid",84400},
        {20003,"Amsterdam",95600}
    };

    eAvion aviones[MAX_AVIONES];
    eVuelo vuelos[MAX_VUELOS];
    inicializarAviones(aviones,MAX_AVIONES);
    inicializarVuelos(vuelos,MAX_VUELOS);
    int nextIdAvion = 10000;
    int nextIdVuelo = 100;

    do
    {
        switch(menu())
        {
        case 1:
            altaAvion(aviones,MAX_AVIONES,aerolineas,CANT_AERO,tipos,CANT_TIPO,&nextIdAvion);
            break;
        case 2:
            modificarAvion(aviones,MAX_AVIONES,aerolineas,CANT_AERO,tipos,CANT_TIPO);
            break;
        case 3:
            bajaAvion(aviones,MAX_AVIONES,aerolineas,CANT_AERO,tipos,CANT_TIPO);
            break;
        case 4:
            if (!listarAviones(aviones,MAX_AVIONES,tipos,CANT_TIPO,aerolineas,CANT_AERO))
            {
                printf("No hay aviones para listar.\n");
            }
            break;
        case 5:
            listarAerolinea(aerolineas,CANT_AERO);
            break;
        case 6:
            listarTipos(tipos,CANT_TIPO);
            break;
        case 7:
            listarDestinos(destinos,CANT_DEST);
            break;
        case 8:
            altaVuelo(vuelos,MAX_VUELOS,aviones,MAX_AVIONES,tipos,CANT_TIPO,aerolineas,CANT_AERO,destinos,CANT_DEST,&nextIdVuelo);
            break;
        case 9:
            if (!listarVuelos(vuelos,MAX_VUELOS,aviones,MAX_AVIONES,destinos,CANT_DEST) )
            {
                printf("No hay vuelos ingresados.\n");
            }
            break;
        case 10:
            continuar ='n';
            break;
        default:
            printf("Opcion incorrecta.\n");
            break;
        }
        system("pause");
    }
    while(continuar == 's');
    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("*********************************************************\n");
    printf("*                        A B M                           *\n");
    printf("*********************************************************\n");
    printf("1.ALTA AVION .\n");
    printf("2.MODIFICAR AVION .\n");
    printf("3.BAJA AVION.\n");
    printf("4.LISTAR AVIONES .\n");
    printf("5.LISTAR AEROLINEAS .\n");
    printf("6.LISTAR TIPOS .\n");
    printf("7.LISTAR DESTINOS.\n");
    printf("8.ALTA VUELO .\n");
    printf("9.LISTAR VUELOS.\n");
    printf("10.SALIR .\n");

    scanf("%d",&opcion);
    fflush(stdin);
    system("cls");
    return opcion;
}
