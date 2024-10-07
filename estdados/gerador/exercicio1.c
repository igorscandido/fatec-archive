#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void gerarNumerosArray(int *a);
int numeroIguaisArray(int *a, int *b);
void printarArray(int *a);

int main() {
    srand(time(NULL));
    int aposta[6], sorteio[6];
    gerarNumerosArray(aposta);
    gerarNumerosArray(sorteio);
    printarArray(aposta);
    printarArray(sorteio);
    printf("\nNúmeros acertados: %d", numeroIguaisArray(aposta, sorteio));

    return 0;
}

void gerarNumerosArray(int *a) {
    int i;
    for (i = 0; i < 6; i++) {
        while (1==1) {
            int aux = rand() % 61;
            int j;
            int duplicado = 0;
            for (j = 0; j < i; j++) {
                if (a[j] == aux) {
                    duplicado = 1;
                }
            }
            if (duplicado != 1) {
                a[i] = aux;
                break;
            }
        }
    }
}

int numeroIguaisArray(int *a, int *b) {
    int i, j, iguais = 0;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            if (a[i] == b[j]) {
                iguais++;
            }
        }
    }
    return iguais;
}

void printarArray(int *a) {
    int i = 0;
    printf("\n");
    for (i = 0; i < 6; i++) {
        printf(" %d ", a[i]);
    }
}