#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> dice(N, vector<int>(6));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> dice[i][j];
        }
    }

    int max_sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += dice[k][(j + k) % 6];
            }
            max_sum = max(max_sum, sum);
        }
    }

    cout << max_sum << endl;

    return 0;
}