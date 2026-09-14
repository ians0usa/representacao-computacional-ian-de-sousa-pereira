#include "grafo.h"
#include <stdlib.h>

Grafo *criarGrafo() {
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));

    if (g == NULL) { return NULL; }

    inicializarMatrizAdj(g->matrizAdj);
    inicializarListaAdj(g->listaAdj);

    return g;
}

bool inserirAresta(Grafo *g, int origem, int destino) {
    if (g == NULL || origem < 0 || origem >= MAX_VERTICES || destino < 0 || destino >= MAX_VERTICES) { return false; }

    No *novoNo = criarNo(destino);
    if (novoNo == NULL) { return false; }

    bool matrizOk = inserirArestaMatriz(g->matrizAdj, origem, destino);
    if (!matrizOk) {
        free(novoNo);
        return false;
    }

    novoNo->proximo = g->listaAdj[origem];
    g->listaAdj[origem] = novoNo;

    return true;
}

bool existeAresta(Grafo *g, int origem, int destino) {
    if (g == NULL || origem < 0 || origem >= MAX_VERTICES || destino < 0 || destino >= MAX_VERTICES) { return false; }

    return existeArestaMatriz(g->matrizAdj, origem, destino);
}

void destruirGrafo(Grafo *g) {
    if (g == NULL) { return; }

    for (int i = 0; i < MAX_VERTICES; i++) {
        No *atual = g->listaAdj[i];

        while (atual != NULL) {
            No *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }

    free(g);
}