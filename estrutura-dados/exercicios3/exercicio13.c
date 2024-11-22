#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elemento {
    int atual;
    struct elemento* proximo;
} Elemento;

typedef Elemento* Lista;

Lista* criarLista();
int gerarElementosLista(Lista* lista, int tamanho);
int inserirElementoFimLista(Lista* lista, int numero);
void printarLista(Lista* lista);
float calcularMedia(Lista* lista);

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

    float media = calcularMedia(lista);
    printf("A média dos valores da lista é: %.2f\n", media);

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

int contarPares(Lista* lista) {
    int contador = 0;
    Elemento* atual = *lista;
    while (atual != NULL) {
        if (atual->atual % 2 == 0) {
            contador++;
        }
        atual = atual->proximo;
    }
    return contador;
}

float calcularMedia(Lista* lista) {
    if (*lista == NULL) {
        return 0; // Lista vazia
    }

    int soma = 0;
    int count = 0;
    Elemento* corrente = *lista;
    while (corrente != NULL) {
        soma += corrente->atual;
        count++;
        corrente = corrente->proximo;
    }

    return (float)soma / count;
}
