#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pendrive.h"

int main()
{
    ePendrive pendrive;

    if((cargarPendrive(&pendrive) == 1)){
       mostrarPendrive(&pendrive);
       }

    return 0;
}

int cargarPendrive(ePendrive* pendrive)
{
    int todoOk = 0;
    int codigo;
    char marca[20];
    int capacidad;
    float precio;

    if(pendrive != NULL){
        printf("Ingrese codigo: ");
        scanf("%d", &codigo);

        printf("Ingrese marca: ");
        fflush(stdin);
        gets(marca);

        printf("Ingrese capacidad: ");
        scanf("%d", &capacidad);

        printf("Ingrese precio: ");
        scanf("%f", &precio);

        todoOk = 1;
    }

    cargarPendriveParam(pendrive, codigo, marca, capacidad, precio);

    return todoOk;
}

int cargarPendriveParam(ePendrive* pendrive, int codigo, char marca[], int cap, float precio){

    int todoOk = 0;

    if(pendrive != NULL){
        pendrive->codigo = codigo;
        strcpy(pendrive->marca, marca);
        pendrive->capacidad = cap;
        pendrive->precio = precio;

        todoOk = 1;
    }

    return todoOk;
}

void mostrarPendrive(ePendrive* pendrive){
    printf("%d  %s  %d  %.2f", pendrive->codigo, pendrive->marca, pendrive->capacidad, pendrive->precio);
}
