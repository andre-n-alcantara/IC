#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

vector<int> dp[1010][1010];

int countSequences(int n, int k) {
    dp[0][0] = {1};
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = {dp[i-1][0][0] + dp[i-1][0].size() > 1 ? dp[i-1][0][1] : 0, 0};
        for (int j = 1; j <= min(i, k); ++j) {
            dp[i][j] = {dp[i-1][j-1][0], dp[i-1][j][0] + dp[i-1][j].size() > 1 ? dp[i-1][j][1] : 0};
            dp[i][j][0] %= MOD;
            dp[i][j][1] %= MOD;
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans = (ans + dp[n][i][0]) % MOD;
    }
    return ans;
}

int main() {
    std::clock_t startTime = std::clock();
    int n, k;
    cin >> n >> k;
    cout << countSequences(n, k) << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}