//bibliotecas
#include <stdio.h>
#include <stdlib.h>

//prototipos
int suma();
int resta();
int division();
int multiplicacion();
int factorial();

//funciones
int main()
{
    int opcion;
    float op1 = 0, op2 = 0;

    do{

        printf("Menu");
        printf("\n\n1. Ingresar primer operando(A= %.0f)", op1);
        printf("\n\n2. Ingresar segundo operando(A= %.0f)", op2);


        printf("\n\nSeleccione opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:

                break;

            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            case 5:

                break;

            default:
                printf("Opcion incorrecta.");
                break;
        }

    }while(opcion != 5);

    return 0;

}

int suma()
{
    int opSuma1;
    int opSuma2;
    int resultadoSuma;


}

int resta()
{
    int opResta1;
    int opResta2;
    int resultadoResta;


}

int division()
{
    float opDividendo;
    float opDivisor;
    float resultadoDivision;


}

int multiplicacion()
{
    int opMultiplicacion1;
    int opMultiplicacion2;
    int resultadoMultiplicacion;


}

int factorial()
{
    float opFactoreo1;
    float opFactoreo2;
    float resultadoMultiplicacion;


}
