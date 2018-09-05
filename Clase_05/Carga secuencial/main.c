#include <stdio.h>
#define MAX 100

void main(void)
{
    int edad[MAX],i;
    float sueldo[MAX],suma=0,prom,aux;
    for(i=0;i<MAX;i++)
    {
        printf("Ingrese la edad del legajo %d: ",i+1);
        scanf("%d",&edad[i]);
        printf("Ingrese el sueldo del legajo %d: ",i+1);
        scanf("%f",&aux);
        sueldo[i]=aux;
    }

    for(i=0;i<MAX;i++)
        suma=suma+sueldo[i];

    prom=suma/MAX;
    printf("El sueldo promedio es %.2f",prom);

}
