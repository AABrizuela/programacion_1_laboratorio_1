#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "LinkedList.h"

Employee* employee_new(){

    Employee* this;

    this = malloc(sizeof(Employee));

    return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){

	int auxHorasTrabajadas;
	int auxId;
	int flag = 0;
	float auxSueldo;

	Employee* this;

	this = employee_new();

	if(this != NULL){

		auxId = atoi(idStr);
		if(employee_setId(this, auxId)!=1)
		{
			flag = 1;
		}

		if(employee_setNombre(this, nombreStr)!=1)
		{
			flag = 1;
		}

		auxHorasTrabajadas = atoi(horasTrabajadasStr);
		if(employee_setHorasTrabajadas(this, auxHorasTrabajadas)!=1)
		{
			flag = 1;
		}

		auxSueldo = atof(sueldoStr);
		if(employee_setSueldo(this, auxSueldo)!=1)
		{
			flag = 1;
		}

	}



	return this;
}

int employee_setId(Employee* this,int id){

	this->id = id;
}

int employee_setNombre(Employee* this, char* nombre){

	this->nombre = nombre

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){

	this->horasTrabajadas = horasTrabajadas;

}
