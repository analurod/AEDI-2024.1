#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int ident;
    struct no *prox;
} No;

typedef No *pNo;

typedef struct fila {
    No *inicio, *fim;
} Fila;

// Cria uma nova fila
Fila *cria() {
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    if (fila == NULL) {
        exit(1);
    }
    fila->inicio = fila->fim = NULL;
    return fila;
}

// Insere um elemento na fila
void insere(Fila *fila, int num) {
    pNo novo = (No*)malloc(sizeof(No));
    novo->ident = num;
    novo->prox = NULL;

    if (fila->fim == NULL) {
        fila->inicio = fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

// Remove um elemento específico da fila
void retira(Fila *fila, int num) {
    if (fila->inicio == NULL) {
        return;
    }

    pNo aux = fila->inicio;
    pNo prev = NULL;

    // Caso especial: o elemento a ser removido está no início da fila
    if (aux != NULL && aux->ident == num) {
        fila->inicio = aux->prox;
        if (fila->inicio == NULL) {
            fila->fim = NULL;  // A fila está vazia
        }
        free(aux);
        return;
    }

    // Procura pelo elemento na fila
    while (aux != NULL && aux->ident != num) {
        prev = aux;
        aux = aux->prox;
    }

    // Se o elemento não for encontrado
    if (aux == NULL) {
        return;
    }

    // Remove o nó do meio ou do final da fila
    prev->prox = aux->prox;
    if (aux == fila->fim) {
        fila->fim = prev;  // Atualiza o fim se necessário
    }
    free(aux);
}

// Imprime todos os elementos da fila
void imprime(Fila *fila) {
    pNo aux = fila->inicio;

    if (aux == NULL) {
        return;
    }

    while (aux != NULL) {
        if(aux->prox==NULL){
            printf("%d\n", aux->ident);
        }
        else{
            printf("%d ", aux->ident);
        }
        aux = aux->prox;
    }
}

// Libera a memória da fila
void libera(Fila *fila) {
    No* atual = fila->inicio;
    No* prox;

    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }

    free(fila);
}

int main() {
    int insereCount, removeCount, ident;
    Fila *fila;

    scanf("%d", &insereCount);

    fila = cria();

    for (int i = 0; i < insereCount; i++) {
        scanf("%d", &ident);
        insere(fila, ident);
    }

    scanf("%d", &removeCount);

    for (int i = 0; i < removeCount; i++) {
        scanf("%d", &ident);
        retira(fila, ident);
    }

    imprime(fila);
    libera(fila);

    return 0;
}
