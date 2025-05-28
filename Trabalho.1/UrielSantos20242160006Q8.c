#include <stdio.h>

char tabuleiro[3][3];

void inicializarTabuleiro() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tabuleiro[i][j] = ' ';
}

void mostrarTabuleiro() {
    printf("  1   2   3\n");
    for (int i = 0; i < 3; i++) {
        printf("%c", i + 65);  // 65 = 'A'
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n ---|---|---\n");
    }
    printf("\n");
}

int verificarVitoria(char jogador) {
    for (int i = 0; i < 3; i++) {
        if ((tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) ||
            (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador))
            return 1;
    }
    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador))
        return 1;
    return 0;
}

int verificarEmpate() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tabuleiro[i][j] == ' ')
                return 0;
    return 1;
}

void jogar(char jogador) {
    char entrada[3];
    int linha, coluna;

    while (1) {
        printf("Jogador %c, digite a posição (ex: A1, B3): ", jogador);
        scanf("%s", entrada);

        if ((entrada[0] >= 'A' && entrada[0] <= 'C') && 
            (entrada[1] >= '1' && entrada[1] <= '3')) {

            linha = entrada[0] - 'A';
            coluna = entrada[1] - '1';

            if (tabuleiro[linha][coluna] == ' ') {
                tabuleiro[linha][coluna] = jogador;
                break;
            } else {
                printf("Posição ocupada! Tente novamente.\n");
            }

        } else {
            printf("Entrada inválida! Use o formato correto (A1, B2, etc).\n");
        }
    }
}

int main() {
    char jogadorAtual = 'X';
    int acabou = 0;

    inicializarTabuleiro();

    while (!acabou) {
        mostrarTabuleiro();
        jogar(jogadorAtual);

        if (verificarVitoria(jogadorAtual)) {
            mostrarTabuleiro();
            printf("Parabéns! Jogador %c venceu!\n", jogadorAtual);
            acabou = 1;
        } else if (verificarEmpate()) {
            mostrarTabuleiro();
            printf("Empate!\n");
            acabou = 1;
        } else {
            jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X'; // Alterna jogador
        }
    }

    return 0;
}