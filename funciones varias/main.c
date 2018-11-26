#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int codigo;
	int marca[20];
	int modelo[20];
	int capacidad;
}ePendrive;

int main()
{
    int seguirCargando;
    int i;
    int auxNuevaLogitud;
    int logitudPersonas = 1;
    struct persona* pArrayPersona;
    struct persona* pAuxPersona;
	// Creamos el array de personas
    pArrayPersona = malloc(sizeof(struct persona));
    if (pArrayPersona == NULL)
    {
        printf("\nNo hay lugar en memoria\n");
        exit(0);
    }
    while(1)
    {
        printf("\nIngrese nombre: ");
        scanf("%s",(pArrayPersona+logitudPersonas-1)->nombre);
        printf("\nIngrese edad: ");
        scanf("%d",&((pArrayPersona+logitudPersonas-1)->edad));
        printf("\nSi desea cargar otra persona ingrese (1): ");
        scanf("%d",&seguirCargando);
        if(seguirCargando == 1)
        {
            logitudPersonas++; //Incremento el contador de personas. Correccion.
            // Calculamos el nuevo tamaño del array
            auxNuevaLogitud = sizeof(struct persona) * logitudPersonas;
            // Redimencionamos la lista
            pAuxPersona = realloc( pArrayPersona, auxNuevaLogitud);
            if (pAuxPersona == NULL)
            {
                printf("\nNo hay lugar en memoria\n");
                break;
            }
            //logitudPersonas++; Mal ubicado
            pArrayPersona = pAuxPersona;
        }
        else
        {
            break;
        }
    }

    for(i = 0; i < logitudPersonas; i++)
    {
        printf("\nNombre: %s - ",(pArrayPersona+i)->nombre);
        printf("Edad: %d",(pArrayPersona+i)->edad);
    }

    free(pArrayPersona); // Liberamos la memoria
    return 0;
}

Employee* employee_new(){
    Employee* pEmpleado = malloc(sizeof(Employee));
    pEmpleado->id = -1;
    strcpy(pEmpleado->nombre, "");
    pEmpleado->horasTrabajadas = 0;
    pEmpleado->sueldo = 0;
    return pEmpleado;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){
    FILE *binary;
    int retorno = 0;
    if ((binary = fopen(path, "rb")) != NULL)
        retorno = parser_EmployeeFromBinary(binary, pArrayListEmployee);
    fclose(binary);
return retorno;

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){
    /*Employee *pEmpleado = employee_new();
    int cantidad, retorno = 0;
    while(!feof(pFile)){
        cantidad = fread(pEmpleado, sizeof(Employee), 1, pFile);
        if(cantidad == 1 && pEmpleado != NULL){
            ll_add(pArrayListEmployee, pEmpleado);
            //printf("%5d %20s %3d %6.2f\n",pEmpleado->id,pEmpleado->nombre,pEmpleado->horasTrabajadas,pEmpleado->sueldo);
            retorno = 1;
        }
    }*/
    Employee auxEmpleado;
    int cantidad, retorno = 0;
    while(!feof(pFile)){
        cantidad = fread(&auxEmpleado, sizeof(Employee), 1, pFile);
        Employee *pEmpleado = employee_new();
        if(cantidad == 1){
            pEmpleado->id = auxEmpleado.id;
            strcpy(pEmpleado->nombre,auxEmpleado.nombre);
            pEmpleado->horasTrabajadas = auxEmpleado.horasTrabajadas;
            pEmpleado->sueldo = auxEmpleado.sueldo;
            ll_add(pArrayListEmployee, pEmpleado);
            retorno = 1;
        }
        else{
            if(!feof(pFile))
                break;
        }
    }
    fclose(pFile);
    return retorno;
}/**< FINALIZADO */

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee){
    FILE* binary;
    Employee* this;
    int retorno = 0, largo, i;
    binary = fopen(path, "wb");
    largo = ll_len(pArrayListEmployee);
    if(binary != NULL && pArrayListEmployee != NULL){
        for(i=0; i<largo; i++){
            this = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(this, sizeof(Employee), 1, binary);
        }
        retorno = 1;
    }
    fclose(binary);
    return retorno;
}/**< FINALIZADO */

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){
    FILE* text;
    Employee* this;
    int retorno = 0, largo, i;
    text = fopen(path, "w");
    largo = ll_len(pArrayListEmployee);
    if(text != NULL && pArrayListEmployee != NULL){
        fprintf(text, "id,nombre,horasTrabajadas,sueldo\n");
        for(i=0; i < largo; i++){
            this = (Employee*) ll_get(pArrayListEmployee, i);
            fprintf(text, "%d,%s,%d,%.2f\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        }
        retorno = 1;
    }
    fclose(text);
    return retorno;
}/**< FINALIZADO */
