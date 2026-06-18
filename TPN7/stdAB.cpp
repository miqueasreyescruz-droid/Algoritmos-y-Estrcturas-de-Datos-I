#include "stdAB.h"

AB ABVACIO()
{
    return NULL;
}

AB ARMARAB(AB I, itemAB r, AB D)
{
    nodoAB* T = new nodoAB;
    T -> izq = I;
    T -> der = D;
    T -> raiz = r;

    return T;
}

bool ESABVACIO(AB T)
{
    if (T == NULL)
    {
        return true;
    }
    else
    {    
        return false;
    }
}

bool PERTENECE(AB T, itemAB x)
{
    if (ESABVACIO(T))
    {
        return false;
    }
    else
    {
        return (x == T -> raiz || PERTENECE(T -> izq, x) || PERTENECE(T -> der, x));
    }
}

AB IZQUIERDO(AB T)
{
    return T -> izq;
}

itemAB RAIZ(AB T)
{
    return T -> raiz;
}

AB DERECHO(AB T)
{
    return T -> der;
}
