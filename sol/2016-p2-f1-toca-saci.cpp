
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int startX, startY;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 2) {
                startX = i;
                startY = j;
                break;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({startX, startY});
    map[startX][startY] = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    int count = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 1) {
                q.push({nx, ny});
                map[nx][ny] = 0;
                count++;
            }
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 3) {
                cout << count + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}
