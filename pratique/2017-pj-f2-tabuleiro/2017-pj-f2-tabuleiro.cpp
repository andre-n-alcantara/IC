#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 2; i < N; i++) {
        for (int j = 2; j < N; j++) {
            int countWhite = 0, countBlack = 0;
            if (board[i-1][j-1] == 0) countWhite++;
            else countBlack++;
            if (board[i-1][j] == 0) countWhite++;
            else countBlack++;
            if (board[i][j-1] == 0) countWhite++;
            else countBlack++;
            if (countWhite > countBlack) board[i][j] = 1;
            else board[i][j] = 0;
        }
    }

    cout << board[N-1][N-1] << endl;

    
return 0;
}