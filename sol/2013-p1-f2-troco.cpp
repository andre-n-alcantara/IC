#include <bits/stdc++.h>
using namespace std;

int main() {
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
    return 0;
}