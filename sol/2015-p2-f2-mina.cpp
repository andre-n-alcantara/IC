#include <ctime>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N;
    cin >> N;

    vector<vector<int>> mine(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mine[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int blocked = 0;

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == N - 1 && y == N - 1) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
                if (mine[nx][ny] == 1) {
                    blocked++;
                }

                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    cout << blocked << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}