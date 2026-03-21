#include <stdio.h>
#include <stdlib.h>
void leer_archivo() {
  FILE *fichero;
  char linea[500];
  fichero = fopen("secreto.txt", "r");
  if (fichero == NULL) {
    printf("No hay secretos todavía, cerrando programa por seguridad ante fallos");
    exit(1);
  }
  printf("Los secretos actuales son\n-------------------------------\n");
  while (fgets(linea, sizeof(linea), fichero) != NULL) {
    printf("%s\n", linea);
  }
  fclose(fichero);
  printf("\nFin del archivo\n");
  exit(0);
}
int main() {
  int eleccion;
  printf("Bienvenido, diga 1 si quiere leer los secretos o 2 si quiere escribir un secreto: ");
  eleccion = getchar();
  printf("\n");
  if (eleccion == '1') {
    printf("LLamando a la función leer_archivo");
    leer_archivo();
  }
  char secreto[500];
  FILE *fichero;
  fichero = fopen("secreto.txt", "a");
  printf("Dime tu secreto y pulsa ENTER (se guardará a el archivo secreto.txt): ");
  scanf(" %[^\n]", secreto);
  if (fichero == NULL) {
    printf("\nEl fichero apunta a NULL\n");
    printf("Cerrando\n");
    return 1;
  }
  fprintf(fichero, "%s\n", secreto);
  fclose(fichero);
  printf("\nEl archivo se ha actualizado correctamente con el texto: %s\n", secreto);
  return 0;
}
