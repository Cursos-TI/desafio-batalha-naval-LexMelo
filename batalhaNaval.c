#include <stdio.h>

// Define o tamanho do tabuleiro e do navio
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("=== TABULEIRO BATALHA NAVAL ===\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("=============================\n");
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas fixas dos navios
    int linhaNavioH = 2, colunaNavioH = 2; // Navio horizontal
    int linhaNavioV = 5, colunaNavioV = 5; // Navio vertical

    // Posiciona o navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (colunaNavioH + i < TAMANHO_TABULEIRO) {
            tabuleiro[linhaNavioH][colunaNavioH + i] = 3;
        }
    }

    // Posiciona o navio vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (linhaNavioV + i < TAMANHO_TABULEIRO) {
            tabuleiro[linhaNavioV + i][colunaNavioV] = 3;
        }
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
