#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

void empeladoMenu()
{
    int opcionSubMenu;
    eEmpleado listaEmpleados[LEN];
    eSector listaSector[SECTORLEN] = {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Sistemas"},
        {4, "Contable"},
        {5, "Administrativo"}};

    /*llamar initEmpleados*/
    inicializarEmpleados(listaEmpleados, LEN);

    do
    {
        system("cls");
        printf("*** Menu de Empleado ***\n\n");

        printf("1.- Alta.\n");
        printf("2.- Baja.\n");
        printf("3.- Modificacion.\n");
        printf("4.- Listar.\n");
        printf("5.- Volver.\n\n");

        printf("Elija opcion: ");
        scanf("%d", &opcionSubMenu);
        fflush(stdin);
        printf("\n");

        switch(opcionSubMenu)
        {
            case 1:
                agregarEmpleado(listaEmpleados, LEN, listaSector, SECTORLEN);
                break;

            case 2:
                eliminarEmpleado(listaEmpleados, LEN, listaSector, SECTORLEN);
                break;

            case 3:
                printf("Estamos trabajando para usted.");
                break;

            case 4:
                mostrarEmpleados(listaEmpleados, LEN, listaSector, SECTORLEN);
                system("pause");
                break;

            case 5:
                break;

            default:
                printf("No es una opcion valida. ");
                system("pause");
                break;
        }
    }while(opcionSubMenu!=5);
}

void inicializarEmpleados( eEmpleado x[], int tam)
{
    int i=0;

    for(i=0; i < tam; i++)
    {
        x[i].isEmpty = 0;
    }
}

int buscarLibre( eEmpleado x[], int tam)
{
    int indice = -1, i=0;

    for(i=0; i < tam; i++)
    {

        if( x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado x[], int tam, int legajo)
{
    int indice=-1, i=0;

    for(i=0; i < tam; i++)
    {


        if( x[i].legajo == legajo && x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]){
    int i=0;

    for(i=0; i < tamSector; i++){
        if( sectores[i].id == idSector){

            strcpy(cadena, sectores[i].descripcion);
            break;
        }
    }
}

int elegirSector(eSector sectores[], int tam){
    int idSector, i=0;
    printf("\nSectores\n\n");
    for(i=0; i < tam; i++){
        printf("%d %s\n", sectores[i].id, sectores[i].descripcion);
    }
    printf("\nSeleccione sector: ");
    scanf("%d", &idSector);

    return idSector;
}

void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{
    eEmpleado nuevoEmpleado;
    int indice;
    int esta;
    int legajo;

    indice = buscarLibre(empleados, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(empleados, tam, legajo);

        if(esta != -1)
        {
            printf("Existe un empleado con el legajo %d\n", legajo);
            mostrarEmpleado( empleados[esta], sectores, SECTORLEN);
        }
        else{
            nuevoEmpleado.legajo = legajo;

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(nuevoEmpleado.apellido);

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);

            printf("Ingrese sueldo: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.sueldo);

            nuevoEmpleado.idSector = elegirSector(sectores, 5);

            nuevoEmpleado.isEmpty = 1;

            empleados[indice] = nuevoEmpleado;
        }
    }
}

void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector)
{
    char descripcion[20];

    cargarDescripcion(sectores, tamSector, emp.idSector, descripcion);

    printf("%d %s %s %c %.2f %s \n\n", emp.legajo, emp.apellido, emp.nombre, emp.sexo, emp.sueldo, descripcion);

}

void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector)
{
    int i;
    for(i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == 1)
        {
            mostrarEmpleado(nomina[i], sectores, tamSector);
        }
    }
}

void eliminarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector){

int legajo;
int indice;
char borrar;
eEmpleado emp;

printf("Ingrese legajo: ");
scanf("%d", &legajo);

indice = buscarEmpleado(empleados, tam, legajo);

if( indice == -1){
    printf("No hay ningun empleado con el legajo %d\n", legajo);
}
else{
    emp = empleados[indice];
    mostrarEmpleado(emp, sectores, tamSector);

    printf("\nConfirma borrado?: ");
    fflush(stdin);
    scanf("%c", &borrar);
    if(borrar != 's'){
        printf("Borrado cancelado\n\n");
    }
    else{
        empleados[indice].isEmpty = 0;
        printf("Se ha eliminado el empleado\n\n");
    }
    system("pause");
}

}
