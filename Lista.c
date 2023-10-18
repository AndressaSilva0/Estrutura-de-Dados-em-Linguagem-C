#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int lista[TAM];
int contador = 0;  // Inicializa o contador de elementos na lista

void adicionar(int l[], int posicao, int dado, int tamanho) {
    if (contador >= tamanho) {
        printf("\n\nA lista está cheia, não foi possível inserir o valor!\n\n");
        return;  // Verifica se a lista está cheia e exibe uma mensagem
    }

    if ((posicao < 0) || (posicao >= tamanho)) {
        printf("\n\nPosição inválida\n\n");
        return;  // Verifica se a posição especificada é válida
    }

    if (l[posicao] == 0) {  // Verifica se a posição está vazia
        l[posicao] = dado;
        contador++;  // Insere o valor na posição especificada e incrementa o contador
    } else {
        int distancia = 1;

        while (distancia < tamanho) {
            int esquerda = posicao - distancia;
            int direita = posicao + distancia;

            if (esquerda >= 0 && l[esquerda] == 0) {
                l[esquerda] = dado;
                contador++;  // Insere o valor na posição vazia mais próxima à esquerda e incrementa o contador
                return;
            }

            if (direita < tamanho && l[direita] == 0) {
                l[direita] = dado;
                contador++;  // Insere o valor na posição vazia mais próxima à direita e incrementa o contador
                return;
            }

            distancia++;
        }

        if (contador >= tamanho) {
            printf("\n\nA lista está cheia, não foi possível inserir o valor!\n\n");
        }
    }
}

void listar(int l[], int tamanho) {
    int i;
    printf("\n\nListando a pilha\n\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d\n", l[i]);  // Exibe os elementos da lista
    }
}

int buscar(int p[], int tamanho, int chave) {
    int i;
    for (i = tamanho - 1; i >= 0; i--) {
        if (p[i] == chave) {
            return i;  // Procura a chave na lista e retorna a posição se encontrada
        }
    }

    return -1;  // Retorna -1 se a chave não for encontrada
}

void remover(int l[], int posicao, int tamanho) {
    if ((posicao < 0) || (posicao >= tamanho)) {
        printf("\n\nPosição inválida\n\n");
        return;  // Verifica se a posição especificada é válida
    }
    l[posicao] = 0;
    contador--;  // Remove o elemento na posição especificada e decrementa o contador
}

int main(int argc, char **argv) {
    int pos, leitura, key;

    while (1) {
        printf("Informe o valor e a posição: ");
        scanf("%d %d", &leitura, &pos);
        if (leitura == 0)
            break;
        adicionar(lista, pos, leitura, TAM);  // Adiciona um valor à lista
    }

    listar(lista, TAM);  // Lista os elementos da lista

    printf("Informe a posição que deseja remover: ");
    scanf("%d", &pos);
    remover(lista, pos, TAM);  // Remove um elemento da lista

    listar(lista, TAM);  // Lista os elementos após a remoção

    printf("Informe a posição que deseja remover: ");
    scanf("%d", &pos);
    remover(lista, pos, TAM);  // Remove outro elemento da lista

    listar(lista, TAM);  // Lista os elementos após a segunda remoção

    printf("Informe o valor e a posição: ");
    scanf("%d %d", &leitura, &pos);
    adicionar(lista, pos, leitura, TAM);  // Adiciona um valor após a remoção

    listar(lista, TAM);  // Lista os elementos após a adição

    printf("Informe o valor e a posição: ");
    scanf("%d %d", &leitura, &pos);
    adicionar(lista, pos, leitura, TAM);  // Adiciona outro valor

    listar(lista, TAM);  // Lista os elementos após a segunda adição

    printf("\nInforme a chave da busca: ");
    scanf("%d", &key);
    int posicao = buscar(lista, TAM, key);

    if (posicao == -1) {
        printf("\nChave não encontrada!\n");
    } else {
        printf("\n Chave encontrada na posição %d\n", posicao);  // Realiza uma busca e exibe a posição da chave se encontrada
    }

    return (EXIT_SUCCESS);
}
