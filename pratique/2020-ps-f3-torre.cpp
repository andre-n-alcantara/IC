#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximizeSideSum(vector<vector<int>> dice) {
    int n = dice.size();
    int maxSum = 0;

    for (int i = 0; i < n; i++) {
        sort(dice[i].begin(), dice[i].end());
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += dice[i][j];
        }
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dice(n, vector<int>(6));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> dice[i][j];
        }
    }

    cout << maximizeSideSum(dice) << endl;

    return 0;
}