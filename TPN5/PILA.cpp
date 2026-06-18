#include "PILA.h"

Pila PILAVACIA()
{
    Pila NuevaPila;

    NuevaPila.altura = 0;
    NuevaPila.cabecera = NULL;

    return NuevaPila;
}

Pila PUSH(Pila P, item i)
{
    Nodo* NuevoNodo = new Nodo;

    NuevoNodo -> siguiente = P.cabecera;
    P.cabecera = NuevoNodo;
    P.altura++;

    return P;
}

Pila POP(Pila P)
{
    if (P.cabecera == NULL)
    {
        return P;
    }
    else
    {
        Nodo* aux = P.cabecera;
        P.cabecera = P.cabecera -> siguiente; 
        P.altura--;
        delete(aux);

        return P;
    }
}

item TOP(Pila P)
{
    if (P.cabecera == NULL)
    {
        return indefinido;
    }
    else
    {
        return P.cabecera -> dato;
    }
}

bool ESPILAVACIA(Pila P)
{
    if (P.cabecera == NULL && P.altura == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int ALTURA(Pila P)
{
    return P.altura;
}
