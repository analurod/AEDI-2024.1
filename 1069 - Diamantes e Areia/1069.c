#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilhano{
    char valor;
    struct pilhano *prox;
} pilhaNo;

void push(pilhaNo **topo, char valor){
    pilhaNo* novo = (pilhaNo*) malloc(sizeof(pilhaNo));

    if(novo==NULL){
        exit(1);
    }

    novo->valor = valor;
    novo->prox = *topo;
    *topo = novo;
}

int pop(pilhaNo **topo){
    // Verifica se a pilha está vazia
    if (*topo == NULL) {
        return -1;
    }

    pilhaNo *aux = *topo;
    int pop = aux->valor;

    //Atualiza o topo
    *topo = (*topo)->prox;

    // Libera a memória do nó desempilhado
    free(aux);

    return pop;
}

void minerando(char *teste, pilhaNo **topo){
  int tam = strlen(teste), diamantes =0, conf;

    for(int i = 0; i < tam; i++){
      if(teste[i] == '<'){
        push(topo, teste[i]);
      }
      else if (teste[i] == '>'){
        conf = pop(topo);
        
        if(conf == '<'){
          diamantes ++;
        }
      }
    }
  
    printf("%d\n", diamantes);
}  


int main(){
  int n, tam;
  char teste[1001];
  pilhaNo *topo = NULL;

  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%s", teste);

    minerando(teste, &topo);

    // Loop para "limpar" tudo que tiver sobrado na pilha
    while(topo!= NULL){
      pop(&topo);
    }
  }

  return 0;
}