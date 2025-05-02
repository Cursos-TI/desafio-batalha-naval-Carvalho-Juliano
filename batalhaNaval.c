#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define DIMENSAO_TABULEIRO 10
#define HABILIDADE 5

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    int i, j;
    int matriz[DIMENSAO_TABULEIRO][DIMENSAO_TABULEIRO] = {0};
    int habilidade[HABILIDADE][HABILIDADE] = {0};
    int origemLinha = 2;
    int origemColuna = 4;

    //Criação dos navios manualmente no codigo
    matriz[4][4] = 3;
    matriz[4][5] = 3;
    matriz[4][6] = 3;

    matriz[7][4] = 3;
    matriz[7][5] = 3;
    matriz[7][6] = 3;

    matriz[0][0] = 3;
    matriz[1][1] = 3;
    matriz[2][2] = 3;

    matriz[0][5] = 3;
    matriz[1][6] = 3;
    matriz[2][7] = 3;

    //IMPRIMIR HABILIDADE NO TABULEIRO
    for (i = 0; i < HABILIDADE; i++) {
        for (j = 0; j < HABILIDADE; j++){
            if (j >= (HABILIDADE / 2) - i && j <= (HABILIDADE / 2) + i) {
                habilidade[i][j] = 1;  // marca área de efeito
            }
        }
    }

    /*Codigos para os outros formatos das habilidades.*/
    //codigo para habilidade em cruz
    //if (i == HABILIDADE / 2 || j == HABILIDADE / 2)
    //habilidade[i][j] = 1

    //codigo para habilidade em losango
    // if (abs(i - HABILIDADE / 2) + abs(j - HABILIDADE / 2) <= HABILIDADE / 2)
    // habilidade[i][j] = 1;

    for ( i = 0; i < HABILIDADE; i++) {
        for ( j = 0; j < HABILIDADE; j++) {
            // Calcula posição no tabuleiro
            int linhaTabuleiro = origemLinha + i - HABILIDADE / 2;
            int colunaTabuleiro = origemColuna + j - HABILIDADE / 2;

            // Verifica se está dentro dos limites
            if (linhaTabuleiro >= 0 && linhaTabuleiro < DIMENSAO_TABULEIRO &&
                colunaTabuleiro >= 0 && colunaTabuleiro < DIMENSAO_TABULEIRO) {
                if (habilidade[i][j] == 1 && matriz[linhaTabuleiro][colunaTabuleiro] != 3) {
                    matriz[linhaTabuleiro][colunaTabuleiro] = 5;  // marca área afetada
                }
            }
        }
    }

    //TABULEIRO
    for(i = 0; i < DIMENSAO_TABULEIRO; i++){
        for (j = 0; j < DIMENSAO_TABULEIRO; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        
        printf("\n");
    }


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

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
