/* PROBLEMA 1029
Quase todo estudante de Ciência da Computação recebe em algum momento no início de seu curso de graduação algum problema envolvendo a sequência de Fibonacci. Tal sequência tem como os dois primeiros valores 0 (zero) e 1 (um) e cada próximo valor será sempre a soma dos dois valores imediatamente anteriores. Por definição, podemos apresentar a seguinte fórmula para encontrar qualquer número da sequência de Fibonacci:
fib(0) = 0
fib(1) = 1
fib(n) = fib(n-1) + fib(n-2);

Uma das formas de encontrar o número de Fibonacci é através de chamadas recursivas.

Desta forma,
fib(4) = 1+0+1+1+0 = 3
Foram feitas 8 calls, ou seja, 8 chamadas recursivas.
Entrada
A primeira linha da entrada contém um único inteiro N, indicando o número de casos de teste. Cada caso de teste contém um inteiro X (1 ≤ X ≤ 39) .

Saída
Para cada caso de teste de entrada deverá ser apresentada uma linha de saída, no seguinte formato: fib(n) = num_calls calls = result, aonde num_calls é o número de chamadas recursivas, tendo sempre um espaço antes e depois do sinal de igualdade, conforme o exemplo abaixo.
*/

#include <stdio.h>

// Variável global para contar o número de chamadas recursivas
int num_calls;

// Função recursiva para calcular o valor de Fibonacci e contar chamadas
int fibonacci(int n) {
    num_calls++; // Contar a chamada recursiva

    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int N, X;
    
    // Ler o número de casos de teste
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        // Ler o valor de X para o caso de teste
        scanf("%d", &X);
        
        // Resetar o contador de chamadas
        num_calls = -1;
        
        // Calcular o valor de Fibonacci para X
        int result = fibonacci(X);
        
        // Imprimir o resultado formatado
        printf("fib(%d) = %d calls = %d\n", X, num_calls, result);
    }

    return 0;
}
