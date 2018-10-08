#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "negocio.h"
#include "comida.h"
#include "menuPrincipal.h"
#include "utn.h"

void menuPrincipal(eEmpleado listaEmpleados[], int len, eComida listaComida[], int lenComida)
{
	int optionMainMenu = 0;

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
				empleadoMenu(listaEmpleados, len);
				break;

			case 2:
				comidaMenu(listaComida, len);
				break;

			case 3:
				break;

			case 4:
				printf("Gracias por usar el ABM.\n");
				break;

			default:
				printf("No es una opcion valida. ");
				system("pause");
				break;
		}
	}while(optionMainMenu!=4);

}

void empleadoMenu(eEmpleado listaEmpleados[], int len)
{
    int opcionSubMenu;
    eSector listaSector[SECTORLEN] = {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Sistemas"},
        {4, "Contable"},
        {5, "Administrativo"}};

    do
    {
        system("cls");
        printf("*** Menu de Empleado ***\n\n");

        printf("1.- Alta.\n");
        printf("2.- Baja.\n");
        printf("3.- Modificacion.\n");
        printf("4.- Listar.\n");
        printf("5.- Volver.\n\n");

        printf("Elija opcion: ");
        scanf("%d", &opcionSubMenu);
        fflush(stdin);
        printf("\n");

        switch(opcionSubMenu)
        {
            case 1:
                agregarEmpleado(listaEmpleados, LEN, listaSector, SECTORLEN);
                break;

            case 2:
                eliminarEmpleado(listaEmpleados, LEN, listaSector, SECTORLEN);
                break;

            case 3:
                modificarEmpleado(listaEmpleados, LEN, listaSector, SECTORLEN);
                break;

            case 4:
                mostrarEmpleados(listaEmpleados, LEN, listaSector, SECTORLEN);
                system("pause");
                break;

            case 5:
                break;

            default:
                printf("No es una opcion valida. ");
                system("pause");
                break;
        }
    }while(opcionSubMenu!=5);
}

void inicializarEmpleados(eEmpleado listaEmpleados[], int tam)
{
	int i=0;

	for(i=0; i < tam; i++)
	{
		listaEmpleados[i].isEmpty = 1;
	}
}

