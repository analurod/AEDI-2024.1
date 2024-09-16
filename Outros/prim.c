#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Estrutura para representar uma lista de adjacência
typedef struct no {
    int vertice;
    int peso;
    struct no *prox;
} No;

typedef struct grafo {
    int V;
    No **adj;
} Grafo;

// Função para criar um novo nó
No* novoNo(int vertice, int peso) {
    No* novo = (No*) malloc(sizeof(No));
    novo->vertice = vertice;
    novo->peso = peso;
    novo->prox = NULL;
    return novo;
}

// Função para criar um grafo com V vértices
Grafo* criaGrafo(int V) {
    Grafo* g = (Grafo*) malloc(sizeof(Grafo));
    g->V = V;
    g->adj = (No**) malloc(V * sizeof(No*));

    for (int i = 0; i < V; i++)
        g->adj[i] = NULL;

    return g;
}

// Função para adicionar uma aresta no grafo
void adicionaAresta(Grafo* g, int u, int v, int peso) {
    No* novo = novoNo(v, peso);
    novo->prox = g->adj[u];
    g->adj[u] = novo;

    novo = novoNo(u, peso);
    novo->prox = g->adj[v];
    g->adj[v] = novo;
}

// Função para encontrar o vértice com a chave mínima
int chaveMinima(int key[], int inMST[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (inMST[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }

    return min_index;
}

// Algoritmo de Prim
void prim(Grafo* g) {
    int V = g->V;
    int parent[V];  // Array para armazenar a árvore geradora
    int key[V];     // Valores de pesos mínimos
    int inMST[V];   // inMST[i] será 1 se o vértice i estiver na AGM

    // Inicializa todos os valores de chave como infinito
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
    }

    // Sempre começa do primeiro vértice (0)
    key[0] = 0;
    parent[0] = -1;

    // A árvore terá V vértices
    for (int i = 0; i < V - 1; i++) {
        int u = chaveMinima(key, inMST, V);
        inMST[u] = 1;

        // Atualiza os valores de chave dos vértices adjacentes
        No* temp = g->adj[u];
        while (temp != NULL) {
            int v = temp->vertice;
            if (inMST[v] == 0 && temp->peso < key[v]) {
                parent[v] = u;
                key[v] = temp->peso;
            }
            temp = temp->prox;
        }
    }

    // Imprime a AGM
    printf("Arestas da Árvore Geradora Mínima:\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d\n", parent[i], i);
}

int main() {
    int V = 5;
    Grafo* g = criaGrafo(V);

    adicionaAresta(g, 0, 1, 2);
    adicionaAresta(g, 0, 3, 6);
    adicionaAresta(g, 1, 2, 3);
    adicionaAresta(g, 1, 3, 8);
    adicionaAresta(g, 1, 4, 5);
    adicionaAresta(g, 2, 4, 7);
    adicionaAresta(g, 3, 4, 9);

    prim(g);

    return 0;
}
