#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Matriz que representa o tabuleiro 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Vetores que representam os dois navios
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais do navio horizontal
    int linhaHorizontal = 2;
    int colunaHorizontal = 3;

    // Coordenadas iniciais do navio vertical
    int linhaVertical = 5;
    int colunaVertical = 7;

    int i, j;

    for (i = 0; i < TAMANHO_TABULEIRO; i++) {

        for (j = 0; j < TAMANHO_TABULEIRO; j++) {

            tabuleiro[i][j] = 0;
        }
    }

    if (linhaHorizontal < 0 ||
        linhaHorizontal >= TAMANHO_TABULEIRO ||
        colunaHorizontal < 0 ||
        colunaHorizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {

        printf("Erro: posicao invalida para o navio horizontal.\n");

        return 1;
    }

    for (i = 0; i < TAMANHO_NAVIO; i++) {

        tabuleiro[linhaHorizontal][colunaHorizontal + i] =
            navioHorizontal[i];
    }

    if (linhaVertical < 0 ||
        linhaVertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        colunaVertical < 0 ||
        colunaVertical >= TAMANHO_TABULEIRO) {

        printf("Erro: posicao invalida para o navio vertical.\n");

        return 1;
    }

    for (i = 0; i < TAMANHO_NAVIO; i++) {

        if (tabuleiro[linhaVertical + i][colunaVertical] != 0) {

            printf("Erro: os navios estao sobrepostos.\n");

            return 1;
        }
    }

    for (i = 0; i < TAMANHO_NAVIO; i++) {

        tabuleiro[linhaVertical + i][colunaVertical] =
            navioVertical[i];
    }

    printf("\nTABULEIRO BATALHA NAVAL\n\n");

    for (i = 0; i < TAMANHO_TABULEIRO; i++) {

        for (j = 0; j < TAMANHO_TABULEIRO; j++) {

            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    return 0;
}