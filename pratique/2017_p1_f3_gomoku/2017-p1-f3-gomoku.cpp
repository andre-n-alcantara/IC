#include <iostream>
#include <vector>

using namespace std;

bool checkWin(vector<vector<int>> &board, int player) {
    // Check rows
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 11; j++) {
            bool win = true;
            for (int k = 0; k < 5; k++) {
                if (board[i][j + k] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }

    // Check columns
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 15; j++) {
            bool win = true;
            for (int k = 0; k < 5; k++) {
                if (board[i + k][j] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }

    // Check diagonals (top-left to bottom-right)
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            bool win = true;
            for (int k = 0; k < 5; k++) {
                if (board[i + k][j + k] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }

    // Check diagonals (bottom-left to top-right)
    for (int i = 4; i < 15; i++) {
        for (int j = 0; j < 11; j++) {
            bool win = true;
            for (int k = 0; k < 5; k++) {
                if (board[i - k][j + k] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> board(15, vector<int>(15));
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            cin >> board[i][j];
        }
    }

    if (checkWin(board, 1)) cout << 1 << endl;
    else if (checkWin(board, 2)) cout << 2 << endl;
    else cout << 0 << endl;

    return 0;
}