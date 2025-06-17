#include <stdio.h>

// --- Constantes para os Movimentos ---
// Define quantas casas cada peça pode andar.
const int CASAS_TORRE = 5;
const int CASAS_BISPO = 3;
const int CASAS_CAVALO = 2;

// --- Função para imprimir o tabuleiro ---
void imprimirTabuleiro(char tabuleiro[8][8]) {
    // Mostra o tabuleiro com letras e números
    printf("  A B C D E F G H\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// --- Função recursiva para simular o movimento da peça ---
void moverPeca(char tabuleiro[8][8], int linha, int coluna, int movimentosRestantes, char direcao, char peca) {
    // Caso base: para a recursão quando não há mais movimentos
    if (movimentosRestantes == 0)
        return;

    // Calcula a nova posição com base na direção
    int novaLinha = linha;
    int novaColuna = coluna;

    if (direcao == 'c') novaLinha--;         // cima
    else if (direcao == 'b') novaLinha++;    // baixo
    else if (direcao == 'e') novaColuna--;   // esquerda
    else if (direcao == 'd') novaColuna++;   // direita
    else if (direcao == 'n') {               // diagonal (bispo)
        novaLinha--;
        novaColuna--;
    }

    // Verifica se a nova posição está dentro do tabuleiro
    if (novaLinha >= 0 && novaLinha < 8 && novaColuna >= 0 && novaColuna < 8) {
        tabuleiro[novaLinha][novaColuna] = peca;
        // Chama a função novamente com um movimento a menos
        moverPeca(tabuleiro, novaLinha, novaColuna, movimentosRestantes - 1, direcao, peca);
    }
}

// --- Função principal ---
int main() {
    char tabuleiro[8][8];

    // Inicializa o tabuleiro com '-'
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            tabuleiro[i][j] = '-';

    int linhaInicial, colunaInicial;
    char tipoPeca, direcao;

    // Entrada dos dados do usuário
    printf("Informe a posição inicial (linha 1-8, coluna A-H): ");
    scanf("%d %c", &linhaInicial, &direcao);

    printf("Informe o tipo da peça (T = Torre, B = Bispo, C = Cavalo): ");
    scanf(" %c", &tipoPeca);

    // Converte letra da coluna para índice numérico
    colunaInicial = direcao - 'A';

    // Ajusta índice da linha
    linhaInicial--;

    // Marca a posição inicial da peça
    tabuleiro[linhaInicial][colunaInicial] = tipoPeca;

    // Define movimentos e direção de acordo com a peça
    int movimentos;
    printf("Informe a direção (c = cima, b = baixo, e = esquerda, d = direita, n = diagonal): ");
    scanf(" %c", &direcao);

    if (tipoPeca == 'T') movimentos = CASAS_TORRE;
    else if (tipoPeca == 'B') movimentos = CASAS_BISPO;
    else if (tipoPeca == 'C') movimentos = CASAS_CAVALO;
    else movimentos = 0;

    // Chama a função de movimento
    moverPeca(tabuleiro, linhaInicial, colunaInicial, movimentos, direcao, tipoPeca);

    // Mostra o tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}


