#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

int main() {

     //============================================================
     //DECLARAÇÃO DAS MATRIZES
     //============================================================

    // Tabuleiro principal do jogo
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Matrizes das habilidades especiais
    int habilidadeCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];


     //============================================================
     // DECLARAÇÃO DOS NAVIOS
     //============================================================

    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};
    int navioDiagonalDireita[TAMANHO_NAVIO] = {3, 3, 3};
    int navioDiagonalEsquerda[TAMANHO_NAVIO] = {3, 3, 3};

     //============================================================
     //COORDENADAS DOS NAVIOS
     //============================================================

    // Navio horizontal
    int linhaHorizontal = 1;
    int colunaHorizontal = 1;

    // Navio vertical
    int linhaVertical = 4;
    int colunaVertical = 8;

    // Navio diagonal para a direita
    int linhaDiagonalDireita = 3;
    int colunaDiagonalDireita = 2;

    // Navio diagonal para a esquerda
    int linhaDiagonalEsquerda = 6;
    int colunaDiagonalEsquerda = 6;

    // ============================================================
    // COORDENADAS DAS HABILIDADES
    // ============================================================

    int origemConeLinha = 0;
    int origemConeColuna = 6;

    int origemCruzLinha = 4;
    int origemCruzColuna = 5;

    int origemOctaedroLinha = 7;
    int origemOctaedroColuna = 2;


    // Centro das matrizes 5x5
    int centro = TAMANHO_HABILIDADE / 2;

    int i, j;


    // ============================================================
    // INICIALIZAÇÃO DO TABULEIRO
    // ============================================================
   
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {

        for (j = 0; j < TAMANHO_TABULEIRO; j++) {

            tabuleiro[i][j] = 0;
        }
    }

    // ============================================================
    // NAVIO HORIZONTAL
    // ============================================================
 
    if (linhaHorizontal >= 0 &&
        linhaHorizontal < TAMANHO_TABULEIRO &&
        colunaHorizontal >= 0 &&
        colunaHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        for (i = 0; i < TAMANHO_NAVIO; i++) {

            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] == 0) {

                tabuleiro[linhaHorizontal][colunaHorizontal + i] =
                    navioHorizontal[i];

            } else {

                printf("Erro: sobreposicao no navio horizontal.\n");
                return 1;
            }
        }

    } else {

        printf("Erro: navio horizontal fora do tabuleiro.\n");
        return 1;
    }
    // ============================================================
    // NAVIO VERTICAL
    // ============================================================

    if (linhaVertical >= 0 &&
        linhaVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        colunaVertical >= 0 &&
        colunaVertical < TAMANHO_TABULEIRO) {

        for (i = 0; i < TAMANHO_NAVIO; i++) {

            if (tabuleiro[linhaVertical + i][colunaVertical] == 0) {

                tabuleiro[linhaVertical + i][colunaVertical] =
                    navioVertical[i];

            } else {

                printf("Erro: sobreposicao no navio vertical.\n");
                return 1;
            }
        }

    } else {

        printf("Erro: navio vertical fora do tabuleiro.\n");
        return 1;
    }

    // ============================================================
    // NAVIO DIAGONAL PARA A DIREITA
    // ============================================================

    if (linhaDiagonalDireita >= 0 &&
        colunaDiagonalDireita >= 0 &&
        linhaDiagonalDireita + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        colunaDiagonalDireita + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        for (i = 0; i < TAMANHO_NAVIO; i++) {

            if (tabuleiro[linhaDiagonalDireita + i]
                         [colunaDiagonalDireita + i] == 0) {

                tabuleiro[linhaDiagonalDireita + i]
                         [colunaDiagonalDireita + i] =
                    navioDiagonalDireita[i];

            } else {

                printf("Erro: sobreposicao no navio diagonal direita.\n");
                return 1;
            }
        }

    } else {

        printf("Erro: navio diagonal direita fora do tabuleiro.\n");
        return 1;
    }

    // ============================================================
    // NAVIO DIAGONAL PARA A ESQUERDA
    // ============================================================

    if (linhaDiagonalEsquerda >= 0 &&
        linhaDiagonalEsquerda + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        colunaDiagonalEsquerda < TAMANHO_TABULEIRO &&
        colunaDiagonalEsquerda - (TAMANHO_NAVIO - 1) >= 0) {

        for (i = 0; i < TAMANHO_NAVIO; i++) {

            if (tabuleiro[linhaDiagonalEsquerda + i]
                         [colunaDiagonalEsquerda - i] == 0) {

                tabuleiro[linhaDiagonalEsquerda + i]
                         [colunaDiagonalEsquerda - i] =
                    navioDiagonalEsquerda[i];

            } else {

                printf("Erro: sobreposicao no navio diagonal esquerda.\n");
                return 1;
            }
        }

    } else {

        printf("Erro: navio diagonal esquerda fora do tabuleiro.\n");
        return 1;
    }

    // ============================================================
    // CRIAÇÃO DA MATRIZ DA HABILIDADE CONE
    // ============================================================
 
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {

        for (j = 0; j < TAMANHO_HABILIDADE; j++) {

            habilidadeCone[i][j] = 0;

             if (i <= centro &&
                j >= centro - i &&
                j <= centro + i) {

                habilidadeCone[i][j] = 1;
            }
        }
    }


    // ============================================================
    // CRIAÇÃO DA MATRIZ DA HABILIDADE CRUZ
    // ============================================================
 
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {

        for (j = 0; j < TAMANHO_HABILIDADE; j++) {

            if (i == centro || j == centro) {

                habilidadeCruz[i][j] = 1;

            } else {

                habilidadeCruz[i][j] = 0;
            }
        }
    }

    // ============================================================
    // CRIAÇÃO DA MATRIZ DA HABILIDADE OCTAEDRO
    // ============================================================

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {

        for (j = 0; j < TAMANHO_HABILIDADE; j++) {

            if (abs(i - centro) + abs(j - centro) <= centro) {

                habilidadeOctaedro[i][j] = 1;

            } else {

                habilidadeOctaedro[i][j] = 0;
            }
        }
    }

    // ============================================================
    // SOBREPOSIÇÃO DO CONE NO TABULEIRO
    // ============================================================

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {

        for (j = 0; j < TAMANHO_HABILIDADE; j++) {

            if (habilidadeCone[i][j] == 1) {

                int linhaTabuleiro;
                int colunaTabuleiro;

                linhaTabuleiro =
                    origemConeLinha + i;

                colunaTabuleiro =
                    origemConeColuna + j - centro;

                if (linhaTabuleiro >= 0 &&
                    linhaTabuleiro < TAMANHO_TABULEIRO &&
                    colunaTabuleiro >= 0 &&
                    colunaTabuleiro < TAMANHO_TABULEIRO) {

                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {

                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                    }
                }
            }
        }
    }

    // ============================================================
    // SOBREPOSIÇÃO DA CRUZ NO TABULEIRO
    // ============================================================
 
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {

        for (j = 0; j < TAMANHO_HABILIDADE; j++) {

            if (habilidadeCruz[i][j] == 1) {

                int linhaTabuleiro;
                int colunaTabuleiro;

                linhaTabuleiro =
                    origemCruzLinha + i - centro;

                colunaTabuleiro =
                    origemCruzColuna + j - centro;


                // Validação dos limites do tabuleiro
                if (linhaTabuleiro >= 0 &&
                    linhaTabuleiro < TAMANHO_TABULEIRO &&
                    colunaTabuleiro >= 0 &&
                    colunaTabuleiro < TAMANHO_TABULEIRO) {

                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {

                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                    }
                }
            }
        }
    }

    // ============================================================
    // SOBREPOSIÇÃO DO OCTAEDRO NO TABULEIRO
    // ============================================================

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {

        for (j = 0; j < TAMANHO_HABILIDADE; j++) {

            if (habilidadeOctaedro[i][j] == 1) {

                int linhaTabuleiro;
                int colunaTabuleiro;

                linhaTabuleiro =
                    origemOctaedroLinha + i - centro;

                colunaTabuleiro =
                    origemOctaedroColuna + j - centro;


                // Validação dos limites
                if (linhaTabuleiro >= 0 &&
                    linhaTabuleiro < TAMANHO_TABULEIRO &&
                    colunaTabuleiro >= 0 &&
                    colunaTabuleiro < TAMANHO_TABULEIRO) {

                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {

                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                    }
                }
            }
        }
    }

    // ============================================================
    // EXIBIÇÃO DAS MATRIZES DAS HABILIDADES
    // ============================================================

    printf("\n=====================================\n");
    printf("HABILIDADE: CONE\n");
    printf("=====================================\n\n");

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {

        for (j = 0; j < TAMANHO_HABILIDADE; j++) {

            printf("%d ", habilidadeCone[i][j]);
        }

        printf("\n");
    }


    printf("\n=====================================\n");
    printf("HABILIDADE: CRUZ\n");
    printf("=====================================\n\n");

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {

        for (j = 0; j < TAMANHO_HABILIDADE; j++) {

            printf("%d ", habilidadeCruz[i][j]);
        }

        printf("\n");
    }


    printf("\n=====================================\n");
    printf("HABILIDADE: OCTAEDRO\n");
    printf("=====================================\n\n");

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {

        for (j = 0; j < TAMANHO_HABILIDADE; j++) {

            printf("%d ", habilidadeOctaedro[i][j]);
        }

        printf("\n");
    }

    // ============================================================
    // EXIBIÇÃO DO TABULEIRO FINAL
    // ============================================================

    printf("\n=====================================\n");
    printf("TABULEIRO BATALHA NAVAL\n");
    printf("=====================================\n");

    printf("\nLegenda:\n");
    printf("0 = Agua\n");
    printf("3 = Navio\n");
    printf("5 = Area de habilidade\n\n");

    printf("   ");

    for (j = 0; j < TAMANHO_TABULEIRO; j++) {

        printf("%d ", j);
    }

    printf("\n");

    for (i = 0; i < TAMANHO_TABULEIRO; i++) {

        printf("%d  ", i);

        for (j = 0; j < TAMANHO_TABULEIRO; j++) {

            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }


    return 0;
}