
#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool valido(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> mapa(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mapa[i][j];
        }
    }

    int costa = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mapa[i][j] == '#') {
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (valido(x, y, m, n) && mapa[x][y] == '.') {
                        costa++;
                        break;
                    }
                }
            }
        }
    }

    cout << costa << endl;
    return 0;
}
