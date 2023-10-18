#include <stdio.h>
#include <stdlib.h>

#define TAM 5

// Definição da estrutura da pilha
typedef struct SPilha {
    int topo;          // Índice do topo da pilha
    int dados[TAM];    
} TPilha;

// Função para adicionar um elemento à pilha
void push(TPilha *pilha, int dado) {
    if (pilha->topo == TAM - 1) {
        printf("\nA pilha está cheia\n"); // Verifica se a pilha está cheia
        return;
    }
    
    pilha->dados[++pilha->topo] = dado; // Adiciona o dado à pilha e atualiza o topo
}

// Função para listar os elementos da pilha
void listar(TPilha *pilha) {
    if (pilha->topo == -1) {
        printf("\nA pilha está vazia\n"); // Verifica se a pilha está vazia
        return;
    }
    printf("\nListando a pilha:\n");
    for (int i = pilha->topo; i >= 0; i--) {
        printf("%d\n", pilha->dados[i]);
    }
}

// Função para buscar um elemento na pilha
int buscar(TPilha *pilha, int chave) {
    for (int i = pilha->topo; i >= 0; i--) {
        if (pilha->dados[i] == chave) {
            return i; // Retorna a posição do elemento se encontrado
        }
    }
    return -1; // Retorna -1 se a chave não for encontrada
}

// Função para remover um elemento da pilha (desempilhar)
void pop(TPilha *pilha) {
    if (pilha->topo == -1) {
        printf("\nA pilha está vazia\n"); // Verifica se a pilha está vazia
        return;
    }
    pilha->topo--; // Decrementa o topo para remover o elemento
}

int main(int argc, char **argv) {
    TPilha pilha;
    pilha.topo = -1; // Inicializa o topo da pilha
    int leitura, key;

    printf("Informe os valores (0 para parar):\n");
    while (1) {
        printf("Informe o valor: ");
        scanf("%d", &leitura);
        if (leitura == 0)
            break;
        push(&pilha, leitura); 
    }

    listar(&pilha); 
    pop(&pilha); 
    pop(&pilha); 
    listar(&pilha); 

    printf("Informe a chave da busca: ");
    scanf("%d", &key);
    int posicao = buscar(&pilha, key); 

    if (posicao == -1) {
        printf("\nChave não encontrada!\n");
    } else {
        printf("\nChave encontrada na posição %d\n", posicao);
    }

    return (EXIT_SUCCESS);
}
