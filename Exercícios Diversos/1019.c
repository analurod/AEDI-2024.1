/* PROBLEMA 1019
Leia um valor inteiro, que é o tempo de duração em segundos de um determinado evento em uma fábrica, e informe-o expresso no formato horas:minutos:segundos.

Entrada
O arquivo de entrada contém um valor inteiro N.

Saída
Imprima o tempo lido no arquivo de entrada (segundos), convertido para horas:minutos:segundos, conforme exemplo fornecido.
*/

#include <stdio.h>

int main() {
 
    int tempo, segundos, minutos;

    scanf("%d", &tempo);

    minutos= tempo%3600;
    segundos = minutos%60;
    printf("%d:%d:%d\n", tempo/3600, minutos/60, segundos);
 
    return 0;
}