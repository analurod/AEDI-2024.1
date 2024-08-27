#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilhano {
    char valor;
    struct pilhano *prox;
} pilhaNo;

// Função para empilhar uma carta no topo da pilha
void push(pilhaNo **topo, int carta) {
    pilhaNo* novo = (pilhaNo*) malloc(sizeof(pilhaNo));
    if (novo == NULL) {
        exit(1);  // Falha na alocação de memória
    }
    novo->valor = carta;
    novo->prox = *topo;
    *topo = novo;
}

// Função para remover uma carta do topo da pilha
int pop(pilhaNo **topo) {
    if (*topo == NULL) {
        return -1;  // Pilha vazia
    }
    pilhaNo *aux = *topo;
    int valor = aux->valor;
    *topo = aux->prox;
    free(aux);
    return valor;
}

// Função para "empilhar" uma carta na base da pilha
void push_base(pilhaNo **topo, int base) {
    pilhaNo* novo = (pilhaNo*) malloc(sizeof(pilhaNo));
    novo->valor = base;
    novo->prox = NULL;

    if (*topo == NULL) {
        *topo = novo;
    } else {
        pilhaNo *aux = *topo;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

// Função que descarta e move cartas
void descarta(pilhaNo **topo) {
    printf("Discarded cards: ");

    // Enquanto tiver pelo menos 2 cartas na pilha
    while (*topo != NULL && (*topo)->prox != NULL) {
        int descartada = pop(topo);

        if(*topo != NULL && (*topo)->prox != NULL){
            printf("%d, ", descartada);  // Imprime as cartas descartadas
        }
        else{
            printf("%d\n", descartada); // Impressão diferenciada para última carta
        }

        int base = pop(topo);  // Remove a carta do topo
        push_base(topo, base);  // Coloca a carta no final da pilha
    }
}

int main() {
    int cartas;

    while (1) {
        scanf("%d", &cartas);

        if (cartas == 0) {
            break;  // Sai do loop se o número de cartas for 0
        }

        pilhaNo *topo = NULL;

        // Empilha as cartas na pilha, começando do maior para o menor (para deixar o 1 inicialmente no topo)
        for (int i = cartas; i > 0; i--) {
            push(&topo, i);
        }

        descarta(&topo);

        // Imprime a carta restante
        if (topo != NULL) {
            printf("Remaining card: %d\n", topo->valor);
        }

        // Libera a memória da pilha
        while (topo != NULL) {
            pop(&topo);
        }
    }

    return 0;
}
