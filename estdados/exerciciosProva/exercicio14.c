#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 10
#define COLUNAS 10
#define MAX_VALOR 1000

int main() {
    srand(time(NULL));
    int matriz[LINHAS][COLUNAS];
    int valor_procurado;

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = rand() % (MAX_VALOR + 1);
        }
    }

    printf("Digite o valor procurado (0 a 1000): ");
    scanf("%d", &valor_procurado);

    int encontrado = 0;
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (matriz[i][j] == valor_procurado) {
                printf("Valor %d encontrado na posição [%d][%d]\n", valor_procurado, i, j);
                encontrado = 1;
            }
        }
    }

    if (!encontrado) {
        printf("Valor %d não encontrado na matriz.\n", valor_procurado);
    }

    printf("\nMatriz:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
