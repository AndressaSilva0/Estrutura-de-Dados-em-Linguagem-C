#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int fila[TAM];

void enqueue(int f[], int dado, int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (f[i] == 0)
        {
            f[i] = dado;
            return;
        }
    }

    printf("\nValor não inserido, a fila está cheia\n");
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
    int i;
    for (i = 0; i < tamanho; i++)
    {
        f[i] = f[i + 1];
    }
    f[tamanho - 1] = 0;
}

int main(int argc, char **argv)
{
    int dado, chave;

    while (1)
    {
        printf("Informe o valor: ");
        scanf("%d", &dado);
        if (dado == 0)
            break;
        enqueue(fila, dado, TAM);
    }

    printf("\n\nListando a fila\n\n");
    listar(fila, TAM);

    printf("\n\nInsira a chave a ser buscada: ");
    scanf("%d", &chave);

    buscar(fila, TAM, chave);
    dequeue(fila, TAM);
    listar(fila, TAM);
    return (EXIT_SUCCESS);
}