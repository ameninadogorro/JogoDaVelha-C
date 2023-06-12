#include <stdio.h>

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[3][3]) {
    printf("     1   2   3\n");
    printf("   -------------\n");
    for (int i = 0; i < 3; i++) {
        printf("%d  |", i + 1);
        for (int j = 0; j < 3; j++) {
            printf(" %c |", tabuleiro[i][j]);
        }
        printf("\n");
        printf("   -------------\n");
    }
}

// Função para verificar se houve vitória
int verificarVitoria(char tabuleiro[3][3], char jogador) {
    // Verificar linhas e colunas
    for (int i = 0; i < 3; i++) {
        if ((tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) ||
            (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)) {
            return 1;
        }
    }
    // Verificar diagonais
    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)) {
        return 1;
    }
    return 0;
}

int main() {
    char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};  // Tabuleiro vazio
    int linha, coluna;
    char jogador = 'X';
    int jogadas = 0;

    printf("Jogo da Velha\n");
    printf("--------------\n");

    while (1) {
        imprimirTabuleiro(tabuleiro);

        // Obter a jogada do jogador atual
        printf("Jogador %c, digite a linha (1-3): ", jogador);
        scanf("%d", &linha);
        printf("Jogador %c, digite a coluna (1-3): ", jogador);
        scanf("%d", &coluna);

        // Verificar se a posição está vazia
        if (tabuleiro[linha - 1][coluna - 1] == ' ') {
            tabuleiro[linha - 1][coluna - 1] = jogador;
            jogadas++;

            // Verificar se houve vitória
            if (verificarVitoria(tabuleiro, jogador)) {
                imprimirTabuleiro(tabuleiro);
                printf("Jogador %c venceu! Parabéns!\n", jogador);
                break;
            }
            // Verificar se deu empate
            else if (jogadas == 9) {
                imprimirTabuleiro(tabuleiro);
                printf("Empate!\n");
                break;
            }

            // Alternar para o próximo jogador
            jogador = (jogador == 'X') ? 'O' : 'X';
        } else {
            printf("Posição inválida. Tente novamente.\n");
        }
    }

    return 0;
