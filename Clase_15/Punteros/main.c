#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vec[5], i = 0;
    int* ptr;
    char cad[10];
    char* ptrcad;

    ptr = vec;
    ptrcad = cad;

    for(i=0; i<5; i++){
        vec[i] = i+3;
        printf("%d\n", vec[i]);
    }

    printf("\n");

    for(i=0; i<5; i++){
        *(ptr+i) = i+5;
        printf("%d\n", *(ptr+i));
    }

    printf("Ingrese dato: ");
    fflush(stdin);
    scanf("%s\n", ptrcad);    //scanf("%s", &cad);

    printf("Ingresaste: %s", ptrcad); //revisar

    return 0;
}
