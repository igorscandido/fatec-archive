#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_VETOR 100
#define MAX_VALOR 100

float calcular_media(int vetor[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return (float)soma / tamanho;
}

int encontrar_maximo(int vetor[], int tamanho) {
    int maximo = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maximo) {
            maximo = vetor[i];
        }
    }
    return maximo;
}

int encontrar_minimo(int vetor[], int tamanho) {
    int minimo = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] < minimo) {
            minimo = vetor[i];
        }
    }
    return minimo;
}

int main() {
    int W[TAM_VETOR], J[TAM_VETOR];

    srand(time(NULL));

    for (int i = 0; i < TAM_VETOR; i++) {
        W[i] = rand() % (MAX_VALOR + 1);
        J[i] = rand() % (MAX_VALOR + 1);
    }

    int max_W = encontrar_maximo(W, TAM_VETOR);
    int min_J = encontrar_minimo(J, TAM_VETOR);
    float media_W = calcular_media(W, TAM_VETOR);
    float media_J = calcular_media(J, TAM_VETOR);

    float t = (max_W * (min_J + 1)) / (media_W + media_J);

    printf("Max(W): %d\n", max_W);
    printf("Min(J): %d\n", min_J);
    printf("Media(W): %.2f\n", media_W);
    printf("Media(J): %.2f\n", media_J);
    printf("t = %.2f\n", t);

    return 0;
}
