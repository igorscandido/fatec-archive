#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_VETOR 10

int main() {
    srand(time(NULL));
    int w[TAM_VETOR], k[TAM_VETOR];

    for (int i = 0; i < TAM_VETOR; i++) {
        w[i] = rand() % 100;
    }

    for (int i = 0; i < TAM_VETOR; i++) {
        k[i] = rand() % 100;
    }

    int soma = 0;
    for (int i = 0; i < TAM_VETOR; i++) {
        soma += w[i] + k[TAM_VETOR - 1 - i];
    }

    printf("Vetor w: ");
    for (int i = 0; i < TAM_VETOR; i++) {
        printf("%d ", w[i]);
    }
    printf("\n");

    printf("Vetor k: ");
    for (int i = 0; i < TAM_VETOR; i++) {
        printf("%d ", k[i]);
    }
    printf("\n");

    printf("A soma é: %d\n", soma);

    return 0;
}
