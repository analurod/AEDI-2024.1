/* strstr - Recebe: Uma string fonte. Uma string para comparação.

Retorna: Retorna um ponteiro para o primeiro caractere da ocorrência caso a subsequência ‘comparacao’ seja encontrada na string ‘fonte’. Caso a string ‘comparacao’ não esteja presente na string ‘fonte’, um ponteiro NULL é retornado. */

#include <stdio.h>
#include <string.h>

void compara(char *texto, char *palavra){
  char *ponteiro, *copia = texto;
  int encontrou = 0;

  // Procura todas as ocorrências da palavra no texto (utilizado a função strstr)
  while ((ponteiro = strstr(copia, palavra)) != NULL) {
    
      // Calcula a posição da ocorrência
      printf("%ld ", ponteiro - texto);
      copia += ((ponteiro - texto) + strlen(palavra)); // Move o ponteiro para a próxima busca
      encontrou = 1; // Se encontrou atualiza o encontrou
  }

  if (encontrou == 0) { // Caso não tenha encontrado
      printf("-1");
  }

  printf("\n");
}

int main(){
  char texto[10001], palavra[50];
  int quant, tam;

  scanf("%[^\n]", texto);

  // Verifica condição
  tam = strlen(texto);
  if(tam < 50 || tam > 10000){
    return -1;
  }
  
  scanf("%d", &quant);

  // Verifica condição
  if(quant < 1 || quant > 128){
    return -1;
  }

  for(int i = 0; i < quant; i++){
    scanf("%s", palavra);

    // Verifica condição
    tam = strlen(palavra);
    if(tam < 2 || tam > 50){
      return -1;
    }
    
    compara(texto, palavra);
  }
  

  return 0;
}