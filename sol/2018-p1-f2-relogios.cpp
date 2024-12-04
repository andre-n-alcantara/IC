
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int MAX_L = 100, MAX_C = 100, MAX_K = 105;

int L, C, K;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    int time = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == L - 1 && y == C - 1) return time;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (abs(dx) + abs(dy) != 1) continue;

                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx < 0 || ny < 0 || nx >= L || ny >= C) continue;
                    if (visited[nx][ny]) continue;

                    int clockTime = grid[nx][ny];
                    if (clockTime == -1 || clockTime == time % K) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        time++;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> L >> C >> K;
    grid.resize(L, vector<int>(C));
    visited.resize(L, vector<bool>(C, false));

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    cout << bfs() << endl;

    return 0;
}
