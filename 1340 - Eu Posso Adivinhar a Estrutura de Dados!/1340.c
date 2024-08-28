/*
Pilha (Stack):
push (empilha) e pop (desempilha). O último elemento adicionado deve ser o primeiro a ser removido (LIFO - Last In, First Out).

Fila (Queue):
 enqueue (enfileira) e dequeue (desenfileira). O primeiro elemento adicionado deve ser o primeiro a ser removido (FIFO - First In, First Out).

Fila de Prioridade (Priority Queue):
insert (insere) e removeMax (remove o máximo). O elemento com a maior prioridade (ou o maior valor) deve ser removido primeiro.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Estrutura para a Pilha (Stack)
typedef struct {
    int dados[MAX_SIZE];
    int topo;
} Pilha;

// Estrutura para a Fila (Queue)
typedef struct {
    int dados[MAX_SIZE];
    int prim;
    int ultm;
} Fila;

// Estrutura para a Fila de Prioridade (Priority Queue)
typedef struct {
    int dados[MAX_SIZE];
    int tamanho;
} FilaPrioridade;

// Inicializa uma pilha
void inicializaPilha(Pilha* p) {
    p->topo = -1;
}

// Adiciona um elemento na pilha
void empilha(Pilha* p, int valor) {
    if (p->topo < MAX_SIZE - 1) {
        p->dados[++(p->topo)] = valor;
    }
}

// Remove o elemento do topo da pilha e retorna seu valor
int desempilha(Pilha* p) {
    if (p->topo >= 0) {
        return p->dados[(p->topo)--];
    }
    return -1; // Erro: pilha vazia
}

// Retorna o valor do topo da pilha sem removê-lo
int topoPilha(Pilha* p) {
    if (p->topo >= 0) {
        return p->dados[p->topo];
    }
    return -1; // Erro: pilha vazia
}

// Verifica se a pilha está vazia
bool pilhaVazia(Pilha* p) {
    return p->topo == -1;
}

// Inicializa uma fila
void inicializaFila(Fila* f) {
    f->prim = 0;
    f->ultm = -1;
}

// Adiciona um elemento na fila
void enfileira(Fila* f, int valor) {
    if (f->ultm < MAX_SIZE - 1) {
        f->dados[++(f->ultm)] = valor;
    }
}

// Remove o elemento da frente da fila e retorna seu valor
int desenfileira(Fila* f) {
    if (f->prim <= f->ultm) {
        return f->dados[(f->prim)++];
    }
    return -1; // Erro: fila vazia
}

// Retorna o valor do elemento da frente da fila sem removê-lo
int frenteFila(Fila* f) {
    if (f->prim <= f->ultm) {
        return f->dados[f->prim];
    }
    return -1; // Erro: fila vazia
}

// Verifica se a fila está vazia
bool filaVazia(Fila* f) {
    return f->prim > f->ultm;
}

// Inicializa uma fila de prioridade
void inicializaFilaPrioridade(FilaPrioridade* fp) {
    fp->tamanho = 0;
}

// Adiciona um elemento na fila de prioridade
void insereFilaPrioridade(FilaPrioridade* fp, int valor) {
    if (fp->tamanho < MAX_SIZE) {
        int i = fp->tamanho++;
        fp->dados[i] = valor;
        // Reorganiza para manter a propriedade da fila de prioridade
        while (i > 0) {
            int pai = (i - 1) / 2;
            if (fp->dados[pai] < fp->dados[i]) {
                int temp = fp->dados[pai];
                fp->dados[pai] = fp->dados[i];
                fp->dados[i] = temp;
                i = pai;
            } else {
                break;
            }
        }
    }
}

// Remove e retorna o maior valor da fila de prioridade
int removeMaxFilaPrioridade(FilaPrioridade* fp) {
    if (fp->tamanho > 0) {
        int max = fp->dados[0];
        fp->dados[0] = fp->dados[--(fp->tamanho)];
        int i = 0;
        // Reorganiza para manter a propriedade da fila de prioridade
        while (i * 2 + 1 < fp->tamanho) {
            int filho = i * 2 + 1;
            if (filho + 1 < fp->tamanho && fp->dados[filho] < fp->dados[filho + 1]) {
                filho++;
            }
            if (fp->dados[i] < fp->dados[filho]) {
                int temp = fp->dados[i];
                fp->dados[i] = fp->dados[filho];
                fp->dados[filho] = temp;
                i = filho;
            } else {
                break;
            }
        }
        return max;
    }
    return -1; // Erro: fila de prioridade vazia
}

// Retorna o maior valor da fila de prioridade sem removê-lo
int maxFilaPrioridade(FilaPrioridade* fp) {
    if (fp->tamanho > 0) {
        return fp->dados[0];
    }
    return -1; // Erro: fila de prioridade vazia
}

// Verifica se a fila de prioridade está vazia
bool filaPrioridadeVazia(FilaPrioridade* fp) {
    return fp->tamanho == 0;
}

int main() {
    Pilha pilha;
    Fila fila;
    FilaPrioridade filaPrioridade;

    int n, operacao, numero;
    bool ehPilha, ehFila, ehFilaPrioridade;

    // Lê a quantidade de operações
    while (scanf("%d", &n) != EOF) {
        inicializaPilha(&pilha);
        inicializaFila(&fila);
        inicializaFilaPrioridade(&filaPrioridade);

        // Define flags como true para indicar que as estruturas ainda podem corresponder às operações fornecidas
        ehPilha = true;
        ehFila = true;
        ehFilaPrioridade = true;

        // Processa cada operação
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &operacao, &numero);

            // Inserir
            if (operacao == 1) {
                if (ehPilha) {
                    empilha(&pilha, numero);
                }
                if (ehFila) {
                    enfileira(&fila, numero);
                }
                if (ehFilaPrioridade) {
                    insereFilaPrioridade(&filaPrioridade, numero);
                }
            } 
            // Remove
            else {
                if (ehPilha) {
                    if (pilhaVazia(&pilha) || topoPilha(&pilha) != numero) {
                        ehPilha = false;
                    } else {
                        desempilha(&pilha);
                    }
                }

                if (ehFila) {
                    if (filaVazia(&fila) || frenteFila(&fila) != numero) {
                        ehFila = false;
                    } else {
                        desenfileira(&fila);
                    }
                }

                if (ehFilaPrioridade) {
                    if (filaPrioridadeVazia(&filaPrioridade) || maxFilaPrioridade(&filaPrioridade) != numero) {
                        ehFilaPrioridade = false;
                    } else {
                        removeMaxFilaPrioridade(&filaPrioridade);
                    }
                }
            }
        }

        // Determina e imprime o tipo de estrutura de dados
        if (ehPilha && !ehFila && !ehFilaPrioridade) {
            printf("stack\n");
        } else if (!ehPilha && ehFila && !ehFilaPrioridade) {
            printf("queue\n");
        } else if (!ehPilha && !ehFila && ehFilaPrioridade) {
            printf("priority queue\n");
        } else if (!ehPilha && !ehFila && !ehFilaPrioridade) {
            printf("impossible\n");
        } else {
            printf("not sure\n");
        }
    }

    return 0;
}
