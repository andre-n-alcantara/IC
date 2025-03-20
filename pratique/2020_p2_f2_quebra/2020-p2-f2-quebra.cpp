#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxVal(int N, vector<int> &row1, vector<int> &row2) {
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == 1) {
                dp[i][j] = max(dp[i][j - 1], (j > row1.size() ? 0 : row1[j - 1]) * (j > row2.size() ? 0 : row2[j - 1]));
            } else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j] + (j > row1.size() ? 0 : row1[j - 1]) * (j > row2.size() ? 0 : row2[j - 1]));
            }
        }
    }

    return dp[N][N];
}

int main() {
    int N;
    cin >> N;

    int M;
    cin >> M;
    vector<int> row1(M);
    for (int i = 0; i < M; i++) {
        cin >> row1[i];
    }

    cin >> M;
    vector<int> row2(M);
    for (int i = 0; i < M; i++) {
        cin >> row2[i];
    }

    cout << maxVal(N, row1, row2) << endl;

    
return 0;
}