
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
char farm[252][252];
bool visited[252][252];

int dirR[] = {-1, 1, 0, 0};
int dirC[] = {0, 0, -1, 1};

void bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;

    int wolves = 0, sheep = 0;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (farm[r][c] == 'v') wolves++;
        if (farm[r][c] == 'k') sheep++;

        for (int i = 0; i < 4; i++) {
            int nr = r + dirR[i];
            int nc = c + dirC[i];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C &&
                farm[nr][nc] != '#' && !visited[nr][nc]) {
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }

    if (wolves >= sheep) sheep = 0;
    else wolves = 0;
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> farm[i][j];
        }
    }

    int wolves = 0, sheep = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (farm[i][j] != '#' && !visited[i][j]) {
                bfs(i, j);
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (farm[i][j] == 'v' && !visited[i][j]) wolves++;
            if (farm[i][j] == 'k' && !visited[i][j]) sheep++;
        }
    }

    cout << sheep << " " << wolves << endl;
    return 0;
}
