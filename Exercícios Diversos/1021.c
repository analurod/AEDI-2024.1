/* PROBLEMA 1021
Leia um valor de ponto flutuante com duas casas decimais. Este valor representa um valor monetário. A seguir, calcule o menor número de notas e moedas possíveis no qual o valor pode ser decomposto. As notas consideradas são de 100, 50, 20, 10, 5, 2. As moedas possíveis são de 1, 0.50, 0.25, 0.10, 0.05 e 0.01. A seguir mostre a relação de notas necessárias.

Entrada
O arquivo de entrada contém um valor de ponto flutuante N (0 ≤ N ≤ 1000000.00).

Saída
Imprima a quantidade mínima de notas e moedas necessárias para trocar o valor inicial, conforme exemplo fornecido.

Obs: Utilize ponto (.) para separar a parte decimal. */

#include <stdio.h>

int main() {
    float valor;
    int notas, moedas, resto, centavos;

    scanf("%f", &valor);

    // Converte para centavos
    centavos = valor * 100;

    printf("NOTAS:\n");
    notas = centavos / 10000;
    printf("%d nota(s) de R$ 100.00\n", notas);
    resto = centavos % 10000;

    notas = resto / 5000;
    printf("%d nota(s) de R$ 50.00\n", notas);
    resto = resto % 5000;

    notas = resto / 2000;
    printf("%d nota(s) de R$ 20.00\n", notas);
    resto = resto % 2000;

    notas = resto / 1000;
    printf("%d nota(s) de R$ 10.00\n", notas);
    resto = resto % 1000;

    notas = resto / 500;
    printf("%d nota(s) de R$ 5.00\n", notas);
    resto = resto % 500;

    notas = resto / 200;
    printf("%d nota(s) de R$ 2.00\n", notas);
    resto = resto % 200;

    printf("MOEDAS:\n");
    moedas = resto / 100;
    printf("%d moeda(s) de R$ 1.00\n", moedas);
    resto = resto % 100;

    moedas = resto / 50;
    printf("%d moeda(s) de R$ 0.50\n", moedas);
    resto = resto % 50;

    moedas = resto / 25;
    printf("%d moeda(s) de R$ 0.25\n", moedas);
    resto = resto % 25;

    moedas = resto / 10;
    printf("%d moeda(s) de R$ 0.10\n", moedas);
    resto = resto % 10;

    moedas = resto / 5;
    printf("%d moeda(s) de R$ 0.05\n", moedas);
    resto = resto % 5;

    moedas = resto / 1;
    printf("%d moeda(s) de R$ 0.01\n", moedas);

    return 0;
}
