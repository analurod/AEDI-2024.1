#include <stdio.h>
#include <stdlib.h>

typedef struct caixa{
  int velocidade, tempo;
  struct caixa *prox;
} Caixa;

typedef struct cliente{
  int itens;
  struct cliente *prox;
} Cliente;

typedef Caixa *Pcaixa;
typedef Cliente *Pcliente, *inicio, *fim;

// Cria fila de caixas/funcionários
Pcaixa cria_caixa(){
  Pcaixa fila = (Caixa*)malloc(sizeof(Caixa));
  fila->prox=NULL;

 return fila;
}

// Cria fila de clientes
Pcliente cria_cliente(){
  Pcliente cliente = (Cliente*)malloc(sizeof(Cliente));
    cliente->prox=NULL;

   return cliente;
}

void forma_caixa(Pcaixa fila, int v){
  Pcaixa no = (Caixa*)malloc(sizeof(Caixa));
  Pcaixa aux;

  for(aux = fila; aux->prox != NULL; aux= aux->prox); // Acha o último

  aux->prox = no;
  no->velocidade = v;
  no->tempo = 0;
  no->prox=NULL;
}

void clientes(Pcliente cl, int v){
  Pcliente no = (Cliente*)malloc(sizeof(Cliente));
  Pcliente aux;
  int indice;

  for(indice = 0, aux = cl; aux->prox != NULL; aux= aux->prox, indice++); // Acha o último

  aux->prox = no;
  no->itens = v;
  no->prox=NULL;
}

void passar_compras(Pcliente cl, Pcaixa fila) {
    Pcliente aux2 = cl->prox; // Começa com o primeiro cliente na fila

    while (aux2 != NULL) { // Itera sobre todos os clientes
        Pcaixa menor_tempo_caixa = fila->prox;
        Pcaixa aux = fila->prox;

        // Encontrar a caixa com o menor tempo acumulado
        while (aux != NULL) {
            if (aux->tempo < menor_tempo_caixa->tempo) {
                menor_tempo_caixa = aux;
            }
            aux = aux->prox;
        }

        // Atualiza o tempo da caixa escolhida
        menor_tempo_caixa->tempo += aux2->itens * menor_tempo_caixa->velocidade;
        aux2 = aux2->prox; // Passa para o próximo cliente
    }
}

int maior_tempo(Pcliente cl, Pcaixa fila){
  int maior = 0;
  Pcaixa aux;

  for(aux = fila->prox; aux != NULL; aux= aux->prox){
    if(maior < aux->tempo){
      maior = aux-> tempo;
    }
  }


  return maior;
}

void libera(Pcliente cl, Pcaixa fila){
  Pcliente aux, lixo = cl;
  Pcaixa aux2, lixo2 = fila;
  
  while(lixo!= NULL){
    aux = lixo->prox;
    free(lixo);
    lixo=aux;
  }

  while(lixo2!= NULL){
    aux2 = lixo2->prox;
    free(lixo2);
    lixo2=aux2;
  }
  
}

int main(void) {
  int cliente, caixa, ler, cont = 0, maior;
  Pcaixa cx = cria_caixa();
  Pcliente cl = cria_cliente();

  // Leitura de quantidade de clientes e caixas
  scanf("%d %d", &caixa, &cliente);

  // Verificação 
  if(caixa < 1 || caixa > cliente || cliente > 10000){
      return -1;
  }

  for(int i = 0; i < caixa; i++){
    scanf("%d", &ler);
    forma_caixa(cx, ler);
  }

  for(int i = 0; i < cliente; i++){
    scanf("%d", &ler);
    clientes(cl, ler);
  }

  passar_compras(cl, cx);
  maior = maior_tempo(cl, cx);
  
  printf("%d\n", maior);

  libera(cl, cx);

  
  return 0;
}