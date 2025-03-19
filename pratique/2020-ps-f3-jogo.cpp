#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int L, C, P;
vector<vector<int>> board;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    int cnt = 0;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (board[x][y] == 0) {
            cnt++;
            board[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 1 && nx <= L && ny >= 1 && ny <= C && board[nx][ny] == 0)
                    q.push({nx, ny});
            }
        }
    }
    return cnt;
}

int main() {
    cin >> L >> C;
    board.resize(L + 1, vector<int>(C + 1, 0));
    cin >> P;
    for (int i = 0; i < P; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = -1;
    }
    int ans = 0;
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= C; j++) {
            if (board[i][j] == 0) {
                ans += bfs(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}