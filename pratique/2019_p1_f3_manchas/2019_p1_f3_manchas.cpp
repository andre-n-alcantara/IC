#include <iostream>
#include <vector>
#include < queue>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(vector<vector<int>>& img, int x, int y, int n, int m) {
    queue<pair<int, int>> q;
    q.push({x, y});
    img[x][y] = 0;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && img[nx][ny] == 1) {
                q.push({nx, ny});
                img[nx][ny] = 0;
            }
        }
    }
}

int countSpots(vector<vector<int>>& img, int n, int m) {
    int spots = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (img[i][j] == 1) {
                bfs(img, i, j, n, m);
                spots++;
            }
        }
    }

    return spots;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> img(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> img[i][j];
        }
    }

    cout << countSpots(img, n, m) << endl;

    return 0;
}