#include "FILA.h"

Fila FILAVACIA()
{
    Fila F;
    F.frente = NULL;
    F.final = NULL;
    F.longitud = 0;
    return F;
}

Fila ENFILA(Fila fila, item dato)
{
    Nodo* NuevoNodo = new Nodo;
    NuevoNodo -> dato = dato;
    NuevoNodo -> siguiente = NULL;

    if (ESFILAVACIA(fila))
    {
        fila.frente = NuevoNodo;
        fila.final = NuevoNodo;
    }
    else
    {
        fila.final -> siguiente = NuevoNodo;
        fila.final = NuevoNodo;
    }

    fila.longitud++;
    
    return fila;
}

bool ESFILAVACIA(Fila fila)
{
    if (fila.frente == NULL && fila.final == NULL && fila.longitud == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

item FRENTE(Fila fila)
{
    if (ESFILAVACIA(fila))
    {
        return indefinido;       
    }
    else
    {
        return fila.frente -> dato;
    }
}

Fila DEFILA(Fila fila)
{
    if (ESFILAVACIA(fila))
    {
        return fila;
    }
    else
    {
        Nodo* aux = fila.frente;
        fila.frente = fila.frente -> siguiente;
        fila.longitud--;
        free(aux);

        if (fila.frente == NULL)
        {
            fila.final == NULL;
        }
        
    }

    return fila;
}

void LIBERAR(Fila fila)
{
    while (fila.frente == NULL)
    {
        Nodo* aux = fila.frente;
        fila.frente = fila.frente -> siguiente;
        free(aux);   
    }

    fila.final == NULL;
}

