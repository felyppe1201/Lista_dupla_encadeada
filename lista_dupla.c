#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

void inicializarLista(ListaDupla* l) {
    l->cabeca = NULL;
    l->cauda = NULL;
    l->tamanho = 0;
}

void inserirInicio(ListaDupla* l, int valor) {
    No* novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = l->cabeca;
    if (l->cabeca)
        l->cabeca->anterior = novo;
    else
        l->cauda = novo;
    l->cabeca = novo;
    l->tamanho++;
}

void inserirFim(ListaDupla* l, int valor) {
    No* novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = l->cauda;
    if (l->cauda)
        l->cauda->proximo = novo;
    else
        l->cabeca = novo;
    l->cauda = novo;
    l->tamanho++;
}

void inserirPosicao(ListaDupla* l, int posicao, int valor) {
    if (posicao <= 0) {
        inserirInicio(l, valor);
    } else if (posicao >= l->tamanho) {
        inserirFim(l, valor);
    } else {
        No* atual = l->cabeca;
        for (int i = 0; i < posicao - 1; i++)
            atual = atual->proximo;

        No* novo = malloc(sizeof(No));
        novo->valor = valor;
        novo->proximo = atual->proximo;
        novo->anterior = atual;
        atual->proximo->anterior = novo;
        atual->proximo = novo;
        l->tamanho++;
    }
}

void removerInicio(ListaDupla* l) {
    if (!l->cabeca) return;
    No* temp = l->cabeca;
    l->cabeca = temp->proximo;
    if (l->cabeca)
        l->cabeca->anterior = NULL;
    else
        l->cauda = NULL;
    free(temp);
    l->tamanho--;
}

void removerFim(ListaDupla* l) {
    if (!l->cauda) return;
    No* temp = l->cauda;
    l->cauda = temp->anterior;
    if (l->cauda)
        l->cauda->proximo = NULL;
    else
        l->cabeca = NULL;
    free(temp);
    l->tamanho--;
}

void removerPosicao(ListaDupla* l, int posicao) {
    if (posicao < 0 || posicao >= l->tamanho) return;
    if (posicao == 0) {
        removerInicio(l);
    } else if (posicao == l->tamanho - 1) {
        removerFim(l);
    } else {
        No* atual = l->cabeca;
        for (int i = 0; i < posicao; i++)
            atual = atual->proximo;
        atual->anterior->proximo = atual->proximo;
        atual->proximo->anterior = atual->anterior;
        free(atual);
        l->tamanho--;
    }
}

void removerPorValor(ListaDupla* l, int valor) {
    No* atual = l->cabeca;
    while (atual) {
        if (atual->valor == valor) {
            if (atual->anterior)
                atual->anterior->proximo = atual->proximo;
            else
                l->cabeca = atual->proximo;
            if (atual->proximo)
                atual->proximo->anterior = atual->anterior;
            else
                l->cauda = atual->anterior;
            free(atual);
            l->tamanho--;
            return;
        }
        atual = atual->proximo;
    }
}

void exibirFrente(ListaDupla* l) {
    No* atual = l->cabeca;
    printf("Frente: ");
    while (atual) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void exibirTras(ListaDupla* l) {
    No* atual = l->cauda;
    printf("Trás: ");
    while (atual) {
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }
    printf("\n");
}

int buscar(ListaDupla* l, int valor) {
    No* atual = l->cabeca;
    while (atual) {
        if (atual->valor == valor)
            return 1;
        atual = atual->proximo;
    }
    return 0;
}

void destruirLista(ListaDupla* l) {
    No* atual = l->cabeca;
    while (atual) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    l->cabeca = NULL;
    l->cauda = NULL;
    l->tamanho = 0;
}
