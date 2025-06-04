#include <stdio.h>

#define TAM 10
#define TAM_HAB 5

void aplicar_habilidade(int tab[TAM][TAM], int efeito[TAM_HAB][TAM_HAB], int origem_l, int origem_c) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int tab_l = origem_l + i - TAM_HAB / 2;
            int tab_c = origem_c + j - TAM_HAB / 2;

            if (tab_l >= 0 && tab_l < TAM && tab_c >= 0 && tab_c < TAM) {
                if (efeito[i][j] == 1 && tab[tab_l][tab_c] == 0) {
                    tab[tab_l][tab_c] = 5;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Exemplo: navio fixo
    tabuleiro[2][3] = tabuleiro[2][4] = tabuleiro[2][5] = 3;

    // Matrizes de habilidades (Cone, Cruz, Octaedro)
    int cone[TAM_HAB][TAM_HAB] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int cruz[TAM_HAB][TAM_HAB] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    int octaedro[TAM_HAB][TAM_HAB] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplicar habilidades no tabuleiro
    aplicar_habilidade(tabuleiro, cone, 6, 2);
    aplicar_habilidade(tabuleiro, cruz, 6, 6);
    aplicar_habilidade(tabuleiro, octaedro, 6, 9);

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
            if (tabuleiro[i][j] == 0) {
                printf("~ ");
            } else if (tabuleiro[i][j] == 3) {
                printf("N ");
            } else if (tabuleiro[i][j] == 5) {
                printf("* ");
            }
        }
        printf("\n");
    }

    return 0;
}
