#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct produto {
    int codProd;
    float valor;
    int qtdeEstoque;
} Produto;

typedef struct elemento {
    Produto produto;
    struct elemento* proximo;
} Elemento;

typedef Elemento* Lista;

Lista* criarLista() {
    Lista lista = NULL;
    return &lista;
}

void inserirFim(Lista* lista, Produto produto) {
    Elemento* novo = malloc(sizeof(Elemento));
    novo->produto = produto;
    novo->proximo = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        Elemento* aux = *lista;
        while (aux->proximo) {
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}

Produto* maisBarato(Lista lista) {
    if (lista == NULL) {
        return NULL;
    }

    Produto* maisBarato = &lista->produto;
    while (lista) {
        if (lista->produto.valor < maisBarato->valor) {
            maisBarato = &lista->produto;
        }
        lista = lista->proximo;
    }
    return maisBarato;
}

void imprimirLista(Lista lista) {
    while (lista) {
        printf("Código: %d, Valor: R$%.2f, Estoque: %d\n", 
               lista->produto.codProd, 
               lista->produto.valor, 
               lista->produto.qtdeEstoque);
        lista = lista->proximo;
    }
}

int main() {
    srand(time(NULL));
    Lista lista = NULL;

    for (int i = 0; i < 10; i++) {
        Produto p = {i+1, (float)rand() / RAND_MAX * 100, rand() % 100};
        inserirFim(&lista, p);
    }

    printf("Lista de produtos:\n");
    imprimirLista(lista);

    Produto* pbarato = maisBarato(lista);
    printf("\nProduto mais barato:\n");
    printf("Código: %d, Valor: R$%.2f\n", pbarato->codProd, pbarato->valor);

    return 0;
}