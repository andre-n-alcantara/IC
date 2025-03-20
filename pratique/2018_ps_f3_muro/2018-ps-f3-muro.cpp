#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int numWays(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i >= 1) dp[i] += dp[i - 1];
        if (i >= 2) dp[i] += dp[i - 2];
        dp[i] %= MOD;
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << numWays(n) << endl;
    return 0;
}