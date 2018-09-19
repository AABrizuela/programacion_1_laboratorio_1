#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "persona.h"



void init(EPersona lista[], int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        lista[i].isEmpty = 1;
    }
}

int obtenerEspacioLibre(EPersona lista[], int len)
{
    int i;
    int retorno = -1;

    for(i=0; i<len; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


void alta(EPersona lista[], int len)
{
    int index;

    index = obtenerEspacioLibre(lista, len);

    if(index != -1)
    {
        printf("Apellido: ");
        fflush(stdin);
        gets(lista[index].apellido);

        printf("\nNombre: ");
        fflush(stdin);
        gets(lista[index].nombre);

        printf("\nDNI: ");
        scanf("%ld", &lista[index].dni);

        printf("\nFecha de nacimiento: ");
        printf("\nDia: ");
        scanf("%d", &lista[index].feNac.dia);
        printf("\nMes: ");
        scanf("%d", &lista[index].feNac.mes);
        printf("\nAño: ");
        scanf("%d", &lista[index].feNac.anio);

        lista[index].isEmpty = 0;
    }
    else
    {
        //no hay espacio libre
    }
    return;
}

void ordenar(EPersona lista[], int len)
{
    EPersona auxPersona;
    int i, j;

    for(i=0; i < len-1; i++)
    {
        for(j= i+1; j < len; j++)
        {
            if(strcmp(lista[i].apellido, lista[j].apellido) >0 )
            {
                auxPersona = lista[i];
                lista[i] = lista[j];
                lista[j] = auxPersona;
            }
            else if(strcmp(lista[i].apellido, lista[j].apellido) ==0 && strcmp(lista[i].nombre, lista[j].nombre) > 0)
            {
                auxPersona = lista[i];
                lista[i] = lista[j];
                lista[j] = auxPersona;
            }
        }
    }
}

void mostrar(EPersona lista[], int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(lista[i].isEmpty==0)
        {
            printf("%s %s\t%ld\t%d/%d/%d\n\n", lista[i].apellido, lista[i].nombre, lista[i].dni, lista[i].feNac.dia, lista[i].feNac.mes, lista[i].feNac.anio);
        }
    }

}

int eliminar(EPersona lista[], int len)
{
    int i;
    int retorno = -1;

    for(i=0; i<len; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
void modificar(EPersona lista[], int len)
{
    int opcionModificar = 0;
    int i, index;
    long int auxiliarDni;

    index = lista[index].dni;

    printf("Ingrese DNI de la persona a MODIFICAR.");
    scanf("%ld", &auxiliarDni);

    //index = buscarPorDni(van los parametros);
    for(i=0; i<len; i++)
    {
        //if(encontrado != -1)
        if(auxiliarDni == index)
        {
            printf("%s %s\t%ld\t%d/%d/%d\n\n", lista[index].apellido, lista[index].nombre, lista[index].dni, lista[index].feNac.dia, lista[index].feNac.mes, lista[index].feNac.anio);

            do
            {
                printf("Desea MODIFICAR este elemento S|N?");
                fflush(stdin);
                scanf("%c", &rta);
                rta = tolower(rta);
            }
            while(rta != 'n' && rta != 's');

            if(rta == 's')
            {
                do
                {
                    printf("1- Modificar APELLIDO.\n");
                    printf("2- Modificar NOMBRE\n");
                    printf("3- Modificar DNI\n");
                    printf("4- Modificar FECHA DE NACIMIENTO\n\n");
                    printf("5- Volver\n");

                    switch(opcionModificar)
                    {
                    case 1:
                        printf("Ingrese nuevo apellido: ");
                        gets(lista[i].apellido);
                        printf("APELLIDO MODIFICADO.");
                        break;

                    case 2:
                        printf("Ingrese nuevo nombre: ");
                        gets(lista[i].nombre);
                        printf("NOMBRE MODIFICADO.");
                        break;

                    case 3:
                        printf("Ingrese nuevo dni: ");
                        scanf("%ld", &lista[i].dni);
                        printf("DNI MODIFICADO.");
                        break;

                    case 4:
                        printf("\nFecha de nacimiento: ");
                        printf("\nDia: ");
                        scanf("%d", &lista[index].feNac.dia);
                        printf("\nMes: ");
                        scanf("%d", &lista[index].feNac.mes);
                        printf("\nAño: ");
                        scanf("%d", &lista[index].feNac.anio);
                        printf("FECHA DE NACIMIENTO MODIFICADA.");
                        break;

                    case 5:
                        //volver al menu anterior
                        break;
                    default:
                        printf("Opcion incorrecta...");
                    }
                }
                while(opcionModificar!=5);
            }
            else{
                printf("No se modificaron los datos...");
            }

        }
        else{
            printf("Dato inexistente...")
        }
    }
}
