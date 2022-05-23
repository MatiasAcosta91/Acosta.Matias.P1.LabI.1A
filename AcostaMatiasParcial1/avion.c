#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "avion.h"


#define INTENTOSINF -1

int inicializarAviones (eAvion aviones[], int maxAviones)
{
    int retorno = 0;
    if (aviones!= NULL && maxAviones> 0)
    {
        for (int i = 0; i < maxAviones; i++)
        {
            aviones[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}
int buscarIndexLibre(eAvion aviones[],int maxAviones, int* pIndex)
{
    int retorno = 0;
    if (aviones !=  NULL && maxAviones >0 && pIndex != NULL)
    {
        *pIndex = -1;
        for (int i = 0; i < maxAviones; i++)
        {
            if (aviones[i].isEmpty ==1)
            {
                *pIndex =  i;
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

int listarAvion(eAvion aviones,eAerolinea aerolineas[],int cantAero, eTipo tipos[],int cantTipos)
{
    int retorno = 0;
    char descTipo[20];
    char descAero[20];
    if (aerolineas != NULL && cantAero > 0 && cantTipos > 0)
    {
        cargarDescAero(aerolineas,cantAero,aviones.idAerolinea,descAero);
        cargarDescTipo(tipos,cantTipos,aviones.idTipo,descTipo);
        printf("%d     %10s      %10s      %5d\n",aviones.id,descAero,descTipo,aviones.capacidad);
    }
    return retorno;
}

int listarAviones( eAvion aviones[],int tamAviones,eTipo tipos[],int cantTipos,eAerolinea aerolineas[],int cantAerolineas)
{
    int retorno = 0;
    if (aviones != NULL && tipos != NULL && aerolineas != NULL && cantAerolineas > 0 && cantTipos > 0 && tamAviones >0)
    {
        printf("ID           AEROLINEA           TIPO      CAPACIDAD \n");
        printf("------------------------------------------------------\n");
        for (int i = 0; i < tamAviones; i++)
        {
            if (aviones[i].isEmpty == 0)
            {
                listarAvion(aviones[i],aerolineas,cantAerolineas,tipos,cantTipos);
                retorno = 1;
            }
        }
    }
    return retorno;
}

int buscarAvionId(eAvion aviones[],int tamAviones, int idBuscado,int* posEncontrada)
{
    int retorno = 0;
    if (aviones !=  NULL && tamAviones >0 && posEncontrada!= NULL && idBuscado >= 10000)
    {
        for (int i = 0; i < tamAviones; i++)
        {
            if (aviones[i].id == idBuscado)
            {
                *posEncontrada = i;
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

int altaAvion(eAvion aviones[],int maxAviones,eAerolinea aerolineas[],int cantAero, eTipo tipos[],int cantTipos,int* nextIdAvion)
{
    int retorno = 0;
    int posLibre;
    char mensajeAerolinea[]="Seleccione Aerolinea: ";
    char mensajetipo[]="Seleccione Tipo: ";
    char mensajeCapacidad[]="Ingrese capacidad 10 a 30 pasajeros: ";
    char mensajeError[]="ERROR=";
    char confirmaAlta;
    eAvion auxAvion;
    if (aviones!= NULL && tipos != NULL &&  tipos != NULL && nextIdAvion != NULL && maxAviones>0 && cantTipos>0 && cantAero>0)
    {
        if(!buscarIndexLibre(aviones,maxAviones,&posLibre))
        {
            printf("No hay espacio para cargar mas aviones.\n");
        }
        else
        {


            listarAerolinea(aerolineas,cantAero);
            utn_getNumeroInt(&auxAvion.idAerolinea,mensajeAerolinea,mensajeError,1000,1004,INTENTOSINF);

            listarTipos(tipos,cantTipos);
            utn_getNumeroInt(&auxAvion.idTipo,mensajetipo,mensajeError,5000,5004,INTENTOSINF);

            utn_getNumeroInt(&auxAvion.capacidad,mensajeCapacidad,mensajeError,10,30,INTENTOSINF);

            auxAvion.id= *nextIdAvion;
            printf("ID           AEROLINEA      TIPO          CAPACIDAD \n");
            printf("----------------------------------------------------\n");
            listarAvion(auxAvion,aerolineas,cantAero,tipos,cantTipos);
            printf("\n\nConfirma Alta s/n: ");
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
                aviones[posLibre] = auxAvion;
                aviones[posLibre].isEmpty = 0;
                aviones[posLibre].id = *nextIdAvion;
                *nextIdAvion = *nextIdAvion+1;
                retorno = 1;
                printf("Alta Confirmada.\n");
            }
            else
            {
                printf("Se cancelo el alta.\n");
            }

        }


    }
    return retorno;
}
int bajaAvion (eAvion aviones[],int maxAviones,eAerolinea aerolineas[],int cantAero, eTipo tipos[],int cantTipos)
{
    int retorno = 0;
    char mensajeIdAvion[]="Ingrese el id del avion: ";
    char mensajeError[]="Error=";
    int idBuscado;
    int indiceBuscado;
    char confirmaBaja;
    if (aviones!= NULL && tipos != NULL &&  tipos != NULL && maxAviones>0 && cantTipos>0 && cantAero>0)
    {
        if(!listarAviones(aviones,maxAviones,tipos,cantTipos,aerolineas,cantAero) )
        {
            printf("No hay aviones ingresados.\n");
        }
        else
        {
            utn_getNumeroInt(&idBuscado,mensajeIdAvion,mensajeError,10000,9999999,INTENTOSINF);
            if (! buscarAvionId(aviones,maxAviones,idBuscado,&indiceBuscado) )
            {
                printf("No se encontro el Id ingresado.\n");
            }
            else
            {
                printf("ID           AEROLINEA      TIPO       CAPACIDAD \n");
                printf("--------------------------------------------------\n");
                listarAvion(aviones[indiceBuscado],aerolineas,cantAero,tipos,cantTipos);
                printf("Confirma baja? s/n: ");
                fflush(stdin);
                scanf("%c",&confirmaBaja);
                confirmaBaja = tolower(confirmaBaja);
                while (confirmaBaja!= 's' && confirmaBaja!= 'n')
                {

                    printf("ERROR: Confirma baja? S/N: ");
                    fflush(stdin);
                    scanf("%c",&confirmaBaja);
                    confirmaBaja = tolower(confirmaBaja);
                }
                if (confirmaBaja == 's')
                {
                    printf("Baja Exitosa.\n");
                    aviones[indiceBuscado].isEmpty = 1;
                }
                else
                {
                    printf("Baja Cancelada.\n");
                }
            }
            retorno = 1;
        }
    }
    return retorno;
}
int modificarAvion (eAvion aviones[],int maxAviones,eAerolinea aerolineas[],int cantAero, eTipo tipos[],int cantTipos)
{
    int retorno = 0;
    char mensajeIdAvion[]="Ingrese el id del avion: ";
    char mensajetipo[]="Seleccione Tipo: ";
    char mensajeCapacidad[]="Ingrese  nueva capacidad 10 a 30 pasajeros: ";
    char mensajeError[]="Error=";
    int idBuscado;
    int indiceBuscado;
    char continuar = 's';
    int flagConfirmaCambio = 0;
    eAvion auxAvion;
    if (aviones!= NULL && tipos != NULL &&  tipos != NULL && maxAviones>0 && cantTipos>0 && cantAero>0)
    {
        if(!listarAviones(aviones,maxAviones,tipos,cantTipos,aerolineas,cantAero) )
        {
            printf("No Aviones ingresados.\n");
        }
        else
        {
            utn_getNumeroInt(&idBuscado,mensajeIdAvion,mensajeError,10000,9999999,INTENTOSINF);
            if (! buscarAvionId(aviones,maxAviones,idBuscado,&indiceBuscado) )
            {
                printf("No se encontro el Id ingresado.\n");
            }
            else
            {
                auxAvion = aviones[indiceBuscado];
                do
                {
                    system("cls");
                    printf("ID           AEROLINEA      TIPO       CAPACIDAD \n");
                    printf("--------------------------------------------------\n");
                    listarAvion(auxAvion,aerolineas,cantAero,tipos,cantTipos);
                    switch(menuModificacion())
                    {
                    case 1:
                        listarTipos(tipos,cantTipos);
                        utn_getNumeroInt(&auxAvion.idTipo,mensajetipo,mensajeError,5000,5004,INTENTOSINF);
                        break;
                    case 2:
                        utn_getNumeroInt(&auxAvion.capacidad,mensajeCapacidad,mensajeError,10,30,INTENTOSINF);
                        break;
                    case 3:
                        printf("Cambio confirmado.\n");
                        aviones[indiceBuscado]=auxAvion;
                        flagConfirmaCambio = 1;
                        break;
                    case 4:
                        if(!flagConfirmaCambio)
                        {
                            printf("No se guardaron los cambios.\n");
                        }
                        continuar= 'n';
                        break;
                    default:
                        printf("Opcion incorrecta.\n");
                        break;
                    }
                    system("pause");
                }
                while (continuar == 's');
            }
            retorno = 1;
        }
    }
    return retorno;
}
int buscarAvionExistente(eAvion aviones[],int cantAviones,int idAvionBuscado,int* indiceAvionBusc)
{
    int retorno =0;
    if (aviones != NULL && cantAviones >0 && idAvionBuscado >= 10000 && indiceAvionBusc != NULL)
    {
        for (int i = 0; i < cantAviones; i++)
        {
            if(aviones[i].isEmpty == 0 && aviones[i].id == idAvionBuscado)
            {
                *indiceAvionBusc = i;
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}
int menuModificacion()
{
    int opcion;
    printf("*********************************************************\n");
    printf("*                      MODIFICACION                     *\n");
    printf("*********************************************************\n");
    printf("1.MODIFICAR TIPO.\n");
    printf("2.MODIFICAR CAPACIDAD.\n");
    printf("3.CONFIRMAR CAMBIOS\n");
    printf("4.SALIR\n");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

int listarAvionesSegunTipo( eAvion aviones[],int tamAviones,eTipo tipos[],int cantTipos,eAerolinea aerolineas[],int cantAerolineas)
{
    int retorno = 0;
    char mensajeTipo[]="Seleccione tipo.\n";
    char mensajeError[]="Error=";
    int tipoElegido;
    char descTipo[20];
    int cont= 0;
    if (aviones != NULL && tipos != NULL && aerolineas != NULL && cantAerolineas > 0 && cantTipos > 0 && tamAviones >0)
    {
        printf("   * * * A V I O N E S   P O R   T I P O * * *\n\n\n");
        listarTipos(tipos,cantTipos);
        utn_getNumeroInt(&tipoElegido,mensajeTipo,mensajeError,5000,5004,INTENTOSINF);
        cargarDescTipo(tipos,cantTipos,tipoElegido,descTipo);
        printf("ID           AEROLINEA           TIPO      CAPACIDAD \n");
        printf("--------------------------------------------------\n");
        for (int i = 0 ; i < tamAviones; i++)
        {
            if(aviones[i].isEmpty == 0 && aviones[i].idTipo == tipoElegido)
            {
                listarAvion(aviones[i],aerolineas,cantAerolineas,tipos,cantTipos);
                cont ++;
            }
        }
        if (!cont)
        {
            printf("No hay aviones del tipo %s\n",descTipo);
        }
        else
        {
            printf("Se encontraron un total de %d aviones del tipo %s\n",cont,descTipo);
        }
        retorno = 1;
    }
    return retorno;
}
int listarAvionesSegunAerolinea( eAvion aviones[],int tamAviones,eTipo tipos[],int cantTipos,eAerolinea aerolineas[],int cantAerolineas)
{
    int retorno = 0;
    char mensajeAerolinea[]="Seleccione Aerolinea.\n";
    char mensajeError[]="Error=";
    int aerolineaElegida;
    char descAero[20];
    int cont= 0;
    if (aviones != NULL && tipos != NULL && aerolineas != NULL && cantAerolineas > 0 && cantTipos > 0 && tamAviones >0)
    {
        printf("   * * * A V I O N E S   P O R   A E R O L I N E A * * *\n\n\n");
        listarAerolinea(aerolineas,cantAerolineas);
        utn_getNumeroInt(&aerolineaElegida,mensajeAerolinea,mensajeError,1000,1004,INTENTOSINF);
        cargarDescAero(aerolineas,cantAerolineas,aerolineaElegida,descAero);
        printf("ID           AEROLINEA           TIPO      CAPACIDAD \n");
        printf("--------------------------------------------------\n");
        for (int i = 0 ; i < tamAviones; i++)
        {
            if(aviones[i].isEmpty == 0 && aviones[i].idAerolinea == aerolineaElegida)
            {
                listarAvion(aviones[i],aerolineas,cantAerolineas,tipos,cantTipos);
                cont ++;
            }
        }
        if (!cont)
        {
            printf("No hay aviones para la aerolinea %s\n",descAero);
        }
        else
        {
            printf("Se encontraron un total de %d aviones de la aerolinea %s\n",cont,descAero);
        }
        retorno = 1;
    }
    return retorno;
}
int promediarJetSegunAerolinea( eAvion aviones[],int tamAviones,eTipo tipos[],int cantTipos,eAerolinea aerolineas[],int cantAerolineas)
{
    int retorno = 0;
    char mensajeAerolinea[]="Seleccione Aerolinea.\n";
    char mensajeError[]="Error=";
    int aerolineaElegida;
    char descAero[20];
    int contJets = 0;
    int contHelice = 0;
    int contPlaneador = 0;
    int contCarga = 0;
    int total;
    int flagJet= 0;
    float promedioJets;
    if (aviones != NULL && tipos != NULL && aerolineas != NULL && cantAerolineas > 0 && cantTipos > 0 && tamAviones >0)
    {
        printf("   * * * P R O M E D I O     J E T S   P O R   A E R O L I N E A * * *\n\n\n");
        listarAerolinea(aerolineas,cantAerolineas);
        utn_getNumeroInt(&aerolineaElegida,mensajeAerolinea,mensajeError,1000,1004,INTENTOSINF);
        cargarDescAero(aerolineas,cantAerolineas,aerolineaElegida,descAero);
        printf("ID           AEROLINEA           TIPO      CAPACIDAD \n");
        printf("--------------------------------------------------\n");
        for (int i = 0 ; i < tamAviones; i++)
        {
            if(aviones[i].isEmpty == 0 && aviones[i].idAerolinea == aerolineaElegida)
            {
                switch(aviones[i].idTipo)
                {
                case 5000:
                    flagJet = 1;
                    contJets++;
                    break;
                case 5001:
                    contHelice++;
                    break;
                case 5002:
                    contPlaneador++;
                    break;
                case 5003:
                    contCarga++;
                    break;
                }
            }
        }
        if (!flagJet)
        {
            printf("No hay aviones del tipo Jet para la aerolinea %s\n",descAero);
        }
        else
        {
            total = contJets + contHelice + contPlaneador + contCarga;
            promedioJets = (float) contJets / total;
            printf("Para la aerolinea %s se encontro un priomedio %.2f de aviones tipo Jet\n",descAero,promedioJets);
            retorno = 1;
        }

    }
    return retorno;
}
int informarAvionesPorCadaAerolinea(eAvion aviones[],int tamAviones,eTipo tipos[],int cantTipos,eAerolinea aerolineas[],int cantAerolineas)
{
    int retorno = 0;
    char descAero[20];
    int flagIngreso;
    if (aviones != NULL && tipos != NULL && aerolineas != NULL && cantAerolineas > 0 && cantTipos > 0 && tamAviones >0)
    {
        printf("   * * *  LISTADO DE AVIONES POR CADA AEROLINEA * * *\n\n\n");
        for (int a = 0; a < cantAerolineas; a++)
        {
            flagIngreso = 0;
            cargarDescAero(aerolineas,cantAerolineas,aerolineas[a].id,descAero);
            printf("\n\n\nAerolinea %s: \n",descAero);
            printf("ID           AEROLINEA           TIPO      CAPACIDAD \n");
            printf("--------------------------------------------------\n");
            for (int i = 0; i <tamAviones; i++)
            {
                if (aviones[i].isEmpty == 0 && aviones[i].idAerolinea == aerolineas[a].id)
                {
                    listarAvion(aviones[i],aerolineas,cantAerolineas,tipos,cantTipos);
                    flagIngreso = 1;
                }
            }
            if(!flagIngreso)
            {
                printf("No hay aviones para la aerolinea %s.\n",descAero);
            }

        }
        retorno = 1;
    }
    return retorno = 0;

}

int  listarAerolineaConMasCarga (eAvion aviones[],int tamAviones,eTipo tipos[],int cantTipos,eAerolinea aerolineas[],int cantAerolineas)
{
    int retorno = 0;

    int acumLan=0;
    int acumIberia=0;
    int acumNorw=0;
    int acumAmerican=0;
    int acumAustral=0;
    int aerolineaMasCarga;
    int flagIngreso = 0;
    char descAero[20];
    int acumMax;
    if (aviones != NULL && tipos != NULL && aerolineas != NULL && cantAerolineas > 0 && cantTipos > 0 && tamAviones >0)
    {
        printf("   * * * AEROLINEA CON MAS CAPACIDAD * * *\n\n\n");

        printf("ID           AEROLINEA           TIPO      CAPACIDAD \n");
        printf("--------------------------------------------------\n");
        for (int i = 0; i < tamAviones; i++)
        {
            if (aviones[i].isEmpty == 0)
            {
                switch(aviones[i].idAerolinea)
                {
                case 1000:
                    acumLan = acumLan + aviones[i].capacidad;
                    flagIngreso =1;
                    break;
                case 1001:
                    acumIberia = acumIberia + aviones[i].capacidad;
                    flagIngreso =1;
                    break;
                case 1002:
                   acumNorw = acumNorw  + aviones[i].capacidad;
                   flagIngreso =1;
                    break;
                case 1003:
                   acumAmerican = acumAmerican + aviones[i].capacidad;
                   flagIngreso =1;
                    break;
                case 1004:
                    acumAustral = acumAustral + aviones[i].capacidad;
                    flagIngreso =1;
                    break;

                }
            }

        }
        if (acumLan > acumIberia && acumLan > acumNorw && acumLan > acumAmerican && acumLan > acumAustral)
        {
            aerolineaMasCarga = 1000;
            acumMax = acumLan;
        }
        else
        {
            if (acumIberia >  acumNorw && acumIberia > acumAmerican && acumIberia > acumAustral)
            {
                aerolineaMasCarga = 1001;
                acumMax = acumIberia;
            }
            else
            {
                if (acumNorw > acumAmerican && acumNorw > acumAustral)
                {
                    aerolineaMasCarga = 1002;
                    acumMax = acumNorw;
                }
                else
                {
                    if (acumAmerican > acumAustral)
                    {
                        aerolineaMasCarga = 1003;
                        acumMax = acumAmerican;
                    }
                    else
                    {
                        aerolineaMasCarga = 1004;
                        acumMax = acumAustral;
                    }

                }
            }
        }
        if (!flagIngreso)
        {
            printf("No hay aviones ingresados.\n");
        }
        else
        {
            cargarDescAero (aerolineas,cantAerolineas,aerolineaMasCarga,descAero);
            printf("La aerolinea con mas carga es %s con un capacidad total de %d\n",descAero,acumMax);
        }

    }
    return retorno;
}
int  listarAerolineaConMenosAviones (eAvion aviones[],int tamAviones,eTipo tipos[],int cantTipos,eAerolinea aerolineas[],int cantAerolineas)
{
    int retorno = 0;

    int contLan=0;
    int contIberia=0;
    int contNorw=0;
    int contAmerican=0;
    int contAustral=0;
    int aerolineaMenosAviones;
    int flagIngreso = 0;
    char descAero[20];
    int contMax;
    if (aviones != NULL && tipos != NULL && aerolineas != NULL && cantAerolineas > 0 && cantTipos > 0 && tamAviones >0)
    {
        printf("   * * * AEROLINEA CON MAS CAPACIDAD * * *\n\n\n");

        printf("ID           AEROLINEA           TIPO      CAPACIDAD \n");
        printf("--------------------------------------------------\n");
        for (int i = 0; i < tamAviones; i++)
        {
            if (aviones[i].isEmpty == 0)
            {
                switch(aviones[i].idAerolinea)
                {
                case 1000:
                    contLan++;
                    flagIngreso =1;
                    break;
                case 1001:
                    contIberia++;
                    flagIngreso =1;
                    break;
                case 1002:
                   contNorw ++;
                   flagIngreso =1;
                    break;
                case 1003:
                   contAmerican++;
                   flagIngreso =1;
                    break;
                case 1004:
                    contAustral++;
                    flagIngreso =1;
                    break;

                }
            }

        }
        if (contLan < contIberia && contLan < contNorw && contLan < contAmerican && contLan < contAustral)
        {
            aerolineaMenosAviones = 1000;
            contMax = contLan;
        }
        else
        {
            if (contIberia <  contNorw && contIberia < contAmerican && contIberia < contAustral)
            {
                aerolineaMenosAviones = 1001;
                contMax = contIberia;
            }
            else
            {
                if (contNorw < contAmerican && contNorw < contAustral)
                {
                    aerolineaMenosAviones = 1002;
                    contMax = contNorw;
                }
                else
                {
                    if (contAmerican < contAustral)
                    {
                        aerolineaMenosAviones = 1003;
                        contMax = contAmerican;
                    }
                    else
                    {
                        aerolineaMenosAviones = 1004;
                        contMax = contAustral;
                    }

                }
            }
        }
        if (!flagIngreso)
        {
            printf("No hay aviones ingresados.\n");
        }
        else
        {
            cargarDescAero (aerolineas,cantAerolineas,aerolineaMenosAviones,descAero);
            printf("La aerolinea con menos aviones es %s con un total de %d\n",descAero,contMax);
        }

    }
    return retorno;
}
