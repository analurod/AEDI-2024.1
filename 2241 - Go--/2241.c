#include <stdio.h>

#define MAX_N 500

int main() {
    int N, P;
    scanf("%d %d", &N, &P);

    int board[MAX_N][MAX_N] = {0};  // Tabuleiro: 0 - vazio, 1 - pedra preta, 2 - pedra branca
    int prefixBlack[MAX_N + 1][MAX_N + 1] = {0};  // Prefixo para pedras pretas
    int prefixWhite[MAX_N + 1][MAX_N + 1] = {0};  // Prefixo para pedras brancas

    // Leitura das pedras pretas
    for (int i = 0; i < P; i++) {
        int L, C;
        scanf("%d %d", &L, &C);
        board[L-1][C-1] = 1;  // Pedra preta
    }

    // Leitura das pedras brancas
    for (int i = 0; i < P; i++) {
        int L, C;
        scanf("%d %d", &L, &C);
        board[L-1][C-1] = 2;  // Pedra branca
    }

    // Construção das matrizes de prefixo
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            prefixBlack[i][j] = prefixBlack[i-1][j] + prefixBlack[i][j-1] - prefixBlack[i-1][j-1] + (board[i-1][j-1] == 1);
            prefixWhite[i][j] = prefixWhite[i-1][j] + prefixWhite[i][j-1] - prefixWhite[i-1][j-1] + (board[i-1][j-1] == 2);
        }
    }

    int countBlack = 0, countWhite = 0;

    // Contagem de sub-áreas quadradas
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N - k + 1; i++) {
            for (int j = 1; j <= N - k + 1; j++) {
                int x1 = i, y1 = j;
                int x2 = i + k - 1, y2 = j + k - 1;

                int blackCount = prefixBlack[x2][y2] - prefixBlack[x1-1][y2] - prefixBlack[x2][y1-1] + prefixBlack[x1-1][y1-1];
                int whiteCount = prefixWhite[x2][y2] - prefixWhite[x1-1][y2] - prefixWhite[x2][y1-1] + prefixWhite[x1-1][y1-1];
                
                if (blackCount > 0 && whiteCount == 0) {
                    countBlack++;
                } else if (whiteCount > 0 && blackCount == 0) {
                    countWhite++;
                }
            }
        }
    }

    printf("%d %d\n", countBlack, countWhite);

    return 0;
}
