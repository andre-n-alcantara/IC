#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 501;

char grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int n, f;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (grid[cx][cy] <= f) {
            grid[cx][cy] = '*';

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (abs(dx) != abs(dy) && cx + dx >= 0 && cx + dx < n && cy + dy >= 0 && cy + dy < n && !visited[cx + dx][cy + dy]) {
                        q.push({cx + dx, cy + dy});
                        visited[cx + dx][cy + dy] = true;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> f;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    bfs(0, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}