/* PROBLEMA 1024
A tarefa aqui neste problema é ler uma expressão matemática na forma de dois números Racionais (numerador / denominador) e apresentar o resultado da operação. Cada operando ou operador é separado por um espaço em branco. A sequência de cada linha que contém a expressão a ser lida é: número, caractere, número, caractere, número, caractere, número. A resposta deverá ser apresentada e posteriormente simplificada. Deverá então ser apresentado o sinal de igualdade e em seguida a resposta simplificada. No caso de não ser possível uma simplificação, deve ser apresentada a mesma resposta após o sinal de igualdade.

Considerando N1 e D1 como numerador e denominador da primeira fração, segue a orientação de como deverá ser realizada cada uma das operações:
Soma: (N1*D2 + N2*D1) / (D1*D2)
Subtração: (N1*D2 - N2*D1) / (D1*D2)
Multiplicação: (N1*N2) / (D1*D2)
Divisão: (N1/D1) / (N2/D2), ou seja (N1*D2)/(N2*D1)
Entrada
A entrada contem vários casos de teste. A primeira linha de cada caso de teste contem um inteiro N (1 ≤ N ≤ 1*104), indicando a quantidade de casos de teste que devem ser lidos logo a seguir. Cada caso de teste contém um valor racional X (1 ≤ X ≤ 1000), uma operação (-, +, * ou /) e outro valor racional Y (1 ≤ Y ≤ 1000).

Saída
A saída consiste em um valor racional, seguido de um sinal de igualdade e outro valor racional, que é a simplificação do primeiro valor. No caso do primeiro valor não poder ser simplificado, o mesmo deve ser repetido após o sinal de igualdade.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void codificando(char *texto) {
    int tam, meio;
    tam = strlen(texto);
    meio = tam / 2;

    // Alocar e inicializar o array codigo
    char *codigo = malloc((tam + 1) * sizeof(char));
    if (codigo == NULL) {
      exit(1);
    }

    // Codificar caracteres deslocando caracteres alfabéticos
    for (int i = 0; i < tam; i++) {
        if ((texto[i] >= 'a' && texto[i] <= 'z') || (texto[i] >= 'A' && texto[i] <= 'Z')) {
            codigo[i] = texto[i] + 3;
        } else {
            codigo[i] = texto[i];
        }
    }
    codigo[tam] = '\0'; // Terminar a string com nulo

    // Reverter a string codificada
    char *reverso = malloc((tam + 1) * sizeof(char));
    if (reverso == NULL) {
      free(codigo);
      exit(1);
    }
    for (int i = 0, j = tam - 1; i < tam; i++, j--) {
        reverso[i] = codigo[j];
    }
    reverso[tam] = '\0'; // Terminar a string revertida com nulo

    // Aplicar a transformação final
    for (int i = 0; i < tam; i++) {
        if (i < meio) {
            // Copiar a primeira metade como está
            codigo[i] = reverso[i];
        } else {
            // Deslocar caracteres da segunda metade por -1
            codigo[i] = reverso[i] - 1;
        }
    }
    codigo[tam] = '\0'; // Terminar a string final com nulo

    // Imprimir o resultado
    printf("%s\n", codigo);

    // Liberar memória alocada
    free(codigo);
    free(reverso);
}

int main() {
    int n;
    char mensagem[1001];

    scanf("%d", &n);
    getchar(); // Consumir o caractere de nova linha após a entrada do inteiro

    for (int i = 0; i < n; i++) {
        scanf("%[^\n]", mensagem);

        codificando(mensagem);
    }

    return 0;
}
