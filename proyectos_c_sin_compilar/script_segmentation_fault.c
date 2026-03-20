#include <stdio.h>
int main() {
  int *puntero_malo = (int *)0;
  printf("Rompiendo el programa...\n");
  printf("Dirección del puntero malo: %p\n", puntero_malo);
  *puntero_malo = 666;
  printf("Como llegaste aquí?, el sistema tuvo que haber cerrado esto...\n");
  return 0;
}
