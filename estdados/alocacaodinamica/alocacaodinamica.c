#include <stdio.h>

#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char * argv[]) {
  int size = 0;
  int * numeros = NULL;
  while (1 == 1) {
    int entrada;
    printf("Digite um valor (-1 sai): ");
    scanf("%d", & entrada);
    if (entrada == -1) {
      break;
    } else {
      size = size + 4;
      numeros = realloc(numeros, size);
      numeros[(size / 4) - 1] = entrada;
    }
  }

  int i, soma = 0;
  printf("Numeros: \n");
  for (i = 0; i < size / 4; i++) {
    printf("%d ", numeros[i]);
    soma += numeros[i];
  }

  printf("\nSoma total: %d | Valor medio: %.2f", soma, ((float) soma / (float)(size / 4)));
  free(numeros);

  return 0;
}