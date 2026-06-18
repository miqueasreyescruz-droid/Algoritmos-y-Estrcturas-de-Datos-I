#ifndef STDAB_h
#define STDAB_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char itemAB;
const itemAB indefinido = '@';

struct nodoAB
{
    itemAB raiz;
    nodoAB* izq;
    nodoAB* der;
};
typedef struct nodoAB *AB;

AB ABVACIO();
AB ARMARAB(AB I, itemAB r, AB D);
bool ESABVACIO(AB T);
bool PERTENECE(AB T, itemAB x);
AB IZQUIERDO (AB T);
itemAB RAIZ (AB T);
AB DERECHO (AB T);

#endif