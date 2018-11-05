#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"

int menu()
{

	int optionMainMenu=0;




		system("cls");
		printf("1.- Alta de empleado.\n");
		printf("2.- Modificar empleado.\n");
		printf("3.- Baja de empleado.\n");
		printf("4.- Informes.\n");
		printf("5.- Salir.\n\n");

		printf("Ingrese opcion: ");
		scanf("%d", &optionMainMenu);

		return optionMainMenu;

}

void subMenu()
{
	int optionSubMenu=0;

	do
	{
		system("cls");
		printf("1.- Listar empleados ordenados alfabeticamente por Apellido y Sector. (Asc.)\n");
		printf("2.- Listar empleados ordenados alfabeticamente por Apellido y Sector. (Desc.)\n");
		printf("3.- Total y promedio de salarios, y cuantos empleados superan el promedio.\n");
		printf("4.- Volver.\n\n");

		printf("Ingrese opcion: ");
		scanf("%d", &optionSubMenu);

		switch(optionSubMenu)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
		}
	}while(optionSubMenu != 4);
}

void initEmployees( eEmployee employeeList[], int len)
{
    int i=0;

    for(i=0; i < len; i++)
    {
        employeeList[i].isEmpty = 0;
    }
}

int getFreeSpot(eEmployee employeeList[], int len)
{
    int index = -1, i=0;

    for(i=0; i<len; i++)
    {

        if( employeeList[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

void addEmployee(eEmployee employeeList[], int len)
{

	int index;

	index = getFreeSpot(employeeList, len);

	if(index == -1)
	{
		printf("No hay lugar.\n");
		return;
	}
    else
    {
        system("cls");
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(employeeList[index].name);

        printf("Ingrese apellido:\n ");
        fflush(stdin);
        gets(employeeList[index].lastName);

        // ETC

        employeeList[index].isEmpty = -1;
        employeeList[index].id = index;
    }
}
