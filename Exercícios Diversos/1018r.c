/* PROBLEMA 1018 - RECURSIVO
Leia um valor inteiro. A seguir, calcule o menor número de notas possíveis (cédulas) no qual o valor pode ser decomposto. As notas consideradas são de 100, 50, 20, 10, 5, 2 e 1. A seguir mostre o valor lido e a relação de notas necessárias.

Entrada
O arquivo de entrada contém um valor inteiro N (0 < N < 1000000).

Saída
Imprima o valor lido e, em seguida, a quantidade mínima de notas de cada tipo necessárias, conforme o exemplo fornecido. Não esqueça de imprimir o fim de linha após cada linha, caso contrário seu programa apresentará a mensagem: “Presentation Error”.
*/

#include <stdio.h>

void calcula_quantNotas(int valor, int notas[], int i) {
    if (valor < 0 || i >= 7) {
        return;
    }
    
    int qnotas = valor / notas[i];
    printf("%d nota(s) de R$ %d,00\n", qnotas, notas[i]);

    calcula_quantNotas(valor % notas[i], notas, i + 1);
}

int main() {
    int valor, i = 0;
    int notas[] = {100, 50, 20, 10, 5, 2, 1};

    scanf("%d", &valor);

    if (valor < 0 || valor > 1000000) {
        return 1;
    }

    printf("%d\n", valor);

    calcula_quantNotas(valor, notas, i);

    return 0;
}