/* PROBLEMA 1016 - RECURSIVO
Dois carros (X e Y) partem em uma mesma direção. O carro X sai com velocidade constante de 60 Km/h e o carro Y sai com velocidade constante de 90 Km/h.

Em uma hora (60 minutos) o carro Y consegue se distanciar 30 quilômetros do carro X, ou seja, consegue se afastar um quilômetro a cada 2 minutos.

Leia a distância (em Km) e calcule quanto tempo leva (em minutos) para o carro Y tomar essa distância do outro carro.

Entrada
O arquivo de entrada contém um número inteiro.

Saída
Imprima o tempo necessário seguido da mensagem "minutos".
*/

#include <stdio.h>

void tempo_distanciar();
 
int main() {
    int kmDistante, tempo =0;
    
    scanf("%d", &kmDistante);
    
    tempo_distanciar(kmDistante, tempo);
 
    return 0;
}

/*Recebe o parâmetro d (distancia) e retorna o tempo (t)
necessário para Y se distanciar de X em d quilometros*/
void tempo_distanciar(int d, int t){
    if(d == 0){
        printf("%d minutos\n", t);
    }
    else{
        tempo_distanciar(d-1, t+2);
    }
}
