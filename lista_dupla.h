#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

typedef struct No {
    int valor;
    struct No* anterior;
    struct No* proximo;
} No;

typedef struct {
    No* cabeca;
    No* cauda;
    int tamanho;
} ListaDupla;

// Inicialização
void inicializarLista(ListaDupla* l);

// Inserções
void inserirInicio(ListaDupla* l, int valor);
void inserirFim(ListaDupla* l, int valor);
void inserirPosicao(ListaDupla* l, int posicao, int valor);

// Remoções
void removerInicio(ListaDupla* l);
void removerFim(ListaDupla* l);
void removerPosicao(ListaDupla* l, int posicao);
void removerPorValor(ListaDupla* l, int valor);

// Exibição
void exibirFrente(ListaDupla* l);
void exibirTras(ListaDupla* l);

// Busca
int buscar(ListaDupla* l, int valor);

// Liberação
void destruirLista(ListaDupla* l);

#endif
