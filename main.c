#include <stdio.h>
#include "lista_dupla.h"

int main() {
    ListaDupla l;
    inicializarLista(&l);

    // Inserções
    inserirInicio(&l, 10);
    inserirFim(&l, 30);
    inserirPosicao(&l, 1, 20);
    inserirFim(&l, 40);
    inserirPosicao(&l, 2, 25);

    printf("Depois das inserções:\n");
    exibirFrente(&l);
    exibirTras(&l);

    // Remoções
    removerInicio(&l);
    removerFim(&l);
    removerPosicao(&l, 1);
    removerPorValor(&l, 30);
    printf("\nDepois das remoções:\n");
    exibirFrente(&l);
    exibirTras(&l);

    // Busca
    printf("\nBuscar 20: %s\n", buscar(&l, 20) ? "Encontrado" : "Não encontrado");
    printf("Buscar 99: %s\n", buscar(&l, 99) ? "Encontrado" : "Não encontrado");

    destruirLista(&l);
    return 0;
}
