#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT 5
int main()
{
    int legajo[CANT], i, cantidad;
    float salario[CANT];
    char nombre[CANT][31];

    for(i = 0; i < CANT; i++)
    {

        printf("Legajo:");
        scanf("%d", &legajo[i]);
        printf("Salario: ");
        scanf("%f", &salario[i]);
        fgets(nombre[i], sizeof(nombre[i]) - 2, stdin);
        cantidad = strlen(nombre[i]);
        nombre[cantidad - 1] = "\0";

    }

    printf("legajo\t nombre\t\tsalario\n\n");

    for(i = 0; i < CANT; i++)
    {

        printf("%d\t%s\t\t%.2f\n", legajo[i], nombre[i], salario[i]);

    }

    return 0;

}
