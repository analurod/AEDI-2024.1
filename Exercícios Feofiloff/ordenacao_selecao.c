// Tempo de execução O(n²) no pior caso - lento para n grandes

/*O algoritmo de seleção divide o vetor em duas partes: uma parte já ordenada e outra não ordenada.
A cada iteração, encontra o menor elemento da parte não ordenada e o coloca na próxima posição da parte ordenada.
O processo é repetido até que toda a parte não ordenada seja movida para a parte ordenada, resultando em um vetor completamente ordenado.*/

// A função recebe um vetor v de tamanho n e o ordena em ordem crescente utilizando o algoritmo de ordenação por seleção.
void selecao(int n, int v[]) {
    int i, j, min, temp;

    // Loop para percorrer cada elemento do vetor, exceto o último
    for (i = 0; i < n - 1; i++) {
        // Assume que o primeiro elemento não ordenado é o menor
        min = i;

        // Loop para encontrar o menor elemento na parte não ordenada do vetor
        for (j = i + 1; j < n; j++) {
            // Se encontrar um elemento menor, atualiza a posição do menor
            if (v[j] < v[min]) {
                min = j;
            }
        }

        // Troca o elemento atual (v[i]) com o menor encontrado na parte não ordenada
        temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}
