#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 6

typedef struct{
    int vert;
    struct no *prox;
} Vertice;

typedef Vertice *pVert;

typedef struct{
    int v;
    int a;
    pVert *adj;
} Grafo;

typedef struct {
    int items[MAX];
    int inicio, fim;
} Fila;

void inicializaFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
}

bool filaVazia(Fila *f) {
    return f->fim < f->inicio;
}

void enfileira(Fila *f, int valor) {
    if (f->fim < MAX - 1) {
        f->items[++f->fim] = valor;
    }
}

int desenfileira(Fila *f) {
    if (!filaVazia(f)) {
        return f->items[f->inicio++];
    }
    return -1; // Fila vazia
}

Grafo *inicializa(int V){
    Grafo *g = (Grafo*) malloc (sizeof (Grafo));
    
    g->v= V;
    g->a=0;
    g->adj = (pVert*) malloc (V * sizeof (pVert));

    for(int i = 0; i < V; i++){
        g->adj[i] = NULL;
    }

    return g;
}

void insereAresta(Grafo *g, int a, int b){
    pVert novo = (Vertice*) malloc (sizeof (Vertice));

    novo->vert = b; // Define o vértice de destino da aresta
    novo->prox = g->adj[a];  // Faz o novo nó apontar para a lista existente

    g->adj[a] = novo; // Atualiza a lista de adjacência de v
    g->a++; // Incrementa o número de arestas
}



void liberaGrafo(Grafo *g) {
    for (int v = 0; v < g->v; v++) {
        pVert atual = g->adj[v];
        while (atual != NULL) {
            pVert temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(g->adj);
    free(g);
}

void bfs(Grafo *g, int inicio) {
    int visitado[MAX] = {0}; 
    Fila fila; // Gerencia os vértices já visitados
    inicializaFila(&fila); 
    
    visitado[inicio] = 1; // Marcar o vértice inicial como visitado
    enfileira(&fila, inicio); // Adiciona o vertice inicial na fila
    
    // Enquanto houver vértices na fila
    while (!filaVazia(&fila)) {
        int vert = desenfileira(&fila); // Remove o vértice da frente da fila para ser visitado
        printf("Vértice visitado: %d\n", vert);
        
        pVert adj = g->adj[vert]; // Acessa a lista de adjacência do vértice removido

        // Itera sobre todos os vizinhos do vértice
        while (adj != NULL) {
            if (visitado[adj->vert] == 0) { 
                visitado[adj->vert] = 1; 
                enfileira(&fila, adj->vert); // Adiciona o vizinho na fila
            }
            adj = adj->prox; // Passa para o próximo vizinho
        }
    }
}

int main(){
    Grafo *g = inicializa(MAX);

    insereAresta(g, 0, 1);
    insereAresta(g, 1, 2);
    insereAresta(g, 1, 3);
    insereAresta(g, 3, 4);
    insereAresta(g, 2, 5);

    printf("Resultado da BFS a partir do vértice 1:\n");
    bfs(g, 1);


    liberaGrafo(g);

    return 0;
}