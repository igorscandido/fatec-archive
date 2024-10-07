#include <stdio.h>

void maior_menor(int *a, int *b) {
    if (*a > *b) {
        *b = *b;
    } else {
        *a = *a;
    }

    int temp = *a;
    *a = (*a > *b) ? *a : *b;
    *b = (temp < *b) ? temp : *b;
}

int main() {
    int A, B;

    printf("Digite o primeiro valor (A): ");
    scanf("%d", &A);
    printf("Digite o segundo valor (B): ");
    scanf("%d", &B);

    maior_menor(&A, &B);

    printf("Maior valor: %d\n", A);
    printf("Menor valor: %d\n", B);

    return 0;
}
