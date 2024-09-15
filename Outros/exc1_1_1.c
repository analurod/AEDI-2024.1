/* Exc 1.1.1
Escreva a documentação correta da função abaixo.
*/

/* A função recebe um vetor v de tamanho n e retorna um inteiro com a 
soma de todos os elementos do vetor */
int soma(int n, int v[]){
    int i, x = 0;
    for(i = 0; i < n; i++){
        x+=v[i];
    }
    return x;
}