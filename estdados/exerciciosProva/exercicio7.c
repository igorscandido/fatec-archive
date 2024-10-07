#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_VETOR 20

int main() {
    srand(time(NULL));
    int numeros[TAM_VETOR];

    printf("Ordem normal dos números:\n");
    for (int i = 0; i < TAM_VETOR; i++) {
        numeros[i] = rand() % 101;
        printf("%d ", numeros[i]);
    }

    printf("\nNúmeros em ordem inversa:\n");
    for (int i = TAM_VETOR - 1; i >= 0; i--) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}
