#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 101;
const int MAX_M = 101;

vector<vector<char>> board(MAX_N, vector<char>(MAX_M));
vector<vector<bool>> visited(MAX_N, vector<bool>(MAX_M, false));

int dfs(int l, int c) {
    if (l < 0 || l >= board.size() || c < 0 || c >= board[0].size() || board[l][c] == '.' || visited[l][c])
        return 0;
    visited[l][c] = true;
    return 1 + dfs(l - 1, c) + dfs(l + 1, c) + dfs(l, c - 1) + dfs(l, c + 1);
}

int main() {
    int N, M, K;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    cin >> K;
    int destroyed = 0;
    for (int i = 0; i < K; i++) {
        int l, c;
        cin >> l >> c;
        l--; c--; // adjust to 0-based indices
        if (board[l][c] == '#') {
            int size = dfs(l, c);
            if (size > 0) destroyed++;
        }
    }
    cout << destroyed << endl;
    return 0;
}