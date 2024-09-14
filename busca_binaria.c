// Busca Binária

// Tem tempo de excução O(log^n)

#include <stdio.h>


/*A função recebe um vetor de tamanho n e um inteiro x.
Se x é um elemento de v a função retorna a possição, caso não seja retorna o tamanho do vetor*/
int buscaBinaria(int x, int n, int v[]) {
    int esq = -1;  
    int dir = n; 
    int meio;

    while (esq < dir - 1) {  // Enquanto os índices forem válidos
        meio = (esq + dir) / 2;  // Calcula o meio do vetor

        if (v[meio] < x) {  // Se o valor do meio for menor que x
            esq = meio;  // Olha na parte superior do vetor
        } else {  // Caso contrário
            dir = meio;  // Olha na parte inferior do vetor
        }
    }

    return dir;  // Retorna -1 se o valor não estiver presente
}

int main(){
    int vetor[]={1,2,3,4,5,6,7,8,9,100}, x, pos;

    scanf("%d", &x);

    pos = buscaBinaria(x, 10, vetor);

    printf("\n %d", pos);
    return 0;
}