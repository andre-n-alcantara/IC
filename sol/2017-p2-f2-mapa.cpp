
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    int L, C;
    cin >> L >> C;
    vector<vector<char>> mapa(L, vector<char>(C));
    int x, y;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cin >> mapa[i][j];
            if (mapa[i][j] == 'o') {
                x = i;
                y = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < L && ny >= 0 && ny < C && mapa[nx][ny] == 'H') {
                mapa[nx][ny] = '.';
                q.push({nx, ny});
            }
        }
    }
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (mapa[i][j] == 'H') {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }
    return 0;
}