int buscarLibre(eEmpleado listaEmpleados[], int tam)
{
    int indice = -1, i=0;

    for(i=0; i < tam; i++)
    {

        if( listaEmpleados[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado listaEmpleados[], int tam, int legajo)
{
    int indice=-1, i=0;

    for(i=0; i < tam; i++)
    {
        if( listaEmpleados[i].legajo == legajo && listaEmpleados[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[])
{
    int i=0;

    for(i=0; i < tamSector; i++){
        if( sectores[i].id == idSector){

            strcpy(cadena, sectores[i].descripcion);
            break;
        }
    }
}

int elegirSector(eSector sectores[], int tam)
{
	int idSector, i=0;

	printf("\nSectores\n\n");

	for(i=0; i < tam; i++)
	{
		printf("%d %s\n", sectores[i].id, sectores[i].descripcion);
	}

	idSector = getValidInt("Seleccione sector: ", "Error, ingrese un valor numerico.", 1, 5);

	return idSector;
}

void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{
	eEmpleado nuevoEmpleado;
	int indice;
	int esta;
	int legajo;

	indice = buscarLibre(empleados, tam);

	if(indice == -1)
	{
		printf("No hay lugar\n\n");
		system("pause");
	}
	else
	{
		printf("Ingrese legajo: ");
		scanf("%d", &legajo);

		esta = buscarEmpleado(empleados, tam, legajo);

		if(esta != -1)
		{
			printf("Existe un empleado con el legajo %d\n", legajo);
			mostrarEmpleado( empleados[esta], sectores, SECTORLEN);
		}
		else{
			nuevoEmpleado.legajo = legajo;

			getValidString("Ingrese apellido: ", "Error, ingrese apellido.", nuevoEmpleado.apellido);

			/*printf("Ingrese apellido: ");
			fflush(stdin);
			gets(nuevoEmpleado.apellido);*/

			getValidString("Ingrese nombre: ", "Error, ingrese nombre.", nuevoEmpleado.nombre);

			/*printf("Ingrese nombre: ");
			fflush(stdin);
			gets(nuevoEmpleado.nombre);*/



			printf("Ingrese sexo: ");
			scanf("%c", &nuevoEmpleado.sexo);
			fflush(stdin);
			while(nuevoEmpleado.sexo != 'm' && nuevoEmpleado.sexo != 'f')
			{
				printf("Error, ingrese f o m: ");
				scanf("%c", &nuevoEmpleado.sexo);
				fflush(stdin);
			}

			nuevoEmpleado.sueldo = getValidFloat("Ingrese sueldo: ", "Error, ingrese valor numerico: ", 1, 999999);

			/*printf("Ingrese sueldo: ");
			fflush(stdin);
			scanf("%f", &nuevoEmpleado.sueldo);*/

			nuevoEmpleado.idSector = elegirSector(sectores, 5);

			nuevoEmpleado.isEmpty = 0;

			empleados[indice] = nuevoEmpleado;
		   }
	    }
}

void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector)
{
    char descripcion[20];

    cargarDescripcion(sectores, tamSector, emp.idSector, descripcion);

    printf("%d\t%s\t%s\t%c\t%.2f\t%s\n\n", emp.legajo, emp.apellido, emp.nombre, emp.sexo, emp.sueldo, descripcion);

}

void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector)
{
    int i;
    for(i=0; i< tam; i++)
    {
        if(nomina[i].isEmpty == 0)
        {
            mostrarEmpleado(nomina[i], sectores, tamSector);
        }
    }
}

void eliminarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{

	int legajo;
	int indice;
	char borrar;
	eEmpleado emp;

	printf("Ingrese legajo: ");
	scanf("%d", &legajo);

	indice = buscarEmpleado(empleados, tam, legajo);

	if( indice == -1){
		printf("No hay ningun empleado con el legajo %d\n", legajo);
	}
	else{
		emp = empleados[indice];
		mostrarEmpleado(emp, sectores, tamSector);

		printf("\nConfirma borrado?: ");
		fflush(stdin);
		scanf("%c", &borrar);
		if(borrar != 's'){
		printf("Borrado cancelado\n\n");
	}
	else{
		empleados[indice].isEmpty = 1;
		printf("Se ha eliminado el empleado\n\n");
	}
	system("pause");
	}

}

void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{

	int opcionMenuMod;
	char edit;
	char nuevoNombre[51];
	char nuevoApellido[51];
	char nuevoSexo;
	float nuevoSalario;
	int nuevoSector;
	int indice;
	int legajo;

	legajo = getValidInt("Ingrese legajo de empleado a modificar: ", "Error, fuera de rango.", 1, 5);
	indice = buscarEmpleado(empleados, tam, legajo);

	do
	{
		system("cls");
		printf("*** Empleado a modificar ***\n\n");

		mostrarEmpleado(empleados[indice], sectores, tamSector);

		printf("*** Menu de MODIFICACIONES ***\n\n");
		printf("1.- Modificar apellido.\n");
		printf("2.- Modificar nombre.\n");
		printf("3.- Modificar sexo.\n");
		printf("4.- Modificar salario.\n");
		printf("5.- Modificar sector.\n");
		printf("6.- Salir.\n\n");

		printf("Elija opcion: ");
		scanf("%d", &opcionMenuMod);

		switch(opcionMenuMod)
		{
			case 1:
				printf("\nModifica apellido? s/n ");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit!='s')
				{
					printf("Modificacion cancelada.\n\n");
				}
				else
				{
					getValidString("Ingrese NUEVO apellido: ", "Error, reingrese.", nuevoApellido);
					strcpy(empleados[indice].apellido, nuevoApellido);
					printf("Se ha modificado el apellido con exito\n\n");
				}

				system("pause");
				break;

			case 2:
				printf("\nModifica nombre? s/n ");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit!='s')
				{
					printf("Modificacion cancelada.\n\n");
				}
				else
				{
					getValidString("Ingrese NUEVO nombre: ", "Error, reingrese.", nuevoNombre);
					strcpy(empleados[indice].nombre, nuevoNombre);
					printf("Se ha modificado el nombre con exito\n\n");
				}

				system("pause");
				break;

			case 3:
				printf("\nModifica sexo? s/n ");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit!='s')
				{
					printf("Modificacion cancelada.\n\n");
				}
				else
				{
					printf("Ingrese NUEVO sexo: ");
					scanf("%c", &nuevoSexo);
					fflush(stdin);
					while(nuevoSexo != 'm' && nuevoSexo != 'f')
					{
						printf("Error, ingrese f o m: ");
						scanf("%c", &nuevoSexo);
						fflush(stdin);
					}
					empleados[indice].sexo = nuevoSexo;
					printf("Se ha modificado el sexo con exito.\n\n");
				}

				system("pause");
				break;

			case 4:
				printf("\nModifica sueldo?: ");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit != 's'){
				printf("Modificacion cancelada\n\n");
				}
				else{
					nuevoSalario = getValidFloat("Ingrese NUEVO sueldo: ", "Error, reingrese.", 0, 99999);

					empleados[indice].sueldo = nuevoSalario;
					printf("Se ha modificado el sueldo con exito\n\n");
				}

				system("pause");
				break;

			case 5:
				printf("\nModifica sector?: ");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit != 's'){
				printf("Modificacion cancelada\n\n");
				}
				else{
					nuevoSector = getValidInt("Ingrese NUEVO sector: ", "Error, reingrese.", 0, 5);

					empleados[indice].idSector = nuevoSector;
					printf("Se ha modificado el sector con exito\n\n");
				}

				system("pause");
				break;

			case 6:
				break;

			default:
				printf("Opcion equivocada. ");
				system("pause");
				break;

		}
	}while(opcionMenuMod!=6);
}

