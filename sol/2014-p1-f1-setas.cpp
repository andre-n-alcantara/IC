#include <iostream>
#include <vector>
#include <string>

using namespace std;

int directions[128] = {
    ['V'] = 1,  // down
    ['<'] = -1,  // left
    ['>'] = 1,  // right
    ['A'] = -1  // up
};

bool isSafe(vector<string>& board, int i, int j) {
    int n = board.size();
    int di = 0, dj = 0;
    if (board[i][j] == 'V') {
        di = 1;
    } else if (board[i][j] == '<') {
        dj = -1;
    } else if (board[i][j] == '>') {
        dj = 1;
    } else if (board[i][j] == 'A') {
        di = -1;
    }
    while (i >= 0 && i < n && j >= 0 && j < n) {
        i += di;
        j += dj;
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return false;
        }
    }
    return true;
}

int countSafeCells(vector<string>& board) {
    int n = board.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isSafe(board, i, j)) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    cout << countSafeCells(board) << endl;
    return 0;
}