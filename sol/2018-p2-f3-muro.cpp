
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;

    vector<long long> dp(N + 1);
    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        if (i >= 1) dp[i] += dp[i - 1];
        if (i >= 2) dp[i] += dp[i - 2];
        dp[i] %= MOD;
    }

    cout << dp[N] << endl;

    return 0;
}
