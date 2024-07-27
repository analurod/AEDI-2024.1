/* PROBLEMA 1009
Faça um programa que leia o nome de um vendedor, o seu salário fixo e o total de vendas efetuadas por ele no mês (em dinheiro). Sabendo que este vendedor ganha 15% de comissão sobre suas vendas efetuadas, informar o total a receber no final do mês, com duas casas decimais.

Entrada
O arquivo de entrada contém um texto (primeiro nome do vendedor) e 2 valores de dupla precisão (double) com duas casas decimais, representando o salário fixo do vendedor e montante total das vendas efetuadas por este vendedor, respectivamente.

Saída
Imprima o total que o funcionário deverá receber, conforme exemplo fornecido.
*/

#include <stdio.h>

int main() {
    double valorFixo, montante, salario;
    char nomeVendedor[10];
    
    scanf("%s", nomeVendedor);
    scanf("%lf %lf", &valorFixo, &montante);
    
    salario = valorFixo + 0.15*montante;
    
    printf("TOTAL = R$ %.2lf\n", salario);
    
    return 0;
}