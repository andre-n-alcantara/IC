#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1005;

int n;
vector<string> grid(MAX_N);
vector<vector<int>> dist(MAX_N, vector<int>(MAX_N, -1));

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs() {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '0') {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] >= 9) dist[i][j] = 9;
            cout << dist[i][j];
        }
        cout << "\n";
    }
    return 0;
}