#include <stdio.h>

int main() {
    double mat1[2][3], mat2[2][3], soma[2][3];
    
    printf("Digite os itens da primeira matriz:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &mat1[i][j]);
        }
    }

    printf("Digite os itens da segunda matriz:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &mat2[i][j]);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            soma[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf("A soma das matrizes é:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", soma[i][j]);
        }
        printf("\n");
    }

    return 0;
}
