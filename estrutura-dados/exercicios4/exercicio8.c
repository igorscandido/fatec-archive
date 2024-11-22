#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISCIPLINAS 5

struct disciplina {
    int codigo;
    int cargaHoraria;
};

typedef struct disciplina Disciplina;

struct avaliacao {
    float p1;
    float p2;
    float media;
    Disciplina disciplina;
};

typedef struct avaliacao Avaliacao;

struct aluno {
    int codigo;
    int idade;
    Avaliacao avaliacoes[MAX_DISCIPLINAS];
};

typedef struct aluno Aluno;

void gerarAluno(Aluno* a, int codigoAluno);
void exibirAluno(Aluno* a);
float calcularMediaGeralSala(Aluno alunos[], int size);

int main() {
    int size = 5;
    srand(time(NULL));

    Aluno alunos[size];

    for (int i = 0; i < size; i++) {
        gerarAluno(&alunos[i], i + 1);
    }
    
    for (int i = 0; i < size; i++) {
        exibirAluno(&alunos[i]);
    }

    float mediaGeral = calcularMediaGeralSala(alunos, size);
    printf("Média geral: %.2f\n", mediaGeral);
    
    return 0;
}

void gerarAluno(Aluno* a, int codigoAluno) {
    a->codigo = codigoAluno;
    a->idade = (rand() % 10) + 18;
    
    for (int i = 0; i < MAX_DISCIPLINAS; i++) {
        a->avaliacoes[i].disciplina.codigo = rand() % 500 + 1;
        a->avaliacoes[i].disciplina.cargaHoraria = rand() % 6 + 1;
        
        a->avaliacoes[i].p1 = rand() % 11;
        a->avaliacoes[i].p2 = rand() % 11;
        a->avaliacoes[i].media = (a->avaliacoes[i].p1 + a->avaliacoes[i].p2) / 2;
    }
}

void exibirAluno(Aluno* a) {
    printf("Aluno: %d Idade %d\n", a->codigo, a->idade);
    printf("-------------------------------\n");
    printf("Disciplinas\n");
    printf("-------------------------------\n");
    printf("Cod c. hor p1 p2 media\n");
    
    for (int i = 0; i < MAX_DISCIPLINAS; i++) {
        printf("%d %d %.1f %.1f %.1f\n", a->avaliacoes[i].disciplina.codigo, 
            a->avaliacoes[i].disciplina.cargaHoraria,
            a->avaliacoes[i].p1, a->avaliacoes[i].p2, a->avaliacoes[i].media);
    }
    printf("-------------------------------\n");
}

float calcularMediaGeralSala(Aluno alunos[], int size) {
    float somaMedias = 0;
    int totalAvaliacoes = size * MAX_DISCIPLINAS;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < MAX_DISCIPLINAS; j++) {
            somaMedias += alunos[i].avaliacoes[j].media;
        }
    }
    
    return somaMedias / totalAvaliacoes;
}