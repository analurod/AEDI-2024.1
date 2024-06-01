#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cliente, funcionario, *itens, *velocidade, *tempo, t = 0;

    // Leitura de quantidade de clientes e caixas
    scanf("%d %d", &funcionario, &cliente);

    // Verificação 
    if(funcionario < 1 || funcionario > cliente || cliente > 10000){
        return -1;
    }

    // Alocação memória itens, velocidade, tempo
    itens = (int *)malloc(cliente * sizeof(int));
    velocidade = (int *)malloc(funcionario * sizeof(int));
    tempo = (int *)malloc(funcionario * sizeof(int)); // Armazena tempo total de cada funcionário

    
    for(int i = 0; i < funcionario; i++){
        scanf("%d", &velocidade[i]);
    }

    for(int i = 0; i < cliente; i++){
        scanf("%d", &itens[i]);
    }

    // Loop para percorrer todos os clientes
    while(t < cliente) 
    {
        if(t < funcionario) // Atribui cada um dos "primeiros" clientes a um caixa/funcionário
        {
            tempo[t] = velocidade[t] * itens[t];

            t++;
        }
            
        // Se todos os caixas estiverem ocupados
        else
        {
            int aux = tempo[0];
            int livre = 0;

            // Encontrar o funcionário que ficará livre primeiro
            for(int i = 0; i < funcionario; i++){
                if(aux > tempo[i]) {
                    aux = tempo[i];
                    livre = i;
                }
            }
            
            tempo[livre] += velocidade[livre] * itens[t];

            livre = 0;
            t++;
        }
    }

    
    int maior = tempo[0];

    // Encontra o maior tempo necessário
    for(int i = 0; i < funcionario; i++){
        if(maior < tempo[i]){
            maior = tempo[i];
        }
    }
        printf("%d\n", maior);

    free(itens);
    free(velocidade);
    free(tempo);
}
