#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_VETOR 10
#define TAM_VETOR_SEC 50

int main() {
    srand(time(NULL));
    int vetor[TAM_VETOR];
    int vetor_sec[TAM_VETOR_SEC];
    int referencia, i, contador_menores = 0, contador_referencia = 0;

    printf("Digite 10 numeros inteiros:\n");
    for (i = 0; i < TAM_VETOR; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Digite um valor de referencia: ");
    scanf("%d", &referencia);

    printf("Numeros maiores que o valor de referencia (%d):\n", referencia);
    for (i = 0; i < TAM_VETOR; i++) {
        if (vetor[i] > referencia) {
            printf("%d ", vetor[i]);
        }
    }
    printf("\n");

    for (i = 0; i < TAM_VETOR; i++) {
        if (vetor[i] < referencia) {
            contador_menores++;
        }
    }
    printf("Quantidade de numeros menores que o valor de referencia: %d\n", contador_menores);

    for (i = 0; i < TAM_VETOR; i++) {
        if (vetor[i] == referencia) {
            contador_referencia++;
        }
    }
    printf("Quantidade de vezes que o valor de referencia aparece no vetor: %d\n", contador_referencia);

    printf("Gerando 50 numeros inteiros aleatorios para o segundo vetor:\n");
    for (i = 0; i < TAM_VETOR_SEC; i++) {
        vetor_sec[i] = rand() % 101;
        printf("%d ", vetor_sec[i]);
    }
    printf("\n");

    printf("Contagem das ocorrencias dos numeros do primeiro vetor no segundo vetor:\n");
    for (i = 0; i < TAM_VETOR; i++) {
        int ocorrencias = 0;
        for (int j = 0; j < TAM_VETOR_SEC; j++) {
            if (vetor[i] == vetor_sec[j]) {
                ocorrencias++;
            }
        }
        printf("Numero %d aparece %d vezes no segundo vetor.\n", vetor[i], ocorrencias);
    }

    int total_ocorrencias = 0;
    for (i = 0; i < TAM_VETOR_SEC; i++) {
        for (int j = 0; j < TAM_VETOR; j++) {
            if (vetor_sec[i] == vetor[j]) {
                total_ocorrencias++;
                break;
            }
        }
    }

    float porcentagem = (total_ocorrencias / (float)TAM_VETOR_SEC) * 100;
    printf("Porcentagem de numeros do segundo vetor que constam no primeiro: %.2f%%\n", porcentagem);

    return 0;
}
