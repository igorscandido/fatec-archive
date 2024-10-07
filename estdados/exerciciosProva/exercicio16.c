#include <stdio.h>

int main() {
    int a, b;

    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo número: ");
    scanf("%d", &b);

    if (&a > &b) {
        printf("O maior endereço é de 'a' (%p) com valor: %d\n", &a, a);
    } else {
        printf("O maior endereço é de 'b' (%p) com valor: %d\n", &b, b);
    }

    return 0;
}
