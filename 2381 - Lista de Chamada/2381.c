#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura
struct aluno{
    char aluno[21]; 
    struct aluno *prox;
};
typedef struct aluno Alunos; 

// Função que cria lista COM cabeça
Alunos *cria(){
  Alunos *lista = (Alunos *) malloc (sizeof(Alunos));

  //Se não foi possível alocar memória
  if(lista == NULL){
    exit(1);
  }

  lista->prox = NULL; //inicializa lista

  return lista;
}

/* Função recebe a lista atual e o nome a ser inserido,
cria uma nova celúla e insere o novo nome no coeço da lista*/
void insere(Alunos *lista, char *nome){
  Alunos *nova = (Alunos *) malloc (sizeof(Alunos));

  if(nova == NULL){
    exit(1);
  } //Se não foi possível alocar memória

  strcpy(nova->aluno, nome);
  nova->prox = lista->prox;
  lista->prox = nova;
}

/* Função recebe a lista desordenada e 
ordena o nome dos alunos em ordem alfabetica*/
void ordenar(Alunos **pLista){

  //Se a lista estiver vazia ou com apenas um elemento não tem o que ordenar
  if((*pLista)->prox == NULL || ((*pLista)->prox)->prox == NULL){
    return;
  }

  Alunos *aux = *pLista, *aux2;

  char temp_nome[21]; //Armazena o nome durante a troca

  //Loop percorre lista
  while(aux != NULL) {
      aux2 = aux->prox;

      //Loop percorre comparação lista
      while(aux2 != NULL) {

        //Se o anteior (aux) for "maior" trocam de lugar
          if(strcmp(aux->aluno, aux2->aluno) > 0) {
            strcpy(temp_nome, aux->aluno);
            strcpy(aux->aluno, aux2->aluno);
            strcpy(aux2->aluno, temp_nome);
          }
          aux2 = aux2->prox;
      }
      aux = aux->prox;
  }
}

/* Função recebe a lista já ordenada e o número de chamada 
que foi sorteado, encontra o respectivo aluno e imprime seu nome*/
void acha_imprime(Alunos *lista, int sorteado) {
  Alunos *aux;
  aux = lista->prox;

    // Enquanto o número atual não for o sorteado continua procurando o aluno
    for(int i = 1; i < sorteado; i++){
        aux = aux->prox;
    }

  printf ("%s\n", aux->aluno);
}

//Recebe a lista e libera a memória alocada
void libera(Alunos *lista) {
    Alunos *aux;

    while(lista->prox != NULL){
      aux = lista->prox;
      lista->prox = aux->prox;
      free(aux);
    }
}


int main() {
    int quant, sorteado;
    char nome[21];
    Alunos *lista = cria();

    scanf("%d %d", &quant, &sorteado);

    for(int i = 0; i < quant; i++){
        scanf("%s", nome);
        insere(lista, nome);
    }

    ordenar(&lista);

    acha_imprime(lista, sorteado);

    libera(lista);
    free(lista);

    return 0;
}