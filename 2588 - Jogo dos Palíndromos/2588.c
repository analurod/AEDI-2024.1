#include <stdio.h>
#include <string.h>

int main() {

    int c[200];        
    int i, ans;        
    char string[1010]; 

    // Loop para ler strings da entrada padrão até o fim do arquivo
    while (scanf("%s", string) != EOF) {

        i = 0; 
        memset(c, 0, sizeof(c)); // Zera o array de contagem

        // Conta a frequência de cada caractere na string - Utilizando o código ASCII para incrementar 
        while (string[i])
            c[string[i++]]++;

        ans = 0; // IContador de caracteres com frequência ímpar
        
        // Verifica cada posição do array de contagem 
        for (i = 0; i < 200; ++i){
            if (c[i] & 1){ //Compara bit a bit (&) e retorna 1 caso seja impar
                ++ans;   
            }
        }

        printf("%d\n", ans <= 1 ? 0 : ans - 1);

    }

    return 0;
}