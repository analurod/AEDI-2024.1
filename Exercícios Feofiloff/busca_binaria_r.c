// Busca Binária Recursiva

// Tempo de execução O(log^n)

/*A função recebe um vetor de tamanho n e um inteiro x.
Se x é um elemento de v a função retorna a possição, caso não seja retorna o tamanho do vetor*/
int BuscaBináriaRec(int x, int esq, int dir, int v[]){
    if (esq == dir-1){
        return dir;
    }
    else{
        int meio = (esq+dir)/2;
        if(v[meio] < x){
            return BuscaBináriaRec(x, meio, dir, v);
        }
        else{
            return BuscaBináriaRec(x, esq, meio, v);
        }
    }
}