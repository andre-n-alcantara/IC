#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<char>> wall;
vector<vector<bool>> visited;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
                if (wall[nx][ny] == '#' || wall[nx][ny] == 'o') {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                } else if (wall[nx][ny] == '.') {
                    wall[nx][ny] = 'o';
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;
    wall.assign(N, vector<char>(M));
    visited.assign(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> wall[i][j];
            if (wall[i][j] == 'o') {
                bfs(i, j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << wall[i][j];
        }
        cout << endl;
    }

    return 0;
}