#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* #include <conio.h> */
#include <curses.h>

// const int empleadosMax=10; <<<< RUNTIME 
#define maxEmpleados 10   /// <<<< PRECOMPILER
#define maxSectores 5

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int idSector;
    int isEmpty;
} eEmpleado;

typedef struct{
    int id;
    char descripcion[20];
}eSector;

typedef struct
{
    int id;
    char descripcion[20];
}eComida;

typedef struct
{
    int id;
    int idEmpleado;
    int idComida;
}eAlmuerzo;


void inicializarEmpleados( eEmpleado x[], int tam);
int buscarLibre( eEmpleado x[], int tam);
int buscarEmpleado(eEmpleado x[], int tam, int legajo);
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector);
void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector);
void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);
void eliminarEmpleado(eEmpleado *empleados, int tam, eSector sectores[], int tamSector);
void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);;
int elegirSector(eSector sectores[], int tam);
void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]);
void listarEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);
void cargarDescripcionComida(eSector comidas[], int tamComida, int idComida, char cadena[]);
int menu();

int main()
{

    char seguir = 's';
    eEmpleado lista[10];
    eSector sectores[] = {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
        };

    eComida comidas[] = {
        {1, "Milanesa"},
        {2, "Fideos"},
        {3, "Pizza"},
        {4, "Sopa"},
        {5, "Pescado"}
        };

    eAlmuerzo almuerzos[] = {
        {100, 1111, 2},
        {101, 5555, 1},
        {102, 4545, 3},
        {103, 3232, 4},
        {104, 1111, 1},
        {105, 5555, 5},
        {106, 4545, 2},
        {107, 3232, 5},
        {108, 1111, 2},
        {109, 5555, 1},
        {110, 4545, 1},
        {111, 3232, 4},
        {112, 1111, 3},
        {113, 5555, 5},
        {114, 4545, 4},
        {115, 3232, 5},
        {116, 1111, 2},
        {117, 5555, 5},
        {118, 4545, 2},
        {119, 3232, 3},
        {120, 1111, 2},
        {121, 5555, 1},
        {122, 4545, 3},
        {123, 3232, 4},
        };

    inicializarEmpleados(lista, 10);


    do
    {
        switch(menu())
        {

        case 1:
            agregarEmpleado(lista, maxEmpleados, sectores, 5);
            system("pause");
            break;
        case 2:
            eliminarEmpleado(lista, maxEmpleados, sectores, 5);
            break;
        case 3:
            modificarEmpleado(lista, maxEmpleados, sectores, 5);
            break;
        case 4:
            mostrarEmpleados(lista, maxEmpleados, sectores, 5);
            system("pause");
            break;
        case 5:
            // mostrarAlmuerzos();
	    printf("No hice mostrarAlmuerzos, hacerla");
            break;
        case 10:
            seguir = 'n';
            break;
        }

    }
    while(seguir == 's');



    return 0;
}

void inicializarEmpleados( eEmpleado x[], int tam)
{
    int i=0;

    for(i=0; i < tam; i++)
    {
        x[i].isEmpty = 0;
    }
}

int buscarLibre( eEmpleado x[], int tam)
{
    int indice = -1, i=0;

    for(i=0; i< tam; i++)
    {

        if( x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado x[], int tam, int legajo)
{
    int indice=-1, i=0;

    for(i=0; i < tam; i++)
    {


        if( x[i].legajo == legajo && x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Listar\n");
    printf("5- Listar todos los empleados de un sector");
    printf("6- Mostrar almuerzos");
    printf("10- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
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
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(empleados, tam, legajo);

        if(esta != -1)
        {
            printf("Existe un empleado con el legajo %d\n", legajo);
            mostrarEmpleado( empleados[esta], sectores, maxSectores);
        }
        else{
            nuevoEmpleado.legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);

            printf("Ingrese sueldo: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.sueldo);

            nuevoEmpleado.idSector = elegirSector(sectores, 5);

            nuevoEmpleado.isEmpty = 1;

            empleados[indice] = nuevoEmpleado;

        }
    }

}

//eEmpleado emp, char descripcion[]
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector)
{
    char descripcion[20];

    cargarDescripcion(sectores, tamSector, emp.idSector, descripcion);

    printf("%d %s %c %.2f %s \n\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, descripcion);

}


void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector)
{
    int i=0;
    for(i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == 1)
        {
            mostrarEmpleado(nomina[i], sectores, tamSector);
        }
    }
}

void eliminarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector){

int legajo;
int indice;
char borrar;

printf("Ingrese legajo: ");
scanf("%d", &legajo);

indice = buscarEmpleado(empleados, tam, legajo);

if( indice == -1){
    printf("No hay ningun empleado con el legajo %d\n", legajo);
}
else{
    mostrarEmpleado( empleados[indice], sectores, tamSector);

    printf("\nConfirma borrado?: ");
    fflush(stdin);
    scanf("%c", &borrar);
    if(borrar != 's'){
        printf("Borrado cancelado\n\n");
    }
    else{
        empleados[indice].isEmpty = 0;
        printf("Se ha eliminado el empleado\n\n");
    }
    system("pause");
}

}

void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector){

int legajo;
int indice;
char modificar;
float nuevoSueldo;

printf("Ingrese legajo: ");
scanf("%d", &legajo);

indice = buscarEmpleado(empleados, tam, legajo);

if( indice == -1){
    printf("No hay ningun empleado con el legajo %d\n", legajo);
}
else{
    mostrarEmpleado( empleados[indice], sectores, tamSector);

    printf("\nModifica sueldo?: ");
    fflush(stdin);
    scanf("%c", &modificar);
    if(modificar != 's'){
        printf("Modificacion cancelada\n\n");
    }
    else{
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);

        empleados[indice].sueldo = nuevoSueldo;
        printf("Se ha modificado el sueldo con exito\n\n");
    }

    system("pause");
}



}


int elegirSector(eSector sectores[], int tam){
    int idSector, i=0;
    printf("\nSectores\n\n");
    for(i=0; i < tam; i++){
        printf("%d %s\n", sectores[i].id, sectores[i].descripcion);
    }
    printf("\nSeleccione sector: ");
    scanf("%d", &idSector);

    return idSector;
}

void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]){
    int i=0;

    for(i=0; i < tamSector; i++){
        if( sectores[i].id == idSector){

            strcpy(cadena, sectores[i].descripcion);
            break;
        }
    }
}

void cargarDescripcionComida(eSector comidas[], int tamComida, int idComida, char cadena[])
{
    int i=0;

    for(i=0; i < tamComida; i++){
        if( comidas[i].id == idComida){

            strcpy(cadena, comidas[i].descripcion);
            break;
        }
    }
}

void listarEmpleadosXSector(eEmpleado x[], int tam, eSector sectores[], int tamSector)
{
    int auxSector=0, i=0, j=0, flag=0, idSector;
    char descripcion[20];

    // Muestro menu de sectores.
    printf("Elija un sector a mostrar:");
    for(i=0; i < tamSector; i++)
    {
	    printf("%d - %s", sectores[i].id, sectores[i].descripcion);
    }
    // Pido q elija un sector y veo que sea valido
    scanf("%d", &auxSector);
    /*Validar sector*/

    // Muestro los empleados del sector ingresado
    for (i=0; i <  tam;i++)
    {
	if(auxSector == x[i].idSector)
	{
		mostrarEmpleado(x[i], sectores, tamSector);
		flag = 1;
	}
    }

    if(flag == 0)
    {
        printf("No hay empleados para mostrar...");
    }
}
