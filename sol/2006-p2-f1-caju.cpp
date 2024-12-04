#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int L, C, M, N;
    cin >> L >> C >> M >> N;

    vector<vector<int>> farm(L, vector<int>(C));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cin >> farm[i][j];
        }
    }

    int max_caju = 0;
    for (int i = 0; i <= L - M; i++) {
        for (int j = 0; j <= C - N; j++) {
            int sum = 0;
            for (int k = 0; k < M; k++) {
                for (int l = 0; l < N; l++) {
                    sum += farm[i + k][j + l];
                }
            }
            max_caju = max(max_caju, sum);
        }
    }

    cout << max_caju << endl;

    return 0;
}