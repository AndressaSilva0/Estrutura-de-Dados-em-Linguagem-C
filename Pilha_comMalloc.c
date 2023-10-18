#include <stdio.h>
#include <stdlib.h>


typedef struct SPilha
{
    int topo;
    int *dados;
    int tamanho;
} TPilha;

// Função para adicionar um elemento à pilha.
void push(TPilha *pilha, int dado)
{
    // Verifica se a pilha está cheia.
    if (pilha->topo == pilha->tamanho - 1)
    {
        printf("\nA pilha está cheia\n");
        return;
    }

    // Adiciona o dado à pilha e atualiza o topo.
    pilha->dados[++pilha->topo] = dado;
}

// Função para listar os elementos da pilha.
void listar(TPilha *pilha)
{
    // Verifica se a pilha está vazia.
    if (pilha->topo == -1)
    {
        printf("\nA pilha está vazia\n");
        return;
    }
    printf("\nListando a pilha:\n");
    for (int i = pilha->topo; i >= 0; i--)
    {
        printf("%d\n", pilha->dados[i]);
    }
}

// Função para buscar um elemento na pilha.
int buscar(TPilha *pilha, int chave)
{
    for (int i = pilha->topo; i >= 0; i--)
    {
        if (pilha->dados[i] == chave)
        {
            return i; // Retorna a posição do elemento se encontrado.
        }
    }
    return -1; // Retorna -1 se a chave não for encontrada.
}

// Função para remover um elemento da pilha (desempilhar).
void pop(TPilha *pilha)
{
    // Verifica se a pilha está vazia.
    if (pilha->topo == -1)
    {
        printf("\nA pilha está vazia\n");
        return;
    }
    pilha->topo--; // Decrementa o topo para remover o elemento.
}

int main(int argc, char **argv)
{
    TPilha pilha;
    pilha.topo = -1;
    int leitura, key;

    printf("Informe o tamanho da pilha: ");
    scanf("%d", &pilha.tamanho);

    // Aloca memória para o array de dados da pilha com base no tamanho especificado.
    pilha.dados = (int *)malloc(pilha.tamanho * sizeof(int));

    if (pilha.dados == NULL)
    {
        printf("Erro ao alocar memória para a pilha.\n");
        return (EXIT_FAILURE);
    }

    printf("Informe os valores (0 para parar):\n");
    while (1)
    {
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

    if (posicao == -1)
    {
        printf("\nChave não encontrada!\n");
    }
    else
    {
        printf("\nChave encontrada na posição %d\n", posicao);
    }

    free(pilha.dados); // Libera a memória alocada para os dados da pilha.
    return (EXIT_SUCCESS);
}
