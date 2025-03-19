#include <ctime>
#include <bits/stdc++.h>
using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int V, M;
    cin >> V >> M;
    vector<int> coins(M);
    for (int i = 0; i < M; i++)
        cin >> coins[i];
    vector<bool> dp(V + 1, false);
    dp[0] = true;
    for (int i = 0; i < M; i++)
        for (int j = coins[i]; j <= V; j++)
            dp[j] = dp[j] || dp[j - coins[i]];
    cout << (dp[V] ? "S" : "N") << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}