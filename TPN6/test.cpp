#include <stdio.h>
#include "FILA.h"

int main () {
    Fila MiFila = FILAVACIA();

    printf("La fila %s vacia\n", ESFILAVACIA(MiFila) ? "esta" : "no esta");

    MiFila = ENFILA(MiFila,32);
    MiFila = ENFILA(MiFila,45);
    MiFila = ENFILA(MiFila,63);
    MiFila = ENFILA(MiFila,63);

    printf("La fila %s vacia\n", ESFILAVACIA(MiFila) ? "esta" : "no esta");

    printf("Frente de la fila: %d", MiFila.frente -> dato);

    MiFila = DEFILA(MiFila);
    MiFila = DEFILA(MiFila);

    printf("Frente de la fila: %d",MiFila.frente -> dato);

    return 0;
}