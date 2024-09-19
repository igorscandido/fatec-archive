#include <stdio.h>

#include <stdlib.h>

#include <time.h>


#define TAMANHO 50000
#define BUSCAR 178
#define LIMITE_ALEATORIO 150000

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void preencherArrayAleatorio(int V[], int posicoes);
void preencherArrayOrdenado(int V[], int posicoes);
int buscaLinear(int V[], int value, int posicoes);
int buscaOrdernada(int V[], int value, int posicoes);
void ordenar(int V[], int posicoes);
void imprimir(int V[], int posicoes);

void processarAleatorio(int V[]) {
  clock_t inicio = clock();

  int posicao = buscaLinear(V, BUSCAR, TAMANHO);

  clock_t fim = clock();
  double total = (double)(fim - inicio) / CLOCKS_PER_SEC;
  printf("tempo total aleatorio: %lf", total);
}

void processarOrdenado(int V[]) {
  ordenar(V, TAMANHO); // fora para nao contar no tempo de busca

  clock_t inicio = clock();

  int posicao = buscaOrdenada(V, BUSCAR, TAMANHO);

  clock_t fim = clock();
  double total = (double)(fim - inicio) / CLOCKS_PER_SEC;
  printf("tempo total ordenado: %lf", total);
}

int main(int argc, char * argv[]) {
  srand(time(NULL));
  int V[TAMANHO];
  preencherArrayAleatorio(V, TAMANHO);
  //imprimir(V, TAMANHO);

  printf("\n############ ALEATORIO ##########\n");
  processarAleatorio(V);
  printf("\n############ ORDENADO ##########\n");
  processarOrdenado(V);
  return 1;
}

void preencherArrayAleatorio(int V[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    V[i] = rand() % LIMITE_ALEATORIO;
  }
}

void preencherArrayOrdenado(int V[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    while (1 == 1) {
      int valor = rand() % LIMITE_ALEATORIO;
      if (i == 0) {
        V[i] = valor;
        break;
      }
      if (i != 0 && valor > V[i - 1]) {
        V[i] = valor;
        break;
      }
    }
  }
}

int buscaLinear(int V[], int value, int posicoes) {
  int i;
  for (i = 0; i < posicoes; i++) {
    if (value == V[i]) {
      printf("Numero de iteracoes: %d\n", i);
      return i;
    }
  }

  printf("Numero de iteracoes: %d\n", TAMANHO);
  return -1;
}

int buscaOrdenada(int V[], int value, int posicoes) {
  int i;
  for (i = 0; i < posicoes; i++) {
    if (value == V[i]) {
      printf("Numero de iteracoes: %d\n", i);
      return i;
    }
    if (value < V[i + 1]) {
      printf("Numero de iteracoes: %d\n", i);
      return -1;
    }
  }

  return -1;
}

void ordenar(int V[], int posicoes) {
  int i, j;
  for (j = 0; j < posicoes; j++) {
    for (i = 0; i < posicoes - 1; i++) {
      if (V[i] > V[i + 1]) {
        int aux = V[i + 1];
        V[i + 1] = V[i];
        V[i] = aux;
      }
    }
  }
}

void imprimir(int V[], int posicoes) {
  int i;
  printf("Impressao: | ");
  for (i = 0; i < posicoes; i++) {
    printf(" %d |", V[i]);
  }
  printf("\n");
}