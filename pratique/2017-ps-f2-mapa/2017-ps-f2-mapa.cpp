#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int L, C;
vector<vector<char>> mapa;
queue<pair<int, int>> fila;
vector<pair<int, int>> direcoes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(int x, int y) {
    fila.push({x, y});
    while (!fila.empty()) {
        x = fila.front().first;
        y = fila.front().second;
        fila.pop();
        for (auto dir : direcoes) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            if (nx >= 0 && nx < L && ny >= 0 && ny < C && mapa[nx][ny] == 'H') {
                mapa[nx][ny] = '.';
                fila.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> L >> C;
    mapa.resize(L, vector<char>(C));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cin >> mapa[i][j];
            if (mapa[i][j] == 'o') {
                bfs(i, j);
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