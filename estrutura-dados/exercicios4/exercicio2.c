#include <stdio.h>

int main() {
    int matriz[10][10] = {0};
    int linha, coluna, valor;

    printf("Digite o indice da linha e da coluna e o valor:\n");
    while (1) {
        scanf("%d %d", &linha, &coluna);
        if (linha < 0 || coluna < 0) {
            break;
        }
        scanf("%d", &valor);
        if (linha < 10 && coluna < 10) {
            matriz[linha][coluna] = valor;
        } else {
            printf("Indice invalido.\n");
            break;
        }
    }

    printf("Resultado:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
