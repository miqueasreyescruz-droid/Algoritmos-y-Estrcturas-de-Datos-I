#ifndef FILA_h
#define FILA_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;
const int indefinido = -99999;

struct Nodo
{
    item dato;
    Nodo* siguiente;
};

typedef struct 
{
    Nodo* cabecera;
    int altura;
} Pila;

Pila PILAVACIA ();
Pila PUSH (Pila P, item i);
Pila POP (Pila P);
item TOP (Pila P);
bool ESPILAVACIA (Pila P);
int ALTURA (Pila P);
Pila PUSHF (Pila P, item i);

#endif