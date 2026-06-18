#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

const item indefinido = '@';

Lista crearLista() {
    Lista nuevaLista;
    nuevaLista.L = NULL;
    nuevaLista.cantidad = 0;
    return nuevaLista;
}

bool esListaVacia(Lista H) {
    return H.L == NULL;
}

void mostrar(Lista H) {
    Nodo* actual = H.L;
    while (actual != NULL) {
        printf("%c ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

item primerElemento(Lista H) {
    if (H.L == NULL) {
        printf("La lista esta vacia, no se puede obtener el primer elemento\n");
        return indefinido;
    }
    return H.L->dato;
}

Lista insertar(Lista H, item x) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        return H;
    }
    nuevoNodo->dato = x;
    nuevoNodo->siguiente = H.L;
    H.L = nuevoNodo;
    H.cantidad++;
    return H;
}

Lista borrar(Lista H) {
    if (H.L == NULL) {
        printf("La lista esta vacia, no se puede borrar\n");
        return H;
    }
    Nodo* nodoABorrar = H.L;
    H.L = nodoABorrar->siguiente;
    free(nodoABorrar);
    H.cantidad--;
    return H;
}

int longitud(Lista H) {
    return H.cantidad;
}

bool pertenece(Lista H, item x) {
    Nodo* nodoActual = H.L;
    while (nodoActual != NULL) {
        if (nodoActual->dato == x) {
            return true;
        }
        nodoActual = nodoActual->siguiente;
    }
    return false;
}

Lista insertarFinal(Lista H, item x) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        return H;
    }
    nuevoNodo->dato = x;
    nuevoNodo->siguiente = NULL;

    if (H.L == NULL) {
        H.L = nuevoNodo;
    } else {
        Nodo* aux = H.L;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevoNodo;
    }
    H.cantidad++;
    return H;
}

item posicionK (Lista *H, int k) {
    if (H == NULL || esListaVacia(*H) || k < 1) {
        return indefinido;
    }

    while (!esListaVacia(*H) && k > 1) {
        *H = borrar(*H);
        k--;
    }

    if (esListaVacia(*H)) {
        return indefinido;
    }

    return primerElemento(*H);
}
