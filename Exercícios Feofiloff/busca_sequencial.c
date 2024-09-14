// Vetor ordenado - Busca Sequencial

/*A função recebe um vetor de tamanho n e um inteiro x.
Se x é um elemento de v a função retorna a possição, caso não seja retorna o tamanho do vetor*/
int BuscaSequencial(int x, int n, int v[]){
    int j=0;

    while (j < n && v[j] < x){
        j++;
    }

    return j;
})