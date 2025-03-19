#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0));

    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        graph[X][Y] = graph[Y][X] = Z;
    }

    int max_sum = 0;
    vector<int> best_band;

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            for (int k = j + 1; k <= N; k++) {
                if (i != j && i != k && j != k) {
                    int sum = graph[i][j] + graph[i][k] + graph[j][k];
                    if (sum > max_sum) {
                        max_sum = sum;
                        best_band = {i, j, k};
                    }
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << best_band[i] << " ";
    }
    cout << endl;

    return 0;
}