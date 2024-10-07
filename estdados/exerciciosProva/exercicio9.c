#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_VETOR 20
#define MAX_VALOR 50

int existe_no_vetor(int vetor[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            return 1;
        }
    }
    return 0;
}

void ordenar_vetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int A[TAM_VETOR], B[TAM_VETOR], C[TAM_VETOR * 2];
    int tamanho_C = 0;

    for (int i = 0; i < TAM_VETOR; i++) {
        A[i] = rand() % (MAX_VALOR + 1);
    }

    for (int i = 0; i < TAM_VETOR; i++) {
        B[i] = rand() % (MAX_VALOR + 1);
    }

    for (int i = 0; i < TAM_VETOR; i++) {
        if (!existe_no_vetor(C, tamanho_C, A[i])) {
            C[tamanho_C++] = A[i];
        }
    }

    for (int i = 0; i < TAM_VETOR; i++) {
        if (!existe_no_vetor(C, tamanho_C, B[i])) {
            C[tamanho_C++] = B[i];
        }
    }

    ordenar_vetor(C, tamanho_C);

    printf("Vetor A: ");
    for (int i = 0; i < TAM_VETOR; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("Vetor B: ");
    for (int i = 0; i < TAM_VETOR; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    printf("Vetor C (elementos únicos ordenados): ");
    for (int i = 0; i < tamanho_C; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    return 0;
}
