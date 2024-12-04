#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

struct State {
    int x, y, h, t;
};

int bfs(vector<vector<int>> &grid, int n, int m) {
    queue<State> q;
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(10, INF)));
    q.push({0, 0, grid[0][0], 0});
    dist[0][0][grid[0][0]] = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    while (!q.empty()) {
        State s = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = s.x + dx[i];
            int ny = s.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int nh = (grid[nx][ny] + s.t) % 10;
                if (nh <= s.h + 1 && dist[nx][ny][nh] > s.t + 1) {
                    dist[nx][ny][nh] = s.t + 1;
                    q.push({nx, ny, nh, s.t + 1});
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < 10; i++) {
        ans = min(ans, dist[n-1][m-1][i]);
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    cout << bfs(grid, n, m) << endl;
    return 0;
}