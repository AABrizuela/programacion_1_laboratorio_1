#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "LinkedList.h"

Employee* employee_new(){

    Employee* this;

    this = malloc(sizeof(Employee));

    return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr){

    Employee* this;

    this = employee_new();

    /*setters para cada campo
    set_
    set_
    set_
    set_
    */
    //Employee* this = malloc(sizeof(Employee));


    return this;
}
