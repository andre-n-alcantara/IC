#include <ctime>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

const int MAX_N = 12;
const int MAX_M = 12;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(vector<vector<bool>>& grid, int x1, int y1, int x2, int y2) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(MAX_N, vector<bool>(MAX_M, false));
    q.push({x1, y1});
    visited[x1][y1] = true;
    int dist = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x == x2 && y == y2) return dist;
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx >= 0 && nx < MAX_N && ny >= 0 && ny < MAX_M && !grid[nx][ny] && !visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        dist++;
    }
    return -1;
}

int main() {
    int N, M, Xe, Ye, Xs, Ys;
    cin >> N >> M >> Xe >> Ye >> Xs >> Ys;
    vector<vector<bool>> grid(N, vector<bool>(M, false));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (i % 2 == 0 && j % 2 == 0) grid[i-1][j-1] = true;
        }
    }
    int ans = bfs(grid, Xe-1, Ye-1, Xs-1, Ys-1);
    cout << ans << endl;
    
return 0;
}