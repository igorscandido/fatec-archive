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
int trocarElementos(Lista* lista, int posicao1, int posicao2);
void printarLista(Lista* lista);

int main() {
    srand(time(NULL));

    Lista* lista = criarLista();
    if (lista == NULL) {
        printf("lista could not be created");
        return 1;
    }

    gerarElementosLista(lista, 10);

    printf("Lista: ");
    printarLista(lista);

    if (trocarElementos(lista, 2, 5)) {
        printf("Elementos trocados com sucesso.\n");
    } else {
        printf("Erro ao trocar elementos.\n");
    }

    printf("Lista trocada: ");
    printarLista(lista);

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

int trocarElementos(Lista* lista, int posicao1, int posicao2) {
    if (lista == NULL || posicao1 < 0 || posicao2 < 0) {
        return 0;
    }

    Elemento* atual = *lista;
    Elemento* anterior1 = NULL, *anterior2 = NULL, *no1 = NULL, *no2 = NULL;
    int i = 0;

    while (atual != NULL) {
        if (i == posicao1) {
            no1 = atual;
        } else if (i == posicao2) {
            no2 = atual;
        }
        if (i == posicao1 - 1) {
            anterior1 = atual;
        } else if (i == posicao2 - 1) {
            anterior2 = atual;
        }
        atual = atual->proximo;
        i++;
    }

    if (no1 == NULL || no2 == NULL) {
        return 0;
    }

    if (anterior1 != NULL) {
        anterior1->proximo = no2;
    } else {
        *lista = no2;
    }

    if (anterior2 != NULL) {
        anterior2->proximo = no1;
    } else {
        if (anterior1 == NULL) {
            *lista = no1;
        } else {
            anterior2->proximo = no1;
        }
    }

    Elemento* temp = no1->proximo;
    no1->proximo = no2->proximo;
    no2->proximo = temp;

    return 1;
}