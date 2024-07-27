/* PROBLEMA 1013
Faça um programa que leia três valores e apresente o maior dos três valores lidos seguido da mensagem “eh o maior”. 

Entrada
O arquivo de entrada contém três valores inteiros.

Saída
Imprima o maior dos três valores seguido por um espaço e a mensagem "eh o maior".
*/

#include <stdio.h>

int main() {
    int a[3],  maior=-20000;
    
    for(int i=0; i<3; i++){
        scanf("%d", &a[i]);
        if(a[i]>maior){
            maior=a[i];
        }
    }
    
    printf("%d eh o maior\n", maior);
    
    
    
    return 0;
}