#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

#define LEN_COMIDA 20

typedef struct
{
	int idMenu;
	char descripcion[51];
	float importe;
	int isEmpty;
}eComida;

void inicializarComida(eComida listaComida[], int tamComida);

void comidaMenu(eComida listaComida[], int tamComida);

void agregarComida(eComida listaComida[], int tamComida);

void eliminarComida(eComida listaComida[], int tamComida);

void modificarComida(eComida listaComida[], int tamComida);

void mostrarComida(eComida listaComida);

void mostrarComidas(eComida listaComida[], int tamComida);

#endif // COMIDA_H_INCLUDED
