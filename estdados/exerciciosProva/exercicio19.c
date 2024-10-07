#include <stdio.h>

int soma_dobros(int *a, int *b) {
    *a = *a * 2;
    *b = *b * 2;
    return *a + *b;
}

int main() {
    int A, B;

    printf("Digite o primeiro valor (A): ");
    scanf("%d", &A);
    printf("Digite o segundo valor (B): ");
    scanf("%d", &B);

    int resultado = soma_dobros(&A, &B);

    printf("Dobro de A: %d\n", A);
    printf("Dobro de B: %d\n", B);
    printf("Soma dos dobrados: %d\n", resultado);

    return 0;
}
