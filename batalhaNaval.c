// Define o tamanho do tabuleiro e do navio
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Define símbolos para água e navio
#define AGUA 0
#define NAVIO 1

// Mostra o tabuleiro no terminal
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verifica se é possível colocar um navio nessa posição
int validarPosicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + (orientacao == 0 ? 0 : i);
        int c = coluna + (orientacao == 0 ? i : 0);

        // Verifica se está dentro do tabuleiro
        if (l >= TAMANHO_TABULEIRO || c >= TAMANHO_TABULEIRO) {
            return 0;
        }

        // Verifica se já tem navio nessa posição
        if (tabuleiro[l][c] == NAVIO) {
            return 0;
        }
    }
    return 1;
}

// Coloca o navio no tabuleiro se a posição for válida
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    if (validarPosicao(tabuleiro, linha, coluna, orientacao)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            int l = linha + (orientacao == 0 ? 0 : i);
            int c = coluna + (orientacao == 0 ? i : 0);
            tabuleiro[l][c] = NAVIO;
        }
    }
}

// Função principal
int main() {
    // Cria o tabuleiro e preenche com água
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posiciona 4 navios em posições fixas
    posicionarNavio(tabuleiro, 0, 0, 0); // Horizontal
    posicionarNavio(tabuleiro, 2, 3, 1); // Vertical
    posicionarNavio(tabuleiro, 5, 5, 0);
    posicionarNavio(tabuleiro, 8, 1, 1);

    // Mostra o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}

