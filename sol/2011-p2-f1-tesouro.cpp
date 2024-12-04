#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y, d;
};

bool bfs(int N, vector<Point> pistas, int tx, int ty) {
    queue<Point> q;
    q.push({tx, ty, 0});
    vector<vector<bool>> vis(N, vector<bool>(N, false));
    vis[tx][ty] = true;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        q.pop();

        for (int i = 0; i < pistas.size(); i++) {
            if (abs(pistas[i].x - x) + abs(pistas[i].y - y) == pistas[i].d) {
                if (!vis[pistas[i].x][pistas[i].y]) {
                    q.push({pistas[i].x, pistas[i].y, pistas[i].d});
                    vis[pistas[i].x][pistas[i].y] = true;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!vis[i][j]) return false;
        }
    }

    return true;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<Point> pistas(K);
    for (int i = 0; i < K; i++) {
        cin >> pistas[i].x >> pistas[i].y >> pistas[i].d;
    }

    bool found = false;
    int tx, ty;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (bfs(N, pistas, i, j)) {
                if (found) {
                    cout << "-1 -1" << endl;
                    return 0;
                }
                found = true;
                tx = i;
                ty = j;
            }
        }
    }

    if (found) {
        cout << tx << " " << ty << endl;
    } else {
        cout << "-1 -1" << endl;
    }

    return 0;
}