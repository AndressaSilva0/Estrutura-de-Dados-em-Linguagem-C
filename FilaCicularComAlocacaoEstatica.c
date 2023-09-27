#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int fila[TAM];
int start = 0; // Índice de início da fila.
int end = 0;   // Índice de final da fila.

void enqueue(int f[], int dado, int tamanho)
{
    // Verifica se a próxima posição após 'end' é igual a 'start' e se o valor em 'end' não é zero.
    if ((end + 1) % tamanho == start && f[end] != 0)
    {
        printf("\nValor não inserido, a fila circular está cheia\n");
        return;
    }

    f[end] = dado; // Insere o dado na posição 'end' da fila.

    // Verifica se a fila está vazia e atualiza 'start' e 'end' caso necessário.
    if (start == -1 && end == -1)
    {
        start = end = 0;
    }
    else
    {
        // Atualiza 'end' para a próxima posição na fila circular.
        end = (end + 1) % tamanho;
    }
}

void listar(int f[], int tamanho)
{
    int i;
    printf("\n\nListando a fila\n\n");
    for (i = 0; i < tamanho; i++)
    {

        printf("%d ", f[i]);
    }
}

int buscar(int f[], int tamanho, int chave)
{

    int i;

    for (i = 0; i < tamanho; i++)
    {
        if (f[i] == chave)
        {
            printf("\nA chave %d foi encontrada na posição %d\n", chave, i);
            return i;
        }
    }
    printf("\nA chave %d não foi encontrada\n", chave);
    return -1;
}
void dequeue(int f[], int tamanho)
{
    // Verifica se a fila está vazia.
    if (f[start] == 0)
    {
        printf("\nA fila está vazia, não é possível remover\n");
        return;
    }
    // Remove o elemento na posição 'start' da fila, definindo-o como zero.
    f[start] = 0;

    // Atualiza 'start' para a próxima posição na fila circular.
    start = (start + 1) % tamanho;
}

int main(int argc, char **argv)
{
    int dado, chave, escolha;

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
            enqueue(fila, dado, TAM);
            listar(fila, TAM);
            break;
        case 2:
            dequeue(fila, TAM);
            if (dado != -2)
            {
                printf("Valor removido da fila: %d\n", dado);
            }
            listar(fila, TAM);
            break;
        case 3:
            printf("Informe a Chave que deseja buscar no vetor:");
            scanf("%d", &chave);
            buscar(fila, TAM, chave);
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