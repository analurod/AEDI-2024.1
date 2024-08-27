#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilhano{
    char valor;
    struct pilhano *prox;
} pilhaNo;

void push(pilhaNo **topo, char valor){
    pilhaNo* novo = (pilhaNo*) malloc(sizeof(pilhaNo));

    if(novo==NULL){
        exit(1);
    }

    novo->valor = valor;
    novo->prox = *topo;
    *topo = novo;
}

int pop(pilhaNo **topo){
    // Verifica se a pilha está vazia
    if (*topo == NULL) {
        return -1;
    }

    pilhaNo *aux = *topo;
    int pop = aux->valor;

    //Atualiza o topo
    *topo = (*topo)->prox;

    // Libera a memória do nó desempilhado
    free(aux);

    return pop;
}

// Função que retorna a precedência de um operador.
int precedencia(char op) {
    if (op == '+' || op == '-') {
        return 1; // Operadores de baixa precedência
    } else if (op == '*' || op == '/') {
        return 2; // Operadores de média precedência
    }
    else if (op == '^'){
        return 3; //Operadores de alta precedência
    }
    return 0; //Nenhuma precedência
}

// Função recebe a forma infixa em uma expressão posfixa
char* infixaParaPosfixa(pilhaNo **topo, char infixa[]) {
    char *posfixa;
    int tam, i, j;

    // Calcula o tamanho da expressão infixa
    tam = strlen(infixa);

    //Aloca memória para a expressão posfixa
    posfixa = (char*)malloc((tam + 1) * sizeof(char));

    //Verifica erro na alocação
    if(posfixa == NULL){
        exit (1);
    }

    // Loop para verificar cada caractere da expressão infixa
    for (i = 0, j = 0; infixa[i] != '\0'; i++) {
        
        // Se o caractere for um operando (número ou letra) é adicionado a posfixa
        if ((infixa[i] >= '0' && infixa[i] <= '9') || (infixa[i] >= 'a' && infixa[i] <= 'z') ||  (infixa[i]>= 'A' && infixa[i]<='Z')) {
            posfixa[j++] = infixa[i];
        }
            
        // Se o caractere for um parêntese esquerdo '(', empilha
        else if (infixa[i] == '(') {
            push(topo, infixa[i]);
        }
        // Se o caractere for um parêntese direito ')', desempilha até encontrar '('
        else if (infixa[i] == ')') {
            while (*topo != NULL && (*topo)->valor != '(') {
                posfixa[j++] = pop(topo);
            }
            pop(topo); // Remove o '(' da pilha
        }
        // Se o caractere for um operador (+, -, *, /)
        else {
            // Desempilha operadores da pilha enquanto a precedência for maior ou igual ao operador atual
            while (*topo != NULL && precedencia((*topo)->valor) >= precedencia(infixa[i])){
                posfixa[j++] =pop(topo);
            }
            // Empilha o operador atual
            push(topo, infixa[i]);
        }
    }

    // Desempilha todos os operadores restantes na pilha
    while (*topo != NULL) {
        posfixa[j++] = pop(topo);
    }

    posfixa[j] = '\0'; // Finaliza a string posfixa com o caractere nulo

    return posfixa; // Retorna a string posfixa gerada
}

int main() {
    int quant_teste;
    char infixa[300], *posfixa;
    pilhaNo *topo = NULL;

    // Lê o número de expressões que serão testadas
    scanf("%d", &quant_teste);
    
      
    if (quant_teste >= 1000) {
        return -1;
    }

    // Para cada expressão de teste
    for (int j = 0; j < quant_teste; j++) {
        scanf("%s", infixa);
              
        // Converte a expressão infixa para posfixa
        posfixa = infixaParaPosfixa(&topo, infixa);
                
        printf("%s\n", posfixa);
        free(posfixa);
    }

    return 0;
}
