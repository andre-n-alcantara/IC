#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPiramide(vector<vector<int>> &mat) {
    int N = mat.size();
    vector<vector<int>> dp(N, vector<int>(N, 0));

    dp[0][0] = mat[0][0];
    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i-1][0] + mat[i][0];
        dp[i][i] = dp[i-1][i-1] + mat[i][i];
        for (int j = 1; j < i; j++) {
            dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + mat[i][j];
        }
    }

    int minWeight = INT_MAX;
    for (int i = 0; i < N; i++) {
        minWeight = min(minWeight, dp[N-1][i]);
    }

    return minWeight;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> mat(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }

    cout << minPiramide(mat) << endl;

    
return 0;
}