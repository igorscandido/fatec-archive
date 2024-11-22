#include <stdio.h>

int main() {
    int numero;

    printf("Digite um número para geração da tabuada: ");
    scanf("%d", &numero);

    printf("Tabuada do %d:\n", numero);
    printf("Soma:\n");
    for (int i = 0; i <= 10; i++) {
        printf("%d + %d = %d\n", numero, i, numero + i);
    }

    printf("Multiplicação:\n");
    for (int i = 0; i <= 10; i++) {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }

    return 0;
}
