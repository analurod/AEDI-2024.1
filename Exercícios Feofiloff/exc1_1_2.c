/* Exc 1.1.2
Escreva a documentação correta da função abaixo.
*/

/*A função recebe um vetor, um inteiro n (tamanho do vetor) e um inteiro x
e retorna a posição que o x se encontra no vetor. Caso não seja encontrado,
retorna o tamanho do vetor
*/
int onde(int x, int v[], int n){
    int j=0;
    while (j<n && v[j] != x){
        j+=1;
    }
    return j;
}