#ifndef BAUL_h
#define BAUL_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char Objeto;
const Objeto indefinido = '@';

struct Nodo
{
    Objeto dato;
    Nodo* siguiente;
};

struct BAUL
{
    Nodo* objetos;
    Nodo* primero;
    int capacidadMAX;
    int ocupado;
};

BAUL BAULVACIO (int capacidad);
BAUL GUARDAR (BAUL C, Objeto u); // Constructora escondida
BAUL AGREGAR (BAUL C, Objeto u);
int CAPACIDAD (BAUL C);
bool ESTAVACIO (BAUL C);
Objeto ULTIMO (BAUL C);
Objeto PRIMERO (BAUL C);
BAUL QUITARULTIMO (BAUL C);
BAUL VACIAR (BAUL C);
bool CONTIENE (BAUL C, Objeto u);
int OCUPADO (BAUL C);
int DISPONIBLE (BAUL C);

#endif