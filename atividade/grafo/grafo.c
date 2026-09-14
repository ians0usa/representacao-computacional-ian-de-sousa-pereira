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

    bool matrizOk = inserirArestaMatriz(g->matrizAdj, origem, destino);

    No *novoNo = criarNo(destino);
    if (novoNo == NULL) {
        return false;
    }

    novoNo->proximo = g->listaAdj[origem];
    g->listaAdj[origem] = novoNo;

    return matrizOk;
}

bool existeAresta(Grafo *g, int origem, int destino) {
    if (g == NULL || origem < 0 || origem >= MAX_VERTICES || destino < 0 || destino >= MAX_VERTICES) { return false; }

    return existeArestaMatriz(g->matrizAdj, origem, destino);
}

void destruirGrafo(Grafo *g) {
    if (g == NULL) { return; }

    destruirListaAdj(g->listaAdj);

    free(g);
}