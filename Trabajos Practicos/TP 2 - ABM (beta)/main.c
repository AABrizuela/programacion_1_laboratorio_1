#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"
#define EMPLOYEES 3


int main()
{
    int optionMainMenu;

    eEmployee employeeList[EMPLOYEES];

    initEmployees(employeeList, EMPLOYEES);

    optionMainMenu = menu();



        switch(optionMainMenu)
		{
			case 1:
			    addEmployee(employeeList, EMPLOYEES);
			    system("pause");
				break;

			case 2:
				break;

			case 3:
				break;

			case 4:
				subMenu();
				break;

			case 5:
				break;
		}




    return 0;
}
