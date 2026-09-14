#include "lista.h"
#include <stdlib.h>

No *criarNo(int vertice) {

    No *novoNo = (No *)malloc(sizeof(No));

    if (novoNo == NULL) { return NULL; }

    novoNo->vertice = vertice;
    novoNo->proximo = NULL;

    return novoNo;
}

void inicializarListaAdj(No *lista[]) {

    for (int i = 0; i < MAX_VERTICES; i++) {
        lista[i] = NULL;
    }
}

void destruirListaAdj(No **lista) {

    if (lista == NULL) { return; }

    for (int i = 0; i < MAX_VERTICES; i++) {

        No *atual = lista[i];
        
        while (atual != NULL) {

            No *proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
        lista[i] = NULL;
    }
}