#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int matriz[10][10];
    int valorProcurado;
    int encontrado = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matriz[i][j] = rand() % 1000;
        }
    }

    printf("Matriz 10x10:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nDigite um valor para procurar: ");
    scanf("%d", &valorProcurado);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (matriz[i][j] == valorProcurado) {
                printf("Valor %d na posição [%d][%d]\n", valorProcurado, i, j);
                encontrado = 1;
            }
        }
    }

    if (!encontrado) {
        printf("Valor %d não encontrado na matriz.\n", valorProcurado);
    }

    return 0;
}
