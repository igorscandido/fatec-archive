#include <stdio.h>

#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct aluno {
  int matricula;
  char nome[30];
  float nota1;
  float nota2;
  float nota3;
}
Aluno;

typedef struct elemento {
  Aluno dados;
  Aluno * proximo;
}
Elemento;

typedef Elemento * Lista;

Lista * criarLista();
void adicionarNaLista(Lista * lista, Lista * proximo);

int main(int argc, char * argv[]) {
  Lista * lista = criarLista();
  adicionarNaLista(lista, criarLista());
  printf("%p", lista);
  return 0;
}

Lista * criarLista() {
  Lista * lista = (Lista * ) malloc(sizeof(Lista));
  if (lista != NULL) {
    * lista = NULL;
  }
  return lista;
}

void adicionarNaLista(Lista * lista, Aluno novoAluno) {
  Lista * novo = criarLista()
  if (novo != NULL) {
    * novo.dados = proximo;
    novo -> proximo = lista;
    * lista = novo;
  }
}