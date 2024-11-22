#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 60
#define NUM_APOSTAS 10
#define NUM_AZAR 6
#define NUM_NU 6

struct aposta {
    int concurso;
    int numerosAzar[NUM_AZAR];
    int apostas[NUM_APOSTAS][NUM_NU];
};

typedef struct aposta Aposta;

// (i)
int verificarNumero(int num, int numeros[], int tam);
void gerarApostas(Aposta* a);
void mostrarApostas(Aposta* a);
void numeroMaisApostado(Aposta* a);

int main() {
    srand(time(NULL));

    Aposta a;
    int i;

    // (a)
    printf("Informe o número do concurso: ");
    scanf("%d", &a.concurso);

    // (b)
    printf("Informe 6 números (entre 1 e 60): ");
    for (i = 0; i < NUM_AZAR; i++) {
        scanf("%d", &a.numerosAzar[i]);
    }

    // (c)
    gerarApostas(&a);

    // (d)
    mostrarApostas(&a);

    // (e)
    numeroMaisApostado(&a);

    return 0;
}

int verificarNumero(int num, int numeros[], int tam) {
    for (int i = 0; i < tam; i++) {
        if (numeros[i] == num) {
            return 1;
        }
    }
    return 0;
}

void gerarApostas(Aposta* a) {
    int numero;
    for (int i = 0; i < NUM_APOSTAS; i++) {
        for (int j = 0; j < NUM_NU; j++) {
            do {
                numero = (rand() % MAX_NUM) + 1;
            } while (verificarNumero(numero, a->numerosAzar, NUM_AZAR) || verificarNumero(numero, a->apostas[i], j));
            
            a->apostas[i][j] = numero;
        }
    }
}

void mostrarApostas(Aposta* a) {
    printf("Apostas geradas para o concurso %d:\n", a->concurso);
    for (int i = 0; i < NUM_APOSTAS; i++) {
        printf("Aposta %d: ", i + 1);
        for (int j = 0; j < NUM_NU; j++) {
            printf("%d ", a->apostas[i][j]);
        }
        printf("\n");
    }
}

void numeroMaisApostado(Aposta* a) {
    int contagem[MAX_NUM + 1] = {0};
    for (int i = 0; i < NUM_APOSTAS; i++) {
        for (int j = 0; j < NUM_NU; j++) {
            contagem[a->apostas[i][j]]++;
        }
    }

    int maisApostado = 0, maxApostas = 0;
    for (int i = 1; i <= MAX_NUM; i++) {
        if (contagem[i] > maxApostas) {
            maxApostas = contagem[i];
            maisApostado = i;
        }
    }

    printf("O número mais apostado no concurso %d foi o %d, com %d apostas.\n", a->concurso, maisApostado, maxApostas);
}
