#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elemento {
    int atual;
    struct elemento* proximo;
} Elemento;

typedef Elemento* Lista;

Lista* criarLista();
Lista* concatenarListas(Lista* lista1, Lista* lista2);
int gerarElementosLista(Lista* lista, int tamanho);
int inserirElementoFimLista(Lista* lista, int numero);
void printarLista(Lista* lista);

int main() {
    srand(time(NULL));

    Lista* lista1 = criarLista();
    if (lista1 == NULL) {
        printf("lista could not be created");
        return 1;
    }

    gerarElementosLista(lista1, 10);

    printf("Lista 1: ");
    printarLista(lista1);

    Lista* lista2 = criarLista();
    if (lista2 == NULL) {
        printf("lista could not be created");
        return 1;
    }

    gerarElementosLista(lista2, 10);

    printf("Lista 2: ");
    printarLista(lista2);

    Lista* lista3 = concatenarListas(lista1, lista2);

    printf("Lista 3: ");
    printarLista(lista3);

    return 0;
}

Lista* criarLista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if (*lista != NULL) {
        *lista = NULL;
    }
    return lista;
}

int gerarElementosLista(Lista* lista, int tamanho) {
    int x = 0;
    for (x = 0; x <= tamanho; x++) {
        int numero = rand() % 1000;
        if (inserirElementoFimLista(lista, numero) != 1) {
            printf("error: could not insert item on the edge of the list");
            return 0;
        }
    }
}

int inserirElementoFimLista(Lista* lista, int numero) {
    if (lista == NULL) {
        return 0;
    }
    
    Elemento* elem = (Elemento*) malloc(sizeof(Elemento));
    if (elem == NULL) {
        return 0;
    }
    elem->atual = numero;
    elem->proximo = NULL;

    if (*lista == NULL) {
        *lista = elem;
        return 1;
    }

    Elemento* aux = *lista;
    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }
    aux->proximo = elem;
    return 1;
}

void printarLista(Lista* lista) {
    Elemento* aux = *lista;
    while (aux->proximo != NULL) {
        printf("%d ", aux->atual);
        aux = aux->proximo;
    }
    printf("\n");
}

Lista* concatenarListas(Lista* lista1, Lista* lista2) {
    Lista* lista3 = criarLista();
    *lista3 = *lista1;
    Elemento* aux = *lista3;
    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }
    aux->proximo = *lista2;
    return lista3;
}
