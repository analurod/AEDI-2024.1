#include <stdio.h>
#include <stdlib.h>

#define MAX 6

typedef struct no{
    int vert;
    struct no *prox;
} Vertice;

typedef Vertice *pVert;

typedef struct grafo{
    int v;
    int a;
    pVert *adj;
} Grafo;

int ordem[MAX], cont = 0;

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

void dfs(Grafo *g, int v){
    pVert aux;
    ordem[v] = cont++;

    for(aux = g->adj[v]; aux != NULL; aux = aux ->prox){
        int temp = aux->vert;
        if(ordem[temp] == -1){
            dfs(g, temp);
        }
    }
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

int main(){
    Grafo *g = inicializa(MAX);

    insereAresta(g, 0, 1);
    insereAresta(g, 1, 2);
    insereAresta(g, 1, 3);
    insereAresta(g, 2, 4);
    insereAresta(g, 2, 5);

    for(int i = 0; i < MAX; i++){
        ordem[i] = -1;
    }

    // Executa DFS para todos os vértices para garantir a cobertura total
    for (int i = 0; i < MAX; i++) {
        if (ordem[i] == -1) {  // Se o vértice ainda não foi visitado
            dfs(g, i);
        }
    }

    printf("Ordem de descoberta: ");
    for (int i = 0; i < MAX; i++) {
        if (ordem[i] != -1)  // Verifica se o vértice foi descoberto
            printf("Vértice %d: Ordem %d\n", i, ordem[i]);
    }
    printf("\n");

    liberaGrafo(g);

    return 0;
}