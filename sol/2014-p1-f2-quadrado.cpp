#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> square(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> square[i][j];
        }
    }

    int targetSum = (N * (N * N + 1)) / 2;

    int original = 0, modified = 0;
    for (int i = 0; i < N; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < N; j++) {
            rowSum += square[i][j];
            colSum += square[j][i];
        }
        if (rowSum != targetSum) {
            original = targetSum - (rowSum - square[i][0]);
            modified = square[i][0];
        }
        if (colSum != targetSum) {
            original = targetSum - (colSum - square[0][i]);
            modified = square[0][i];
        }
    }

    cout << original << " " << modified << endl;

    return 0;
}