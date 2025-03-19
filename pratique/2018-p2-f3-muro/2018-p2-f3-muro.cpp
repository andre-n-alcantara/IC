#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    std::clock_t startTime = std::clock();
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

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}