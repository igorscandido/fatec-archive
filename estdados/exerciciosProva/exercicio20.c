#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void encontrar_maior_e_ocorrencias(int arr[], int n, int *maior, int *contagem) {
    *maior = arr[0];
    *contagem = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > *maior) {
            *maior = arr[i];
            *contagem = 1;
        } else if (arr[i] == *maior) {
            (*contagem)++;
        }
    }
}

int main() {
    srand(time(NULL));
    int n = 10;
    int array[n];
    int maior, contagem;

    for (int i = 0; i < n; i++) {
        array[i] = rand() % 101;
    }

    printf("Array de números aleatórios: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    encontrar_maior_e_ocorrencias(array, n, &maior, &contagem);

    printf("Maior elemento: %d\n", maior);
    printf("Número de ocorrências: %d\n", contagem);

    return 0;
}