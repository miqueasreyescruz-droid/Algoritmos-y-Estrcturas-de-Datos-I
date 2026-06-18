#include "BAUL.h"

BAUL BAULVACIO(int capacidad)
{
    BAUL NuevoBaul;
    NuevoBaul.objetos = NULL;
    NuevoBaul.primero = NULL;
    NuevoBaul.capacidadMAX = capacidad;
    NuevoBaul.ocupado = 0;

    return NuevoBaul;
}

BAUL GUARDAR(BAUL C, Objeto u)
{
    Nodo* NuevoNodo = new Nodo;

    if (C.objetos == NULL)
    {
        C.primero = NuevoNodo;
    }
    
    NuevoNodo -> dato = u;
    NuevoNodo -> siguiente = C.objetos;
    C.objetos = NuevoNodo;
    C.ocupado++;

    return C;
}

BAUL AGREGAR(BAUL C, Objeto u)
{
    if (C.ocupado < C.capacidadMAX)
    {
        C = GUARDAR(C,u);
        return C;
    }
    else
    {
        return C;
    }
}

int CAPACIDAD(BAUL C)
{
    return C.capacidadMAX;
}

bool ESTAVACIO(BAUL C)
{
    if (C.objetos == NULL && C.ocupado == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Objeto ULTIMO(BAUL C)
{
    if (ESTAVACIO(C))
    {
        return indefinido;
    }
    else
    {
        return C.objetos -> dato;
    }
    
    return Objeto();
}

Objeto PRIMERO(BAUL C)
{
    if (ESTAVACIO(C))
    {
        return indefinido;
    }
    else
    {
        return C.primero -> dato;
    }
    
}

BAUL QUITARULTIMO(BAUL C)
{
    if (ESTAVACIO(C))
    {
        return C;
    }
    else
    {
        if (C.objetos -> siguiente == NULL)
        {
            C.primero = NULL;
        }

        Nodo* aux = C.objetos;
        C.objetos = C.objetos -> siguiente;
        delete(aux);
        C.ocupado--;
        
        return C;
    }
}

BAUL VACIAR(BAUL C)
{
    while (C.objetos != NULL)
    {
        Nodo* aux = C.objetos;
        C.objetos = C.objetos -> siguiente;    
        delete(aux);
    }
    C.ocupado = 0;
    C.primero = NULL;

    return C;
}

bool CONTIENE(BAUL C, Objeto u)
{
    while (C.objetos != NULL)
    {
        if ( C.objetos -> dato == u)
        {
            return true;
        }

        C.objetos = C.objetos -> siguiente; 
    }

    return false;
}

int OCUPADO(BAUL C)
{
    return C.ocupado;
}

int DISPONIBLE(BAUL C)
{
    return C.capacidadMAX - C.ocupado;
}
