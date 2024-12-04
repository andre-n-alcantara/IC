#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> grid;
queue<pair<int, int>> q;

void bfs(int x, int y, int n, int m) {
    q.push({x, y});
    grid[x][y] = true;

    int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !grid[nx][ny]) {
                q.push({nx, ny});
                grid[nx][ny] = true;
            }
        }
    }
}

int main() {
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;

    grid.assign(n + 1, vector<bool>(m + 1, false));

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        grid[a][b] = true;
    }

    bfs(x, y, n, m);

    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}