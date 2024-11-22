#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int verificaPrimo(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int W[100];

    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        W[i] = rand() % 1001;
    }

    printf("Numeros primos encontrados no vetor W:\n");
    for (int i = 0; i < 100; i++) {
        if (verificaPrimo(W[i])) {
            printf("%d ", W[i]);
        }
    }
    printf("\n");

    return 0;
}