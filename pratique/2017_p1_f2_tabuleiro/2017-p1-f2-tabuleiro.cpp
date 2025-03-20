#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> board(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> board[i][j];
        }
    }

    for (int i = 2; i < N; i++) {
        for (int j = 2; j < N; j++) {
            int white = 0, black = 0;
            if (board[i-1][j-1] == 0) white++; else black++;
            if (board[i-1][j] == 0) white++; else black++;
            if (board[i][j-1] == 0) white++; else black++;
            if (white > black) board[i][j] = 1;
            else board[i][j] = 0;
        }
    }

    std::cout << board[N-1][N-1] << std::endl;

    return 0;
}