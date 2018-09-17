#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT 500

typedef struct
{
    int legajo;
    char nombre[50];
    char sexo;
    float sueldo;
}eEmpleado;

void mostrarEmpleado(eEmpleado employee);
void mostrarEmpleados(eEmpleado lista[], int tam);
void ordenarEmpleados(eEmpleado lista[], int tam);

int main()
{
    eEmpleado empleados[]={
        {1234, "Juan", 'm', 12300},
        {2321, "Luisa", 'f', 14700},
        {2122, "Ariel", 'm', 11300},
        {3423, "Laura", 'f', 15600},
        {6753, "Hugo", 'm', 10800}
        };
    //int i = 0;

    /*for(i=0; i<CANT; i++)
    {

        printf("Ingrese los datos del empleado.\n");

        printf("Legajo: ");
        scanf("%d", &empleados[i].legajo);

        printf("\nNombre: ");
        fflush(stdin);
        gets(empleados[i].nombre);

        printf("\nSexo: ");
        fflush(stdin);
        scanf("%c", &empleados[i].sexo);

        printf("\nSueldo: ");
        scanf("%f", &empleados[i].sueldo);

    }*/

    mostrarEmpleados(empleados, 5);

    return 0;
}

void mostrarEmpleado(eEmpleado employee)
{
    printf("%d\t%s\t%c\t%.2f\n\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo);
}

void mostrarEmpleados(eEmpleado lista[], int tam)
{
    system("cls");
    printf(" Legajo\tNombre\tSexo\tSueldo\n\n");
    for(int i=0; i<tam; i++)
    {
        mostrarEmpleado(lista[i]);
    }
}

void ordenarEmpleados(eEmpleado lista[], int tam)
{
    eEmpleado auxEmpleado;

    for(int i=0; i < tam-1; i++)
    {
        for(int j= i+1; j < tam; i++)
        {
            if(lista[i].sexo > lista[j].sexo)
            {
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;
            }else if(lista[i].sexo == lista[j].sexo && strcmp(lista[i].nombre, lista[j].nombre) < 0)
            {
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;
            }
        }
    }


}
