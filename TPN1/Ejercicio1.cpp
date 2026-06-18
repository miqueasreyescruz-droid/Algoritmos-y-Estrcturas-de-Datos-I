#include "Lista.h"
#include <stdio.h>

// Programa Principal

int main() {

  Lista H;
  H = crearLista();

  H = insertar(H, 'A');
  H = insertar(H, 'B');
  H = insertar(H, 'C');
  H = insertar(H, 'D');

  mostrar(H);

  printf("Primer elemento: %c\n", primerElemento(H));
  printf("Longitud de la lista: %d\n", longitud(H));
  printf("Pertenece el elemento 'B' a la lista? %s\n",
         pertenece(H, 'B') ? "SI" : "NO");
  printf("Pertenece el elemento 'E' a la lista? %s\n",
         pertenece(H, 'E') ? "SI" : "NO");

  H = insertarFinal(H, 'E');

  mostrar(H);

  printf("Pertenece el elemento 'E' a la lista? %s\n",
         pertenece(H, 'E') ? "SI" : "NO");

  while (H.L != NULL) {
    H = borrar(H);
  }

  return 0;
}
