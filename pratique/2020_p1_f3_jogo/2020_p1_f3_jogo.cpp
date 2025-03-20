#include <ctime>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int L, C, P;
vector<vector<bool>> board;
vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int x, int y) {
    return x >= 0 && x < L && y >= 0 && y < C;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    board[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (auto dir : directions) {
            int nx = cx + dir[0];
            int ny = cy + dir[1];

            if (isValid(nx, ny) && !board[nx][ny]) {
                q.push({nx, ny});
                board[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> C >> P;
    board.resize(L, vector<bool>(C, false));

    for (int i = 0; i < P; i++) {
        int x, y;
        cin >> x >> y;
        board[x - 1][y - 1] = true;
    }

    int maxWhite = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (!board[i][j]) {
                bfs(i, j);
                maxWhite++;
            }
        }
    }

    cout << maxWhite << endl;

    
return 0;
}