#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "comida.h"
#include "almuerzo.h"
//#include "utn.h"

int main()
{
    int optionMainMenu=0;

    do
    {
        system("cls");
        printf("*** Bienvenido al ABM ***\n\n");
        printf("Menu principal.\n\n");

        printf("1.- Empleado.\n");
        printf("2.- Menu comida.\n");
        printf("3.- Almuerzos.\n");
        printf("4.- Salir.\n\n");

        printf("Elija opcion: ");
        scanf("%d", &optionMainMenu);
        fflush(stdin);
        printf("\n");

        switch(optionMainMenu)
        {
            case 1:
                empeladoMenu();
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                printf("Gracias por usar el ABM.\n");
                return 0;
                break;

            default:
                printf("No es una opcion valida. ");
                system("pause");
                break;
        }
    }while(optionMainMenu!=4);

    return 0;
}
