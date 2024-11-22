#include <stdio.h>

struct Aluno {
    char nome[100];
    int matricula;
    char curso[100];
};

int main() {
    int size = 5;
    struct Aluno alunos[size];

    for (int i = 0; i < size; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        getchar();
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

        printf("Digite o numero de matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);
        getchar();

        printf("Digite o curso do aluno %d: ", i + 1);
        fgets(alunos[i].curso, sizeof(alunos[i].curso), stdin);
    }

    printf("\nDados dos alunos:\n");
    for (int i = 0; i < size; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Curso: %s", alunos[i].curso);
    }

    return 0;
}
