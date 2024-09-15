/* Exc 4.7.1
Escreva uma função de um vetor para lista.
*/

#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista encadeada
typedef struct no {
    int valor;
    struct no *prox;
} No;

// Função recebe o valor de um elemento do vetor v, cria um novo nó e aloca na lista
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo != NULL) {
        novo->valor = valor;
        novo->prox = NULL;
    }
    return novo;
}

// Função recebe um vetor v de tamanho n e cópia todos os seus elementos para uma lista
No* copiarParaLista(int v[], int n) {
    if (n == 0) return NULL;  // Se o vetor estiver vazio, retorna NULL

    No *inicio = criarNo(v[0]);  // Cria o primeiro nó
    No *atual = inicio;

    for (int i = 1; i < n; i++) {
        atual->prox = criarNo(v[i]);  // Cria um novo nó para cada elemento do vetor
        atual = atual->prox;          // Avança para o próximo nó
    }

    return inicio;  // Retorna o ponteiro para o início da lista
}