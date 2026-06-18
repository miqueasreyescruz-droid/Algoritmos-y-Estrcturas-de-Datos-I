#ifndef FILA_h
#define FILA_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;
const item indefinido = -99999;

struct Nodo
{
    item dato;
    Nodo* siguiente;
};

typedef struct
{
    int longitud;
    Nodo* frente;
    Nodo* final;
} Fila;

Fila FILAVACIA ();
Fila ENFILA (Fila fila, item dato);
bool ESFILAVACIA (Fila fila);
item FRENTE (Fila fila);
Fila DEFILA (Fila fila);
void LIBERAR (Fila fila);

#endif