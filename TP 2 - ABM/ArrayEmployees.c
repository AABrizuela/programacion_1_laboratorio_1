#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"
#include "utn.h"

void menu()
{

	int optionMainMenu;
	eEmployee employeeList[EMPLOYEES];

	do
	{
		system("cls");
		printf("*** Bienvenido al ABM ***\n\n");

		printf("1.- Alta de empleado.\n");
		printf("2.- Modificar empleado.\n");
		printf("3.- Baja de empleado.\n");
		printf("4.- Informes.\n");
		printf("5.- Salir.\n\n");

		printf("Ingrese opcion: ");
		scanf("%d", &optionMainMenu);
		printf("\n");

		//initEmployees(employeeList, LENGTH);

		switch(optionMainMenu)
		{
			case 1:
				addEmployee(employeeList, LENGTH);
				system("pause");
				break;

			case 2:
				//editEmployee(employeeList, LENGTH);
				//system("pause");
				break;

			case 3:
				removeEmployee(employeeList, LENGTH);
				system("pause");
				break;

			case 4:
				subMenu(employeeList, LENGTH);
				break;

			case 5:
				printf("Gracias por usar el ABM.\n");
				break;
		}
	}while(optionMainMenu !=5);
}

void subMenu(eEmployee employeeList[], int len)
{
	int optionSubMenu;

	do
	{
		system("cls");
		printf("1.- Listar empleados ordenados alfabeticamente por Apellido y Sector.\n");
		printf("2.- Total y promedio de salarios, y cuantos empleados superan el promedio.\n");
		printf("3.- Volver.\n\n");

		printf("Ingrese opcion: ");
		scanf("%d", &optionSubMenu);

		switch(optionSubMenu)
		{
			case 1:
				sortByAlphaAndSector(employeeList, len);
				printEmployees(employeeList, len);
				system("pause");
				break;
			case 2:
				break;
			case 3:
				break;
		}
	}while(optionSubMenu != 3);
}

void initEmployees(eEmployee employeeList[], int len)
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
	eEmployee newEmployee;
	int index;

	index = getFreeSpot(employeeList, len);

	if(index == -1)
	{
		printf("No hay lugar.\n");
		return;
	}else{
	printf("Ingrese nombre: ");
	fflush(stdin);
	gets(newEmployee.name);

	printf("Ingrese apellido: ");
	fflush(stdin);
	gets(newEmployee.lastName);

	printf("Ingrese salario: ");
	scanf("%f", &newEmployee.salary);

	printf("Ingrese sector: ");
	fflush(stdin);
	scanf("%d", &newEmployee.sector);

	newEmployee.id = index + 1;
	}
}

void removeEmployee(eEmployee employeeList[], int len)
{
	int id;
	int index;
	char deleteEmployee;
	eEmployee employee;

	printf("Ingrese legajo: ");
	scanf("%d", &id);

	index = findEmployeeById(employeeList, len, id);

	if( index == -1){
	    printf("No hay ningun empleado con el legajo %d\n", id);
	}
	else{
		employee = employeeList[index];
		printEmployee(employee, len);

		printf("\nConfirma borrado?: ");
		fflush(stdin);
		scanf("%c", &deleteEmployee);
		if(deleteEmployee != 's'){
			printf("Borrado cancelado\n\n");
		}
		else{
			employeeList[index].isEmpty = 0;
			printf("Se ha eliminado el empleado\n\n");
		}
		system("pause");
	}
}

void sortByAlphaAndSector(eEmployee employeeList[], int len)
{
	eEmployee auxEmp;
	int i, j;

	if(employeeList!=NULL && len > 0)
	{
		for(i=0; i < len; i++)
		{
			for(j=0; j < len; j++)
			{
				if(strcmp(employeeList[j].lastName, employeeList[i].lastName) < 0)
                        {
                            auxEmp = employeeList[i];
                            employeeList[i] = employeeList[j];
                            employeeList[j] = auxEmp;
                        }
                        else if(strcmp(employeeList[j].lastName, employeeList[i].lastName) == 0 && employeeList[j].sector < employeeList[i].sector)
                        {
                            auxEmp = employeeList[i];
                            employeeList[i] = employeeList[j];
                            employeeList[j] = auxEmp;
                        }
			}
		}
	}
}

void printEmployee(eEmployee employee, int len)
{
	printf("%d %s %s %.2f %d", employee.id, employee.lastName, employee.name, employee.salary, employee.sector);
}

void printEmployees(eEmployee employeeList[], int len)
{
	int i;

	for(i=0; i< len; i++)
	{
		if(employeeList[i].isEmpty == 1)
		{
			printEmployee(employeeList[i], len);
		}
	}
	printf("Deberia haber mostrado algo");
}

int findEmployeeById(eEmployee employeeList[], int len, int id)
{
    int index=-1, i=0;

    for(i=0; i < len; i++)
    {
        if( employeeList[i].id == id && employeeList[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}
