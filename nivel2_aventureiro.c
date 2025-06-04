#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Coordenadas dos navios
    int linha_h1 = 1, col_h1 = 1;
    int linha_v1 = 4, col_v1 = 6;
    int linha_diag1 = 0, col_diag1 = 0;     // Diagonal principal
    int linha_diag2 = 0, col_diag2 = 9;     // Diagonal inversa

    // Horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_h1][col_h1 + i] = 3;
    }

    // Vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_v1 + i][col_v1] = 3;
    }

    // Diagonal principal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_diag1 + i][col_diag1 + i] = 3;
    }

    // Diagonal inversa
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_diag2 + i][col_diag2 - i] = 3;
    }

    // Cabeçalho
    printf("    ");
    for (int j = 0; j < TAM; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    // Exibição do tabuleiro
    for (int i = 0; i < TAM; i++) {
        printf("%2d  ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
