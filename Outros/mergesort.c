// Tempo de execução O(n*log^n)

/* "dividir e conquistar" - Divide repetidamente um vetor em subvetores menores,
ordena essas partes e combina as partes ordenadas*/

#include <stdio.h>
#include <stdlib.h>

/* Função para mesclar dois subvetores ordenados de um vetor em um único subvetor ordenado.
  A função recebe um vetor `v` e os índices `p`, `q`, e `r` onde:
  - `v[p..q-1]` é o primeiro subvetor (ordenado)
  - `v[q..r-1]` é o segundo subvetor (ordenado)
  A função mescla os dois subvetores e coloca o resultado no intervalo `v[p..r-1]`. */
void Intercala(int p, int q, int r, int v[]) {
    int i, j, k;
    int *w;
    
    // Aloca memória para o vetor temporário 'w' que armazenará a mescla dos subvetores.
    w = malloc((r - p) * sizeof(int));
    
    // Verifica se a alocação foi bem-sucedida
    if (w == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    // Índices para percorrer os subvetores e o vetor temporário
    i = p;  // Índice para o primeiro subvetor
    j = q;  // Índice para o segundo subvetor
    k = 0;  // Índice para o vetor temporário 'w'
    
    // Mescla os dois subvetores enquanto há elementos em ambos
    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            w[k++] = v[j++];
        }
    }
    
    // Copia os elementos restantes do primeiro subvetor, se houver
    while (i < q) {
        w[k++] = v[i++];
    }
    
    // Copia os elementos restantes do segundo subvetor, se houver
    while (j < r) {
        w[k++] = v[j++];
    }
    
    // Copia os elementos do vetor temporário 'w' de volta para o vetor original 'v'
    for (i = p; i < r; i++) {
        v[i] = w[i - p];
    }
    
    // Libera a memória alocada para 'w'
    free(w);
}

/* Função recursiva para ordenar um vetor usando o algoritmo MergeSort. 
 O vetor é dividido recursivamente em dois subvetores, e em seguida
 os subvetores são ordenados e mesclados para formar o vetor final ordenado.*/
void Mergesort(int p, int r, int v[]) {
    // Verifica se o subvetor tem mais de um elemento para continuar o processo de divisão
    if (p < r - 1) {
        // Calcula o ponto médio do subvetor
        int q = (p + r) / 2;

        // Chama recursivamente o Mergesort para o primeiro subvetor (v[p..q-1])
        Mergesort(p, q, v);

        // Chama recursivamente o Mergesort para o segundo subvetor (v[q..r-1])
        Mergesort(q, r, v);

        // Mescla os dois subvetores ordenados em um único subvetor ordenado
        Intercala(p, q, r, v);
    }
}

