/* EXC 2.2.2
Critique a função abaixo. Ela promete encontrar o valor de um elemento máximo de v[0..n-1].
*/

// Apesar do código cumprir o objetivo de achar o máximo em um vetor, ele executa muitas chamadas recursivas e tem muitas condições, tudo isso poderia ser simplificado tornando o código mais eficiente

#include <stdio.h> 
#include <string.h>

int maximoR1(int v[], int n){
  int x;
  if(n==1){
    return v[0];
  }
  if(n==2){
    if(v[0] < v[1]){
      return v[0];
    }
    else{
      return maximoR1(v, n-1);
    }
  }
  x = maximoR1(v, n-1);
  if(x < v[n-1]){
    return v[n-1];
  }
  else{
    return x;
  }
}

