#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef char item;
extern const item indefinido;

struct Nodo {
    item dato;
    Nodo* siguiente;
};

typedef struct {
    struct Nodo* L;
    int cantidad;
} Lista;

Lista crearLista();
bool esListaVacia(Lista H);
void mostrar(Lista H);
item primerElemento(Lista H);
Lista insertar(Lista H, item x);
Lista borrar(Lista H);
int longitud(Lista H);
bool pertenece(Lista H, item x);
Lista insertarFinal(Lista H, item x);

item posicionK(Lista *H, int k);

#endif // LISTA_H
