#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 12;

int n, m, xe, ye, xs, ys;
vector<vector<bool>> armarios(MAX_N, vector<bool>(MAX_N, false));
vector<vector<bool>> visitados(MAX_N, vector<bool>(MAX_N, false));
vector<vector<int>> dx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs() {
    queue<pair<int, int>> fila;
    fila.push({xe, ye});
    visitados[xe][ye] = true;
    int distancia = 0;

    while (!fila.empty()) {
        int tamanho = fila.size();
        for (int i = 0; i < tamanho; i++) {
            int x = fila.front().first;
            int y = fila.front().second;
            fila.pop();
            if (x == xs && y == ys) return distancia;
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j][0];
                int ny = y + dx[j][1];
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visitados[nx][ny] && !armarios[nx][ny]) {
                    fila.push({nx, ny});
                    visitados[nx][ny] = true;
                }
            }
        }
        distancia++;
    }

    return -1;
}

int main() {
    cin >> n >> m;
    cin >> xe >> ye;
    cin >> xs >> ys;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i % 2 == 0 || j % 2 == 0) armarios[i][j] = true;
        }
    }

    cout << bfs() << endl;

    return 0;
}