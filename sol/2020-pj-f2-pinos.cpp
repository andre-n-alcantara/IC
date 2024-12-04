
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countValidMoves(vector<string> board) {
    int validMoves = 0;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == 'o') {
                // Check up direction
                if (i > 1 && board[i-1][j] == 'o' && board[i-2][j] == '.') {
                    validMoves++;
                }
                // Check down direction
                if (i < 5 && board[i+1][j] == 'o' && board[i+2][j] == '.') {
                    validMoves++;
                }
                // Check left direction
                if (j > 1 && board[i][j-1] == 'o' && board[i][j-2] == '.') {
                    validMoves++;
                }
                // Check right direction
                if (j < 5 && board[i][j+1] == 'o' && board[i][j+2] == '.') {
                    validMoves++;
                }
            }
        }
    }

    return validMoves;
}

int main() {
    vector<string> board(7);
    for (int i = 0; i < 7; i++) {
        cin >> board[i];
    }

    cout << countValidMoves(board) << endl;

    return 0;
}
