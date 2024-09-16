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

void bfs(Grafo *g, int inicio, int *dist) {
    int visitado[MAX];

    for(int i = 0; i < MAX; i++){
        visitado[i] = 0; 
        dist[i] = 0;
    }
    
    int fila[MAX];
    int frente = 0, traseira = 0;

    // Começa com o vértice inicial
    fila[traseira++] = inicio;
    visitado[inicio] = 1;
    dist[inicio] = 0;
    
    while (frente < traseira) {
        int u = fila[frente++];
        
        pVert aux;
        for (aux = g->adj[u]; aux != NULL; aux = aux->prox) {
            int v = aux->vert;
            if (!visitado[v]) {
                visitado[v] = 1;
                fila[traseira++] = v;
                dist[v] = dist[u] + 1; // Atualiza a distância para o vértice v
            }
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

    int dist[MAX];
    bfs(g, 0, dist); // Executa BFS a partir do vértice 0

    printf("Distâncias mínimas a partir do vértice 0:\n");
    for (int i = 0; i < g->v; i++) {
        printf("Distância do vértice 0 ao vértice %d: %d\n", i, dist[i]);
    }

    liberaGrafo(g);

    return 0;
}