#include <stdio.h>
#include <string.h>

struct Aluno {
    int matricula;
    char nome[80];
    float nota1;
    float nota2;
    float nota3;
    float media;
};

int main() {
    int size = 5;
    struct Aluno alunos[size];
    int i;
    float maiorNota1 = -1, maiorMedia = -1, menorMedia = 11;
    int indexMaiorNota1 = -1, indexMaiorMedia = -1, indexMenorMedia = -1;

    // (a)
    for (i = 0; i < size; i++) {
        printf("Informe os dados do aluno %d:\n", i + 1);
        printf("Matrícula: ");
        scanf("%d", &alunos[i].matricula);
        getchar();
        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        printf("Nota da primeira prova: ");
        scanf("%f", &alunos[i].nota1);
        printf("Nota da segunda prova: ");
        scanf("%f", &alunos[i].nota2);
        printf("Nota da terceira prova: ");
        scanf("%f", &alunos[i].nota3);
        
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;

        // (b)
        if (alunos[i].nota1 > maiorNota1) {
            maiorNota1 = alunos[i].nota1;
            indexMaiorNota1 = i;
        }

        // (c)
        if (alunos[i].media > maiorMedia) {
            maiorMedia = alunos[i].media;
            indexMaiorMedia = i;
        }

        // (d)
        if (alunos[i].media < menorMedia) {
            menorMedia = alunos[i].media;
            indexMenorMedia = i;
        }
    }

    printf("\nAluno com maior nota na primeira prova:\n");
    printf("Matrícula: %d, Nome: %s, Nota 1: %.2f\n", alunos[indexMaiorNota1].matricula, alunos[indexMaiorNota1].nome, alunos[indexMaiorNota1].nota1);

    printf("\nAluno com maior média geral:\n");
    printf("Matrícula: %d, Nome: %s, Média: %.2f\n", alunos[indexMaiorMedia].matricula, alunos[indexMaiorMedia].nome, alunos[indexMaiorMedia].media);

    printf("\nAluno com menor média geral:\n");
    printf("Matrícula: %d, Nome: %s, Média: %.2f\n", alunos[indexMenorMedia].matricula, alunos[indexMenorMedia].nome, alunos[indexMenorMedia].media);

    // (e)=
    printf("\nStatus de aprovação/reprovação:\n");
    for (i = 0; i < size; i++) {
        if (alunos[i].media >= 6) {
            printf("Aluno: %s, Matrícula: %d, Aprovado com média: %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].media);
        } else {
            printf("Aluno: %s, Matrícula: %d, Reprovado com média: %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].media);
        }
    }

    return 0;
}
