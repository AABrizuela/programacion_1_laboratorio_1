#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* p;
    int i;
    p = (int*) malloc(sizeof(int));

    if(p == NULL)
    {
        printf("No se consiguio memoria.\n");
        exit(1);
    }

    for(i = 0; i < 11; i++){
        *p = i;
        printf("%d\n", *p);
    }

    free(p);

    return 0;
}
