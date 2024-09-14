// Tempo de execução O(n²) no pior caso - lento para n grandes


// A função recebe um vetor v de tamanho e n e ordena de forma crescente
void insercao(int n, int v[]) {
    int i, j, x;
    for(j = 1; j < n; j++) {  // Loop externo que percorre o vetor a partir do segundo elemento
        x = v[j];    // O valor do elemento atual a ser inserido
        for(i = j - 1; i >= 0 && v[i] > x; i--) { // Loop interno que procura a posição correta para o valor 'x'
            v[i + 1] = v[i]; // Move o elemento atual uma posição para a frente
        }
        v[i + 1] = x;   // Insere o valor 'x' na posição correta
    }
}
