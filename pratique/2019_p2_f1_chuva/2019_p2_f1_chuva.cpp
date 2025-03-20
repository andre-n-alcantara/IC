#include <ctime>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

vector<vector<char>> wall;
vector<vector<bool>> visited;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (wall[cx][cy] == '.') wall[cx][cy] = 'o';

        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];

            if (isValid(nx, ny) && !visited[nx][ny]) {
                if (wall[nx][ny] == '.' || wall[nx][ny] == 'o') {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
                if (k == 0 && wall[nx][ny] == '#') {
                    if (ny > 0 && wall[nx][ny - 1] == '.') q.push({nx, ny - 1});
                    if (ny < M - 1 && wall[nx][ny + 1] == '.') q.push({nx, ny + 1});
                }
                if (k == 2 && wall[nx][ny] == '#') {
                    if (ny > 0 && wall[nx][ny - 1] == '.') q.push({nx, ny - 1});
                    if (ny < M - 1 && wall[nx][ny + 1] == '.') q.push({nx, ny + 1});
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
        }
    }

    for (int j = 0; j < M; j++) {
        if (wall[0][j] == 'o') {
            bfs(0, j);
            break;
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