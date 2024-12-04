#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<vector<char>> image;
int N;

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int shortestPathDistance(int x1, int y1, int x2, int y2) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    q.push({x1, y1});
    visited[x1][y1] = true;

    int distance = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == x2 && y == y2) {
                return distance;
            }

            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (isValid(nx, ny) && image[nx][ny] == '*' && !visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        distance++;
    }

    return -1; // not reachable
}

bool isRegular() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (image[i][j] == '*') {
                for (int k = 0; k < N; k++) {
                    for (int l = 0; l < N; l++) {
                        if (image[k][l] == '*') {
                            int manhattanDist = manhattanDistance(i, j, k, l);
                            int shortestPathDist = shortestPathDistance(i, j, k, l);
                            if (shortestPathDist < manhattanDist) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    cin >> N;
    image.resize(N, vector<char>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> image[i][j];
        }
    }

    if (isRegular()) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}