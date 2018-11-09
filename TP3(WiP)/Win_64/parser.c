#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
Employee* empAux;
char idStr[5];
char nombreStr[128];
char horasTrabajadasStr[4];
char sueldoStr[6];

    fgets(pfile);
    do
    {
	fscanf(pFile, "%5[^,],%128[^,],%4[^,],%5[^\n]", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
        empAux = employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);
        ll_add(pArrayListEmployee, (void*)empAux);
    }while(!feof(pFile));
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
Employee* empAux;

    do
    {
	fread((void*)empAux, sizeof(Employee), 1, pFile); //void *ptr, size_t size, size_t nmemb, FILE *stream
	ll_add(pArrrayListemployee, (void*)empAux);
    }while(!feof(pFile));

    return 1;
}
