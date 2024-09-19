#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencher(int m[5][5]);
void mostrar(int m[5][5]);
void copiar(int m[5][5], int n[5][5]);

int main() {
    srand(time(NULL));
    int matriz[5][5];
    preencher(matriz);
    mostrar(matriz);
    int copia[5][5];
    copiar(matriz, copia);
    printf("\n\n");
    mostrar(copia);
}

void preencher(int m[5][5]) {
    int i;
    for (i = 0; i < 5; i++) {
        int j;
        for (j = 0; j < 5; j++) {
            m[i][j] = rand() % 99;
        } 
    }
}

void mostrar(int m[5][5]) {
    int i;
    for (i = 0; i < 5; i++) {
        int j;
        for (j = 0; j < 5; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void copiar(int m[5][5], int n[5][5]) {
    int i;
    for (i = 0; i < 5; i++) {
        int j;
        for (j = 0; j < 5; j++) {
            n[i][j] = m[i][j];
        }
    }
}
