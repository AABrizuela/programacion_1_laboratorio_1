#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    int codigo, estado;

    printf("Ingrese codigo ");
    scanf("&i", &codigo);

    estado = utn_getNumero(&codigo, "Ingrese codigo:", "Error, codigo incorrecto", 1, 10000, 3);

    return 0;
}
