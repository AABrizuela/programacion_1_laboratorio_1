#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).");
    printf("3. Alta de empleado");
    printf("4. Modificar datos de empleado");
    printf("5. Baja de empleado");
    printf("6. Listar empleados");
    printf("7. Ordenar empleados");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).");
    printf("10. Salir");

    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("data.csv", listaEmpleados);
                break;
            case 3:
                employee_new();
                break;

        }
    }while(option != 10);
    return 0;
}
