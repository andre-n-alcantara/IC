#include <ctime>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_L = 500;
const int MAX_C = 500;

int L, C;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<vector<int>> directions = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};

int bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    int steps = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == L - 1 && y == C - 1) return steps;

            for (auto d : directions) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && nx < L && ny >= 0 && ny < C && grid[nx][ny] == 1 && !visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        steps++;
    }
    return -1;
}

int main() {
    std::clock_t startTime = std::clock();
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> C;
    grid.resize(L, vector<int>(C));
    visited.resize(L, vector<bool>(C, false));

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    cout << bfs() << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}