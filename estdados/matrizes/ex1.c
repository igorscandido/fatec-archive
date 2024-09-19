#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int matr[6][6];
    int l, c, soma;
    soma=0;
    for (l = 0;l<6;l++) {
        printf("|");
        for (c = 0;c<6;c++) {
            matr[l][c] = rand() % 100;
            if (l == c) {
                printf(" %2d |",matr[l][c]);
                soma += matr[l][c];
            } else {
                printf("  |");
            }
        }
        printf("\n\n");
    }
    printf("Soma da diagonal principal: %2d\n", soma);

    return 0;
}