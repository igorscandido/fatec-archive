#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int main() {
    int matriz[LINHAS][COLUNAS] = {0};
    int linha, coluna, valor;

    printf("Digite os índices da linha e da coluna e o valor (ou índices negativos para sair):\n");

    while (1) {
        printf("Linha (-1 para sair): ");
        scanf("%d", &linha);
        if (linha < 0) break;

        printf("Coluna (-1 para sair): ");
        scanf("%d", &coluna);
        if (coluna < 0) break;

        if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS) {
            printf("Valor: ");
            scanf("%d", &valor);
            matriz[linha][coluna] = valor;
        } else {
            printf("Índices fora do limite da matriz. Tente novamente.\n");
        }
    }

    printf("\nMatriz:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
