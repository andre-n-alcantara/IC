#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
    int N, F;
    cin >> N >> F;

    vector<string> mapa(N);
    for (int i = 0; i < N; i++) {
        cin >> mapa[i];
    }

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<int, int>> q;

    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && mapa[nx][ny] - '0' <= F) {
                mapa[nx][ny] = '*';
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << mapa[i] << endl;
    }

    return 0;
}