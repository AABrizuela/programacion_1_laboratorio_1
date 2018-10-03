#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#define LEN 100
#define SECTORLEN 5

typedef struct
{
    int legajo;
    char apellido[51];
    char nombre[51];
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
    int dia;
    int mes;
    int anio;
}eFechaIngreso;

/** \brief Menu para las funciones de empleados.
 *
 * \return void
 *
 */
void empeladoMenu();

/** \brief Inicializa todas las posiciones del array poniendolas en 0
 *
 * \param x[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void inicializarEmpleados( eEmpleado x[], int tam);

/** \brief Busca posiciones libres en el array de empleado
 *
 * \param x[] eEmpleado
 * \param tam int
 * \return int
 *
 */
int buscarLibre( eEmpleado x[], int tam);

/** \brief Busca un empleado y devuelve la posicion en el indice
 *
 * \param x[] eEmpleado
 * \param tam int
 * \param legajo int
 * \return int
 *
 */
int buscarEmpleado(eEmpleado x[], int tam, int legajo);

/** \brief Muestra un empleado
 *
 * \param emp eEmpleado
 * \param sectores[] eSector
 * \param tamSector int
 * \return void
 *
 */
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector);

/** \brief Muestra varios empleados usando un for con la funcion mostrarEmpleado()
 *
 * \param nomina[] eEmpleado
 * \param tam int
 * \param sectores[] eSector
 * \param tamSector int
 * \return void
 *
 */
void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector);

/** \brief Agrega empleados en posiciones libres
 *
 * \param empleados[] eEmpleado
 * \param tam int
 * \param sectores[] eSector
 * \param tamSector int
 * \return void
 *
 */
void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);

/** \brief Elimina empleados cambiando el valor de su isEmpty a 0
 *
 * \param empleados eEmpleado*
 * \param tam int
 * \param sectores[] eSector
 * \param tamSector int
 * \return void
 *
 */
void eliminarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);

/** \brief
 *
 * \param empleados[] eEmpleado
 * \param tam int
 * \param sectores[] eSector
 * \param tamSector int
 * \return void
 *
 */
void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);;

/** \brief Se elige el sector
 *
 * \param sectores[] eSector
 * \param tam int
 * \return int
 *
 */
int elegirSector(eSector sectores[], int tam);

/** \brief Se usa para cargarle una descripcion a cierto id.
 *
 * \param sectores[] eSector
 * \param tamSector int
 * \param idSector int
 * \param cadena[] char
 * \return void
 *
 */
void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]);

#endif // EMPLEADO_H_INCLUDED
