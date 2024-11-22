#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TAM_VETOR 100

float calcular_media(int vetor[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return (float)soma / tamanho;
}

float calcular_desvio_padrao(int vetor[], int tamanho, float media) {
    float soma_dos_quadrados = 0.0;

    for (int i = 0; i < tamanho; i++) {
        soma_dos_quadrados += pow(vetor[i] - media, 2);
    }

    return sqrt(soma_dos_quadrados / (tamanho - 1));
}

int main() {
    int J[TAM_VETOR];

    srand(time(NULL));

    for (int i = 0; i < TAM_VETOR; i++) {
        J[i] = rand() % 101;
    }

    float media = calcular_media(J, TAM_VETOR);
    
    float desvio_padrao = calcular_desvio_padrao(J, TAM_VETOR, media);

    printf("Média: %.2f\n", media);
    printf("Desvio Padrão: %.2f\n", desvio_padrao);

    return 0;
}
