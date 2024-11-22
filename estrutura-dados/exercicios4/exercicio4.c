#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherMatriz(int (*matriz)[5]);
void mostrarMatriz(int (*matriz)[5]);
int somaMatriz(int (*matriz)[5]);
double mediaMatriz(int (*matriz)[5]);
int procurarValor(int (*matriz)[5], int valor);

int main() {
    int matriz[10][5];
    int valorProcurado;

    preencherMatriz(matriz);
    mostrarMatriz(matriz);

    printf("\nSoma dos elementos da matriz: %d\n", somaMatriz(matriz));
    printf("Média dos elementos da matriz: %.2f\n", mediaMatriz(matriz));

    printf("\nDigite um valor para procurar: ");
    scanf("%d", &valorProcurado);

    if (procurarValor(matriz, valorProcurado) == -1) {
        printf("Valor %d não encontrado.\n", valorProcurado);
    }

    return 0;
}

void preencherMatriz(int (*matriz)[5]) {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = rand() % 100;
        }
    }
}

void mostrarMatriz(int (*matriz)[5]) {
    printf("Matriz 10x5:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int somaMatriz(int (*matriz)[5]) {
    int soma = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            soma += matriz[i][j];
        }
    }
    return soma;
}

double mediaMatriz(int (*matriz)[5]) {
    int soma = somaMatriz(matriz);
    return (double)soma / (10 * 5);
}

int procurarValor(int (*matriz)[5], int valor) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            if (matriz[i][j] == valor) {
                printf("Valor %d encontrado na posição %dx%d\n", valor, i, j);
                return 1;
            }
        }
    }
    return -1;
}
