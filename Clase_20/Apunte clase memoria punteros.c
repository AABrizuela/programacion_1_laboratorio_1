PeopleList* persona_initLista(void)
{
    PeopleList* pl = (PeopleList*)malloc(sizeof(PeopleList));
    pl->index=0;
    pl->size=2;
    pl->lista = (Persona**)malloc(sizeof(Persona*)*pl->size);
    return pl;
}


Size es el tamaño de la lista

Se usa doble puntero porque el primer puntero es la direccion de memoria de y
el segundo puntero es el principio de la lista dinamica de punteros. Necesitas
2 indirecciones para llegar al dato.

<Agregar items a una lista en particular>

Se pueden trabajar los punteros como array

pl->lista[pl->index] = p
pl->index++

Donde index es el lugar libre en la lista de punteros y p es la persona.
Supongamos que es 0, accede al primer elemento de la lista.

void persona_addPersona(PeopleList* pl, Persona* p)
{
    pl->lista[pl->index]=p;
    pl->index++;
    // si no hay mas lugar, pedimos más memoria para hacer un array más grande
    if(pl->index>=pl->size)
    {
        printf("no hay mas lugar, redefinimos el array\r\n");
        pl->size+=10;
        pl->lista = (Persona**)realloc(pl->lista,sizeof(Persona*)*pl->size);
    }
}

Se puede decir que la funcion es "multi-lista", la lista con la que se va a trabajar
se pasa como argumento. Es decir, la funcion "ll_add()" va a recibir una lista como
si fuera una variable mas.

<Programa final>

#include "Persona.h"
PeopleList* pl = persona_initLista();
do
{
    Persona* persona = persona_newPersona();
    char nombreAux[20];
    preguntarNombre(nombreAux);
    if(persona_setName(persona,nombreAux))
        printf("El nombre no es valido");

        int edadAux = preguntarEdad();
    if(persona_setEdad(persona,edadAux))
        printf("La edad no es válida");
        persona_addPersona(pl,persona);

}while(preguntarSalir()!='S');

