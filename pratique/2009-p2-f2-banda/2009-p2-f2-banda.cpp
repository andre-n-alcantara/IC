#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> graph;
vector<int> bestBand;

int getSum(int a, int b, int c) {
    int sum = 0;
    if (a != b) sum += graph[a][b];
    if (a != c) sum += graph[a][c];
    if (b != c) sum += graph[b][c];
    return sum;
}

int main() {
    cin >> N >> M;
    graph.resize(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x][y] = graph[y][x] = z;
    }
    int maxSum = 0;
    for (int a = 1; a <= N; a++) {
        for (int b = a + 1; b <= N; b++) {
            for (int c = b + 1; c <= N; c++) {
                int sum = getSum(a, b, c);
                if (sum > maxSum) {
                    maxSum = sum;
                    bestBand = {a, b, c};
                }
            }
        }
    }
    for (int i : bestBand) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}