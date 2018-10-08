#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "negocio.h"
#include "comida.h"
#include "menuPrincipal.h"

int main()
{
	eEmpleado listaEmpleados[LEN];
	eComida listaComida[LEN_COMIDA];

	inicializarEmpleados(listaEmpleados, LEN);
	inicializarComida(listaComida, LEN_COMIDA);

	menuPrincipal(listaEmpleados, LEN, listaComida, LEN_COMIDA);

	return 0;
}
