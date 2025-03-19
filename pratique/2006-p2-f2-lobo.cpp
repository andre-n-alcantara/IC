#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int r, c;
vector<vector<char>> farm;
vector<vector<bool>> visited;

void bfs(int x, int y, int& sheep, int& wolf) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int s = 0, w = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (farm[x][y] == 'k') s++;
        if (farm[x][y] == 'v') w++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[nx][ny] && farm[nx][ny] != '#') {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    if (s > w) sheep += s;
    else wolf += w;
}

int main() {
    cin >> r >> c;
    farm.resize(r, vector<char>(c));
    visited.resize(r, vector<bool>(c, false));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> farm[i][j];
        }
    }

    int sheep = 0, wolf = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!visited[i][j] && farm[i][j] != '#' && farm[i][j] != '.') {
                bfs(i, j, sheep, wolf);
            }
        }
    }

    cout << sheep << " " << wolf << endl;

    return 0;
}