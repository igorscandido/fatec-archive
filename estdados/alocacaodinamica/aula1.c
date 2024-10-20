#include <stdio.h>

#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char * argv[]) {
  int * p, * r;
  p = (int * ) calloc(1, sizeof(int));
  if (p == NULL) {
    printf("Erro de memoria insuficiente\n");
    exit(1);
  }
  int a = 1;
  int b = 4;
  char nome[50];
  r = realloc(p, 50 * sizeof(int));
  printf("Ponteiro P = %p | Ponteiro R = %p", p, r);
  return 0;
}