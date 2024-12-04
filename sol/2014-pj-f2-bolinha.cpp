
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, I, J;
    cin >> N >> I >> J;
    I--; J--; // ajustar índices para 0-based

    vector<vector<int>> camisetas(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> camisetas[i][j];
        }
    }

    vector<vector<bool>> bandeiras(N, vector<bool>(N, false));
    queue<pair<int, int>> fila;
    fila.push({I, J});
    bandeiras[I][J] = true;

    int count = 0;
    while (!fila.empty()) {
        int i = fila.front().first;
        int j = fila.front().second;
        fila.pop();

        count++;

        for (int k = 0; k < 4; k++) {
            int ni = i + (k == 0 ? -1 : k == 1 ? 1 : k == 2 ? -1 : 1);
            int nj = j + (k == 0 ? 1 : k == 1 ? 1 : k == 2 ? -1 : -1);
            if (ni >= 0 && ni < N && nj >= 0 && nj < N && !bandeiras[ni][nj] && camisetas[ni][nj] >= camisetas[i][j]) {
                bandeiras[ni][nj] = true;
                fila.push({ni, nj});
            }
        }
    }

    cout << count << endl;

    return 0;
}
