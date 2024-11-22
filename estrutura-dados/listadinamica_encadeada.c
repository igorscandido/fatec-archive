#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct aluno {
  int matricula;
  char* nome[30];
  float nota1;
  float nota2;
  float nota3;
} Aluno;

typedef struct elemento {
  Aluno dados;
  Aluno* proximo;
} Elemento;

typedef Elemento* Lista;

Lista* criarLista();
int inserirNoFim(Lista *lista, Aluno novoAluno);
void exibirElementos(Lista *lista);

int main(int argc, char * argv[]) {
  Lista* lista = criarLista();
  Aluno alunoNovo;
  strcpy(alunoNovo.nome, "Igor");
  inserirNoFim(lista, alunoNovo);
  strcpy(alunoNovo.nome, "Marcos");
  inserirNoFim(lista, alunoNovo);
  exibirElementos(lista);
  return 0;
}

Lista* criarLista() {
  Lista* lista = (Lista*) malloc(sizeof(Lista));
  if (lista != NULL) {
    *lista = NULL;
  }
  return lista;
}

int inserirNoFim(Lista *lista, Aluno novoAluno) {
  if (lista == NULL) {
    return 0;
  }
  Elemento *elemento = (Elemento*) malloc(sizeof(Elemento));
  if (elemento == NULL) {
    return 0;
  }
  elemento->dados = novoAluno;
  if (*lista == NULL) {
    *lista = elemento;
  } else {
    Elemento *aux = *lista;
    while(aux->proximo != NULL) {
      aux = aux->proximo;
    }
    aux->proximo = elemento;
  }
}

void exibirElementos(Lista *lista) {
  Elemento* aux = *lista;
  while (aux != NULL) {
    printf("%s\n",aux->dados.nome);
    aux = aux->proximo;
  }
}
