#include <stdio.h>
#include <stdlib.h>

int suma(int, int); //prototipo, declaracion.

int main()
{

    int nro1, nro2, result;

    printf("Ingrese primer operando: ");
    scanf("%d", &nro1);
    printf("\n Ingrese segundo operando: ");
    scanf("%d", &nro2);

    result = suma(nro1, nro2); //Llamada de funcion.
    system("cls"); //o "clear" para linux.
    printf("Resultado: %d", result);

    return 0;
}

int suma(int op1, int op2)
{

    int resultado;
    resultado = op1 + op2;
    return resultado;

}
