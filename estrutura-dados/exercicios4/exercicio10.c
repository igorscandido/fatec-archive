#include <stdio.h>

long fatorial(long num);
long fatorialQuadruplo(long n);

int main() {
    long n;
    printf("Digite um número inteiro (positivo): ");
    scanf("%lu", &n);

    if (n < 0) {
        printf("Número inválido.\n");
        return 1;
    }

    long resultado = fatorialQuadruplo(n);
    printf("O fatorial quádruplo de %lu é: %lu\n", n, resultado);

    return 0;
}

long fatorial(long num) {
    long resultado = 1;
    for (int i = 1; i <= num; i++) {
        resultado *= i;
    }
    return resultado;
}

long fatorialQuadruplo(long n) {
    long fatorial2n = fatorial(2 * n);
    long fatorialN = fatorial(n);
    return fatorial2n / fatorialN;
}
