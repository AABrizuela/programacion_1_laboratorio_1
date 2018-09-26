#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
    int isEmpty;
}eFecha;

typedef struct
{
    char nombre[31];
    char sexo;
    int legajo;
    float sueldo;
    int idSector;
    int isEmpty;
}eEmpleado;

typedef struct
{
    int id;
    char descripcion[31];
    int isEmpty;
}eSector;

typedef struct
{
    int id;
    char descripcion[31];
    int isEmpty;
}eMenu;

typedef struct
{
    int idEmpleado;
    int idMenu;
    int isEmpty;
}eEmpleadoMenu;

int main()
{
    int opcion;
    do{
        system("cls");
        printf("Bienvenido al ABM.\n");
        printf("Seleccione Menu.\n\n");
        printf("1.- Empleados.\n");
        printf("2.- Sectores.\n");
        printf("3.- Menu.\n");
        printf("4.- Salir.\n");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                //menuAltas();
                break;
            case 2:

                break;

        }

    }while(opcion!=10);

    return 0;
}
