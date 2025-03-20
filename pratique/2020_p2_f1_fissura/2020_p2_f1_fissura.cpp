#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void bfs(vector<vector<char>>& grid, int x, int y, int F) {
  queue<pair<int, int>> q;
  q.push({x, y});
  grid[x][y] = '*';

  while (!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] - '0' <= F && grid[nx][ny] != '*') {
        q.push({nx, ny});
        grid[nx][ny] = '*';
      }
    }
  }
}

int main() {
  int N, F;
  cin >> N >> F;

  vector<vector<char>> grid(N, vector<char>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> grid[i][j];
    }
  }

  bfs(grid, 0, 0, F);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }

  return 0;
}