#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*una forma de declarar una estructura
struct empleado
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
};*/

//otra forma de declarar una estructura.
//se declara un nuevo tipo de dato que es una estructura

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
}eEmpleado;

void mostrarEmpleado(eEmpleado employee);

int main()
{
    //struct empleado unEmpleado;

    eEmpleado unEmpleado;
    eEmpleado otroEmpleado;
    eEmpleado emp3 = {2222, "Jose", 'm', 20000};
    eEmpleado emp4 = emp3;
    eEmpleado emp5;

    unEmpleado.legajo = 1234;
    strcpy(unEmpleado.nombre, "Juan");
    unEmpleado.sexo = 'm';
    unEmpleado.sueldo = 10000.5;

    otroEmpleado.legajo = 1122;
    strcpy(otroEmpleado.nombre, "Lucia");
    otroEmpleado.sexo = 'f';
    otroEmpleado.sueldo = 15000.75;
    //FICHA.CAMPO

    printf("Ingrese los datos del empleado.\n");
    printf("Legajo: ");
    scanf("%d", &emp5.legajo);
    printf("\nNombre: ");
    fflush(stdin);
    gets(emp5.nombre);
    printf("\nSexo: ");
    fflush(stdin);
    scanf("%c", &emp5.sexo);
    printf("\nSueldo: ");
    scanf("%f", &emp5.sueldo);

    mostrarEmpleado(unEmpleado);
    mostrarEmpleado(otroEmpleado);
    mostrarEmpleado(emp3);
    mostrarEmpleado(emp4);
    mostrarEmpleado(emp5);

    return 0;
}

void mostrarEmpleado(eEmpleado employee)
{
    printf("%d\t%s\t%c\t%.2f\n\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo);
}
