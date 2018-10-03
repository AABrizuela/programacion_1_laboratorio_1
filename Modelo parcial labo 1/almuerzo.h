#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

#define ALMUERZOS 2000

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    int legajoEmpleado;
    int idComida;
    eFecha diaMesAnio;
    int isEmpty;
}eAlmuerzo;

#endif // ALMUERZO_H_INCLUDED
