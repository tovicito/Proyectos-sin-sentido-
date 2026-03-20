#include <stdio.h>
int main() {
  printf("Di una letra: ");
  char letra = getchar();
  switch(letra) {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
      printf("\n La letra %c es una vocal\n", letra);
      break;
    default:
      printf("\n Es una consonante, o un símbolo raro\n");
      break;
  }
  printf("La letra escogida fue %c y su valor ascii es %d\n", letra, letra);
  return 0;
  
}
