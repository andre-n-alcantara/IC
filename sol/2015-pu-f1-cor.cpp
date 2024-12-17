#include <ctime>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1001;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

vector<vector<char>> grid;
vector<vector<int>> dist;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() &&
                grid[nx][ny] == '*' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    std::clock_t startTime = std::clock();
    int N;
    cin >> N;

    grid.resize(N, vector<char>(N));
    dist.resize(N, vector<int>(N, -1));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '0') {
                dist[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '0') {
                bfs(i, j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dist[i][j] >= 9) {
                cout << '9';
            } else {
                cout << (char)('0' + dist[i][j]);
            }
        }
        cout << endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}