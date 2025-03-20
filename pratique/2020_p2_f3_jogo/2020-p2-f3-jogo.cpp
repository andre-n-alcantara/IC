#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_L = 6;
const int MAX_C = 6;

int L, C, P;
vector<vector<bool>> board(MAX_L + 1, vector<bool>(MAX_C + 1, false));
vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dfs(int x, int y) {
    if (x < 1 || x > L || y < 1 || y > C) return 0;
    if (board[x][y]) return 0;
    int count = 1;
    board[x][y] = true;
    for (auto dir : dirs) {
        int nx = x + dir[0];
        int ny = y + dir[1];
        count += dfs(nx, ny);
    }
    return count;
}

int main() {
    cin >> L >> C;
    cin >> P;
    for (int i = 0; i < P; i++) {
        int xi, yi;
        cin >> xi >> yi;
        board[xi][yi] = true;
    }
    int maxWhite = 0;
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= C; j++) {
            if (!board[i][j]) {
                int white = dfs(i, j);
                maxWhite = max(maxWhite, white);
            }
        }
    }
    cout << maxWhite << endl;
    return 0;
}