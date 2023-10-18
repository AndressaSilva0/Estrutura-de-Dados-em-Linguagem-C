#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct SFila
{
    int dados[TAM];
    int start; // Índice de início da fila.
    int end;   // Índice de final da fila.

} TFila;

TFila fila;
void enqueue(int dado, int tamanho)
{
    // Verifica se a próxima posição após 'end' é igual a 'start' e se o valor em 'end' não é zero.
    if ((fila.end != -1) && (fila.start == ((fila.end + 1) % tamanho)))
    {
        printf("\nValor não inserido, a fila circular está cheia\n");
        return;
    }
    // Atualiza 'end' para a próxima posição na fila circular.
    fila.end = (fila.end + 1) % tamanho;
    fila.dados[fila.end] = dado; // Insere o dado na posição 'end' da fila.

}

void listar(int tamanho)
{
    if (fila.start == -1 && fila.end == -1) // Verifica se a fila está vazia.
    {
        printf("\nA fila está vazia\n");
        return;
    }
    int i;
    printf("\n\nListando a fila\n\n");
    i = fila.start;
    do
    {
        printf("%d ", fila.dados[i]);
        i = (i + 1) % tamanho;
    } while (i != (fila.end + 1) % tamanho);
    printf("\n");
}

int buscar(int tamanho, int chave)
{
    if (fila.start == -1 && fila.end == -1)
    {
        printf("\nA fila está vazia, a chave %d não foi encontrada\n", chave);
        return -1;
    }
    int i;
    i = fila.start;
    do
    {
        if (chave == fila.dados[i]) // Compara a chave com os elementos da fila.
            return i;               // Retorna a posição se a chave for encontrada
        i = (i + 1) % tamanho;
    } while (i != (fila.end + 1) % tamanho);

    return -1; // Retorna -1 se a chave não for encontrada.
}

void dequeue(int tamanho)
{
    if (fila.start == fila.end)
    {
        fila.start = fila.end = -1; // Verifica se a fila está vazia.
        printf("\nA fila está vazia\n");
        return;
    }
    else
    {
        fila.start = (fila.start + 1) % tamanho; // Atualiza o início da fila para remover o elemento.
    }
}

int main(int argc, char **argv)
{
    int dado, chave, escolha;
    fila.end = -1;
    fila.start = 0;

    do
    {
        printf("\n1. Inserir na fila (enqueue)\n");
        printf("2. Remover da fila (dequeue)\n");
        printf("3. Busca por elemento na fila\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("Informe o valor para inserir na fila: ");
            scanf("%d", &dado);
            enqueue( dado, TAM);
            listar(TAM);
            break;
        case 2:
            dequeue(TAM);
            if (dado != -1)
            {
                printf("Valor removido da fila: %d\n", dado);
            }
            listar(TAM);
            break;
        case 3:
            printf("Informe a Chave que deseja buscar no vetor:");
            scanf("%d", &chave);
            buscar(TAM, chave);
            int posicao = buscar(TAM, chave);

            if (posicao == -1)
            {
                printf("\nChave não encontrada!");
            }
            else
            {
                printf("\n Chave encontrada na posição %d", posicao);
            }

            break;
        case 4:
            printf("Encerrando o programa.\n");
            break;
        default:
            printf("Opção inválida.\n");
        }
    } while (escolha != 4);

    return (EXIT_SUCCESS);
}
