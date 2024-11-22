#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int A, B;

    printf("Digite o primeiro valor (A): ");
    scanf("%d", &A);
    printf("Digite o segundo valor (B): ");
    scanf("%d", &B);

    printf("Antes da troca: A = %d, B = %d\n", A, B);

    trocar(&A, &B);

    printf("Após a troca: A = %d, B = %d\n", A, B);

    return 0;
}
