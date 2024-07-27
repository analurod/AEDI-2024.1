/* PROBLEMA 1022
A tarefa aqui neste problema é ler uma expressão matemática na forma de dois números Racionais (numerador / denominador) e apresentar o resultado da operação. Cada operando ou operador é separado por um espaço em branco. A sequência de cada linha que contém a expressão a ser lida é: número, caractere, número, caractere, número, caractere, número. A resposta deverá ser apresentada e posteriormente simplificada. Deverá então ser apresentado o sinal de igualdade e em seguida a resposta simplificada. No caso de não ser possível uma simplificação, deve ser apresentada a mesma resposta após o sinal de igualdade.

Considerando N1 e D1 como numerador e denominador da primeira fração, segue a orientação de como deverá ser realizada cada uma das operações:
Soma: (N1*D2 + N2*D1) / (D1*D2)
Subtração: (N1*D2 - N2*D1) / (D1*D2)
Multiplicação: (N1*N2) / (D1*D2)
Divisão: (N1/D1) / (N2/D2), ou seja (N1*D2)/(N2*D1)
Entrada
A entrada contem vários casos de teste. A primeira linha de cada caso de teste contem um inteiro N (1 ≤ N ≤ 1*104), indicando a quantidade de casos de teste que devem ser lidos logo a seguir. Cada caso de teste contém um valor racional X (1 ≤ X ≤ 1000), uma operação (-, +, * ou /) e outro valor racional Y (1 ≤ Y ≤ 1000).

Saída
A saída consiste em um valor racional, seguido de um sinal de igualdade e outro valor racional, que é a simplificação do primeiro valor. No caso do primeiro valor não poder ser simplificado, o mesmo deve ser repetido após o sinal de igualdade.
*/

#include <stdio.h>
#include <stdlib.h>

/* Função recebe a "expressão" digitada e retorna o resultado
sem simplificar */
void calcula(int numero[], char caracter[], int *numerador, int *denominador){
  
  switch (caracter[1]){
    
    case '+':
      *denominador = numero[1] * numero[3];
      *numerador = numero[3]*numero[0] + numero[1]*numero[2];
    break;

    case '-':
      *denominador = numero[1] * numero[3];
      *numerador = numero[3]*numero[0] - numero[1]*numero[2];
    break;

    case '*':
      *denominador = numero[1] * numero[3];
      *numerador = numero[0] * numero[2];
    break;

    case '/':
      *numerador = numero[3]* numero[0];
      *denominador = numero[1] * numero[2];
    break;
  } 
}

/* Função recebe o numerador e denominador e calcula 
o MDC utilizando "Algoritmo de Euclides" */
int mdc(int numA, int numB){

  

  // Se o resto for 0 o dividendo é o MDC;
  if(numB == 0){
    return abs(numA); // MDC sempre positivo
  }

  // Caso o resto seja diferente de zero repete o processo de divisão e substituição
  return mdc(numB, numA % numB);
}

int main() {

   int casos, numero[4], numerador, denominador, divisor;
   char caracter[3];
  

   scanf("%d", &casos);

   if(casos < 1 && casos > 10000){
       return 1;
   }

    for(int i = 0; i < casos; i++){
      scanf("%d %c %d %c %d %c %d", &numero[0], &caracter[0], &numero[1], &caracter[1], &numero[2], &caracter[2], &numero[3]);

      // "Tratamento" para caso os denominadores sejam zero
      if(numero[1] == 0 || numero[3] == 0){
        printf("ERRO! Os denominadores devem ser diferentes de zero!");
        return 1;
      }

      calcula(numero, caracter, &numerador, &denominador);

      divisor = mdc(numerador, denominador);
      

      printf("%d/%d = %d/%d\n", numerador, denominador, numerador/divisor, denominador/divisor);
    }

    return 0;
}