/*--------------Codigo Comida--------------*/

void comidaMenu(eComida listaComida[], int tamComida)
{
	int opcionSubMenuComida;

	do
	{
		system("cls");
		printf("*** Menu de Comida ***\n\n");

		printf("1.- Alta.\n");
		printf("2.- Baja.\n");
		printf("3.- Modificacion.\n");
		printf("4.- Listar.\n");
		printf("5.- Volver.\n\n");

		printf("Elija opcion: ");
		scanf("%d", &opcionSubMenuComida);
		fflush(stdin);
		printf("\n");

		switch(opcionSubMenuComida)
		{
			case 1:
				agregarComida(listaComida, tamComida);
				break;

			case 2:
				eliminarComida(listaComida, tamComida);
				break;

			case 3:
				modificarComida(listaComida, tamComida);
				break;

			case 4:
				mostrarComidas(listaComida, tamComida);
				system("pause");
				break;

			case 5:
				break;

			default:
				printf("No es una opcion valida. ");
				system("pause");
				break;
		}
	}while(opcionSubMenuComida!=5);
}

void inicializarComida(eComida listaComida[], int tamComida)
{
	int i=0;

	for(i=0; i < tamComida; i++)
	{
		listaComida[i].importe = 1;
	}
}

int buscarLibreComida(eComida listaComida[], int tamComida)
{
    int indice = -1, i=0;

    for(i=0; i < tamComida; i++)
    {

        if( listaComida[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarComida(eComida listaComida[], int tamComida, int id)
{
    int indice=-1, i=0;

    for(i=0; i < tamComida; i++)
    {
        if( listaComida[i].idMenu == id && listaComida[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void agregarComida(eComida listaComida[], int tamComida)
{
	eComida nuevaComida;
	int indice;
	int esta;
	int id;

	indice = buscarLibreComida(listaComida, tamComida);

	if(indice == -1)
	{
		printf("No hay lugar\n\n");
		system("pause");
	}
	else
	{
		printf("Ingrese id: ");
		scanf("%d", &id);

		esta = buscarComida(listaComida, tamComida, id);

		if(esta != -1)
		{
			printf("Existe una comida con el id %d\n", id);
			mostrarComida(listaComida[esta]);
		}
		else{
			nuevaComida.idMenu = id;

			getValidString("Ingrese nombre de comida: ", "Error, ingrese nombre de comida.", nuevaComida.descripcion);

			nuevaComida.importe = getValidFloat("Ingrese precio: ", "Error, ingrese dato numerico: ", 1, 999999);

			nuevaComida.isEmpty = 0;

			listaComida[indice] = nuevaComida;
		   }
	    }
}

void mostrarComida(eComida listaComida)
{
    printf("%d\t%s\t%.2f\n\n", listaComida.idMenu, listaComida.descripcion, listaComida.importe);
}

void mostrarComidas(eComida listaComida[], int tamComida)
{
    int i;
    for(i=0; i< tamComida; i++)
    {
        if(listaComida[i].isEmpty == 0)
        {
            mostrarComida(listaComida[i]);
        }
    }
}

void eliminarComida(eComida listaComida[], int tamComida)
{

	int id;
	int indice;
	char borrar;
	eComida comida;

	printf("Ingrese id: ");
	scanf("%d", &id);

	indice = buscarComida(listaComida, tamComida, id);

	if( indice == -1){
		printf("No hay ninguna comida con el id %d\n", id);
	}
	else{
		comida = listaComida[indice];
		mostrarComida(comida);

		printf("\nConfirma borrado?: ");
		fflush(stdin);
		scanf("%c", &borrar);
		if(borrar != 's'){
		printf("Borrado cancelado\n\n");
	}
	else{
		listaComida[indice].isEmpty = 1;
		printf("Se ha eliminado la comida\n\n");
	}
	system("pause");
	}

}

void modificarComida(eComida listaComida[], int tamComida)
{

	int opcionMenuMod;
	char edit;
	char nuevaDescripcion[51];
	char nuevoImporte;
	int indice;
	int id;

	id = getValidInt("Ingrese id de la comida a modificar: ", "Error, fuera de rango.", 1, 5);
	indice = buscarComida(listaComida, tamComida, id);

	do
	{
		system("cls");
		printf("*** Comida a modificar ***\n\n");

		mostrarComida(listaComida[indice]);

		printf("*** Menu de MODIFICACIONES ***\n\n");
		printf("1.- Modificar descripcion.\n");
		printf("2.- Modificar importe.\n");
		printf("3.- Salir.\n\n");

		printf("Elija opcion: ");
		scanf("%d", &opcionMenuMod);

		switch(opcionMenuMod)
		{
			case 1:
				printf("\nModifica descripcion? s/n ");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit!='s')
				{
					printf("Modificacion cancelada.\n\n");
				}
				else
				{
					getValidString("Ingrese NUEVA descripcion: ", "Error, reingrese.", nuevaDescripcion);
					strcpy(listaComida[indice].descripcion, nuevaDescripcion);
					printf("Se ha modificado la descripcion con exito\n\n");
				}

				system("pause");
				break;

			case 2:
				printf("\nModifica importe?: ");
				fflush(stdin);
				scanf("%c", &edit);
				if(edit != 's'){
				printf("Modificacion cancelada\n\n");
				}
				else{
					nuevoImporte = getValidFloat("Ingrese NUEVO importe: ", "Error, reingrese.", 1, 99999);

					listaComida[indice].importe = nuevoImporte;
					printf("Se ha modificado el importe con exito\n\n");
				}

				system("pause");
				break;

			case 3:
				break;

			default:
				printf("Opcion equivocada. ");
				system("pause");
				break;

		}
	}while(opcionMenuMod!=3);
}
