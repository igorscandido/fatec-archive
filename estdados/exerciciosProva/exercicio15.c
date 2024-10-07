#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 10
#define COLUNAS 5
#define DISCIPLINAS 5

typedef struct disciplina {
    int codigo;
    int cargaHoraria;
} Disciplina;

typedef struct avaliacao {
    float p1;
    float p2;
    float media;
    Disciplina disciplina;
} Avaliacao;

typedef struct aluno {
    int codigo;
    int idade;
    Avaliacao avaliacoes[DISCIPLINAS];
} Aluno;

void preencher_matriz(int matriz[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = rand() % 101;
        }
    }
}

void mostrar_matriz(int matriz[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int soma_matriz(int matriz[LINHAS][COLUNAS]) {
    int soma = 0;
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            soma += matriz[i][j];
        }
    }
    return soma;
}

float media_matriz(int matriz[LINHAS][COLUNAS]) {
    return (float)soma_matriz(matriz) / (LINHAS * COLUNAS);
}

int procurar_valor(int matriz[LINHAS][COLUNAS], int valor) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (matriz[i][j] == valor) {
                return valor;
            }
        }
    }
    return -1;
}

void gerar_dados_alunos(Aluno alunos[LINHAS]) {
    for (int i = 0; i < LINHAS; i++) {
        alunos[i].codigo = i + 1;
        alunos[i].idade = rand() % 30 + 20;
        for (int j = 0; j < DISCIPLINAS; j++) {
            alunos[i].avaliacoes[j].disciplina.codigo = rand() % 500 + 1;
            alunos[i].avaliacoes[j].disciplina.cargaHoraria = rand() % 6 + 1;
            alunos[i].avaliacoes[j].p1 = (float)(rand() % 101) / 10;
            alunos[i].avaliacoes[j].p2 = (float)(rand() % 101) / 10;
            alunos[i].avaliacoes[j].media = (alunos[i].avaliacoes[j].p1 + alunos[i].avaliacoes[j].p2) / 2;
        }
    }
}

void exibir_dados_alunos(Aluno alunos[LINHAS]) {
    for (int i = 0; i < LINHAS; i++) {
        printf("Aluno: %d Idade: %d\n", alunos[i].codigo, alunos[i].idade);
        printf("-------------------------------\n");
        printf("Disciplinas\n");
        printf("-------------------------------\n");
        printf("Cod  c.hor  p1  p2  media\n");
        for (int j = 0; j < DISCIPLINAS; j++) {
            printf("%-3d %-6d %-3.1f %-3.1f %-3.1f\n", 
                alunos[i].avaliacoes[j].disciplina.codigo,
                alunos[i].avaliacoes[j].disciplina.cargaHoraria,
                alunos[i].avaliacoes[j].p1,
                alunos[i].avaliacoes[j].p2,
                alunos[i].avaliacoes[j].media);
        }
        printf("-------------------------------\n");
    }
}

float media_geral(Aluno alunos[LINHAS]) {
    float soma_total = 0;
    int total_avaliacoes = 0;

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < DISCIPLINAS; j++) {
            soma_total += alunos[i].avaliacoes[j].media;
            total_avaliacoes++;
        }
    }
    return soma_total / total_avaliacoes;
}

int main() {
    srand(time(NULL));

    int matriz[LINHAS][COLUNAS];
    Aluno alunos[LINHAS];

    preencher_matriz(matriz);
    printf("Matriz:\n");
    mostrar_matriz(matriz);
    printf("Soma da matriz: %d\n", soma_matriz(matriz));
    printf("Média da matriz: %.2f\n", media_matriz(matriz));

    int valor_procurado;
    printf("Digite um valor para procurar na matriz: ");
    scanf("%d", &valor_procurado);
    int resultado = procurar_valor(matriz, valor_procurado);
    if (resultado != -1) {
        printf("Valor %d encontrado na matriz.\n", resultado);
    } else {
        printf("Valor %d não encontrado na matriz.\n", valor_procurado);
    }

    gerar_dados_alunos(alunos);
    exibir_dados_alunos(alunos);
    
    float mediaSala = media_geral(alunos);
    printf("Média geral da sala: %.2f\n", mediaSala);

    return 0;
}
