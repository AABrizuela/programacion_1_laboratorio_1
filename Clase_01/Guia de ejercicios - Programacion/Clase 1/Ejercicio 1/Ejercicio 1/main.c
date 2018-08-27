#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numero;
    int contador;
    int promedio;
    int acumuladorNumeros;

    acumuladorNumeros = 0;

    for (contador = 0; contador < 5; contador++)
    {

        numero = scanf("Ingrese un numero %d", &numero);
        acumuladorNumeros = (float) acumuladorNumeros + numero;

    }

    promedio = (float) acumuladorNumeros / contador;

    printf("El promedio de los numeros ingresados es: %d", promedio);

    return 0;
}
